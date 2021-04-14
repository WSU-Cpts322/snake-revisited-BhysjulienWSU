#ifndef GAME_OBJ
#define GAME_OBJ

class GameObject
{
	public: 
		int getY()
		{
			return y; 
		}	
		int getX()
		{
			return x; 
		}
		bool GetPower()
		{
			return power; 
		}
		void SetPower(bool _power)
		{
			power = _power; 
		}
		void setX(int _x)
		{
			x = _x;
		}
		void setY(int _y) 
		{
			y = _y;
		}
	private: 
		int x;
		int y; 
		bool power; 
};


#endif 
