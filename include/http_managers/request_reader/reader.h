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
    virtual void ReadRequest(IMarshaller m, Http::Request r) = 0;
};

class JsonRequestBodyReader : public IRequestReader
{
    JsonRequestBodyReader() = default;

    void ReadRequest(IMarshaller m, Http::Request r) override;

    ~JsonRequestBodyReader() = default;
};

class JsonRequestQueryReader : public IRequestReader
{
    JsonRequestQueryReader() = default;

    void ReadRequest(IMarshaller m, Http::Request r) override;

    ~JsonRequestQueryReader() = default;
};

#endif // TECHNO_SEARCH_READER_H
