//
// Created by fillinmar on 14.04.2021.
//

#include "models.h"
#include <iomanip>
#include "struct_mapping/struct_mapping.h"

using namespace Pistache;

GetStoreMetadataRequest::GetStoreMetadataRequest() : StoreID(0){
}

void GetStoreMetadataRequest::Marshall(const Http::Uri::Query &query){
    StoreID = boost::lexical_cast<int>(query.get("id").value());
};

GetStoreListRequest::GetStoreListRequest() : Search(""), limit(0), skip(0){};

void GetStoreListRequest::Marshall(const Http::Uri::Query &query){
    Search = (query.get("name").value());
    limit = boost::lexical_cast<int>(query.get("storage").value());
    skip = boost::lexical_cast<int>(query.get("storage").value());
};

UpdateStoreRequest::UpdateStoreRequest() : Store(0, "", 0.0, 0.0, ""){};

void UpdateStoreRequest::Marshall(const std::string &body){
    //TODO:: check regular is it
    auto jsonData = std::istringstream(R"json(\n" + body + "\n)json");
    nlohmann::json d;

    struct_mapping::map_json_to_struct(Store, jsonData);
};

AddStoreRequest::AddStoreRequest() : Store(0, "", 0.0, 0.0, ""){};

void AddStoreRequest::Marshall(const std::string &body){
    //TODO:: check regular is it
    auto jsonData = std::istringstream(R"(json)" + body + R"(json)");

    struct_mapping::map_json_to_struct(Store, jsonData);
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

StoreList::StoreList() :  Store(0, "", 0.0, 0.0, "") {};
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
    for (auto item = array.begin(); item != array.end(); ++item) {
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
    for (auto item = array.begin(); item != array.end(); ++item) {
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
