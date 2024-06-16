#ifndef VEC2_H
#define VEC2_H

typedef struct Vec2 {
    float x;
    float y;
} Vec2;

Vec2 vec2_new(float x, float y);

Vec2 vec2_zero(void);

Vec2 vec2_add(Vec2 a, Vec2 b);

Vec2 vec2_sub(Vec2 a, Vec2 b);

Vec2 vec2_scale(Vec2 v, float scalar);

float vec2_mag(Vec2 v);

Vec2 vec2_normalize(Vec2 v);

#endif // !VEC2_H
