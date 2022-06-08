/*
** EPITECH PROJECT, 2022
** SW
** File description:
** removeSpaces
*/

#include <string>

std::string removeSpaces(std::string line)
{
    std::string result = "";

    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] != ' ')
            result += line[i];
    }
    return result;
}
