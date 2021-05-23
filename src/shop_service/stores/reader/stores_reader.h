//
// Created by fillinmar on 17.04.2021.
//

#ifndef TECHNO_SEARCH_STORES_READER_H
#define TECHNO_SEARCH_STORES_READER_H

#include "models.h"
#include "postgres_reader.h"

#include <pqxx/pqxx>
#include <vector>

class StoreMetadataReader : public PostgresReader
{
  public:
    StoreMetadataReader() = default;

    StoreMetadataReader(const StoreMetadataReader &r) = delete;

    StoreMetadataReader(const std::vector<StoreMetadataReader> &v) = delete;

    void Execute(const pqxx::result R) override;

    std::vector<StoreMetadata> Get();

    ~StoreMetadataReader() override = default;

  private:
    std::vector<StoreMetadata> data;
};

class StoreListReader : public PostgresReader
{
  public:
    StoreListReader() = default;

    StoreListReader(const StoreList &r) = delete;

    StoreListReader(const std::vector<StoreList> &v) = delete;

    void Execute(const pqxx::result R) override;

    std::vector<StoreList> Get();

    ~StoreListReader() override = default;

  private:
    std::vector<StoreList> data;
};

class AddStoreReader : public PostgresReader
{
  public:
    AddStoreReader() = default;

    AddStoreReader(const AddStore &r) = delete;

    AddStoreReader(const std::vector<AddStore> &v) = delete;

    void Execute(const pqxx::result R) override;

    std::vector<AddStore> Get();

    ~AddStoreReader() override = default;

  private:
    std::vector<AddStore> data;
};
#endif
