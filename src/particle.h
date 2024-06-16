#ifndef PARTICLE_H
#define SPRING_H

#include "../include/raylib.h"
#include "vec2.h"

typedef struct Particle {
    Vec2 pos;
    Vec2 v;
    Vec2 a;
    float damping;
    int r;
    Color color;
} Particle;

Particle particle_new(Vec2 pos, Color color);

void particle_draw(Particle *p);

void particle_force_apply(Particle *p, Vec2 v_force);

void particle_update(Particle *p);

void particle_coll_res(Particle *p);

#endif // !PARTICLE_H
