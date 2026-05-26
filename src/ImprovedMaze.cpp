#include "ImprovedMaze.h"







Maze::Maze(){
    maze = vector<vector<vector<bool>>>(10,vector<vector<bool>>(10,vector<bool>(7, false)));
    pathStack = vector<point>();
    selectionStack = vector<point>();
    currentTile = {0,0};

}

bool Maze::QueryInitialization(vector<bool> tile){
    return (tile[0] && tile[1] && tile[2] && tile[3]);
}

void Maze::GenerateMaze(){
int movementDir;
point previousTile;
pathStack.push_back({0,0});
random_device rd;
mt19937 gen(rd());


while (!pathStack.empty()){

    if(!(currentTile.x-1 < 0) && !(QueryInitialization(maze[currentTile.x-1][currentTile.y]))){
        selectionStack.push_back({currentTile.x-1,currentTile.y});
    } 
    if(!(currentTile.x+1 > (maze.size()-1)) && !(QueryInitialization(maze[currentTile.x+1][currentTile.y]))){
        selectionStack.push_back({currentTile.x+1,currentTile.y});
    } 
    if(!(currentTile.y-1 < 0) && !(QueryInitialization(maze[currentTile.x][currentTile.y-1]))){
        selectionStack.push_back({currentTile.x,currentTile.y-1});
    } 
    if(!(currentTile.y+1 > (maze.size()-1)) && !(QueryInitialization(maze[currentTile.x][currentTile.y+1]))){
        selectionStack.push_back({currentTile.x,currentTile.y+1});
    } 
    

    if(!selectionStack.empty()){
    previousTile = currentTile;
    uniform_int_distribution choice(0,static_cast<int>(selectionStack.size()-1));
    currentTile = selectionStack[choice(gen)];
    pathStack.push_back(currentTile);

    if(currentTile.x - previousTile.x > 0){

        //Moved Right, give a Left path to previous tile
        maze[previousTile.x][previousTile.y][0] = true;
        maze[currentTile.x][currentTile.y][1] = true;

    } else if (currentTile.x - previousTile.x < 0){

        //Moved Left, give a Right path to previous tile
        maze[previousTile.x][previousTile.y][1] = true;
        maze[currentTile.x][currentTile.y][0] = true;

    } else if(currentTile.y - previousTile.y > 0){

        //Moved Down, give an Up path to previous tile
        maze[previousTile.x][previousTile.y][2] = true;
        maze[currentTile.x][currentTile.y][3] = true;

    } else if(currentTile.y - previousTile.y < 0){

        //Moved Up, give a Down path to previous tile
        maze[previousTile.x][previousTile.y][3] = true;
        maze[currentTile.x][currentTile.y][2] = true;

    }


    } else {
    pathStack.pop_back();
    if(!pathStack.empty()){
    currentTile = pathStack[pathStack.size()-1];
    }
    }

    selectionStack.clear();
}
}