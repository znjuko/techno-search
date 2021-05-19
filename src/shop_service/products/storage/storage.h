//
// Created by fillinmar on 14.04.2021.
//

#ifndef TECHNO_SEARCH_PRODUCT_STORAGE_H
#define TECHNO_SEARCH_PRODUCT_STORAGE_H

#include "common_storage.h"
#include "models.h"

#include <memory>

class ProductStorage
{
  private:
    CommonStorage : store;

  public:
    std::shared_ptr<GetProductMetadataResponse> GetStoreMetadata(std::shared_ptr<GetProductMetadataRequest> req){};
    std::shared_ptr<GetProductListResponse> GetListStore(std::shared_ptr<GetProductListRequest> req);
    std::shared_ptr<UpdateProductResponse> UpdateProductMetadata(std::shared_ptr<UpdateProductRequest> req);
    std::shared_ptr<AddProductResponse> AddStore(std::shared_ptr<AddProductRequest> req);
};

#endif // TECHNO_SEARCH_PRODUCT_STORAGE_H
