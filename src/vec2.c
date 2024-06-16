#include "vec2.h"
#include <math.h>

Vec2 vec2_new(float x, float y)
{
    return (Vec2){ x, y };
}

Vec2 vec2_zero(void)
{
    return (Vec2){ 0.0f, 0.0f };
}

Vec2 vec2_add(Vec2 a, Vec2 b)
{
    return (Vec2){ a.x + b.x, a.y + b.y };
}

Vec2 vec2_sub(Vec2 a, Vec2 b)
{
    return (Vec2){ a.x - b.x, a.y - b.y };
}

Vec2 vec2_scale(Vec2 v, float scalar)
{
    return (Vec2){ v.x*scalar, v.y*scalar };
}

float vec2_mag(Vec2 v)
{
    return sqrtf((v.x*v.x) + (v.y*v.y));
}

Vec2 vec2_normalize(Vec2 v)
{
    Vec2 result = {0};
    float magnitude = sqrtf((v.x*v.x) + (v.y*v.y));

    if (magnitude > 0)
    {
        result.x = v.x/magnitude;
        result.y = v.y/magnitude;
    }

    return result;
}
