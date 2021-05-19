//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_PRODUCT_MANAGER_H
#define TECHNO_SEARCH_PRODUCT_MANAGER_H

#include "models.h"
#include "storage.h"

class ProductManager
{
  public:
    ProductManager() = delete;
    explicit ProductManager(const ProductManager &storage) noexcept;
    GetProductMetadataResponse GetStoreMetadata(GetProductMetadataRequest req){};
    GetProductListResponse GetListStore(GetProductListRequest req);
    UpdateProductResponse UpdateProductMetadata(UpdateProductRequest req);
    AddProductResponse AddStore(AddProductRequest req);
    ~ProductManager();

  private:
    ProductStorage product;
};

#endif // TECHNO_SEARCH_PRODUCT_MANAGER_H
