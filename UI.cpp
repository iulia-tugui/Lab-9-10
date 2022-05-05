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
    std::cout << "2. Verify change" << '\n';
    std::cout << "x. Exit" << '\n';
    std::cout << "Give option: ";
}

void Console::runMenu() {
    char mainOption;
    bool mainShoulRun = true;
    while (mainShoulRun) {
        this->showMainMenu();
        std::cin >> mainOption;
        switch (mainOption) {
            case '1': {
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
                            std::cout << "Give id: ";
                            std::cin>>id;
                            std::cout << "Give code: ";
                            std::cin >> cod;
                            std::cout << "Give day: ";
                            std::cin >> day;
                            std::cout << "Give price: ";
                            std::cin >> price;
                            service.add(id, cod, day, price);
                            break;
                        }
                        case '2': {
                            int id;
                            int cod;
                            std::string day;
                            double price;
                            std::cout << "Give the id of the ticket to be modified: ";
                            std::cin>>id;
                            std::cout << "Give the new cod: ";
                            std::cin >> cod;
                            std::cout << "Give the new day: ";
                            std::cin >> day;
                            std::cout << "Give the new price: ";
                            std::cin >> price;
                            service.update(id, cod, day, price);
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
                            for (int i = 0; i < tickets.size(); i++) {
                                std::cout << tickets[i];
                            }
                            break;
                        }
                        case '5': {
                            unsigned int number;
                            double value;
                            std::cout << "Give value: ";
                            std::cin >> value;
                            std::cout << "Give number: ";
                            std::cin >> number;
                            coinService.add(value, number);
                            break;
                        }
                        case '6': {
                            unsigned int code, number;
                            double value;
                            std::cout << "Give the code of the coin to be modified: ";
                            std::cin >> code;
                            std::cout << "Give the new value: ";
                            std::cin >> value;
                            std::cout << "Give the new number: ";
                            std::cin >> number;
                            coinService.update(code,value, number);
                            break;
                        }
                        case '7': {
                            unsigned int code;
                            std::cout << "Give the code of the coin to be deleted: ";
                            std::cin >> code;
                            coinService.remove(code);
                            break;
                        }
                        case '8': {
                            std::vector<Coin> coins = coinService.read();
                            for (int i = 0; i < coins.size(); i++) {
                                std::cout << coins[i];
                            }
                            break;
                        }
                        case 'x': {
                            shouldRun = false;
                            break;
                        }
                        default: {
                            std::cout << "Invalid option! Try again!"<< '\n';
                            break;
                        }
                    }
                }
                break;
            }
            case'2':{
                char userOption;
                bool userShouldRun = true;
                while(userShouldRun) {
                    this->showUserMenu();
                    std::cin >> userOption;
                    switch (userOption) {
                        case '1': {
                            std::vector<Ticket> tickets = service.read();
                            for (int i = 0; i < tickets.size(); i++) {
                                std::cout << tickets[i];
                            }
                            break;
                        }
                        case '2': {
                            int codeTicket;
                            double money;
                            double price;
                            std::cout << "Give code: ";
                            std::cin >> codeTicket;
                            std::cout << "Give the value of money introduced: ";
                            std::cin >> money;
                            price = service.getTicket(codeTicket).getPrice();
                            bool ok = coinService.verifyChange(money - price);
                            if (ok) {
                                std::cout << "The change can be given!" << '\n';
                            } else {
                                std::cout << "The change cannot be given!" << '\n';
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
                break;
            }
            case'x':{
                mainShoulRun = false;
                break;
            }
            default:
            {
                std::cout << "Invalid option! Try again!" << '\n';
            }
                break;
        }
    }
}