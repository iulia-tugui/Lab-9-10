//
// Created by Iulia on 5/5/2022.
//

#include "CoinService.h"

void CoinService::add(int id, double value, int number) {
    Coin coin(id, value, number);
    this->coinValidator.setCoin(coin);
    this->coinValidator.validate();
    repo.add(coin);

}

std::vector<Coin> CoinService::read() {
    return repo.getAll();
}

void CoinService::update(int id, double value, int number) {
    Coin coin(id, value, number);
    this->coinValidator.setCoin(coin);
    this->coinValidator.validate();
    repo.update(id, coin);

}

void CoinService::remove(int id) {
    repo.remove(id);

}

std::vector<Coin> CoinService::getChange(double change) {
    std::vector<Coin> coins = repo.getAll();
    std::vector<Coin> changeCoins = std::vector<Coin>();
    std::vector<Coin> updates = std::vector<Coin>();
    for (int index = coins.size() - 1; index >= 0; --index) {
        if (coins[index].getValue() <= change) {
            int nrReturnedCoins = std::min((int) (change / coins[index].getValue()), coins[index].getNumber());
            changeCoins.emplace_back(coins[index].getId(), coins[index].getValue(), nrReturnedCoins);
            change -= coins[index].getValue() * nrReturnedCoins;
            updates.emplace_back(coins[index].getId(), coins[index].getValue(), coins[index].getNumber() - nrReturnedCoins);
        }
    }

    if(change > 0) {
        throw MyException("Could not give change!");
    }

    for(const Coin& coin : updates) {
        if(coin.getNumber() == 0) {
            repo.remove(coin.getId());
        } else {
            repo.update(coin.getId(), coin);
        }
    }

    return changeCoins;
}

void CoinService::add(Coin newCoin) {
    std::vector<Coin> coins = repo.getAll();

    int mxId = 1;
    for(const Coin& coin : coins) {
        mxId = std::max(mxId, coin.getId());
    }

    newCoin.setId(mxId + 1);
    repo.add(newCoin);
};