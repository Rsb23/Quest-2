#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "Maze Generation.h"
using namespace std;


//Sets the exits for the starting tile
vector<bool> InitialTile(){
    vector<bool> exits;
    exits = {0,1,1,0,0,0,0};
    return exits;
}

//randomly generates exits when called
vector<bool> CreateTile(){
    vector<bool> exits = {0,0,0,0,0,0,0};
    for (int i = 0; i < 4 ; i++){
        exits[i] = rand()%2;
    }
    return exits;
}

//checks to see if the tile is unitialized, which only occurs if a tile has no exits
bool IsTileUninitialized(const vector<bool> &tile_exits) {
    for (bool exit_status : tile_exits) {
        if (exit_status) {
            return false;
        }
    }
    return true;
}

//prints the tile to the terminal
void DisplayTile(vector<bool> exits) {

    vector<vector<string>> Display(11, vector<string>(11)); 

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            Display[i][j] = "█";
            if(exits[0] == 1 && ((i==4||i==5||i==6)&&(j<=6))){
                
                Display[i][j] = ".";
                
            } if(exits[1] == 1 && ((j==4||j==5||j==6)&&(i>=4))){
                
                Display[i][j] = ".";
                
            } if(exits[2] == 1 && ((i==4||i==5||i==6)&&(j>=4))){
                
                Display[i][j] = ".";
                
            } if(exits[3] == 1 && ((j==4||j==5||j==6)&&(i<=6))){
                Display[i][j] = ".";
            }
            if(exits[4]){
                for(int i=4; i<=6; i++){
                    for(int j=4; j<=6; j++){
                Display[i][j] = "#";
                }
            }
            } else if (exits[5]){
                Display[5][5] = "骨";
            } else {
            Display[5][5] = "@";
            }
            cout << Display[i][j] << " "; 

        }

        cout << endl; 
    }
}

//selects and generates the next eligible tile
void SelectTile(vector<bool> EligibleExits, vector<bool> CurrentExits, vector<vector<vector<bool>>> &Map, int &x, int &y, int &ForcedExit){
    int SelectedExit;

   if (!EligibleExits.empty()) {
        SelectedExit = EligibleExits[rand() % EligibleExits.size()];
    
        if(SelectedExit == 0){ // Left: y-- (horizontal)
            ForcedExit = 2;
            y--; 
        } else if (SelectedExit == 1){ // Bottom: x++ (vertical)
            ForcedExit = 3;
            x++; 
        } else if (SelectedExit == 2){ // Right: y++ (horizontal)
            ForcedExit = 0;
            y++; 
        } else if (SelectedExit == 3){ // Top: x-- (vertical)
            ForcedExit = 1;
            x--; 
        }

        vector<bool> RawExits = CreateTile();
        RawExits[ForcedExit] = 1;


        // Check Left exit (y-1)
        if(RawExits[0] && (y - 1 < 0)){
            RawExits[0] = 0;
        }
        // Check Bottom exit (x+1)
        if(RawExits[1] && (x + 1 > 9)){
            RawExits[1] = 0;
        }
        // Check Right exit (y+1)
        if(RawExits[2] && (y + 1 > 9)){
            RawExits[2] = 0;
        }
        // Check Top exit (x-1)
        if(RawExits[3] && (x - 1 < 0)){
            RawExits[3] = 0;
        }

        Map[x][y] = RawExits; 

    } 
}


void GenerateMaze(vector<bool> &CurrentExits, vector<vector<vector<bool>>> &Map, vector<bool> &EligibleExits,int &x, int &y, vector<vector<int>> &pathStack){
    int ForcedExit = 3;

    for(int q = 0; q<10; q++){ 
        
        CurrentExits = Map[x][y];
        EligibleExits.clear(); 
        
        for(int i = 0; i < 4; i++){
            
            bool isValidMove = false;
            // Check if the current tile has an exit and it's not the forced return
            if (CurrentExits[i] && (i != ForcedExit)) {
                
                int next_x = x;
                int next_y = y;
                
                // Determine the coordinates of the target tile
                if (i == 0){ 
                next_y--; 
                } // Left: y-- 
                else if (i == 1){ 
                next_x++; 
                } // Bottom: x++
                else if (i == 2){ 
                next_y++; 
                } // Right: y++
                else if (i == 3){ 
                next_x--; 
                } // Top: x--

                // 1. Boundary Check: Ensure the target is within 0-9
                if (next_x >= 0 && next_x < 10 && next_y >= 0 && next_y < 10) {
                    
                // Check if Map[next_x][next_y] is the unitialized, and needs to generated
                    
                    if (IsTileUninitialized(Map[next_x][next_y])) {
                        isValidMove = true;
                    }
                }
            }

            if (isValidMove) {
                EligibleExits.push_back(i);
            }
        }
        
        //Logic for backtracking
        if (EligibleExits.empty()) 
        {   
            // Pop the current dead-end tile
            pathStack.pop_back(); 
            
            if (pathStack.empty()) {
                //if this segment runs, that means all possible paths are filled and generation couldn't finish
                //unlikely but possible
                break; // Exit generation
            }
            
            // Move to the previous tile (new x, y)
            x = pathStack.back()[0];
            y = pathStack.back()[1];
            
            // Re-read CurrentExits from the new tile for the next iteration
            // The ForcedExit will be automatically recalculated in the next iteration.
            continue; 
        }

        //Moves the generator to the new tile
        SelectTile(EligibleExits, CurrentExits, Map, x, y, ForcedExit);
        pathStack.push_back({x, y}); // Push the new tile onto the stack
    }
}

