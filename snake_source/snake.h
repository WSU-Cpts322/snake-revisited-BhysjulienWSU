#ifndef SNAKE
#define SNAKE

#include <thread>
#include <semaphore.h>
#include <vector>
#include <utility>


using namespace std;

class Snake
{
public:
	Snake(int width, int height);
	Snake(int width, int height, int length); 
	int getFinYTail();
	int getFinXTail();
	int getxTail(int x);
	int getyTail(int y);
	int getX();
	int getY();
	int GetLength();
	void incLength();
	void decLength();
	int setDirection(int Snake_direction_int);
	char getDirect();
	void SetPosition(int Y, int X, int length, int direction); 
	void UpdatePosition();
	void SetBool(int snakePos, bool set); 
	bool GetBool(int snakePos);	
	bool GetHeadBool();
	void SetHeadBool(bool set); 
	void SetPower(bool set);
	bool GetPower(); 
private:
	int Snake_x; //Snake head
	int Snake_y; //Snake head 
	bool SnakeHead_bool; //Turn off/oon snake. 
	bool power; //Bool to determine if we have a power snake 
	int Snake_Length = 0;
	bool snake_bool[1000];//Turn off/on positions of snake
	int snake_tail_x[1000];//Snake tail
	int snake_tail_y[1000];
	enum Current_Direction {up = 1, down = 2, left = 3, right = 4 };
	Current_Direction Snake_Direction;

	void Head_Pos_Chng();
	int Direct(int	Snake_direction_int);
};

#endif

