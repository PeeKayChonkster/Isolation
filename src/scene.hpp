#include "object.hpp"
#include <vector>

namespace chEn
{
    class Scene: public Drawable, public Runnable
    {
    private:
        std::vector<Object> objects;
    public:
        void addObject(Object obj);
        void addObject(Object&& obj);
        void emplaceObject()
    };
}