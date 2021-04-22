#ifndef SNAKE
#define SNAKE

#include <thread>
#include <semaphore.h>
#include <vector>
#include <utility>
#include "gameObject.h"


using namespace std;

class Snake: public GameObject
{
public:
	Snake(); 
	Snake(int width, int height);
	int getFinYTail(); //Function that returns the Y cords of the last piece of the snake 
	int getFinXTail(); //Function that returns the x cords for the last piece of the sna,e 
	int getxTail(int x); //Given a position, returns the x cords of that position in the snke 
	int getyTail(int y); //Same as getxTail but for the y position 
	int GetLength();
	void incLength(); //Incs the length by one. 
	void decLength(); //Ended up not using this this function 
	int setDirection(int Snake_direction_int); //Given an enum, provides a new direction for the snake via private Direct function 
	char getDirect(); //Returns the current direction of the snake 
	void SetPosition(int Y, int X, int length, int direction); //Set initial values of the snake 
	void UpdatePosition();
	//void SetBool(int snakePos, bool set); 
	//bool GetBool(int snakePos);	
	//bool GetHeadBool();
	//void SetHeadBool(bool set); 
	void SetPower(bool set); //Toggles power off and on 
	bool GetPower();  
	void SetLength(int length); //Used for setting custom lengths of snake 
private:
	//bool SnakeHead_bool; //Turn off/oon snake. 
	bool power; //Bool to determine if we have a power snake 
	int Snake_Length = 0;
	//bool snake_bool[1000];//Turn off/on positions of snake
	int snake_tail_x[1000];//Snake tail
	int snake_tail_y[1000];
	enum Current_Direction {up = 1, down = 2, left = 3, right = 4 };
	Current_Direction Snake_Direction;

	void Head_Pos_Chng(); //Updates the snake after the direction change 
	int Direct(int	Snake_direction_int); //Calculates the new direction 
};

#endif

