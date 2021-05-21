//
// Created by fillinmar on 14.04.2021.
//

#include "models.h"

#include "struct_mapping/struct_mapping.h"

#include <iomanip>

using namespace Pistache;

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
    if (limitPatam->empty())
    {
        throw EmptyValue("limit");
    }
    Limit = boost::lexical_cast<int>(*limitPatam);

    auto skipParam = query.get("skip");
    if (skipParam->empty())
    {
        throw EmptyValue("skip");
    }
    Skip = boost::lexical_cast<int>(*skipParam);
};

UpdateProductRequest::UpdateProductRequest() : Product(0, 0, "", "", 0, 0, 0){};

void UpdateProductRequest::Marshall(const std::string &body)
{
    // TODO:: check regular is it
    auto jsonData = std::istringstream(R"json(\n" + body + "\n)json");
    nlohmann::json d;

    struct_mapping::map_json_to_struct(Product, jsonData);
};

AddProductRequest::AddProductRequest() : Product(0, 0, "", "", 0, 0, 0){};

void AddProductRequest::Marshall(const std::string &body)
{
    // TODO:: check regular is it
    auto jsonData = std::istringstream(R"(json)" + body + R"(json)");

    struct_mapping::map_json_to_struct(Product, jsonData);
};

ProductMetadata::ProductMetadata() : Product(0, 0, "", "", 0, 0, 0){};

void ProductMetadata::Marshall(const Http::Uri::Query &body){};

nlohmann::json ProductMetadata::UnMarshall()
{
    nlohmann::json output;
    output["product"] = Product.ProductID;
    output["store"] = Product.StoreID;
    output["name"] = Product.Name;
    output["category"] = Product.Category;
    output["price"] = Product.Price;
    output["quantity"] = Product.Quantity;
    output["counter"] = Product.CounterID;
    return output;
};

ProductList::ProductList() : Product(0, 0, "", "", 0, 0, 0){};
void ProductList::Marshall(const std::string &body){};
nlohmann::json ProductList::UnMarshall()
{
    nlohmann::json output;
    output["product"] = Product.ProductID;
    output["store"] = Product.StoreID;
    output["name"] = Product.Name;
    output["category"] = Product.Category;
    output["price"] = Product.Price;
    output["quantity"] = Product.Quantity;
    output["counter"] = Product.CounterID;
    return output;
};

UpdateProduct::UpdateProduct() : Product(0, 0, "", "", 0, 0, 0){};
void UpdateProduct::Marshall(const std::string &body){};
nlohmann::json UpdateProduct::UnMarshall()
{
    nlohmann::json output;
    output["product"] = Product.ProductID;
    output["store"] = Product.StoreID;
    output["name"] = Product.Name;
    output["category"] = Product.Category;
    output["price"] = Product.Price;
    output["quantity"] = Product.Quantity;
    output["counter"] = Product.CounterID;
    return output;
};

AddProduct::AddProduct() : Product(0, 0, "", "", 0, 0, 0){};

void AddProduct::Marshall(const std::string &body){};

nlohmann::json AddProduct::UnMarshall()
{
    nlohmann::json output;
    output["product"] = Product.ProductID;
    output["store"] = Product.StoreID;
    output["name"] = Product.Name;
    output["category"] = Product.Category;
    output["price"] = Product.Price;
    output["quantity"] = Product.Quantity;
    output["counter"] = Product.CounterID;
    return output;
};

GetProductMetadataResponse::GetProductMetadataResponse() : array(std::vector<ProductMetadata>()){};
nlohmann::json GetProductMetadataResponse::UnMarshall()
{
    nlohmann::json output;
    output["value"] = output;

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
    output["values"] = outputArray;

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
    output["values"] = outputArray;

    return output;
};

AddProductResponse::AddProductResponse() : array(std::vector<AddProduct>()){};
nlohmann::json AddProductResponse::UnMarshall()
{
    nlohmann::json output;
    output["value"] = output;

    return output;
};
