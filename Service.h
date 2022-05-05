//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_SERVICE_H
#define LAB_9_10_SERVICE_H

#include "Domain/Ticket.h"
#include "Repository/Repo.h"

class Service {
private:
    IRepo<Ticket> &repository;
public:
    Service(IRepo<Ticket> &Irepo);
    ~Service() = default;

    void add(int id, int cod, std::string day, double price);

    std::vector<Ticket> read();

    void update(int id, int cod, std::string day, double price);

    void remove(unsigned int cod);

    Ticket getTicket( int cod);
};

#endif //LAB_9_10_SERVICE_H
