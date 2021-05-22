//
// Created by fillinmar on 15.04.2021.
//

#ifndef TECHNO_SEARCH_POSTGRES_STORAGE_H
#define TECHNO_SEARCH_POSTGRES_STORAGE_H

#include "../query/query.h"
#include "../reader/reader.h"
//#include "query.h"
//#include "reader.h"

#include <pqxx/pqxx>

class PostgresStorage
{
  public:
    PostgresStorage() = delete;

    void Insert(const PostgresQuery &q);

    void Select(std::shared_ptr<PostgresQuery> q, std::shared_ptr<PostgresReader> r);

    void SelectAndInsert(const PostgresQuery &qIns, std::shared_ptr<PostgresQuery> qSel,
                         std::shared_ptr<PostgresReader> r);

    ~PostgresStorage() = default;

  private:
    pqxx::connection C;
};

#endif