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

// TYPE
enum artifacts_type {
    TYPE_ATTRIBUTE = 1,
    TYPE_ARCHETYPE = 2,
};

// ATTRIBUTE
enum attribute {
    ATTRIBUTE_FIRE = 1,
    ATTRIBUTE_WATER = 2,
    ATTRIBUTE_WIND = 3,
    ATTRIBUTE_LIGHT = 4,
    ATTRIBUTE_DARK = 5,
};

// UNIT_STYLE
enum artifacts_quality {
    STYLE_DEF = 1,
    STYLE_ATK = 1,
    STYLE_HP = 1,
    STYLE_SUPPORT = 1,
};

// SET_ID
enum artifacts_main_stat {
    MAIN_STAT_HP = 100,
    MAIN_STAT_ATK = 101,
    MAIN_STAT_DEF = 102,
};

// FIRST VALUE OF PREFIX/SEC_EFF
enum artifacts_stat_id {
    STAT_ATK_PROP_HP = 200,
    STAT_DEF_PROP_HP = 201,
    STAT_SPD_PROP_HP = 202,
    SPD_UNDER_INABILITY_EFFECT = 203,
    ATK_INCREASING_EFFECT = 204,
    DEF_INCREASING_EFFECT = 205,
    SPD_INCREASING_EFFECT = 206,
    CR_INCREASING_EFFECT = 207,
    DMG_COUNTERATTACK = 208,
    DMG_TOGETHER = 209,
    BOMB_DMG = 210,
    DMG_REFLECTED = 211,
    CRUSHING_HIT_DMG = 212,
    DMG_UNDER_INABILITY_EFFECT = 213,
    CRIT_DMG_RECEIVED = 214,
    LIFE_DRAIN = 215,
    HP_REVIVED = 216,
    ATB_REVIVED = 217,
    ADDITIONAL_DMG_BY_HP = 218,
    ADDITIONAL_DMG_BY_ATK = 219,
    ADDITIONAL_DMG_BY_DEF = 220,
    ADDITIONAL_DMG_BY_SPD = 221,
    CRIT_DMG_HP_CONDITION_GOOD = 222,
    CRIT_DMG_HP_CONDITION_BAD = 223,
    SINGLE_TARGET_CRIT_DMG = 224,
    DMG_DEALT_ON_FIRE = 300,
    DMG_DEALT_ON_WATER = 301,
    DMG_DEALT_ON_WIND = 302,
    DMG_DEALT_ON_LIGHT = 303,
    DMG_DEALT_ON_DARK = 304,
    DMG_RECEIVED_FROM_FIRE = 305,
    DMG_RECEIVED_FROM_WATER = 306,
    DMG_RECEIVED_FROM_WIND = 307,
    DMG_RECEIVED_FROM_LIGHT = 308,
    DMG_RECEIVED_FROM_DARK = 309,
    SKILL_1_CRIT_DMG = 400,
    SKILL_2_CRIT_DMG = 401,
    SKILL_3_CRIT_DMG = 402,
    SKILL_4_CRIT_DMG = 403,
    SKILL_1_RECOVERY = 404,
    SKILL_2_RECOVERY = 405,
    SKILL_3_RECOVERY = 406,
    SKILL_1_ACCURACY = 407,
    SKILL_2_ACCURACY = 408,
    SKILL_3_ACCURACY = 409,
};

// RANK
enum artifacts_quality {
    QUALITY_COMMON = 1,
    QUALITY_MAGIC = 2,
    QUALITY_RARE = 3,
    QUALITY_HERO = 4,
    QUALITY_LEGENDARY = 5,
};

typedef struct s_stat {
    artifacts_stat_id id;
    size_t value;
    size_t np_procs;
    size_t fourth;
    size_t nb_reroll;
} stat_t;

extern std::map<runes_stat_id, float> max_main_stat5;
extern std::map<runes_stat_id, float> max_main_stat6;

class Rune {
  public:
    void setInfos(std::ifstream &file);
    void setID(std::string);
    void calculateEfficiency(void);
    std::string getID(void) const;
    size_t getSlot(void) const;
    runes_quality getQuality(void) const;
    runes_stars getNbStars(void) const;
    runes_set getSet(void) const;
    stat_t getMainStat(void) const;
    stat_t getInnateStat(void) const;
    const stat_t *getSubStats(void) const;
    float getEfficiency(void) const;

  private:
    // rune_id
    std::string _id;
    // type
    artifacts_type _type;
    // rank
    artifacts_quality _quality;
    // pri_eff
    stat_t _main_stat;
    // prefix_eff
    stat_t _innate_stat;
    // sec_eff
    stat_t _sub_stats[4];

    float _efficiency;
};

#endif /* !RUNE_HPP_ */
