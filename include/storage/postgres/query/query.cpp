//
// Created by fillinmar on 15.04.2021.
//
#include <string>

#include "query.h"

PostgresQuery::~PostgresQuery() {
}

GetStoreMetadataQuery::GetStoreMetadataQuery() {
}

GetStoreMetadataQuery::~GetStoreMetadataQuery() {
}

std::string GetStoreMetadataQuery::GetQuery() const {
    return this->query;
}

void GetStoreMetadataQuery::SetupQuery(std::shared_ptr<GetStoreMetadataRequest> req) {
    this->query = "SELECT id, name, open_at, close_at, address"
                  "FROM store WHERE id=" + std::to_string(req->StoreID)+";";
}

GetStoreListQuery::GetStoreListQuery() {
}

std::string GetStoreListQuery::GetQuery() const {
    return this->query;
}

void GetStoreListQuery::SetupQuery(std::shared_ptr<GetStoreListRequest> req) {
    this->query = "SELECT id, name, open_at, close_at, address"
                  "FROM store WHERE name LIKE '" + (req->Search)+ "%';";
}

GetStoreListQuery::~GetStoreListQuery() {
}

UpdateStoreQuery::UpdateStoreQuery() {
}

std::string UpdateStoreQuery::GetQuery() const {
    return this->query;
}

void UpdateStoreQuery::SetupQuery(std::shared_ptr<UpdateStoreRequest> req) {

    this->query = "UPDATE store"
                  "SET name = " +  (req->Store.Name) +", open_at = "+ std::to_string(req->Store.OpenAt) + ", close_at = " + std::to_string(req->Store.CloseAt)+ ", address = " +(req->Store.Address)+
    "WHERE id = " + std::to_string(req->Store.StoreID)+ ";";
}

UpdateStoreQuery::~UpdateStoreQuery() {
}

AddStoreQuery::AddStoreQuery() {
}

std::string AddStoreQuery::GetQuery() const {
    return this->query;
}

void AddStoreQuery::SetupQuery(std::shared_ptr<AddStoreRequest> req) {
    this->query = "INSERT INTO store(name, open_at, close_at, address)"
"VALUES (" + (req->Store.Name)+ ", " + std::to_string(req->Store.OpenAt) +", " + std::to_string(req->Store.CloseAt)+ ", " +(req->Store.Address);
}

AddStoreQuery::~AddStoreQuery() {
}

GetProductMetadataQuery::GetProductMetadataQuery() {
}

GetProductMetadataQuery::~GetProductMetadataQuery() {
}

std::string GetProductMetadataQuery::GetQuery() const {
    return this->query;
}

void GetProductMetadataQuery::SetupQuery(std::shared_ptr<GetProductMetadataRequest> req) {
    this->query = "SELECT id, name, category, price, quantity, id_store, id_counter"
                  "FROM product WHERE id=" + std::to_string(req->ProductID)+";";
}

GetProductListQuery::GetProductListQuery() {
}

std::string GetProductListQuery::GetQuery() const {
    return this->query;
}

void GetProductListQuery::SetupQuery(std::shared_ptr<GetProductListRequest> req) {
    this->query = "SELECT id, name, category, price, quantity, id_store, id_counter "
                  "FROM store WHERE name LIKE '" + (req->Search)+ "%';";
}

GetProductListQuery::~GetProductListQuery() {
}

UpdateProductQuery::UpdateProductQuery() {
}

std::string UpdateProductQuery::GetQuery() const {
    return this->query;
}

void UpdateProductQuery::SetupQuery(std::shared_ptr<UpdateStoreRequest> req) {

    this->query = "UPDATE product"
                  "SET name = " +  (req->Product.Name) +", category = "+ (req->Product.Category) + ", price = " + std::to_string(req->Product.Price)+ ", quantity = " +std::to_string(req->Product.Quantity)+ ", id_store = " + std::to_string(req->Product.StoreID)+ ", id_counter = " +std::to_string(req->Product.CounterID)+
                  "WHERE id = " + std::to_string(req->Product.ProductID)+ ";";
}

UpdateProductQuery::~UpdateProductQuery() {
}

AddProductQuery::AddProductQuery() {
}

std::string AddProductQuery::GetQuery() const {
    return this->query;
}

void AddProductQuery::SetupQuery(std::shared_ptr<AddStoreRequest> req) {
    this->query = "INSERT INTO product(name, category, price, quantity, id_store, id_counter)"
                  "VALUES (" + (req->Product.Name)+ ", " + (req->Product.Category) +", " + std::to_string(req->Product.Price)+ ", " +std::to_string(req->Product.Quantity)+ ", " + std::to_string(req->Product.StoreID) + ", " +std::to_string(req->Product.CounterID);
}

AddProductQuery::~AddProductQuery() {
}