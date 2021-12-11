#include "raylib-cpp.hpp"
#include "chonky_timer.hpp"
#include "object.hpp"

int main()
{
    raylib::Window window(1000u, 1000u, "chonky engine is where it's at");
    window.SetTargetFPS(60);

    raylib::Camera3D camera;
    camera.position = Vector3{0.0f, 10.0f, 10.0f};
    camera.target = Vector3{0.0f, 0.0f, 0.0f};
    camera.up = Vector3{0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    chEn::Object obj("tempObject", "./res/models/test_cube.obj");
    obj.drawWires = true;
    float deltaTime = 0.0f;
    chEn::Timer deltaTimer;

    deltaTimer.start();
    while(!window.ShouldClose())
    { 
        deltaTime = deltaTimer.peekSinceLastPeek();

        if(IsKeyDown(KEY_S)) obj.transform.move(raylib::Vector3(0.0f, 0.0f, 0.1f));
        if(IsKeyDown(KEY_W)) obj.transform.move(raylib::Vector3(0.0f, 0.0f, -0.1f));
        if(IsKeyDown(KEY_D)) obj.transform.move(raylib::Vector3(0.1f, 0.0f, 0.0f));
        if(IsKeyDown(KEY_A)) obj.transform.move(raylib::Vector3(-0.1f, 0.0f, 0.0f));
        if(IsKeyDown(KEY_SPACE)) obj.transform.move(raylib::Vector3(0.0f, 0.1f, 0.0f));
        if(IsKeyDown(KEY_LEFT_CONTROL)) obj.transform.move(raylib::Vector3(0.0f, -0.1f, 0.0f));
        if(IsKeyDown(KEY_Q)) obj.transform.rotate(raylib::Vector3(0.0f, 1.0f, 0.0f), 0.02f);
        if(IsKeyDown(KEY_E)) obj.transform.rotate(raylib::Vector3(0.0f, 1.0f, 0.0f), -0.02f);
        

        BeginDrawing();
        
        window.ClearBackground(RAYWHITE);
        DrawFPS(10, 10);

        BeginMode3D(camera);

        obj.draw();
        DrawGrid(10.0f, 1.0f);

        EndMode3D();

        EndDrawing();
    }  

    window.Close();
    return 0;
}