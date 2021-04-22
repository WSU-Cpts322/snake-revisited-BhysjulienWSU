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
		void PrintBoxSel(int posY, int posX); //Function that handles highlight the currently selectd box. 
		void HighLightSelection(int _boarder, int _fill, int position, Settings &myGame, int maxPosi, bool color);//Helper function for dehilighting the non-selected box. 
		bool ColorModeSelect(bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names); //Menu for handling color selection and taking input. 
		void CustomColorSelect(Settings &myGame, int *scoresNum, string *names); //Sub menu custom color logic handler 
		bool SizeModeSelect(bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names); //handles menu and input for a customized gamemap size. 
		void PrintSelection(string tempStr, int posY, int posX, string &c11,string &c12, string &c21, string &c22, char temp, int tempColor);//Main menu selection printer. Only ussed on main menu/ 
		bool GameModeSelect(bool enterFlag, int position, Settings &myGame, int * scoresNum, string * names); //Once game style is selected, allows the user to increase or decrease difficulty. 
		void SecurityProfile(Security &scores); //Private security admin setting menu function for handling display and logic input/output. Allows usser to remove or add security profiles. 
	public:
		//Don't allow creating an instance of this object. 
		SelectionManager(); 
		string OptionsSelect(Settings &myGame, int * scoresNum, string * names); //Public main menu selection. Returns a string with the typle oof selection made.. 
		void AdminSettings(Security &scores); //Menu for displaying and taking input for admin menu. 
		bool ShowScores(Settings myGame, Security &scores); //
		string menuSelection(Settings &myGame, string *names, int *scores);
		string GetInit(int length);
		void CustomSize(Settings &mygame, int *scoresNum, string *names); 
		string SetPassword(bool newcheck); 
		bool PasswordInput(string password); 
};

#endif
