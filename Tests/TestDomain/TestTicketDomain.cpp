//
// Created by Iulia on 5/19/2022.
//

#include "TestTicketDomain.h"
#include "../../Domain/Ticket.h"
#include <cassert>
void TestTicketDomain::testTicketDomain() {
    Ticket t;
    assert(t.getId()==0);
    assert(t.getCode()==0);
    assert(t.getPrice()==0);

    t.setId(1);
    t.setPrice(12);
    t.setDay("Monday");
    t.setCode(123);
    assert(t.getId()==1);
    assert(t.getPrice()==12);
    assert(t.getCode()==123);
    assert(t.getDay()=="Monday");

    Ticket t1(2,233,"Friday", 10, 1);
    assert(t1.getId()==2);
    assert(t1.getCode()==233);
    assert(t1.getPrice()==10);
    assert(t1.getDay()=="Friday");
    assert(t1.getNumberOfTickets()==1);

    Ticket t2;
    t2 = t1;
    assert(t2.getId()==2);
    assert(t2.getCode()==233);
    assert(t2.getPrice()==10);
    assert(t2.getDay()=="Friday");
    assert(t2.getNumberOfTickets()==1);
}
