#ifndef SELECT
#define SELECT

using namespace std; 

class SelectionManager
{
	public: 
		//Don't allow creating an instance of this object. 
		SelectionManager(){}
		static bool ColorModeSelect(bool enterFlag, int position, Terminal &myGame, int * scoresNum, string * names)
		{

			erase();
			myGame.PrintColorScreen(); 
			myGame.UpdateTerminal();
			int position_temp = 1;
			myGame.PrintColorSelection(position_temp);
			int input = 1;
			//Display menu. have user select. Wriite difficulty to myGame object. 
			bool difFlag = false; 
			myGame.Revisited(0, 53, 0);
		       	myGame.PaintSnakeEasy(53,56); 	
		       	myGame.PrintHighScores(names, scoresNum); 	
			while(!difFlag && !myGame.QuitGame())
			{
				input = myGame.KeyPress();
				if(input == 's')
				{
					if(position_temp<7)
					{
						position_temp ++;
						myGame.PrintColorSelection(position_temp);
					}
				}
				if(input == 'w')
				{
					if(position_temp>1)
					{
						position_temp --;
						myGame.PrintColorSelection(position_temp);
					}
				}
				if (input == '\n')
				{
					erase(); 
					difFlag = true; 
					enterFlag = false;
					myGame.OptionsScreen();
					myGame.UpdateTerminal(); 
					myGame.PrintSelection(position, 18); 
					myGame.Revisited(0, 41, 0);
		       			myGame.PaintSnakeEasy(41,56); 	
		       			myGame.PrintHighScores(names, scoresNum); 	
				}
				if(input == 'q')
				{
					//Quit game completely. 
					myGame.SetQuitGame(true);
				}
	
			}
			return enterFlag;
		}


		static bool SizeModeSelect(bool enterFlag, int position, Terminal &myGame, int * scoresNum, string * names)
		{
			erase(); 
			myGame.PrintSizeScreen(); 
			myGame.UpdateTerminal();
			int position_temp = 1;
			myGame.PrintSizeSelection(position_temp); //Print Dif Options 
			int input = 1;
			//Display menu. have user select. Wriite difficulty to myGame object. 
			bool difFlag = false; 
			myGame.Revisited(0, 29, 0);
		       	myGame.PaintSnakeEasy(29,56); 	
		       	myGame.PrintHighScores(names, scoresNum); 	
			while(!difFlag && !myGame.QuitGame())
			{
				input = myGame.KeyPress(); 
				if(input == 's')
				{
					if(position_temp<3)
					{
						position_temp ++;
						myGame.PrintSizeSelection(position_temp); //Print Dif Options 
					}
				}
				if(input == 'w')
				{
					if(position_temp>1)
					{
						position_temp --;
						myGame.PrintSizeSelection(position_temp); //Print Dif Options 
					}
				}
				if (input == '\n')
				{
					erase(); 
					difFlag = true; 
					enterFlag = false;
					myGame.OptionsScreen();
					myGame.UpdateTerminal(); 
					myGame.PrintSelection(position, 18); 
					myGame.Revisited(0, 41, 0);
		       			myGame.PaintSnakeEasy(41,56); 	
		       			myGame.PrintHighScores(names, scoresNum); 	
				}
				if(input == 'q')
				{
					myGame.SetQuitGame(true);
				}
			}
			return enterFlag; 
		}

