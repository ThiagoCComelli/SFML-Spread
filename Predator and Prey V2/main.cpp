#include <vector>
#include <iostream>
#include "application.cpp"
#include "creature.cpp"

#define LINHAS 500
#define COLUNAS 500
#define TAMANHO 2

using namespace sf;
using namespace std;

int main()
{
    Application program;
    vector<vector<Creature>>grid;
    vector<Creature>tempGrid;
    int predator = 0;
    int prey = 0;
    srand(time(0));
    Font font;
    Text textPredator;
    Text textPrey;
    font.loadFromFile("VCR.ttf");

    textPredator.setPosition(10,40);
    textPrey.setPosition(10,10);



    // int b = (rand() % 3)-1;
    
    for(int i = 0;i<LINHAS;i++){
        for(int j = 0;j<COLUNAS;j++){
            tempGrid.push_back(Creature(2,i,j));
        }
        grid.push_back(tempGrid);
        tempGrid.clear();
    }

    while (program.window.isOpen())
    {
        Event event;
        while (program.window.pollEvent(event))
        {
            if (event.type == Event::Closed){
                program.window.close();
            } if (event.type == Event::MouseButtonPressed){
                if(event.key.code == Mouse::Left){
                    grid[int(event.mouseButton.x/2)][int(event.mouseButton.y/2)] = Creature(0,int(event.mouseButton.x/2),int(event.mouseButton.y/2));
                } else if (event.key.code == Mouse::Right){
                    grid[int(event.mouseButton.x/2)][int(event.mouseButton.y/2)] = Creature(1,int(event.mouseButton.x/2),int(event.mouseButton.y/2));
                }
            } 
        }
        program.window.clear();

        prey = 0;
        predator = 0;
        for(int i = 0;i<LINHAS;i++){
            for(int j = 0;j<COLUNAS;j++){
                    program.window.draw(grid[i][j].shape);
                    if(grid[i][j].type == 0){
                        prey++;
                    } else if (grid[i][j].type == 1){
                        predator++;
                    }
            }
        }
        for(int i = 0;i<LINHAS;i++){
            for(int j = 0;j<COLUNAS;j++){
                if(grid[i][j].type==0 && i > 1 && i < 498 && j > 1 && j < 498){
                    grid[i][j].come();
                    
                    int a = (rand() % 3)-1;
                    int b = (rand() % 3)-1;


                    if(grid[i][j].life >= 100){
                        int c = (rand() % 3)-1;
                        int d = (rand() % 3)-1;
                        if(grid[i+c][j+d].type == 2){
                            grid[i+c][j+d] = Creature(0,i+c,j+d);
                            grid[i][j].cria();
                        }
                    }
                    if(grid[i+a][j+b].type == 2){
                        grid[i][j].update(i+a,j+b,false);
                        grid[i+a][j+b] = grid[i][j];
                        grid[i][j] = Creature(2,i,j);
                    }
                }
            }
        }
        for(int i = 0;i<LINHAS;i++){
            for(int j = 0;j<COLUNAS;j++){
                if(grid[i][j].type==1 && i > 1 && i < 498 && j > 1 && j < 498){
                    grid[i][j].life-=10;
                    if(grid[i][j].life <= 0){
                        grid[i][j] = Creature(2,i,j);
                    }
                    int a = (rand() % 3)-1;
                    int b = (rand() % 3)-1;
                    if(grid[i+a][j+b].type == 0){
                        grid[i+a][j+b] = Creature(1,i+a,j+b);
                    }
                    int c = (rand() % 3)-1;
                    int d = (rand() % 3)-1;
                    if(grid[i+c][j+d].type == 2){
                        grid[i][j].update(i+a,j+b,false);
                        grid[i+c][j+d] = grid[i][j];
                        grid[i][j] = Creature(2,i,j);
                    }
                }
            }
        }

        textPredator.setFont(font);
        textPrey.setFont(font);
        textPredator.setString("Predator: "+to_string(predator));
        textPrey.setString("Prey: "+to_string(prey));
        program.window.draw(textPredator);
        program.window.draw(textPrey);
        
        program.window.display();
    }

    return 0;
}