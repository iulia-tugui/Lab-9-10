//
// Created by Iulia on 5/9/2022.
//

#include "TicketValidator.h"

void TicketValidator::validate() {
    if (this->doesExit()) {
        throw MyException("Exista un produs cu acelasi cod");
    }
    this->update();
}

bool TicketValidator::doesExit() {
    for (auto p: this->repo.getAll()) {
        if (p.getCode() == this->ticket.getCode()) {
            return true;
        }
    }
    return false;
}

void TicketValidator::update() {
    if (this->ticket.getCode() <= 0) {
        throw MyException("Biletul trebuie sa aiba codul numar pozitiv.");
    }else if (this->ticket.getPrice() <= 0) {
        throw MyException("Biletul trebuie sa aiba pretul pozitiv.");
    } else if (this->ticket.getDay().empty()) {
        throw MyException("Biletul trebuie sa aiba o zi");
    }
}