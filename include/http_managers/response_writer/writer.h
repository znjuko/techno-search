//
// Created by paccbet on 14.04.2021.
//

#ifndef TECHNO_SEARCH_WRITER_H
#define TECHNO_SEARCH_WRITER_H

#include "unmarshaller.h"

#include <pistache/endpoint.h>

using namespace Pistache;

class IResponseWriter
{
  public:
    virtual void WriteResponse(std::shared_ptr<IUnMarshaller> u, Http::ResponseWriter *writer) = 0;

    virtual ~IResponseWriter() noexcept = 0;
};

class JsonResponseWriter : public IResponseWriter
{
  public:
    JsonResponseWriter() = default;

    void WriteResponse(std::shared_ptr<IUnMarshaller> u, Http::ResponseWriter *writer) override;

    ~JsonResponseWriter() noexcept override;
};

class ErrorResponseWriter
{
  public:
    ErrorResponseWriter() = default;

    void WriteError(Http::Code code, const std::string &error, Http::ResponseWriter *writer) noexcept;

    ~ErrorResponseWriter() noexcept = default;
};

#endif // TECHNO_SEARCH_WRITER_H
