#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Grid {
    protected :
        char displayArray[3][3];
    public :
        Grid(){ // Setting the each item to ' ' to show nothing
            memset(displayArray , ' ',sizeof(displayArray));
        }
        bool fill(int posX, int posY, int player){
            if (displayArray[posX][posY] == ' '){
                displayArray[posX][posY] = player?'X':'O';  // setting player piece to the specific location
                return 1;
            }
            else {
                return 0;
            }
        }
        
        void show(char* statement){    // Temperary code to show the basic grid of the game
            system("cls");
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
            cout<<statement<<endl;
        }
};

class play : public Grid{
    char winner;
    public :
        void start(){
            char statement[300] = "O Player turn";  // statement to print in the show function
            int x,y;    // temperary way to take move input
            int player = 0;
            this->show(statement);
            while(!checkWin()){
                this->show(statement);
                cin>>x>>y;  // temperary way to take move input
                if (this->fill(x,y,player)) {
                    ++player %= 2;  // this means increase value then mod by 2 :- (0+1 % 2 = 1 OR 1+1 % 2 = 0)
                    strcpy(statement, player ? "X" : "O");
                    strcat(statement, " Player Turn");
                }
                else {
                    strcpy(statement, "Invalid Move try again");
                }
            }
            strcpy(statement, player ? "O" : "X");  // swaped player as player is change in the last round
            strcat(statement, " Player Won!\n Congracts");
            this->show(statement);
        }
        bool checkWin(){
            for (int i = 0 ; i<3 ; i++){
                if ( displayArray[i][0] != ' ' && ((displayArray[i][0] == displayArray[i][1]) && (displayArray[i][1] == displayArray[i][2]))){
                    winner = displayArray[i][0];
                    return 1;
                }
                else if (displayArray[0][i] != ' ' &&  (displayArray[0][i] == displayArray[1][i]) && (displayArray[1][i] == displayArray[2][i])){
                    winner = displayArray[0][i];
                    return 1;
                }
            }
            if ( displayArray[0][0] != ' ' &&  (displayArray[0][0] == displayArray[1][1]) && (displayArray[1][1] == displayArray[2][2])){
                winner = displayArray[0][0];
                return 1;
            }
            else if( displayArray[0][2] != ' ' && (displayArray[0][2] == displayArray[1][1]) && (displayArray[1][1] == displayArray[2][0])){
                winner = displayArray[0][2];
                return 1;
            }
            return 0;
        }
};

int main(){
    play a;
    a.start();
    return 0;
}
