#include "scoreManager.h"

ScoreKeeper::ScoreKeeper()
{
}

void ScoreKeeper::ReadStart(string fileName)
{
	ReadFile(fileName); 
}

bool ScoreKeeper::FileCheck(string fileName)
{
	bool check = false; 
	if(ifstream(fileName))
	{
		check = true; 			
	}
	if(check == false)
	{
		ofstream fileCheck(fileName);
		if(!fileCheck)
		{
			check = false; 
		}
		else
		{
			check = true; 
			fileCheck.close(); //Sore the files 
		}

	}
	return check; 
}
void ScoreKeeper::GetHighScores(int *scores, string *names)
{
	scores[0] = oldSchoolEasy[0];//TODO I really should have put these values in an 2D array
	scores[1] = oldSchoolHard[0];
	scores[2] = oldSchool2020[0];
	scores[3] = newSchoolEasy[0];
	scores[4] = newSchoolHard[0];
	scores[5] = newSchool2020[0];
	names[0] = oldSchoolEasyName[0];
	names[1] = oldSchoolHardName[0];
	names[2] = oldSchool2020Name[0];
	names[3] = newSchoolEasyName[0];
	names[4] = newSchoolHardName[0];
	names[5] = newSchool2020Name[0];
}	
bool ScoreKeeper::IsEmpty(ifstream& fileE)
{
	return fileE.peek() == ifstream::traits_type::eof(); 
}
int ScoreKeeper::ParseInput(string& input)
{
	int score;
	string delimiter = " ";
	string temp = input.substr(0,input.find(delimiter)); //Now the int value should be in the string. 
	input.erase(0, input.find(delimiter) + delimiter.length()); //Remove the score value from the string. 
	input = input.substr(0,3); 
	stringstream temp_stream(temp);
	temp_stream >> score; 

	return score; 
}
void ScoreKeeper::WriteToString(string readIn, int linNum)
{
	int i = linNum; 
	 if(i<10 && readIn != "")
	 {
		oldSchoolEasy[i] =  ParseInput(readIn); 
		oldSchoolEasyName[i] = readIn; 
	 }
	 else if(i<20 && readIn != "")
	 {
		oldSchoolHard[i-10] =  ParseInput(readIn); 
		oldSchoolHardName[i-10] = readIn; 
	 }
	 else if(i<30 && readIn !="")
	 {
		oldSchool2020[i-20] =  ParseInput(readIn); 
		oldSchool2020Name[i-20] = readIn; 
	 }
	 else if(i<40 && readIn !="")
	 {
		newSchoolEasy[i-30] =  ParseInput(readIn); 
		newSchoolEasyName[i-30] = readIn; 
	 }
	 else if(i<50 && readIn !="")
	 {
		newSchoolHard[i-40] =  ParseInput(readIn); 
		newSchoolHardName[i-40] = readIn; 
	 }
	 else if(i<60 && readIn != "")
	 {
		newSchool2020[i-50] =  ParseInput(readIn); 
		newSchool2020Name[i-50] = readIn;
	 }	
}
void ScoreKeeper::ReadScores(string fileName)
{
	int i = 0; 
	string readTemp; 
	ifstream fileIn;
	fileIn.open(fileName, ifstream::in);
	while(std::getline(fileIn, readTemp))
	{
		if(readTemp == "OldEasy") //Then header was found 
		{
			i = 0;
			std::getline(fileIn,readTemp);//Get new line
		}
		if(readTemp == "OldHard")
		{
			i = 10;
			std::getline(fileIn,readTemp);//Get new line
		}
		if(readTemp == "Old2020")
		{
			i = 20;
			std::getline(fileIn,readTemp);//Get new line
		}
		if(readTemp == "NewEasy")
		{
			i = 30;
			std::getline(fileIn,readTemp);//Get new line
		}
		if(readTemp == "NewHard")
		{
			i = 40;
			std::getline(fileIn,readTemp);//Get new line
		}
		if(readTemp == "New2020")
		{
			i = 50;
			std::getline(fileIn,readTemp);//Get new line
		}
		WriteToString(readTemp, i); 
		i++;
	}
}
void ScoreKeeper::ReadSecurity(string fileName)
{
	int i = 0; 
	string readTemp; 
	ifstream fileIn; 
	fileIn.open(fileName,ifstream::in);
	while(std::getline(fileIn,readTemp))
	{	
		securityBlock[i] = readTemp; 	
	}
}
void ScoreKeeper::ReadFile(string fileName)
{
	bool fileCheck = FileCheck(fileName); 
	bool emptyCheck = false; 

	if(fileCheck) //The file is there. Lets see if its empty 
	{
		ifstream fileIn;
		fileIn.open(fileName, ifstream::in);
		emptyCheck = IsEmpty(fileIn); 
		if(!emptyCheck) //Then there is content. Lets read it in. 
		{
			if(fileName == "scores")
			{
				ReadScores(fileName); 
			}
			else if(fileName == "security")
			{
				ifstream fileIn;
				fileIn.open(fileName, ifstream::in);
				string readTemp; 
				int j = 0; 
				while(std::getline(fileIn,readTemp)&& j<100)
				{
					securityBlock[j]= readTemp;
					j++;
				}
					
			}
			fileIn.close();
		}
		else 
		{
			if(fileName == "scores")
			{
				PreLoadTest(oldSchoolEasyName, oldSchoolEasy);
				PreLoadTest(oldSchoolHardName, oldSchoolHard);
				PreLoadTest(newSchoolEasyName, newSchoolEasy);
				PreLoadTest(newSchoolHardName, newSchoolHard);
			}
			else if(fileName == "security")	
			{
				PreLoadSecurity(); 
			}
		}
	}
}
bool ScoreKeeper::SecurityCheck(string intials)
{
	bool check = false; 
	int i =0;
	while(securityBlock[i] != "" && i < 100)
	{
		if(securityBlock[i] == intials)
			check = true;
		i++;
		if(i == 100) break; 
	}
	return check; 
}
void ScoreKeeper::PreLoadSecurity()
{
	securityBlock[0] = "BLL"; 
	securityBlock[1] = "ABC"; 
	securityBlock[3] = "DEF";
	securityBlock[4] = "BL "; 
}
void ScoreKeeper::PreLoadTest(string * names, int *score)
{
	score[0] = 100000;
	score[1] = 10000;
	score[2] = 10; 
	names[0] = "BDH";
	names[1] = "BDH";
	names[2] = "BDH"; 

}
bool ScoreKeeper::HighScoreCheck(int score, int newSchool, string gameDif) //return true if a highscore was achieved. 
{
	bool beatScore;
	if(newSchool == 1) //Then the game is oldSchool 
	{
		if(gameDif == "Easy")
		{
			beatScore = CheckScore(oldSchoolEasy, score); 
			if(beatScore)
				currentGame = OE; 
		}
		else if(gameDif == "HARD")
		{
			beatScore = CheckScore(oldSchoolHard, score); 
			if(beatScore)
				currentGame = OH;
		}
		else if(gameDif == "2020")
		{
			beatScore = CheckScore(oldSchool2020, score);
			if(beatScore)
				currentGame = O2;
		}
	}
	else if(newSchool == 2) //Then the game is newSchool 
	{
		if(gameDif == "Easy")
		{
			beatScore = CheckScore(newSchoolEasy,score); 
			if(beatScore)
				currentGame = NE;
		}
		else if(gameDif == "HARD")
		{
			beatScore = CheckScore(newSchoolHard, score); 
			if(beatScore)
				currentGame = NH;
		}
		else if(gameDif == "2020")
		{			
			beatScore = CheckScore(newSchool2020, score); 
			if(beatScore)
				currentGame = N2;
		}
	}
	return beatScore; 
}
bool ScoreKeeper::CheckScore(int *score, int playerScore)
{
	score[10] = playerScore; 
 	if(score[9] < score[10]) //Then they beat a high score. We just don't know which one. 
	{
		return true; 	
	}
	return false; 
}

