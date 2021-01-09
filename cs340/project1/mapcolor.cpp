#include<cassert>
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;

struct state {
    string initial;
    int position;
    int color;
    state* nextstate = NULL;
};

//getPosition takes a string integer, and the array of reference states
// returns the position of the state given.
int getPosition(string ini, vector<state> states) {
    int position = 0;
    while (true) {
        if (states[position].initial == ini) {
            break;
        }
        position++;
    }
    
    return position;
}
//Recursize call for coloring
int graphColoring(int cState, vector<state> &mapArray, vector<state> &repArray) {
	if (cState > mapArray.size()) return 0;
	int color = 1;
	int status = -1;
	state *next = new state;
	while(color < 5 and status == -1) {
		status = 0;
		next = mapArray[cState].nextstate;
		while(next != NULL) {
			if(repArray[next->position].color == color) {
				status = -1;
				break;
			}
			next = next->nextstate;
		}
		if(status == 0) {
			mapArray[cState].color = repArray[cState].color = color;
			status = graphColoring(++cState, mapArray, repArray);
		}
		else {
			color++;
		}
	}
	return status;
}

int main() {
    vector<state> mapArray, representationArray;
    string fileName, inData;
    ifstream inFile;
    int count = 0;

    cout<<"Enter the name of file: ";
    cin>>fileName;
    cout<<endl;

    //Populating representationArray - Assigning a value to each state

    inFile.open(fileName.c_str());
    assert(inFile.is_open());
    cout<<"File "<<fileName<<" opened for representationArray.\n";

   while(getline(inFile, inData)) { //Representation Array
        string stateIni;
        stringstream inLine(inData);
        getline(inLine, stateIni, ',');
        representationArray.push_back(state());
        representationArray[count].initial = stateIni;
        representationArray[count].position = count;
        representationArray[count].color = 0;
        count++;
    }
    inFile.close();
	
    //Populating mapArray - Populating each state object with the given information
    inFile.open(fileName.c_str());
    assert(inFile.is_open());
    cout << "File " << fileName << " opened for map declaration.\n";
	count = 0;
	while(getline(inFile, inData)) {
		string stateIni;
		stringstream inLine(inData);
		state *nextState;
		bool first = true;
		//https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
		while(getline(inLine,stateIni,',')) {
			if(first) { //Is the first state in the line
				mapArray.push_back(state());
				mapArray[count].initial = stateIni;
				mapArray[count].position = getPosition(stateIni, representationArray);
				mapArray[count].color = 0;
				first = false;
			}
			else { //Is a state connected to the first state, make new node
				state *newState = new state;
				newState->initial = stateIni;
				newState->position = getPosition(newState->initial, representationArray);
				newState->color = 0;
				if (mapArray[count].nextstate == NULL) {
					mapArray[count].nextstate = newState;
				}
				else {
					nextState->nextstate = newState;
				}
				nextState = newState;
			}
		}
		count++;
	}
    inFile.close();

	int colorStatus = graphColoring(0, mapArray, representationArray);
	if(colorStatus == -1) {
		cout<<"Coloring failed.\n";
	}
	else {
		cout<<"Coloring complete.\n";
		int x = 0;
		for(const state x : representationArray) {
			cout<<x.initial<<" "<<x.color<<endl;
		}
	}

}
