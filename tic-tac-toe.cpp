#include<iostream>
#include<string>
using namespace std;

class Tic {
    private:
    int mat [9] = {0,0,0,
	    	   0,0,0,
		   0,0,0};
    int win [8][3] = {{0,1,2},
	    	      {3,4,5},
	  	      {6,7,8},
		      {0,3,6},
		      {1,4,7},
		      {2,5,8},
 		      {0,4,8},
		      {2,4,6}};
    int moves = 9;
    int moveX = 0;
    int moveY = 0;
    int player = 1;

    public:
    Tic () {
        draw();
	action();
    }
    private:
    void draw () {
	cout << "\e[2J\e[H";    
	for(int j = 0; j < 3; j++) {
	    for(int i = 0; i < 3; i++) {
		int loc = mat[j*3+i];
		if (loc == 0) cout << " □";
		if (loc == 1) cout << " ○";
		if (loc == 2) cout << " ×";
	    }
	    cout << endl;
	}
    }
    private:
    void action () {
	getInput(player, "");
	
	if(player == 1) mat[moveY*3 + moveX] = 1;
	else mat[moveY*3 + moveX] = 2;	

	draw();

        if(result() == 1) {
            cout << "player" << player << " win!!" << endl;
	} else {
	    action();
	}
	player = player==1?2:1;
    }
    private:
    int result () {
        for (int j = 0; j < 8; j++) {
		int isMatch = 3;
		int firstN = mat[win[j][0]];
	    for (int i = 0; i < 3; i++) {
		if (mat[win[j][i]] == 0) break;
	        if (mat[win[j][i]] == firstN) isMatch--;  
	    }
	    if (isMatch == 0) {
		return 1;
	    }
	}
	return 0;
    }
    private:
    bool isMoveValid () {
	int validity = 0;
	if(moveX < 3) validity++;
	if(moveY < 3) validity++;
	if(mat[moveY*3 + moveX] == 0) validity++;
	cout << "valid p:" << validity << endl;
	return validity==3?true:false;
    }
    private:
    void getInput(int pid, string msg) {
	cout << msg;
        cout << "player" << pid;
	cout << (player==1?" (○) ":" (×) ");
	cout << " Enter [row col]: " << endl;
        cin >> moveX >> moveY;
	moveX--;
	moveY--;
	if(!isMoveValid()) getInput(pid, "last move was invalid, retry!!");
    }
};

int main () {
    Tic T1;
    return 0;
}
