/*
** EPITECH PROJECT, 2022
** SW
** File description:
** main
*/

#include "Config/config.hpp"
#include "File/file.hpp"
#include "Rune/rune.hpp"

#include <iomanip>
#include <iostream>
#include <string.h>

extern std::map<rune_set, std::string> set_names;

int display_helper(void)
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\t/runes filepath" << std::endl;
    std::cout << "DESCRIPTION:" << std::endl;
    std::cout << "\tfilepath: Path of the JSON you want to inspect." << std::endl;
    return 0;
}

void print_rune(Rune rune)
{
    std::cout << "Rune[" << rune.getID() << "]: ";
    std::cout << set_names[rune.getSet()] << " ";
    std::cout << rune.getSlot() << " " << rune.getNbStars() << "\t| ";
    std::cout << rune.getMainStat().base_value << " " << stat_names[rune.getMainStat().id] << "\t| ";
    std::cout << rune.getInnateStat().base_value << " " << stat_names[rune.getInnateStat().id] << "\t| ";
    for (size_t i = 0; i < 4; i++)
        std::cout << "\t" << rune.getSubStats()[i].base_value + rune.getSubStats()[i].value_grind << " " << stat_names[rune.getSubStats()[i].id];
    std::cout << "\t= " << rune.getEfficiency() << std::endl;
}

void display_result(std::vector<Rune> &runes, Config &conf)
{
    size_t score = 0;
    size_t set_pod = 0;
    size_t eff_pod = 0;
    std::map<rune_set, std::map<int, int>> map_score = {};
    bool found_set = false;
    for (size_t i = 0; i < runes.size(); i++) {
        set_pod = 0;
        eff_pod = 0;
        for (int index = conf.getEffPods().size() - 1; index >= 0; index--) {
            if (runes[i].getEfficiency() >= conf.getEffPods()[index].value) {
                eff_pod = conf.getEffPods()[index].coeff;
                set_pod = 1;
                found_set = false;
                for (size_t set = 0; set < conf.getSetPods().size(); set++) {
                    if (runes[i].getSet() == conf.getSetPods()[set].value) {
                        set_pod = conf.getSetPods()[set].coeff;
                        map_score[runes[i].getSet()][index] += 1;
                        found_set = true;
                        break;
                    }
                }
                if (!found_set) {
                    map_score[(rune_set)0][index] += 1;
                }
                break;
            }
        }
        score += eff_pod * set_pod;
    }
    std::cout << "Score: " << score << std::endl << std::endl;
    for (size_t i = 0; i < conf.getEffPods().size(); i++)
        std::cout << "\t" << conf.getEffPods()[i].value;
    std::cout << std::endl << "Rest";
    for (size_t i = 0; i < conf.getEffPods().size(); i++)
        std::cout << "\t" << map_score[(rune_set)0][i];
    std::cout << std::endl;
    for (size_t y = 0; y < conf.getSetPods().size(); y++) {
        std::cout << set_names[(rune_set)conf.getSetPods()[y].value];
        for (size_t x = 0; x < conf.getEffPods().size(); x++) {
            std::cout << "\t" << map_score[(rune_set)conf.getSetPods()[y].value][x];
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv)
{
    ParserJSON file;
    std::vector<Rune> runes = {};
    std::vector<pods_t> effpods = {};
    std::vector<pods_t> setpods = {};
    std::vector<std::vector<int>> stat_pods = {};
    Config conf;

    std::cout << std::setprecision(5);
    if (argc == 1 || (argc == 2 && strcmp(argv[1], "-h") == 0))
        return display_helper();
    if (argc > MAX_NB_FILE + 1) {
        std::cout << "Invalid number of arguments. Use -h to display helper." << std::endl;
        return 84;
    }
    try {
        conf.readConfigFile();
    } catch (...) {
        std::cout << "Error while reading config file." << std::endl;
        return 84;
    }
    for (int i = 1; i < argc; i++) {
        try {
            file.read_json(argv[i]);
        } catch (...) {
            std::cout << "Error while reading " << argv[i] << " file." << std::endl;
            continue;
        }
        runes = file.getRunes();
        std::cout << "========[" << file.getWizardName() << "]========" << std::endl;
        display_result(runes, conf);
        if (i < argc - 1)
            std::cout << std::endl;
    }
}
