#include <iostream>
#include "Domain/Ticket.h"
#include "Repository/RepoInFile.h"
#include "Service.h"
#include "CoinService.h"
#include "UI.h"
int main() {
    RepoInFile<Ticket> repoInFile("products.txt");
    Service service(repoInFile);

    RepoInFile<Coin> Coinrepo("coins0.txt");
    CoinService coinService(Coinrepo);

    Console console(service, coinService);

    console.runMenu();
}
