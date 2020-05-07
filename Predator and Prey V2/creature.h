#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

class Creature{
public:
    int type,life=20,posX,posY;
    RectangleShape shape;
    
    Creature(int type,int posX,int posY);
    void update(int i, int j,bool op);
    void cria();
    void come();
};