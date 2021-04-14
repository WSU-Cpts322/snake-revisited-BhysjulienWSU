#ifndef SELECT
#define SELECT
#include <string>
#include "settings.h" 
#include "colors.h" 
#include "specialPrints.h"
#include "scoreManager.h"
#include "security.h"

using namespace std; 

class SelectionManager: public SpecialPrint
{
	private: 
		void PrintBoxSel(int posY, int posX);
		void HighLightSelection(int _boarder, int _fill, int position, Settings &myGame, int maxPosi, bool color);
		bool ColorModeSelect(bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names);
		void CustomColorSelect(Settings &myGame, int *scoresNum, string *names);
		bool SizeModeSelect(bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names);
		void PrintSelection(string tempStr, int posY, int posX, string &c11,string &c12, string &c21, string &c22, char temp, int tempColor);
		bool GameModeSelect(bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names);
	public:
		//Don't allow creating an instance of this object. 
		SelectionManager();
		string OptionsSelect(Settings &myGame, int * scoresNum, string * names);
		void AdminSettings(Security &scores);
		bool ShowScores(Settings myGame, Security &scores);
		string menuSelection(Settings &myGame, string *names, int *scores);
		string GetInit(int length);
		void CustomSize(Settings &mygame, int *scoresNum, string *names); 
};

#endif
