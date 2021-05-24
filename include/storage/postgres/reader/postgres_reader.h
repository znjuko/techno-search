//
// Created by fillinmar on 17.04.2021.
//

#ifndef TECHNO_SEARCH_POSTGRES_READER_H
#define TECHNO_SEARCH_POSTGRES_READER_H

#include <pqxx/pqxx>

class PostgresReader
{
  public:
    virtual void Execute(const pqxx::result R) = 0;
//    virtual void Execute(const pqxx::result R, std::shared_ptr<UpdateStoreRequest> req)

    virtual ~PostgresReader() = default;
};

#endif
