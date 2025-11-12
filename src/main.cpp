#include "player.h"
#include "map.h"

int main()
{
    // Placeholder width and height
    int height{10};
    int width{10};

    // Stores the previous value that the character was in
    int holdx;
    int holdy;

    // Stores direction the user chooses to move
    std::string direction;

    // Initializes map and player
    Map testMap;
    Player test;

    test.setXPos(1);
    test.setYPos(1);

    // Creates the map
    std::vector<std::vector<std::string>> map = testMap.generateMap(width, height);
    map[1][1] = "@"; // Place the player at the starting position taking into account wall thickness
    testMap.displayMap(map);

    // Main game loop
    while (true)
    {
        std::cin >> direction;
        holdx = test.getXPos();
        holdy = test.getYPos();

        // Move the player
        test.move(direction, map);

        // Update the map with the new position of the player
        map[holdx][holdy] = ".";                   // Remove the player from the old position
        map[test.getXPos()][test.getYPos()] = "@"; // Place the player at the new position

        // Display the updated map
        testMap.displayMap(map);
    }
    return 0;
}