		static bool GameModeSelect(bool enterFlag, int position, Terminal &myGame, int * scoresNum, string * names)
		{ 

			erase(); 
			myGame.DifficultyScreen(); 
			myGame.UpdateTerminal();
			int position_temp = 1;
			myGame.PrintDifficultySelection(position_temp); //Print Dif Options 
			int input = 1;
			//Display menu. have user select. Wriite difficulty to myGame object. 
			bool difFlag = false; 
			myGame.Revisited(0, 29, 0);
		       	myGame.PaintSnakeEasy(29,56); 	
		       	myGame.PrintHighScores(names, scoresNum); 	
			while(!difFlag && !myGame.QuitGame())
			{
				input = myGame.KeyPress(); 
				if(input == 's')
				{
					if(position_temp<3)
					{
						position_temp ++;
						myGame.PrintDifficultySelection(position_temp); //Print Dif Options 
					}
				}
				if(input == 'w')
				{
					if(position_temp>1)
					{
						position_temp --;
						myGame.PrintDifficultySelection(position_temp); //Print Dif Options 
					}
				}
				if (input == '\n')
				{
					erase(); 
					difFlag = true; 
					enterFlag = false;
					myGame.OptionsScreen();
					myGame.UpdateTerminal(); 
					myGame.PrintSelection(position, 18); 
					myGame.Revisited(0, 41, 0);
		       			myGame.PaintSnakeEasy(41,56); 	
		       			myGame.PrintHighScores(names, scoresNum); 	
				}
				if(input == 'q')
				{
					myGame.SetQuitGame(true);
				}
			}
			return enterFlag; 
		}


