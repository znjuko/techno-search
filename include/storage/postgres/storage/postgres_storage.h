//
// Created by fillinmar on 15.04.2021.
//

#ifndef TECHNO_SEARCH_POSTGRES_STORAGE_H
#define TECHNO_SEARCH_POSTGRES_STORAGE_H

#include "../query/postgres_query.h"
#include "../reader/postgres_reader.h"
//#include "query.h"
//#include "reader.h"

#include <pqxx/pqxx>

class PostgresStorage
{
  public:
    PostgresStorage() = delete;

    explicit PostgresStorage(const char *options);

    void Insert(std::shared_ptr<PostgresQuery> q);

    void Select(std::shared_ptr<PostgresQuery> q, std::shared_ptr<PostgresReader> r);

    void InsertAndSelect(std::shared_ptr<PostgresQuery> q, std::shared_ptr<PostgresQuery> forSelect,
                         std::shared_ptr<PostgresReader> r);

    ~PostgresStorage() = default;

  private:
    pqxx::connection C;
};

#endif
