//
// Created by Iulia on 5/5/2022.
//

#include "Service.h"

Service::Service(IRepo<Ticket> &Irepo): repository(Irepo){}


void Service::add(int id, int cod, std::string day, double price) {
    Ticket ticket(id, cod, day, price);
    repository.add(ticket);

}

std::vector<Ticket> Service::read() {
    return repository.getAll();
}

void Service::update(int id, int cod, std::string day, double price) {
    Ticket ticket(id, cod, day, price);
    repository.update(cod, ticket);

}

void Service::remove(unsigned int cod) {
    repository.remove(cod);

}

Ticket Service::getTicket( int cod) {
    return repository.getEntity(cod);
}