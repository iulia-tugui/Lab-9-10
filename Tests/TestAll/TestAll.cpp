//
// Created by Iulia on 5/19/2022.
//

#include "TestAll.h"
#include "../TestDomain/TestCoinDomain.h"
#include "../TestDomain/TestTicketDomain.h"
#include "../TestRepository/TestTicketRepoInFile.h"
void TestAll::allTests() {
    TestCoinDomain testCoinDomain;
    testCoinDomain.testCoinDomain();
    TestTicketDomain testTicketDomain;
    testTicketDomain.testTicketDomain();

}
