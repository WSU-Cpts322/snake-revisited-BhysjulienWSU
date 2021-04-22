#include "fileIO.h"

void FileIO::SortScore(int index)
{
	for(int i = 0; i<=10; i++)
	{
		for(int j = 0; j<=10-i-1; j++)
		{
			if(scores[index][j] < scores[index][j+1])//Then swap 
			{
				SwapScore(scores[index][j], scores[index][j+1]);
				SwapName(names[index][j], names[index][j+1]); 
			}
					
		}
	
	}
}

void FileIO::SwapScore(int &posA, int &posB)
{
	int temp;
	temp = posA;
	posA = posB;
	posB = temp; 
}
void FileIO::SwapName(string &posA, string &posB)
{
	string temp;
	temp = posA;
	posA = posB;
	posB = temp; 
}
string FileIO::getSecBlock(int index) 
{
	return securityBlock[index];
}
void FileIO::setSecBlock(int index, string initials)
{
	securityBlock[index] = initials; 
}
int FileIO::getScore(int indexR, int indexC) 
{
	return scores[indexR][indexC];
}
string FileIO::getName(int indexR, int indexC)
{
	return names[indexR][indexC];
}
void FileIO::setScore(int indexR, int indexC, int value)
{
	scores[indexR][indexC] = value; 
}
void FileIO::setName(int indexR, int indexC, string name)
{
	names[indexR][indexC] = name; 
}
void FileIO::ReadStart(string fileName)
{
	ReadFile(fileName); 
}

