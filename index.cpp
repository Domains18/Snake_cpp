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
void SnakeGame::DisplayGameOver() {
	cout << " ===========================================================================\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||           ____    _    __  __ _____ _____     _______ ____            ||\n";
	cout << " ||          / ___|  / \\  |  \\/  | ____/ _ \\ \\   / / ____|  _ \\           ||\n";
	cout << " ||         | |  _  / _ \\ | |\\/| |  _|| | | \\ \\ / /|  _| | |_) |          ||\n";
	cout << " ||         | |_| |/ ___ \\| |  | | |__| |_| |\\ V / | |___|  _ <           ||\n";
	cout << " ||          \\____/_/   \\_\\_|  |_|_____\\___/  \\_/  |_____|_| \\_\\          ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                  PRESS ANY KEY TO RETURN TO MENU                      ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ===========================================================================\n";
}
void SnakeGame::DisplayInstructions() {
	cout << " ===========================================================================\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                           *Instructions*                              ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                           ____                        ||\n";
	cout << " ||                  ________________________/ O  \\___/                   ||\n";
	cout << " ||                 <_____________________________/   \\                   ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||             1. W,A,S,D to change direction of the Snake.              ||\n";
	cout << " ||             2. Eat the Fruit to Make the Snake Grow. With             ||\n";
	cout << " ||                each fruit 10 Points will be Added to the              ||\n";
	cout << " ||                score.                                                 ||\n";
	cout << " ||             3. If Snake eats itself, game will be over.               ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                  PRESS ANY KEY TO RETURN TO MENU                      ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ===========================================================================\n";
}
void SnakeGame::DisplayCredits() {
	cout << " ===========================================================================\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                               *Credits*                               ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                           Game Developed by                           ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                  )             (      (      (      (                 ||\n";
	cout << " ||               ( /(     (       )\\ )   )\\ )   )\\ )   )\\ )              ||\n";
	cout << " ||               )\\())    )\\     (()/(  (()/(  (()/(  (()/(              ||\n";
	cout << " ||              ((_)\\  ((((_)(    /(_))  /(_))  /(_))  /(_))             ||\n";
	cout << " ||               _((_)  )\\ _ )\\  (_))   (_))   (_))   (_))               ||\n";
	cout << " ||              | || |  (_)_\\(_) | _ \\  | _ \\  |_ _|  / __|              ||\n";
	cout << " ||              | __ |   / _ \\   |   /  |   /   | |   \\__ \\              ||\n";
	cout << " ||              |_||_|  /_/ \\_\\  |_|_\\  |_|_\\  |___|  |___/              ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ||                    PRESS ANY KEY TO RETURN TO MENU                    ||\n";
	cout << " ||                                                                       ||\n";
	cout << " ===========================================================================\n";
}

void SnakeGame::ControllerInput(){
    if(_kbhit()){
        switch(_getch()){
            case 'a':
                SnakeDirection = LEFT;
                break;
            case 'b':
                SnakeDirection = RIGHT;
                break;
            case 'c':
                SnakeDirection = UP;
                break;
            case 'd':
                SnakeDirection = DOWN;
                break;
            case 'w':
                SnakeDirection = LEFT;
                break;
            case 's':
                SnakeDirection = RIGHT;
                break;
            case 'f':
                SnakeDirection = DOWN;
                break;
            case 't':
                SnakeDirection = UP;
                break;
        }
    }
}
void SnakeGame::SetupGame(){
    GameOver = false;
    SnakeDirection= STOP;
    SnakeHeadX = Width/2;
    SnakeHeadY = Height/2;
    FruitX = rand() % Width;
    FruitY = rand() % Height;
}