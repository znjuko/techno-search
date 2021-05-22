//
// Created by fillinmar on 14.04.2021.
//

#include "product_storage.h"

#include "../query/query.h"
#include "../reader/product_reader.h"

#include <utility>

std::shared_ptr<GetProductMetadataResponse> ProductStorage::GetProductMetadata(
    std::shared_ptr<GetProductMetadataRequest> req)
{
    auto q = std::shared_ptr<GetProductMetadataQuery>();
    q->SetupQuery(req);
    std::shared_ptr<ProductMetadataReader> reader;

    storage->Select(q, reader);

    auto res = std::shared_ptr<GetProductMetadataResponse>();
    res->array = std::move(reader->Get());
    return res;
}

std::shared_ptr<GetProductListResponse> ProductStorage::GetProductList(std::shared_ptr<GetProductListRequest> req)
{
    auto q = std::shared_ptr<GetProductListQuery>();
    q->SetupQuery(req);
    std::shared_ptr<ProductListReader> reader;

    storage->Select(q, reader);

    auto res = std::shared_ptr<GetProductListResponse>();
    res->array = std::move(reader->Get());
    return res;
}

std::shared_ptr<AddProductResponse> ProductStorage::AddProduct(std::shared_ptr<AddProductRequest> req)
{
    auto q = std::shared_ptr<AddProductQuery>();
    q->SetupQuery(req);
    std::shared_ptr<AddProductReader> reader;

    storage->Select(q, reader);

    auto res = std::shared_ptr<AddProductResponse>();
    res->array = std::move(reader->Get());
    return res;
}

ProductStorage::~ProductStorage()
{
}

ProductStorage::ProductStorage(std::shared_ptr<PostgresStorage> storage) : storage(storage)
{
}
