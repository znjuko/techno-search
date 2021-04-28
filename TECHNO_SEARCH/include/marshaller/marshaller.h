#ifndef MARSHALLER_H
#define MARSHALLER_H
#include <string>

class IMarshaller
{
  public:
    virtual void Marshall(const std::string &body) = 0;

    virtual ~IMarshaller() = default;
};

#endif // MARSHALLER_H
