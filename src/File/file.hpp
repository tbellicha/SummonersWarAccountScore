/*
** EPITECH PROJECT, 2022
** SW
** File description:
** file
*/

#ifndef FILE_HPP_
#define FILE_HPP_

#include "Rune/rune.hpp"
#include "utils/utils.hpp"

#include <vector>

#define MAX_NB_FILE 8

int read_json(char *filepath);

class ParserJSON {
  public:
    void read_json(char *filepath);
    std::vector<Rune> getRunes(void) const;
    std::string getWizardName(void) const;

  private:
    std::vector<Rune> _runes;
    std::string _wizard_name;
};

#endif /* !FILE_HPP_ */
