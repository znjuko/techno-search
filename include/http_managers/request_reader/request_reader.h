//
// Created by paccbet on 14.04.2021.
//

#ifndef TECHNO_SEARCH_COMMON_HTTP_READER_H
#define TECHNO_SEARCH_COMMON_HTTP_READER_H

#include "marshaller.h"

#include <pistache/endpoint.h>

using namespace Pistache;

class IRequestReader
{
  public:
    virtual void ReadRequest(std::shared_ptr<IMarshaller> m, const Http::Request &r) = 0;

    virtual ~IRequestReader() noexcept = 0;
};

class JsonRequestBodyReader : public IRequestReader
{
  public:
    JsonRequestBodyReader() = default;

    void ReadRequest(std::shared_ptr<IMarshaller> m, const Http::Request &r) override;

    ~JsonRequestBodyReader() noexcept override;
};

class RequestQueryReader
{
  public:
    RequestQueryReader() = default;

    void ReadRequest(std::shared_ptr<IQueryMarshaller> m, const Http::Request &r);

    ~RequestQueryReader() noexcept;
};

class RequestReader
{
  public:
    RequestReader() = default;

    void ReadRequest(std::shared_ptr<IRequestMarshaller> m, const Rest::Request &r);

    ~RequestReader() noexcept;
};

#endif // TECHNO_SEARCH_READER_H
