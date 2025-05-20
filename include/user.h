#pragma once
#include <string>

class User{
    private:
    std::string _name;

    unsigned int _id;

    public:
    User(std::string name);
    ~User();
    std::string getName() const;
    unsigned int getID() const;
};