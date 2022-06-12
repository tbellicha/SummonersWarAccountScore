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

    while (getline(file, line)) {
        if (line == "")
            break;
        while (line[0] == ' ' || line[0] == '\t')
            line = &line[1];
        curr_pod.value = std::stof(line.substr(0, line.find(':')));
        curr_pod.coeff = std::stof(line.substr(line.find(':') + 1));
        this->_effpods.push_back(curr_pod);
    }
    sortPods(this->_effpods);
}

void Config::readSetPods(std::ifstream &file)
{
    std::string line;
    pods_t curr_pod;

    while (getline(file, line)) {
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
        curr_pod.coeff = std::stof(line.substr(line.find(':') + 1));
        this->_setpods.push_back(curr_pod);
    }
    sortPods(this->_setpods);
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
    while (getline(file, line)) {
        if (line == "EFF:")
            readEffPods(file);
        if (line == "SET:")
            readSetPods(file);
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
