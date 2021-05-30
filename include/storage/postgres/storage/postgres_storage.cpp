//
// Created by fillinmar on 15.04.2021.
//

#include <iostream>
#include "postgres_storage.h"

PostgresStorage::PostgresStorage(const char* options) : C(options)
{
}

void PostgresStorage::Insert(std::shared_ptr<PostgresQuery> q)
{
    pqxx::work Transaction{C};

    Transaction.exec0(q->GetQuery());

    Transaction.commit();
}

void PostgresStorage::Select(std::shared_ptr<PostgresQuery> q, std::shared_ptr<PostgresReader> r)
{
    pqxx::work Transaction{C};

    pqxx::result R{Transaction.exec(q->GetQuery())};

    r->Execute(R);
}

void PostgresStorage::InsertAndSelect(std::shared_ptr<PostgresQuery> q,std::shared_ptr<PostgresQuery> forSelect, std::shared_ptr<PostgresReader> r)
{
    pqxx::work Transaction{C};

    Transaction.exec0(q->GetQuery());

    Transaction.commit();

    pqxx::result R{Transaction.exec(forSelect->GetQuery())};

    r->Execute(R);
}

