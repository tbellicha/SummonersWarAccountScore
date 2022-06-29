/*
** EPITECH PROJECT, 2022
** SW
** File description:
** config
*/

#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <fstream>
#include <map>
#include <vector>

#define CONFIG_FILEPATH "config.txt"

typedef struct pods {
    float value;
    float coeff;
} pods_t;

typedef struct monsters {
    std::size_t id;
    std::string name;
    std::string element;
    std::size_t nb_stars;
} monsters_t;

class Config {
  public:
    void readConfigFile(void);
    void readEffPods(std::ifstream &file);
    void readSetPods(std::ifstream &file);
    void readMonsters(std::ifstream &file);
    std::vector<pods_t> getEffPods(void) const;
    std::vector<pods_t> getSetPods(void) const;
    std::vector<monsters_t> getMonsters(void) const;

  private:
    std::vector<pods_t> _effpods;
    std::vector<pods_t> _setpods;
    std::vector<monsters_t> _monsters;
};

#endif /* !CONFIG_HPP_ */
