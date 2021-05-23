//
// Created by fillinmar on 15.04.2021.
//

#include "postgres_storage.h"

PostgresStorage::PostgresStorage(const char* options) : C(options)
{
}

void PostgresStorage::Insert(const PostgresQuery &q)
{
    pqxx::work Transaction{C};

    Transaction.exec0(q.GetQuery());
}

void PostgresStorage::Select(std::make_shared<PostgresQuery> q, std::make_shared<PostgresReader> r)
{

    pqxx::work Transaction{C};

    pqxx::result R{Transaction.exec(q->GetQuery())};

    r->Execute(R);
}

void PostgresStorage::SelectAndInsert(const PostgresQuery &qIns, std::make_shared<PostgresQuery> qSel,
                                      std::make_shared<PostgresReader> r)
{
    pqxx::work Transaction{C};

    Transaction.exec0(qIns.GetQuery()); //добавила или обновила

    pqxx::result R{Transaction.exec(qSel->GetQuery())}; //получила данные

    r->Execute(R);
}

