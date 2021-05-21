//
// Created by paccbet on 14.04.2021.
//

#include "reader.h"

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
