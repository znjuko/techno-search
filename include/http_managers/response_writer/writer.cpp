//
// Created by paccbet on 14.04.2021.
//

#include "writer.h"

IResponseWriter::~IResponseWriter() noexcept {};

JsonResponseWriter::~JsonResponseWriter() noexcept {};

void JsonResponseWriter::WriteResponse(std::shared_ptr<IUnMarshaller> u, Http::ResponseWriter *writer)
{
    auto output = u->UnMarshall();
    writer->send(Http::Code::Ok, output.dump());
};

void ErrorResponseWriter::WriteError(Http::Code code, const std::string &error, Http::ResponseWriter *writer) noexcept
{
    writer->send(code, error);
}
