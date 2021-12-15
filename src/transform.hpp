#ifndef CHEN_TRANSFORM
#define CHEN_TRANSFORM

#include <vector>
#include <raylib-cpp.hpp>


namespace chen
{
    class Transform
    {
    private:
        raylib::Transform transform;
    public:
        class Node* node;
        Transform* parent;
        std::vector<Transform*> children;

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

        raylib::Transform getRayTransform() const;

        // this function is dangerous, child transform pointer could be non-constant (if it's inside of std::vector for example)
        void addChild(Node* child);
        void removeChild(Node* child);
    };
}

#endif // CHEN_TRANSFORM