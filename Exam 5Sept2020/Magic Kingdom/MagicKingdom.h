#pragma once
#ifndef MAGIC_H
#define MAGIC_H

#include <iostream>
#include <sstream>
#include "Struct.h"
#include <map>
#include <vector>

class MagicKingdom {
    
    
public:
    std::map<int, std::vector<std::string> > AntiMags;
    std::map<int, std::vector<std::string>, std::greater<int> > Magicians, Commoner;
    MagicKingdom operator<<(const Villager& v) {
        std::string name = v.name;
        int power = v.power;
        std::string magicItem = v.magicItem;

        std::string str = name + " - " + magicItem;

        if (power < 0) {
            this->AntiMags[power].push_back(str);
        }
        else if (power >= 100)
            this->Magicians[power].push_back(str);
        else
            this->Commoner[power].push_back(str);


        return *this;
    }

    void printAll() {
        //if (!AntiMags.empty()) {
            std::cout << "Anti-Mages:" << std::endl;
            for (std::pair<int, std::vector<std::string> > p : AntiMags) {
                for (int i = 0; i < p.second.size(); i++)
                    std::cout << p.second[i] << std::endl;
            }
        
        //if (!Commoner.empty()) {
            std::cout << "Commoners:" << std::endl;
            for (std::pair<int, std::vector<std::string> > p : Commoner) {
                for (int i = 0; i < p.second.size(); i++)
                    std::cout << p.second[i] << std::endl;
            }
        
        //if (!Magicians.empty()) {
            std::cout << "Mages:" << std::endl;
            for (std::pair<int, std::vector<std::string> > p : Magicians) {
                for (int i = 0; i < p.second.size(); i++)
                    std::cout << p.second[i] << std::endl;
            }
        
    }
};


#endif // !MAGIC_H
