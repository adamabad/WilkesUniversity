// adamplayer.cc
// M. Anthony Kapolka
// Edited by: Adam Abad
// Date: Nov 22, 2019
// CS 340
// vers 1.0
// Wed Feb 25 01:30:35 EST 1998

using namespace std;
#include <iostream>
#include "adamplayer.h"

adamplayer::adamplayer(owner p) { 
	cout << "Creating Player!" << endl;
	whoiam = p; //playerA, playerB
};

void adamplayer::setup(ghostboard & B) {
	if(whoiam == playerA) {
		char start[4][2] = {'y','b','y','y','b','b','y','b'};
		B.placeghosts(start, whoiam);
	}
	else {
		char start[4][2] = {'y','b','y','b','y','y','b','b'};
		B.placeghosts(start, whoiam);
	}	
};
/*
int ** setValue(ghostboard B) {
	int getX1, getY1, getX2, getY2;
	B.getlastmove(getX1, getY1, getX2, getY2);
	
	int good, bad;
	B.getcapture(whoiam, good, bad);
	int ghostsleft = 8 - (good + bad);
	return value;
}
*/
void adamplayer::move(ghostboard B, int &x1, int &y1, int &x2, int &y2) {
	//Set board space:
	int value[6][6];
	int takevalue, good, bad;
	//0 value;
	for(int x = 0; x < 6; x++) {
		for(int y = 0; y < 6; y++) {
			value[x][y] = 0;
		}
	}
	
	if(whoiam == playerA) {
		B.getcapture(playerB, good, bad);
		if(bad == 3) {
			takevalue = 25;
		}
		else {
			takevalue = 100;
		}
		//Set static values;
		//Set Gates:
		value[5][0] = 100;
		value[5][5] = 100;
		//Check if there is opp team pieces near player gates:
		if(B.getowner(1,0) != empty && B.getowner(1,0) != whoiam) { //Is an opponent piece
			value[1][0] = takevalue;
		}
		if(B.getowner(0,1) != empty && B.getowner(0,1) != whoiam) { //Is an opponent piece
			value[0][1] = takevalue;
		}
		if(B.getowner(0,4) != empty && B.getowner(0,4) != whoiam) { //Is an opponent piece
			value[0][3] = takevalue;
		}
		if(B.getowner(1,5) != empty && B.getowner(1,5) != whoiam) { //Is an opponent piece
			value[1][5] = takevalue;
		}
		int rowvalue = 30; //For forward progress
		for(int x = 0; x < 6; x++) {
			for(int y = 0; y < 6; y++) {
				if(value[x][y] == 0) {
					if(B.getowner(x,y) == empty) {
						//Check ahead of empty square for opp or player peieces
						bool oppLocated = false;
						if(x + 1 < 6) {	
							if(B.getowner(x + 1, y) != whoiam && B.getowner(x + 1, y) != empty) {
								oppLocated = true;
							}
						}
						if(x - 1 >= 0) {
							if(B.getowner(x - 1, y) != whoiam && B.getowner(x - 1, y) != empty) {
								oppLocated = true;
							}
						}
						if(y + 1 < 6) {	
							if(B.getowner(x, y + 1) != whoiam && B.getowner(x, y + 1) != empty) {
								oppLocated = true;
							}
						}
						if(y - 1 >= 6) {	
							if(B.getowner(x, y - 1) != whoiam && B.getowner(x, y - 1) != empty) {
								oppLocated = true;
							}
						}
						if(oppLocated) {
							value[x][y] = rowvalue - 50;
						}
						else {
							value[x][y] = rowvalue;
						}
					}
					else if(B.getowner(x,y) == whoiam) {
						value[x][y] = -100;
					}
					else {
						value[x][y] = takevalue; //Take opponent piece
					}
				}
			}
			rowvalue = rowvalue + 10;
		}
	}
	else {
		B.getcapture(playerA, good, bad);
		if(bad == 3) {
			takevalue = 25;
		}
		else {
			takevalue = 100;
		}
		//Set static values;
		//Set Gates:
		value[0][0] = 100;
		value[0][5] = 100;
		//Check if there is opp team pieces near player gates:
		if(B.getowner(4,0) != empty && B.getowner(4,0) != whoiam) { //Is an opponent piece
			value[4][0] = takevalue;
		}
		if(B.getowner(5,1) != empty && B.getowner(5,1) != whoiam) { //Is an opponent piece
			value[5][1] = takevalue;
		}
		if(B.getowner(4,5) != empty && B.getowner(4,5) != whoiam) { //Is an opponent piece
			value[4][5] = takevalue;
		}
		if(B.getowner(5,4) != empty && B.getowner(5,4) != whoiam) { //Is an opponent piece
			value[5][4] = takevalue;
		}
		int rowvalue = 90; //For forward progress
		for(int x = 0; x < 6; x++) {
			for(int y = 0; y < 6; y++) {
				if(value[x][y] == 0) {
					if(B.getowner(x,y) == empty) {
						//Check ahead of empty square for opp or player peieces
						bool oppLocated = false;
						if(x + 1 < 6) {	
							if(B.getowner(x + 1, y) != whoiam && B.getowner(x + 1, y) != empty) {
								oppLocated = true;
							}
						}
						if(x - 1 >= 0) {
							if(B.getowner(x - 1, y) != whoiam && B.getowner(x - 1, y) != empty) {
								oppLocated = true;
							}
						}
						if(y + 1 < 6) {	
							if(B.getowner(x, y + 1) != whoiam && B.getowner(x, y + 1) != empty) {
								oppLocated = true;
							}
						}
						if(y - 1 >= 6) {	
							if(B.getowner(x, y - 1) != whoiam && B.getowner(x, y - 1) != empty) {
								oppLocated = true;
							}
						}
						if(oppLocated) {
							value[x][y] = rowvalue - 50;
						}
						else {
							value[x][y] = rowvalue;
						}
					}
					else if(B.getowner(x,y) == whoiam) {
						value[x][y] = -100;
					}
					else {
						value[x][y] = takevalue; //Take opponent piece
					}
				}
			}
			rowvalue = rowvalue - 10;
		}
	}
	//Select move:
	int thisValue = 0; //Best calculated outcome
	for(int x = 0; x < 6; x++) {
		for(int y = 0; y < 6; y++) {
			if(B.getowner(x,y) == whoiam) { //Is the player's piece
				//Checks the available matrix of the piece
				if(x - 1 >= 0) {
					if(value[x - 1][y] > thisValue && B.getowner(x - 1,y) != whoiam) {
						thisValue = value[x - 1][y];
						x1 = x;
						y1 = y;
						x2 = x - 1;
						y2 = y;
					}
				}
				if(x + 1 < 6) {
					if(value[x + 1][y] > thisValue && B.getowner(x + 1,y) != whoiam) {
						thisValue = value[x + 1][y];
						x1 = x;
						y1 = y;
						x2 = x + 1;
						y2 = y;
					}
				}
				if(y - 1 >= 0) {
					if(value[x][y - 1] > thisValue && B.getowner(x,y - 1) != whoiam) {
						thisValue = value[x][y - 1];
						x1 = x;
						y1 = y;
						x2 = x;
						y2 = y - 1;
					}
				}
				if(y + 1 < 6) {
					if(value[x][y + 1] > thisValue && B.getowner(x,y + 1) != whoiam) {
						thisValue = value[x][y + 1];
						x1 = x;
						y1 = y;
						x2 = x;
						y2 = y + 1;
					}
				}
			}
		}
	}
	cerr << "adamplayer response is (" << x1 << "," << y1 << ") to (" << x2 << "," << y2 << ")" << endl;
};

