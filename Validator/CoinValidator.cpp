//
// Created by Iulia on 5/9/2022.
//

#include "CoinValidator.h"

void CoinValidator::validate() {
    if (this->doesExit()) {
        throw MyException("Exista o moneda cu acelasi id");
    }
    this->update();
}

bool CoinValidator::doesExit() {
    for (auto it: this->repo.getAll()) {
        if (it.getId() == this->coin.getId()) {
            return true;
        }
    }
    return false;
}

void CoinValidator::update() {

    if (this->coin.getId() <= 0) {
        throw MyException("Moneda trebuie sa aiba id-ul numar pozitiv.");
    } else if (this->coin.getNumber() <= 0) {
        throw MyException("Moneda trebuie sa aiba numarul strict pozitiv");
    } else if (this->coin.getValue() <= 0) {
        throw MyException("Moneda trebuie sa aiba valoarea strict pozitiva");
    }
}
