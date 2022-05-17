//
// Created by Iulia on 5/5/2022.
//

#include "Service.h"



void Service::add(int id, int cod, std::string day, double price, int numberOfTickets) {
    if(!repository.checkId(id)) {
        throw MyException("Id already exists!");
    }

    Ticket ticket=Ticket(id, cod, day, price, numberOfTickets);
    repository.add(ticket);
}

std::vector<Ticket> Service::read() {
    return repository.getAll();
}

void Service::update(int id, int cod, std::string day, double price, int numberOfTickets) {
    Ticket ticket(id, cod, day, price, numberOfTickets);

    if (!repository.checkId(id)) {
        throw MyException("Invalid id!");
    }

    repository.update(id, ticket);
}

void Service::remove(int id) {
    repository.remove(id);

}

Ticket Service::getTicket( int code) {
    return repository.getEntityByCode(code);
}