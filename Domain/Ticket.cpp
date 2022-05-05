//
// Created by Iulia on 4/21/2022.
//

#include "Ticket.h"
#include <vector>
#include <sstream>

using namespace std;
Ticket::Ticket() {
    this->id = 0;
    this->cod = 0;
    this->day = nullptr;
    this->price = 0;
}

Ticket::Ticket(int newId, int newCod, string newDay, double newPrice) {
    this->id = newId;
    this->cod = newCod;
    this->day = newDay;
    this->price = newPrice;
}

Ticket::Ticket(const Ticket &ticket) {
    this->id = ticket.id;
    this->cod=ticket.cod;
    this->day=ticket.day;
    this->price=ticket.price;
}

void Ticket::setCode(int newCode) {
    this->cod = newCode;
}

void Ticket::setDay(string newDay) {
    this->day = std::move(newDay);
}

void Ticket::setPrice(double newPrice) {
    this->price = newPrice;
}

int Ticket::getCode() const {
    return cod;
}

string Ticket::getDay() {
    return day;
}

int Ticket::getId() const {
    return id;
}

double Ticket::getPrice() const {
    return price;
}

string Ticket::delimitate(char delimitator) {
    return std::to_string(this->id) + delimitator + std::to_string(this->cod) + this->day + delimitator +std::to_string(this->price);
}

ostream &operator<<(ostream &os, const Ticket &ticket){
    os<<"Ticket {"<<endl<<"Id: "<<ticket.id<<endl<<"Cod: "<<ticket.cod<<endl<<"Day: "<<ticket.day<<endl<<"Price: "<<ticket.price<<'}'<<endl;
    return os;
}

Ticket::Ticket(string stringTicket, char separator) {
    std::vector<std::string> entities;
    std::stringstream ss (stringTicket);
    std::string object;
    while (getline (ss, object, separator)) {
        entities.push_back(object);
    }
    if(entities.size() == 3) {
        std::stringstream c(entities[0]);
        c >> this->id;
        std::stringstream a(entities[1]);
        a >> this->cod;
        this->day = entities[2];
        std::stringstream p(entities[3]);
        p >> this->price;
    }
}


Ticket::~Ticket() = default;
