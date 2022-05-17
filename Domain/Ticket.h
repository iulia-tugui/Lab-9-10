//
// Created by Iulia on 4/21/2022.
//

#ifndef LAB_9_10_TICKET_H
#define LAB_9_10_TICKET_H
#include <cstring>
#include <iostream>
using namespace std;

class Ticket {
private:
    int id;
    int cod;
    string day;
    double price;
    int numberOfTickets;
public:
    Ticket();

    Ticket(int newId, int newCod, string newDay, double newPrice, int numberOfTickets);

    Ticket(const Ticket &ticket);

    Ticket(string stringTicket, char separator);

    ~Ticket();

    void setCode(int newCode);

    void setDay(string newDay);

    void setPrice(double newPrice);

    void setId(int newId);

    void setNumberOfTickets(int newNumberOfTickets);

    int getCode() const;

    string getDay();

    int getId() const;

    double getPrice() const;

    int getNumberOfTickets() const;

    string delimitate(char delimitator);

    friend ostream &operator<<(ostream &os, const Ticket &ticket);


};


#endif //LAB_9_10_TICKET_H
