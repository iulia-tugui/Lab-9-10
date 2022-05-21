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
                addTicket();
                break;
            }
            case '2': {
                modifyTicket();
                break;
            }
            case '3': {
                deleteTicket();
                break;
            }
            case '4': {
                showAllTickets();
                break;
            }
            case '5': {
                addCoin();
                break;
            }
            case '6': {
                modifyCoin();
                break;
            }
            case '7': {
                deleteCoin();
                break;
            }
            case '8': {
                showAllCoins();
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
                showAllTickets();
                break;
            }
            case '2': {
                buyATicket();
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

void Console::addTicket() {
    try {
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

        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Invalid input!");
        }
        service.add(id, cod, day, price, numberOfTickets);

    } catch (const MyException &exception) {
        std::cerr << exception.what() << '\n';
    }
}

void Console::modifyTicket() {
    try {
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

        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Invalid input!");
        }
        service.update(id, cod, day, price, numberOfTickets);
    } catch (const MyException &exception) {
        std::cerr << exception.what() << '\n';
    }
}

void Console::deleteTicket() {
    try {
        int id;
        std::cout << "Give the id of the ticket to be deleted: ";
        if(std::cin >> id) {
            service.remove(id);
        }else{
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Id must have a positive value!");
        }
    } catch (const MyException &exception) {
        std::cerr << exception.what() << '\n';
    }
}

void Console::showAllTickets() {
    std::vector<Ticket> tickets = service.read();
    for (auto &ticket: tickets) {
        std::cout << ticket;
    }
}

void Console::addCoin() {
    try {
        int id, number, x;
        double value;
        x = 1;
        while (x != 0) {
            std::cout << "Give id: ";
            std::cin >> id;
            std::cout << "Give value [500/200/100/50/10/5/1/0.5/0.1/0.05/0.01]: ";
            std::cin >> value;
            std::cout << "Give number: ";
            std::cin >> number;
            coinService.add(id, value, number);
            std::cout << "If you want to add more type '1' else type '0': ";
            std::cin >> x;
        }
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Id must have a positive value!");
        }
    }
    catch (const MyException &exception) {
        std::cerr << exception.what() << '\n';
    }
}

void Console::modifyCoin() {
    try {
        int id, number;
        double value;
        std::cout << "Give the id of the coin to be modified: ";
        std::cin >> id;
        std::cout << "Give the new value: ";
        std::cin >> value;
        std::cout << "Give the new number: ";
        std::cin >> number;

        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Invalid input!");
        }
        coinService.update(id, value, number);
    } catch (const MyException &exception) {
        std::cerr << exception.what() << '\n';
    }
}

void Console::deleteCoin() {
    try {
        int id;
        std::cout << "Give the id of the coin to be deleted: ";
        std::cin >> id;
        if(!std::cin)
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            throw MyException("Invalid input!");
        }
        coinService.remove(id);
    } catch (const MyException &exception) {
        std::cerr << exception.what() << '\n';
    }
}

void Console::showAllCoins() {
    std::vector<Coin> coins = coinService.read();
    for (auto &coin: coins) {
        std::cout << coin;
    }
}

void Console::buyATicket() {
    int codeTicket;
    double money = 0;
    double price;

    std::cout << "Give code: ";
    std::cin >> codeTicket;
    std::cout << "Give the money introduced: ";

    vector<Coin> coinsToAdd = vector<Coin>();

    for (double value: validValues) {
        int nrCoins;
        std::cout << "Value " << value << ": ";
        std::cin >> nrCoins;

        if (nrCoins > 0) {
            coinsToAdd.emplace_back(Coin(value, nrCoins));
            money += value * nrCoins;
        }
    }

    price = service.getTicket(codeTicket).getPrice();

    try {
        for (const Coin &coin: coinsToAdd) {
            coinService.add(coin);
        }

        std::vector<Coin> change = coinService.getChange(money - price);

        std::cout << "Change: \n";

        for (const Coin &coin: change) {
            std::cout << coin << '\n';
            coinService.remove(coin.getId());
        }
    } catch (const MyException &exception) {
        std::cerr << exception.what() << '\n';
    }

}
