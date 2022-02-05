#ifndef CHEN_Transform3D_HPP
#define CHEN_Transform3D_HPP

#include <vector>
#include <raylib-cpp.hpp>


namespace chen
{
    class Transform3D
    {
    private:
        raylib::Transform3D transform;
    public:
        class Node3D* node;
        Transform3D* parent;
        std::vector<Transform3D*> children;

        raylib::Vector3 getGlobalPosition() const;
        raylib::Quaternion getGlobalRotation() const;
        raylib::Vector3 getGlobalScale() const;

        raylib::Vector3 getLocalPosition() const;
        raylib::Quaternion getLocalRotation() const;
        raylib::Vector3 getLocalScale() const;

        void setLocalPosition(raylib::Vector3 position);
        void setLocalRotation(raylib::Quaternion rotation);
        void setLocalScale(raylib::Vector3 scale);

        void setGlobalPosition(raylib::Vector3 position);
        void setGlobalRotation(raylib::Quaternion rotation);
        void setGlobalScale(raylib::Vector3 scale);

        void move(raylib::Vector3 translation);
        void rotate(raylib::Vector3 axis, float angle);
        void lookAt(raylib::Vector3 point);

        raylib::Transform3D getRayTransform3D() const;

        // this function is dangerous, child Transform3D pointer could be non-constant (if it's inside of std::vector for example)
        void addChild(Node3D* child);
        void removeChild(Node3D* child);
    };
}

#endif // CHEN_Transform3D_HPP