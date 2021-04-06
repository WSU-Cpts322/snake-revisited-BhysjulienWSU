#ifndef SELECT
#define SELECT

using namespace std; 

class SelectionManager
{

	public:
		//Don't allow creating an instance of this object. 
		SelectionManager(){}

		static void CustomColorSelect(Terminal &terminal, Settings &myGame, int *scoresNum, string *names)
		{
			terminal.EraseAll(); 
			bool returnFlag = false; 
			terminal.PrintSnakeHeader();
		       	terminal.SetColor(true,WW); 	
			terminal.PrintMultiChars("SELECT,,TWO,,COLOR,,SETS", 11,2); 
			terminal.PrintMultiChars("1ST:,,BOARD,,AND,,SNAKE", 17,2); 
			terminal.PrintMultiChars("2ND:,,GAME,,BOARDER", 23,2);
		       	terminal.PrintBox(0,132,64,51,64,51,BLBL,WW, false, true);
		       	terminal.SetColor(true, BB); 	
			terminal.PrintMultiChars("B,,=,,BLACK", 2,134);
		       	terminal.SetColor(true, RR); 	
			terminal.PrintMultiChars("R,,=,,RED", 8,134);
		       	terminal.SetColor(true, GG); 	
			terminal.PrintMultiChars("G,,=,,GREEN", 14,134);
		       	terminal.SetColor(true, GG); 	
			terminal.PrintMultiChars("G,,=,,GREEN", 14,134);
		       	terminal.SetColor(true, YY); 	
			terminal.PrintMultiChars("Y,,=,,YELLOW", 20,134);
		       	terminal.SetColor(true, BLBL); 	
			terminal.PrintMultiChars("L,,=,,BLUE", 26,134);
		       	terminal.SetColor(true, MM); 	
			terminal.PrintMultiChars("M,,=,,MEGENTA", 32,134);
		       	terminal.SetColor(true, CC); 	
			terminal.PrintMultiChars("C,,=,,CYAN", 38,134);
		       	terminal.SetColor(true, WB); 	
			terminal.PrintMultiChars("H,,=,,WHITE", 44,134);
		       	terminal.SetColor(false, WB); 	
			terminal.PrintString(30,2, "The first letter is the foreground for a given colorset, and the second is the background."); 
			terminal.PrintString(32,2, "Note: for the primary (1st) color set, two different colors are required."); 
			terminal.PrintMultiChars("1ST:,,,,,,,,,,,,,,,,,,,,,,,,,/,,,", 34,2); 
			terminal.PrintMultiChars("2ND:,,,,,,,,,,,,,,,,,,,,,,,,,/,,,", 41,2); 
		       	terminal.UpdateTerminal();	
			string c11 = "";
			string c12 = "";
			string c21 = "";
			string c22 = "";
			
			int input = -1;
			int posY = 1; 
			int posX = 1; 
			while(!myGame.QuitGame() && !returnFlag)
			{
				input = terminal.KeyPress(); 
				if(input == 'w')
				{
					if(posY > 1)
					{
						posY--; 
					}
				}
				else if(input == 's')
				{
					if(posY < 2)
					{
						posY++;
					}
				}
				else if(input == 'a')
				{
					if(posX > 1)
					{
						posX--;
					}
				}
				else if(input == 'd')
				{
					if(posX<2)
					{
						posX++; 
					}
				}
				else if(input  == 'q')
				{
					myGame.SetQuitGame(true); 
				}
				else if(input == '\n')
				{
					returnFlag = true; 
				}
				else
				{
					int tempColor; 
					string tempStr = ""; 
					bool valid = false; 
					char temp = input;
					if(input >= 97 && input <= 122) //Then its uppercase 
					{
						temp = toupper(temp);	
					}
					if(temp == 'B' || temp == 'R' || temp == 'G' || temp == 'Y' || temp == 'L' || temp == 'M' || temp == 'C' || temp == 'H' || temp == 127 || temp ==8)
					{
						if(temp == 'B')
						{
							tempStr = "BLACK";
							tempColor = WB;
						}
						if(temp == 'R')
						{
							tempStr = "RED";
							tempColor = RR;
						}
						if(temp == 'G')
						{
							tempStr = "GREEN"; 
							tempColor = GG;
						}
						if(temp == 'Y')
						{
							tempStr = "YELLOW";
							tempColor = YY;
						}
						if(temp == 'L')
						{
							tempStr = "BLUE";
							tempColor = BLBL;
						}
						if(temp == 'M')
						{
							tempStr = "MAGENTA";
							tempColor = MM;
						}
						if(temp == 'C')
						{
							tempStr = "CYAN"; 
							tempColor = CC;
						}
						if(temp == 'H')
						{
							tempStr = "WHITE"; 
							tempColor = WW;
						}
						if(temp == 127 || temp == 8)
						{
							temp = ' ';
							tempStr = "";
							tempColor = BB; 
						}

						valid = true;
					}
					if(valid)
					{
						PrintSelection(terminal, tempStr, posY, posX, c11,c12,c21,c22,temp, tempColor);
						valid = false; 
					}
				}
				PrintBoxSel(posY, posX, terminal); 
			}
			string primary = c11+c12;
			string secondary = c21+c22; 
			terminal.SetCustomColor(primary, true, true); 
			terminal.SetCustomColor(secondary, false, true); 

		}
		static void PrintBoxSel(int posY, int posX, Terminal &terminal)
		{
			
			int j = -6;
			int y = 22;
			if(posY == 1 && posX ==1)
			{
				terminal.PrintBox(39+j,5+y,46,6,46,6,RR,BB,false, false); 
				terminal.PrintBox(39+j,56+y,46,6,46,6,BB,BB,false, false); 
				terminal.PrintBox(46+j,5+y,46,6,46,6,BB,BB,false, false); 
				terminal.PrintBox(46+j,56+y,46,6,46,6,BB,BB,false, false); 
			}
			else if(posY ==1 && posX ==2)
			{
				terminal.PrintBox(39+j,56+y,46,6,46,6,RR,RR,false, false); 
				terminal.PrintBox(39+j,5+y,46,6,46,6,BB,BB,false, false); 
				terminal.PrintBox(46+j,5+y,46,6,46,6,BB,BB,false, false); 
				terminal.PrintBox(46+j,56+y,46,6,46,6,BB,BB,false, false); 
			}
			else if(posY ==2 && posX ==1)
			{
				terminal.PrintBox(46+j,5+y,46,6,46,6,RR,RR,false, false); 
				terminal.PrintBox(39+j,5+y,46,6,46,6,BB,BB,false, false); 
				terminal.PrintBox(39+j,56+y,46,6,46,6,BB,BB,false, false); 
				terminal.PrintBox(46+j,56+y,46,6,46,6,BB,RR,false, false); 
			}
			else if(posY ==2 && posX ==2) 
			{
				terminal.PrintBox(46+j,56+y,46,6,46,6,RR,RR,false, false); 
				terminal.PrintBox(39+j,5+y,46,6,46,6,BB,BB,false, false); 
				terminal.PrintBox(39+j,56+y,46,6,46,6,BB,BB,false, false); 
				terminal.PrintBox(46+j,5+y,46,6,46,6,BB,BB,false, false); 
			}
		}
		static void PrintSelection(Terminal &terminal, string tempStr, int posY, int posX, string &c11,string &c12, string &c21, string &c22, char temp, int tempColor)
		{
			if(posY == 1 && posX ==1)
			{
				string _tempStr;
				_tempStr.push_back(temp);
				if(_tempStr == "L")
				{
					_tempStr = "BL";
				}
				if(_tempStr == "H")
				{
					_tempStr = "W"; 
				}
				if(c12 == "" || _tempStr != c12)
				{
					c11 =""; 
					c11 = _tempStr; 
					terminal.PrintMultiChars("        ", 34,2+22); 
					terminal.SetColor(true, tempColor); 
					terminal.PrintMultiChars(tempStr,34,50+22-(tempStr.length()*6)); 
				}
			}
			else if(posY ==1 && posX ==2)
			{
				string _tempStr;
				_tempStr.push_back(temp);	
				if(_tempStr == "L")
				{
					_tempStr = "BL";
				}
				if(_tempStr == "H")
				{
					_tempStr = "W"; 
				}
				if(c11 == "" || c11 != _tempStr)
				{
					c12 =""; 
					c12 = _tempStr;
					terminal.PrintMultiChars("        ",34 ,59+22); 
					terminal.SetColor(true, tempColor); 
					terminal.PrintMultiChars(tempStr,34,59+22); 
				}
			}
			else if(posY ==2 && posX ==1)
			{
				c21 =""; 
				c21.push_back(temp);
				if(c21 == "L")
				{
					c21 = "BL";
				}
				if(c21 == "H")
				{
					c21 = "W"; 
				}
				terminal.PrintMultiChars("        ", 41,2+22); 
				terminal.SetColor(true, tempColor); 
				terminal.PrintMultiChars(tempStr,41,50+22-tempStr.length()*6); 
			}
			else if(posY ==2 && posX ==2) 
			{
				c22 =""; 
				c22.push_back(temp);
				if(c22 == "L")
				{
					c22 = "BL";
				}
				if(c22 == "H")
				{
					c22 = "W"; 
				}
				terminal.PrintMultiChars("        ", 41,59+22); 
				terminal.SetColor(true, tempColor); 
				terminal.PrintMultiChars(tempStr,41,59+22); 
			}
			if(c12 != "" && c11 !="")
			{
				string primary = c11+c12;
				int prim  = terminal.SetCustomColor(primary, true, false); 
				terminal.SetColor(true, prim); 
				terminal.PrintMultiChars("1ST:", 34,2); 
				terminal.SetColor(false, prim); 
			}
			if(c22 != "" && c21 !="")
			{
				string secondary = c21+c22; 
				int second  = terminal.SetCustomColor(secondary, false, false); 
				terminal.SetColor(true,second); 
				terminal.PrintMultiChars("2ND:", 41,2); 
				terminal.SetColor(false, second); 
			}

		}
		static bool ColorModeSelect(Terminal &terminal, bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names)
		{

			terminal.EraseAll();
			terminal.PrintColorScreen(true); 
			terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			terminal.UpdateTerminal();
			int position_temp = 1;
			terminal.PrintColorSelection(position_temp);
			int input = 1;
			//Display menu. have user select. Wriite difficulty to myGame object. 
			bool difFlag = false; 
			terminal.Revisited(0, 47, 0);
		       	terminal.PaintSnakeEasy(47,56); 	
		       	terminal.PrintHighScores(names, scoresNum); 	
			while(!difFlag && !myGame.QuitGame())
			{
				input = terminal.KeyPress();
				if(input == 's' || input == 'B')
				{
					if(position_temp<6)
					{
						position_temp ++;
						terminal.PrintColorSelection(position_temp);
					}
				}
				if(input == 'w' || input == 'A')
				{
					if(position_temp>1)
					{
						position_temp --;
						terminal.PrintColorSelection(position_temp);
					}
				}
				if (input == '\n')
				{
					if(position_temp == 6) 
					{
						//Custom Menu Selection; 
						CustomColorSelect(terminal,myGame, scoresNum, names);  
					}
					erase(); 
					difFlag = true; 
					enterFlag = false;
					terminal.OptionsScreen(true);
					terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
					terminal.UpdateTerminal(); 
					terminal.PrintSelection(position, 18); 
					terminal.Revisited(0, 41, 0);
		       			terminal.PaintSnakeEasy(41,56); 	
		       			terminal.PrintHighScores(names, scoresNum);	
				}
				else
				{
					HighLightSelection(WC,CC, position_temp, terminal, 6, false);
					terminal.PrintColorScreen(false); 	
				}
				if(input == 'q')
				{
					//Quit game completely. 
					myGame.SetQuitGame(true);
				}
			}
			return enterFlag;
		}


