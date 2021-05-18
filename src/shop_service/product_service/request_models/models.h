//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_PRODUCT_MODELS_H
#define TECHNO_SEARCH_PRODUCT_MODELS_H

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
    int limit;
    int skip;
};

class UpdateProductRequest : public IMarshaller
{
public:
    UpdateProductRequest();

    void Marshall(const std::string &body) override;

    ~UpdateProductRequest() override = default;

    int ProductID;
    std::string shopName;
    std::string name;
    std::string category;
    int price;
    int quantity;
    std::string articul;
};

class AddProductRequest : public IMarshaller
{
public:
    AddProductRequest();
    void Marshall(const std::string &body) override;
    ~AddProductRequest() override = default;

    std::string shopName;
    std::string name;
    std::string category;
    int price;
    int quantity;
    std::string articul;
};

class ProductMetadata : public IMarshaller, public IUnMarshaller
{
  public:
    ProductMetadata();

    void Marshall(const Http::Uri::Query &body) override;

    nlohmann::json UnMarshall() override;

    ~ProductMetadata() override = default;

    int ProductID;
    std::string shopName;
    std::string name;
    std::string category;
    int price;
    int quantity;
    std::string articul;
};

class ProductList: public IMarshaller, public IUnMarshaller
{
  public:
    ProductList();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~ProductList() override = default;

    int ProductID;
    std::string shopName;
    std::string name;
    std::string category;
    int price;
    int quantity;
    std::string articul;
};

class UpdateProduct : public IMarshaller, public IUnMarshaller
{
public:
    UpdateProduct();
    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~UpdateProduct() override = default;

    int ProductID;
    std::string shopName;
    std::string name;
    std::string category;
    int price;
    int quantity;
    std::string articul;
};

class AddProduct: public IMarshaller, public IUnMarshaller
{
public:
    AddProduct();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~AddProduct() override = default;

    std::string shopName;
    std::string name;
    std::string category;
    int price;
    int quantity;
    std::string articul;
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
