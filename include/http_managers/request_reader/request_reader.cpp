//
// Created by paccbet on 14.04.2021.
//

#include "request_reader.h"

IRequestReader::~IRequestReader() noexcept {};

JsonRequestBodyReader::~JsonRequestBodyReader() noexcept {};

void JsonRequestBodyReader::ReadRequest(std::shared_ptr<IMarshaller> m, const Http::Request &r)
{
    m->Marshall(r.body());
};

RequestQueryReader::~RequestQueryReader() noexcept {};

void RequestQueryReader::ReadRequest(std::shared_ptr<IQueryMarshaller> m, const Http::Request &r)
{
    m->Marshall(r.query());
};

RequestReader::~RequestReader() noexcept
{
}

void RequestReader::ReadRequest(std::shared_ptr<IRequestMarshaller> m, const Rest::Request &r)
{
    m->Marshall(r);
}
