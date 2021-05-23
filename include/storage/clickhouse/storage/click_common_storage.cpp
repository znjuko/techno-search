//
// Created by paccbet on 15.04.2021.
//

#include "click_common_storage.h"

ClickStorage::ClickStorage(const ClientOptions &opts) : client(opts)
{
}

void ClickStorage::Insert(const ClickQuery &q)
{
    this->client.Execute(q.GetQuery());
}

void ClickStorage::Select(std::shared_ptr<ClickQuery> q, std::shared_ptr<ClickReader> r)
{
    this->client.Select(q->GetQuery(), [&](const Block &block) { r->Execute(block); });
}
