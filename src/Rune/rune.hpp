/*
** EPITECH PROJECT, 2022
** SW
** File description:
** rune
*/

#ifndef RUNE_HPP_
#define RUNE_HPP_

#include <fstream>
#include <map>
#include <unistd.h>

// SET_ID
enum rune_set {
    SET_ENERGY = 1,
    SET_GUARD = 2,
    SET_SWIFT = 3,
    SET_BLADE = 4,
    SET_RAGE = 5,
    SET_FOCUS = 6,
    SET_ENDURE = 7,
    SET_FATAL = 8,
    SET_DESPAIR = 10,
    SET_VAMPIRE = 11,
    SET_VIOLENT = 13,
    SET_NEMESIS = 14,
    SET_WILL = 15,
    SET_SHIELD = 16,
    SET_REVENGE = 17,
    SET_DESTROY = 18,
    SET_FIGHT = 19,
    SET_DETERMINATION = 20,
    SET_ENHANCE = 21,
    SET_ACCURACY = 22,
    SET_TOLERANCE = 23,
};

// FIRST VALUE OF PREFIX/SEC_EFF
enum stat_id {
    STAT_NONE = 0,
    STAT_HP = 1,
    STAT_HP_PCT,
    STAT_ATK,
    STAT_ATK_PCT,
    STAT_DEF,
    STAT_DEF_PCT,
    STAT_SPD = 8,
    STAT_CRIT_RATE_PCT,
    STAT_CRIT_DMG_PCT,
    STAT_RESIST_PCT,
    STAT_ACCURACY_PCT,
};

// RANK
enum quality {
    QUALITY_NORMAL = 1,
    QUALITY_MAGIC,
    QUALITY_RARE,
    QUALITY_HERO,
    QUALITY_LEGEND,
    QUALITY_NORMAL_ANTIC = 11,
    QUALITY_MAGIC_ANTIC,
    QUALITY_RARE_ANTIC,
    QUALITY_HERO_ANTIC,
    QUALITY_LEGEND_ANTIC,
};

// CLASS
enum stars {
    ONE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    ONE_ANTIC = 11,
    TWO_ANTIC,
    THREE_ANTIC,
    FOUR_ANTIC,
    FIVE_ANTIC,
    SIX_ANTIC,
};

static std::map<rune_set, std::string> set_names = {
    {SET_ENERGY, "Energy"},
    {SET_GUARD, "Guard"},
    {SET_SWIFT, "Swift"},
    {SET_BLADE, "Blade"},
    {SET_RAGE, "Rage"},
    {SET_FOCUS, "Focus"},
    {SET_ENDURE, "Endure"},
    {SET_FATAL, "Fatal"},
    {SET_DESPAIR, "Despair"},
    {SET_VAMPIRE, "Vampire"},
    {SET_VIOLENT, "Violent"},
    {SET_NEMESIS, "Nemesis"},
    {SET_WILL, "Will"},
    {SET_SHIELD, "Shield"},
    {SET_REVENGE, "Revenge"},
    {SET_DESTROY, "Destroy"},
    {SET_FIGHT, "Fight"},
    {SET_DETERMINATION, "Determination"},
    {SET_ENHANCE, "Enhance"},
    {SET_ACCURACY, "Accuracy"},
    {SET_TOLERANCE, "Tolerance"},
};

static std::map<stat_id, std::string> stat_names = {
    {STAT_HP, "HP"},
    {STAT_HP_PCT, "HP%"},
    {STAT_ATK, "ATK"},
    {STAT_ATK_PCT, "AK%"},
    {STAT_DEF, "DEF"},
    {STAT_DEF_PCT, "DF%"},
    {STAT_SPD, "SPD"},
    {STAT_CRIT_RATE_PCT, "CR%"},
    {STAT_CRIT_DMG_PCT, "CD%"},
    {STAT_RESIST_PCT, "RES"},
    {STAT_ACCURACY_PCT, "ACC"},
};

typedef struct s_stat {
    stat_id id;
    size_t base_value;
    size_t third;
    size_t value_grind;
} stat_t;

extern std::map<stat_id, float> max_main_stat5;
extern std::map<stat_id, float> max_main_stat6;

class Rune {
  public:
    void setInfos(std::ifstream &file);
    void setID(std::string);
    void calculateEfficiency(void);
    std::string getID(void) const;
    size_t getSlot(void) const;
    quality getQuality(void) const;
    stars getNbStars(void) const;
    rune_set getSet(void) const;
    stat_t getMainStat(void) const;
    stat_t getInnateStat(void) const;
    const stat_t *getSubStats(void) const;
    float getEfficiency(void) const;

  private:
    // rune_id
    std::string _id;
    // slot_no
    size_t _slot;
    // rank
    quality _quality;
    // class
    stars _nb_stars;
    // set_id
    rune_set _set;
    // pri_eff
    stat_t _main_stat;
    // prefix_eff
    stat_t _innate_stat;
    // sec_eff
    stat_t _sub_stats[4];

    float _efficiency;
};

#endif /* !RUNE_HPP_ */
