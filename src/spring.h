#ifndef SPRING_H
#define SPRING_H

#include "../include/raylib.h"
#include "particle.h"

typedef struct Spring {
    float k;
    float rest;
    Particle *a;
    Particle *b;
} Spring;

Spring spring_new(float k, float rest, Particle *a, Particle *b);

void spring_calc_force(Spring *p);

void spring_draw(Spring *p);

#endif // SPRING_H
