//
// Created by fillinmar on 15.04.2021.
//

#ifndef TECHNO_SEARCH_COMMON_STORAGE_H
#define TECHNO_SEARCH_STORAGE_H

#include "query.h"
#include "reader.h"

#include <pqxx/pqxx>


class PostgresStorage
{
  public:
    PostgresStorage() = delete;

    explicit PostgresStorage(const ClientOptions &opts);

    void Insert(const PostgresQuery &q);

    void Select(std::shared_ptr<PostgresQuery> q, std::shared_ptr<PostgresReader> r);

    ~PostgresStorage() = default;

  private:
    postgres::Client client;
};

#endif // TECHNO_SEARCH_COMMON_STORAGE_H
