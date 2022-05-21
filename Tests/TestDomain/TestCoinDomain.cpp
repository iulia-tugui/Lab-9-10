//
// Created by Iulia on 5/19/2022.
//

#include "TestCoinDomain.h"
#include <cassert>
#include "../../Domain/Coin.h"

void TestCoinDomain::testCoinDomain() {
    Coin coin;
    assert(coin.getId()==0);
    assert(coin.getValue()==0);

    coin.setId(1);
    coin.setNumber(2);
    coin.setValue(1);
    assert(coin.getId()==1);
    assert(coin.getValue()==1);
    assert(coin.getNumber()==2);

    Coin coin1(2,5,1);
    assert(coin1.getId()==2);
    assert(coin1.getValue()==5);
    assert(coin1.getNumber()==1);

    Coin coin2;
    coin2 = coin1;
    assert(coin1.getId()==2);
    assert(coin1.getValue()==5);
    assert(coin1.getNumber()==1);
}
