#ifndef _fruit_h
#define _fruit_h

#include <iostream>
#include <thread>
#include <semaphore.h>
#include <vector>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Fruit
{
public:
	Fruit(int _width, int _height);
	int getFruitY();
	int getFruitX();
	void setFruit(int y,int x);

private:
	int fruitX = 0;
	int fruitY = 0;
	int height = 0;
	int width = 0;
	void newFruit(int y, int x); 

};
#endif

