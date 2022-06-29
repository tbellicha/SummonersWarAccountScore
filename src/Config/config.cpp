/*
** EPITECH PROJECT, 2022
** SW
** File description:
** config
*/

#include "config.hpp"
#include "Rune/rune.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
extern "C"
{
#include <sys/stat.h>
}

static void sortPods(std::vector<pods_t> &pod)
{
    for (size_t i = 0; i < pod.size(); i++)
        for (size_t j = i + 1; j < pod.size(); j++)
            if (pod[i].coeff > pod[j].coeff)
                std::swap(pod[i], pod[j]);
}

extern std::map<runes_set, std::string> runes_set_name;
extern std::map<runes_stat_id, std::string> runes_stat_name;

void Config::readEffPods(std::ifstream &file)
{
    std::string line;
    pods_t curr_pod;

    while (std::getline(file, line)) {
        if (line == "")
            break;
        while (line[0] == ' ' || line[0] == '\t')
            line = &line[1];
        curr_pod.value = std::atof(line.substr(0, line.find(':')).c_str());
        curr_pod.coeff = std::atof(line.substr(line.find(':') + 1).c_str());
        this->_effpods.push_back(curr_pod);
    }
    sortPods(this->_effpods);
}

void Config::readSetPods(std::ifstream &file)
{
    std::string line;
    pods_t curr_pod;

    while (std::getline(file, line)) {
        if (line == "")
            break;
        while (line[0] == ' ' || line[0] == '\t')
            line = &line[1];
        for (size_t i = 0; i < runes_set_name.size(); i++) {
            if (runes_set_name[(runes_set)i] == line.substr(0, line.find(':'))) {
                curr_pod.value = (runes_set)i;
                break;
            }
        }
        curr_pod.coeff = std::atof(line.substr(line.find(':') + 1).c_str());
        this->_setpods.push_back(curr_pod);
    }
    sortPods(this->_setpods);
}

void Config::readMonsters(std::ifstream &file)
{
    std::string line;
    monsters_t curr_monster;

    while (std::getline(file, line)) {
        if (line == "")
            break;
        while (line[0] == ' ' || line[0] == '\t')
            line = &line[1];
        curr_monster.name = line.substr(0, line.find(':'));
        curr_monster.element = line.substr(line.find(':') + 1, line.size() - (line.find(':') + 1) - 2);
        curr_monster.nb_stars = std::atof(line.substr(line.find(':', line.find(':') + 1) + 1).c_str());
        this->_monsters.push_back(curr_monster);
    }
}

void Config::readConfigFile(void)
{
    std::ifstream file(CONFIG_FILEPATH);
    struct stat st;
    std::string line;

    if (stat(CONFIG_FILEPATH, &st) != 0)
        throw std::exception();
    if (!file.is_open())
        throw std::exception();
    while (std::getline(file, line)) {
        if (line == "EFF:")
            readEffPods(file);
        if (line == "SET:")
            readSetPods(file);
        if (line == "MONSTERS:")
            readMonsters(file);
    }
}

std::vector<pods_t> Config::getEffPods(void) const
{
    return this->_effpods;
}

std::vector<pods_t> Config::getSetPods(void) const
{
    return this->_setpods;
}

std::vector<monsters_t> Config::getMonsters(void) const
{
    return this->_monsters;
}
