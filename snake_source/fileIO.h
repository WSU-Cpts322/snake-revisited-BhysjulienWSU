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
		string password = "";
		int passwordLen; 
		int scores[6][11] = {0};
		string names[6][11];
		void ReadSecurity(string fileName);
		string ConvertToUp(string readTemp); 	
		void PreLoadSecurity(); 	
		void PreLoadTest(); 
		void ReadScores(string fileName); 	
		string WriteScores();
	        bool FileCheck(string fileName); 	
		void WriteToString(string readIn, int linNum); 
		bool IsEmpty(ifstream& fileE);
		string securityBlock[100] = {""}; 
		int ParseInput(string& input);
		stringstream WriteDif(int indexR, int indexB);
	public: 		
		void ReadFile(string fileName); 
		void PublicWrite(string type); 
		void ReadStart(string fileName); 
		int getScore(int indexR, int indexC);
		string getName(int indexR, int indexC);
		void setScore(int indexR, int indexC, int value); 
		void setName(int indexR, int indexC, string name); 
		void SortScore(int index);
		void SwapScore(int &posA, int&posB); 
		void SwapName(string &posA, string &posB);
		string getSecBlock(int index); 
		void setSecBlock(int index, string initials); 
		string getPassword();
		void setPassword(string token); 
		int getPasswordLen();
};



#endif
