//
// Created by paccbet on 15.04.2021.
//

#include "common_storage.h"

ClickStorage::ClickStorage(const ClientOptions &opts) : client(opts)
{
}

void ClickStorage::Insert(const ClickQuery &q)
{
}

void ClickStorage::Select(const ClickQuery &q, std::shared_ptr<ClickReader> r)
{
    this->client.Select(q.GetQuery(), [&] (const Block& block) {
        r->Execute(block);
    });
}
