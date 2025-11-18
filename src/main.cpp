
#include "Maze Generation.cpp"
#include "player.cpp"
#include "store.cpp"
#include<vector>
#include<iostream>
using namespace std;

int main()
{
    srand(time(0));
    Store store;
    char move;
    char engage;
    bool win = 0;
    int y = 0; // Current column index (0-9)
    int x = 0; // Current row index (0-9)
    int PrevX;
    int PrevY;
    int PlayX = x;
    int PlayY = y;
    vector<bool> CurrentExits;
    vector<bool> EligibleExits;
    // Add a stack for backtracking: stores {x, y} pairs
    vector<vector<int>> pathStack;

    // A counter to track how many tiles have been initialized (for GenerateMissingPaths)
    int completed_tiles_count = 0; 
    
    // 10 x 10 x 4 3d vector for the map
    vector<vector<vector<bool>>> Map(10, vector<vector<bool>>(10,vector<bool>(7,0)));

    Map[x][y] = InitialTile(); 
    pathStack.push_back({x, y}); // Push starting tile onto the stack
    completed_tiles_count++; // Start tile is the first completed tile

    // Loop continues until 10 tiles are completed by the DFS algorithm
    GenerateMaze(CurrentExits, Map, EligibleExits, x, y, pathStack);
    
    // Call the GenerateMissingPaths function to fill in any uninitialized areas
    for(int i = 0; i < 100; i++){
    GenerateMissingPaths(Map, completed_tiles_count); 
    //Places walls at locations where exits don't line up
    FixWalls(Map);
    }

    //Make the win exist
    GenerateFinish(Map);
    //Displays the inital tile before the game loop starts
    DisplayTile(Map[PlayX][PlayY]);

    GenerateGates(Map);
    GenerateWarden(Map);
    

    //Main game loop
    while(win == 0){
    //Tracks current tiles exits
    CurrentExits = Map[PlayX][PlayY];

    //Calls the Player Move function to let the player navigate
    PlayerMove(move,PlayX,PlayY,CurrentExits,Map, PrevX, PrevY, store);

    //Displays the tile that the player is on
    DisplayTile(Map[PlayX][PlayY]);

    if(Map[PlayX][PlayY][4]){
        cout<<"There's A Gate\n";
        cout<<"Answers the question? (y/n)\n";
        cin>>engage;

        if(engage == 'y'){
            //whatever happens when you engage a gate
        } else {
            PlayX = PrevX;
            PlayY = PrevY;
            DisplayTile(Map[PlayX][PlayY]);
        }


        //Run this is the answer is correct to erase gate from the map
        /*if(answer){
            Map[PlayX][PlayY][4] = 0;
        } else{
            //Whatever happens when you fail a gate 
        }*/
    }

    if(Map[PlayX][PlayY][5]){
        cout<<"There's A Warden\n";
        cout<<"Answers the question? (y/n)\n";
        cin>>engage;

        if(engage == 'y'){
            //whatever happens when you engage a gate
        } else {
            PlayX = PrevX;
            PlayY = PrevY;
            DisplayTile(Map[PlayX][PlayY]);
        }


        //Run this is the answer is correct to erase Warden from the map
        /*if(answer){
            Map[PlayX][PlayY][5] = 0;
        } else{
            //Whatever happens when you fail a Warden
        }*/
    }

    //checks for the win flag
    if(Map[PlayX][PlayY][6]){
        win=1;
        break;
    }
    }

    cout<<"You win";
    return 0;
}