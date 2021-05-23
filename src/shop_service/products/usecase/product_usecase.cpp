//
// Created by fillinmar on 14.04.2021.
//

#include "product_usecase.h"

std::shared_ptr<GetProductMetadataResponse> ProductManager::GetProductMetadata(
    std::shared_ptr<GetProductMetadataRequest> req)
{
    return storage->GetProductMetadata(req);
}

std::shared_ptr<GetProductListResponse> ProductManager::GetProductList(std::shared_ptr<GetProductListRequest> req)
{
    return storage->GetProductList(req);
}

std::shared_ptr<UpdateProductResponse> ProductManager::UpdateProduct(std::shared_ptr<UpdateProductRequest> req)
{
    return storage->UpdateProduct(req);
}

std::shared_ptr<AddProductResponse> ProductManager::AddProduct(std::shared_ptr<AddProductRequest> req)
{
    return storage->AddProduct(req);
}

ProductManager::ProductManager(const std::shared_ptr<ProductStorage> &storage) : storage(storage)
{
}

ProductManager::~ProductManager() = default;
