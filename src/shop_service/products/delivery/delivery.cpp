//
// Created by fillinmar on 14.04.2021.
//

#include "delivery.h"

void ProductService::GetProductMetadata(const Http::Request &req, Http::ResponseWriter res)
{
    std::shared_ptr<GetProductMetadataRequest> reqReader;
    try
    {
        queryReader.ReadRequest(reqReader, req);
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong product id", &res);
        return;
    }

    std::shared_ptr<GetProductMetadataResponse> respWriter;
    try
    {
        respWriter = manager.GetProductMetadata(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.WriteResponse(respWriter, &res);
}

void ProductService::GetProductList(const Http::Request &req, Http::ResponseWriter res)
{
    std::shared_ptr<GetProductMetadataRequest> reqReader;
    try
    {
        queryReader.ReadRequest(reqReader, req);
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong products` name", &res);
        return;
    }

    std::shared_ptr<GetProductMetadataResponse> respWriter;
    try
    {
        respWriter = manager.GetProductList(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.WriteResponse(respWriter, &res);
}

void ProductService::UpdateProduct(const Http::Request &req, Http::ResponseWriter res)
{
    std::shared_ptr<UpdateProductRequest> reqReader;
    try
    {
        bodyReader.ReadRequest(reqReader, req);
    }
    catch (const boost::exception &e)
    {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong product id", &res);
        return;
    }

    std::shared_ptr<UpdateProductResponse> respWriter;
    try
    {
        respWriter = manager.UpdateProduct(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.WriteResponse(respWriter, &res);
}

void ProductService::AddProduct(const Http::Request &req, Http::ResponseWriter res)
{
    std::shared_ptr<AddProductRequest> reqReader;
    try
    {
        bodyReader.ReadRequest(reqReader, req);
    }
    catch (const boost::exception &e)
    {
        errorWriter.WriteError(Http::Code::Bad_Request, "wrong product metadata", &res);
        return;
    }

    std::shared_ptr<AddProductResponse> respWriter;
    try
    {
        respWriter = manager.AddProduct(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter.WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter.WriteResponse(respWriter, &res);
}
void ProductService::SetupService(Rest::Router router)
{
    router.addRoute(Http::Method::Get, "api/v1/product",
                    Pistache::Rest::Routes::bind(&ProductService::GetProductMetadata, this));

    router.addRoute(Http::Method::Get, "api/v1/product/search",
                    Pistache::Rest::Routes::bind(&ProductService::GetProductList, this));

    router.addRoute(Http::Method::Post, "api/v1/product",
                    Pistache::Rest::Routes::bind(&ProductService::AddProduct, this));

    router.addRoute(Http::Method::Put, "api/v1/product",
                    Pistache::Rest::Routes::bind(&ProductService::UpdateProduct, this));
}
