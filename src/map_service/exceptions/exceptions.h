//
// Created by Никита Черных on 19.05.2021.
//

#ifndef RENAMEIT_EXCEPTIONS_H
#define RENAMEIT_EXCEPTIONS_H

#include <exception>
#include <string>

class StoreGraphNotFound : public std::exception
{
  public:
    explicit StoreGraphNotFound(const int &ID)
    {
        msg = "store with ID:" + std::to_string(ID) + " not found";
    };

    [[nodiscard]] const char *what() const noexcept override
    {
        return msg.c_str();
    }

  private:
    std::string msg;
};

#endif // RENAMEIT_EXCEPTIONS_H
