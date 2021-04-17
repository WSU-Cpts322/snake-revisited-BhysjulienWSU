#ifndef SECURE
#define SECURE
#include "scoreManager.h"
class Security: public ScoreKeeper
{

	private:
		string baddies[100]; 
	public:
		bool DeleteSecurity(string initials); 
	       	void AddSecurity(string initials);
		bool SecurityCheck(string initials); 


};



#endif 
