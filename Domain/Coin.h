//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_COIN_H
#define LAB_9_10_COIN_H

#include <string>
#include <ostream>
#include <sstream>



class Coin {

private:
    int id;
    double value;
    int number;
public:
    Coin();
    Coin(double value, int number) : Coin(0, value, number) {};
    Coin(int id, double value, int number);
    Coin(const Coin &coin);
    Coin(std::string stringCoin, char separator);
    ~Coin() = default;

    int getId() const;

    int getCode() {};

    void setId(int id);

    double getValue() const;

    int getNumber() const;

    void setValue(double value);

    void setNumber(int number);

    bool operator==(const Coin &rhs) const;

    bool operator!=(const Coin &rhs) const;

    bool operator<(const Coin &rhs) const;

    bool operator>(const Coin &rhs) const;

    bool operator<=(const Coin &rhs) const;

    bool operator>=(const Coin &rhs) const;

    std::string delimitate(char delimitator);

    friend std::ostream &operator<<(std::ostream &os, const Coin &coin);
};


#endif //LAB_9_10_COIN_H
