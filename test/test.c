#include <assert.h>
#include <stddef.h>
#include <stdio.h>

typedef struct point_t point_t;

struct point_t {
    double x;
    double y;
};

int main(void)
{
    point_t pts[] = {
        { .x = 0.0, .y = 0.0 },
        { .x = 1.0, .y = 2.0 },
        { .x = 3.0, .y = 4.0 }
    };

    for (size_t i = 0; i < 3; i++) {
        printf("(%.2f, %.2f)\n", pts[i].x, pts[i].y);
    }

    return 0;
}