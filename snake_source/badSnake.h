#ifndef BAD_SNAKE
#define BAD_SNAKE
#include "snake.h" 

class BadSnake: public Snake
{
	public: 
		BadSnake(int width, int height, int length);
		void SetBool(int snakePos, bool set);
		bool GetBool(int snakePos);
		bool GetHeadBool(); 
		void SetHeadBool(bool set);
	private:
		bool snake_bool[1000]; 
		bool SnakeHead_bool; 
};


#endif 
