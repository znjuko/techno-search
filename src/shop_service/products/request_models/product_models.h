//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_PRODUCT_MODELS_H
#define TECHNO_SEARCH_PRODUCT_MODELS_H

#include "common_exceptions.h"
#include "marshaller.h"
#include "unmarshaller.h"

#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <nlohmann/json.hpp>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <string>

using namespace Pistache;

class Product
{
  public:
    int ProductID;
    int StoreID;
    std::string Name;
    std::string Category;
    int Price;
    int Quantity;
    int CounterID;
    Product(int ProductID, int StoreID, std::string Name, std::string Category, int Price, int Quantity, int CounterID)
    {
        this->ProductID = ProductID;
        this->StoreID = StoreID;
        this->Name = Name;
        this->Category = Category;
        this->Price = Price;
        this->Quantity = Quantity;
        this->CounterID = CounterID;
    }
};

class GetProductMetadataRequest : public IQueryMarshaller
{
  public:
    GetProductMetadataRequest();

    ~GetProductMetadataRequest() override = default;

    void Marshall(const Http::Uri::Query &body) override;

    int ProductID;
};

class GetProductListRequest : public IQueryMarshaller
{
  public:
    GetProductListRequest();

    void Marshall(const Http::Uri::Query &body) override;

    ~GetProductListRequest() override = default;

    std::string Search;
    int Limit;
    int Skip;
};

class UpdateProductRequest : public IMarshaller
{
  public:
    UpdateProductRequest();

    void Marshall(const std::string &body) override;

    ~UpdateProductRequest() override = default;

    Product Product;
};

class AddProductRequest : public IMarshaller
{
  public:
    AddProductRequest();
    void Marshall(const std::string &body) override;
    ~AddProductRequest() override = default;

    Product Product;
};

class ProductMetadata : public IQueryMarshaller, public IUnMarshaller
{
  public:
    ProductMetadata();

    void Marshall(const Http::Uri::Query &body) override;

    nlohmann::json UnMarshall() override;

    ~ProductMetadata() override = default;

    Product Product;
};

class ProductList : public IMarshaller, public IUnMarshaller
{
  public:
    ProductList();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~ProductList() override = default;

    Product Product;
};

class UpdateProduct : public IMarshaller, public IUnMarshaller
{
  public:
    UpdateProduct();
    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~UpdateProduct() override = default;

    Product Product;
};

class AddProduct : public IMarshaller, public IUnMarshaller
{
  public:
    AddProduct();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~AddProduct() override = default;

    Product Product;
};

class GetProductMetadataResponse : public IUnMarshaller
{
  public:
    GetProductMetadataResponse();

    nlohmann::json UnMarshall() override;

    ~GetProductMetadataResponse() override = default;

    std::vector<ProductMetadata> array;
};

class GetProductListResponse : public IUnMarshaller
{
  public:
    GetProductListResponse();

    nlohmann::json UnMarshall() override;

    ~GetProductListResponse() override = default;

    std::vector<ProductList> array;
};

class UpdateProductResponse : public IUnMarshaller
{
  public:
    UpdateProductResponse();

    nlohmann::json UnMarshall() override;

    ~UpdateProductResponse() override = default;

    std::vector<UpdateProduct> array;
};

class AddProductResponse : public IUnMarshaller
{
  public:
    AddProductResponse();

    nlohmann::json UnMarshall() override;

    ~AddProductResponse() override = default;

    std::vector<AddProduct> array;
};

#endif // TECHNO_SEARCH_PRODUCT_MODELS_H
