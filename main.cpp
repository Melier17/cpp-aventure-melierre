#include "raylib.h"

int main(void)
{
    // Inicializar ventana
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "Aventura Melierre");
    
    SetTargetFPS(60);

    // Bucle del juego
    while (!WindowShouldClose())    
    {
        // Dibujar
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Aventura Melierre cargando...", 190, 200, 20, DARKGRAY);
            DrawText("Proximamente: Niveles + Combate", 160, 230, 20, MAROON);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
