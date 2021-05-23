//
// Created by fillinmar on 15.04.2021.
//

#include "postgres_storage.h"

void PostgresStorage::Insert(const PostgresQuery &q)
{
    pqxx::work Transaction{C};

    Transaction.exec0(q.GetQuery());
}

void PostgresStorage::Select(std::shared_ptr<PostgresQuery> q, std::shared_ptr<PostgresReader> r)
{

    pqxx::work Transaction{C};

    pqxx::result R{Transaction.exec(q->GetQuery())};

    r->Execute(R);
}

void PostgresStorage::SelectAndInsert(const PostgresQuery &qIns, std::shared_ptr<PostgresQuery> qSel,
                                      std::shared_ptr<PostgresReader> r)
{
    pqxx::work Transaction{C};

    Transaction.exec0(qIns.GetQuery()); //добавила или обновила

    pqxx::result R{Transaction.exec(qSel->GetQuery())}; //получила данные

    r->Execute(R);
}