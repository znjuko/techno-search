//
// Created by fillinmar on 17.04.2021.
//

#ifndef TECHNO_SEARCH_PRODUCTS_READER_H
#define TECHNO_SEARCH_PRODUCTS_READER_H

#include "models.h"
#include "reader.h"

#include <boost/lexical_cast.hpp>
#include <pqxx/pqxx>
#include <vector>

class ProductMetadataReader : public PostgresReader
{
  public:
    ProductMetadataReader() = default;

    ProductMetadataReader(const ProductMetadataReader &r) = delete;

    ProductMetadataReader(const std::vector<ProductMetadataReader> &v) = delete;

    void Execute(const pqxx::result R) override;

    std::vector<ProductMetadata> Get();

    ~ProductMetadataReader() override = default;

  private:
    std::vector<ProductMetadata> data;
};

class ProductListReader : public PostgresReader
{
  public:
    ProductListReader() = default;

    ProductListReader(const ProductList &r) = delete;

    ProductListReader(const std::vector<ProductList> &v) = delete;

    void Execute(const pqxx::result R) override;

    std::vector<ProductList> Get();

    ~ProductListReader() override = default;

  private:
    std::vector<ProductList> data;
};

class AddProductReader : public PostgresReader
{
  public:
    AddProductReader() = default;

    AddProductReader(const AddProduct &r) = delete;

    AddProductReader(const std::vector<AddProduct> &v) = delete;

    void Execute(const pqxx::result R) override;

    std::vector<AddProduct> Get();

    ~AddProductReader() override = default;

  private:
    std::vector<AddProduct> data;
};
#endif
