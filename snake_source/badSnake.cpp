#include "badSnake.h" 
#include <iostream>

BadSnake::BadSnake(int width, int height, int length)
{
	setX(2+(rand() %(width-2)));
	setY(1);
	SetLength(length); 
}
void BadSnake::SetBool(int snakePos, bool set)
{
	snake_bool[snakePos] = set; 
}
bool BadSnake::GetBool(int snakePos)
{
	return snake_bool[snakePos]; 
}
void BadSnake::SetHeadBool(bool set)
{
	SnakeHead_bool = set; 
}
bool BadSnake::GetHeadBool()
{
	return SnakeHead_bool; 
}
