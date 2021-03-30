#include "fruit.h"

//Fruit constructor 
Fruit::Fruit(int _width, int _height)
{
	width = _width;
	height = _height;
}
//returns Y position of current fruit
int Fruit::getFruitY()
{
	return fruitY;
}
//returns x position of current fruit 
int Fruit::getFruitX()
{
	return fruitX;
}

bool Fruit::GetPower()
{
	return power; 
}
void Fruit::SetPower(bool _power)
{
	power = _power; 
}

void Fruit::setFruit(int y, int x)
{
	bool flag = true; 
	fruitY = 1 + (rand() % height-2);//-2 to stay inside boarders. 
	fruitX = 1 + (rand() % width-2);
	while(flag)
	{
	
		if(fruitY == y && fruitX == x)
		{
			fruitY = 2 + (rand() % (height-4));//-2 to stay inside boarders. 
			fruitX = 2 + (rand() % (width-4));
		}	
		else if(fruitY < 2 || fruitY >= height-2 || fruitX >= width-2 || fruitX < 2)
		{
			fruitY = 2 + (rand() % (height-4));//-2 to stay inside boarders. 
			fruitX = 2 + (rand() % (width-4));
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
		power = true; 
	}
	else 
	{
		power = false; 
	}
}

