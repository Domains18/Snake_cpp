#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>

using namespace std;

class SnakeGame
{
private:
    enum Direction
    {
        STOP = 0,
        LEFT,
        RIGHT,
        UP, 
        DOWN
    };
    Direction SnakeDirection;
    int SnakeBodyCount;
    bool GameOver;
    bool BodyPrintFlag;
    const int Width;
    const int Height;
    int SnakeHeadX, SnakeHeadY, FruitX, FruitY;
    int SnakeX[100], SnakeY[100];
    static void DisplayMainMenu();
    static void DisplayGameOver();
    static void DisplayInstructions();
    static void DisplayCredits();
    void ControllerInput();
    void SetupGame();
    void PrintStage();
    void PlayGame();

public:
    SnakeGame();
    void StartGame();

};

SnakeGame::SnakeGame() : Width(52), Height(22){
    SnakeBodyCount = 0;
    GameOver = false ;
    BodyPrintFlag = false;
    SnakeHeadX = 0;
    SnakeHeadY = 0;
    FruitX = 0;
    FruitY = 0;
    for (int i = 0; i< 100; i++)
    {
        SnakeX[i] = 0;
        SnakeY[i] = 0;
    }
}

void SnakeGame::DisplayMainMenu(){
    cout << " ===========================================================================\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                           *SNAKE GAME*                                ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                      __    __    __    __                             ||\n";
	cout << " ||                     /  \\  /  \\  /  \\  /  \\                            ||\n";
	cout << " ||____________________/  __\\/  __\\/  __\\/  __\\___________________________||\n";
	cout << " ||___________________/  /__/  /__/  /__/  /______________________________||\n";
	cout << " ||                   | / \\   / \\   / \\   / \\  \\____                      ||\n";
	cout << " ||                   |/   \\_/   \\_/   \\_/   \\    o \\                     ||\n";
	cout << " ||                                           \\_____/--<                  ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                              *Menu*                                   ||\n";
	cout << " ||									  ||\n";
	cout << " ||                         -> 1. Play Game                               ||\n";
	cout << " ||                         -> 2. Instructions                            ||\n";
	cout << " ||                         -> 3. Credits                                 ||\n";
	cout << " ||                         -> 4. Exit                                    ||\n";
	cout << " ||				                                          ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ===========================================================================\n";
}
}