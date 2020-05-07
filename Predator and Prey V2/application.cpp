#include "application.h"

using namespace sf;

Application::Application() : window(VideoMode(1000,1000),"SFML") {
    window.setFramerateLimit(60);
}


