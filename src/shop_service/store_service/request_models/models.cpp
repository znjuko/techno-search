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

GetStoreListRequest::GetStoreListRequest() : Search(""){

      };

void GetStoreListRequest::Marshall(const Http::Uri::Query &query){
    Search = (query.get("name").value());
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

StoreMetadata::StoreMetadata() : openAt(0), closeAt(0), address(""), name(""){};

void StoreMetadata::Marshall(const std::string &body){};

nlohmann::json StoreMetadata::UnMarshall()
{
    return nlohmann::json();
};

StoreList::StoreList() : storeList(), skip(0),limit(0) {};
void StoreList::Marshall(const std::string &body){};
nlohmann::json StoreList::UnMarshall()
{
    return nlohmann::json();
};

UpdateStore::UpdateStore() : openAt(0), closeAt(0), address(""), name(""){};
void UpdateStore::Marshall(const std::string &body){};
nlohmann::json UpdateStore::UnMarshall()
{
    return nlohmann::json();
};

AddStore::AddStore() : openAt(0), closeAt(0), address(""), name(""){};

void AddStore::Marshall(const std::string &body){};

nlohmann::json AddStore::UnMarshall()
{
    return nlohmann::json();
};

GetStoreMetadataResponse::GetStoreMetadataResponse() : array(std::vector<StoreMetadata>()){};
nlohmann::json GetStoreMetadataResponse::UnMarshall()
{
    return nlohmann::json();
};

GetStoreListResponse::GetStoreListResponse() : array(std::vector<StoreList>()){};
nlohmann::json GetStoreListResponse::UnMarshall()
{
    return nlohmann::json();
};

UpdateStoreResponse::UpdateStoreResponse() : array(std::vector<UpdateStore>()){};
nlohmann::json UpdateStoreResponse::UnMarshall()
{
    return nlohmann::json();
};

AddStoreResponse::AddStoreResponse() : array(std::vector<AddStore>()){};
nlohmann::json AddStoreResponse::UnMarshall()
{
    return nlohmann::json();
};
