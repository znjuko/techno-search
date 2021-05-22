//
// Created by Никита Черных on 20.05.2021.
//

#include "path_models.h"

void GetStorePathRequest::Marshall(const Rest::Request &req)
{
    StoreID = req.param(":shopID").as<int>();

    auto fromNodeParam = req.query().get("startNode");
    if (fromNodeParam->empty())
    {
        throw EmptyValue("startNode");
    }
    FromNode = boost::lexical_cast<int>(*fromNodeParam);

    auto toNodeParam = req.query().get("endNode");
    if (toNodeParam->empty())
    {
        throw EmptyValue("endNode");
    }
    ToNode = boost::lexical_cast<int>(*toNodeParam);
}

GetStorePathRequest::GetStorePathRequest() : StoreID(0), FromNode(0), ToNode(0)
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
