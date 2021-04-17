#ifndef GAMEMAP
#define GAMEMAP 
#include<map>
#include<string>
#include<iostream>
#include "terminal.h" 

class GameMap: public Terminal
{
	private:
	void PrintWSUGameBoard()
	{
		SetColor(true, WR); 

		for(int i = 2; i<=21; i++)
		{
			mvvline(2,i,' ',34); 
		}
		for(int i = 0; i<=19; i++)
		{
			mvvline(2,38+i,' ',34); 
		}
		for(int i = 0; i<3; i++)
		{
			mvvline(2,79+i,' ',8); 
			mvvline(14,79+i,' ',10); 
			mvvline(28,79+i,' ',8); 
		}
		for(int i = 0; i<12;i++)
		{
			mvvline(28,126+i,' ',8); 
		}

		for(int i = 0; i< 4; i++)
		{
			mvvline(28-i, 22+i, ' ', 8+i);
			mvvline(28-i, 37-i, ' ', 8+i);
			mvvline(24-i, 26+i, ' ', 11);
			mvvline(24-i, 33-i, ' ', 11);
		}
		for(int i = 58; i<=57; i++)
		{
			mvvline(2,i,' ',34); 
		}
		for(int i = 0; i<5; i++)
		{
			mvvline(28,58+i,' ',8); 
			mvvline(2,98+i,' ',8); 
		}
		for(int i = 0; i<16; i++)
		{
			mvvline(2,63+i,' ',22); 
			mvvline(2,82+i,' ',8); 
			mvvline(28,63+i,' ',8); 
			mvvline(14,82+i,' ',22); 
		}
		for(int i = 0; i<23; i++)
		{
			mvvline(2,103+i,' ',34); 
		}
		for(int i = 0; i<24; i++)
		{
			mvvline(2,138+i,' ',34); 
		}
		SetColor(false, WR); 
		SetColor(true, WW); 
	//Boarder. Print in RR
		mvhline(1,1,'X',22); //Top W
		mvhline(1,37,'X',22);//Top W
		mvhline(1,62,'X',65);//Top S
		mvhline(1,137,'X',26);//Top U
		mvvline(2,1,'X',34); //Left W
		mvvline(2,22,'X',26); //Mid Left W
		mvvline(2,37,'X',26); //Mid rigt W
		mvvline(2,58,'X',25); //Right W
		mvvline(2,62,'X',22);//Left S
		mvvline(25,81,'X',2); // Middle bottom S
		mvvline(11,79,'X',2); // Middle top S
		mvhline(27,58,'X',24);//Middle BottomS
		mvhline(24,62,'X',20);//Middle Bottom S
		mvhline(10,79,'X',24);//Middle BottomS
		mvhline(13,79,'X',20);//Middle Bottom S
		mvvline(14,98,'X',22); //Right S
		mvvline(11,102,'X',25); //left U
		mvvline(2,126,'X',25); //Middle Left U 
		mvvline(2,137,'X',25); //Middel Right U
		mvvline(2,162,'X',34); //Right U
		mvhline(27,126,'X',12);//Middle U
		mvhline(36,1,'X',25);//Bottom W
		mvhline(36,34,'X',65);//Bottom W/S
		mvhline(36,102,'X',61);//Bottom W/S
		mvhline(26,23,'X',1);//W
		mvhline(25,24,'X',1);//W
		mvhline(24,25,'X',1);//W
		mvhline(23,26,'X',1);//W
		mvhline(22,27,'X',1);//W
		mvhline(21,28,'X',1);//W
		mvhline(20,29,'X',2);//W
		mvhline(21,31,'X',1);//W
		mvhline(22,32,'X',1);//W
		mvhline(23,33,'X',1);//W
		mvhline(24,34,'X',1);//W
		mvhline(25,35,'X',1);//W
		mvhline(26,36,'X',1);//W
		mvhline(35,26,'X',1);//W
		mvhline(34,27,'X',1);//W
		mvhline(33,28,'X',1);//W

		mvhline(32,29,'X',2);//W
		mvhline(33,31,'X',1);//W
		mvhline(34,32,'X',1);//W
		mvhline(35,33,'X',1);//W
		mvhline(25,333,'X',1);//W

		SetColor(false, WW);
		SetColor(true, BB);
		mvhline(26-2,36+25,'X',1);//W
		mvhline(26-1-12,40+1+34+24,'X',1);//W
		SetColor(false,BB); 
	}	
	public: 
	void PrintBoard(string gameTypeString, int width, int height)
	{
		if(gameTypeString == "WSU School")
		{
			//Call print WSU gameboard. 
			PrintWSUGameBoard(); 	
		}
		else
		{
			PrintBox(1,1,1,1,width, height, GetCurrentSecondColor(), GetCurrentPrimaryColor(), true, true); //myGame.GetCurrentColor()); 
		}
	}
};


#endif 
