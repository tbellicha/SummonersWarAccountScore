/*
** EPITECH PROJECT, 2022
** SW
** File description:
** getStat
*/

#include "utils.hpp"

#include <iostream>

stat_t readMainStat(std::ifstream &file)
{
    stat_t main_stat;
    std::string line;

    while (getline(file, line)) {
        if (line.find("pri_eff") != std::string::npos) {
            getline(file, line);
            line = removeSpaces(line);
            line = line.substr(0, line.find(","));
            main_stat.id = (stat_id)std::stoi(line);
            getline(file, line);
            line = removeSpaces(line);
            line = line.substr(0, line.find(","));
            main_stat.base_value = (stat_id)std::stoi(line);
            main_stat.third = 0;
            main_stat.value_grind = 0;
            break;
        }
    }
    return main_stat;
}

stat_t readInnateStat(std::ifstream &file)
{
    stat_t innate_stat;
    std::string line;

    innate_stat.id = STAT_NONE;
    innate_stat.base_value = 0;
    innate_stat.value_grind = 0;
    while (getline(file, line)) {
        if (line.find("prefix_eff") != std::string::npos) {
            getline(file, line);
            line = removeSpaces(line);
            line = line.substr(0, line.find(","));
            innate_stat.id = (stat_id)std::stoi(line);
            getline(file, line);
            line = removeSpaces(line);
            line = line.substr(0, line.find(","));
            innate_stat.base_value = (stat_id)std::stoi(line);
            innate_stat.third = 0;
            innate_stat.value_grind = 0;
            break;
        }
    }
    return innate_stat;
}

void readSubStat(std::ifstream &file, stat_t *stats, size_t nb_subs)
{
    std::string line;

    while (getline(file, line)) {
        if (line.find("sec_eff") != std::string::npos && line.find("sec_eff :[]") == std::string::npos) {
            size_t i = 0;
            for (i = 0; i < nb_subs; i++) {
                // Skip the first line "["
                getline(file, line);
                getline(file, line);
                line = removeSpaces(line);
                line = line.substr(0, line.find(","));
                stats[i].id = (stat_id)std::stoi(line);
                getline(file, line);
                line = removeSpaces(line);
                line = line.substr(0, line.find(","));
                stats[i].base_value = (stat_id)std::stoi(line);
                getline(file, line);
                line = removeSpaces(line);
                line = line.substr(0, line.find(","));
                stats[i].third = (stat_id)std::stoi(line);
                getline(file, line);
                line = removeSpaces(line);
                line = line.substr(0, line.find(","));
                stats[i].value_grind = (stat_id)std::stoi(line);
                // Skip the last line "],"
                getline(file, line);
            }
            for (; i < 4; i++) {
                stats[i].id = STAT_NONE;
                stats[i].base_value = 0;
                stats[i].third = 0;
                stats[i].value_grind = 0;
            }
            break;
        }
    }
}
