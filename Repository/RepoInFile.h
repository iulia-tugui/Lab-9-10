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

    void update(unsigned int code, T entity) override{
        for(int i = 0; i < entities.size(); i++){
            if(entities[i].getCode() == code){
                entities[i] = entity;
                entities[i].setCode(code);
            }
        }
    }

    void remove(unsigned int code) override{
        for(int i=0; i < entities.size(); i++){
            if(entities[i].getCode() == code){
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

    T getEntity(unsigned int code){
        for(int i = 0; i < entities.size(); i++){
            if(entities[i].getCode() == code){
                return entities[i];
            }
        }
    }
};

#endif //LAB_9_10_REPOINFILE_H
