//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_REPO_H
#define LAB_9_10_REPO_H

#include<vector>


template<class T> class IRepo{
public:
    virtual void add(T Entity) = 0;

    virtual std::vector<T> getAll() = 0;

    virtual void update(unsigned  int code, T Entity) = 0;

    virtual void remove(unsigned int code) = 0;

    virtual T getEntity(unsigned int code) = 0;
};

#endif //LAB_9_10_REPO_H
