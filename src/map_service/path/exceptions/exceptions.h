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
    explicit StoreGraphNotFound(const int &ID) : ID(ID){};

    [[nodiscard]] const char *what() const throw()
    {
        auto msg = "store with ID:" + std::to_string(ID) + " not found";
        return msg.c_str();
    }

  private:
    int ID;
};

#endif // RENAMEIT_EXCEPTIONS_H
