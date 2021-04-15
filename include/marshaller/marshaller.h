//
// Created by paccbet on 14.04.2021.
//

#ifndef MARSHALLER_H
#define MARSHALLER_H

#include <pistache/endpoint.h>
#include <string>

using namespace Pistache;

class IMarshaller
{
  public:
    virtual void Marshall(const std::string &body) = 0;

    virtual ~IMarshaller() = default;
};

class IQueryMarshaller
{
  public:
    virtual void Marshall(const Http::Uri::Query &body) = 0;

    virtual ~IQueryMarshaller() = default;
};

#endif // MARSHALLER_H
