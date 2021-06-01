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
}

GetStoreListRequest::GetStoreListRequest() : Search(""), Limit(0), Skip(0){};

void GetStoreListRequest::Marshall(const Http::Uri::Query &query)
{
    auto searchParam = query.get("name");
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

UpdateStoreRequest::UpdateStoreRequest() : store(0, "", 0.0, 0.0, ""){};

void UpdateStoreRequest::Marshall(const std::string &body)
{
    std::string a = body;
    json j = json::parse(body);
    json object = j["storeToUpdate"];

    store.StoreID = object[0]["id"];
    store.Name = object[0]["name"];
    store.OpenAt = object[0]["openAt"];
    store.CloseAt = object[0]["closeAt"];
    store.Address = object[0]["address"];
};

AddStoreRequest::AddStoreRequest() : store(0, "", 0.0, 0.0, ""){};

void AddStoreRequest::Marshall(const std::string &body)
{
    json j = json::parse(body);
    json object = j["storeToAdd"];

    store.Name = object[0]["name"];
    store.OpenAt = object[0]["openAt"];
    store.CloseAt = object[0]["closeAt"];
    store.Address = object[0]["address"];
};

StoreMetadata::StoreMetadata() : store(0, "", 0.0, 0.0, ""){};

void StoreMetadata::Marshall(const Http::Uri::Query &body){};

nlohmann::json StoreMetadata::UnMarshall()
{
    nlohmann::json output;
    output["address"] = store.Address;
    output["closeAt"] = store.CloseAt;
    output["openAt"] = store.OpenAt;
    output["name"] = store.Name;
    output["storeID"] = store.StoreID;
    return output;
};

StoreList::StoreList() : store(0, "", 0.0, 0.0, ""){};
void StoreList::Marshall(const std::string &body){};
nlohmann::json StoreList::UnMarshall()
{
    nlohmann::json output;
    output["address"] = store.Address;
    output["closeAt"] = store.CloseAt;
    output["openAt"] = store.OpenAt;
    output["name"] = store.Name;
    output["storeID"] = store.StoreID;
    return output;
};

UpdateStore::UpdateStore() : store(0, "", 0.0, 0.0, ""){};
void UpdateStore::Marshall(const std::string &body){};
nlohmann::json UpdateStore::UnMarshall()
{
    nlohmann::json output;
    output["address"] = store.Address;
    output["closeAt"] = store.CloseAt;
    output["openAt"] = store.OpenAt;
    output["name"] = store.Name;
    output["storeID"] = store.StoreID;
    return output;
};

AddStore::AddStore() : store(0, "", 0.0, 0.0, ""){};

void AddStore::Marshall(const std::string &body){};

nlohmann::json AddStore::UnMarshall()
{
    nlohmann::json output;
    output["storeID"] = store.StoreID;
    return output;
};

GetStoreMetadataResponse::GetStoreMetadataResponse() : array(std::vector<StoreMetadata>()){};

nlohmann::json GetStoreMetadataResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = array.begin(); item != array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["storeById"] = outputArray;

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
    output["storeSearch"] = outputArray;

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
    output["updatedStore"] = outputArray;

    return output;
};

AddStoreResponse::AddStoreResponse() : array(std::vector<AddStore>()){};
nlohmann::json AddStoreResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = array.begin(); item != array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["addedStore"] = outputArray;

    return output;
};
