//
// Created by fillinmar on 15.04.2021.
//

#ifndef TECHNO_SEARCH_QUERY_H
#define TECHNO_SEARCH_QUERY_H

#include <string>

class PostgresQuery
{
  public:
    virtual std::string GetQuery() const = 0;

    virtual ~PostgresQuery();
};

#endif // TECHNO_SEARCH_QUERY_H
