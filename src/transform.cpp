#include "transform.hpp"
#include <raymath.h>
#include <algorithm>
#include "node.hpp"

raylib::Vector3 chen::Transform::getGlobalPosition() const
{
    return parent? parent->getGlobalPosition() + getLocalPosition() : getLocalPosition();
}

raylib::Quaternion chen::Transform::getGlobalRotation() const
{
    return parent? parent->getGlobalRotation() * getLocalRotation() : getLocalRotation();
}

raylib::Vector3 chen::Transform::getGlobalScale() const
{
    raylib::Vector3 localScale = getLocalScale();
    raylib::Vector3 globalScale = parent? parent->getGlobalScale() : raylib::Vector3::One();
    return raylib::Vector3{ localScale.x * globalScale.x, localScale.y * globalScale.y, localScale.z * globalScale.z };
}

raylib::Vector3 chen::Transform::getLocalPosition() const
{
    return transform.translation;
}

raylib::Quaternion chen::Transform::getLocalRotation() const
{
    return transform.rotation;
}

raylib::Vector3 chen::Transform::getLocalScale() const
{
    return transform.scale;
}

void chen::Transform::setLocalPosition(raylib::Vector3 position)
{
    transform.translation = position;
}

void chen::Transform::setLocalRotation(raylib::Quaternion rotation)
{
    transform.rotation = rotation;
}

void chen::Transform::setLocalScale(raylib::Vector3 scale)
{
    transform.scale = scale;
}

void chen::Transform::setGlobalPosition(raylib::Vector3 position)
{
    transform.translation = position - getGlobalPosition();
}

void chen::Transform::setGlobalRotation(raylib::Quaternion rotation)
{
    transform.rotation = rotation.Invert() * getGlobalRotation();
}

void chen::Transform::setGlobalScale(raylib::Vector3 scale)
{
    raylib::Vector3 globalScale = getGlobalScale();
    transform.scale.x = scale.x / globalScale.x;
    transform.scale.y = scale.y / globalScale.y;
    transform.scale.z = scale.z / globalScale.z;
}


void chen::Transform::move(raylib::Vector3 translate)
{
    transform.translation += translate; 
}

void chen::Transform::rotate(raylib::Vector3 axis, float angle)
{
    axis = axis.Normalize();
    float sine = sin(angle / 2.0f);
    transform.rotation = getGlobalRotation() * raylib::Quaternion(axis.x * sine, axis.y * sine, axis.z * sine, cos(angle/2.0f));
}

void chen::Transform::lookAt(raylib::Vector3 point)
{
    
    //  WASN'T TESTED!
    transform.rotation = raylib::Quaternion::Identity().Transform(raylib::Matrix().LookAt(getGlobalPosition(), point, raylib::Vector3::Up()));
}

raylib::Transform chen::Transform::getRayTransform() const
{
    return transform;
}

void chen::Transform::addChild(Node* child)
{
    if(std::find(children.begin(), children.end(), child) != children.end())
    {
        children.push_back(child);
    }
}

void chen::Transform::removeChild(Node* child)
{
    auto childIter = std::find(children.begin(), children.end(), child);
    if(childIter != children.end())
    {
        children.erase(childIter);
    }
}
