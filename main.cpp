#include <iostream>
#include "Domain/Ticket.h"
#include "Repository/RepoInFile.h"
#include "Service.h"
#include "CoinService.h"
#include "UI.h"
int main() {
    RepoInFile<Ticket> repoInFile("tickets.txt");
    TicketValidator ticketValidator(repoInFile);
    Service service(repoInFile, ticketValidator);

    RepoInFile<Coin> Coinrepo("coins.txt");
    CoinValidator coinValidator(Coinrepo);
    CoinService coinService(Coinrepo, coinValidator);

    Console console(service, coinService);

    console.runMenu();
}
