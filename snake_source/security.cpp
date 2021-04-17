#include "security.h"

void Security::AddSecurity(string initials)
{
	int index = 0; 
	while(getSecBlock(index) != "" && index<100)
	{
		index ++; 
	}
	setSecBlock(index,initials);
       	for(int i = 0; i<6; i++)
	{
		for(int j = 0; j<10; j++)
		{
			if(getName(i,j) == initials)
			{
				setName(i,j,"");
				setScore(i,j,0);
			}
		}
	}
	for(int i = 0; i<6; i++)
	{
		SortScore(i); 
	}
}
bool Security::DeleteSecurity(string initials)
{
	bool flag = false; 
	int index = 0; 
	while(getSecBlock(index) != "" && index<100)
	{
		if(getSecBlock(index) == initials)
		{
			setSecBlock(index,"");
			int temp = index; 
			while(temp<99 && getSecBlock(temp) != "")
			{
				setSecBlock(temp,getSecBlock(temp+1)); 
				temp++;
			}
			setSecBlock(temp,"");
			flag = true; 
		}
		index ++; 
	}
	return flag; 
}
bool Security::SecurityCheck(string intials)
{
	bool check = false; 
	int i =0;
	while(getSecBlock(i) != "" && i < 100)
	{
		if(getSecBlock(i) == intials)
			check = true;
		i++;
		if(i == 100) break; 
	}
	return check; 
}
