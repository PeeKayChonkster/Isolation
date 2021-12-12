#include "billboard.hpp"

chen::Billboard::Billboard(std::string filePath, raylib::Camera3D* currentCamera, std::string name): Node(name), texture(filePath), currentCamera(currentCamera) {}

chen::Billboard::~Billboard()
{
    texture.Unload();
}

void chen::Billboard::draw()
{
    DRAW_OVERRIDE

    DrawBillboard(*currentCamera, texture, transform.getGlobalPosition(), size, tint);
}