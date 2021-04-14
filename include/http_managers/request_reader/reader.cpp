//
// Created by paccbet on 14.04.2021.
//

#include "reader.h"

IRequestReader::~IRequestReader() noexcept {};

JsonRequestBodyReader::~JsonRequestBodyReader() noexcept {};

void JsonRequestBodyReader::ReadRequest(IMarshaller m, Http::Request r){};

RequestQueryReader::~RequestQueryReader() noexcept {};

void RequestQueryReader::ReadRequest(IMarshaller m, Http::Request r){};
