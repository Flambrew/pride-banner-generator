#include <stdint.h>

static const uint8_t BANNER_HEIGHT = 80;
static const uint8_t BANNER_WIDTH = 45;
static const uint8_t SPACE_WIDTH = 1;
static const uint8_t CHAR_WIDTH = 5;
static const uint8_t CHAR_HEIHT = 5;
static const uint8_t OFFSET_DEFAULT = 0;

/* For flags with nonuniform stripe widths use quantity to create proportions:
    (ex: bisexual flag - pink, pink, purple, blue, blue) */
typedef struct flag {
    uint32_t *color;
    uint8_t count;
} Flag;

typedef enum pattern_area {
    HALF_TOP,
    HALF_BOTTOM,
    HALF_LEFT,
    HALF_RIGHT,
    THIRD_TOP,
    THIRD_HORIZONTAL,
    THIRD_BOTTOM,
    THIRD_LEFT,
    THIRD_RIGHT,
    THIRD_VERTICAL,
    
} Pattern_Area;

typedef struct pattern {
    Pattern_Area area;
    Flag color;
} Pattern;

typedef enum decal {
    AROACE_AGENDER,
    MALE,
    FEMALE,
    ENBY_MIX,
    ENBY_GLYPH,
    ENBY_FEM_MIX,
    ENBY_FEM_GLYPH,
    ENBY_MASC_MIX,
    ENBY_MASC_GLYPH,
    DEMIBOY,
    DEMIGIRL,
    BIGENDER,
    TRANSGENDER,
    GAY,
    LESBIAN,
    STRAIGHT,
    BISEXUAL,
    BISEXUAL_MALE,
    BISEXUAL_FEMALE,
    BISEXUAL_ENBY_MIX,
    BISEXUAL_ENBY_GLYPH,
    BISEXUAL_TRANSGENDER,
    TORIC_ENBY,
    TORIC_TRANS,
    TRIXIC_ENBY,
    TRIXIC_TRANS,
    FEMBOY,
    TOMBOY,
    ORCHIE,
    OOPHIE,
} Decal;

typedef struct banner {
    Pattern *patterns;
    Decal *decal;
    char *text;
} Banner;

void add_flag() {

}

void line_width(char *str, uint8_t *offset, int8_t *chars_remaining) {
    char c;
    uint8_t width; // to account for no initial interchar spacing
    for (width = -1; (c = str[*offset]) != '\n' && c != '\0'; ++*offset) {
        if (c >= '0' && c <= '9' || c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
            width += CHAR_WIDTH;
        } else if (c == ' ') {
            width += SPACE_WIDTH;
        } else {
            *chars_remaining = INT8_MIN;
            return;
        }
        ++width;
    }

    if (c == '\n') {
        ++*offset;
    }

    *chars_remaining = BANNER_WIDTH - 2 - width;
}