//
// Created by fillinmar on 15.04.2021.
//

#include "stores_reader.h"

void StoreMetadataReader::Execute(const pqxx::result R)
{
    for (auto row : R)
    { // in this case only one go to loop
        data[0].Store.StoreID = boost::lexical_cast<int>(row[0].c_str());
        data[0].Store.Name = row[1].c_str();
        data[0].Store.OpenAt = boost::lexical_cast<float>(row[2].c_str());
        data[0].Store.CloseAt = boost::lexical_cast<float>(row[3].c_str());
        data[0].Store.Address = (row[4].c_str());
    }
}

std::vector<StoreMetadata> StoreMetadataReader::Get()
{
    return data;
}

void StoreListReader::Execute(const pqxx::result R)
{
    int i = 0;
    for (auto row : R)
    {
        data[i].Store.StoreID = boost::lexical_cast<int>(row[0].c_str());
        data[i].Store.Name = row[1].c_str();
        data[i].Store.OpenAt = boost::lexical_cast<float>(row[2].c_str());
        data[i].Store.CloseAt = boost::lexical_cast<float>(row[3].c_str());
        data[i].Store.Address = (row[4].c_str());
        i++;
    }
}

std::vector<StoreList> StoreListReader::Get()
{
    return data;
}

void AddStoreReader::Execute(const pqxx::result R)
{
    for (auto row : R)
    {
        data[0].Store.StoreID = boost::lexical_cast<int>(row[0].c_str());
    }
}

std::vector<AddStore> AddStoreReader::Get()
{
    return data;
}
