#ifndef SCORE_MNG
#define SCORE_MNG

#include <iostream> 
#include <string>
#include <fstream>
#include <sstream>
#define OE 1
#define OH 2
#define O2 3
#define NE 4
#define NH 5
#define N2 6
using namespace std; 

class ScoreKeeper
{
	private: 
		int scores[6];
		string names[6];
		int currentGame; 
		int oldSchoolEasy[11] = {0}; //<<<<< ---- WHY DID I DO IT THIS WAY??? Change it to 2D Array. 
		int oldSchoolHard[11] = {0};
		int oldSchool2020[11] = {0};
		int newSchoolEasy[11] = {0};
		int newSchoolHard[11] = {0};
		int newSchool2020[11] = {0};
		string oldSchoolEasyName[11];//= {0};
		string oldSchoolHardName[11];//= {0};
		string oldSchool2020Name[11];//= {0};
		string newSchoolEasyName[11];//= {0};
		string newSchoolHardName[11];//= {0};
		string newSchool2020Name[11];//= {0};
		string securityBlock[100] = {""}; 
		void WriteToString(string readIn, int linNum); 
		int ParseInput(string& input);
		bool IsEmpty(ifstream& fileE);
	        bool FileCheck(string fileName); 	
		bool CheckScore(int *score, int name);
		void SortScore(int *score, string *name);
		void SwapScore(int &posA, int &posB); 
		void SwapName(string &posA, string &posB); 
		string WriteScores(string *names, int *scores);
		stringstream WriteDif(string *names,  int *score, int index);
		void WriteDif(string toWrite, string names,  int score, int index);
		void PreLoadTest(string *names, int *scores); 
		void ReadScores(string fileName); 	
		void ReadSecurity(string fileName);
		void PreLoadSecurity(); 		

		//Check if a file excists 
		//Make sure we can read and write to directory (if not, give notice to player that the scores will not be saved. 
		//Read in from file if it excists 
		//If not, make one. 
		//Read eveything into a string. Several categories
		//   - Old School: Easy, Hard, 2020
		//   - New School: Easy Hard, 2020 


	public: 
		ScoreKeeper();
		bool SecurityCheck(string intials); 
		void GetHighScores(int *scores, string *names); 
		void ReadFile(string fileName); 
		bool HighScoreCheck(int check, int newSchool, string gameDif); 
		void AssignScore(string intials); //Only takes a string and assigns it if a high score has been detected. 
		int GetScore(int index, int GameType, string& initials); 	
		void PublicWrite(string type); 
		void ReadStart(string fileName); 
		int* GetStringScore(int type);
		string* GetNames(int GameType);
};


#endif 
