#ifndef UNMARSHALLER_H
#define UNMARSHALLER_H

#include <nlohmann/json.hpp>

class IUnMarshaller
{
  public:
    virtual nlohmann::json UnMarshall() = 0;

    virtual ~IUnMarshaller() = default;
};

#endif // UNMARSHALLER_H