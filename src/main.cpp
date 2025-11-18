#include "player.h"
#include "map.h"
#include "store.h"

int main()
{
    // Placeholder width and height
    int height{10};
    int width{10};

    // Stores the previous value that the character was in
    int holdx;
    int holdy;

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

    test.setXPos(1);
    test.setYPos(1);

    // Creates the map
    std::vector<std::vector<std::string>> map = testMap.generateMap(width, height);
    map[1][1] = "@"; // Place the player at the starting position taking into account wall thickness
    testMap.displayMap(map);

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
    }
    return 0;
}