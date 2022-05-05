//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_COINSERVICE_H
#define LAB_9_10_COINSERVICE_H

#include "Domain/Coin.h"
#include "Repository/Repo.h"

class CoinService {
private:
    IRepo<Coin> &repo;
    unsigned int coinCode = 0;
public:
    CoinService(IRepo<Coin> &IRepo);
    ~CoinService() = default;

    void add(double value, unsigned int number);

    std:: vector<Coin> read();

    void update(unsigned int code, double value, unsigned int number);

    void remove(unsigned int code);

    bool verifyChange(double change);


};

#endif //LAB_9_10_COINSERVICE_H
