//
// Created by fillinmar on 15.04.2021.
//

#ifndef TECHNO_SEARCH_QUERY_H
#define TECHNO_SEARCH_QUERY_H

#include "models.h"

#include <memory>

#include <string>

class PostgresQuery
{
  public:
    virtual std::string GetQuery() const = 0;

    virtual ~PostgresQuery();
};

class GetStoreMetadataQuery : public PostgresQuery
{
  public:
    GetStoreMetadataQuery();

    GetStoreMetadataQuery (std::string *query) = delete;

    GetStoreMetadataQuery (std::string &query) = delete;

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

    ~AddStoreQuery() override;

  private:
    std::string query;
};
class GetProductMetadataQuery : public PostgresQuery
{
  public:
    GetProductMetadataQuery();

    GetProductMetadataQuery (std::string *query) = delete;

    GetProductMetadataQuery (std::string &query) = delete;

    std::string GetQuery() const override;

    void SetupQuery(std::shared_ptr<GetProductMetadataRequest> req);

    ~GetProductMetadataQuery() override;

  private:
    std::string query;
};

class GetProductListQuery : public PostgresQuery
{
  public:
    GetProductListQuery();

    GetProductListQuery(std::string *query) = delete;

    GetProductListQuery(std::string &query) = delete;

    std::string GetQuery() const override;

    void SetupQuery(std::shared_ptr<GetProductListRequest> req);

    ~GetProductListQuery() override;

  private:
    std::string query;
};

class UpdateProductQuery : public PostgresQuery
{
  public:
    UpdateProductQuery();

    UpdateProductQuery(std::string query) = delete;

    UpdateProductQuery(std::string &query) = delete;

    std::string GetQuery() const override;

    void SetupQuery(std::shared_ptr<UpdateProductRequest> req);

    ~UpdateProductQuery() override;

  private:
    std::string query;
};

class AddProductQuery : public PostgresQuery
{
  public:
    AddProductQuery();

    AddProductQuery(std::string query) = delete;

    AddProductQuery(std::string &query) = delete;

    std::string GetQuery() const override;

    void SetupQuery(std::shared_ptr<AddProductRequest> req);

    ~AddProductQuery() override;

  private:
    std::string query;
};

#endif // TECHNO_SEARCH_QUERY_H
