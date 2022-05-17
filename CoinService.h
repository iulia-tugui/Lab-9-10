//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_COINSERVICE_H
#define LAB_9_10_COINSERVICE_H

#include "Domain/Coin.h"
#include "Repository/Repo.h"
#include "Validator/CoinValidator.h"

class CoinService {
private:
    IRepo<Coin> &repo;
    CoinValidator coinValidator;
public:
    CoinService(IRepo<Coin> &IRepo, CoinValidator coinValidator1): repo{
                  IRepo},                                                   coinValidator{
                                                                         std::move(
                                                                                 coinValidator1)} {};

    ~CoinService() = default;

    void add(int id, double value, int number);

    void add(Coin coin);

    std:: vector<Coin> read();

    void update(int id, double value, int number);

    void remove(int id);

    std::vector<Coin> getChange(double change);


};

#endif //LAB_9_10_COINSERVICE_H
