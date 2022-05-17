//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_REPOINMEMORY_H
#define LAB_9_10_REPOINMEMORY_H
#include "../Domain/Ticket.h"
#include <vector>
#include "Repo.h"
#include "../Domain/MyException.h"

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

    void update(int id, T entity) override{
        for(int i=0; i < entities.size(); i++){
            if(entities[i].getId() == id){
                entities[i] = entity;
                entities[i].setId(id);
            }
        }
    }

    void remove(int id){
        for(int i = 0; i < entities.size(); i++){
            if(entities[i].getId() == id){
                entities.erase(entities.begin() + i);
                i = entities.size();
            }
        }
    }

    T getEntity(int id){
        for(int i =0; i < entities.size(); i++){
            if(entities[i].getId() == id){
                return entities[i];
            }
        }

        throw MyException("Entity does not exist!");
    }
    T getEntityByCode(int cod){
        for(int i=0; i< entities.size(); i++){
            if(entities[i].getCode() == cod){
                return entities[i];
            }
        }
        throw MyException("Entity does not exist!");
    }
};

#endif //LAB_9_10_REPOINMEMORY_H
