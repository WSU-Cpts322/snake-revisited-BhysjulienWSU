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
	void setFruit(int y,int x);
	Fruit(); 

private:
	int height = 0;
	int width = 0;
	void newFruit(int y, int x); 
	void DeterminePower();
};
#endif

