#include<iostream>
using namespace std;

class Tic {
    private:
    int mat [3][3] = {{0,1,2},
	   	      {0,1,2},
		      {0,1,2}};

    public:
    Tic () {	
        draw();
    }
    private:
    void draw () {
	for(int j = 0; j < 3; j++) {
	    for(int i = 0; i < 3; i++) {
		if (mat[j][i]==0) cout << "  ";
		if (mat[j][i]==1) cout << " ○";
		if (mat[j][i]==2) cout << " ×";
	    }
	    cout << endl;
	}
    }
};

int main () {
    Tic T1 = Tic();
    return 0;
}
