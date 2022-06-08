/*
** EPITECH PROJECT, 2022
** SW
** File description:
** utils
*/

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include "Rune/rune.hpp"

#include <string>

std::string getMemberValue(std::ifstream &file, std::string member);
stat_t readMainStat(std::ifstream &file);
stat_t readInnateStat(std::ifstream &file);
void readSubStat(std::ifstream &file, stat_t *stats, size_t nb_subs);
std::string removeSpaces(std::string line);

#endif /* !UTILS_HPP_ */
