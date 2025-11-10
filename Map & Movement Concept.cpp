#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Player {
public:
    int xpos, ypos;
    void move(string direction, vector<vector<string>>& map) {
        // "moves" character based on input, doesn't move if it detects a wall, and can be changed to start asking questions when detecting a guard
        if (direction == "w") {
            if (map[xpos - 1][ypos] == "*") {
                cout << "There's a wall" << endl;
            } else if(map[xpos - 1][ypos] == "X") {
                cout<<"It's a guard!: (Placeholder question)"<<endl;
            } else {
                xpos--;
            }
        } else if (direction == "s") {
            if (map[xpos + 1][ypos] == "*") {
                cout << "There's a wall" << endl;
            }else if(map[xpos + 1][ypos] == "X") {
                cout<<"It's a guard!: (Placeholder question)"<<endl;
            } else {
                xpos++;
            }
        } else if (direction == "a") {
            if (map[xpos][ypos - 1] == "*") {
                cout << "There's a wall" << endl;
            } else if(map[xpos][ypos - 1] == "X") {
                cout<<"It's a guard!: (Placeholder question)"<<endl;
            } else {
                ypos--;
            }
        } else if (direction == "d") {
            if (map[xpos][ypos + 1] == "*") {
                cout << "There's a wall" << endl;
            } else if(map[xpos][ypos + 1] == "X") {
                cout<<"It's a guard: (Placeholder question)"<<endl;
            } else {
                ypos++;
            }
        } else {
            cout << "Invalid character entered" << endl;
        }
    }

    // Returns the current character position
    int getpos(char z) {
        if (z == 'x') {
            return xpos;
        } else if (z == 'y') {
            return ypos;
        } else {
            return -255;
        }
    }
};

class Map {
public:
    // Generates the map with borders
    vector<vector<string>> borderMap(int width, int height) {
        vector<vector<string>> map(height, vector<string>(width));
            srand(time(0));
        // Fill the border with '*' (walls) and all other spaces with '.'
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                    map[i][j] = "*";
                } else {
                    map[i][j] = ".";
                }
            }
        }
        //Generates a random position within walls
        int place = rand()%height-1;

        if (place == 0){
            place = 1;
        }
        
       //Places one guard on the far wall based on the random position
        map[place][width-1] = "X";

        return map;
    }

    // Prints out the map
    void displayMap(const vector<vector<string>>& map) {
        for (const auto& row : map) {
            for (const auto& cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Placeholder width and height
    int height = 10;
    int width = 10;

    // Stores the previous value that the character was in
    int holdx;
    int holdy;

    // Stores direction the user chooses to move
    string direction;

    // Initializes map and player
    Map testMap;
    Player test;
    
    test.xpos = 1;
    test.ypos = 1;

    // Creates the map
    vector<vector<string>> map = testMap.borderMap(width, height);
    map[1][1] = "@";  // Place the player at the starting position
    testMap.displayMap(map);

    // Main game loop
    while (true) {
        cin >> direction;
        holdx = test.getpos('x');
        holdy = test.getpos('y');

        // Move the player
        test.move(direction, map);

        // Update the map with the new position of the player
        map[holdx][holdy] = ".";  // Remove the player from the old position
        map[test.getpos('x')][test.getpos('y')] = "@";  // Place the player at the new position

        // Display the updated map
        testMap.displayMap(map);
    }

    return 0;
}
