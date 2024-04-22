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
        void fill(int position, int player){
            switch (position){  // Setting the value at the position with the player 0 or 1
                case 1:
                    displayArray[0][0] = player? 'X' : 'O';
                    break;
                case 2:
                    displayArray[0][1] = player? 'X' : 'O';
                    break;
                case 3:
                    displayArray[0][2] = player? 'X' : 'O';
                    break;
                case 4:
                    displayArray[1][0] = player? 'X' : 'O';
                    break;
                case 5:
                    displayArray[1][1] = player? 'X' : 'O';
                    break;
                case 6:
                    displayArray[1][2] = player? 'X' : 'O';
                    break;
                case 7:
                    displayArray[2][0] = player? 'X' : 'O';
                    break;
                case 8:
                    displayArray[2][1] = player? 'X' : 'O';
                    break;
                case 9:
                    displayArray[2][2] = player? 'X' : 'O';
                    break;
            }
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
    a.fill(1,0);
    a.show();
    a.fill(2,1);
    a.show();
    a.fill(3,0);
    a.show();
    a.fill(4,1);
    a.show();
    a.fill(5,0);
    a.show();
    a.fill(6,1);
    a.show();
    a.fill(7,0);
    a.show();
    a.fill(8,1);
    a.show();
    a.fill(9,0);
    a.show();
    return 0;
}
