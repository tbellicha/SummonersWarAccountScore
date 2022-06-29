/*
** EPITECH PROJECT, 2022
** SWAS
** File description:
** monster
*/

#include "monster.hpp"

#include <fstream>
#include <iostream>
extern "C"
{
#include <sys/stat.h>
}

void Monster::readMonstersFile(void)
{
    std::ifstream file(MONSTERS_FILEPATH);
    struct stat st;
    std::string line;

    if (stat(MONSTERS_FILEPATH, &st) != 0)
        throw std::exception();
    if (!file.is_open())
        throw std::exception();
    while (std::getline(file, line)) {
        _monsters[std::atof(line.substr(0, line.find(' ')).c_str())] = line.substr(line.find(' ') + 1);
    }
}

void Monster::mergeWithConfig(std::vector<monsters_t> monsters)
{
    for (std::size_t i = 0; i < monsters.size(); i++) {
        for (auto it = this->_monsters.begin(); it != this->_monsters.end(); it++) {
            if (it->second == monsters[i].name)
                std::cout << monsters[i].name << std::endl;
        }
    }
}

std::string Monster::getMonsterByID(int id) const
{
    try {
        return _monsters.at(id);
    } catch (std::out_of_range const &) {
        return "";
    }
}
