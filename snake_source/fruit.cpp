#include "fruit.h"

//Fruit constructor 
Fruit::Fruit(int _width, int _height)
{
	width = _width;
	height = _height;
}
//returns Y position of current fruit
void Fruit::setFruit(int y, int x)
{
	bool flag = true; 
	setY(1 + (rand() % height-2));//-2 to stay inside boarders. 
	setX(1 + (rand() % width-2));
	while(flag)
	{
	
		if(getY() == y && getX() == x)
		{
			setY(2 + (rand() % (height-4)));//-2 to stay inside boarders. 
			setX(2 + (rand() % (width-4)));
		}	
		else if(getY() < 2 || getY() >= height-2 || getX() >= width-2 || getX() < 2)
		{
			setY(2 + (rand() % (height-4)));//-2 to stay inside boarders. 
			setX(2 + (rand() % (width-4)));
		}
		else
		{
			flag = false; 
		}
	}
	DeterminePower(); 
}
void Fruit::newFruit(int y,int x)
{
	setFruit(y,x); 
}
void Fruit::DeterminePower()
{
	int i = (rand() % 10);
	if(i == 10 || i ==5 || i == 0)
	{
		SetPower(true); 
	}
	else 
	{
		SetPower(false); 
	}
}

