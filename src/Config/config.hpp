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

class Config {
  public:
    void readConfigFile(void);
    void readEffPods(std::ifstream &file);
    void readSetPods(std::ifstream &file);
    std::vector<pods_t> getEffPods(void) const;
    std::vector<pods_t> getSetPods(void) const;

  private:
    std::vector<pods_t> _effpods;
    std::vector<pods_t> _setpods;
};

#endif /* !CONFIG_HPP_ */
