//
// Created by fillinmar on 31.03.2021.
//
#include "marshaller.h"
#include "postgres_storage.h"
#include "product_delivery.h"
#include "product_models.h"
#include "product_storage.h"
#include "product_usecase.h"
#include "request_reader.h"

#include <fstream>
#include <gtest/gtest.h>
#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>
#include <pqxx/pqxx>
#include <signal.h>
const std::string &body_update_product = "{\n"
                                         "  \"productToUpdate\": [\n"
                                         "    {\n"
                                         "      \"id\": 1,\n"
                                         "      \"storeID\": 1,\n"
                                         "      \"name\": \"Cola\",\n"
                                         "      \"category\": \"Drinks\",\n"
                                         "      \"price\": 44,\n"
                                         "      \"quantity\": 5,\n"
                                         "      \"counterID\": 1\n"
                                         "    }\n"
                                         "  ]\n"
                                         "}";
const std::string &body_add_product = "{\n"
                                      "  \"productToAdd\": [\n"
                                      "    {\n"
                                      "      \"storeID\": 1,\n"
                                      "      \"name\": \"Cola\",\n"
                                      "      \"category\": \"Drinks\",\n"
                                      "      \"price\": 44,\n"
                                      "      \"quantity\": 5,\n"
                                      "      \"counterID\": 1\n"
                                      "    }\n"
                                      "  ]\n"
                                      "}";
std::string id = "id";
std::string value_id = "6";

std::string name = "name";
std::string limit = "limit";
std::string skip = "skip";
std::string valueName = "name";
std::string valueLimit = "5";
std::string valueSkip = "2";

TEST(update_product_test_request, basic_test)
{
    std::shared_ptr<JsonRequestBodyReader> bodyReaderTest;
    auto reqReader = std::make_shared<UpdateProductRequest>();
    reqReader->Marshall(body_update_product);
    ASSERT_EQ(reqReader->product.ProductID, 1);
    ASSERT_EQ(reqReader->product.StoreID, 1);
    ASSERT_EQ(reqReader->product.CounterID, 1);
    ASSERT_EQ(reqReader->product.Quantity, 5);
    ASSERT_EQ(reqReader->product.Price, 44);
    ASSERT_EQ(reqReader->product.Name, "Cola");
    ASSERT_EQ(reqReader->product.Category, "Drinks");
}

TEST(add_product_test_request, basic_test)
{
    std::shared_ptr<JsonRequestBodyReader> bodyReaderTest;
    auto reqReader = std::make_shared<AddProductRequest>();
    reqReader->Marshall(body_add_product);
    ASSERT_EQ(reqReader->product.CounterID, 1);
    ASSERT_EQ(reqReader->product.Quantity, 5);
    ASSERT_EQ(reqReader->product.Price, 44);
    ASSERT_EQ(reqReader->product.Name, "Cola");
    ASSERT_EQ(reqReader->product.Category, "Drinks");
}

TEST(get_metadata_product_test_request, basic_test)
{
    std::shared_ptr<RequestQueryReader> queryReaderTest;

    auto reqReader = std::make_shared<GetProductMetadataRequest>();

    Http::Uri::Query q;
    q.add(id, value_id);

    reqReader->Marshall(q);
    ASSERT_EQ(reqReader->ProductID, 6);
}

TEST(get_list_product_test_request, basic_test)
{
    std::shared_ptr<RequestQueryReader> queryReaderTest;

    auto reqReader = std::make_shared<GetProductListRequest>();

    Http::Uri::Query q;
    q.add(name, valueName);
    q.add(limit, valueLimit);
    q.add(skip, valueSkip);

    reqReader->Marshall(q);
    ASSERT_EQ(reqReader->Search, valueName);
    ASSERT_EQ(reqReader->Limit, 5);
    ASSERT_EQ(reqReader->Skip, 2);
}
Product productToTest(1, 1, "Cola", "Drinks", 50, 3, 2);
