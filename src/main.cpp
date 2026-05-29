#include "maze.cpp"
#include "player.cpp"
#include "guardian.cpp"
#include "ravager.cpp"
#include "trickster.cpp"
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
    Player * _player;
    
    //Create the maze
    Maze maze;
    // Create Store class
    Store _store;
    
    // player class selection loop
    int classSel{0};
    while (!win)
    {

        while (true)
        {
            std::cout << "Please Choose Player Class\n";
            std::cout << "Bulwark The Guardian\n"
                      << "\"When the storm hits, Bulwark stands unbroken\"\n"
                      << "Energy Shield - prevents loss of points when Gate OR Warden is incorrect\n"
                      << "\n"
                      << "Aegis The Ravager\n"
                      << "\"Breaker of oaths, bearer of darkness\"\n"
                      << "Vengeance Protocol - starts with 3 Cue Cards OR 1 Supreme Cue Card\n"
                      << "\n";
            /*
            << "Ronan The Trickster\n"
            << "\"Illusion is the truth you can't handle\"\n"
            << "Shadow Shift - skip over 3 gates OR 1 Warden without unlocking them\n";
            */

            std::cout << "Enter Class (1, 2 or 3 to exit): ";
            std::cin >> classSel;

            if (classSel)
            {
                if (classSel == 1)
                {
                    _player = new Guardian();
                    break;
                }
                else if (classSel == 2)
                {
                    _player = new Ravager();
                    break;
                }
                /*
                else if (classSel == 3)
                {
                    Trickster _player;
                    break;
                }
                */
                else if (classSel == 3)
                {
                    std::cout << "Goodbye!\n";
                    return 0;
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

        // displays start tile
        maze.DisplayPlayerTile();

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
                _store.storeMenu(*_player);
                maze.DisplayPlayerTile();
            }
            else if (input == 'e')
            {
                std::cout << "Goodbye!\n";
                return 0;
            }
            else if (input == 'w' || input == 'a' || input == 's' || input == 'd')
            {
                maze.Move(input);
                maze.DisplayPlayerTile();

                if (maze.GetPlayerTileStatus()[4])
                {
                    std::cout << "There's A Gate!\n";
                    std::cout << "Challenge? (y/n)\n";
                    std::cin >> engage;

                    if (engage == 'y')
                    {
                        _player->encounterGate(maze);
                        maze.DisplayPlayerTile();
                    }
                    else
                    {
                        maze.MoveBack();
                        maze.DisplayPlayerTile();
                    }
                }

                if (maze.GetPlayerTileStatus()[5])
                {
                    std::cout << "There's A Warden\n";
                    std::cout << "Answers the question? (y/n)\n";
                    std::cin >> engage;

                    if (engage == 'y')
                    {
                        _player->encounterWarden(maze);
                        maze.DisplayPlayerTile();
                    }
                    else
                    {
                        maze.MoveBack();
                        maze.DisplayPlayerTile();
                    };
                }
            }
            else
            {
                std::cout << "Please enter a valid option\n!";
            }
            // checks for the win flag
            if (maze.GetPlayerTileStatus()[6])
            {
                win = true;
                break;
            }
        }
    }

    std::cout << "You win!";
    return 0;
}