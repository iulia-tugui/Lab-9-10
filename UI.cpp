//
// Created by Iulia on 5/5/2022.
//

#include "UI.h"

Console::Console(Service &service, CoinService &coinService) : service(service), coinService(coinService) {}


void Console::showMainMenu() {
    std::cout << "1. Admin" << '\n';
    std::cout << "2. User" << '\n';
    std::cout << "x. Exit" << '\n';
    std::cout << " Give option: ";
}

void Console::showAdminMenu() {
    std::cout << "1. Add a ticket" << '\n';
    std::cout << "2. Modify a ticket" << '\n';
    std::cout << "3. Delete a ticket" << '\n';
    std::cout << "4. Show all tickets" << '\n';
    std::cout << "5. Add a coin" << '\n';
    std::cout << "6. Modify a coin" << '\n';
    std::cout << "7. Delete a coin" << '\n';
    std::cout << "8. Show all coins" << '\n';
    std::cout << "x. Exit" << '\n';
    std::cout << "Give option: ";

}

void Console::showUserMenu() {
    std::cout << "1. Show all tickets" << '\n';
    std::cout << "2. Buy a ticket" << '\n';
    std::cout << "x. Exit" << '\n';
    std::cout << "Give option: ";
}

void Console::adminView() {
    char option;
    bool shouldRun = true;

    while (shouldRun) {
        this->showAdminMenu();
        std::cin >> option;

        switch (option) {
            case '1': {
                int id;
                int cod;
                std::string day;
                double price;
                int numberOfTickets;

                std::cout << "Give id: ";
                std::cin >> id;
                std::cout << "Give code: ";
                std::cin >> cod;
                std::cout << "Give day: ";
                std::cin >> day;
                std::cout << "Give price: ";
                std::cin >> price;
                std::cout << "Give number of tickets: ";
                std::cin >> numberOfTickets;
                try {
                    service.add(id, cod, day, price, numberOfTickets);
                } catch (const MyException& exception) {
                    std::cerr << exception.what() << '\n';
                }
                break;
            }
            case '2': {
                int id;
                int cod;
                std::string day;
                double price;
                int numberOfTickets;

                std::cout << "Give the id of the ticket to be modified: ";
                std::cin >> id;
                std::cout << "Give the new cod: ";
                std::cin >> cod;
                std::cout << "Give the new day: ";
                std::cin >> day;
                std::cout << "Give the new price: ";
                std::cin >> price;
                std::cout << "Give number of tickets: ";
                std::cin >> numberOfTickets;

                try {
                    service.update(id, cod, day, price, numberOfTickets);
                } catch (const MyException& exception) {
                    std::cerr << exception.what() << '\n';
                }
                break;
            }
            case '3': {
                int id;
                std::cout << "Give the id of the ticket to be deleted: ";
                std::cin >> id;
                service.remove(id);
                break;
            }
            case '4': {
                std::vector<Ticket> tickets = service.read();
                for (auto & ticket : tickets) {
                    std::cout << ticket;
                }

                break;
            }
            case '5': {
                int id, number;
                double value;
                std::cout << "Give id: ";
                std::cin >> id;
                std::cout << "Give value: ";
                std::cin >> value;
                std::cout << "Give number: ";
                std::cin >> number;

                coinService.add(id, value, number);
                break;
            }
            case '6': {
                int id, number;
                double value;
                std::cout << "Give the id of the coin to be modified: ";
                std::cin >> id;
                std::cout << "Give the new value: ";
                std::cin >> value;
                std::cout << "Give the new number: ";
                std::cin >> number;
                coinService.update(id, value, number);
                break;
            }
            case '7': {
                int id;
                std::cout << "Give the id of the coin to be deleted: ";
                std::cin >> id;
                coinService.remove(id);
                break;
            }
            case '8': {
                std::vector<Coin> coins = coinService.read();
                for (auto & coin : coins) {
                    std::cout << coin;
                }
                break;
            }
            case 'x': {
                shouldRun = false;
                break;
            }
            default: {
                std::cout << "Invalid option! Try again!" << '\n';
                break;
            }
        }
    }
}

void Console::userView() {
    char userOption;
    bool userShouldRun = true;
    while (userShouldRun) {
        this->showUserMenu();
        std::cin >> userOption;
        switch (userOption) {
            case '1': {
                std::vector<Ticket> tickets = service.read();
                for (auto & ticket : tickets) {
                    std::cout << ticket;
                }
                break;
            }
            case '2': {
                int codeTicket;
                double money = 0;
                double price;

                std::cout << "Give code: ";
                std::cin >> codeTicket;
                std::cout << "Give the money introduced: ";

                vector <Coin> coinsToAdd = vector<Coin>();

                for(double value : validValues) {
                    int nrCoins;
                    std::cout << "Value " << value << ": ";
                    std::cin >> nrCoins;

                    if(nrCoins > 0) {
                        coinsToAdd.emplace_back(Coin(value, nrCoins));
                        money += value * nrCoins;
                    }
                }

                price = service.getTicket(codeTicket).getPrice();

                try {
                    for (const Coin& coin : coinsToAdd) {
                        coinService.add(coin);
                    }

                    std::vector<Coin> change = coinService.getChange(money - price);

                    std::cout << "Change: \n";

                    for (const Coin &coin: change) {
                        std::cout << coin << '\n';
                    }
                } catch (const MyException &exception) {
                    std::cerr << exception.what() << '\n';
                }


                break;
            }
            case 'x': {
                userShouldRun = false;
                break;
            }
            default: {
                std::cout << "Invalid option! Try again!" << '\n';
            }

        }
    }
}

void Console::runMenu() {
    char mainOption;
    bool mainShouldRun = true;

    while (mainShouldRun) {
        this->showMainMenu();
        std::cin >> mainOption;

        try {
            switch (mainOption) {
                case '1': {
                    adminView();
                    break;
                }
                case '2': {
                    userView();
                    break;
                }
                case 'x': {
                    mainShouldRun = false;
                    break;
                }
                default: {
                    std::cout << "Invalid option! Try again!" << '\n';
                }
            }
        }
        catch (MyException &e) {
            cout << e.what() << '\n';
        }
        catch (...) {
            cout << "Unknown error" << '\n';
        }
    }
}