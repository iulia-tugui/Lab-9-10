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
public:
    Console(Service &service, CoinService &coinService);
    ~Console() = default;
    void showAdminMenu();
    void showUserMenu();
    void showMainMenu();
    void runMenu();

};

#endif //LAB_9_10_UI_H
