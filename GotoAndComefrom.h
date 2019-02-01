#pragma once
//This is required for my code to work.
#include <string>
//Required before calls to Start_Goto. Call only once.
#define Init_Variables std::string where = ""; std::string strBreak = ""; int switchVal = 0; int ForSwitch  = 0; std::string label1 = ""; std::string label2 = ""; int loopNum = 0; std::string comefromPos = ""; std::string ifGoto = ""; bool test;
//a is a label. Declare variables before calling this. This function must be called before using any gotos.
#define Start(a) for(;;) {for(int a = 0; a < 1; a++){ if(where == "") {ifGoto = ""; if(true) {
//This function must be called at the end of main.
#define End where = ""; break; }}}if (where == "") {break;} ifGoto = ""; }
//This creates a label called x.
#define Define_Pos(x) where = #x;}} if(where==#x) {ifGoto = #x; if(comefromPos == "") {comefromPos = #x;} else {comefromPos = "";
//This goes to a label called x.
#define Goto(x) where = #x; break;
//x is a string not a var.
#define Define_Pos_String(x) where = x;}} if(where==x) {ifGoto = x; if(comefromPos == "") {comefromPos = x; break;} else {comefromPos = "";
//x is a string not a var.
#define Goto_String(x) where = x; break;
//a is an array of strings. All things labeled in that array go to this position. B is a label. Do not have multiple of a label, unless you add "" at end. Not known why.  
#define Comefrom_String(x,b) }}test = false; for(int b = 0; b < sizeof(x)/sizeof((x)[0]); b++) {if((x)[b]==comefromPos){test = true; break;}} if(test || (where == ifGoto)) {if(test) {comefromPos = "";}if(true){
//a is the first part of the for, b is the second, c is the third, d and e are labels, and f is the thing inside the for.
#define For(a,b,c,d,e,f) a;Define_Pos(d) if (!(b)) {Goto(e)} strBreak=#e;f c; Goto(d) Define_Pos(e)
//d and e are strings not vars.
#define For_String(a,b,c,d,e,f) a;Define_Pos_String(d) if (!(b)) {Goto_String(e)} strBreak=e;f c; Goto_String(d) Define_Pos_String(e)
//a is thing inside of if, b is a label.
#define Start_If(a,b) label1 = #b; if(!(a)) {Goto(b)} 
//Bs a string not a var.
#define Start_If_String(a,b) label1 = b; if(!(a)) {Goto_String(b)}
//a is the b within Start_If_With_Goto.
#define End_If Define_Pos_String(label1)
//B and c are labels.
#define Start_If_Else(a,b,c) label1 = #b; label2 = #c; if(!(a)) {Goto(b)}
//B and C are strings not vars.
#define Start_If_Else_String(a,b,c) label1 = b; label2 = c; if(!(a)) {Goto_String(b)}
//a in this is b in Start_If_With_Goto, and b is c in it.
#define End_If_Start_Else Goto_String(label2) Define_Pos_String(label1) 
//a is this is c in Start_If_Else_If_Part_With_Goto.
#define End_Else Define_Pos_String(label2)
//a is the condition, b and c are labels.
#define Start_While(a,b,c) label1 = #b; label2 = #c;Define_Pos(b) if(!(a)) {Goto(c)} strBreak=#c;
//b and c are strings not vars;
#define Start_While_String(a,b,c) label1 = b; label2 = c; Define_Pos_String(b) if(!a) {Goto_String(c)} strBreak=c;
//Ends the loop.
#define End_While Goto_String(label1) Define_Pos_String(label2)
//a is the condition, b is the label, and c is whats inside.
#define Do_While(a,b,c) Define_Pos(b) strBreak=#b;c if(a) {Goto(b)}
//b is a string not a var.
#define Do_While_String(a,b,c) Define_Pos_String(b) strBreak = b; c; if(a) {Goto_String(b)}
//Call this to break out of a loop.
#define Break Goto_String(strBreak)
//Initilize switch to work with goto. a,b, and c are labels, and e is the stuff inside of the switch, and d is the part would be the number switch is.
#define Switch(a,b,c,d,e) For(ForSwitch = 0, ForSwitch<1, ForSwitch++, a,b,switchVal=d; Start_If(false, c) e)
//a,b, and c are strings not vars.
#define Switch_String(a,b,c,d,e) For_String(ForSwitch = 0, ForSwitch<1, ForSwitch++, a,b,switchVal=d; Start_If_String(false, c) e)
//a is the thing to compare to, and b is a label.
#define Case(a,b) switchVal = a; End_If Start_If(switchVal == a,b)
//b is a string not a var.
#define Case_String(a,b) switchVal = a; End_If Start_If(switchVal == a,b)
//Default case.
#define Default switchVal = 0; End_If
//a is the thing it is going to be (for(a:b)). B is the array, c and d are labels, and e is what happens next.
#define For_Each(a,b,c,d,e) For(loopNum = 0, loopNum < (sizeof(b)/sizeof((b)[0])), loopNum++, c,d,a=b[loopNum];e)
//c and d are strings not vars.
#define For_Each_String(a,b,c,d,e) For_String(loopNum = 0, loopNum < (sizeof(b)/sizeof((b)[0])), loopNum++, c,d,a=b[loopNum];e)
//No try-catch because clean code.