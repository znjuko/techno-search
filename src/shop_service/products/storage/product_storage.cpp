//
// Created by fillinmar on 14.04.2021.
//

#include "product_storage.h"

#include "../query/product_query.h"
#include "../reader/product_reader.h"

#include <utility>

std::shared_ptr<GetProductMetadataResponse> ProductStorage::GetProductMetadata(
    std::shared_ptr<GetProductMetadataRequest> req)
{
    auto q = std::make_shared<GetProductMetadataQuery>();
    q->SetupQuery(req);

    auto reader = std::make_shared<ProductMetadataReader>();
    storage->Select(q, reader);

    auto res = std::make_shared<GetProductMetadataResponse>();
    res->array = reader->Get();
    return res;
}

std::shared_ptr<GetProductListResponse> ProductStorage::GetProductList(std::shared_ptr<GetProductListRequest> req)
{
    auto q = std::make_shared<GetProductListQuery>();
    q->SetupQuery(req);

    auto reader = std::make_shared<ProductListReader>();
    storage->Select(q, reader);

    auto res = std::make_shared<GetProductListResponse>();
    res->array = reader->Get();
    return res;
}

std::shared_ptr<AddProductResponse> ProductStorage::AddProduct(std::shared_ptr<AddProductRequest> req, std::shared_ptr<AddProductRequest> req2)
{
    auto q = std::make_shared<AddProductQuery>();
    q->SetupQuery(req);
    storage->Insert(q);

    auto q2 = std::make_shared<AddProductQuery>();
    q2->SetupQueryForId(req2); //translate to postgres request
    auto reader = std::make_shared<AddProductReader>();
    storage->Select(q2, reader);//return Id

    auto res = std::make_shared<AddProductResponse>();
    res->array = reader->Get();
    return res;
}

ProductStorage::~ProductStorage()
{
}

std::shared_ptr<UpdateProductResponse> ProductStorage::UpdateProduct(std::shared_ptr<UpdateProductRequest> req, std::shared_ptr<UpdateProductRequest> req2)
{
    auto q = std::make_shared<UpdateProductQuery>();
    q->SetupQuery(req);
    storage->Insert(q);

    auto q2 = std::make_shared<UpdateProductQuery>();
    q2->SetupQueryForUpdatedProduct(req2);
    auto reader = std::make_shared<UpdateProductReader>();
    storage->Select(q2, reader);

    auto res = std::make_shared<UpdateProductResponse>();
    res->array = reader->Get();
    return res;
}

ProductStorage::ProductStorage(std::shared_ptr<PostgresStorage> storage) : storage(storage)
{
}
