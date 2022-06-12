/*
** EPITECH PROJECT, 2022
** SW
** File description:
** rune
*/

#include "rune.hpp"
#include "utils/utils.hpp"

#include <iostream>

void Rune::setInfos(std::ifstream &file)
{
    try {
        this->_slot = (size_t)stoi(getMemberValue(file, "slot_no"));
    } catch (std::exception &e) {
        return;
    }
    this->_quality = (runes_quality)stoi(getMemberValue(file, "rank"));
    this->_nb_stars = (runes_stars)stoi(getMemberValue(file, "class"));
    this->_set = (runes_set)stoi(getMemberValue(file, "set_id"));
    this->_main_stat = readMainStat(file);
    this->_innate_stat = readInnateStat(file);
    readSubStat(file, this->_sub_stats, this->_quality > 10 ? this->_quality - 11 : this->_quality - 1);
    calculateEfficiency();
}

void Rune::setID(std::string id)
{
    this->_id = id;
}

float getMaxValueStat6(stat_t stat)
{
    switch (stat.id) {
        case STAT_HP: return 750;
        case STAT_ATK:
        case STAT_DEF: return 40;
        case STAT_HP_PCT:
        case STAT_ATK_PCT:
        case STAT_DEF_PCT:
        case STAT_RESIST_PCT:
        case STAT_ACCURACY_PCT: return 8;
        case STAT_SPD:
        case STAT_CRIT_RATE_PCT: return 6;
        case STAT_CRIT_DMG_PCT: return 7;
        default: return 0;
    }
}

float getMaxValueStat5(stat_t stat)
{
    switch (stat.id) {
        case STAT_HP: return 600;
        case STAT_ATK:
        case STAT_DEF: return 30;
        case STAT_HP_PCT:
        case STAT_ATK_PCT:
        case STAT_DEF_PCT:
        case STAT_RESIST_PCT:
        case STAT_ACCURACY_PCT: return 7;
        case STAT_SPD:
        case STAT_CRIT_RATE_PCT:
        case STAT_CRIT_DMG_PCT: return 5;
        default: return 0;
    }
}

float calculateEffStat6(stat_t stat)
{
    return ((stat.base_value + stat.value_grind) / (getMaxValueStat6(stat) * 5));
}

void Rune::calculateEfficiency(void)
{
    float eff_main = 0;
    float eff_innate = 0;
    float eff_subs = 0;

    switch (_nb_stars) {
        case FIVE_ANTIC:
        case FIVE:
            eff_main = max_main_stat5[this->_main_stat.id] / max_main_stat6[this->_main_stat.id];
            if (this->_innate_stat.id != STAT_NONE)
                eff_innate = calculateEffStat6(this->_innate_stat);
            for (int i = 0; i < 4; i++)
                eff_subs += calculateEffStat6(_sub_stats[i]);
            this->_efficiency = ((eff_main + eff_innate + eff_subs) / 2.8) * 100;
            break;
        case SIX_ANTIC:
        case SIX:
            eff_main = max_main_stat6[this->_main_stat.id] / max_main_stat6[this->_main_stat.id];
            if (this->_innate_stat.id != STAT_NONE)
                eff_innate = calculateEffStat6(this->_innate_stat);
            for (int i = 0; i < 4; i++)
                eff_subs += calculateEffStat6(_sub_stats[i]);
            this->_efficiency = ((eff_main + eff_innate + eff_subs) / 2.8) * 100;
            break;
        default: this->_efficiency = 0.00; break;
    }
}

std::string Rune::getID(void) const
{
    return this->_id;
}

size_t Rune::getSlot(void) const
{
    return this->_slot;
}

runes_quality Rune::getQuality(void) const
{
    return this->_quality;
}

runes_stars Rune::getNbStars(void) const
{
    return this->_nb_stars;
}

runes_set Rune::getSet(void) const
{
    return this->_set;
}

stat_t Rune::getMainStat(void) const
{
    return this->_main_stat;
}

stat_t Rune::getInnateStat(void) const
{
    return this->_innate_stat;
}

const stat_t *Rune::getSubStats(void) const
{
    return this->_sub_stats;
}

float Rune::getEfficiency(void) const
{
    return this->_efficiency;
}
