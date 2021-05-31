#include "map_request_models.h"

#include <cmath>
nlohmann::json AdjacencyPoints::UnMarshall()
{
    auto output = nlohmann::json();

    output["storeID"] = StoreID;

    auto points = nlohmann::json::array();
    for (int i = 0; i < Points.size(); ++i)
    {
        auto p = nlohmann::json();
        p["pointID"] = i;
        p["x"] = Points[i].x;
        p["y"] = Points[i].y;
        points.push_back(p);
    }
    output["points"] = points;

    return output;
}

AdjacencyPoints::AdjacencyPoints(const std::string &body)
{
    auto jsonBody = json::parse(body);

    StoreID = jsonBody["storeID"];
    int size = jsonBody["size"];
    Points = std::vector<Point>(size, Point());

    auto points = jsonBody["adjacency_table"];
    for (auto p : points)
    {
        int pos = p["pointID"];
        Points[pos] = Point(p["x"], p["y"]);
    }
}
AdjacencyPoints::AdjacencyPoints() : StoreID(0), Points(0)
{
}

void StoreActionRequest::Marshall(const Http::Uri::Query &query)
{
    auto storeParam = query.get("storeID");
    if (storeParam->empty())
    {
        throw EmptyValue("storeID");
    }
    StoreID = boost::lexical_cast<int>(*storeParam);
}

StoreActionRequest::StoreActionRequest(){

};

nlohmann::json StoreAdjacencyPointsResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = array.begin(); item != array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["adjacency"] = outputArray;

    return output;
};

StoreCountersAdjacency::StoreCountersAdjacency(const std::string &data)
{
    auto jsonData = json::parse(data);

    StoreID = jsonData["storeID"];

    auto adj = jsonData["objects"];
    for (const auto &item : adj)
    {
        int counterID = jsonData["counterID"];
        int pointID = jsonData["pointID"];
        auto countAdj = CounterWithPoints(counterID, pointID);
        counterWithPoints.push_back(countAdj);
    }
}

StoreCountersAdjacency::StoreCountersAdjacency() : StoreID(0), counterWithPoints(0)
{
}

void StoreMap::Marshall(const std::string &body)
{
    auto jsonBody = json::parse(body);
    StoreID = jsonBody["storeID"];

    for (const auto &geometry : jsonBody["geometry"])
    {
        for (const auto &coord : geometry["coordinates"])
        {
            StoreGeometry.AddPoint(Point(coord[0], coord[1]));
        }
    }
    StoreGeometry.InitLines();

    for (const auto &geometry : jsonBody["inherit"])
    {
        auto poly = Polygon();
        for (const auto &coord : geometry["coordinates"])
        {
            poly.AddPoint(Point(coord[0], coord[1]));
        }
        poly.InitLines();
        poly.SetID(geometry["props"][0]["value"]);
        InheritObjects.push_back(poly);
    }
}

StoreMap::StoreMap()
{
}

void RawStoreMap::Marshall(const std::string &body)
{
    auto jsonBody = json::parse(body);
    StoreID = jsonBody["storeID"];
    Inherit = jsonBody["inherit"];
    Geometry = jsonBody["geometry"];
}

nlohmann::json RawStoreMap::UnMarshall()
{
    auto output = nlohmann::json();

    output["storeID"] = StoreID;
    output["inherit"] = Inherit;
    output["geometry"] = Geometry;

    return nlohmann::json();
}

RawStoreMap::RawStoreMap(const std::string &body)
{
    auto jsonBody = json::parse(body);
    StoreID = jsonBody["storeID"];
    Inherit = jsonBody["inherit"];
    Geometry = jsonBody["geometry"];
}

void GetStorePathRequest::Marshall(const Rest::Request &req)
{
    StoreID = req.param(":storeID").as<int>();

    auto fromNodeParam = req.query().get("start");
    if (fromNodeParam->empty())
    {
        throw EmptyValue("start");
    }
    FromCounter = boost::lexical_cast<int>(*fromNodeParam);

    auto toNodeParam = req.query().get("end");
    if (toNodeParam->empty())
    {
        throw EmptyValue("end");
    }
    ToCounter = boost::lexical_cast<int>(*toNodeParam);
}

GetStorePathRequest::GetStorePathRequest() : StoreID(0), FromCounter(0), ToCounter(0)
{
}

GetStorePathResponse::GetStorePathResponse(std::vector<size_t> Path) : Array(std::move(Path))
{
}

nlohmann::json GetStorePathResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (size_t &item : Array)
    {
        outputArray.push_back(item);
    }
    output["path"] = outputArray;

    return output;
}

StoreModel::StoreModel(const std::string &data)
{
    auto jsonData = json::parse(data);

    ID = jsonData["storeID"];
    Size = jsonData["size"];

    auto adj = jsonData["adjacency_table"];
    for (const auto &item : adj)
    {
        Adjacency.push_back(boost::lexical_cast<double>(item));
    }
}

StoreModel::StoreModel() : ID(0), Size(0), Adjacency(0)
{
}
