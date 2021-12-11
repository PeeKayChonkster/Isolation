#ifndef CHEN_OBJECT
#define CHEN_OBJECT

#include <string>
#include "transform.hpp"

namespace chEn
{
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

    class Object: public Runnable, public Drawable
    {
    public:
        chEn::Transform transform;
        std::string name;
        raylib::Model model;

        Object() = default;
        Object(std::string name, std::string modelPath);

        virtual void draw() override;

        virtual void start() override;
        virtual void update(float deltaTime) override;

    };
}
#endif // CHEN_OBJECT