#include "scoreManager.h"

ScoreKeeper::ScoreKeeper()
{
}
void ScoreKeeper::GetHighScores(int *hscores, string *hnames)
{
	for(int i = 0; i<6; i++)
	{
		hscores[i] = getScore(i,0);
		hnames[i] = getName(i,0);
	}
}	
bool ScoreKeeper::HighScoreCheck(int score, int newSchool, string gameDif) //return true if a highscore was achieved. 
{
	bool beatScore;
	if(newSchool == 1) //Then the game is oldSchool 
	{
		if(gameDif == "Easy")
		{
			beatScore = CheckScore(0, score); 
			if(beatScore)
				currentGame = OE; 
		}
		else if(gameDif == "Hard")
		{
			beatScore = CheckScore(1, score); 
			if(beatScore)
				currentGame = OH;
		}
		else if(gameDif == "2020")
		{
			beatScore = CheckScore(2, score);
			if(beatScore)
				currentGame = O2;
		}
	}
	else if(newSchool == 2) //Then the game is newSchool 
	{
		if(gameDif == "Easy")
		{
			beatScore = CheckScore(3,score); 
			if(beatScore)
				currentGame = NE;
		}
		else if(gameDif == "Hard")
		{
			beatScore = CheckScore(4, score); 
			if(beatScore)
				currentGame = NH;
		}
		else if(gameDif == "2020")
		{			
			beatScore = CheckScore(5, score); 
			if(beatScore)
				currentGame = N2;
		}
	}
	return beatScore; 
}
bool ScoreKeeper::CheckScore(int index, int playerScore)
{
	bool beatScore = false;
       	setScore(index,10,playerScore);	
 	if(getScore(index,9) < getScore(index,10)) //Then they beat a high score. We just don't know which one. 
	{
		beatScore = true; 	
	}
	return beatScore; 
}

void ScoreKeeper::AssignScore(string intials)
{
	switch (currentGame)
	{
		case OE:
			setName(0,10,intials);
			SortScore(0);
		break;

		case OH:
			setName(1,10,intials);
			SortScore(1);
		break;

		case O2:
			setName(2,10,intials);
			SortScore(2);
		break;

		case NE:
			setName(3,10,intials);
			SortScore(3);
		break;

		case NH:
			setName(4,10,intials);
			SortScore(4);
		break;

		case N2:
			setName(5,10,intials);
			SortScore(5);
		break; 

		default: 
			currentGame = 0; 
		break; 
	}	
}


int ScoreKeeper::GetScore(int index, int GameType, string& initials)
{
	int score;
	if(index >= 10)
	{
	}
	switch (GameType)
	{
		case OE:
			initials = getName(OE-1,index);
			score = getScore(OE-1,index);
		break;

		case OH:
			initials = getName(OH-1,index);
			score = getScore(OH-1,index);
		break;

		case O2:
			initials = getName(O2-1,index);
			score = getScore(O2-1,index);
		break;

		case NE:
			initials = getName(NE-1,index);
			score = getScore(NE-1,index);
		break;

		case NH:
			initials = getName(NH-1,index);
			score = getScore(NH-1,index);
		break;

		case N2:
			initials = getName(N2-1,index);
			score = getScore(N2-1,index);
		break; 
	}
	return score; 
}
int* ScoreKeeper::GetArrayScore(int GameType)
{
	if(GameType>6 || GameType < 1)
	{}
	for(int j =0; j<10;j++)
	{
		temp[j] = getScore(GameType-1, j); 
	}
	return temp;
}

string* ScoreKeeper::GetNames(int GameType)
{
	if(GameType>6 || GameType < 1)
	{}
	for(int j =0; j<10;j++)
	{
		tempArray[j] = getName(GameType-1, j); 
	}
	return tempArray; 
}	
