//
// Created by fillinmar on 14.04.2021.
//
#ifndef TECHNO_SEARCH_PRODUCT_STORAGE_H
#define TECHNO_SEARCH_PRODUCT_STORAGE_H

#include "../../../../include/storage/postgres/storage/postgres_storage.h"
#include "product_models.h"
//#include "storage.h"

#include <memory>

class ProductStorage
{
  public:
    explicit ProductStorage(std::shared_ptr<PostgresStorage> storage);

    std::shared_ptr<GetProductMetadataResponse> GetProductMetadata(std::shared_ptr<GetProductMetadataRequest> req);

    std::shared_ptr<GetProductListResponse> GetProductList(std::shared_ptr<GetProductListRequest> req);

    std::shared_ptr<UpdateProductResponse> UpdateProduct(std::shared_ptr<UpdateProductRequest>
        req);

    std::shared_ptr<AddProductResponse> AddProduct(std::shared_ptr<AddProductRequest> req, std::shared_ptr<AddProductRequest> req2);

    ~ProductStorage();

  private:
    std::shared_ptr<PostgresStorage> storage;
};

#endif
