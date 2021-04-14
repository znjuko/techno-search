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
    virtual void WriteResponse(IUnMarshaller u, Http::ResponseWriter writer) = 0;
    //    virtual ~IResponseWriter() = 0;
};

class JsonResponseWriter : public IResponseWriter
{
    JsonResponseWriter() = default;

    void WriteResponse(IUnMarshaller u, Http::ResponseWriter writer) override;

    ~JsonResponseWriter() = default;
};

#endif // TECHNO_SEARCH_WRITER_H
