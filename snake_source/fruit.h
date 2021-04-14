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
#include "gameObject.h"

using namespace std;

class Fruit: public GameObject
{
public:
	Fruit(int _width, int _height);
	//int getY();
	//int getX();
	void setFruit(int y,int x);
	//void SetPower(bool _power); 
	//bool GetPower(); 

private:
	//bool power; 
	//int fruitX = 0;
	//int fruitY = 0;
	int height = 0;
	int width = 0;
	void newFruit(int y, int x); 
	void DeterminePower();
};
#endif

