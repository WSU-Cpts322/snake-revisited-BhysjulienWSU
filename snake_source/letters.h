#ifndef LETTERS
#define LETTERS 
#include <cstring>
using namespace std; 

class Letters
{
	private:
	       	int Colon(int y, int x) 
		{
			int width = 2; 
			string line1 = "XX";	
			PrintString(y, x+1, line1); 
			PrintString(y+1, x+1, line1); 
			PrintString(y+3, x+1, line1); 
			PrintString(y+4, x+1, line1); 
			return(width); 
		}
	       	int WhiteSp(int y, int x) 
		{
			int width = 5; 
			string line1 = "     ";	
			string line2 = "     ";	
			string line3 = "     ";	
			string line4 = "     ";	
			string line5 = "     ";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}

		int letterA(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			string line4 = "XXXXX";	
			PrintString(y, x+2, line1); 
			PrintString(y+1, x+1, line1); 
			PrintString(y+1, x+3, line1); 
			PrintString(y+2, x, line1); 
			PrintString(y+2, x+4, line1); 
			PrintString(y+3, x, line4); 
			PrintString(y+4, x, line1); 
			PrintString(y+4, x+4, line1); 
			return(width); 
		}
		int letterB(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXX";	
			string line2 = "X";	
			PrintString(y, x, line1); 
			PrintString(y+2, x, line1); 
			PrintString(y+4, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+3, x+0, line2); 
			PrintString(y+3, x+4, line2); 
			return(width); 
		}
		int letterC(int y, int x)
		{
			int width = 5; 
			string line1 = "XXX";	
			string line2 = "X";	
			string line3 = "X";	
			PrintString(y, x+1, line1);
		       	PrintString(y+4,x+1,line1); 	
			PrintString(y+1, x, line2); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+3, x, line2); 
			PrintString(y+3, x+4, line2); 
			PrintString(y+2, x, line3); 
			return(width); 
		}
		int letterD(int y, int x)
		{
			int width = 5; 
			string line1 = "XXX";	
			string line2 = "X";	
			PrintString(y, x, line1); 
			PrintString(y+4, x, line1);
			PrintString(y+1, x, line2); 
			PrintString(y+3, x, line2); 
			PrintString(y+1, x+3, line2); 
			PrintString(y+3, x+3, line2); 
			PrintString(y+2, x, line2); 
			PrintString(y+2, x+4, line2); 

			return(width); 
		}
		int letterE(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			string line3 = "XXXX";	
			string line4 = "X";	
			string line5 = "XXXXX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letterF(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			string line3 = "XXXX";	
			string line4 = "X";	
			string line5 = "X";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letterG(int y, int x)
		{
			int width = 5; 
			string line1 = "XXX";	
			string line2 = "X";	
			string line3 = "XX";	
			string line5 = "XXXX ";	
			PrintString(y, x+1, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+4, x, line5);
		       	PrintString(y+2, x, line2); 
			PrintString(y+2, x+3, line3);	
			PrintString(y+3, x, line2); 
			PrintString(y+3, x+4, line2); 
			return(width); 
		}
		int letterH(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			string line3 = "XXXXX";	
			PrintString(y+2, x, line3); 
			PrintString(y, x, line1); 
			PrintString(y+1, x, line1); 
			PrintString(y+3, x, line1); 
			PrintString(y+4, x, line1); 
			PrintString(y, x+4, line1); 
			PrintString(y+1, x+4, line1); 
			PrintString(y+3, x+4, line1); 
			PrintString(y+4, x+4, line1); 
			return(width); 
		}
		int letterI(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			string line3 = "X";	
			string line4 = "X";	
			string line5 = "XXXXX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x+2, line2); 
			PrintString(y+2, x+2, line3); 
			PrintString(y+3, x+2, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letterJ(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			string line5 = "XXX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x+2, line2); 
			PrintString(y+2, x+2, line2); 
			PrintString(y+3, x, line2); 
			PrintString(y+3, x+2, line2); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letterK(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			string line3 = "XXX";	
			PrintString(y+2, x, line3); 
			PrintString(y, x, line1); 
			PrintString(y, x+3, line1); 
			PrintString(y+1, x, line1); 
			PrintString(y+1, x+2, line1); 
			PrintString(y+3, x, line1); 
			PrintString(y+3, x+3, line1); 
			PrintString(y+4, x, line1); 
			PrintString(y+4, x+4, line1); 
			return(width); 
		}
		int letterL(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			string line2 = "X";	
			string line3 = "X";	
			string line4 = "X";	
			string line5 = "XXXXX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letterM(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			string line2 = "XX";	
			PrintString(y, x, line1); 
			PrintString(y, x+4, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+1, x+3, line2); 
			PrintString(y+2, x, line1); 
			PrintString(y+2, x+4, line1); 
			PrintString(y+2, x+2, line1); 
			PrintString(y+3, x, line1); 
			PrintString(y+3, x+4, line1); 
			PrintString(y+4, x, line1); 
			PrintString(y+4, x+4, line1); 
			return(width); 
		}
		int letterN(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			string line2 = "XX";	
			PrintString(y, x, line1); 
			PrintString(y, x+4, line1); 
			PrintString(y+2, x, line1); 
			PrintString(y+2, x+2, line1); 
			PrintString(y+2, x+4, line1); 
			PrintString(y+4, x, line1); 
			PrintString(y+4, x+4, line1); 
			PrintString(y+1, x+4, line1); 
			PrintString(y+3, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+3, x+3, line2); 
			return(width); 
		}
		int letterO(int y, int x)
		{
			int width = 5; 
			string line1 = "XXX";	
			string line2 = "X";	
			PrintString(y, x+1, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line2); 
			PrintString(y+3, x, line2); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+2, x+4, line2); 
			PrintString(y+3, x+4, line2); 
			PrintString(y+4, x+1, line1); 
			return(width); 
		}
		int letterP(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXX";	
			string line2 = "X";	
			string line3 = "XXXX";	
			string line4 = "X";	
			string line5 = "X";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letterQ(int y, int x)
		{
			int width = 5; 
			string line1 = "XXX";	
			string line2 = "X";	
			string line4 = "XX";	
			string line5 = "XXXX";	
			PrintString(y, x+1, line1); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+2, x, line2); 
			PrintString(y+2, x+4, line2); 
			PrintString(y+1, x, line2); 
			PrintString(y+1, x, line2); 
			PrintString(y+3, x+3, line4); 
			PrintString(y+4, x+1, line5); 
			PrintString(y+3, x, line2); 
			return(width); 
		}
		int letterR(int y, int x)
		{
			int width = 5; 
			string line1 = "XXX";	
			string line2 = "X";	
			string line3 = "XXXX";	
			PrintString(y, x+1, line1); 
			PrintString(y+2, x, line3); 
			PrintString(y+1, x, line2); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+3, x, line2); 
			PrintString(y+3, x+2, line2); 
			PrintString(y+4, x, line2); 
			PrintString(y+4, x+3, line2); 
			return(width); 
		}
		int letterS(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			string line3 = "XXXXX";	
			string line4 = "X";	
			string line5 = "XXXXX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x+4, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letterT(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			string line3 = "X";	
			string line4 = "X";	
			string line5 = "X";	
			PrintString(y, x, line1); 
			PrintString(y+1, x+2, line2); 
			PrintString(y+2, x+2, line3); 
			PrintString(y+3, x+2, line4); 
			PrintString(y+4, x+2, line5); 
			return(width); 
		}
		int letterU(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			string line5 = "XXX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line1); 
			PrintString(y+2, x, line1); 
			PrintString(y+3, x, line1); 
			PrintString(y, x+4, line1); 
			PrintString(y+1, x+4, line1); 
			PrintString(y+2, x+4, line1); 
			PrintString(y+3, x+4, line1); 
			PrintString(y+4, x+1, line5); 
			return(width); 
		}
		int letterV(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			PrintString(y, x, line1); 
			PrintString(y, x+4, line1); 
			PrintString(y+1, x, line1); 
			PrintString(y+1, x+4, line1); 
			PrintString(y+2, x, line1); 
			PrintString(y+2, x+4, line1); 
			PrintString(y+3, x+1, line1); 
			PrintString(y+3, x+3, line1); 
			PrintString(y+4, x+2, line1); 
			return(width); 
		}
		int letterW(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			string line4 = "XX";	
			PrintString(y, x, line1); 
			PrintString(y, x+4, line1); 
			PrintString(y+1, x, line1); 
			PrintString(y+1, x+4, line1); 
			PrintString(y+4, x, line1); 
			PrintString(y+4, x+4, line1); 
			PrintString(y+2, x, line1); 
			PrintString(y+2, x+4, line1); 
			PrintString(y+2, x+2, line1); 
			PrintString(y+3, x, line4); 
			PrintString(y+3, x+3, line4); 
			return(width); 
		}
		int letterX(int y, int x)
		{
			int width = 5; 
			string line1 = "X   X";	
			string line2 = " X X ";	
			string line3 = "  X  ";	
			string line4 = " X X ";	
			string line5 = "X   X";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letterY(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			PrintString(y, x, line1); 
			PrintString(y, x+4, line1); 
			PrintString(y+1, x+1, line1); 
			PrintString(y+1, x+3, line1); 
			PrintString(y+2, x+2, line1); 
			PrintString(y+3, x+2, line1); 
			PrintString(y+4, x+2, line1); 
			return(width); 
		}
		int letterZ(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			PrintString(y, x, line1); 
			PrintString(y+1, x+3, line2); 
			PrintString(y+2, x+2, line2); 
			PrintString(y+3, x+1, line2); 
			PrintString(y+4, x, line1); 
			return(width); 
		}
		int Exl(int y, int x)
		{
			int width = 4; 
			string line1 = "XX";	
			string line2 = "XX";	
			string line3 = "XX";	
			string line5 = "XX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int SmallSpace(int y, int x)
		{
			int width = 1; 
			string line1 = "";	
			string line2 = "";	
			string line3 = "";	
			string line4 = "";	
			string line5 = "";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letter1(int y, int x)
		{
			int width = 5; 
			string line1 = "XXX";	
			string line2 = "X";	
			string line5 = "XXXXX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x+2, line2); 
			PrintString(y+2, x+2, line2); 
			PrintString(y+3, x+2, line2); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letter2(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXX";	
			string line2 = "X";	
			string line3 = "XXX";	
			string line4 = "X";	
			string line5 = "XXXXX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+2, x+1, line3); 
			PrintString(y+3, x, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letter3(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXX";	
			string line2 = "X";	
			string line3 = "XXXXX";	
			string line4 = "X";	
			string line5 = "XXXX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x+4, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letter4(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			string line3 = "XXXXX";	
			PrintString(y, x, line1); 
			PrintString(y, x+4, line1); 
			PrintString(y+1, x, line1); 
			PrintString(y+1, x+4, line1); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x+4, line1); 
			PrintString(y+4, x+4, line1); 
			return(width); 
		}
		int letter5(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			string line3 = "XXXXX";	
			string line4 = "X";	
			string line5 = "XXXXX";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line3); 
			PrintString(y+3, x+4, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int letter6(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line1); 
			PrintString(y+3, x, line2); 
			PrintString(y+4, x, line1); 
			PrintString(y+3, x, line2); 
			PrintString(y+3, x+4, line2); 
			return(width); 
		}
		int letter7(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "    X";	
			PrintString(y, x, line1); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+2, x+4, line2); 
			PrintString(y+3, x+4, line2); 
			PrintString(y+4, x+4, line2); 
			return(width); 
		}
		int letter8(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line1); 
			PrintString(y+4, x, line1); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+3, x+4, line2); 
			PrintString(y+3, x, line2); 
			return(width); 
		}
		int letter9(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			string line2 = "X";	
			string line3 = "XXXXX";	
			string line4 = "X";	
			string line5 = "X";	
			PrintString(y, x, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line1); 
			PrintString(y+3, x+4, line2); 
			PrintString(y+4, x+4, line2); 
			PrintString(y+1, x+4, line2); 
			return(width); 
		}
		int letter0(int y, int x)
		{
			int width = 5; 
			string line1 = "XXX";	
			string line2 = "X";	
			PrintString(y, x+1, line1); 
			PrintString(y+1, x, line2); 
			PrintString(y+2, x, line2); 
			PrintString(y+3, x, line2); 
			PrintString(y+1, x+4, line2); 
			PrintString(y+2, x+4, line2); 
			PrintString(y+3, x+4, line2); 
			PrintString(y+4, x+1, line1); 
			return(width); 
		}
		int letterDiv(int y, int x)
		{
			int width = 5; 
			string line1 = "X";	
			string line2 = "X";	
			string line3 = "X";	
			string line4 = "X";	
			string line5 = "X";	
			PrintString(y, x+4, line1); 
			PrintString(y+1, x+3, line2); 
			PrintString(y+2, x+2, line3); 
			PrintString(y+3, x+1, line4); 
			PrintString(y+4, x, line5); 
			return(width); 
		}
		int Period(int y, int x)
		{
			int width = 2; 
			string line1 = "XX";	
			PrintString(y+3, x+1, line1); 
			PrintString(y+4, x+1, line1); 
			return(width); 
		}
		int Equal(int y, int x)
		{
			int width = 5; 
			string line1 = "XXXXX";	
			PrintString(y+1, x, line1); 
			PrintString(y+3, x, line1); 
			return(width); 
		}
		
		
	public: 
		void PrintString(int y, int x, string String)
		{	
  			mvprintw(y,x, String.c_str()); 
		}
		int pubSmallSpace(int y, int x)
		{
			return SmallSpace(y, x); 
		}
		int pubExl(int y, int x)
		{
			return Exl(y, x); 
		}
		int pubWhiteSp(int y, int x)
		{
			return WhiteSp(y, x); 
		}
		int pubLetterDiv(int y, int x)
		{
			return letterDiv(y, x);
		}
		int pubLetterA(int y, int x)
		{
			return letterA(y, x);
		}
		int pubLetterB(int y, int x)
		{
			return letterB(y, x);
		}
		int pubLetterC(int y, int x)
		{
			return letterC(y, x);
		}
		int pubLetterD(int y, int x)
		{
			return letterD(y, x);
		}
		int pubLetterE(int y, int x)
		{
			return letterE(y, x);
		}
		int pubLetterF(int y, int x)
		{
			return letterF(y, x);
		}
		int pubLetterG(int y, int x)
		{
			return letterG(y, x);
		}
		int pubLetterH(int y, int x)
		{
			return letterH(y, x);
		}
		int pubLetterI(int y, int x)
		{
			return letterI(y, x);
		}
		int pubLetterJ(int y, int x)
		{
			return letterJ(y, x);
		}
		int pubLetterK(int y, int x)
		{
			return letterK(y, x);
		}
		int pubLetterL(int y, int x)
		{
			return letterL(y, x);
		}
		int pubLetterM(int y, int x)
		{
			return letterM(y, x);
		}
		int pubLetterN(int y, int x)
		{
			return letterN(y, x);
		}
		int pubLetterO(int y, int x)
		{
			return letterO(y, x);
		}
		int pubLetterP(int y, int x)
		{
			return letterP(y, x);
		}
		int pubLetterQ(int y, int x)
		{
			return letterQ(y, x);
		}
		int pubLetterR(int y, int x)
		{
			return letterR(y, x);
		}
		int pubLetterS(int y, int x)
		{
			return letterS(y, x);
		}
		int pubLetterT(int y, int x)
		{
			return letterT(y, x);
		}
		int pubLetterU(int y, int x)
		{
			return letterU(y, x);
		}
		int pubLetterV(int y, int x)
		{
			return letterV(y, x);
		}
		int pubLetterW(int y, int x)
		{
			return letterW(y, x);
		}
		int pubLetterX(int y, int x)
		{
			return letterX(y, x);
		}
		int pubLetterY(int y, int x)
		{
			return letterY(y, x);
		}
		int pubLetterZ(int y, int x)
		{
			return letterZ(y, x);
		}
		int pubLetter1(int y, int x)
		{
			return letter1(y, x); 
		}
		int pubLetter2(int y, int x)
		{
			return letter2(y, x);
		}
		int pubLetter3(int y, int x)
		{
			return letter3(y, x);
		}
		int pubLetter4(int y, int x)
		{
			return letter4(y, x);
		}
		int pubLetter5(int y, int x)
		{
			return letter5(y, x);
		}
		int pubLetter6(int y, int x)
		{
			return letter6(y, x);
		}
		int pubLetter7(int y, int x)
		{
			return letter7(y, x);
		}
		int pubLetter8(int y, int x)
		{
			return letter8(y, x);
		}
		int pubLetter9(int y, int x)
		{
			return letter9(y, x);
		}
		int pubLetter0(int y, int x)
		{
			return letter0(y, x);
		}
		int pubColon(int y, int x)
		{
			return Colon(y, x);
		}
		int pubPeriod(int y, int x)
		{
			return Period(y, x);
		}
		int pubEqual(int y, int x)
		{
			return Equal(y, x);
		}
		void PrintMultiChars(string message, int posY, int posX)
		{
			int y = posY;
			int x = posX;
			char * parsed = new char[message.length()+1];
			strcpy(parsed, message.c_str()); 
			unsigned j = 0; 
			while(j < message.length()) 
			{
				switch (parsed[j])
				{
					case '=':
						x = x + pubEqual(y,x) + 1; 
						break; 
					case '.':
						x = x + pubPeriod(y,x) + 1; 
						break; 
					case ':':
						x = x + pubColon(y,x) + 1; 
						break; 
					case '/':
						x = x + pubLetterDiv(y,x) + 1; 
						break; 
					case ',':
						x = x + pubSmallSpace(y,x) + 1; 
						break; 
					case '!':
						x = x + pubExl(y,x) + 1; 
						break; 
					case ' ':
						x = x + pubWhiteSp(y,x) + 1; 
						break; 
					case 'A': 
						x = x + pubLetterA(y,x) + 1; 
						break; 
					case 'B': 
						x = x + pubLetterB(y,x) + 1; 
						break; 
					case 'C': 
						x = x + pubLetterC(y,x) + 1; 
						break; 
					case 'D': 
						x = x + pubLetterD(y,x) + 1; 
						break; 
					case 'E': 
						x = x + pubLetterE(y,x) + 1; 
						break; 
					case 'F': 
						x = x + pubLetterF(y,x) + 1; 
						break; 
					case 'G': 
						x = x + pubLetterG(y,x) + 1; 
						break; 
					case 'H': 
						x = x + pubLetterH(y,x) + 1; 
						break; 
					case 'I': 
						x = x + pubLetterI(y,x) + 1; 
						break; 
					case 'J': 
						x = x + pubLetterJ(y,x) + 1; 
						break; 
					case 'K': 
						x = x + pubLetterK(y,x) + 1; 
						break; 
					case 'L': 
						x = x + pubLetterL(y,x) + 1; 
						break; 
					case 'M': 
						x = x + pubLetterM(y,x) + 1; 
						break; 
					case 'N': 
						x = x + pubLetterN(y,x) + 1; 
						break; 
					case 'O': 
						x = x + pubLetterO(y,x) + 1; 
						break; 
					case 'P': 
						x = x + pubLetterP(y,x) + 1; 
						break; 
					case 'Q': 
						x = x + pubLetterQ(y,x) + 1; 
						break; 
					case 'R': 
						x = x + pubLetterR(y,x) + 1; 
						break; 
					case 'S': 
						x = x + pubLetterS(y,x) + 1; 
						break; 
					case 'T': 
						x = x + pubLetterT(y,x) + 1; 
						break; 
					case 'U': 
						x = x + pubLetterU(y,x) + 1; 
						break; 
					case 'V': 
						x = x + pubLetterV(y,x) + 1; 
						break; 
					case 'W': 
						x = x + pubLetterW(y,x) + 1; 
						break; 
					case 'X': 
						x = x + pubLetterX(y,x) + 1; 
						break; 
					case 'Y': 
						x = x + pubLetterY(y,x) + 1; 
						break; 
					case 'Z': 
						x = x + pubLetterZ(y,x) + 1; 
						break; 
					case '1': 
						x = x + pubLetter1(y,x) + 1; 
						break; 
					case '2': 
						x = x + pubLetter2(y,x) + 1; 
						break; 
					case '3': 
						x = x + pubLetter3(y,x) + 1; 
						break; 
					case '4': 
						x = x + pubLetter4(y,x) + 1; 
						break; 
					case '5': 
						x = x + pubLetter5(y,x) + 1; 
						break; 
					case '6': 
						x = x + pubLetter6(y,x) + 1; 
						break; 
					case '7': 
						x = x + pubLetter7(y,x) + 1; 
						break; 
					case '8': 
						x = x + pubLetter8(y,x) + 1; 
						break; 
					case '9': 
						x = x + pubLetter9(y,x) + 1; 
						break; 
					case '0': 
						x = x + pubLetter0(y,x) + 1; 
						break; 
				}
				j++; 
				
			}

		}
};

# endif
