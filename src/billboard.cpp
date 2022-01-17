#include "billboard.hpp"
#include "debug.hpp"
#include "resman_static.hpp"

chen::Billboard::Billboard(std::string filePath, raylib::Camera3D* currentCamera, std::string name): Node(name), texture(filePath), currentCamera(currentCamera), shader("", "./res/shaders/billboard.fs") {} 

chen::Billboard::~Billboard()
{
    texture.Unload();
}

void chen::Billboard::draw()
{
    DRAW_OVERRIDE
    
    chen::Debug::printLine("drawing " + name);
    BeginShaderMode(shader);
    DrawBillboard(*currentCamera, texture, transform.getGlobalPosition(), size, tint);
    EndShaderMode();
}