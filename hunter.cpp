#include "hunter.h"

using namespace sf;

Hunter::Hunter() {
    shape.setSize(Vector2f(10.f,10.f));
    shape.setFillColor(Color::Red);
    shape.setPosition(200,400);
}