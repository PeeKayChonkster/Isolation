#include "node3D.hpp"
#include <exception>
#include <algorithm>
#include "debug.hpp"

//// static members /////
bool chen::Node3D::nodeCache[MAX_NODES] = { false };


int chen::Node3D::getNewId()
{
    for(uint8_t i = 0u; i < MAX_NODES; ++i)
    {
        if(!nodeCache[i]) 
        {
            chen::Debug::printPersistentLine("Gave out id=" + std::to_string(i) + " to node \"" + this->name + "\"");
            nodeCache[i] = true;
            return i;
        }
    }
    return -1;
}
/////////////////////////


chen::Node3D::Node3D() : Node3D("_noname_") {}

chen::Node3D::Node3D(std::string name) : name(name)
{
    if(int newId = getNewId() < 0) throw "No more vacant node id's left";
    else id = static_cast<uint16_t>(newId);
    transform = Transform3D();
    transform.node = this;
}

chen::Node3D::~Node3D()
{
    nodeCache[id] = false;
}

// void chen::Node::draw()
// {
//     if(visible)
//     {
//         // apply rotation to model
//         model.index()
//         model.SetTransform(transform.getGlobalRotation().ToMatrix());
//         // apply translation to model
//         model.Draw(transform.getGlobalPosition());
//         if(drawWires) model.DrawWires(transform.getGlobalPosition(), 1.0f, BLACK);
//         for(Node* ch : transform.children)
//         {
//             ch->draw();
//         }
//     }
// }

void chen::Node3D::startChildren()
{
    for(uint i = 0u; i < transform.children.size(); ++i)
    {
        transform.children[i]->node->start();
    }
}

void chen::Node3D::updateChildren(float deltaTime)
{
    for(uint i = 0u; i < transform.children.size(); ++i)
    {
        transform.children[i]->node->update(deltaTime);
    }
}

void chen::Node3D::drawChildren()
{
    for(uint i = 0u; i < transform.children.size(); ++i)
    {
        transform.children[i]->node->draw();
    }
}

uint16_t chen::Node3D::getId() const
{
    return id;
}

void chen::Node3D::start()
{
    // First, call children's start methods, then execute own start method
    START_OVERRIDE

    ///// start() code for this node starts from here /////
    ///////////////////////////////////////////////////////
}

void chen::Node3D::update(float deltaTime)
{
    // First, call children's update methods, then execute own update method
    UPDATE_OVERRIDE

    ///// update() code for this node starts from here /////
    ////////////////////////////////////////////////////////
}

void chen::Node3D::draw()
{
    // First, call children's draw methods, then execute own draw method
    DRAW_OVERRIDE

    ///// draw() code for this node starts from here /////
    //////////////////////////////////////////////////////
}
