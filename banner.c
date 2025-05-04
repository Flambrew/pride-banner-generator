#include <stdint.h>

static const uint32_t BANNER_HEIGHT = 80;
static const uint32_t BANNER_WIDTH = 45;

/* For flags with nonuniform stripe widths use quantity to create proportions:
    (ex: bisexual flag - pink, pink, purple, blue, blue) */
typedef struct flag {
    uint32_t *color;
    uint8_t count;
} Flag;

typedef struct banner {
    uint32_t bitmap[BANNER_HEIGHT * BANNER_WIDTH];
} Banner;

