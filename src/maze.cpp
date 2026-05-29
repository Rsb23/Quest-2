#include "Maze.h"
#pragma once
//tdo, fix maze movement, fix maze display
Maze::Maze(){
    maze = vector<vector<vector<bool>>>(10,vector<vector<bool>>(10,vector<bool>(7, false)));
    pathStack = vector<point>();
    selectionStack = vector<point>();
    currentTile = {0,0};
    playerTile = currentTile;

    GenerateMaze();

}

Maze::Maze(int x, int y){
    maze = vector<vector<vector<bool>>>(10,vector<vector<bool>>(10,vector<bool>(7, false)));
    pathStack = vector<point>();
    selectionStack = vector<point>();
    currentTile = {x,y};
    playerTile = currentTile;

    GenerateMaze();
}

Maze::Maze(size_t size){
    maze = vector<vector<vector<bool>>>(size,vector<vector<bool>>(size,vector<bool>(7, false)));
    pathStack = vector<point>();
    selectionStack = vector<point>();
    currentTile = {0,0};
    playerTile = currentTile;

    GenerateMaze();    
}

Maze::Maze(int x,int y, size_t size){
    maze = vector<vector<vector<bool>>>(size,vector<vector<bool>>(size,vector<bool>(7, false)));
    pathStack = vector<point>();
    selectionStack = vector<point>();
    currentTile = {x,y};
    playerTile = currentTile;

    GenerateMaze();    
}

bool Maze::IsInitialized(vector<bool> tile){
    return (tile[0] || tile[1] || tile[2] || tile[3]);
}

//Randomly places the finish in one of the corners that are not the starting tile
void Maze::GenerateFinish(){
    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution choice(0,2);

    switch(choice(gen)){
        //Top right corner
        case 0: maze[maze.size()-1][0][6] = true;
        //Bottom left corner
        case 1: maze[0][maze.size()-1][6] = true;
        //Bottom right corner
        case 2: maze[maze.size()-1][maze.size()-1][6] = true;
    }

}

//rolls a 1/3 chance to place a gate on each tile, tiles have either a gate, a warden, the finish, or nothing
void Maze::GenerateGates(){
    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution choice(0,2);

    for(int x = 0; x<maze.size()-1; x++){
        for(int y = 0; y<maze.size()-1; y++){
            if((choice(gen) == 2 && !(maze[x][y][5] || maze[x][y][6])) && (x || y)){
                maze[x][y][4] = true;
            }
        }
    }
}

//rolls a 1/10 chance to place a warden on each tile, tiles have either a gate, a warden, or the finish
void Maze::GenerateWardens(){
    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution choice(0,9);

    for(int x = 0; x<maze.size()-1; x++){
        for(int y = 0; y<maze.size()-1; y++){
            if((choice(gen) == 9 && !(maze[x][y][4] || maze[x][y][6])) && (x || y)){
                maze[x][y][5] = true;
            }
        }
    }
}

