#ifndef GAMEMANAGER
#define GAMEMANAGER
#define numOfSnakes 4
#define HARD_MODE 4
#define TIMERSET 80 
//TODO function for selecting color scheme in own class. 
//TODO This is allow for GameManager to oppoerate without passing myGame settings. 
	//function for selecting game mode for both types of games.
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
			Snake* badSnake; 
			Fruit* fruit;
			//Setup basic game variables 
		bool SpaceCheck(int y, int x, Terminal &terminal, char checkChar)
		{
			bool collision = false; 
			int check = mvinch(y, x)& A_CHARTEXT;
			if(check == checkChar)  
			{
				collision = true;
			}
			return collision; 
		}

		//Compare function for determing future position of Snake. TODO restruct good snake logic to eliminate this function and use space check. 
		bool Compare(int y, int x, int direction, Terminal &terminal, Snake sanke)
		{
			bool collision = false; 
			int boardX;
			int boardY; 
			boardX = x;
			boardY = y;
			
			if(direction == 'w' || direction == 'B')
			{
				boardY--;
			}
			else if(direction == 's' || direction == 'A')
			{
				boardY++;
			}
			else if(direction == 'd' || direction == 'C')
			{
				boardX++;
			}
			else if(direction == 'a' || direction == 'D')
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
	
		//This function changes snake direction and also updates the position. 
		void ChangeDirection(Snake &snake, int input, Settings &myGame, int delay)
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
				
				case 'D':
					snake.setDirection(3);
				break;

				case 'C':
					snake.setDirection(4);
				break;

				case 'A':
					snake.setDirection(1);
					napms(delay/2);
				break;

				case 'B':
					snake.setDirection(2);
					napms(delay/2);
				break; 

				case 'q':
				myGame.QuitGame();
				break; 
			}
			
		}
		void FruitMatch(Fruit &fruit, Settings &myGame, Terminal &terminal,  bool snakePower)
		{
			int check = 0;
			bool check2 = true;
		        int gameMultipliertemp;
			if(snakePower)
			{
				gameMultipliertemp = gameMultiplier*2; 
			}
			else 
			{
				gameMultipliertemp = gameMultiplier; 
			}

			while(check == 0 || check2 == true)
			{
				fruit.setFruit(fruit.getFruitY(), fruit.getFruitX()); 
				check = mvinch(fruit.getFruitY(), fruit.getFruitX()) & A_COLOR;//Make sure we're printing on red space. 
				check2 = SpaceCheck(fruit.getFruitY(), fruit.getFruitX(),terminal,'X'); 
			}
			string fruitChar = "@";
			score = score + baseScore*gameMultipliertemp;  
			//TODO Move printing score out of this function. It doesn't make sense here. 
			string scoreTemp = "Score: " + to_string(score);  
			terminal.SetColor(true, WB);						
			mvprintw(myGame.GetHeight()+2, 1, scoreTemp.c_str());
			terminal.SetColor(false, WB); 
			terminal.SetColor(true, terminal.GetCurrentPrimaryColor()); 
		//	mvprintw(fruit.getFruitY(),fruit.getFruitX(), fruitChar.c_str());
		}
		int SnakeAttack(int count, int &attackNumMove, Snake *badSnake, Settings &myGame, Terminal &terminal)
		{	
		
			bool check = false;
			if(count == HARD_MODE)//Release another snake 
			{
				//Reset 
				check = true;
				count = 0;//Snake will have new coor:wq
				attackNumMove ++; 
						
			}
			if(check)//Wait for the snake to be off the map before moving. And add to length if the snake is longer than 1/2 of the hight of the screen. 
			{
				int j = attackNumMove; 
				if(!badSnake[j%4].GetHeadBool()&& !badSnake[j%4].GetBool(badSnake[j %4].GetLength()))
				{
					int snakeNumCheck = j%4; 
					BadAttack(myGame, badSnake[j %4], badSnakeX, badSnakeY); 
					check = false;
					//Add function for increase length of all units.
					if(badSnake[snakeNumCheck].GetLength()<(myGame.GetHeight()))
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
			for(int snakeNum = 0; snakeNum < 4; snakeNum++)//Move all the bad snakes. 
			{
				//Set Color 
				terminal.SetColor(true, terminal.GetCurrentPrimaryColor()); 
				int check = mvinch(badSnake[snakeNum].getFinYTail(), badSnake[snakeNum].getFinXTail())& A_COLOR;//Get the color its on and don't print if it is black. 
				if(!SpaceCheck(badSnake[snakeNum].getFinYTail(), badSnake[snakeNum].getFinXTail(), terminal, 'X') && check != 0) //
					mvprintw(badSnake[snakeNum].getFinYTail(),badSnake[snakeNum].getFinXTail(), space.c_str()); 
				ChangeDirection(badSnake[snakeNum],badSnake[snakeNum].getDirect(),myGame,0); 
				badSnake[snakeNum].UpdatePosition(); 
				//Check if head will collide. Swap bool if so. 
				if(SpaceCheck(badSnake[snakeNum].getY(), badSnake[snakeNum].getX(), terminal, 'X')) //If we see an X swap bool values. 
				{
					badSnake[snakeNum].SetHeadBool(!badSnake[snakeNum].GetHeadBool());
				}
				if(badSnake[snakeNum].GetHeadBool() && !SpaceCheck(badSnake[snakeNum].getY(), badSnake[snakeNum].getX(), terminal, 'X'))
				{		
					mvprintw(badSnake[snakeNum].getY(),badSnake[snakeNum].getX(), snake_Head.c_str());
				}
				terminal.SetColor(false, terminal.GetCurrentPrimaryColor()); 
			}

			return count;
		
		}
		void GameSetup(Terminal &terminal, Settings &myGame, Snake &snake, Snake *badSnake, Fruit *fruit) 
		{
			terminal.EraseAll(); 	
			terminal.SetColor(true, terminal.GetCurrentPrimaryColor());
			terminal.PrintBoard(myGame.GetGameType(), myGame.GetWidth(), myGame.GetHeight()); //myGame.GetCurrentColor()); 
			//	myGame.MainScreen(); 
			badSnakeX = false;
			badSnakeY = false;;
			pause = false; 
			for(int i = 0; i<fruitCount;i++)
			{
				fruit[i] = Fruit(myGame.GetWidth(),myGame.GetHeight());
			}
			for(int i = 0; i<4; i++)
			{
				badSnake[i] = Snake(height, width, 4); //Make this a 
				BadAttack(myGame, badSnake[i],badSnakeX ,badSnakeY); 
			}
			//Snake badSnake [3](myGame.GetHeight(), myGame.GetWidth(), 2); 
			//Pass it at a coordinate that it can't be at.

			for(int i = 0; i<fruitCount; i++)
			{
				int check = 0;
				bool check2 = true; 
				while(check == 0 || check2 == true)
				{
					fruit[i].setFruit(fruit[i].getFruitY(), fruit[i].getFruitX()); 
					check = mvinch(fruit[i].getFruitY(), fruit[i].getFruitX()) & A_COLOR;//Make sure we're printing on red space. 
					check2 = SpaceCheck(fruit[i].getFruitY(), fruit[i].getFruitX(),terminal, 'X'); 
				}
			}
			PrintFruit(fruit, terminal);
			terminal.SetColor(false, terminal.GetCurrentPrimaryColor());
		}
		void PrintFruit(Fruit *fruit, Terminal &terminal)
		{
			for(int i = 0; i<fruitCount; i++)
			{
				terminal.PrintString(fruit[i].getFruitY(), fruit[i].getFruitX(), fruitChar); 
				//mvprintw(fruit[i].getFruitY(),fruit[i].getFruitX(), fruitChar.c_str());
			}
		}
		//Control start position of badSnakes. 
		void BadAttack(Settings &myGame, Snake &badSnake, bool &badSnakeX, bool &badSnakeY) //TODO CAN'T GET THE RANDOM NUMBERS TO WORK CORRECTLY> 
		{//TODO Currently only setup to take a max of four snakes. Restructure logic to take more 
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
	public: 
	GameManager(int _height, int _width, int _gameMultiplier, string _snakeHead, int _fruitCount, int _delay)
	{
		fruitCount = _fruitCount;
		gameMultiplier = _gameMultiplier; 
		height = _height;
		width = _width;
		delay = _delay; 	
	}
	~GameManager()
	{
		free(badSnake);
		free(fruit);
	}
	//Setup global game variables. 
//TODO Remove Terminal dependency. Create seperate color Class and then only pass in width and heiight. 
	int PlayGame(Terminal &terminal, Settings &myGame)
	{
		Snake snake(width,height);
		badSnake = (Snake*)malloc(sizeof(Snake)*numOfSnakes);//Make number of Snakes a variable for constructor. More snakes on Hard. 
		fruit= (Fruit*)malloc(sizeof(Snake)*fruitCount); (myGame.GetWidth(),myGame.GetHeight());
		GameSetup(terminal, myGame, snake, badSnake, fruit); 
		int powerTimer = 0; 
		char input = 'i';
		int count = 0;
		int attackNumMove = 0; 
		while(!myGame.GameOver() && !myGame.QuitGame())
		{		
			bool check = false; 
			int temp_input = terminal.KeyPress();
			if(temp_input == 'a' || temp_input == 'd' || temp_input == 'w' || temp_input == 's' || temp_input == 'A' || temp_input == 'C' || temp_input == 'B' || temp_input == 'D')
			{
				input = temp_input; 	
				count++; 
				pause = false; 
			}
			else if(temp_input == 'q')
			{
				myGame.SetQuitGame(true);//TODO Decouple this from this classs. 
			}
			else if(temp_input == 'p')
			{
				if(pause == false)
					pause = true; 
				else 
					pause = false;
			}
			if(myGame.GetGameType(1) == 2 && !pause)//It gets messy with newSchool. 
				count = SnakeAttack(count, attackNumMove, badSnake, myGame, terminal); //Call main function for controlling attacking snakes. 
			else count = 0; 
			if(!pause)
			{
				terminal.SetColor(true, terminal.GetCurrentPrimaryColor()); 
		
				if(snake.getFinYTail() != 0 || snake.getFinXTail() != 0)
				{
					mvprintw(snake.getFinYTail(),snake.getFinXTail(), space.c_str()); 
				}
			ChangeDirection(snake, input, myGame, delay);
			if(input == 'a' || input == 'd' || input == 'w' || input == 's' || input == 'A' || input == 'C' || input == 'B' || input == 'D')
			{
				check = Compare(snake.getY(), snake.getX(), snake.getDirect(), terminal, snake); 
				snake.UpdatePosition();
				if(check)
				{
					bool gameFlag = true; 
					for(int i = 0; i<fruitCount; i++)
					{
						if(fruit[i].getFruitY() == snake.getY() && fruit[i].getFruitX() == snake.getX()) //Then the snake has eaten a fruit
						{	
							if(fruit[i].GetPower() && myGame.GetGameType(1) == 2)
							{
								snake.SetPower(true); 
							}
							else
							{
								snake.incLength();
							}
							FruitMatch(fruit[i], myGame,terminal, snake.GetPower()); 
					 
							gameFlag = false;
						}
					}
					myGame.SetGameOver(gameFlag);//What was matched wasn't a fruit, game over. 
				}
					
			}
			if(snake.GetPower())
			{
				terminal.SetColor(true, terminal.GetCurrentSecondColor()); 
				powerTimer = powerTimer + TIMERSET/myGame.GetGameSize()*3; 
			}
			mvprintw(snake.getY(),snake.getX(), snake_Head.c_str()); //Print Snake head. 
			for(int y =0; y<snake.GetLength(); y++)//Move printing out of this class. 
			{
				if(snake.getyTail(y) != 0 || snake.getxTail(y) != 0) //Then the tail isn't been assigned yet. 
				{
					mvprintw(snake.getyTail(y),snake.getxTail(y), snake_tail.c_str());
				}
				
			}
			if(snake.GetPower())
			{
				terminal.SetColor(false, terminal.GetCurrentSecondColor()); 
			}
			if(powerTimer > 120)
			{
				snake.SetPower(false);
			        powerTimer = 0;	
			}	
			terminal.SetColor(true, terminal.GetCurrentPrimaryColor()); 
			terminal.UpdateTerminal();
			napms(delay);
			PrintFruit(fruit,terminal); 
			terminal.SetColor(false, terminal.GetCurrentPrimaryColor()); 
			}
		}

		myGame.SetQuitGame(false);
		terminal.SetColor(true, terminal.GetCurrentPrimaryColor());
		myGame.SetGameOver(false);
		terminal.EraseAll();
	return score; 
	}

};
#endif
