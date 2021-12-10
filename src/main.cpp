#include <raylib.h>


int main()
{
    InitWindow(600u, 600u, "chonky engine is where it's at");
    Model temp = LoadModel("res/models/Computer.gltf");
    Camera3D camera;
    camera.position = Vector3{0.0f, 10.0f, 10.0f};
    camera.target = Vector3{0.0f, 0.0f, 0.0f};
    camera.up = Vector3{0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    while(!WindowShouldClose())
    { 
        BeginDrawing();
            ClearBackground(GRAY);
            BeginMode3D(camera);
            DrawModelEx(temp, Vector3{0.0f, 0.0f, 0.0f}, Vector3{1.0f, 0.0f, 0.0f}, 90.0f, Vector3{1.0f, 1.0f, 1.0f}, WHITE);
            //DrawCube(Vector3(), 2.0f, 2.0f, 2.0f, GREEN);
            
            DrawGrid(10, 1.0f);

            EndMode3D();
        EndDrawing();
    }

    UnloadModel(temp);
    CloseWindow();
    return 0;
}
