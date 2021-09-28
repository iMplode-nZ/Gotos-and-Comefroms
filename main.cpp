#include <GotoAndComefrom.h>
#include <iostream>

int fact(int x) {
	Init_Variables
	Start(x)
		int result = 1;
		Comefrom_String(["not_finished"], whatever_label)
		result *= x;
		x--;
		if (x <= 0) { Goto(finish) }
		Define_Pos(not_finished)
		Define_Pos(finish)
		return result;
	End
}
