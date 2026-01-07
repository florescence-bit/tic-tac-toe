#include<iostream>
using namespace std;

class Tic {
    private:
    int mat [9] = {0,1,2,
	    	   0,1,2,
		   0,1,2};
    int win [8] = {{0,1,2},
	    	  {3,4,5},
		  {6,7,8},
		  {0,3,6},
		  {1,4,7},
		  {2,5,8},
		  {0,4,8},
		  {2,4,6}};
    int moves = 9;

    public:
    Tic () {
	cout << "\e[2J\e[H";
        draw();
    }
    private:
    void draw () {
	for(int j = 0; j < 3; j++) {
	    for(int i = 0; i < 3; i++) {
		int loc = mat[j*3+i];
		if (loc) cout << " □";
		if (loc) cout << " ○";
		if (loc) cout << " ×";
	    }
	    cout << endl;
	}
    }
    private:
    void action () {
        if(moves == 0) result();
    }
    private:
    void result () {
        for (int j = 0; j < 12; j++) {
		bool isMatch = true;
	    for (int i = 0; i < 3; i++) {
		if (mat[win[j][i]]) break;
		int firstN = win[j][0];
	        mat[i] 
	    }
	}
    }
};

int main () {
    Tic T1 = Tic();
    return 0;
}
