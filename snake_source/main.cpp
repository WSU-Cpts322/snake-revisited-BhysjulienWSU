#include <string>
#include "terminal.h"
#include "snake.h"
#include "fruit.h"
#include "selectionMngr.h"
#define HARD_MODE 4
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
using namespace std;
int PlayGame(Terminal &myGame);
string menuSelection(Terminal &myGame);
string OptionsSelect(Terminal &myGame);
void ChangeDirection(Snake &snake, int input, Terminal &myGame, int delay);
void gameOverCheck(Snake &snake, Terminal &myGame, int width, int height);
bool GameModeSelect(bool enterFlag, int position, Terminal &myGame);
bool Compare(int y, int x, int direction, Terminal &myGame, Snake sanke);
bool SpaceCheck(int y, int x, Terminal &myGame, char checkChar);
int main()

{
	//TODO PlayGame is working. Move to its own class and makee it modular for added functionality. 
	//TODO Move game status out of terminal.h (game over, game type, etc) and into PlayGame. Make Terminal a terminal specific class. 
	//TODO Create termina.cpp file and move class over. 
	//TODO Use function pointers to reduce redundency in selectionMng.h. 
	//TODO Add high score class. Takes two arguments for a consstructor???? Score & name List? Maybe an object per player? Think more about this. 
	//TODO track and print HighScores 
	//TODO balance difficulties a little more. Easy to slow, fast stll to fast. 
	//TODO Add boxes on Gamemode 2
	//TODO ADD WSU Logo 
	const int SCREEN_WIDTH = 25;
	const int SCREEN_HEIGHT = 25; 
	//Create a Terminal Object wrapper. 
	Terminal myGame(SCREEN_HEIGHT, SCREEN_WIDTH); 
	//Create a snake Object.
	//x and y are temp. 
	//Check to see if the user has selected for the game to be over. 
	int input = 0; 
	while(!myGame.QuitGame())
	{
		string option = SelectionManager::menuSelection(myGame);
		input = myGame.KeyPress(); 
		if(option == "Options")
		{
			myGame.OptionsScreen();
			SelectionManager::OptionsSelect(myGame);
		}//Go to options game board. 
		else if(option == "High Scores")
		{
		
		}	//Go to view the high scores;; 
		else if(option == "Play Game")	//launch game with current options. 
		{
			PlayGame(myGame);
		}
		if(input == 'q')
		{
			myGame.SetQuitGame(true); 
		}
	}
	return 0;
}
//function for selecting color scheme 
//function for selecting game mode for both types of games. 
void BadAttack(Terminal &myGame, Snake &badSnake, bool &badSnakeX, bool &badSnakeY) //TODO CAN'T GET THE RANDOM NUMBERS TO WORK CORRECTLY> 
{
	//Start with all elements for snake as fause
	badSnake.SetHeadBool(false);
	for(int i =0; i<badSnake.GetLength(); i++)
	{
		badSnake.SetBool(i,false); 
	}
	if(badSnakeX == false && badSnakeY == false)
	{
		badSnakeX = true;
	        badSnake.SetPosition(-2, 2 +(rand() % (myGame.GetWidth() -2)), badSnake.GetLength(), 2);//Set direction down 
		while(badSnake.getX()<2||badSnake.getX()>myGame.GetHeight())
	        	badSnake.SetPosition(-2, 2 +(rand() % (myGame.GetWidth() -2)), badSnake.GetLength(), 2);//Set direction down 
	}
	else if(badSnakeX == true && badSnakeY == false)
	{
		badSnakeX = false;
		badSnakeY = true; 
	        badSnake.SetPosition(myGame.GetHeight()+3, 2 +(rand() % (myGame.GetWidth() -2)), badSnake.GetLength(), 1);//Now go up 
		while(badSnake.getX()<2||badSnake.getX()>myGame.GetWidth())
	        	badSnake.SetPosition(myGame.GetHeight()-1, 2 +(rand() % (myGame.GetWidth() -2)), badSnake.GetLength(), 1);//Now go up 
		
	}
	else if(badSnakeX == false && badSnakeY == true)
	{
		badSnakeX = true; 
		badSnake.SetPosition(2 + (rand() %(myGame.GetHeight()-2)), myGame.GetWidth()+3, badSnake.GetLength(), 3);
		while(badSnake.getY()<2 || badSnake.getY()>myGame.GetHeight())
	        	badSnake.SetPosition(2 + (rand() %(myGame.GetHeight()-2)), myGame.GetWidth()-1, badSnake.GetLength(), 3);
	}
	else if(badSnakeX == true && badSnakeY == true)
	{
	
	        badSnake.SetPosition(2 + (rand() %(myGame.GetHeight()-2)),-1, badSnake.GetLength(), 4);
		while(badSnake.getY()<2 || badSnake.getY()>myGame.GetHeight())
		       	badSnake.SetPosition(2 + (rand() %(myGame.GetHeight()-2)),1, badSnake.GetLength(), 4);
		badSnakeX = false;
		badSnakeY = false; 
	}
}
int PlayGame(Terminal &myGame)
{
	erase(); 
	myGame.SetColor(true, myGame.GetCurrentPrimaryColor());
	myGame.PrintBox(1,myGame.GetWidth(),1,1,myGame.GetHeight(),1,1,1,myGame.GetCurrentSecondColor(), myGame.GetCurrentPrimaryColor()); //myGame.GetCurrentColor()); 
//	myGame.MainScreen(); 
	bool badSnakeX = false;
	bool badSnakeY = false;;
	bool pause = false; 
	Snake snake(myGame.GetWidth(),myGame.GetHeight());
	Snake* badSnake = (Snake*)malloc(sizeof(Snake)*4);
	for(int i = 0; i<4; i++)
	{
		badSnake[i] = Snake(myGame.GetHeight(), myGame.GetWidth(), 2); 
		BadAttack(myGame, badSnake[i],badSnakeX ,badSnakeY); 
	}
	//Snake badSnake [3](myGame.GetHeight(), myGame.GetWidth(), 2); 
	Fruit fruit(myGame.GetWidth(),myGame.GetHeight());
	bool ate_fruit = false;
	//Pass it at a coordinate that it can't be at. 
	fruit.setFruit(snake.getY(), snake.getX());
	string fruitChar = "@";
	mvprintw(fruit.getFruitY(),fruit.getFruitX(), fruitChar.c_str());
	int score = 0;
	int delay = myGame.GetDifficulty(); 

	string snake_Head = "O";
	string snake_tail = "o";
	string space = " ";
	char input = 'i';
	int count = 0;
	int snakeNum = 0;
	int boxMoveCount = 0; 
	int attackNumMove = 0; 
	while(!myGame.GameOver() && !myGame.QuitGame())
	{		
		bool check = false; 
		int temp_input = myGame.KeyPress();
		if(temp_input == 'a' || temp_input == 'd' || temp_input == 'w' || temp_input == 's')
		{
			input = temp_input; 	
			count++; 
			pause = false; 
		}
		else if(temp_input == 'q')
		{
			myGame.SetQuitGame(true);
		}
		else if(temp_input == 'p')
		{
			if(pause == false)
				pause = true; 
			else 
				pause = false;
		}
		if(myGame.GetGameType() == 2 && !pause)//It gets messy with newSchool. 
		{
			bool check = false;
			if(count == HARD_MODE)//Release another snake 
			{
				//Reset 
				boxMoveCount ++;
				if(boxMoveCount == HARD_MODE)
				{
					//Get New Coordinates. Ensure its 2 boxes away from eveerything. 
					//Delete Old Box, wait for two clicks, print new box position. 
					
				}	
				check = true;
				count = 0;//Snake will have new coor:wq
				attackNumMove ++; 
						
			}
			if(check)//Wait for the snake to be off the map before moving. And add to length if the snake is longer than 1/2 of the hight of the screen. 
			{
				int j = attackNumMove; 
				if(!badSnake[j%4].GetHeadBool()&& !badSnake[j%4].GetBool(badSnake[j %4].GetLength()-1))
				{
					int snakeNumCheck = j%4; 
					BadAttack(myGame, badSnake[j %4], badSnakeX, badSnakeY); 
					check = false;
					//Add function for increase length of all units.
					if(badSnake[snakeNumCheck].GetLength()<(myGame.GetHeight())*1/2)
					{
						if(snakeNumCheck ==0)
						{
							badSnake[1].incLength(); 
							badSnake[2].incLength();
							badSnake[3].incLength();
						}
						if(snakeNumCheck ==1)
						{
							badSnake[0].incLength(); 
							badSnake[2].incLength();
							badSnake[3].incLength();
						}
						if(snakeNumCheck ==2)
						{
							badSnake[0].incLength(); 
							badSnake[1].incLength();
							badSnake[3].incLength();
						}
						if(snakeNumCheck ==3)
						{
							badSnake[0].incLength(); 
							badSnake[1].incLength();
							badSnake[2].incLength();
						}
					}

				}

			}
			//Check if there has been a collission 
			//Move badSnake 
			//Print Snake
			for(snakeNum = 0; snakeNum < 4; snakeNum++)//Move all the bad snakes. 
			{
				//Set Color 
				myGame.SetColor(true, myGame.GetCurrentPrimaryColor()); 
				int check = mvinch(badSnake[snakeNum].getFinYTail(), badSnake[snakeNum].getFinXTail())& A_COLOR;//Get the color its on and don't print if it is black. 
				if(!SpaceCheck(badSnake[snakeNum].getFinYTail(), badSnake[snakeNum].getFinXTail(), myGame, 'X') && check != 0) //
					mvprintw(badSnake[snakeNum].getFinYTail(),badSnake[snakeNum].getFinXTail(), space.c_str()); 
				ChangeDirection(badSnake[snakeNum],badSnake[snakeNum].getDirect(),myGame,0); 
				badSnake[snakeNum].UpdatePosition(); 
				//Check if head will collide. Swap bool if so. 
				if(SpaceCheck(badSnake[snakeNum].getY(), badSnake[snakeNum].getX(), myGame, 'X')) //If we see an X swap bool values. 
				{
					badSnake[snakeNum].SetHeadBool(!badSnake[snakeNum].GetHeadBool());
				}
				if(badSnake[snakeNum].GetHeadBool() && !SpaceCheck(badSnake[snakeNum].getY(), badSnake[snakeNum].getX(), myGame, 'X'))
				{		
					mvprintw(badSnake[snakeNum].getY(),badSnake[snakeNum].getX(), snake_Head.c_str());
				}
				for(int y =0; y<badSnake[snakeNum].GetLength(); y++)
				{
					//Make sure we only print inside the boundaries. 
					if(SpaceCheck(badSnake[snakeNum].getyTail(y), badSnake[snakeNum].getxTail(y), myGame, 'X'))
					{
						badSnake[snakeNum].SetBool(y,badSnake[snakeNum].GetBool(y));
					}
					if(badSnake[snakeNum].GetBool(y))
					{
						mvprintw(badSnake[snakeNum].getyTail(y),badSnake[snakeNum].getxTail(y), snake_tail.c_str());
					}
				}
				
				myGame.SetColor(false, myGame.GetCurrentPrimaryColor()); 
			}
		}
		else count = 0; 
		if(!pause)
		{

			myGame.SetColor(true, myGame.GetCurrentPrimaryColor()); 
		//		TODO there is a chance a fruit could start on a tail. Have fruit check if it is an empty space and correct collor. 
//		if(ate_fruit == false)
//		{
			mvprintw(snake.getFinYTail(),snake.getFinXTail(), space.c_str()); 
//		}
		ate_fruit = false; 
		ChangeDirection(snake, input, myGame, delay);
		if(input == 'w' || input == 's' || input =='d' || input == 'a') //Then the snake is on the move
		{
				check = Compare(snake.getY(), snake.getX(), snake.getDirect(), myGame, snake); 
				snake.UpdatePosition();
				if(check)
				{
					if(fruit.getFruitY() == snake.getY() && fruit.getFruitX() == snake.getX()) //Then the snake has eaten a fruit
					{	
						snake.incLength();
						fruit.setFruit(fruit.getFruitY(), fruit.getFruitX()); 
						ate_fruit = true; //Tells the system that the snake has increased in size and to print accordingly. 
						score = score + myGame.ScoreMultiplier(); 
						string scoreTemp = "Score: " + to_string(score);  
						myGame.SetColor(true, WB);						
						mvprintw(myGame.GetHeight()+2, 1, scoreTemp.c_str());
						myGame.SetColor(false, WB); 
						myGame.SetColor(true, myGame.GetCurrentPrimaryColor()); 
						mvprintw(fruit.getFruitY(),fruit.getFruitX(), fruitChar.c_str());
						mvprintw(snake.getFinYTail(),snake.getFinXTail(), space.c_str()); 
					}
					else//You've run into something other than fruit. Gave over. 
					{
						myGame.SetGameOver(true);
					}
				}
				
		}
		//Enter white space for last position of snake. 
		mvprintw(snake.getY(),snake.getX(), snake_Head.c_str());
		for(int y =0; y<snake.GetLength(); y++)
		{
			mvprintw(snake.getyTail(y),snake.getxTail(y), snake_tail.c_str());
		}
		myGame.UpdateTerminal();
		napms(delay);
		mvprintw(fruit.getFruitY(),fruit.getFruitX(), fruitChar.c_str());
		myGame.SetColor(false, myGame.GetCurrentPrimaryColor()); 
		//Check if head is on fruit before updating.
		//mvprintw(fruit.getFruitY(),fruit.getFruitX(), fruitChar.c_str());
		//check to see if you're still alive. 
		//gameOverCheck(snake, myGame,myGame.GetWidth(), myGame.GetHeight());
		}
	}
	myGame.SetQuitGame(false);
	myGame.SetColor(true, myGame.GetCurrentPrimaryColor());
	myGame.SetGameOver(false);
       	erase();
	free(badSnake); 	

return score; 
}

