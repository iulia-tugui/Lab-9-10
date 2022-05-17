//
// Created by Iulia on 5/5/2022.
//

#ifndef LAB_9_10_REPOINFILE_H
#define LAB_9_10_REPOINFILE_H

#include "Repo.h"
#include <fstream>

template<class T> class RepoInFile: public IRepo<T> {
private:
    std::vector<T> entities;
    std::string fileName;
public:
    RepoInFile(std::string name){
        this->fileName = name;
        this->loadFromFile();
    }

    ~RepoInFile() = default;

    void add(T entity) override{
        this->entities.push_back(entity);
        this->saveToFile();
    }

    std::vector<T> getAll() override{
        return this->entities;
    };

    void update( int id, T entity) override{
        for(int i = 0; i < entities.size(); i++){
            if(entities[i].getId() == id){
                entities[i] = entity;
                entities[i].setId(id);
            }
        }
    }

    void remove(int id) override{
        for(int i=0; i < entities.size(); i++){
            if(entities[i].getId() == id){
                entities.erase(entities.begin() + i);
                this->saveToFile();
                i = entities.size();
            }
        }
    }

    void saveToFile(){
        std::ofstream file(this->fileName);
        for(T object : this->entities){
            file << object.delimitate(' ') << '\n';
        }
        file.close();
    }

    void loadFromFile(){
        std::string element;
        std::ifstream file(this->fileName);
        while(std::getline(file, element)){
            T object(element, ' ');
            this->entities.push_back(object);
        }
    }

    T getEntityById(int id){
        for(int i = 0; i < entities.size(); i++){
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

#endif //LAB_9_10_REPOINFILE_H
