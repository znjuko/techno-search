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

ClickReader *ClickStorage::Select(const ClickQuery &q)
{
    this->client.Select();
    return new ProductPopularityMetricReader;
}
