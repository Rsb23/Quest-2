#include "maze.cpp"
#include "player.cpp"
#include "store.cpp"
#include "gate.cpp"
#include "warden.cpp"

int main()
{
    srand(time(0));
    Store store;
    char move;
    char engage;
    bool win = false;
    int y = 0; // Current column index (0-9)
    int x = 0; // Current row index (0-9)
    int PrevX;
    int PrevY;
    int PlayX = x;
    int PlayY = y;
    std::vector<bool> CurrentExits;
    std::vector<bool> EligibleExits;
    // Add a stack for backtracking: stores {x, y} pairs
    std::vector<std::vector<int>> pathStack;

    // A counter to track how many tiles have been initialized (for GenerateMissingPaths)
    int completed_tiles_count = 0;

    // 10 x 10 x 7 3d vector for the map
    std::vector<std::vector<std::vector<bool>>> Map(10, std::vector<std::vector<bool>>(10, std::vector<bool>(7, 0)));




        do{
            //empty maze
            for(int i = 0;i<10;i++){
                for(int j = 0;j<10;j++){
                    for(int k = 0; k < 7;k++){
                        Map[i][j][k] = 0;
                    }
                }
            }

        Map[x][y] = InitialTile();
        pathStack.push_back({x, y}); // Push starting tile onto the stack
        completed_tiles_count++;     // Start tile is the first completed tile

        GenerateMaze(CurrentExits, Map, EligibleExits, x, y, pathStack);

            // Call the GenerateMissingPaths function to fill in any uninitialized areas
        for (int i = 0; i < 100; i++)
        {
            GenerateMissingPaths(Map, completed_tiles_count);
            // Places walls at locations where exits don't line up
            FixWalls(Map);
        }
        // Make the win exist
        GenerateFinish(Map);

    }while(!isCompletable(Map));


    // Displays the inital tile before the game loop starts
    DisplayTile(Map[PlayX][PlayY]);

    // Generate enemy locations
    GenerateGates(Map);
    GenerateWarden(Map);

        // Create player class (override above, player class types not yet implemented)
        Player _player;

        // Create Store class
        Store _store;

    // Main game loop
    while (!win)
    {
        // Tracks current tiles exits
        CurrentExits = Map[PlayX][PlayY];

        // PLAYER CLASS TYPE NOT YET IMPLEMENTED
        // Gets player class/type
        // int classSelection{0};

        /*
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
        }*/

        //Main game loop
        while (true)
        {
            char input{'e'};

            // read player input (either direction, entering store, or exiting program)
            std::cout << "Enter A Direction (w a s d), Enter The Store (b), or Exit (e): ";
            std::cin >> input;

            if (input == 'b')
            {
                Store _store;
                _store.storeMenu(_player);
                DisplayTile(Map[PlayX][PlayY]);
            }
            else if (input == 'e')
            {
                std::cout << "Goodbye!\n";
                return 0;
            }
            else if (input == 'w' || input == 'a' || input == 's' || input == 'd')
            {
                PlayerMove(input, PlayX, PlayY, CurrentExits, Map, PrevX, PrevY);
                DisplayTile(Map[PlayX][PlayY]);

                if (Map[PlayX][PlayY][4])
                {
                    std::cout << "There's A Gate!\n";
                    std::cout << "Challenge? (y/n)\n";
                    std::cin >> engage;

                    if (engage == 'y')
                    {
                        _player.encounterGate(Map, PlayX, PlayY);
                        DisplayTile(Map[PlayX][PlayY]);
                    }
                    else
                    {
                        PlayX = PrevX;
                        PlayY = PrevY;
                    }
                }

                if (Map[PlayX][PlayY][5])
                {
                    std::cout << "There's A Warden\n";
                    std::cout << "Answers the question? (y/n)\n";
                    std::cin >> engage;

                    if (engage == 'y')
                    {
                        _player.encounterWarden(Map, PlayX, PlayY);
                        DisplayTile(Map[PlayX][PlayY]);
                    }
                    else
                    {
                        PlayX = PrevX;
                        PlayY = PrevY;
                    };
                }
            }
            else
            {
                std::cout << "Please enter a valid option\n!";
            }
        // checks for the win flag
        if (Map[PlayX][PlayY][6])
        {
            win = true;
            break;
        }
        }
    }

    std::cout << "You win!";
    return 0;
}