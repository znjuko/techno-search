//
// Created by fillinmar on 15.04.2021.
//

#include "product_reader.h"

void ProductMetadataReader::Execute(const pqxx::result R)
{
    // todo check
    for (auto row : R)
    { // in this case only one go to loop
        data[0].Product.ProductID = boost::lexical_cast<int>(row[0].c_str());
        data[0].Product.Name = row[1].c_str();
        data[0].Product.Category = row[2].c_str();
        data[0].Product.Price = boost::lexical_cast<int>(row[3].c_str());
        data[0].Product.Quantity = boost::lexical_cast<int>(row[4].c_str());
        data[0].Product.StoreID = boost::lexical_cast<int>(row[5].c_str());
        data[0].Product.CounterID = boost::lexical_cast<int>(row[6].c_str());
    }
}

std::vector<ProductMetadata> ProductMetadataReader::Get()
{
    return data;
}

void ProductListReader::Execute(const pqxx::result R)
{
    int i = 0;
    for (auto row : R)
    {
        data[i].Product.ProductID = boost::lexical_cast<int>(row[0].c_str());
        data[i].Product.Name = row[1].c_str();
        data[i].Product.Category = row[2].c_str();
        data[i].Product.Price = boost::lexical_cast<int>(row[3].c_str());
        data[i].Product.Quantity = boost::lexical_cast<int>(row[4].c_str());
        data[i].Product.StoreID = boost::lexical_cast<int>(row[5].c_str());
        data[i].Product.CounterID = boost::lexical_cast<int>(row[6].c_str());
        i++;
    }
}

std::vector<ProductList> ProductListReader::Get()
{
    return data;
}

void AddProductReader::Execute(const pqxx::result R)
{
    for (auto row : R)
    {
        data[0].Product.ProductID = boost::lexical_cast<int>(row[0].c_str());
    }
}

std::vector<AddProduct> AddProductReader::Get()
{
    return data;
}
