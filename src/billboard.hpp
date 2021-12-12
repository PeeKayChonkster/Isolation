#ifndef CHEN_BILLBOARD_HPP
#define CHEN_BILLBOARD_HPP

#include "node.hpp"

namespace chen
{
    class Billboard : public Node
    {
    private:
        raylib::Texture2D texture;
        raylib::Camera3D* currentCamera;
    public:
        Billboard() = delete;
        Billboard(std::string filePath, raylib::Camera3D* currentCamera, std::string name = "_noname_");
        ~Billboard();

        float size = 1.0f;
        raylib::Color tint = WHITE;

        virtual void draw() override;
    };
}


#endif // CHEN_BILLBOARD_HPP