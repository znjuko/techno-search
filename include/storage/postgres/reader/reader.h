//
// Created by fillinmar on 17.04.2021.
//

#ifndef TECHNO_SEARCH_READER_H
#define TECHNO_SEARCH_READER_H

#include "models.h"

#include <pqxx/pqxx>
#include <vector>


class PostgresReader
{
//TODO ask
  public:
    virtual void Execute(const Block &b) = 0;

    virtual ~PostgresReader() = default;
};

class StoreMetadataReader : public PostgresReader
{
  public:
    StoreMetadataReader() = default;

    StoreMetadataReader(const StoreMetadataReader &r) = delete;

    StoreMetadataReader(const std::vector<StoreMetadataReader> &v) = delete;

    void Execute(const Block &b) override;

    std::vector<StoreMetadataReader> Get();

    ~StoreMetadataReader() override = default;

  private:
    std::vector<StoreMetadataReader> data;
};

class StoreListReader : public PostgresReader
{
  public:
    StoreListReader() = default;

    StoreListReader(const StoreList &r) = delete;

    StoreListReader(const std::vector<StoreList> &v) = delete;

    void Execute(const Block &b) override;

    std::vector<StoreList> Get();

    ~StoreListReader() override = default;

  private:
    std::vector<StoreListReader> data;
};

class UpdateStoreReader : public PostgresReader
{
  public:
    UpdateStoreReader() = default;

    UpdateStoreReader(const UpdateStore &r) = delete;

    UpdateStoreReader(const std::vector<UpdateStore> &v) = delete;

    void Execute(const Block &b) override;

    std::vector<UpdateStore> Get();

    ~UpdateStoreReader() override = default;

  private:
    std::vector<UpdateStore> data;
};

class AddStoreReader : public PostgresReader
{
  public:
    AddStoreReader() = default;

    AddStoreReader(const AddStore &r) = delete;

    AddStoreReader(const std::vector<AddStore> &v) = delete;

    void Execute(const Block &b) override;

    std::vector<AddStore> Get();

    ~AddStoreReader() override = default;

  private:
    std::vector<AddStore> data;
};
#endif // TECHNO_SEARCH_READER_H
