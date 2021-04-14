#include "snake.h"
#include <iostream>


void Snake::Head_Pos_Chng()
{
	if (Snake_Length > 0) //Then we need to keep track of the tial.
	{
		if (Snake_Length == 1)
		{
			snake_tail_x[0] = getX();
			snake_tail_y[0] = getY();
		}
		if (Snake_Length > 1) //move the array up by one
		{
			for (int i = Snake_Length - 1; i >= 0; i--)
			{
				snake_tail_x[i + 1] = snake_tail_x[i];
				snake_tail_y[i + 1] = snake_tail_y[i];
			}
			snake_tail_x[0] = getX();
			snake_tail_y[0] = getY();
		}
	}
	switch (Snake_Direction)
	{
	case up:
		setY(getY()-1);
		break;
	case down:
		setY(getY()+1);
		break;
	case right:
		setX(getX()+1);
		break;
	case left:
		setX(getX()-1);
		break;
	}
}
void Snake::SetPower(bool set)
{
	power = set; 
}
bool Snake::GetPower()
{
	return power; 
}
int Snake::Direct(int Snake_direction_int)
{

	switch (Snake_direction_int)
	{
	case 1:
		Snake_Direction = up;
		break;
	case 2:
		Snake_Direction = down;
		break;
	case 4:
		Snake_Direction = right;
		break;
	case 3:
		Snake_Direction = left;;
		break;
	}
	return Snake_direction_int;
}

Snake::Snake(int width, int height)
{
	//		srand(time(NULL));
	//		Snake_x = std::rand() % width;
	//		Snake_y = std::rand() % height;
	setX(width/2);
	setY(height/2);
	Snake_Length = 0;
	power = false; 
}
//Snake::Snake(int width, int height, int length)
//{
//	setX(2+(rand() %(width-2)));
//	setY(1);
//	Snake_Length = length; 
//}
void Snake::SetLength(int length)
{
	Snake_Length = length;
}

Snake::Snake(){}
int Snake::getFinYTail()
{
	int tempY;
	if(Snake_Length == 0)
	{
		tempY = getY();
	}
	else
	{
		tempY = snake_tail_y[Snake_Length-1];
	}
	return tempY;
}
int Snake::getFinXTail()
{
	int tempX;
	if(Snake_Length == 0)
	{
		tempX = getX();
	}
	else
	{
		tempX = snake_tail_x[Snake_Length-1];
	}
	return tempX; 
}

void Snake::SetPosition(int Y, int X, int length, int direction)
{
	setY(Y);
	setX(X);
	Snake_Length = length; 
	Direct(direction); 
}

int Snake::getxTail(int x)
{
	return snake_tail_x[x];
}

int Snake::getyTail(int y)
{
	return snake_tail_y[y];
}
int Snake::GetLength()
{
	return Snake_Length;
}
void Snake::incLength()
{
	Snake_Length++;
}
void Snake::decLength()
{
	Snake_Length--;
}
void Snake::UpdatePosition()
{
	Head_Pos_Chng(); 
}
int Snake::setDirection(int Snake_direction_int)
{
	Direct(Snake_direction_int);
	return(Snake_direction_int);//Return is prob useless. 
}
char Snake::getDirect()
{
	char	Snake_direction_char = 'p';
	switch (Snake_Direction)
	{
	case up:
		Snake_direction_char = 'w';
		break;
	case down:
		Snake_direction_char = 's';
		break;
	case right:
		Snake_direction_char = 'd';
		break;
	case left:
		Snake_direction_char = 'a';;
		break;
	}
	return Snake_direction_char;
}
