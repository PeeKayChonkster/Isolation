#ifndef CHEN_TRANSFORM
#define CHEN_TRANSFORM

#include <vector>
#include <raylib-cpp.hpp>


namespace chEn
{
    class Transform
    {
    private:
        raylib::Transform transform;
    public:
        Transform* parent;
        std::vector<class Object*> children;

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
        void addChild(Object* child);
        void removeChild(Object* child);
    };
}

#endif // CHEN_TRANSFORM