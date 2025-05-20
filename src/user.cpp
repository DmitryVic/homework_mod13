#include "user.h"

    unsigned int regIdUser(){
        static unsigned int idUser = 0;
        return ++idUser;
    }

    User::User(std::string name): _name(name), _id(regIdUser()) {}

    User::~User() = default;

    std::string User::getName() const{
        return this->_name;
    }

    unsigned int  User::getID() const{
        return this->_id;
    }