//
// Created by Iulia on 5/9/2022.
//

#ifndef LAB_9_10_TICKETVALIDATOR_H
#define LAB_9_10_TICKETVALIDATOR_H

#include "../Domain/Ticket.h"
#include "../Repository/Repo.h"
#include "../Domain/MyException.h"
class TicketValidator {
private:
    Ticket ticket;
    IRepo<Ticket> &repo;
public:
    explicit TicketValidator(IRepo<Ticket> &_repo) : repo{_repo} {};

    void validate();

    void setTicket(Ticket other) { this->ticket = other; };

    bool doesExit();

    void update();
};



#endif //LAB_9_10_TICKETVALIDATOR_H
