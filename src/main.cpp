#include "Maze Generation.cpp"
#include "player.h"
#include "store.h"
#include "map.h"

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

    // Gets player class/type
    int classSelection{0};

    while (true)
    {
        std::cout << "Please Choose Player Class)\n";
        std::cout << "Bulwark The Guardian\n"
                  << "\"When the storm hits, Bulwark stands unbroken\"\n"
                  << "Energy Shield - prevents loss of points when Gate OR Warden is incorrect\n"
                  << "\n"
                  << "Aegis The Ravager\n"
                  << "\"Breaker of oaths, bearer of darkness\"\n"
                  << "Vengeance Protocol - starts with 3 Cue Cards OR 1 Supreme Cue Card\n"
                  << "\n"
                  << "Ronan The Trickster\n"
                  << "\"Illusion is the truth you can't handle\"\n"
                  << "Shadow Shift - skip over 3 gates OR 1 Warden without unlocking them\n";

        std::cout << "Enter Class (1,2,3, or 4 to exit): ";
        std::cin >> classSelection;

        if (classSelection)
        {
            if (classSelection == 1)
            {
                Player test();
                break;
            }
            else if (classSelection == 2)
            {
                Player test();
                break;
            }
            else if (classSelection == 3)
            {
                Player test();
                break;
            }
            else
            {
                std::cout << "Invalid Selection!\n";
                continue;
            }
        }
        else
        {
            std::cout << "Please make a selection\n!";
            continue;
        }
    }

    // Initialize map
    Map testMap;
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

    // Main game loop
    while (true)
    {
        char input{'e'};

        // read player input (either direction, entering store, or exiting program)
        std::cout << "Enter A Direction (w a s d), Enter The Store (b), or Exit (e): ";
        std::cin >> input;

        if (input == 'b')
        {
            Store _store;
            _store.storeMenu();
        }
        else if (input == 'e')
        {
            std::cout << "Goodbye!\n";
            break;
        }
        else if (input == 'w' || input == 'a' || input == 's' || input == 'd')
        {
            holdx = test.getXPos();
            holdy = test.getYPos();

            // Move the player
            test.move(input, map);

            // Update the map with the new position of the player
            map[holdx][holdy] = ".";                   // Remove the player from the old position
            map[test.getXPos()][test.getYPos()] = "@"; // Place the player at the new position

            // Display the updated map
            testMap.displayMap(map);
        }
        else
        {
            std::cout << "Please enter a valid option\n!";
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