bool FileIO::FileCheck(string fileName)
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
bool FileIO::IsEmpty(ifstream& fileE)
{
	return fileE.peek() == ifstream::traits_type::eof(); 
}
int FileIO::ParseInput(string& input)
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
void FileIO::WriteToString(string readIn, int linNum)
{
	int i = linNum; 
	 if(i<10 && readIn != "")
	 {
		scores[0][i] =  ParseInput(readIn); 
		names[0][i] = readIn; 
	 }
	 else if(i<20 && readIn != "")
	 {
		scores[1][i-10] =  ParseInput(readIn); 
		names[1][i-10] = readIn; 
	 }
	 else if(i<30 && readIn !="")
	 {
		scores[2][i-20] =  ParseInput(readIn); 
		names[2][i-20] = readIn; 
	 }
	 else if(i<40 && readIn !="")
	 {
		scores[3][i-30] =  ParseInput(readIn); 
		names[3][i-30] = readIn; 
	 }
	 else if(i<50 && readIn !="")
	 {
		scores[4][i-40] =  ParseInput(readIn); 
		names[4][i-40] = readIn; 
	 }
	 else if(i<60 && readIn != "")
	 {
		scores[5][i-50] =  ParseInput(readIn); 
		names[5][i-50] = readIn;
	 }	
}
void FileIO::ReadScores(string fileName)
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
void FileIO::ReadSecurity(string fileName)
{
	int i = 0; 
	string readTemp; 
	ifstream fileIn; 
	fileIn.open(fileName,ifstream::binary);
	while(std::getline(fileIn,readTemp))
	{
		if(readTemp != "password")
		{
			readTemp = ConvertToUp(readTemp); 
			readTemp.resize(3);
			securityBlock[i] = readTemp; 	
		}
		else if(readTemp == "password")
		{
			string del = " "; 
			readTemp = readTemp.erase(0, readTemp.find(del) + del.length()); 
			readTemp = ConvertToUp(readTemp); 		
			password = readTemp;
			passwordLen = password.length(); 	
		}


	}
}
string FileIO::ConvertToUp(string readTemp)
{
	char myArray[readTemp.size()+1];//as 1 char space for null is also required
	strcpy(myArray, readTemp.c_str());
	for(unsigned i = 0; i<strlen(myArray); i++)
	{
		myArray[i] = putchar(toupper(myArray[i]));
	}
	string str(myArray); 
	readTemp = str; 
	return str; 
}
void FileIO::setPassword(string token)
{
	password = token; 
}
string FileIO::getPassword()
{
	return password;
}
int FileIO::getPasswordLen() 
{
	return password.length();
}
void FileIO::ReadFile(string fileName)
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
				fileIn.open(fileName, ifstream::binary);
				string readTemp; 
				int j = 0; 
				while(std::getline(fileIn,readTemp)&& j<100)
				{
					if(readTemp.find("password") == std::string::npos) //Check if it is a password. 
					{
						readTemp = ConvertToUp(readTemp); //Data error handling. Can't be  more than 3
					       	if(readTemp.length() > 3)
					       	{
							readTemp.resize(3);
					       	}
						if(doit) 
						for(unsigned i = 0; i<readTemp.length(); i++) //decode 
						{
							if(i%2 == 0)
							{
								readTemp[i] = readTemp[i]-100;
							}
							else 
							{
								readTemp[i] = readTemp[i] +100;
							}
						}

					//	int count = 0; //Make sure there are not white spaces 
					//	for(int i = 0; readTemp[i]; i++)
					//	{
					//		if(readTemp[i] != ' ')
					//			readTemp[count++] = readTemp [i]; 
					//	}
					//	readTemp[count] = '\0'; 
						securityBlock[j]= readTemp;
						j++;
					}
					else if(readTemp.find("password") != std::string::npos) //Read in and decode password. 
					{
						string del = " ";
						readTemp = readTemp.erase(0, readTemp.find(del) + del.length()); 
						for(unsigned i = 0; i<readTemp.length(); i++)
						{
							if(i%2 == 0)
							{
								readTemp[i] = readTemp[i]-100;
							}
							else 
								readTemp[i] = readTemp[i] +100;
						}
						password = readTemp;
						passwordLen = password.length(); 
					}
				}
					
			}
			fileIn.close();
		}
		else 
		{
			if(fileName == "scores")
			{
				PreLoadTest();
			}
			else if(fileName == "security")	
			{
				PreLoadSecurity(); 
			}
		}
	}
}
void FileIO::PreLoadSecurity()
{
	securityBlock[0] = "BLL"; 
	securityBlock[1] = "ABC"; 
	securityBlock[2] = "DEF";
	securityBlock[3] = "BL";
	securityBlock[4] = "B";
}
void FileIO::PreLoadTest()
{
	
	for(int i =0; i<2; i++)
	{
		scores[i][0] = 100000;
		scores[i][1] = 10000;
		scores[i][2] = 10; 
		names[i][0] = "BDH";
		names[i][1] = "BDH";
		names[i][2] = "BDH"; 
		scores[i+3][0] = 100000;
		scores[i+3][1] = 10000;
		scores[i+3][2] = 10; 
		names[i+3][0] = "BDH";
		names[i+3][1] = "BDH";
		names[i+3][2] = "BDH"; 
	}
}
void FileIO::PublicWrite(string type)
{
	if(type == "scores")
	{
		stringstream allScores; 
		allScores << WriteScores(); 
		ofstream fileOut("scores");
		fileOut << allScores.rdbuf(); //Write all scores. 
		fileOut.close(); 
	}
	else if(type == "security") //Write all security 
	{
		int index =0; 
		stringstream baddies;
	       	while(index < 100)
		{
			if(securityBlock[index] != "")
			{
				string temp = securityBlock[index];
				if(doit)
				for(unsigned i = 0; i<temp.length(); i++) //Encode 
				{
					if(i%2 == 0) 
						temp[i] = temp[i] +100;
					else
						temp[i] = temp[i] -100; 
				}
				baddies << temp;//write encoded data
				baddies << "\n"; 
			}
			index++;
		}
		if(password != "") //Encode password 
		{
			for(unsigned i = 0; i<password.length(); i++)
			{
				if(i%2 == 0) 
					password[i] = password[i] +100;
				else
					password[i] = password[i] -100; 
			}
			baddies << "password " + password; 
		}
		string temp = baddies.str();
		ofstream fileOut("security", ofstream::binary);
		fileOut << baddies.rdbuf(); 
		fileOut.close(); 
	}

}
string FileIO::WriteScores()
{
	string toWrite; 
	stringstream toWriteStream; //Ensure data is written in correct order 
	for(int j = 0; j<6; j++)
	{
		if(j==0)
		{
			toWriteStream << "OldEasy";
			toWriteStream << "\n";
		}
		if(j==1)
		{
			toWriteStream << "OldHard";
			toWriteStream << "\n";
		}
		if(j==2) 
		{
			toWriteStream << "Old2020"; 
			toWriteStream << "\n";
		}
		if(j==3)
		{
			toWriteStream << "NewEasy";
			toWriteStream << "\n";
		}
		if(j==4)
		{
			toWriteStream << "NewHard"; 
			toWriteStream << "\n";
		}
		if(j==5)
		{
			toWriteStream << "New2020"; 
			toWriteStream << "\n";
		}
		for(int i = 0; i<10; i++)
		{
			stringstream temp = WriteDif(j, i); 
			toWriteStream <<  temp.str(); 
		}
	}
	toWrite = toWriteStream.str(); 
	return toWrite; 
}
stringstream FileIO::WriteDif(int indexR, int indexC)
{
	stringstream toWrite;
	if(scores[indexR][indexC] != 0) //Check to make sure a score exists 
	{
        	toWrite	<< scores[indexR][indexC];
		toWrite << " "; 
		toWrite << names[indexR][indexC]; 
//		if(indexC != 9)
//		{
		toWrite << "\n";
//		}
	}	
	return toWrite;
}
