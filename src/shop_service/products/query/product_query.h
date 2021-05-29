//
// Created by fillinmar on 15.04.2021.
//

#ifndef TECHNO_SEARCH_PRODUCTS_QUERY_H
#define TECHNO_SEARCH_PRODUCTS_QUERY_H

#include "product_models.h"

#include <memory>
#include "postgres_query.h"
#include <string>

class GetProductMetadataQuery : public PostgresQuery
{
  public:
    GetProductMetadataQuery();

    GetProductMetadataQuery(std::string *query) = delete;

    GetProductMetadataQuery(std::string &query) = delete;

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

    void SetupQueryForUpdatedProduct(std::shared_ptr<UpdateProductRequest> req);

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

    void SetupQueryForId(std::shared_ptr<AddProductRequest> req);

    ~AddProductQuery() override;

  private:
    std::string query;
};

#endif
