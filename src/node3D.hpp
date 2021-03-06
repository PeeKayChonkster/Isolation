#ifndef CHEN_NODE_HPP
#define CHEN_NODE_HPP

#include <string>
#include <variant>
#include <array>
#include "transform3D.hpp"

namespace chen
{
    #define MAX_NODES 1000
    #define START_OVERRIDE startChildren();
    #define UPDATE_OVERRIDE updateChildren(deltaTime);
    #define DRAW_OVERRIDE if(!visible) return; drawChildren();

    class Drawable
    {
    public:
        bool visible = true;
        bool drawWires = false;
        virtual void draw() = 0;
    };


    class Runnable
    {
    public:
        virtual void start() = 0;
        virtual void update(float deltaTime) = 0;
    };


    class Node3D
    {
    private:
        uint16_t id;
        static bool nodeCache[MAX_NODES];
        
        int getNewId();

    protected:
        void startChildren();
        void updateChildren(float deltaTime);
        void drawChildren();

    public:
        chen::Transform3D transform;
        std::string name;
        bool visible = true;

        Node3D();
        Node3D(std::string name = "_noname_");
        ~Node3D();

        uint16_t getId() const;

        virtual void start();
        virtual void update(float deltaTime);
        virtual void draw();
    };
}

#endif // CHEN_NODE_HPP