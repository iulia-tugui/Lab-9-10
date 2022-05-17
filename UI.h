//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_UI_H
#define LAB_9_10_UI_H

#include "Service.h"
#include "CoinService.h"
class Console {
private:
    Service service;
    CoinService coinService;
    const std::vector<double> validValues = {500, 200, 100, 50, 10, 5, 1, 0.5, 0.1, 0.05, 0.01};
public:
    Console(Service &service, CoinService &coinService);
    ~Console() = default;
    void showAdminMenu();
    void showUserMenu();
    void showMainMenu();
    void runMenu();

    void userView();
    void adminView();
};

#endif //LAB_9_10_UI_H
