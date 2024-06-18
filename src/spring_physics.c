#include "../include/raylib.h"
#include "spring.h"
#include "d_array.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    const Vec2 gravity = { 0.0f, 0.5f };
    DArray *springs = da_new();

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Sandbox");
    SetTargetFPS(60);

    const float k = 0.1f;
    const float rest = 100.0f;

    Particle anchor = particle_new((Vec2){ 200.0f, 100.0f }, RED);
    Particle particle1 = particle_new((Vec2){ 300.0f, 100.0f }, BLUE);
    Particle particle2 = particle_new((Vec2){ 300.0f, 200.0f }, GREEN);
    Particle particle3 = particle_new((Vec2){ 200.0f, 200.0f }, YELLOW);

    float diagonal_len = vec2_mag(vec2_sub(anchor.pos, particle2.pos));

    Spring spring1 = spring_new(k, rest, &anchor, &particle1);
    Spring spring2 = spring_new(k, rest, &particle1, &particle2);
    Spring spring3 = spring_new(k, rest, &particle2, &particle3);
    Spring spring4 = spring_new(k, rest, &particle3, &anchor);
    Spring spring5 = spring_new(k, diagonal_len, &anchor, &particle2);
    Spring spring6 = spring_new(k, diagonal_len, &particle3, &particle1);

    da_append(springs, &spring1);
    da_append(springs, &spring2);
    da_append(springs, &spring3);
    da_append(springs, &spring4);
    da_append(springs, &spring5);
    da_append(springs, &spring6);

    while (!WindowShouldClose()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Particle *anchor = ((Spring *)springs->items[0])->a;
            anchor->pos.y = GetMouseY();
            anchor->pos.x = GetMouseX();
            anchor->v.y = 0;
            anchor->v.x = 0;
        }

        for (size_t i = 0; i < springs->length; i++)
        {
            Spring *spring = (Spring *)springs->items[i];

            spring_calc_force(spring);
            particle_force_apply(spring->a, gravity);
            particle_force_apply(spring->b, gravity);
            particle_update(spring->a);
            particle_update(spring->b);
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (size_t i = 0; i < springs->length; i++)
        {
            Spring *spring = (Spring *)springs->items[i];

            spring_draw(spring);
            particle_draw(spring->a);
            particle_draw(spring->b);
        }

        EndDrawing();
    }

    CloseWindow();

    da_delete(springs);

    return 0;
}