		static bool SizeModeSelect(Terminal &terminal, bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names)
		{
			terminal.EraseAll();  
			terminal.PrintSizeScreen(true); 
			terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			terminal.UpdateTerminal();
			int position_temp = 1;
			terminal.PrintSizeSelection(position_temp); //Print Dif Options 
			int input = 1;
			//Display menu. have user select. Wriite difficulty to myGame object. 
			bool difFlag = false; 
			terminal.Revisited(0, 29, 0);
		       	terminal.PaintSnakeEasy(29,56); 	
		       	terminal.PrintHighScores(names, scoresNum); 	
			terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			while(!difFlag && !myGame.QuitGame())
			{
				input = terminal.KeyPress(); 
				if(input == 's' && input == 'B')
				{
					if(position_temp<3)
					{
						position_temp ++;
						myGame.SetGameSize(terminal.PrintSizeSelection(position_temp)); //Print Dif Options 
					}
				}
				if(input == 'w' && input == 'A')
				{
					if(position_temp>1)
					{
						position_temp --;
						myGame.SetGameSize(terminal.PrintSizeSelection(position_temp)); //Print Dif Options 
					}
				}
				if (input == '\n')
				{
					myGame.SetGameSize(terminal.PrintSizeSelection(position_temp)); //Print Dif Options 
					terminal.EraseAll(); 
					difFlag = true; 
					enterFlag = false;
					terminal.OptionsScreen(true);
					terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
					terminal.UpdateTerminal(); 
					terminal.PrintSelection(position, 18); 
					terminal.Revisited(0, 41, 0);
		       			terminal.PaintSnakeEasy(41,56); 	
		       			terminal.PrintHighScores(names, scoresNum); 	
				}
				if(input == 'q')
				{
					myGame.SetQuitGame(true);
				}
				HighLightSelection(WC,CC, position_temp, terminal, 3, false);
				terminal.PrintSizeScreen(false); 

			}
			return enterFlag; 
		}

