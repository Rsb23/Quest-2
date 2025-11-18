#include "player.h"
#include "store.h"

void PlayerMove(char &move, int &PlayX, int &PlayY, std::vector<bool> CurrentExits, std::vector<std::vector<std::vector<bool>>> &Map,int &PrevX, int &PrevY, Store store){
    PrevY = PlayY;
    PrevX = PlayX;
    //Shows all moves to the player
    std::cout<<"W: Move Up\n" << "A: Move Left\n" << "S: Move Down\n" << "D: Move Right\n"<<"B: Open Shop\n";

    std::cin>>move;


    //checks all possible move values, makes sure that there isn't a wall there, also makes sure that the exit is reciprocated
    //all exits should be because of FixWalls()
    if(move == 'a'){
        if(!Map[PlayX][PlayY][0] || !Map[PlayX][PlayY-1][2]){
            std::cout<<"There's a wall blocking your path"<<std::endl;
        } else {
       PlayY --;
        }
    } else if (move == 's'){
        if(!Map[PlayX][PlayY][1] || !Map[PlayX+1][PlayY][3]){
            std::cout<<"There's a wall blocking your path"<<std::endl;
        } else {
       PlayX ++;
        }
    } else if (move == 'd'){
        if(!Map[PlayX][PlayY][2] || !Map[PlayX][PlayY+1][0]){
            std::cout<<"There's a wall blocking your path"<<std::endl;
        } else {
       PlayY ++;
        }
    } else if (move == 'w'){
        if(!Map[PlayX][PlayY][3] || !Map[PlayX-1][PlayY][1]){
            std::cout<<"There's a wall blocking your path"<<std::endl;
        } else {
       PlayX --;
        }
    } else if(move == 'b'){
        store.StoreMenu();
    } else {
        std::cout<<"Please Enter A Valid Direction";
    }
}