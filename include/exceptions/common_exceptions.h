//
// Created by Никита Черных on 21.05.2021.
//

#ifndef TECHNO_ALGO_COMMON_EXCEPTIONS_H
#define TECHNO_ALGO_COMMON_EXCEPTIONS_H

#include <exception>
#include <string>

class EmptyValue : public std::exception
{
  public:
    explicit EmptyValue(const std::string &field)
    {
        msg = "got empty field: " + field;
    };

    [[nodiscard]] const char *what() const noexcept override
    {
        return msg.c_str();
    }

  private:
    std::string msg;
};

class WrongValue : public std::exception
{
  public:
    explicit WrongValue(const std::string &field)
    {
        msg = "field: " + field + " has wrong value";
    };

    [[nodiscard]] const char *what() const noexcept override
    {
        return msg.c_str();
    }

  private:
    std::string msg;
};

class WrongFieldValue : public std::exception
{
  public:
    explicit WrongFieldValue(const std::string &field, const std::string &value)
    {
        msg = "got field: " + field + " with wrong value: " + value;
    };

    [[nodiscard]] const char *what() const noexcept override
    {
        return msg.c_str();
    }

  private:
    std::string msg;
};

#endif // TECHNO_ALGO_COMMON_EXCEPTIONS_H
