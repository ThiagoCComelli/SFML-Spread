#include "prey.h"

using namespace sf;

Prey::Prey() {
    shape.setSize(Vector2f(10.f,10.f));
    shape.setFillColor(Color::Green);
    shape.setPosition(200,200);
}