		static string OptionsSelect(Terminal &myGame, int * scoresNum, string * names)
		{
			int clear = 30;
			string selection = "";
			bool enterFlag = false;
			int input = 1;
			int position = 1; 
			myGame.Revisited(0, 41, 0);
		       	myGame.PaintSnakeEasy(41,56); 	
			myGame.PrintSelection(position, clear);
		       	myGame.PrintHighScores(names, scoresNum); 	
			while(selection != "Return" && !myGame.QuitGame()) //We dont want to return to the main menu until "return" 
			{
				while(!enterFlag && !myGame.QuitGame())
				{
					input = myGame.KeyPress(); 
					if(input == 's')
					{
						if(position <5)
						{
							position++;
							myGame.PrintSelection(position, clear); 
						}
					}
					else if(input == 'w')
					{
						if(position>1)
						{
							position--;
							myGame.PrintSelection(position, clear);
						}
					}
					else if(input == '\n')
					{
						enterFlag = true;
					}	
					else if(input == 'q')
					{
						myGame.SetQuitGame(true);
					}


				//	erase();
				}
				if(position == 1)
				{
					myGame.SetGameType(1); 
					enterFlag = GameModeSelect(enterFlag, position, myGame, scoresNum, names);
				}
				else if (position ==2)
				{
					myGame.SetGameType(2); 
					enterFlag = GameModeSelect(enterFlag, position, myGame, scoresNum, names);
				}
				else if (position ==3)
				{
					enterFlag = ColorModeSelect(enterFlag, position, myGame, scoresNum, names); 	
				}
				else if (position ==4)
				{
					enterFlag = SizeModeSelect(enterFlag, position, myGame, scoresNum, names); 
				}
				else if (position ==5)
				{
					erase(); 
				//	myGame.MainScreen(); 
					selection = "Return"; 
				}
			}	
			//Print the main menu and return a string option. 
			return selection;
		}
		static void ShowScores(Terminal &myGame, ScoreKeeper &scores)
		{
			erase(); 
			string names [6]; 
			int scoresNum[6]; 
			bool enterFlag = false;
			scores.GetHighScores(scoresNum, names); 
			myGame.PrintHighScoreScreen(names, scoresNum);
			int printXPosition = 4; 
			int printYPosition = 26;
		       	myGame.PrintBox(18,2,56, 15, RR, WW, false); 
		       	myGame.PrintBox(35,2,56, 15, RR, WW, false); 
			myGame.SetColor(true, BW);
			myGame.PrintString(19, 20, "Old School Scores");		
			myGame.PrintString(36, 20, "New School Scores");		
			myGame.PrintString(21, 5, "Easy");		
			myGame.PrintString(21, 26, "Hard");		
			myGame.PrintString(21, 44, "2020");		
			myGame.PrintString(38, 5, "Easy");		
			myGame.PrintString(38, 26, "Hard");		
			myGame.PrintString(38, 44, "2020");		
			for(int i = 1; i<=6; i++)
			{
				if(i <=3)
				{
					printYPosition = 22; //Retsrat at the top 
				}
				else if(i ==4) 
				{
				
					printYPosition = 39; 
					printXPosition = 4; 
				}
				else
				{
					printYPosition = 39; 
				}

				int *intScores = scores.GetStringScore(i);
				string *stgScores = myGame.StringToInt(intScores, 10);
				string *names = scores.GetNames(i);
				for(int j = 0;j<10;j++)
				{
					string gap(10-stgScores[j].length(), '_'); 
					string temp;
					if(names[j] != "")
						temp = stgScores[j] + gap +" (" + names[j] +")";
					else
						temp = stgScores[j] + gap;
					myGame.PrintString(printYPosition, printXPosition, temp); 
					printYPosition++; 
				}
				printXPosition = printXPosition + 18;
			       if(i == 3)
					printXPosition = printXPosition + 4;
			}
			
			myGame.SetColor(false, BW);
			myGame.PrintString(53,2, "Select \"Enter\" to return to the main menu.");
			myGame.UpdateTerminal();

			while(!enterFlag && !myGame.QuitGame())
			{	
				int input = myGame.KeyPress(); 
				if(input == 'q')
				{
					myGame.SetQuitGame(true); 
				}
				else if(input == '\n')
				{
					enterFlag = true;
					erase(); 
				}
			}

		}
		static string menuSelection(Terminal &myGame, string *names, int *scores)
		{
			string selection = ""; 
			bool enterFlag = false;
			bool w = false; 
			bool s = false;
			int input = 1;
			int position = 1; 
			int x = 200;
			int y = 29; 
			int slowDown = 0; 
			int length = 10;
			myGame.MainScreen(names, scores); 
			myGame.UpdateTerminal();
			bool snakeB = false; 
			myGame.PrintSelection(position, 18);
			myGame.SetPaintSnake(0); 
			while(!enterFlag && !myGame.QuitGame())
			{
					
				if(x != 0)
					myGame.Revisited(x,y, length); 
				if(slowDown == 0)
				{
					if(x!= 0)
					{
						x--; 
					}
					else
					{
						if(snakeB) //Slow it down even more. 
						{
							myGame.PaintSnake(y, 57); 
							snakeB = false;
						}	
						else
						{
							snakeB = true; 
						}
					}
				}
				slowDown++;
				if(x !=0)
				{
					if(slowDown == 50)
					{
						slowDown = 0; 
					}
				}
				else
				{
					if(slowDown == 40000)
					{
						slowDown = 0;
					}
				}
				input = myGame.KeyPress(); 
				switch (input)
				{
					case 's':
						if(position < 3) //Then we're not at the bottom of the menu 
						{
							position++;
							myGame.PrintSelection(position, 18);
						}
						w = false;
						s = false;
					break;
				
					case 'w':
						if(position > 1)
						{
							position--;
							myGame.PrintSelection(position,18);
						}	
						w =false;
						s =false; 
					break; 
				
					case '\n':
						enterFlag = true; 
						w = false; 
						s = false;
					break; 
				
					case'q':
						myGame.SetQuitGame(true); 
						w = false;
						s = false;
					break;
				
					case 'W':
						w = true;
						s = false; 	
					break; 

					case 'S': 
						if(w == true)
							s = true; 
						w=false; 

					break; 

					case 'U':
						if(s == true)
						{
							enterFlag = true; 
							return "WSU"; 
						}
						w=false;
						s=false;

					break; 
				}	

			}
			erase();
			if(position == 1 && !myGame.QuitGame())
			{
					selection = "Play Game";
			}
			else if (position ==2 && !myGame.QuitGame())
			{
					selection = "Options";
			}
			else if (position ==3 && !myGame.QuitGame())
			{
					selection = "High Scores";
			}
			
			//Print the main menu and return a string option. 
			return selection;
		}
};

#endif