void Maze::GenerateMaze(){

    point previousTile;
    pathStack.push_back(currentTile);
    random_device rd;
    mt19937 gen(rd());


    while (!pathStack.empty()){
        if(!((currentTile.x)-1 < 0) && !(IsInitialized(maze[currentTile.x-1][currentTile.y]))){
            selectionStack.push_back({currentTile.x-1,currentTile.y});
        } 
        if(!((currentTile.x)+1 > (maze.size()-1)) && !(IsInitialized(maze[currentTile.x+1][currentTile.y]))){
            selectionStack.push_back({currentTile.x+1,currentTile.y});
        } 
        if(!((currentTile.y)-1 < 0) && !(IsInitialized(maze[currentTile.x][currentTile.y-1]))){
            selectionStack.push_back({currentTile.x,currentTile.y-1});
        } 
        if(!((currentTile.y)+1 > (maze.size()-1)) && !(IsInitialized(maze[currentTile.x][currentTile.y+1]))){
            selectionStack.push_back({currentTile.x,currentTile.y+1});
        } 
        

        if(!selectionStack.empty()){
        previousTile = currentTile;
        uniform_int_distribution choice(0,static_cast<int>(selectionStack.size()-1));
        currentTile = selectionStack[choice(gen)];
        pathStack.push_back(currentTile);

        if(currentTile.x - previousTile.x > 0){

            //Moved Right, give a Left path to current tile and Right path to previous
            maze[previousTile.x][previousTile.y][0] = true;
            maze[currentTile.x][currentTile.y][1] = true;

        } else if (currentTile.x - previousTile.x < 0){

            //Moved Left, give a Right path to current tile and Left path to previous
            maze[previousTile.x][previousTile.y][1] = true;
            maze[currentTile.x][currentTile.y][0] = true;

        } else if(currentTile.y - previousTile.y > 0){

            //Moved Down, give an Up path to current tile and Down path to previous
            maze[previousTile.x][previousTile.y][2] = true;
            maze[currentTile.x][currentTile.y][3] = true;

        } else if(currentTile.y - previousTile.y < 0){

            //Moved Up, give a Down path to current tile, and Up path to previous
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

    GenerateFinish();
    GenerateGates();
    GenerateWardens();
        

}

void Maze::DisplayTile(vector<bool> tile){

    vector<vector<string>> Display(11, vector<string>(11));

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            Display[i][j] = "█";
            if (tile[1] == 1 && ((i == 4 || i == 5 || i == 6) && (j <= 6)))
            {

                Display[i][j] = ".";
            }
            if (tile[3] == 1 && ((j == 4 || j == 5 || j == 6) && (i >= 4)))
            {

                Display[i][j] = ".";
            }
            if (tile[0] == 1 && ((i == 4 || i == 5 || i == 6) && (j >= 4)))
            {

                Display[i][j] = ".";
            }
            if (tile[2] == 1 && ((j == 4 || j == 5 || j == 6) && (i <= 6)))
            {
                Display[i][j] = ".";
            }
            if (tile[4])
            {
                for (int i = 4; i <= 6; i++)
                {
                    for (int j = 4; j <= 6; j++)
                    {
                        Display[i][j] = "#";
                    }
                }
            }
            else if (tile[5])
            {
                Display[5][5] = "骨";
            }
            else
            {
                Display[5][5] = "@";
            }
            cout << Display[i][j] << " ";
        }

        cout << endl;
    }
}

void Maze::DisplayPlayerTile(){
        vector<vector<string>> Display(11, vector<string>(11));

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            Display[i][j] = "█";
            if (maze[playerTile.x][playerTile.y][1] && ((i == 4 || i == 5 || i == 6) && (j <= 6)))
            {

                Display[i][j] = ".";
            }
            if (maze[playerTile.x][playerTile.y][2] && ((j == 4 || j == 5 || j == 6) && (i >= 4)))
            {

                Display[i][j] = ".";
            }
            if (maze[playerTile.x][playerTile.y][0] && ((i == 4 || i == 5 || i == 6) && (j >= 4)))
            {

                Display[i][j] = ".";
            }
            if (maze[playerTile.x][playerTile.y][3] && ((j == 4 || j == 5 || j == 6) && (i <= 6)))
            {
                Display[i][j] = ".";
            }
            if (maze[playerTile.x][playerTile.y][4])
            {
                for (int i = 4; i <= 6; i++)
                {
                    for (int j = 4; j <= 6; j++)
                    {
                        Display[i][j] = "#";
                    }
                }
            }
            else if (maze[playerTile.x][playerTile.y][5])
            {
                Display[5][5] = "骨";
            }
            else
            {
                Display[5][5] = "@";
            }
            cout << Display[i][j] << " ";
        }

        cout << endl;
    }
}

void Maze::Move(char dir){
    pathStack.clear();
    pathStack.push_back(playerTile);
    if(dir == 'd'){
        if(maze[playerTile.x][playerTile.y][0]){
            playerTile.x++;
        } else {
            cout<<"Can't go right, there's a wall!"<<endl;
            return;
        }
    } else if (dir == 'a'){
        if(maze[playerTile.x][playerTile.y][1]){
            playerTile.x--;
        } else {
            cout<<"Can't go left, there's a wall!"<<endl;
            return;
        }
    } else if (dir == 's'){
        if(maze[playerTile.x][playerTile.y][2]){
            playerTile.y++;
        } else {
            cout<<"Can't go down, there's a wall!";
            return;
    }
    } else if (dir == 'w'){
        if(maze[playerTile.x][playerTile.y][3]){
            playerTile.y--;
        } else {
            cout<<"Can't go up, there's a wall!"<<endl;
            return;
    }
    } else {
        throw runtime_error("Invalid Character Entered");
    }
}

void Maze::MoveBack(){
    playerTile = pathStack[0];
}

vector<bool> Maze::GetPlayerTileStatus(){
    return maze[playerTile.x][playerTile.y];
}

void Maze::ClearGate(){
    maze[playerTile.x][playerTile.y][4] = false;
}

void Maze::ClearWarden(){
    maze[playerTile.x][playerTile.y][5] = false;
}