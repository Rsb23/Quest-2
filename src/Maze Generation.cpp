/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


class Tile{
    private:
        //used to determine if the tile is the Maze Exit
        bool isEnd = 0;
        //Keeps track of exits the tile has, 0 being a wall, 1 being an exit. in order: Left, Bottom, Right, Top
        //Y axis is mirrored because vector is displayed top to bottom, so  left = x - 1, right = x + 1, up = y - 1, down = y + 1
        vector<bool> exits = {0,0,0,0};
        
        //Tracks if the tile has a Warden (weaker one)
        bool HasWarden = 0;
        //Tracks if the tile has a Sentinel (stronger one)
        bool HasSentinel = 0;
        
    public:
    void InitialTile(){
        exits = {0,1,1,0};
    }
    
    vector<bool> GetExits(){
        return exits;
    }
    
    vector<bool> CreateTile(){
        for (int i = 0; i < 4 ; i++){
            exits[i] = rand()%2;
        }
        return exits;
    }
};

void DisplayTile(vector<bool> exits) {

    vector<vector<string>> Display(11, vector<string>(11)); 

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 11; j++) {
            Display[i][j] = "*";
            if(exits[0] == 1 && ((i==4||i==5||i==6)&&(j<=6))){
                
                Display[i][j] = ".";
                
            } if(exits[1] == 1 && ((j==4||j==5||j==6)&&(i>=4))){
                
                Display[i][j] = ".";
                
            } if(exits[2] == 1 && ((i==4||i==5||i==6)&&(j>=4))){
                
                Display[i][j] = ".";
                
            } if(exits[3] == 1 && ((j==4||j==5||j==6)&&(i<=6))){
                Display[i][j] = ".";
            }
            cout << Display[i][j] << " "; 
        }

        cout << endl; 
    }
}


int main()
{
    srand(time(0));
    //10 x 10 x 4 3d vector to store exit values of individual tiles
    vector<vector<vector<bool>>> Map(10, vector<vector<bool>>(10,vector<bool>(4,0)));
    
    Tile StartTile;
    StartTile.InitialTile();

    vector<bool> exits = {0,0,0,0};


    DisplayTile(StartTile.GetExits());
    return 0;
}