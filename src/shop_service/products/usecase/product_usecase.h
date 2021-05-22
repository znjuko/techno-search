//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_PRODUCT_USECASE_H
#define TECHNO_SEARCH_PRODUCT_USECASE_H

#include "product_models.h"
#include "product_storage.h"

class ProductManager
{
  public:
    ProductManager() = delete;
    ProductManager(const std::shared_ptr<ProductStorage> &storage);
    std::shared_ptr<GetProductMetadataResponse> GetProductMetadata(std::shared_ptr<GetProductMetadataRequest> req);
    std::shared_ptr<GetProductListResponse> GetProductList(std::shared_ptr<GetProductListRequest> req);
    std::shared_ptr<UpdateProductResponse> UpdateProduct(std::shared_ptr<UpdateProductRequest> req);
    std::shared_ptr<AddProductResponse> AddProduct(std::shared_ptr<AddProductRequest> req);

    ~ProductManager();

  private:
    std::shared_ptr<ProductStorage> storage;
};

#endif
