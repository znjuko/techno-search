//
// Created by fillinmar on 14.04.2021.
//

#include "models.h"

using namespace Pistache;

GetStoreMetadataRequest::GetStoreMetadataRequest() : name(""){

}

void GetStoreMetadataRequest::Marshall(const Http::Uri::Query &query){
    //TODO
};

GetStoreListRequest::GetStoreListRequest() : name(""), search(""){};

void GetStoreListRequest::Marshall(const std::string &body){};

UpdateStoreRequest::UpdateStoreRequest() : openAt(0), closeAt(0), address(""), name(""){};

void UpdateStoreRequest::Marshall(const std::string &body){};

AddStoreRequest::AddStoreRequest() : openAt(0), closeAt(0), address(""), name(""){};

void AddStoreRequest::Marshall(const Http::Uri::Query &query){};

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
