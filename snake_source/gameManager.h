#ifndef GAMEMANAGER
#define GAMEMANAGER
#define numOfSnakes 4
#define HARD_MODE 4
#define TIMERSET 80
#include "snake.h"
#include "badSnake.h"
#include "fruit.h"
#include "settings.h"
#include "gameMap.h"
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
		bool SpaceCheck(int y, int x, GameMap &terminal, char checkChar); //Simple check. Mostly used for turning badsnake off and on. 
		bool Compare(int y, int x, int direction, GameMap &terminal, Snake sanke); //Checks if there is a collision of good snake 
		void ChangeDirection(Snake &snake, int input, Settings &myGame, int delay); //Local function to check for change of direction conditions. 
		void FruitMatch(Fruit *fruit, Settings &myGame, GameMap &terminal,  bool snakePower); //Handles if there ia fruit match and the needed logic. 
		int SnakeAttack(int count, int &attackNumMove, BadSnake *badSnake, Settings &myGame, GameMap &terminal); //Updates a position for attack Snake. 
		void GameSetup(GameMap &terminal, Settings &myGame, Snake &snake, BadSnake *badSnake, Fruit *fruit); //Sets up all game objects and positions
		void PrintFruit(Fruit *fruit, GameMap &terminal, bool gametype); //Private function for handling the printing of all static fruit positions 
		void BadAttack(Settings &myGame, BadSnake &badSnake, bool &badSnakeX, bool &badSnakeY); //TODO CAN'T GET THE RANDOM NUMBERS TO WORK CORRECTLY> 
	public: 
		GameManager(int _height, int _width, int _gameMultiplier, string _snakeHead, int _fruitCount, int _delay);  
		~GameManager();
		int PlayGame(Settings &myGame); //handles the core logic functions ofthe gameplay. This is consider the game engine. 

};
#endif
