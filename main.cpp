#include <windows.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "coordinates.h"
#include "path.h"
#include "rocket.h"
using namespace std;

void setCursor(Coordinates _coordinates);
void setupRockets(vector<Path*> _paths, int _startLine);
void setupPaths(int _startLine, int _finishLine, vector<Path*> _paths);
void showIntro(Coordinates _messagePos);
Coordinates generateMovement(Coordinates _pos);
void eraseRocket(Coordinates _pos);
void displayRocket(Coordinates _pos);
void displayTrail(Coordinates _pos);
void clearMessageBar(Coordinates _messagePos);

int main() {
    bool gameOver = false;
    const int startLine = 30;
    const int finishLine = 2;
    Coordinates messagePos(0, 0);
    Coordinates endCoordinates(0, startLine + 2);
    Rocket rocket1;
    Rocket rocket2;
    Rocket rocket3;
    Rocket rocket4;
    Rocket rocket5;
    Rocket rocket6;
    Path path1(1, 10, 20, rocket1, "Path 1");
    Path path2(21, 30, 40, rocket2, "Path 2");
    Path path3(41, 50, 60, rocket3, "Path 3");
    Path path4(61, 70, 80, rocket4, "Path 4");
    Path path5(81, 90, 100, rocket5, "Path 5");
    Path path6(101, 110, 120, rocket6, "Path 6");
    vector<Path*> paths = {&path1, &path2, &path3, &path4, &path5, &path6};

    // Necessary for randomized game outcomes
    srand(time(0));

    // Initial setup
    setupRockets(paths, startLine);
    setupPaths(startLine, finishLine, paths);
    showIntro(messagePos);

    // Main game loop
    while (!gameOver) {
        for (Path* path : paths) {
            Rocket& currRocket = *path->getRocket();
            // Stores coordinates
            Coordinates oldPos = currRocket.getCoordinates();
            // Generates and stores movement info
            Coordinates newPos = generateMovement(oldPos);
            // Ensures rocket is not displayed beyond finish line
            if (newPos.row <= finishLine) {
                newPos.row = 2;
            }
            eraseRocket(oldPos);
            displayRocket(newPos);
            // Ensures trail is displayed within start and finish line
            // also prevents trail from overwriting side of rocket (_finishLine + 1)
            if (newPos.row >= finishLine + 1 and newPos.row < startLine) {
                displayTrail(newPos);
            }
            // Overwrites old coordinates once used
            currRocket.setCoordinates(newPos);
            // Win condition
            if (newPos.row <= finishLine) {
                // Ensures finish line isn't overwritten by rocket
                setCursor(newPos);
                cout << "-^";
                // Displays win message
                clearMessageBar(messagePos);
                setCursor(messagePos);
                cout << "Winner: " << path->getName() << "!";
                gameOver = true;
                break;
            }
            // Collision condition
            if (newPos.col <= path->getLBnd() + 2 || newPos.col >= path->getRBnd() - 2) {
                // Show collision
                setCursor(newPos);
                cout << " X";
                // Displays collision message
                clearMessageBar(messagePos);
                setCursor(messagePos);
                cout << "Collision in " << path->getName() << "!";
                gameOver = true;
                break;
            }
            // Sets speed of rocket movement
            Sleep(100);
        }
    }
    // Prints file information below game
    setCursor(endCoordinates);
    return 0;
}

// Windows API Call, requires windows.h
// https://learn.microsoft.com/en-us/windows/console/setconsolecursorcoordinates
void setCursor(Coordinates _coordinates) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { _coordinates.col, _coordinates.row };
    SetConsoleCursorPosition(hConsole, coord);
}

void setupRockets(vector<Path*> _paths, int _startLine) {
    // Draws the rockets in their initial coordinatess
    for (Path* path : _paths) {
        Coordinates startCoordinates(path->getCntr(), _startLine); // Pos(col, row)
        setCursor(startCoordinates);
        path->getRocket()->setCoordinates(startCoordinates);
        displayRocket(startCoordinates);
    }
}

void setupPaths(int _startLine, int _finishLine, vector<Path*> _paths) {
    // Draws the paths/boundaries
    for (int currRow = _startLine + 2; currRow >= _finishLine; --currRow) {
        for (int i = 0; i < _paths.size(); ++i) {
            Path* path = _paths[i];
            Coordinates pos(path->getLBnd(), currRow);
            setCursor(pos);
            cout << "|";
            // For final right-side border
            if (i == _paths.size() - 1) {
                int rightCol = path->getRBnd();
                pos.col = rightCol;
                setCursor(pos);
                cout << "|";
            }
            // For finish line
            if (currRow == _finishLine) {
                for (int j = 0; j < 122; ++j) {
                    pos.col = j;
                    setCursor(pos);
                    cout << "-";
                }
            }
        }
    }
}

void showIntro(Coordinates _messagePos) {
    setCursor(_messagePos);
    for (int i = 3; i >= 1; --i) {
        cout << i << "... ";
        Sleep(1000);
    }
    cout << "Launch!";
}

Coordinates generateMovement(Coordinates _pos) {
    // Generates upward movement
    int jump = rand() % 4 + 1;
    _pos.row -= jump;
    // Random chance for side movement
    int leftRight = rand() % 5;
    if (leftRight == 0) {
        _pos.col += 2;
    }
    if (leftRight == 1) {
        _pos.col -= 2;
    }
    return _pos;
}

void eraseRocket(Coordinates _pos) {
    for (int i = 0; i < 3; ++i) {
        setCursor(_pos);
        cout << "   \n";
        _pos.row += 1;
    }
}

void displayRocket(Coordinates _pos) {
    // Displays new rocket
    setCursor(_pos);
    cout << " ^\n";
    _pos.row += 1;
    setCursor(_pos);
    cout << "/|\\\n";
    _pos.row += 1;
    setCursor(_pos);
    cout << "/ \\\n";
}

void displayTrail(Coordinates _pos) {
    // Sets trail below rocket
    _pos.row += 3;
    setCursor(_pos);
    cout << ".";
}


void clearMessageBar(Coordinates _messagePos) {
    setCursor(_messagePos);
    cout << "                           ";
}