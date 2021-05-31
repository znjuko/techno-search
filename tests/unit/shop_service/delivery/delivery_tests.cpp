//
// Created by fillinmar on 31.03.2021.
//
#include "product_delivery.h"
#include "store_delivery.h"

#include <fstream>
#include <gtest/gtest.h>
const int a = 5;
const int b = 5;

TEST(DATE_CHECK, GET_NEXT_MONTH)
{
    ASSERT_EQ(a, b);
    //    GetProductMetadata(req, res)
}

// void ProductService::GetProductMetadata(const Rest::Request &req, Http::ResponseWriter res)
//{
//    auto reqReader = std::make_shared<GetProductMetadataRequest>();
//    try
//    {
//        queryReader->ReadRequest(reqReader, req);
//    }
//    catch (const EmptyValue &e)
//    {
//        errorWriter->WriteError(Http::Code::Bad_Request, "empty id", &res);
//        return;
//    }
//    catch (const boost::bad_lexical_cast &e)
//    {
//        errorWriter->WriteError(Http::Code::Bad_Request, "wrong format of product id, need int", &res);
//        return;
//    }
//
//    std::shared_ptr<GetProductMetadataResponse> respWriter;
//    try
//    {
//        respWriter = manager->GetProductMetadata(reqReader);
//    }
//    catch (const std::exception &e)
//    {
//        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
//        return;
//    }
//
//    responseWriter->WriteResponse(respWriter, &res);
//}
//
// void ProductService::GetProductList(const Rest::Request &req, Http::ResponseWriter res)
//{
//    auto reqReader = std::make_shared<GetProductListRequest>();
//    try
//    {
//        queryReader->ReadRequest(reqReader, req);
//    }
//    catch (const EmptyValue &e)
//    {
//        errorWriter->WriteError(Http::Code::Bad_Request, "no name is entered", &res);
//        return;
//    }
//
//    std::shared_ptr<GetProductListResponse> respWriter;
//    try
//    {
//        respWriter = manager->GetProductList(reqReader);
//    }
//    catch (const std::exception &e)
//    {
//        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
//        return;
//    }
//    responseWriter->WriteResponse(respWriter, &res);
//}
//
// void ProductService::UpdateProduct(const Rest::Request &req, Http::ResponseWriter res)
//{
//    auto reqReader = std::make_shared<UpdateProductRequest>();
//    try
//    {
//        bodyReader->ReadRequest(reqReader, req);
//    }
//    catch (const EmptyValue &e)
//    {
//        errorWriter->WriteError(Http::Code::Bad_Request, "not all fields are filled out", &res);
//        return;
//    }
//    catch (const boost::bad_lexical_cast &e)
//    {
//        errorWriter->WriteError(Http::Code::Bad_Request, "wrong type of fields or field", &res);
//        return;
//    }
//    catch (const std::exception &e)
//    {
//        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
//        return;
//    }
//
//    auto reqReaderForMetadata = reqReader;
//
//    std::shared_ptr<UpdateProductResponse> respWriter;
//    try
//    {
//        respWriter = manager->UpdateProduct(reqReader, reqReaderForMetadata);
//    }
//    catch (const std::exception &e)
//    {
//        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
//        return;
//    }
//    responseWriter->WriteResponse(respWriter, &res);
//}
//
// void ProductService::AddProduct(const Rest::Request &req, Http::ResponseWriter res)
//{
//    auto reqReader = std::make_shared<AddProductRequest>();
//    try
//    {
//        bodyReader->ReadRequest(reqReader, req);
//    }
//    catch (const EmptyValue &e)
//    {
//        errorWriter->WriteError(Http::Code::Bad_Request, "not all fields are filled out", &res);
//        return;
//    }
//    catch (const boost::bad_lexical_cast &e)
//    {
//        errorWriter->WriteError(Http::Code::Bad_Request, "wrong type of fields", &res);
//        return;
//    }
//    catch (const std::exception &e)
//    {
//        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
//        return;
//    }
//
//    auto reqReaderForId = reqReader;
//
//    std::shared_ptr<AddProductResponse> respWriter;
//    try
//    {
//        respWriter = manager->AddProduct(reqReader, reqReaderForId);
//    }
//    catch (const std::exception &e)
//    {
//        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
//        return;
//    }
//    responseWriter->WriteResponse(respWriter, &res);
//}
//
// void ProductService::SetupService(Rest::Router &router)
//{
//
//    using namespace Rest;
//
//    Routes::Post(router, "/product", Routes::bind(&ProductService::AddProduct, this));
//    Routes::Get(router, "/product", Routes::bind(&ProductService::GetProductMetadata, this));
//    Routes::Get(router, "/product/search", Routes::bind(&ProductService::GetProductList, this));
//    Routes::Put(router, "/product", Routes::bind(&ProductService::UpdateProduct, this));
//}
// ProductService::ProductService(std::shared_ptr<JsonResponseWriter> responseWriter,
//                               std::shared_ptr<JsonRequestBodyReader> bodyReader,
//                               std::shared_ptr<ErrorResponseWriter> errorWriter,
//                               std::shared_ptr<RequestQueryReader> queryReader, std::shared_ptr<ProductManager>
//                               manager)
//    : responseWriter(std::move(std::move(std::move(responseWriter)))), bodyReader(std::move(bodyReader)),
//    queryReader(std::move(queryReader)), manager(std::move(manager)),
//      errorWriter(std::move(errorWriter))
//{
//}
//
