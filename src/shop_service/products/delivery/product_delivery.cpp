//
// Created by fillinmar on 14.04.2021.
//

#include "product_delivery.h"

void ProductService::GetProductMetadata(const Rest::Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<GetProductMetadataRequest>();
    //    std::shared_ptr<GetProductMetadataRequest> reqReader;
    try
    {
        queryReader->ReadRequest(reqReader, req);
    }
    catch (const EmptyValue &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong product id", &res);
        return;
    }

    std::shared_ptr<GetProductMetadataResponse> respWriter;
    try
    {
        respWriter = manager->GetProductMetadata(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}

void ProductService::GetProductList(const Rest::Request &req, Http::ResponseWriter res)
{
    //    std::shared_ptr<GetProductListRequest> reqReader;
    auto reqReader = std::make_shared<GetProductListRequest>();
    try
    {
        queryReader->ReadRequest(reqReader, req);
    }
    catch (const EmptyValue &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    catch (const boost::bad_lexical_cast &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong products` name", &res);
        return;
    }

    std::shared_ptr<GetProductListResponse> respWriter;
    try
    {
        respWriter = manager->GetProductList(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}

void ProductService::UpdateProduct(const Rest::Request &req, Http::ResponseWriter res)
{
    //    std::shared_ptr<UpdateProductRequest> reqReader;
    auto reqReader = std::make_shared<UpdateProductRequest>();
    try
    {
        bodyReader->ReadRequest(reqReader, req);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    catch (const boost::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong product id", &res);
        return;
    }

    std::shared_ptr<UpdateProductResponse> respWriter;
    try
    {
        respWriter = manager->UpdateProduct(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}

void ProductService::AddProduct(const Rest::Request &req, Http::ResponseWriter res)
{
    auto reqReader = std::make_shared<AddProductRequest>();
    //    std::shared_ptr<AddProductRequest> reqReader;
    try
    {
        bodyReader->ReadRequest(reqReader, req);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, e.what(), &res);
        return;
    }
    catch (const boost::exception &e)
    {
        errorWriter->WriteError(Http::Code::Bad_Request, "wrong product metadata", &res);
        return;
    }

    std::shared_ptr<AddProductResponse> respWriter;
    try
    {
        respWriter = manager->AddProduct(reqReader);
    }
    catch (const std::exception &e)
    {
        errorWriter->WriteError(Http::Code::Conflict, e.what(), &res);
        return;
    }
    responseWriter->WriteResponse(respWriter, &res);
}
// void ProductService::SetupService(std::shared_ptr<Rest::Router> router)
//{
//     router->addRoute(Http::Method::Get, "api/v1/product",
//                     Pistache::Rest::Routes::bind(&ProductService::GetProductMetadata, this));
//
//     router->addRoute(Http::Method::Get, "api/v1/product/search",
//                     Pistache::Rest::Routes::bind(&ProductService::GetProductList, this));
//
//     router->addRoute(Http::Method::Post, "api/v1/product",
//                     Pistache::Rest::Routes::bind(&ProductService::AddProduct, this));
//
//     router->addRoute(Http::Method::Put, "api/v1/product",
//                     Pistache::Rest::Routes::bind(&ProductService::UpdateProduct, this));
// }
//
namespace Generic
{

void handleReady(const Rest::Request &, Http::ResponseWriter response)
{
    response.send(Http::Code::Ok, "1");
}

} // namespace Generic

void ProductService::SetupService(Rest::Router &router)
{
    //    Routes::Post(router, "/record/:name/:value?", Routes::bind(&StatsEndpoint::doRecordMetric, this));
    using namespace Rest;

    Routes::Post(router, "/record/:name/:value?", Routes::bind(&ProductService::AddProduct, this));
    Routes::Get(router, "/product", Routes::bind(&ProductService::GetProductMetadata, this));
    Routes::Get(router, "/product/search", Routes::bind(&ProductService::GetProductList, this));
    Routes::Get(router, "/readyy", Routes::bind(&Generic::handleReady));
    Routes::Put(router, "/auth", Routes::bind(&ProductService::UpdateProduct, this));
}
ProductService::ProductService(std::shared_ptr<JsonResponseWriter> responseWriter,
                               std::shared_ptr<JsonRequestBodyReader> bodyReader,
                               std::shared_ptr<ErrorResponseWriter> errorWriter,
                               std::shared_ptr<RequestQueryReader> queryReader, std::shared_ptr<ProductManager> manager)
    : responseWriter(responseWriter), bodyReader(bodyReader), queryReader(queryReader), manager(manager),
      errorWriter(errorWriter)
{
}
