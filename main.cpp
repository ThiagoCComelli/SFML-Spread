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
    srand(time(0));
    int b = (rand() % 3)-1;
    // Creature creature;
    
    for(int i = 0;i<LINHAS;i++){
        for(int j = 0;j<COLUNAS;j++){
            tempGrid.push_back(Creature(0,i,j));
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
                    grid[int(event.mouseButton.x/2)][int(event.mouseButton.y/2)] = Creature(0,int(event.mouseButton.x/10),int(event.mouseButton.y/10));
                } else if (event.key.code == Mouse::Right){
                    grid[int(event.mouseButton.x/2)][int(event.mouseButton.y/2)] = Creature(1,int(event.mouseButton.x/10),int(event.mouseButton.y/10));
                }
            } 
        }
        program.window.clear();

        for(int i = 0;i<LINHAS;i++){
            for(int j = 0;j<COLUNAS;j++){
                if(grid[i][j].type == 2){
                    program.window.draw(grid[i][j].shape);
                }
            }
        }

        for(int i = 0;i<LINHAS;i++){
            for(int j = 0;j<COLUNAS;j++){
                if(grid[i][j].type == 0 && i > 1 && i < 498 && j > 1 && j < 498){
                    program.window.draw(grid[i][j].shape);
                    int a = (rand() % 3)-1,b = (rand() % 3)-1;
                    if(grid[i][j].life >= 100){
                        // if(grid[i-a][j-b].type != 0){
                            grid[i-a][j-b] = Creature(0,i-a,j-b);
                            grid[i][j].life = 50;
                        // }
                    } else {
                        grid[i][j].life+=5;
                    }                    
                }
            }
        }

        for(int i = 0;i<LINHAS;i++){
            for(int j = 0;j<COLUNAS;j++){
                if(grid[i][j].type == 1 && i > 1 && i < 498 && j > 1 && j < 498){
                    program.window.draw(grid[i][j].shape);
                    int a = (rand() % 3)-1,b = (rand() % 3)-1;
                    if(grid[i][j].life <= 0){
                        grid[i][j] = Creature(2,i,j);
                    } else {
                        if(grid[i-a][j-b].type == 0){
                            grid[i-a][j-b] = Creature(1,i-a,j-b);
                        } else {
                            grid[i-a][j-b] = grid[i][j];
                            grid[i][j] = Creature(2,i,j);
                        }
                    }  
                    grid[i][j].life-=5;                  
                }
            }
        }


        
        program.window.display();
    }

    return 0;
}