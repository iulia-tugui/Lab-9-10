//
// Created by Iulia on 5/9/2022.
//

#ifndef LAB_9_10_MYEXCEPTION_H
#define LAB_9_10_MYEXCEPTION_H
#include <exception>

class MyException : std::exception {
private:
    const char *mesaj;
public:
    MyException(const char *mesaj): mesaj(mesaj){}

    const char *what() const noexcept override{
        return mesaj;
    }
};



#endif //LAB_9_10_MYEXCEPTION_H
