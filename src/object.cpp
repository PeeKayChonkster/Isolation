#include "object.hpp"

chEn::Object::Object(std::string name, std::string modelPath) : name(name), model(modelPath) 
{
    transform = Transform();
}

void chEn::Object::draw()
{
    if(visible)
    {
        model.Draw(transform.getGlobalPosition());
        if(drawWires) model.DrawWires(transform.getGlobalPosition(), 1.0f, BLACK);
        for(Object* ch : transform.children)
        {
            ch->draw();
        }
    }
}

void chEn::Object::start() {}

void chEn::Object::update(float deltaTime) {}