void ScoreKeeper::AssignScore(string intials)
{
	switch (currentGame)
	{
		case OE:
			oldSchoolEasyName[10] = intials; 
			SortScore(oldSchoolEasy, oldSchoolEasyName);
		break;

		case OH:
			oldSchoolHardName[10] = intials; 
			SortScore(oldSchoolHard, oldSchoolHardName);
		break;

		case O2:
			oldSchool2020Name[10] = intials; 
			SortScore(oldSchool2020, oldSchool2020Name);
		break;

		case NE:
			newSchoolEasyName[10] = intials; 
			SortScore(newSchoolEasy, newSchoolEasyName);
		break;

		case NH:
			newSchoolHardName[10] = intials; 
			SortScore(newSchoolHard, newSchoolHardName);
		break;

		case N2:
			newSchool2020Name[10] = intials; 
			SortScore(newSchool2020, newSchool2020Name);
		break; 

		default: 
			currentGame = 0; 
		break; 
	}	
}

void ScoreKeeper::SortScore(int* score, string* name)
{
	for(int i = 0; i<=10; i++)
	{
		for(int j = 0; j<=10-i-1; j++)
		{
			if(score[j] < score[j+1])//Then swap 
			{
				SwapScore(score[j], score[j+1]);
				SwapName(name[j], name[j+1]); 
			}
					
		}
	
	}
}

