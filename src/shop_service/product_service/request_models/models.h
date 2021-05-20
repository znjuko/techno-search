//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_MAP_MODELS_H
#define TECHNO_SEARCH_MODELS_H

#include "marshaller.h"
#include "unmarshaller.h"

#include <nlohmann/json.hpp>

class GetProductMetadataRequest : public IMarshaller
{
  public:
    GetProductMetadataRequest();

    void Marshall(const std::string &body) override;

    ~GetProductMetadataRequest() override = default;

    std::string name;
    std::string shopName;
};

class GetProductListRequest : public IMarshaller
{
  public:
    GetProductListRequest();

    void Marshall(const std::string &body) override;

    ~GetProductListRequest() override = default;

    std::string search;
    std::string name;
    std::string shopName;
};

class UpdateProductRequest : public IMarshaller
{
public:
    UpdateProductRequest();

    void Marshall(const std::string &body) override;

    ~UpdateProductRequest() override = default;

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

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~ProductMetadata() override = default;

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

    ProductMetadata* productList;
    int limit;
    int skip;
};

class UpdateProduct : public IMarshaller, public IUnMarshaller
{
public:
    UpdateProduct();
    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~UpdateProduct() override = default;

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

#endif // TECHNO_SEARCH_MAP_MODELS_H