bool SpaceCheck(int y, int x, Terminal &myGame, char checkChar)
{
	bool collision = false; 
	int check = mvinch(y, x)& A_CHARTEXT;
	if(check == checkChar)  
	{
		collision = true;
	}
	return collision; 
}



//TODO TODO TODO TODO These compare functions must be called right after direction selection is made. 
bool Compare(int y, int x, int direction, Terminal &myGame, Snake sanke)
{
	bool collision = false; 
	int boardX;
	int boardY; 
	boardX = x;
	boardY = y;
	
	if(direction == 'w')
	{
		boardY--;
	}
	else if(direction == 's')
	{
		boardY++;
	}
	else if(direction == 'd')
	{
		boardX++;
	}
	else if(direction == 'a')
	{
		boardX--; 
	}
	int check = mvinch(boardY, boardX)& A_CHARTEXT;
	if(check != 32) //<<---- Trial and error found 288 to be whitespace in ncurses???? 
	{
		collision = true;
	}
	return collision; 
}
/*
void gameOverCheck(Snake &snake, Terminal &myGame, int width, int height)
{
	if(snake.getY()==0 || snake.getX() == 0 || snake.getY() == height || snake.getX() == width-1)
	{
		myGame.SetGameOver(true);
	}
	for(int i = 0; i<snake.GetLength(); i++)
	{
		if(snake.getY() == snake.getyTail(i) && snake.getX() == snake.getxTail(i))
		{
			myGame.SetGameOver(true); 
		}
	}
}*/
//This function changes snake direction and also updates the position. 
void ChangeDirection(Snake &snake, int input, Terminal &myGame, int delay)
{
		switch(input)
		//set/keep snake direction. 	
		{
			case 'a':
				snake.setDirection(3);
			break;

			case 'd':
				snake.setDirection(4);
			break;

			case 'w':
				snake.setDirection(1);
				napms(delay/2);
			break;

			case 's':
				snake.setDirection(2);
				napms(delay/2);
			break; 

			case 'q':
		      	myGame.QuitGame();
			break; 
		}
		///Call compaire here. Or update snake in ma
	
}
