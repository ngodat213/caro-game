// Caro-game create by HydraCoder
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<cmath>
using namespace std;

// VOID FUNCTIONS
void playCaro();
void mainGame();
void gotoMenu(char choice);
void exitMenu();
void upKey();
void downKey();
void leftKey();
void rightKey();
void checkGame();
void pcTurn();
void pauseGame();
void trollStatus();
void helpCaro(string located);
void hideCursor(bool condition);
void colorSet(int init);
void gamePart(string part);

//GLOBAL VARIABLE
int correct = 0;
int caroPointer = 0;
string caroStatus;


int main(){
	//HIDE CURSOR
	hideCursor(true);
	SetConsoleTitle(("Caro-game"));
	
	//VARIABLE
	int choice;
	while(true){
		system("cls");
		colorSet(4); // DARK RED
			gamePart("line_small_left");
		colorSet(15);// WHITE
			cout << "CARO GAME";
		colorSet(4); // DARK RED
			gamePart("line_small_right");
		colorSet(15);// WHITE
			cout << " [1] ";
		colorSet(11);
			cout << "START" << endl;
		colorSet(15);// WHITE
			cout << " [2] ";
		colorSet(14);
			cout << "INSTRUCTIONS" << endl;
		colorSet(15);// WHITE
			cout << " [3] ";
		colorSet(12);// LIGHT RED
			cout << "EXIT" << endl;
		colorSet(4); // DARK RED
			gamePart("seperator");
		colorSet(7); // LIGHT GRAY
			cout << " [Press the number of your choice]";
		colorSet(15); // WHITE

			// GET USER CHOICE
			char select = getch();
			if(!(select < '1' || select > '3')){
				choice = select;
				break;
			}

	}

	// GOTO MENU OF USER CHOICE
	gotoMenu(choice);
	return 0;
}

void checkGame(){
	
}

void playCaro(){
	//CONDITION
	
}

void gotoMenu(char choice){
	if(choice == '1'){
//		playCaro();
	}else if(choice == '2'){
		helpCaro("main");
	}else if(choice == '3'){
		exitMenu();
	}
}

void exitMenu(){
	//DISPLAY
	do{
		system("cls");
		colorSet(4);
			gamePart("line_small_left");
		colorSet(15);
			cout << "CARO GAME";
		colorSet(4);
			gamePart("line_small_right");
		colorSet(13);
			cout << setw(24) << right << "DO YOU WANT TO EXIT" << endl;
		colorSet(4);
			gamePart("seperator");
		colorSet(15);
			cout << " [1] ";
		colorSet(12);
			cout << "YES" << endl;
		colorSet(15);
			cout << " [2] ";
		colorSet(10);
			cout << "NO" << endl;
		colorSet(4);
			gamePart("seperator");
		colorSet(7);
			cout << "[Press the number of your choice!]";
		colorSet(15);

		//GET USER CHOICE
		char select = getch();
		if(!(select < '1' || select > '2')){
			cout << endl;
			if(select == '1'){
				exit(0);
			}else{
				main();
			}
		}
	}while(true);
}

void pauseGame(){
	//DISPLAY
	do{
		system("cls");
		colorSet(4);
			gamePart("line_small_left");
		colorSet(15);
			cout << "SUDOKU";
		colorSet(4);
			gamePart("line_small_right");
		colorSet(13);
			cout << setw(24) << right << "GAME PAUSED" << endl;
		colorSet(4);
			gamePart("seperator");
		colorSet(15);
			cout << "[1] ";
		colorSet(10);
			cout << "INSTRUCTION" << endl;
		colorSet(15);
			cout << "[2] ";
		colorSet(12);
			cout << "QUIT" << endl;
		colorSet(4);
			gamePart("seperator");
		colorSet(7);
			cout << "[Press the number of your choice!]";
		colorSet(15);

		//GET USER CHOICE
		char select = getch();
		if(!(select < '1' || select > '2')){
			cout << endl;
			if(select == '1'){
				helpCaro("in-game");
			}else if(select == '2'){
				trollStatus();
				break;
			}else
				break;
		}
	}while(true);
}

void trollStatus(){
	colorSet(14);
	cout << " Sorry you did not finish" << endl
		<< " the sudoku puzzle." << endl;
	colorSet(13);
		cout << " Better luck next time!" << endl;
	colorSet(15);
		cout << " By the way, thats the solution." << endl;
	colorSet(7);
		cout << " [Press any key to exit the game]" << endl;
	getch(); //pause
	main();
}

void helpCaro(string located){
	system("cls");
	colorSet(4);
		gamePart("line_small_left");
	colorSet(15);
		cout << "CARO GAME";
	colorSet(4);
		gamePart("line_small_right");
	colorSet(13);
		cout << setw(27) << right << "INSTRUCTIONS" << endl;
	colorSet(4);
		gamePart("seperator");
	colorSet(10);
		cout << " How to play!" << endl;
	colorSet(15);
		cout << " Comming soon!" << endl;
	colorSet(4);
		gamePart("seperator");
	colorSet(7);
		cout << " [Press any key to go back]";
	colorSet(15);
	//PAUSE
	getch();
	//GO TO MAIN MENU
	if(located == "main"){
		main();
	}
}

void hideCursor(bool condition){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = (!(condition));
	SetConsoleCursorInfo(out, &cursorInfo);
}

void colorSet(int init){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), init);
}

void gamePart(string part){
	if(part == "line_small_left"){
		cout << " =============== ";
	}else if(part == "line_small_right"){
		cout << " ===============" << endl;
	}else if(part == "seperator"){
		cout << " =========================================" << endl;
	}else if(part == "caro_outer_border"){
		cout << " +-----+-----+-----+" << endl;
	}else if(part == "caro_outer_vertical_border_small"){
		cout << " + ";
	}else if(part == "caro_outer_vertical_border_next_line"){
		cout << " +" << endl;
	}else if(part == "caro_inner_vertical_border_small"){
		cout << " | ";
	}else if(part == "caro_inner_vertical_border_next_line"){
		cout << " |" << endl;
	}else if(part == "sudoku_inner_border"){
		cout << " +-----+-----+-----+" << endl;
	}else{
		cout << "";
	}
}
