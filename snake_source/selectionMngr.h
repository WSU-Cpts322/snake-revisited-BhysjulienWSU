#ifndef SELECT
#define SELECT

using namespace std; 

class SelectionManager
{
	public: 
		//Don't allow creating an instance of this object. 
		SelectionManager(){}
		static bool ColorModeSelect(bool enterFlag, int position, Terminal &myGame)
		{
			erase();
			myGame.PrintColorScreen(); 
			myGame.UpdateTerminal();
			int position_temp = 1;
			myGame.PrintColorSelection(position_temp);
			int input = 1;
			//Display menu. have user select. Wriite difficulty to myGame object. 
			bool difFlag = false; 
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
					myGame.PrintSelection(position); 
				}
				if(input == 'q')
				{
					//Quit game completely. 
					myGame.SetQuitGame(true);
				}
			}
			return enterFlag;
		}


		static bool SizeModeSelect(bool enterFlag, int position, Terminal &myGame)
		{
			erase(); 
			myGame.PrintSizeScreen(); 
			myGame.UpdateTerminal();
			int position_temp = 1;
			myGame.PrintSizeSelection(position_temp); //Print Dif Options 
			int input = 1;
			//Display menu. have user select. Wriite difficulty to myGame object. 
			bool difFlag = false; 
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
					myGame.PrintSelection(position); 
				}
				if(input == 'q')
				{
					myGame.SetQuitGame(true);
				}
			}
			return enterFlag; 
		}

		static bool GameModeSelect(bool enterFlag, int position, Terminal &myGame)
		{ 

			erase(); 
			myGame.DifficultyScreen(); 
			myGame.UpdateTerminal();
			int position_temp = 1;
			myGame.PrintDifficultySelection(position_temp); //Print Dif Options 
			int input = 1;
			//Display menu. have user select. Wriite difficulty to myGame object. 
			bool difFlag = false; 
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
					myGame.PrintSelection(position); 
				}
				if(input == 'q')
				{
					myGame.SetQuitGame(true);
				}
			}
			return enterFlag; 
		}


		static string OptionsSelect(Terminal &myGame)
		{
			string selection = "";
			bool enterFlag = false;
			int input = 1;
			int position = 1; 
			myGame.PrintSelection(position); 
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
							myGame.PrintSelection(position); 
						}
					}
					else if(input == 'w')
					{
						if(position>1)
						{
							position--;
							myGame.PrintSelection(position);
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
					enterFlag = GameModeSelect(enterFlag, position, myGame);
				}
				else if (position ==2)
				{
					myGame.SetGameType(2); 
					enterFlag = GameModeSelect(enterFlag, position, myGame);
				}
				else if (position ==3)
				{
					enterFlag = ColorModeSelect(enterFlag, position, myGame); 	
				}
				else if (position ==4)
				{
					enterFlag = SizeModeSelect(enterFlag, position, myGame); 
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
	public:
		static string menuSelection(Terminal &myGame)
		{
			string selection = ""; 
			bool enterFlag = false;
			int input = 1;
			int position = 1; 
			myGame.MainScreen(); 
			myGame.UpdateTerminal();
			myGame.PrintSelection(position);
			while(!enterFlag && !myGame.QuitGame())
			{
				input = myGame.KeyPress(); 
				switch (input)
				{
					case 's':
						if(position < 3) //Then we're not at the bottom of the menu 
						{
							position++;
							myGame.PrintSelection(position);
						}
					break;
				
					case 'w':
						if(position > 1)
						{
							position--;
							myGame.PrintSelection(position);
						}	
					break; 
				
					case '\n':
						enterFlag = true; 
					break; 
				
					case'q':
						myGame.SetQuitGame(true); 
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
					selection = "High Score";
			}
			
			//Print the main menu and return a string option. 
			return selection;
		}
};

#endif
