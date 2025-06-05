#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#include <stdlib.h>
#include <time.h>

#define _DEFAULT_SOURCE 1

typedef struct point
{
    float x;
    float y;
} point_t;

point_t random_point()
{
    return (point_t)
    {
        .x = 1 - 2 * (float)rand() / (float)RAND_MAX,
        .y = 1 - 2 * (float)rand() / (float)RAND_MAX,
    };
}

bool is_point_in_unit_circle(point_t const p)
{
    return (p.x * p.x + p.y * p.y <= 1);
}

point_t random_point_in_unit_circle()
{
    point_t p;
    do
    {
        p = random_point();
    } while (!is_point_in_unit_circle(p));
 
    return p;
}

float approximate_pi(int const num_samples)
{
    int inside = 0;
    for (int i = 0; i < num_samples; ++i)
    {
        point_t const p = random_point();
        if (is_point_in_unit_circle(p))
        {
            ++inside;
        }
    }
    return 4.0f * (float)inside / (float)num_samples;
}

int main(void)
{
    srand(time(0));

    point_t const piuc = random_point_in_unit_circle();
    printf("Point{x: %.2f, y: %.2f} is in unit circle\n", piuc.x, piuc.y);

    printf("PI is approximately %.6f!\n", approximate_pi(1000));

    return 0;
}