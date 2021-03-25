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
	int decLength();
	int setDirection(int Snake_direction_int);
	char getDirect();
	void SetPosition(int Y, int X, int length, int direction); 
	void UpdatePosition();
	void SetBool(int snakePos, bool set); 
	bool GetBool(int snakePos);	
	bool GetHeadBool();
	void SetHeadBool(bool set); 
private:
	pthread_t input_thread;
	int Snake_x;
	int Snake_y;
	bool SnakeHead_bool; 
	int Snake_Length = 0;
	bool snake_bool[1000];
	int snake_tail_x[1000];
	int snake_tail_y[1000];
	enum Current_Direction { stop = 0, up = 1, down = 2, left = 3, right = 4 };
	Current_Direction Snake_Direction;

	void Head_Pos_Chng();
	int Direct(int	Snake_direction_int);
};

#endif

