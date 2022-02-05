#include "transform3D.hpp"
#include <raymath.h>
#include <algorithm>
#include "node3D.hpp"

raylib::Vector3 chen::Transform3D::getGlobalPosition() const
{
    return parent? parent->getGlobalPosition() + getLocalPosition() : getLocalPosition();
}

raylib::Quaternion chen::Transform3D::getGlobalRotation() const
{
    return parent? parent->getGlobalRotation() * getLocalRotation() : getLocalRotation();
}

raylib::Vector3 chen::Transform3D::getGlobalScale() const
{
    raylib::Vector3 localScale = getLocalScale();
    raylib::Vector3 globalScale = parent? parent->getGlobalScale() : raylib::Vector3::One();
    return raylib::Vector3{ localScale.x * globalScale.x, localScale.y * globalScale.y, localScale.z * globalScale.z };
}

raylib::Vector3 chen::Transform3D::getLocalPosition() const
{
    return transform.translation;
}

raylib::Quaternion chen::Transform3D::getLocalRotation() const
{
    return transform.rotation;
}

raylib::Vector3 chen::Transform3D::getLocalScale() const
{
    return transform.scale;
}

void chen::Transform3D::setLocalPosition(raylib::Vector3 position)
{
    transform.translation = position;
}

void chen::Transform3D::setLocalRotation(raylib::Quaternion rotation)
{
    transform.rotation = rotation;
}

void chen::Transform3D::setLocalScale(raylib::Vector3 scale)
{
    transform.scale = scale;
}

void chen::Transform3D::setGlobalPosition(raylib::Vector3 position)
{
    transform.translation = position - getGlobalPosition();
}

void chen::Transform3D::setGlobalRotation(raylib::Quaternion rotation)
{
    transform.rotation = rotation.Invert() * getGlobalRotation();
}

void chen::Transform3D::setGlobalScale(raylib::Vector3 scale)
{
    raylib::Vector3 globalScale = getGlobalScale();
    transform.scale.x = scale.x / globalScale.x;
    transform.scale.y = scale.y / globalScale.y;
    transform.scale.z = scale.z / globalScale.z;
}


void chen::Transform3D::move(raylib::Vector3 translate)
{
    transform.translation += translate; 
}

void chen::Transform3D::rotate(raylib::Vector3 axis, float angle)
{
    axis = axis.Normalize();
    float sine = sin(angle / 2.0f);
    transform.rotation = getGlobalRotation() * raylib::Quaternion(axis.x * sine, axis.y * sine, axis.z * sine, cos(angle/2.0f));
}

void chen::Transform3D::lookAt(raylib::Vector3 point)
{
    //  WASN'T TESTED!
    transform.rotation = raylib::Quaternion::Identity().Transform(raylib::Matrix().LookAt(getGlobalPosition(), point, raylib::Vector3::Up()));
}

raylib::Transform3D chen::Transform3D::getRayTransform3D() const
{
    return transform;
}

void chen::Transform3D::addChild(Node3D* child)
{
    auto predicate = [&](Transform3D* ch) { return ch->node->getId() == child->getId(); };
    if(std::find_if(children.begin(), children.end(), predicate) == children.end())
    {
        children.push_back(&child->transform);
        child->transform.parent = this;
    }
}

void chen::Transform3D::removeChild(Node3D* child)
{
    auto predicate = [&](Transform3D* ch) { return ch->node->getId() == child->getId(); };
    auto childIter = std::find_if(children.begin(), children.end(), predicate);
    if(childIter != children.end())
    {
        children.erase(childIter);
        child->transform.parent = nullptr;
    }
}
