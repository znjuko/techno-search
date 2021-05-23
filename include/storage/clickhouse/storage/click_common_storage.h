//
// Created by paccbet on 15.04.2021.
//

#ifndef TECHNO_SEARCH_COMMON_CLICK_STORAGE_H
#define TECHNO_SEARCH_COMMON_CLICK_STORAGE_H

#include "query.h"
#include "reader.h"

#include <clickhouse/client.h>

using namespace clickhouse;

class ClickStorage
{
  public:
    ClickStorage() = delete;

    explicit ClickStorage(const ClientOptions &opts);

    // TODO (n.chernyh) : add move constr r8 here
    void Insert(const ClickQuery &q);

    void Select(std::shared_ptr<ClickQuery> q, std::shared_ptr<ClickReader> r);

    ~ClickStorage() = default;

  private:
    clickhouse::Client client;
};

#endif // TECHNO_SEARCH_COMMON_STORAGE_H
