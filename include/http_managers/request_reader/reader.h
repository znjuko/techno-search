//
// Created by paccbet on 14.04.2021.
//

#ifndef TECHNO_SEARCH_READER_H
#define TECHNO_SEARCH_READER_H

#include "marshaller.h"

#include <pistache/endpoint.h>

using namespace Pistache;

class IRequestReader
{
  public:
    virtual void ReadRequest(IMarshaller m, Http::Request r) = 0;

    virtual ~IRequestReader() noexcept = 0;
};

class JsonRequestBodyReader : public IRequestReader
{
  public:
    JsonRequestBodyReader() = default;

    void ReadRequest(IMarshaller m, Http::Request r) override;

    ~JsonRequestBodyReader() noexcept override;
};

class RequestQueryReader : public IRequestReader
{
  public:
    RequestQueryReader() = default;

    void ReadRequest(IMarshaller m, Http::Request r) override;

    ~RequestQueryReader() noexcept override;
};

#endif // TECHNO_SEARCH_READER_H