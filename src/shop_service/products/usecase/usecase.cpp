//
// Created by fillinmar on 14.04.2021.
//

#include "usecase.h"

std::shared_ptr<GetProductMetadataResponse> ProductManager::GetProductMetadata(std::shared_ptr<GetProductMetadataRequest> req)
{
    return storage.GetProductMetadata(req);
}

std::shared_ptr<GetProductListResponse> ProductManager::GetListProduct(
    std::shared_ptr<GetProductListRequest> req)
{
    return storage.GetListStore(req);
}

std::shared_ptr<UpdateProductResponse> ProductManager::UpdateProductMetadata(std::shared_ptr<UpdateProductRequest> req)
{
    return storage.UpdateStoreMetadata(req);
}

std::shared_ptr<AddProductResponse> ProductManager::AddProduct(std::shared_ptr<AddProductRequest> req)
{
    return storage.UpdateStoreMetadata(req);
}

ProductManager::ProductManager(const ProductStorage &storage): storage(storage)
{
}

ProductManager::~ProductManager() = default;
