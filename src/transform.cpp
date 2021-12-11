#include "transform.hpp"
#include <raymath.h>
#include <algorithm>
#include "object.hpp"

raylib::Vector3 chEn::Transform::getGlobalPosition() const
{
    return parent? parent->getGlobalPosition() + getLocalPosition() : getLocalPosition();
}

raylib::Quaternion chEn::Transform::getGlobalRotation() const
{
    return parent? parent->getGlobalRotation() * getLocalRotation() : getLocalRotation();
}

raylib::Vector3 chEn::Transform::getGlobalScale() const
{
    raylib::Vector3 localScale = getLocalScale();
    raylib::Vector3 globalScale = parent? parent->getGlobalScale() : raylib::Vector3::One();
    return raylib::Vector3{ localScale.x * globalScale.x, localScale.y * globalScale.y, localScale.z * globalScale.z };
}

raylib::Vector3 chEn::Transform::getLocalPosition() const
{
    return transform.translation;
}

raylib::Quaternion chEn::Transform::getLocalRotation() const
{
    return transform.rotation;
}

raylib::Vector3 chEn::Transform::getLocalScale() const
{
    return transform.scale;
}

void chEn::Transform::setLocalPosition(raylib::Vector3 position)
{
    transform.translation = position;
}

void chEn::Transform::setLocalRotation(raylib::Quaternion rotation)
{
    transform.rotation = rotation;
}

void chEn::Transform::setLocalScale(raylib::Vector3 scale)
{
    transform.scale = scale;
}

void chEn::Transform::setGlobalPosition(raylib::Vector3 position)
{
    transform.translation = position - getGlobalPosition();
}

void chEn::Transform::setGlobalRotation(raylib::Quaternion rotation)
{
    transform.rotation = rotation.Invert() * getGlobalRotation();
}

void chEn::Transform::setGlobalScale(raylib::Vector3 scale)
{
    raylib::Vector3 globalScale = getGlobalScale();
    transform.scale.x = scale.x / globalScale.x;
    transform.scale.y = scale.y / globalScale.y;
    transform.scale.z = scale.z / globalScale.z;
}


void chEn::Transform::move(raylib::Vector3 translate)
{
    transform.translation += translate; 
}

void chEn::Transform::rotate(raylib::Vector3 axis, float angle)
{
    axis = axis.Normalize();
    float sine = sin(angle / 2.0f);
    transform.rotation = getGlobalRotation() * raylib::Quaternion(axis.x * sine, axis.y * sine, axis.z * sine, cos(angle/2.0f));
}

void chEn::Transform::lookAt(raylib::Vector3 point)
{
    
    //  WASN'T TESTED!
    transform.rotation = raylib::Quaternion::Identity().Transform(raylib::Matrix().LookAt(getGlobalPosition(), point, raylib::Vector3::Up()));
}

raylib::Transform chEn::Transform::getRayTransform() const
{
    return transform;
}

void chEn::Transform::addChild(Object* child)
{
    if(std::find(children.begin(), children.end(), child) != children.end())
    {
        children.push_back(child);
    }
}

void chEn::Transform::removeChild(Object* child)
{
    auto childIter = std::find(children.begin(), children.end(), child);
    if(childIter != children.end())
    {
        children.erase(childIter);
    }
}
