//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_PRODUCTS_MANAGER_H
#define TECHNO_SEARCH_PRODUCTS_MANAGER_H

#include "models.h"
#include "products_storage.h"

class ProductManager
{
  public:
    ProductManager() = delete;
    ProductManager(const ProductStorage &storage);
    std::shared_ptr<GetProductMetadataResponse> GetProductMetadata(std::shared_ptr<GetProductMetadataRequest> req){};
    std::shared_ptr<GetProductListResponse> GetListProduct(std::shared_ptr<GetProductListRequest> req);
    std::shared_ptr<UpdateProductResponse> UpdateProductMetadata(std::shared_ptr<UpdateProductRequest> req);
    std::shared_ptr<AddProductResponse> AddProduct(std::shared_ptr<AddProductRequest> req);
    ~ProductManager();

  private:
    ProductStorage storage;
};

#endif