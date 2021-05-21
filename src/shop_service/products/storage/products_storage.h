//
// Created by fillinmar on 14.04.2021.
//
#ifndef TECHNO_SEARCH_PRODUCTS_STORAGE_H
#define TECHNO_SEARCH_PRODUCTS_STORAGE_H

#include "models.h"
#include "storage.h"

#include <memory>

class ProductStorage
{
  public:
    std::shared_ptr<GetProductMetadataResponse> GetProductMetadata(std::shared_ptr<GetProductMetadataRequest> req){};
    std::shared_ptr<GetProductListResponse> GetProductStore(std::shared_ptr<GetProductListRequest> req);
    std::shared_ptr<UpdateProductResponse> UpdateProductMetadata(std::shared_ptr<UpdateProductRequest> req);
    std::shared_ptr<AddProductResponse> AddProduct(std::shared_ptr<AddProductRequest> req);

  private:
    std::shared_ptr<PostgresStorage> : storage;
};

#endif
