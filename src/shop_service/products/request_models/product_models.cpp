//
// Created by fillinmar on 14.04.2021.
//

#include "product_models.h"

#include "common_exceptions.h"

using namespace Pistache;
using json = nlohmann::json;

GetProductMetadataRequest::GetProductMetadataRequest() : ProductID(0)
{
}

void GetProductMetadataRequest::Marshall(const Http::Uri::Query &query)
{
    auto productParam = query.get("id");
    if (productParam->empty())
    {
        throw EmptyValue("id");
    }
    ProductID = boost::lexical_cast<int>(*productParam);
};

GetProductListRequest::GetProductListRequest() : Search(""), Limit(0), Skip(0){};

void GetProductListRequest::Marshall(const Http::Uri::Query &query)
{
    auto searchParam = query.get("name");
    if (searchParam->empty())
    {
        throw EmptyValue("name");
    }
    Search = *searchParam;

    auto limitParam = query.get("limit");
    if (limitParam->empty())
    {
        throw EmptyValue("limit");
    }
    Limit = boost::lexical_cast<int>(*limitParam);

    auto skipParam = query.get("skip");
    if (skipParam->empty())
    {
        throw EmptyValue("skip");
    }
    Skip = boost::lexical_cast<int>(*skipParam);
};

UpdateProductRequest::UpdateProductRequest() : product(0, 0, "", "", 0, 0, 0){};

void UpdateProductRequest::Marshall(const std::string &body)
{
    json j = json::parse(body);
    json object = j["productToUpdate"];

    product.ProductID = object[0]["id"];
    product.StoreID = object[0]["storeID"];
    product.Name = object[0]["name"];
    product.Category = object[0]["category"];
    product.Price = object[0]["price"];
    product.Quantity = object[0]["quantity"];
    product.CounterID = object[0]["counterID"];
};

AddProductRequest::AddProductRequest() : product(0, 0, "", "", 0, 0, 0){};

void AddProductRequest::Marshall(const std::string &body)
{
    json j = json::parse(body);
    json object = j["productToAdd"];

    product.StoreID = object[0]["storeID"];
    product.Name = object[0]["name"];
    product.Category = object[0]["category"];
    product.Price = object[0]["price"];
    product.Quantity = object[0]["quantity"];
    product.CounterID = object[0]["counterID"];
};

ProductMetadata::ProductMetadata() : product(0, 0, "", "", 0, 0, 0){};

void ProductMetadata::Marshall(const Http::Uri::Query &body){};

nlohmann::json ProductMetadata::UnMarshall()
{
    nlohmann::json output;
    output["product"] = product.ProductID;
    output["storeID"] = product.StoreID;
    output["name"] = product.Name;
    output["category"] = product.Category;
    output["price"] = product.Price;
    output["quantity"] = product.Quantity;
    output["counterID"] = product.CounterID;
    return output;
};

ProductList::ProductList() : product(0, 0, "", "", 0, 0, 0){};

void ProductList::Marshall(const std::string &body){};

nlohmann::json ProductList::UnMarshall()
{
    nlohmann::json output;
    output["productID"] = product.ProductID;
    //TODO: think about show name of shop
    output["storeID"] = product.StoreID;
    output["name"] = product.Name;
    output["category"] = product.Category;
    output["price"] = product.Price;
    output["quantity"] = product.Quantity;
    output["counterID"] = product.CounterID;
    return output;
};

UpdateProduct::UpdateProduct() : product(0, 0, "", "", 0, 0, 0){};

void UpdateProduct::Marshall(const std::string &body){};

nlohmann::json UpdateProduct::UnMarshall()
{
    nlohmann::json output;
    output["productID"] = product.ProductID;
    output["storeID"] = product.StoreID;
    output["name"] = product.Name;
    output["category"] = product.Category;
    output["price"] = product.Price;
    output["quantity"] = product.Quantity;
    output["counterID"] = product.CounterID;
    return output;
};

AddProduct::AddProduct() : product(0, 0, "", "", 0, 0, 0){};

void AddProduct::Marshall(const std::string &body){};

nlohmann::json AddProduct::UnMarshall()
{
    nlohmann::json output;
    output["productID"] = product.ProductID;
    return output;
};

GetProductMetadataResponse::GetProductMetadataResponse() : array(std::vector<ProductMetadata>()){};

nlohmann::json GetProductMetadataResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = array.begin(); item != array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["productById"] = outputArray;

    return output;
};

GetProductListResponse::GetProductListResponse() : array(std::vector<ProductList>()){};
nlohmann::json GetProductListResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = array.begin(); item != array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["productSearch"] = outputArray;

    return output;
};

UpdateProductResponse::UpdateProductResponse() : array(std::vector<UpdateProduct>()){};
nlohmann::json UpdateProductResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = array.begin(); item != array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["updatedProduct"] = outputArray;

    return output;
};

AddProductResponse::AddProductResponse() : array(std::vector<AddProduct>()){};
nlohmann::json AddProductResponse::UnMarshall()
{
    nlohmann::json output;
    nlohmann::json outputArray = nlohmann::json::array();
    for (auto item = array.begin(); item != array.end(); ++item)
    {
        outputArray.push_back(item->UnMarshall());
    }
    output["addedProduct"] = outputArray;

    return output;
};
