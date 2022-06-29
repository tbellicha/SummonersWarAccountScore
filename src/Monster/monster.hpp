/*
** EPITECH PROJECT, 2022
** SWAS
** File description:
** monster
*/

#pragma once

#include "Config/config.hpp"

#include <map>
#include <string>

#define MONSTERS_FILEPATH "monsters.csv"

class Monster {
  public:
    void readMonstersFile();
    std::string getMonsterByID(int id) const;
    void mergeWithConfig(std::vector<monsters_t> monsters);

  private:
    std::map<int, std::string> _monsters;
};
