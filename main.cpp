// Caro-game create by HydraCoder
#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<cmath>
using namespace std;

// VOID FUNCTIONS
void playCaro();
void DrawScreen();
void printValue(int i, int j);
void gotoMenu(char choice);
void exitMenu();
void pcTurn();
int checkGame();
int checkWin();
void pauseGame();
void setPuzzle();
void trollStatus();
void colorSet(int init);
void gamePart(string part);
void helpCaro(string located);
void hideCursor(bool condition);

//GLOBAL VARIABLE
int correct = 0;
int userPoint = 0;
int pcPoint = 0;
int coroPointer = 0;
int roundPuzzle = 0;
string caroStatus;
int caroPuzzle[3][3];

//MAIN FUNCTION
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

int checkGame(){
	// CHECK ROW
	for(int i = 0; i < 3; ++i){ 
		if(caroPuzzle[i][0] == caroPuzzle[i][1]
		|| caroPuzzle[i][1] == caroPuzzle[i][2]){
			return caroPuzzle[i][0];
		}
	}
	// CHECK COLUMN
	for(int i = 0; i < 3; ++i){ 
		if(caroPuzzle[0][i] == caroPuzzle[1][i]
		|| caroPuzzle[1][i] == caroPuzzle[2][i]){
			return caroPuzzle[0][i];
		}
	}
	// CHECK DIAGONAL
	if(caroPuzzle[0][0] == caroPuzzle[1][1]
	|| caroPuzzle[1][1] == caroPuzzle[2][2]){
		return caroPuzzle[0][0];
	}
	
	if(caroPuzzle[1][2] == caroPuzzle[2][2]
	|| caroPuzzle[2][2] == caroPuzzle[2][1]){
		return caroPuzzle[1][2];
	}
	return -1;
}

int checkWin(){
	if(checkGame() != 1){
		if(checkGame() == 0){
			userPoint++;
		}else{
			pcPoint++;
		}
		setPuzzle();
		playCaro();
	}
	return -1;
}

// RESET ALL VALUE CAROPUZZLE
void setPuzzle(){
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < 3; ++j){
			caroPuzzle[i][j] = -1;
		}
	}
}

void playCaro(){
	for(int i = 0; i < 10; ++i){
		if(i == 0 && checkGame() != -1){
			
		}
		DrawScreen();
		getch();
		if(checkGame() != -1){
			if(checkGame() == 1)
		}
	}	
}

void DrawScreen(){
	//HEADER
	system("cls");
	colorSet(4);
		gamePart("line_small_left");
	colorSet(15);
		cout << "CARO GAME";
	colorSet(4);
		gamePart("line_small_right");
		
	// CHECK PLAYER CONDITION
	colorSet(4);
		gamePart("space");
		gamePart("caro_outer_border");
		gamePart("space");
		gamePart("caro_inner_vertical_border_small");
	colorSet(11);
		cout << setw(2) << "USER: " << setw(2) << userPoint << "       ";
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
	colorSet(4);
		gamePart("space");
		gamePart("caro_inner_vertical_border_small");
	colorSet(14);
		cout << setw(2) << "BOT: " << setw(3) << pcPoint << "       ";
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
		gamePart("space");
		gamePart("caro_outer_border");
	colorSet(4);
		gamePart("space");
		gamePart("caro_inner_vertical_border_small");
	colorSet(10);
		cout << setw(2) << "ROUND: " << setw(2) << roundPuzzle << "      ";
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
		gamePart("space");
		gamePart("caro_outer_border");
	// ROW 1
	colorSet(4);
		cout << endl << endl << endl;
		gamePart("space");
		gamePart("caro_outer_border");
		gamePart("space");
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
	// -- PRINT VALUE CARO PUZZLE -- //
	colorSet(4);
		gamePart("space");
		gamePart("caro_inner_vertical_border_small");
	colorSet(10);
		printValue(0,0);
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
	colorSet(10);
		printValue(0,1);
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
	colorSet(10);
		printValue(0,2);
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
	// -- PRINT VALUE CARO PUZZLE -- //
	gamePart("space");
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
	// ROW 2
	colorSet(4);
		gamePart("space");
		gamePart("caro_outer_border");
		gamePart("space");
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
	// -- PRINT VALUE CARO PUZZLE -- //
	colorSet(4);
		gamePart("space");
		gamePart("caro_inner_vertical_border_small");
	colorSet(10);
		printValue(1,0);
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
	colorSet(10);
		printValue(1,1);
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
	colorSet(10);
		printValue(1,2);
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
	// -- PRINT VALUE CARO PUZZLE -- //
	gamePart("space");
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
	//ROW 3
	colorSet(4);
		gamePart("space");
		gamePart("caro_outer_border");
		gamePart("space");
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
	// -- PRINT VALUE CARO PUZZLE -- //
	colorSet(4);
		gamePart("space");
		gamePart("caro_inner_vertical_border_small");
	colorSet(10);
		printValue(2,0);
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
	colorSet(10);
		printValue(2,1);
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
	colorSet(10);
		printValue(2,2);
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
	// -- PRINT VALUE CARO PUZZLE -- //
	gamePart("space");
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_small");
		gamePart("space3");
	colorSet(4);
		gamePart("caro_inner_vertical_border_next_line");
		gamePart("space");
		gamePart("caro_outer_border");
	colorSet(14);
		cout << "[ Press [1-9] number of your choice! ]" << endl;
		cout << " 1   2   3" << endl;
		cout << " 4   5   6" << endl;
		cout << " 7   8   9" << endl;
}

void printValue(int i, int j){
	if(caroPuzzle[i][j] != -1){
		if(caroPuzzle[i][j] == 1){
			cout << " X ";	
		}
		else{
			cout << " O ";
		}
	}else{
		cout << "   ";
	}
}

void gotoMenu(char choice){
	if(choice == '1'){
		setPuzzle();
		playCaro();
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
	}else if(part == "space3"){
		cout << "   ";
	}else if(part == "space"){
		cout << "           ";
	}else{
		cout << "";
	}
}
