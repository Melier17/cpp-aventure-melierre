##include "raylib.h"

struct Player {
    float x, y;
    float speed;
    int size;
    Color color;
};

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    InitWindow(screenWidth, screenHeight, "Aventura Melierre");
    SetTargetFPS(60);

    // Crear jugador
    Player player = { screenWidth/2, screenHeight/2, 5.0f, 30, MAROON };

    while (!WindowShouldClose())    
    {
        // --- LÓGICA ---
        if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) player.y -= player.speed;
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) player.y += player.speed;
        if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) player.x -= player.speed;
        if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) player.x += player.speed;

        // Limites de pantalla
        if (player.x < 0) player.x = 0;
        if (player.x > screenWidth - player.size) player.x = screenWidth - player.size;
        if (player.y < 0) player.y = 0;
        if (player.y > screenHeight - player.size) player.y = screenHeight - player.size;

        // --- DIBUJO ---
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawRectangle(player.x, player.y, player.size, player.size, player.color);
            DrawText("Muevete con WASD o Flechas", 10, 10, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
