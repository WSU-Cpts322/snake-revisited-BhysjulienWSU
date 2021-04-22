#ifndef SCORE_MNG
#define SCORE_MNG

#include <iostream> 
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include "fileIO.h" 
#define OE 1
#define OH 2
#define O2 3
#define NE 4
#define NH 5
#define N2 6
using namespace std; 

class ScoreKeeper: public FileIO 
{
	private: 
		int hscores[6];
		string hnames[6];
		int currentGame; 
		string tempArray[10];
		int temp[10];
		int scores[6][11] = {0};
		string names[6][11];
		bool CheckScore(int index, int playerScore); //TODO


	public:
		ScoreKeeper();
		bool SecurityCheck(string intials);//Checks if the score can be assigned to high scores  
		void GetHighScores(int *hscores, string *hnames); //returns all hig hscores and names. 
		bool HighScoreCheck(int check, int newSchool, string gameDif); 
		void AssignScore(string intials); //Only takes a string and assigns it if a high score has been detected. 
		int GetScore(int index, int GameType, string& initials); 	
		int* GetArrayScore(int type);
		string* GetNames(int GameType);
};


#endif 
