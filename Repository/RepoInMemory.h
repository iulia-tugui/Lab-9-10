//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_REPOINMEMORY_H
#define LAB_9_10_REPOINMEMORY_H
#include "../Domain/Ticket.h"
#include <vector>
#include "Repo.h"

template<class T> class RepoInMemory: public IRepo<T>{
private:
    std::vector<T> entities;
public:
    RepoInMemory() = default;

    ~RepoInMemory() = default;

    void add(T entity) override{
        entities.push_back(entity);
    }

    std::vector<T> getAll() override{
        return entities;
    }

    void update(unsigned  int code, T entity) override{
        for(int i=0; i < entities.size(); i++){
            if(entities[i].getCode() == code){
                entities[i] = entity;
                entities[i].setCode(code);
            }
        }
    }

    void remove(unsigned int code){
        for(int i = 0; i < entities.size(); i++){
            if(entities[i].getCode() == code){
                entities.erase(entities.begin() + i);
                i = entities.size();
            }
        }
    }
    T getEntity(unsigned int code){
        for(int i =0; i < entities.size(); i++){
            if(entities[i].getCode() == code){
                return entities[i];
            }
        }
    }
};

#endif //LAB_9_10_REPOINMEMORY_H
