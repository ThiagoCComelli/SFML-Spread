#include "creature.h"

using namespace sf;

Creature::Creature(int type_=2,int posX_=0,int posY_=0) {
    this->type = type_;
    this->posX = posX_;
    this->posY = posY_;
    shape.setSize(Vector2f(2.f,2.f));
    if(type_ == 1){
        shape.setFillColor(Color::Red);
        shape.setPosition(posX_*2,posY_*2);
        this->life = 100;
    } else if (type_ == 0){
        shape.setFillColor(Color::Green);
        shape.setPosition(posX_*2,posY_*2);
        this->life = 50;
    } else {
        shape.setFillColor(Color::Black);
        shape.setPosition(posX_*2,posY_*2);
    }
}
void Creature::update(int i, int j,bool op=true){
    if(this->type == 1){
        shape.setFillColor(Color::Red);
        shape.setPosition(i*2,j*2);
    } else if (this->type == 0){
        shape.setFillColor(Color::Green);
        shape.setPosition(i*2,j*2);
        if (op){
            this->life = 20;
        }
    } else {
        shape.setFillColor(Color::Black);
        shape.setPosition(i*2,j*2);
    }
}
void Creature::cria(){
    this->life = 20;
}
void Creature::come(){
    this->life += 10;
}