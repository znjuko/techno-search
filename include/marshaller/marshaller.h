//
// Created by paccbet on 14.04.2021.
//

#ifndef MARSHALLER_H
#define MARSHALLER_H

#include <pistache/endpoint.h>
#include <pistache/router.h>
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

class IRequestMarshaller
{
  public:
    virtual void Marshall(const Rest::Request &req) = 0;

    virtual ~IRequestMarshaller() = default;
};

#endif // MARSHALLER_H
