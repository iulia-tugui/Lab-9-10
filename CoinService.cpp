//
// Created by Iulia on 5/5/2022.
//

#include "CoinService.h"

CoinService::CoinService(IRepo<Coin> &IRepo): repo(IRepo) {}

void CoinService::add(double value, unsigned int number) {
    Coin coin(this->coinCode,value, number);
    repo.add(coin);
    this->coinCode++;

}

std::vector<Coin> CoinService::read() {
    return repo.getAll();
}

void CoinService::update(unsigned int code, double value, unsigned int number) {
    Coin coin(code, value, number);
    repo.update(code, coin);

}

void CoinService::remove(unsigned int code) {
    repo.remove(code);

}

bool CoinService::verifyChange(double change) {
    std::vector<Coin> coins = repo.getAll();
    for(int i = coins.size() -1; i >= 0; i--){
        if(coins[i].getValue() <= change){
            unsigned int number = coins[i].getNumber();
            double value = coins[i].getValue();
            while(change >= coins[i].getValue() && number > 0){
                change -= value;
                number--;
            }
        }

    }
    return change == 0;
};