//
// Created by fillinmar on 15.04.2021.
//

#ifndef TECHNO_SEARCH_POSTGRES_STORAGE_H
#define TECHNO_SEARCH_POSTGRES_STORAGE_H

#include "../query/postgres_query.h"
#include "../reader/postgres_reader.h"
#include <memory>
//#include "query.h"
//#include "reader.h"

#include <pqxx/pqxx>

class PostgresStorage
{
  public:
    PostgresStorage() = delete;

    explicit PostgresStorage(const char* options);

    void Insert(const PostgresQuery &q);

    void Select(std::make_shared<PostgresQuery> q, std::make_shared<PostgresReader> r);

    void SelectAndInsert(const PostgresQuery &qIns, std::make_shared<PostgresQuery> qSel,
                         std::make_shared<PostgresReader> r);

    ~PostgresStorage() = default;

  private:
    pqxx::connection C;
};

#endif
