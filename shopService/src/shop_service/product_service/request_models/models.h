//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_MODELS_H
#define TECHNO_SEARCH_MODELS_H

#include "marshaller.h"
#include "unmarshaller.h"

#include <nlohmann/json.hpp>

class GetProductMetadataRequest : public IMarshaller
{
  public:
    GetStoreMetadataRequest();

    void Marshall(const std::string &body) override;

    ~GetStoreMetadataRequest() override = default;

    string name;
    string shopName;
};

class GetProductListRequest : public IMarshaller
{
  public:
    GetStoreListRequest();

    void Marshall(const std::string &body) override;

    ~GetProductListRequest() override = default;

    string search;
    string name;
    string shopName;
};

class UpdateProductRequest : public IMarshaller
{
public:
    UpdateProductRequest();

    void Marshall(const std::string &body) override;

    ~UpdateProductRequest() override = default;

    string shopName;
    string name;
    string category;
    int price;
    int quantity;
    string articul;
};

class AddProductRequest : public IMarshaller
{
public:
    AddProductRequest();
    void Marshall(const std::string &body) override;
    ~AddProductRequest() override = default;

    string shopName;
    string name;
    string category;
    int price;
    int quantity;
    string articul;
};

class ProductMetadata : public IMarshaller, public IUnMarshaller
{
  public:
    ProductMetadata();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~StoreMetadata() override = default;

    string shopName;
    string name;
    string category;
    int price;
    int quantity;
    string articul;
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
    ProductStore();
    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~UpdateProduct() override = default;

    string shopName;
    string name;
    string category;
    int price;
    int quantity;
    string articul;
};

class AddProduct: public IMarshaller, public IUnMarshaller
{
public:
    AddProduct();

    void Marshall(const std::string &body) override;

    nlohmann::json UnMarshall() override;

    ~AddProduct() override = default;

    string shopName;
    string name;
    string category;
    int price;
    int quantity;
    string articul;
};

class GetProductMetadataResponse : public IUnMarshaller
{
  public:
    GetProductMetadataResponse();

    nlohmann::json UnMarshall() override;

    ~GetStoreMetadataResponse() override = default;

    std::vector<ProductMetadata> array;
};

class GetStoreListResponse : public IUnMarshaller
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

#endif // TECHNO_SEARCH_MODELS_H
