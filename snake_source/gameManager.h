#ifndef GAMEMANAGER
#define GAMEMANAGER
#define numOfSnakes 4
#define HARD_MODE 4
#define TIMERSET 80
#include "snake.h"
#include "badSnake.h"
#include "fruit.h"
#include "settings.h"
#include "terminal.h"
#include <cstring>
#include <string> 
//TODO function for selecting color scheme in own class. 
//TODO This is allow for GameManager to oppoerate without passing myGame settings. 
	//function for selecting game mode for both types of gd/ames.
	using namespace std; 
class GameManager
{
	private:
		int height;
		int fruitCount; 
		int width; 	       
		bool badSnakeX;
		bool badSnakeY;
		bool pause; 
		int gameMultiplier; 
		int score = 0;
		int delay; 
		int baseScore = 10; 
		string snake_Head = "O";
		string snake_tail = "o";
		string space = " ";
		string fruitChar = "@";
		BadSnake* badSnake; 
		Fruit* fruit;
		//Setup basic game variables 
		bool SpaceCheck(int y, int x, Terminal &terminal, char checkChar);
		bool Compare(int y, int x, int direction, Terminal &terminal, Snake sanke);
		void ChangeDirection(Snake &snake, int input, Settings &myGame, int delay);
		void FruitMatch(Fruit &fruit, Settings &myGame, Terminal &terminal,  bool snakePower);
		int SnakeAttack(int count, int &attackNumMove, BadSnake *badSnake, Settings &myGame, Terminal &terminal);
		void GameSetup(Terminal &terminal, Settings &myGame, Snake &snake, BadSnake *badSnake, Fruit *fruit); 
		void PrintFruit(Fruit *fruit, Terminal &terminal);
		void BadAttack(Settings &myGame, BadSnake &badSnake, bool &badSnakeX, bool &badSnakeY); //TODO CAN'T GET THE RANDOM NUMBERS TO WORK CORRECTLY> 
	public: 
		GameManager(int _height, int _width, int _gameMultiplier, string _snakeHead, int _fruitCount, int _delay);
		~GameManager();
		int PlayGame(Settings &myGame);

};
#endif
