#include "../include/raylib.h"
#include "vec2.h"
#include "spring.h"

Spring spring_new(float k, float rest, Particle *a, Particle *b)
{
    Spring p;
    p.k = k;
    p.rest = rest;
    p.a = a;
    p.b = b;
    
    return p;
}

void spring_calc_force(Spring *p)
{
    Vec2 v_force = vec2_sub(p->b->pos, p->a->pos);
    float length = vec2_mag(v_force);
    float force_scalar = -p->k * (length - p->rest);
    v_force = vec2_normalize(v_force);
    v_force = vec2_scale(v_force, force_scalar);

    particle_force_apply(p->b, v_force);
    particle_force_apply(p->a, vec2_scale(v_force, -1.0f));
}

void spring_draw(Spring *p)
{
    DrawLineEx((Vector2){p->a->pos.x, p->a->pos.y}, (Vector2){p->b->pos.x, p->b->pos.y}, 3.0f, BLACK);
}
