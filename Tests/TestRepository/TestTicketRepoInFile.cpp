//
// Created by Iulia on 5/19/2022.
//

#include "TestTicketRepoInFile.h"
#include <cassert>
#include "../../Domain/Ticket.h"
#include "../../Repository/RepoInFile.h"

void TestTicketRepoInFile::testTicketRepoInFile() {
    RepoInFile<Ticket> repo("tests.txt");

    Ticket t1(1,123,"Monday", 12, 1);
    Ticket t2(2,124,"Monday", 10, 2);

    repo.add(t1);
    repo.add(t2);

    //assert(repo.getAll()[0].getId()==1);
    //assert(repo.getAll()[0].getDay()=="Monday");
    //assert(repo.getAll()[1].getId()==2);
    assert(repo.getAll()[1].getCode()==124);
    assert(repo.getAll()[1].getNumberOfTickets()==2);

    repo.remove(1);
    assert(repo.getAll().size()==1);

    Ticket t3 = Ticket(3,111,"Friday",12,1);
    repo.update(2, t3);

    assert(t2.getId()==2);
    assert(t2.getCode()==111);
    assert(t2.getDay()=="Friday");
    assert(t2.getPrice()==12);

    repo.remove(3);

}
