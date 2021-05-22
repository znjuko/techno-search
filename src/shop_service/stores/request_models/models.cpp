//
// Created by fillinmar on 14.04.2021.
//

#include "models.h"

#include <iomanip>

using namespace Pistache;
using json = nlohmann::json;

GetStoreMetadataRequest::GetStoreMetadataRequest() : StoreID(0)
{
}

void GetStoreMetadataRequest::Marshall(const Http::Uri::Query &query)
{
    auto storeParam = query.get("id");
    if (storeParam->empty())
    {
        throw EmptyValue("id");
    }
    StoreID = boost::lexical_cast<int>(*storeParam);
};

GetStoreListRequest::GetStoreListRequest() : Search(""), Limit(0), Skip(0){};

void GetStoreListRequest::Marshall(const Http::Uri::Query &query)
{
    auto searchParam = query.get("name");
    if (searchParam->empty())
    {
        throw EmptyValue("name");
    }
    Search = *searchParam;

    auto limitParam = query.get("limit");
    if (limitParam->empty())
    {
        throw EmptyValue("limit");
    }
    Limit = boost::lexical_cast<int>(*limitParam);

    auto skipParam = query.get("skip");
    if (skipParam->empty())
    {
        throw EmptyValue("skip");
    }
    Skip = boost::lexical_cast<int>(*skipParam);
};

UpdateStoreRequest::UpdateStoreRequest() : Store(0, "", 0.0, 0.0, ""){};

void UpdateStoreRequest::Marshall(const std::string &body)
{
    json j = json::parse(body);
    json object = j["storeToUpdate"];

    Store.StoreID = object[0]["storeID"];
    Store.Name = object[0]["name"];
    Store.OpenAt = object[0]["openAt"];
    Store.CloseAt = object[0]["closeAt"];
    Store.Address = object[0]["address"];
};

AddStoreRequest::AddStoreRequest() : Store(0, "", 0.0, 0.0, ""){};

void AddStoreRequest::Marshall(const std::string &body)
{
    json j = json::parse(body);
    json object = j["storeToAdd"];

    Store.Name = object[0]["name"];
    Store.OpenAt = object[0]["openAt"];
    Store.CloseAt = object[0]["closeAt"];
    Store.Address = object[0]["address"];
};

StoreMetadata::StoreMetadata() : Store(0, "", 0.0, 0.0, ""){};

void StoreMetadata::Marshall(const Http::Uri::Query &body){};

nlohmann::json StoreMetadata::UnMarshall()
{
    nlohmann::json output;
    output["storage"] = Store.StoreID;
    output["name"] = Store.Name;
    output["openAt"] = Store.OpenAt;
    output["closeAt"] = Store.CloseAt;
    output["address"] = Store.Address;
    return output;
};

StoreList::StoreList() : Store(0, "", 0.0, 0.0, ""){};
void StoreList::Marshall(const std::string &body){};
nlohmann::json StoreList::UnMarshall()
{
    nlohmann::json output;
    output["storage"] = Store.StoreID;
    output["name"] = Store.Name;
    output["openAt"] = Store.OpenAt;
    output["closeAt"] = Store.CloseAt;
    output["address"] = Store.Address;
    return output;
};

UpdateStore::UpdateStore() : Store(0, "", 0.0, 0.0, ""){};
void UpdateStore::Marshall(const std::string &body){};
nlohmann::json UpdateStore::UnMarshall()
{
    nlohmann::json output;
    output["storage"] = Store.StoreID;
    output["name"] = Store.Name;
    output["openAt"] = Store.OpenAt;
    output["closeAt"] = Store.CloseAt;
    output["address"] = Store.Address;
    return output;
};

AddStore::AddStore() : Store(0, "", 0.0, 0.0, ""){};

void AddStore::Marshall(const std::string &body){};

nlohmann::json AddStore::UnMarshall()
{
    nlohmann::json output;
    output["storage"] = Store.StoreID;
    output["name"] = Store.Name;
    output["openAt"] = Store.OpenAt;
    output["closeAt"] = Store.CloseAt;
    output["address"] = Store.Address;
    return output;
};

GetStoreMetadataResponse::GetStoreMetadataResponse() : array(std::vector<StoreMetadata>()){};
nlohmann::json GetStoreMetadataResponse::UnMarshall()
{
    nlohmann::json output;
    output["value"] = output;

    return output;
};

GetStoreListResponse::GetStoreListResponse() : array(std::vector<StoreList>()){};
nlohmann::json GetStoreListResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = array.begin(); item != array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["values"] = outputArray;

    return output;
};

UpdateStoreResponse::UpdateStoreResponse() : array(std::vector<UpdateStore>()){};
nlohmann::json UpdateStoreResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = array.begin(); item != array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["values"] = outputArray;

    return output;
};

AddStoreResponse::AddStoreResponse() : array(std::vector<AddStore>()){};
nlohmann::json AddStoreResponse::UnMarshall()
{
    nlohmann::json output;
    output["value"] = output;

    return output;
};