//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_REPO_H
#define LAB_9_10_REPO_H

#include<vector>
#include "../Domain/MyException.h"


template<class T> class IRepo{
public:
    virtual void add(T Entity) = 0;

    virtual std::vector<T> getAll() = 0;

    virtual void update(int id, T Entity) = 0;

    virtual void remove(int id) = 0;

    virtual T getEntityById(int id) = 0;

    virtual T getEntityByCode(int cod) = 0;

    bool checkId(int id) {
        try {
            getEntityById(id);
            return true;
        } catch (const MyException& exception) {
            return false;
        }
    }
};

#endif //LAB_9_10_REPO_H
