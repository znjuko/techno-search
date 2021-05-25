//
// Created by fillinmar on 15.04.2021.
//

#ifndef TECHNO_SEARCH_STORES_QUERY_H
#define TECHNO_SEARCH_STORES_QUERY_H

#include "models.h"
#include "postgres_query.h"

#include <memory>
#include <string>

class GetStoreMetadataQuery : public PostgresQuery
{
  public:
    GetStoreMetadataQuery();

    GetStoreMetadataQuery(std::string *query) = delete;

    GetStoreMetadataQuery(std::string &query) = delete;

    std::string GetQuery() const override;

    void SetupQuery(std::shared_ptr<GetStoreMetadataRequest> req);

    ~GetStoreMetadataQuery() override;

  private:
    std::string query;
};

class GetStoreListQuery : public PostgresQuery
{
  public:
    GetStoreListQuery();

    GetStoreListQuery(std::string *query) = delete;

    GetStoreListQuery(std::string &query) = delete;

    std::string GetQuery() const override;

    void SetupQuery(std::shared_ptr<GetStoreListRequest> req);

    ~GetStoreListQuery() override;

  private:
    std::string query;
};

class UpdateStoreQuery : public PostgresQuery
{
  public:
    UpdateStoreQuery();

    UpdateStoreQuery(std::string query) = delete;

    UpdateStoreQuery(std::string &query) = delete;

    std::string GetQuery() const override;

    void SetapQuery2(std::shared_ptr<UpdateStoreRequest> req);

    void SetupQuery(std::shared_ptr<UpdateStoreRequest> req);

    ~UpdateStoreQuery() override;

  private:
    std::string query;
};

class AddStoreQuery : public PostgresQuery
{
  public:
    AddStoreQuery();

    AddStoreQuery(std::string query) = delete;

    AddStoreQuery(std::string &query) = delete;

    std::string GetQuery() const override;

    void SetupQuery(std::shared_ptr<AddStoreRequest> req);

    void SetupQueryForId(std::shared_ptr<AddStoreRequest> req);

    ~AddStoreQuery() override;

  private:
    std::string query;
};
#endif // TECHNO_SEARCH_STORE_STORE_SERVICE_H
