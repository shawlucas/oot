// Hardcoded Instruments
#define INSTR_SFX         126
#define INSTR_DRUM        127
#define INSTR_WV_SAWTOOTH 128
#define INSTR_WV_TRIANGLE 129
#define INSTR_WV_SINE     130
#define INSTR_WV_SQUARE   131
#define INSTR_WV_NOISE    132
#define INSTR_WV_BELL     133
#define INSTR_WV_8PULSE   134
#define INSTR_WV_4PULSE   135
#define INSTR_WV_4PULSE2  136

// Instrument Notes
#define NOTE_A0       0
#define NOTE_BF0      1
#define NOTE_B0       2
#define NOTE_C1       3
#define NOTE_DF1      4
#define NOTE_D1       5
#define NOTE_EF1      6
#define NOTE_E1       7
#define NOTE_F1       8
#define NOTE_GF1      9
#define NOTE_G1      10
#define NOTE_AF1     11
#define NOTE_A1      12
#define NOTE_BF1     13
#define NOTE_B1      14
#define NOTE_C2      15
#define NOTE_DF2     16
#define NOTE_D2      17
#define NOTE_EF2     18
#define NOTE_E2      19
#define NOTE_F2      20
#define NOTE_GF2     21
#define NOTE_G2      22
#define NOTE_AF2     23
#define NOTE_A2      24
#define NOTE_BF2     25
#define NOTE_B2      26
#define NOTE_C3      27
#define NOTE_DF3     28
#define NOTE_D3      29
#define NOTE_EF3     30
#define NOTE_E3      31
#define NOTE_F3      32
#define NOTE_GF3     33
#define NOTE_G3      34
#define NOTE_AF3     35
#define NOTE_A3      36
#define NOTE_BF3     37
#define NOTE_B3      38
#define NOTE_C4      39
#define NOTE_DF4     40
#define NOTE_D4      41
#define NOTE_EF4     42
#define NOTE_E4      43
#define NOTE_F4      44
#define NOTE_GF4     45
#define NOTE_G4      46
#define NOTE_AF4     47
#define NOTE_A4      48
#define NOTE_BF4     49
#define NOTE_B4      50
#define NOTE_C5      51
#define NOTE_DF5     52
#define NOTE_D5      53
#define NOTE_EF5     54
#define NOTE_E5      55
#define NOTE_F5      56
#define NOTE_GF5     57
#define NOTE_G5      58
#define NOTE_AF5     59
#define NOTE_A5      60
#define NOTE_BF5     61
#define NOTE_B5      62
#define NOTE_C6      63
#define NOTE_DF6     64
#define NOTE_D6      65
#define NOTE_EF6     66
#define NOTE_E6      67
#define NOTE_F6      68
#define NOTE_GF6     69
#define NOTE_G6      70
#define NOTE_AF6     71
#define NOTE_A6      72
#define NOTE_BF6     73
#define NOTE_B6      74
#define NOTE_C7      75
#define NOTE_DF7     76
#define NOTE_D7      77
#define NOTE_EF7     78
#define NOTE_E7      79
#define NOTE_F7      80
#define NOTE_GF7     81
#define NOTE_G7      82
#define NOTE_AF7     83
#define NOTE_A7      84
#define NOTE_BF7     85
#define NOTE_B7      86
#define NOTE_C8      87
#define NOTE_DF8     88
#define NOTE_D8      89
#define NOTE_EF8     90
#define NOTE_E8      91
#define NOTE_F8      92
#define NOTE_GF8     93
#define NOTE_G8      94
#define NOTE_AF8     95
#define NOTE_A8      96
#define NOTE_BF8     97
#define NOTE_B8      98
#define NOTE_C9      99
#define NOTE_DF9    100
#define NOTE_D9     101
#define NOTE_EF9    102
#define NOTE_E9     103
#define NOTE_F9     104
#define NOTE_GF9    105
#define NOTE_G9     106
#define NOTE_AF9    107
#define NOTE_A9     108
#define NOTE_BF9    109
#define NOTE_B9     110
#define NOTE_C10    111
#define NOTE_DF10   112
#define NOTE_D10    113
#define NOTE_EF10   114
#define NOTE_E10    115
#define NOTE_F10    116
#define NOTE_BFNEG1 117
#define NOTE_BNEG1  118
#define NOTE_C0     119
#define NOTE_DF0    120
#define NOTE_D0     121
#define NOTE_EF0    122
#define NOTE_E0     123
#define NOTE_F0     124
#define NOTE_GF0    125
#define NOTE_G0     126
#define NOTE_AF0    127

typedef enum {
    SOUNDFONT_SFX_1,
    SOUNDFONT_SFX_2,
    SOUNDFONT_AMBIENCE,
    SOUNDFONT_ORCHESTRA,
    SOUNDFONT_DEKU_TREE,
    SOUNDFONT_MARKET,
    SOUNDFONT_TITLE,
    SOUNDFONT_JABU_JABU,
    SOUNDFONT_KAKARIKO_CHILD,
    SOUNDFONT_FAIRY_FOUNTAIN,
    SOUNDFONT_FIRE_TEMPLE,
    SOUNDFONT_DODONGO_CAVERN,
    SOUNDFONT_FOREST_TEMPLE,
    SOUNDFONT_LON_LON_RANCH,
    SOUNDFONT_GORON_CITY,
    SOUNDFONT_KOKIRI_FOREST,
    SOUNDFONT_SPIRIT_TEMPLE,
    SOUNDFONT_HORSE_RACE,
    SOUNDFONT_WARP_SONGS,
    SOUNDFONT_LEGENDS,
    SOUNDFONT_MINIGAMES,
    SOUNDFONT_ZORA_DOMAIN,
    SOUNDFONT_SHOPS,
    SOUNDFONT_ICE_CAVERN,
    SOUNDFONT_SHADOW_TEMPLE,
    SOUNDFONT_WATER_TEMPLE,
    SOUNDFONT_UNKNOWN_1,
    SOUNDFONT_GERUDO_VALLEY,
    SOUNDFONT_LAKESIDE_LABORATORY, 
    SOUNDFONT_KOTAKE_KOUME_THEME,
    SOUNDFONT_GANON_CASTLE_ORGAN,
    SOUNDFONT_GANON_CASTLE,
    SOUNDFONT_GANONDORF_BATTLE,
    SOUNDFONT_ENDING_1,
    SOUNDFONT_ENDING_2,
    SOUNDFONT_GAME_OVER,
    SOUNDFONT_KAEPORA_GAEBORA_THEME,
    SOUNDFONT_UNKNOWN_2
} SoundfontId;