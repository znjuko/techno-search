//
// Created by fillinmar on 15.04.2021.
//
#include "product_query.h"

#include <string>

GetProductMetadataQuery::GetProductMetadataQuery()
{
}

GetProductMetadataQuery::~GetProductMetadataQuery()
{
}

std::string GetProductMetadataQuery::GetQuery() const
{
    return this->query;
}

void GetProductMetadataQuery::SetupQuery(std::shared_ptr<GetProductMetadataRequest> req)
{
    this->query = "SELECT id, name, category, price, quantity, id_store, id_counter "
                  "FROM product WHERE id=" +
                  std::to_string(req->ProductID) + ";";
}

GetProductListQuery::GetProductListQuery()
{
}

std::string GetProductListQuery::GetQuery() const
{
    return this->query;
}

void GetProductListQuery::SetupQuery(std::shared_ptr<GetProductListRequest> req)
{
    this->query = "SELECT id, name, category, price, quantity, id_store, id_counter "
                  "FROM store WHERE name LIKE '" +
                  (req->Search) + "%';";
}

GetProductListQuery::~GetProductListQuery()
{
}

UpdateProductQuery::UpdateProductQuery()
{
}

std::string UpdateProductQuery::GetQuery() const
{
    return this->query;
}

void UpdateProductQuery::SetupQuery(std::shared_ptr<UpdateProductRequest> req)
{

    this->query = "UPDATE product"
                  "SET name = " +
                  (req->product.Name) + ", category = " + (req->product.Category) +
                  ", price = " + std::to_string(req->product.Price) +
                  ", quantity = " + std::to_string(req->product.Quantity) +
                  ", id_store = " + std::to_string(req->product.StoreID) +
                  ", id_counter = " + std::to_string(req->product.CounterID) +
                  "WHERE id = " + std::to_string(req->product.ProductID) + ";";
}

UpdateProductQuery::~UpdateProductQuery()
{
}

AddProductQuery::AddProductQuery()
{
}

std::string AddProductQuery::GetQuery() const
{
    return this->query;
}

void AddProductQuery::SetupQuery(std::shared_ptr<AddProductRequest> req)
{
    this->query = "INSERT INTO product(name, category, price, quantity, id_store, id_counter)"
                  "VALUES (" +
                  (req->product.Name) + ", " + (req->product.Category) + ", " + std::to_string(req->product.Price) +
                  ", " + std::to_string(req->product.Quantity) + ", " + std::to_string(req->product.StoreID) + ", " +
                  std::to_string(req->product.CounterID);
}

AddProductQuery::~AddProductQuery()
{
}