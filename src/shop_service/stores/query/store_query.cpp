//
// Created by fillinmar on 15.04.2021.
//
#include "store_query.h"

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
    this->query = "SELECT id, name, open_at, close_at, address "
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
    this->query = "SELECT id, name, open_at, close_at, address "
                  "FROM store WHERE name LIKE '" +
                  (req->Search) + "%' LIMIT "+ std::to_string(req->Limit) + " OFFSET " + std::to_string(req->Skip) + ";";
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
    this->query = "UPDATE store "
                  "SET name = '" +
                  (req->store.Name) + "', open_at = " + std::to_string(req->store.OpenAt) +
                  ", close_at = " + std::to_string(req->store.CloseAt) + ", address = '" + (req->store.Address) +
                  "'"
                  " WHERE id = " +
                  std::to_string(req->store.StoreID) + ";";
}

void UpdateStoreQuery::SetapQuery2(std::shared_ptr<UpdateStoreRequest> req)
{
    this->query = "SELECT id, name, open_at, close_at, address "
                  "FROM store WHERE id=" +
                  std::to_string(req->store.StoreID) + ";";
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
                  "VALUES ('" +
                  (req->store.Name) + "', " + std::to_string(req->store.OpenAt) + ", " +
                  std::to_string(req->store.CloseAt) + ", '" + (req->store.Address) + "' );";
}
void AddStoreQuery::SetupQueryForId(std::shared_ptr<AddStoreRequest> req)
{
    this->query = "SELECT id "
                  "FROM store WHERE name = '" +
                  (req->store.Name) + "' AND address = '" + (req->store.Address) + "';";
}

AddStoreQuery::~AddStoreQuery()
{
}
