/*
** EPITECH PROJECT, 2022
** SW
** File description:
** strstr
*/

#include "utils.hpp"

#include <fstream>

std::string getMemberValue(std::ifstream &file, std::string member)
{
    std::string complete_member = "\"" + member + "\": ";
    std::string line;

    while (std::getline(file, line))
        if (line.find(complete_member) != std::string::npos)
            return line.substr(line.find(complete_member) + complete_member.length(), line.length() - 1 - (line.find(complete_member) + complete_member.length()));
    return "";
}
