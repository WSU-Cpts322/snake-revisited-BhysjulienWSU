#ifndef FILEIO
#define FILEIO 
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>

using namespace std; 
class FileIO
{
	private:
		bool doit = true; 
		string password = "";
		int passwordLen; 
		int scores[6][11] = {0};
		string names[6][11];
		void ReadSecurity(string fileName);
		string ConvertToUp(string readTemp); //convert all data to uppder case. 
		void PreLoadSecurity(); //Data for when program is ran for first time. 
		void PreLoadTest(); //preload scores for whhen the program is ran for the first time. 
		void ReadScores(string fileName); //Read scores to local variable
		string WriteScores(); //Write scores to file 
	        bool FileCheck(string fileName); //Check if the file exists 	
		void WriteToString(string readIn, int linNum);  //Read name and score, call parsing method, and ready data for writing. 
		bool IsEmpty(ifstream& fileE); //Checks if the file is empty 
		string securityBlock[100] = {""}; 
		int ParseInput(string& input); //Parses name and scores 
		stringstream WriteDif(int indexR, int indexB);
	public: 		
		void ReadFile(string fileName);  
		void PublicWrite(string type); //Public method for calling private writer 
		void ReadStart(string fileName); //public method for calling private reader 
		int getScore(int indexR, int indexC); //Provides the value of a score, given difficulty and place
		string getName(int indexR, int indexC); //Provides the value of a name, given difficulty and place
		void setScore(int indexR, int indexC, int value); //Read in most recent score. 
		void setName(int indexR, int indexC, string name); //Read in most recent name
		void SortScore(int index); //Bubble sort for when high score is met. 
		void SwapScore(int &posA, int&posB); //Bubble sort support .
		void SwapName(string &posA, string &posB);//bubble sort support 
		string getSecBlock(int index); 
		void setSecBlock(int index, string initials); 
		string getPassword();
		void setPassword(string token); 
		int getPasswordLen();
};



#endif
