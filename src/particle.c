#include "../include/raylib.h"
#include "vec2.h"
#include "particle.h"

Particle particle_new(Vec2 pos, Color color)
{
    Particle p;
    p.pos = pos;
    p.v = vec2_zero();
    p.a = vec2_zero();
    p.damping = 0.95f;
    p.r = 10;
    p.color = color;

    return p;
}

void particle_draw(Particle *p)
{
    DrawCircle(p->pos.x, p->pos.y, p->r, p->color);
}

void particle_force_apply(Particle *p, Vec2 v_force)
{
    p->a = vec2_add(p->a, v_force);
}

void particle_update(Particle *p)
{
    p->v = vec2_add(p->v, p->a);
    p->v = vec2_scale(p->v, p->damping);
    p->pos = vec2_add(p->pos, p->v);
    particle_coll_res(p);
    p->a = vec2_zero();
}

void particle_coll_res(Particle *p) {
    int width = GetScreenWidth();
    int height = GetScreenHeight();

    if (p->pos.x - p->r <= 0) {
        p->pos.x = p->r;
        p->v.x *= -1.0f * 0.5f;
    }
    if (p->pos.x + p->r >= width) {
        p->pos.x = width - p->r;
        p->v.x *= -1.0f * 0.5f;
    }
    if (p->pos.y - p->r <= 0) {
        p->pos.y = p->r;
        p->v.y *= -1.0f * 0.5f;
    }
    if (p->pos.y + p->r >= height) {
        p->pos.y = height - p->r;
        p->v.y *= -1.0f * 0.5f;
    }
}
