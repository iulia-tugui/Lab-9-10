//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_SERVICE_H
#define LAB_9_10_SERVICE_H

#include "Domain/Ticket.h"
#include "Repository/Repo.h"
#include "Validator/TicketValidator.h"

class Service {
private:
    IRepo<Ticket> &repository;
    TicketValidator ticketValidator;
public:
    Service(IRepo<Ticket> &Irepo, TicketValidator ticketValidator): repository{Irepo},
    ticketValidator{std::move(ticketValidator)}{};

    ~Service() = default;

    void add(int id, int cod, std::string day, double price, int numberOfTickets=1);

    std::vector<Ticket> read();

    void update(int id, int cod, std::string day, double price, int numberOfTickets);

    void remove(int id);

    Ticket getTicket( int cod);
};

#endif //LAB_9_10_SERVICE_H
