//
// Created by paccbet on 14.04.2021.
//

#include "writer.h"

IResponseWriter::~IResponseWriter() noexcept {};

JsonResponseWriter::~JsonResponseWriter() noexcept {};

void JsonResponseWriter::WriteResponse(IUnMarshaller u, Http::ResponseWriter writer){

};
