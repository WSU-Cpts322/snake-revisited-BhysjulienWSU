#include "snake.h"
#include <iostream>


void Snake::Head_Pos_Chng()
{
	if (Snake_Length > 0) //Then we need to keep track of the tial.
	{
		if (Snake_Length == 1)
		{
			snake_tail_x[0] = Snake_x;
			snake_tail_y[0] = Snake_y;
		}
		if (Snake_Length > 1) //move the array up by one
		{
			for (int i = Snake_Length - 1; i >= 0; i--)
			{
				snake_tail_x[i + 1] = snake_tail_x[i];
				snake_tail_y[i + 1] = snake_tail_y[i];
			}
			snake_tail_x[0] = Snake_x;
			snake_tail_y[0] = Snake_y;
		}
	}
	switch (Snake_Direction)
	{
	case up:
		Snake_y--;
		break;
	case down:
		Snake_y++;
		break;
	case right:
		Snake_x++;
		break;
	case left:
		Snake_x--;
		break;
	}
}
void Snake::SetHeadBool(bool set)
{
	SnakeHead_bool = set; 
}
bool Snake::GetHeadBool()
{
	return SnakeHead_bool; 
}
void Snake::SetBool(int snakePos, bool set)
{
	snake_bool[snakePos] = set; 
}
bool Snake::GetBool(int snakePos)
{
	return snake_bool[snakePos]; 
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
	Snake_x = width/2;
	Snake_y = height/2;
	Snake_Length = 0;
}
Snake::Snake(int width, int height, int length)
{
	Snake_x = 2+(rand() %(width-2));
	Snake_y = 1;
	Snake_Length = length; 
}
int Snake::getFinYTail()
{
	int tempY;
	if(Snake_Length == 0)
	{
		tempY = Snake_y;
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
		tempX = Snake_x;
	}
	else
	{
		tempX = snake_tail_x[Snake_Length-1];
	}
	return tempX; 
}

void Snake::SetPosition(int Y, int X, int length, int direction)
{
	Snake_y = Y;
	Snake_x = X;
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
int Snake::getX()
{
	return Snake_x;
}
int Snake::getY()
{
	return Snake_y;
}
int Snake::GetLength()
{
	return Snake_Length;
}
void Snake::incLength()
{
	Snake_Length++;
}
int Snake::decLength()
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
