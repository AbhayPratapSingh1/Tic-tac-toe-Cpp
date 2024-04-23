#include<iostream>
using namespace std;

class Grid {
    private :
    char displayArray[3][3];
    public :
        Grid(){ // Setting the each item to ' ' to show nothing
            for (int i=0; i<3; i++){
                for (int j = 0; j<3; j++){
                    displayArray[i][j] = ' ';
                }
            }
        }
        void fill(int posX, int posY, char player){
            displayArray[posX][posY] = player;
        }
        void show(){    // Temperary code to show the basic grid of the game
            cout<<endl;
            for (int i=0 ; i<3 ; i++){
                for (int j = 0 ; j<3 ; j++){
                    cout<<"  "<<displayArray[i][j];
                    if (j!=2){  // print : so that 1 , 2 , 3 element in the row is seperated
                        cout<<"  :";
                    }
                }
                if (i!=2){  // print after 1st and 2nd row of grid so it is betwwen the 1,2,3 rows
                    cout<<endl<<" ..............."<<   endl;
                }
            }
            cout<<endl<<endl<<endl<<endl;

        }
};

int main(){
    Grid a;
    a.show();
    a.fill(0,0,'0');
    a.show();
    a.fill(0,1,'X');
    a.show();
    a.fill(0,2,'0');
    a.show();
    a.fill(1,0,'X');
    a.show();
    a.fill(1,1,'0');
    a.show();
    a.fill(1,2,'X');
    a.show();
    a.fill(2,0,'0');
    a.show();
    a.fill(2,1,'X');
    a.show();
    a.fill(2,2,'0');
    a.show();
    return 0;
}
