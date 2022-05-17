//
// Created by Iulia on 5/9/2022.
//

#ifndef LAB_9_10_COINVALIDATOR_H
#define LAB_9_10_COINVALIDATOR_H

#include "../Domain/Coin.h"
#include "../Repository/Repo.h"
#include "../Domain/MyException.h"
    class CoinValidator {
    private:
        Coin coin;
        IRepo<Coin> &repo;
    public:
        explicit CoinValidator(IRepo<Coin> &_repo) : repo{_repo} {};

        void validate();

        void setCoin(Coin other) { this->coin = other; };

        bool doesExit();

        void update();
    };


#endif //LAB_9_10_COINVALIDATOR_H
