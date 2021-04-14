//
// Created by fillinmar on 14.04.2021.
//

#include "models.h"

GetProductMetadataRequest::GetStoreMetadataRequest() : name(""), shopName(""){};

void GetProductMetadataRequest::Marshall(const std::string &body){};

GetProductListRequest::GetProductListRequest() : shopName(""), name(""), search(""){};

void GetProductListRequest::Marshall(const std::string &body){};

UpdateProductRequest::UpdateProductRequest() : shopName(""), name(""), category(""),price(0), quantity(0), articul(""){};

void UpdateProductRequest::Marshall(const std::string &body){};

AddProductRequest::AddProductRequest() : shopName(""), name(""), category(""),price(0), quantity(0), articul(""){};

void AddStoreRequest::Marshall(const std::string &body){};

ProductMetadata::ProductMetadata() : shopName(""), name(""), category(""),price(0), quantity(0), articul(""){};

void ProductMetadata::Marshall(const std::string &body){};

nlohmann::json ProductMetadata::UnMarshall()
{
    return nlohmann::json();
};

ProductList::ProductList() : ProductList("", "", "",0, 0, ""){};
void ProductList::Marshall(const std::string &body){};
nlohmann::json ProductList::UnMarshall()
{
    return nlohmann::json();
};

UpdateProduct::UpdateProduct() : shopName(""), name(""), category(""),price(0), quantity(0), articul(""){};
void UpdateProduct::Marshall(const std::string &body){};
nlohmann::json UpdateProduct::UnMarshall()
{
    return nlohmann::json();
};

AddProduct::AddProduct() : shopName(""), name(""), category(""),price(0), quantity(0), articul(""){};

void AddProduct::Marshall(const std::string &body){};

nlohmann::json AddProduct::UnMarshall()
{
    return nlohmann::json();
};

GetProductMetadataResponse::GetProductMetadataResponse() : array(std::vector<ProductMetadata>()){};
nlohmann::json GetProductMetadataResponse::UnMarshall()
{
    return nlohmann::json();
};

GetProductListResponse::GetProductListResponse() : array(std::vector<ProductList>()){};
nlohmann::json GetStoreListResponse::UnMarshall()
{
    return nlohmann::json();
};

UpdateProductResponse::UpdateProductResponse() : array(std::vector<UpdateProduct>()){};
nlohmann::json UpdateProductResponse::UnMarshall()
{
    return nlohmann::json();
};

AddProductResponse::AddProductResponse() : array(std::vector<AddProduct>()){};
nlohmann::json AddProductResponse::UnMarshall()
{
    return nlohmann::json();
};
