//
// Created by fillinmar on 15.04.2021.
//
#include "query.h"

#include <string>

GetStoreMetadataQuery::GetStoreMetadataQuery()
{
}

GetStoreMetadataQuery::~GetStoreMetadataQuery()
{
}

std::string GetStoreMetadataQuery::GetQuery() const
{
    return this->query;
}

void GetStoreMetadataQuery::SetupQuery(std::shared_ptr<GetStoreMetadataRequest> req)
{
    this->query = "SELECT id, name, open_at, close_at, address"
                  "FROM store WHERE id=" +
                  std::to_string(req->StoreID) + ";";
}

GetStoreListQuery::GetStoreListQuery()
{
}

std::string GetStoreListQuery::GetQuery() const
{
    return this->query;
}

void GetStoreListQuery::SetupQuery(std::shared_ptr<GetStoreListRequest> req)
{
    this->query = "SELECT id, name, open_at, close_at, address"
                  "FROM store WHERE name LIKE '" +
                  (req->Search) + "%';";
}

GetStoreListQuery::~GetStoreListQuery()
{
}

UpdateStoreQuery::UpdateStoreQuery()
{
}

std::string UpdateStoreQuery::GetQuery() const
{
    return this->query;
}

void UpdateStoreQuery::SetupQuery(std::shared_ptr<UpdateStoreRequest> req)
{

    this->query = "UPDATE store"
                  "SET name = " +
                  (req->Store.Name) + ", open_at = " + std::to_string(req->Store.OpenAt) +
                  ", close_at = " + std::to_string(req->Store.CloseAt) + ", address = " + (req->Store.Address) +
                  "WHERE id = " + std::to_string(req->Store.StoreID) + ";";
}

UpdateStoreQuery::~UpdateStoreQuery()
{
}

AddStoreQuery::AddStoreQuery()
{
}

std::string AddStoreQuery::GetQuery() const
{
    return this->query;
}

void AddStoreQuery::SetupQuery(std::shared_ptr<AddStoreRequest> req)
{
    this->query = "INSERT INTO store(name, open_at, close_at, address)"
                  "VALUES (" +
                  (req->Store.Name) + ", " + std::to_string(req->Store.OpenAt) + ", " +
                  std::to_string(req->Store.CloseAt) + ", " + (req->Store.Address);
}

AddStoreQuery::~AddStoreQuery()
{
}