void ScoreKeeper::SwapScore(int &posA, int &posB)
{
	int temp;
	temp = posA;
	posA = posB;
	posB = temp; 
}
void ScoreKeeper::SwapName(string &posA, string &posB)
{
	string temp;
	temp = posA;
	posA = posB;
	posB = temp; 
}

int ScoreKeeper::GetScore(int index, int GameType, string& initials)
{
	int score;
	if(index >= 10)
	{
		return -1; 
	}
	switch (GameType)
	{
		case OE:
			initials = oldSchoolEasyName[index];
			score = oldSchoolEasy[index];
		break;

		case OH:
			initials = oldSchoolHardName[index]; 
			score = oldSchoolHard[index];
		break;

		case O2:
			initials = oldSchool2020Name[index]; 
			score = oldSchool2020[index];
		break;

		case NE:
			initials  = newSchoolEasyName[index]; 
			score = newSchoolEasy[index];
		break;

		case NH:
			initials = newSchoolHardName[index]; 
			score = newSchoolHard[index]; 
		break;

		case N2:
			initials = newSchool2020Name[index]; 
			score = newSchool2020[index];
		break; 
	}
	return score; 
}
int* ScoreKeeper::GetStringScore(int GameType)
{
	switch (GameType)
	{
		case OE:
			return oldSchoolEasy;
		break;

		case OH:
			return  oldSchoolHard; 
		break;

		case O2:
			return  oldSchool2020; 
		break;

		case NE:
			return  newSchoolEasy; 
		break;

		case NH:
			return newSchoolHard; 
		break;

		case N2:
			return newSchool2020; 
		break; 
	}
	return 0; 
}

string* ScoreKeeper::GetNames(int GameType)
{
	switch (GameType)
	{
		case OE:
			return oldSchoolEasyName;
		break;

		case OH:
			return  oldSchoolHardName; 
		break;

		case O2:
			return  oldSchool2020Name; 
		break;

		case NE:
			return  newSchoolEasyName; 
		break;

		case NH:
			return newSchoolHardName; 
		break;

		case N2:
			return newSchool2020Name; 
		break;

		default:
		break; 

	}
	return oldSchoolEasyName; 
}	

void ScoreKeeper::PublicWrite(string type)
{
	if(type == "scores")
	{
		stringstream allScores; 
		allScores << "OldEasy";
		allScores << "\n" <<WriteScores(oldSchoolEasyName, oldSchoolEasy);//Write all the data to a single string, including newLines.  
		allScores << "\nOldHard"; 
		allScores << "\n" << WriteScores(oldSchoolHardName, oldSchoolHard); 
		allScores << "\nOld2020"; 
		allScores << "\n" << WriteScores(oldSchool2020Name, oldSchool2020); 
		allScores << "\nNewEasy"; 
		allScores << "\n" << WriteScores(newSchoolEasyName, newSchoolEasy); 
		allScores << "\nNewHard";
		allScores << "\n" << WriteScores(newSchoolHardName, newSchoolHard); 
		allScores << "\nNew2020";
		allScores << "\n" << WriteScores(newSchool2020Name, newSchool2020); 
		ofstream fileOut("scores");
		fileOut << allScores.rdbuf(); 
		fileOut.close(); 
	}
	else if(type == "security")
	{
		int index =0; 
		stringstream baddies;
	       	while(index < 100)
		{
			if(securityBlock[index] != "")
			{	
				baddies << securityBlock[index];
				baddies << "\n"; 
			}
			index++;
		}
		string temp = baddies.str();
		ofstream fileOut("security");
		fileOut << baddies.rdbuf(); 
		fileOut.close(); 
	}

}
string ScoreKeeper::WriteScores(string *names, int *scores)
{
	string toWrite; 
	stringstream toWriteStream; 
	for(int i = 0; i<10; i++)
	{
		stringstream temp = WriteDif(names, scores, i); 
		toWriteStream <<  temp.str(); 
	}
	toWrite = toWriteStream.str(); 
	return toWrite; 
}
stringstream ScoreKeeper::WriteDif(string *names, int *scores, int index)
{
	stringstream toWrite;
	if(scores[index] != 0) //Check to make sure a score exists 
	{
        	toWrite	<< scores[index];
		toWrite << " "; 
		toWrite << names[index]; 
		if(index != 9)
		{
			toWrite << "\n";
		}
	}	
	return toWrite;
}
