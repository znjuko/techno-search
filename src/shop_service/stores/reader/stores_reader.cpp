//
// Created by fillinmar on 15.04.2021.
//

#include "stores_reader.h"

void StoreMetadataReader::Execute(const pqxx::result R)
{
    for (auto row : R)
    { // in this case only one go to loop
        data[0].store.StoreID = boost::lexical_cast<int>(row[0].c_str());
        data[0].store.Name = row[1].c_str();
        data[0].store.OpenAt = boost::lexical_cast<float>(row[2].c_str());
        data[0].store.CloseAt = boost::lexical_cast<float>(row[3].c_str());
        data[0].store.Address = (row[4].c_str());
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
        data[i].store.StoreID = boost::lexical_cast<int>(row[0].c_str());
        data[i].store.Name = row[1].c_str();
        data[i].store.OpenAt = boost::lexical_cast<float>(row[2].c_str());
        data[i].store.CloseAt = boost::lexical_cast<float>(row[3].c_str());
        data[i].store.Address = (row[4].c_str());
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
        data[0].store.StoreID = boost::lexical_cast<int>(row[0].c_str());
    }
}
std::vector<AddStore> AddStoreReader::Get()
{
    return data;
}

void UpdateStoreReader::Execute(const pqxx::result R)
{
    for (auto row : R)
    {
        data[0].store.StoreID = boost::lexical_cast<int>(row[0].c_str());
    }
}

std::vector<UpdateStore> UpdateStoreReader::Get()
{
    return data;
}


