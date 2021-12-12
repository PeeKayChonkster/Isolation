#include "raylib-cpp.hpp"
#include "chonky_timer.hpp"
#include "billboard.hpp"
#include "debug.hpp"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

int main()
{
    raylib::Window window(1000u, 1000u, "chonky engine is where it's at");
    window.SetTargetFPS(60);

    raylib::Camera3D camera;    
    raylib::Vector3 cameraInitialOffset;
    camera.position = Vector3{0.0f, 10.0f, 10.0f};
    camera.target = Vector3{0.0f, 0.0f, 0.0f};
    camera.up = Vector3{0.0f, 1.0f, 0.0f};
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    chen::Billboard sadman("./res/textures/sad_man.png", &camera, "Sad man");

    cameraInitialOffset = raylib::Vector3(camera.position) - sadman.transform.getGlobalPosition();

    float deltaTime = 0.0f;
    chen::Timer deltaTimer;

    deltaTimer.start();
    while(!window.ShouldClose())
    { 
        deltaTime = deltaTimer.peekSinceLastPeek();
        chen::Debug::printLine("DeltaTime=" + std::to_string(deltaTime));

        if(IsKeyDown(KEY_S)) sadman.transform.move(raylib::Vector3(0.0f, 0.0f, 0.1f));
        if(IsKeyDown(KEY_W)) sadman.transform.move(raylib::Vector3(0.0f, 0.0f, -0.1f));
        if(IsKeyDown(KEY_D)) sadman.transform.move(raylib::Vector3(0.1f, 0.0f, 0.0f));
        if(IsKeyDown(KEY_A)) sadman.transform.move(raylib::Vector3(-0.1f, 0.0f, 0.0f));
        if(IsKeyDown(KEY_SPACE)) sadman.transform.move(raylib::Vector3(0.0f, 0.1f, 0.0f));
        if(IsKeyDown(KEY_LEFT_CONTROL)) sadman.transform.move(raylib::Vector3(0.0f, -0.1f, 0.0f));
        if(IsKeyDown(KEY_Q)) sadman.transform.rotate(raylib::Vector3(0.0f, 1.0f, 0.0f), 0.02f);
        if(IsKeyDown(KEY_E)) sadman.transform.rotate(raylib::Vector3(0.0f, 1.0f, 0.0f), -0.02f);
        if(IsKeyDown(KEY_H)) sadman.visible = !sadman.visible;
        
        camera.target = raylib::Vector3(camera.target).Lerp(sadman.transform.getGlobalPosition(), 0.1f);
        camera.position = raylib::Vector3(camera.position).Lerp(sadman.transform.getGlobalPosition() + cameraInitialOffset, 0.1f);

        BeginDrawing();////////////////////////////////////////
        
        window.ClearBackground(SKYBLUE);
        DrawFPS(10, 10);

        BeginMode3D(camera);////3333333333333////////

        sadman.draw();

        DrawGrid(10.0f, 1.0f);

        EndMode3D();//////33333333333333//////////////
        
        chen::Debug::draw();
        EndDrawing();//////////////////////////////////////////
    }  

    window.Close();
    return 0;
}