// Function to generate paths from initialized tiles to uninitialized neighbors
void GenerateMissingPaths(vector<vector<vector<bool>>> &Map, int &completed) {

    // Loop through every tile in the 10x10 map
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            
            // Check if the current tile is initialized (not all exits are 0)
            if (IsTileUninitialized(Map[i][j])) {
                continue; // Skip uninitialized tiles
            }

            // Iterate through the four possible exits of the current tile
            for (int k = 0; k < 4; k++) {
                
                // If there is an exit in this direction
                if (Map[i][j][k]) {
                    
                    int next_x = i;
                    int next_y = j;
                    int ForcedExit; // ForcedExit for the new tile

                    // Get the coordinates of the neighbor tile
                    //also sets the forced exit to be the inverse of the selected exit
                    if (k == 0) { // Left: y--
                        next_y--;
                        ForcedExit = 2;
                    } else if (k == 1) { // Bottom: x++
                        next_x++;
                        ForcedExit = 3;
                    } else if (k == 2) { // Right: y++
                        next_y++;
                        ForcedExit = 0;
                    } else if (k == 3) { // Top: x--
                        next_x--;
                        ForcedExit = 1;
                    }

                    // Makes sure it doesn't run into a boundary
                    if (next_x >= 0 && next_x < 10 && next_y >= 0 && next_y < 10) {
                        
                        //See if the neighbor tile is uninitialized
                        if (IsTileUninitialized(Map[next_x][next_y])) {
                            
                            // Initialize the unitialized tile
                            vector<bool> RawExits = CreateTile();
                            // Forces the ForcedExit exit into the current tile
                            RawExits[ForcedExit] = 1; 

                            // Check the new tiles exits to ensure it doesn't try to exit the map
                            //in order left, bottom, right, top
                            
                            if(RawExits[0] && (next_y - 1 < 0)){
                                RawExits[0] = 0;
                            }
                            
                            if(RawExits[1] && (next_x + 1 > 9)){
                                RawExits[1] = 0;
                            }
                            
                            if(RawExits[2] && (next_y + 1 > 9)){
                                RawExits[2] = 0;
                            }
                            
                            if(RawExits[3] && (next_x - 1 < 0)){
                                RawExits[3] = 0;
                            }

                            // Update the map with the new tile
                            Map[next_x][next_y] = RawExits;
                        }
                    }
                }
            }
        }
    }
}

//Turns exits that don't line up with other exits into walls in order to make things consistent
//Looks at every tile on the map
void FixWalls(vector<vector<vector<bool>>> &Map){
    for(int i = 0; i<10 ; i++){
        for(int j = 0; j<10;j++){

            //checks to see if each exit that the tile has is matched by the opposite exit (i.e left to right) in the tile which that exit would lead to
            //if it doesn't, it turns it into a wall
            if(Map[i][j][0] && j > 0){
                if(!Map[i][j-1][2]){
                Map[i][j][0] = 0;
            }
            }
            if(Map[i][j][1] && i<9){
                if(!Map[i+1][j][3]){
                Map[i][j][1] = 0;
                }
            }
            if(Map[i][j][2] && j<9){
                if(!Map[i][j+1][0]){
                Map[i][j][2] = 0;
                }
            }
            if(Map[i][j][3] && j>0){
                if(!Map[i-1][j][1]){
                Map[i][j][3] = 0;
                }
            }
        }
    }
}

//Generates a finish by selecting the first eligible tile, starts from the furthest index values and moves inward
//to try and get the exit far away from the start
void GenerateFinish(vector<vector<vector<bool>>> &Map){
    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            //gives the win flag to the first initialized tile it finds
            if(!IsTileUninitialized(Map[i][j])){
                //sets the win flag
                Map[i][j][6] = 1;
                return;
            }
        }
    }
}

void GenerateGates(vector<vector<vector<bool>>> &Map){
    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            //Makes sure the tiles are initialized before placing a gate there
            if(!IsTileUninitialized(Map[i][j])){
                //1/5 chance of a gate being placed
                if(!Map[i][j][6]){
                    if(rand()%5 == 0){
                        Map[i][j][4] = 1;
                    } else {
                        Map[i][j][4] = 0;
                    }
                } else {
                    Map[i][j][4] = 0;
                }
            }
        }
    }
}

void GenerateWarden(vector<vector<vector<bool>>> &Map){
    for(int i=9;i>=0;i--){
        for(int j=9;j>=0;j--){
            //gives the win flag to the first initialized tile it finds
            if(!IsTileUninitialized(Map[i][j])){
                // 1/20 chance of a Warden being placed
                if(!Map[i][j][6] && !Map[i][j][4]){
                if(rand()%20 == 0){
                    Map[i][j][5] = 1;
                } else {
                    Map[i][j][5] = 0;
                    }
                } else {
                Map[i][j][5] = 0;
                }
            }
        }
    }
}
