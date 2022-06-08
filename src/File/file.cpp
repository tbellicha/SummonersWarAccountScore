/*
** EPITECH PROJECT, 2022
** SW
** File description:
** file
*/

#include "File/file.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string.h>
extern "C"
{
#include <sys/stat.h>
}

static void sortRunesByEfficiency(std::vector<Rune> &runes)
{
    for (size_t i = 0; i < runes.size(); i++)
        for (size_t j = i + 1; j < runes.size(); j++)
            if (runes[i].getEfficiency() > runes[j].getEfficiency())
                std::swap(runes[i], runes[j]);
}

void ParserJSON::read_json(char *filepath)
{
    std::ifstream file(filepath);
    std::string line;
    struct stat st;

    if (stat(filepath, &st) != 0)
        throw std::exception();
    if (!file.is_open())
        throw std::exception();
    this->_runes.clear();
    this->_wizard_name = getMemberValue(file, "wizard_name");
    while (getline(file, line)) {
        Rune curr_rune;
        curr_rune.setID(getMemberValue(file, "rune_id"));
        curr_rune.setInfos(file);
        this->_runes.push_back(curr_rune);
    }
    sortRunesByEfficiency(this->_runes);
}

std::vector<Rune> ParserJSON::getRunes(void) const
{
    return _runes;
}

std::string ParserJSON::getWizardName(void) const
{
    return this->_wizard_name;
}
