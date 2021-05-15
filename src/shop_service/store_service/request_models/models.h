//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_MODELS_H
#define TECHNO_SEARCH_MODELS_H

#include "marshaller.h"
#include "unmarshaller.h"

#include <string>
#include <pistache/endpoint.h>
#include <nlohmann/json.hpp>
#include <algorithm>
#include <pistache/http.h>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace Pistache;

struct StoreStruct{
    int StoreID;
    std::string Name;
    float OpenAt;
    float CloseAt;
    std::string Address;
    StoreStruct(int StoreID, std::string Name,float OpenAt,float CloseAt,std::string Address){
        this->StoreID = StoreID;
        this->Name = Name;
        this->OpenAt = OpenAt;
        this->CloseAt = CloseAt;
        this->Address = Address;
    }
};

class GetStoreMetadataRequest : public IQueryMarshaller
{
  public:
    GetStoreMetadataRequest();

    ~GetStoreMetadataRequest() override = default;

    void Marshall(const Http::Uri::Query &body) override;

    int StoreID;
};

class GetStoreListRequest : public IQueryMarshaller
{
  public:
    GetStoreListRequest();

    void Marshall(const Http::Uri::Query &body) override;

    ~GetStoreListRequest() override = default;

    std::string Search;
};

class UpdateStoreRequest : public IMarshaller
{
public:
    UpdateStoreRequest();

    void Marshall(const std::string &body) override;

    ~UpdateStoreRequest() override = default;
    StoreStruct Store;
};

class AddStoreRequest : public IMarshaller
{
public:
    AddStoreRequest();
    void Marshall(const std::string &body) override;
    ~AddStoreRequest() override = default;
    StoreStruct Store;
};

class StoreMetadata : public IMarshaller, public IUnMarshaller
{
  public:
    StoreMetadata();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~StoreMetadata() override = default;

    float openAt;
    float closeAt;
    std::string address;
    std::string name;
};

class StoreList: public IMarshaller, public IUnMarshaller
{
  public:
    StoreList();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~StoreList() override = default;

    StoreMetadata* storeList;
    int skip;
    int limit;
};

class UpdateStore : public IMarshaller, public IUnMarshaller
{
public:
    UpdateStore();
    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~UpdateStore() override = default;

    float openAt;
    float closeAt;
    std::string address;
    std::string name;
};

class AddStore: public IMarshaller, public IUnMarshaller
{
public:
    AddStore();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~AddStore() override = default;

    float openAt;
    float closeAt;
    std::string address;
    std::string name;
};

class GetStoreMetadataResponse : public IUnMarshaller
{
  public:
    GetStoreMetadataResponse();

    nlohmann::json UnMarshall() override;

    ~GetStoreMetadataResponse() override = default;

    std::vector<StoreMetadata> array;
};

class GetStoreListResponse : public IUnMarshaller
{
  public:
    GetStoreListResponse();

    nlohmann::json UnMarshall() override;

    ~GetStoreListResponse() override = default;

    std::vector<StoreList> array;
};

class UpdateStoreResponse : public IUnMarshaller
{
  public:
    UpdateStoreResponse();

    nlohmann::json UnMarshall() override;

    ~UpdateStoreResponse() override = default;

    std::vector<UpdateStore> array;
};

class AddStoreResponse : public IUnMarshaller
{
public:
    AddStoreResponse();

    nlohmann::json UnMarshall() override;

    ~AddStoreResponse() override = default;

    std::vector<AddStore> array;
};

#endif // TECHNO_SEARCH_MODELS_H