		static bool GameModeSelect(Terminal &terminal, bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names)
		{ 

			terminal.EraseAll(); 
			terminal.DifficultyScreen(true); 
			terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			terminal.UpdateTerminal();
			string dif = "Easy"; 
			int position_temp = 1;
			terminal.PrintDifficultySelection(position_temp); //Print Dif Options 
			int input = 1;
			//Display menu. have user select. Wriite difficulty to myGame object. 
			bool difFlag = false; 
			terminal.Revisited(0, 29, 0);
		       	terminal.PaintSnakeEasy(29,56); 	
		       	terminal.PrintHighScores(names, scoresNum); 	
			while(!difFlag && !myGame.QuitGame())
			{
				input = terminal.KeyPress(); 
				if(input == 's' || input == 'B')
				{
					if(position_temp<3)
					{
						position_temp ++;
						dif = terminal.PrintDifficultySelection(position_temp); //Print Dif Options 
					}
				}
				if(input == 'w' || input == 'A')
				{
					if(position_temp>1)
					{
						position_temp --;
						dif = terminal.PrintDifficultySelection(position_temp); //Print Dif Options 
					}
				}
				if (input == '\n')
				{
					myGame.SetDifficulty(dif); 
					terminal.EraseAll(); 
					difFlag = true; 
					enterFlag = false;
					terminal.OptionsScreen(true);
					terminal.PrintCurrentSettings(myGame.GetGameSize("S"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
					terminal.UpdateTerminal(); 
					terminal.PrintSelection(position, 18); 
					terminal.Revisited(0, 41, 0);
		       			terminal.PaintSnakeEasy(41,56); 	
		       			terminal.PrintHighScores(names, scoresNum); 	
				}
				else 
				{
				HighLightSelection(WC,CC, position_temp, terminal, 3, false);
				terminal.DifficultyScreen(false);
				}
				if(input == 'q')
				{
					myGame.SetQuitGame(true);
				}
			}
			return enterFlag; 
		}


		static string OptionsSelect(Terminal &terminal, Settings &myGame, int * scoresNum, string * names)
		{
			int clear = 30;
			string selection = "";
			bool enterFlag = false;
			int input = 1;
			int position = 1; 
			terminal.Revisited(0, 41, 0);
		       	terminal.PaintSnakeEasy(41,56); 	
			terminal.PrintSelection(position, clear);
		       	terminal.PrintHighScores(names, scoresNum); 	
			terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			while(selection != "Return" && !myGame.QuitGame()) //We dont want to return to the main menu until "return" 
			{
				while(!enterFlag && !myGame.QuitGame())
				{
					input = terminal.KeyPress(); 
					if(input == 's' || input == 'B')
					{
						if(position <5)
						{
							position++;
							terminal.PrintSelection(position, clear); 
						}
					}
					else if(input == 'w' || input == 'A')
					{
						if(position>1)
						{
							position--;
							terminal.PrintSelection(position, clear);
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
					HighLightSelection(WC,CC, position, terminal, 5, false);
					terminal.OptionsScreen(false); 


				//	erase();
				}
				if(position == 1)
				{
					myGame.SetGameType(1); 
					enterFlag = GameModeSelect(terminal, enterFlag, position, myGame, scoresNum, names);
				}
				else if (position ==2)
				{
					myGame.SetGameType(2); 
					enterFlag = GameModeSelect(terminal, enterFlag, position, myGame, scoresNum, names);
				}
				else if (position ==3)
				{
					enterFlag = ColorModeSelect(terminal, enterFlag, position, myGame, scoresNum, names); 	
				}
				else if (position ==4)
				{
					enterFlag = SizeModeSelect(terminal, enterFlag, position, myGame, scoresNum, names); 
				}
				else if (position ==5)
				{
					terminal.EraseAll(); 
				//	myGame.MainScreen(); 
					terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
					selection = "Return"; 
				}
			}	
			//Print the main menu and return a string option. 
			return selection;
		}
		static bool ShowScores(Terminal &terminal, Settings myGame, ScoreKeeper &scores)
		{
			bool quitFlag = false; 
			terminal.EraseAll(); 	
			string names [6]; 
			int scoresNum[6]; 
			bool enterFlag = false;
			scores.GetHighScores(scoresNum, names); 
			terminal.PrintHighScoreScreen(names, scoresNum);
			terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			int printXPosition = 4; 
			int printYPosition = 26;
		       	terminal.PrintBox(18,2,56, 15, 56, 15, RR, WW, false, true); 
		       	terminal.PrintBox(35,2,56, 15, 56, 15, RR, WW, false, true); 
			terminal.SetColor(true, BW);
			terminal.PrintString(19, 20, "Old School Scores");		
			terminal.PrintString(36, 20, "New School Scores");		
			terminal.PrintString(21, 5, "Easy");		
			terminal.PrintString(21, 26, "Hard");		
			terminal.PrintString(21, 44, "2020");		
			terminal.PrintString(38, 5, "Easy");		
			terminal.PrintString(38, 26, "Hard");		
			terminal.PrintString(38, 44, "2020");		
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
				string *stgScores = terminal.StringToInt(intScores, 10);
				string *names = scores.GetNames(i);
				for(int j = 0;j<10;j++)
				{
					string gap(10-stgScores[j].length(), '_'); 
					string temp;
					if(names[j] != "")
						temp = stgScores[j] + gap +" (" + names[j] +")";
					else
						temp = stgScores[j] + gap;
					terminal.PrintString(printYPosition, printXPosition, temp); 
					printYPosition++; 
				}
				printXPosition = printXPosition + 18;
			       if(i == 3)
					printXPosition = printXPosition + 4;
			}
			
			terminal.SetColor(false, BW);
			terminal.PrintString(53,2, "Select \"Enter\" to return to the main menu.");
			terminal.UpdateTerminal();

			while(!enterFlag && !myGame.QuitGame())
			{	
				int input = terminal.KeyPress(); 
				if(input == 'q')
				{
					quitFlag = true; 
					break; 
				}
				else if(input == '\n')
				{
					enterFlag = true;
					erase(); 
				}
			}
			return quitFlag; 

		}
		static string menuSelection(Terminal &terminal, Settings &myGame, string *names, int *scores)
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
			int slowDownMore = 0; 
			int length = 10;
			terminal.MainScreen(names, scores); 
			terminal.PrintCurrentSettings(myGame.GetGameSize("s"), myGame.GetGameType(), myGame.GetDifficultyStr(), myGame.ScoreMultiplier(), 60, 1);  
			terminal.UpdateTerminal();
			bool snakeB = true; 
			terminal.PrintSelection(position, 18);
			terminal.SetPaintSnake(0); 
			while(!enterFlag && !myGame.QuitGame())
			{
					
				if(x != 0)
					terminal.Revisited(x,y, length); 
				slowDown++;
				if(slowDown != 0)
				{
					if(slowDown == 60)
					{
						slowDown = 0;
					}
				}
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
							slowDownMore++;
							if(slowDownMore == 7)
							{
								terminal.PaintSnake(y, 57); 
								slowDownMore = 0;
							}
							snakeB = false;
						}	
						else
						{
							snakeB = true; 
						}
					}
				}
				input = terminal.KeyPress(); 
				switch (input)
				{
					case 's':
						if(position < 3) //Then we're not at the bottom of the menu 
						{
							position++;
							terminal.PrintSelection(position, 18);
						}
						w = false;
						s = false;
					break;
					case 'B':
						if(position < 3) //Then we're not at the bottom of the menu 
						{
							position++;
							terminal.PrintSelection(position, 18);
						}
						w = false;
						s = false;
					break;
					case 'A':
						if(position > 1)
						{
							position--;
							terminal.PrintSelection(position,18);
						}	
						w =false;
						s =false; 
					break; 
				
					case 'w':
						if(position > 1)
						{
							position--;
							terminal.PrintSelection(position,18);
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
				HighLightSelection(WC,CC, position, terminal, 3, false);
				terminal.MainScreen(); 
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
		static void HighLightSelection(int _boarder, int _fill, int position, Terminal &terminal, int maxPosi, bool color)
		{ 
			int boarder, fill;
			if(color)
			{
				//Wrote logic bacwards for how it actually prints.
				boarder = _fill; 
				fill = _boarder; 
			}
			else
			{
				fill = terminal.GetCurrentPrimaryColor();
			       	boarder = terminal.GetCurrentSecondColor(); 
			}
	
			
			int x = 0; 
			int len = 63;
			int ht = 6;
			if(position == 1)
			{
				if(maxPosi>1)
					terminal.PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>2)
					terminal.PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>3)
					terminal.PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>4) 
					terminal.PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>5) 
					terminal.PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>6) 
					terminal.PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>7) 
					terminal.PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(10,x,len,ht,len,ht,boarder,fill,false,true);
			}
			else if(position == 2)
			{
				terminal.PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>2)
					terminal.PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>3)
					terminal.PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>4) 
					terminal.PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>5) 
					terminal.PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>6) 
					terminal.PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>7) 
					terminal.PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(16,x,len,ht,len,ht,boarder,fill,false,true);
			}
			else if(position == 3)
			{
				terminal.PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>3)
					terminal.PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>4) 
					terminal.PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>5) 
					terminal.PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>6) 
					terminal.PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>7) 
					terminal.PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(22,x,len,ht,len,ht,boarder,fill,false,true);
			}
			else if(position == 4)
			{
				terminal.PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>4) 
					terminal.PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>5) 
					terminal.PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>6) 
					terminal.PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>7) 
					terminal.PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(28,x,len,ht,len,ht,boarder,fill,false,true);
			}
			else if(position == 5)
			{
				terminal.PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>5) 
					terminal.PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>6) 
					terminal.PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>7) 
					terminal.PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(34,x,len,ht,len,ht,boarder,fill,false,true);
			}
			else if(position == 6)
			{
				terminal.PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>6) 
					terminal.PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>7) 
					terminal.PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(40,x,len,ht,len,ht,boarder,fill,false,true);
			}
			else if(position == 7)
			{
				terminal.PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
				if(maxPosi>7) 
					terminal.PrintBox(52,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(46,x,len,ht,len,ht,boarder,fill,false,true);
			}
			else if(position == 8)
			{
				terminal.PrintBox(10,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(16,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(22,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(28,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(34,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(40,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(46,x,len,ht,len,ht,BB,BB,false,true);
				terminal.PrintBox(52,x,len,ht,len,ht,boarder,fill,false,true);
			}
		}
};

#endif
