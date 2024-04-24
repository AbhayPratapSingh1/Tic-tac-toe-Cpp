#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Grid {
    protected :
        int gridSize;
        char positionsArray[3][3];
        char displayArray[15][15];
    public :
        Grid(){ // Setting the each item to ' ' to show nothing
            gridSize = 5;
            memset(positionsArray , ' ',sizeof(positionsArray));
            memset(displayArray , ' ',sizeof(displayArray));
        }
        bool fill(int posX, int posY, int player){
            cout<<posX<<" s "<<posY<<endl;
            if (positionsArray[posX][posY] == ' '){
                for (int i=posX*gridSize; i<posX*gridSize+gridSize; i++){
                    for (int j = posY*gridSize; j<posY*gridSize+gridSize; j++){     
                        if (player){  // filling X in the X pattern
                            if (i - posX*gridSize == j - posY*gridSize){  // find each location (between 0 - gridSize) in selected block of grid then turn 'X' digonally
                                displayArray[i][j]='X';
                            }
                            if(i - posX*gridSize == (gridSize - (j - posY*gridSize + 1))){   //  setting 'X' to location where (0  = gridSize - 0 - 1) digonal from other side 
                                displayArray[i][j]='X';
                            }
                        }
                        else if(!(player) && (i==posX*gridSize || i==posX*gridSize + gridSize - 1 || j==posY*gridSize || j==posY*gridSize + gridSize - 1 )) {   // setting the position of outside||border of the grid with 'O' if player is 'O'
                            displayArray[i][j] = '0';
                        }
                    }
                }
                positionsArray[posX][posY] = player?'X':'O';  // setting player piece to the specific location
                return 1;
            }
            return 0;
        }
        void showDis(char* statement){
            for (int i=0; i<gridSize*3 ; i++){
                for(int j =0 ; j<gridSize*3 ; j++){
                    if (j%gridSize == 0){
                        cout<<"||";
                    }
                    cout<<displayArray[i][j];
                }
                cout<<endl;
            }
            cout<<endl<<endl<<endl<<endl;
            cout<<statement<<endl;
        }
        void show(char* statement){    // Temperary code to show the basic grid of the game
            system("cls");
            cout<<"Started"<<endl;
            for (int i=0 ; i<3*gridSize ; i++){
                if (i%gridSize == 0 && i!= 0){
                    cout<<"------------------------"<<endl; // Giving horizontal line for the better look
                }
                for (int j = 0 ; j<3*gridSize ; j++){
                    if(j%gridSize == 0  && j!= 0){
                        cout<<" | ";   // giving vertical look for better view
                    }
                    cout<<displayArray[i][j];
                }
                cout<<endl;                
            }
            cout<<"Ended"<<endl;
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
                if ( positionsArray[i][0] != ' ' && ((positionsArray[i][0] == positionsArray[i][1]) && (positionsArray[i][1] == positionsArray[i][2]))){
                    winner = positionsArray[i][0];
                    return 1;
                }
                else if (positionsArray[0][i] != ' ' &&  (positionsArray[0][i] == positionsArray[1][i]) && (positionsArray[1][i] == positionsArray[2][i])){
                    winner = positionsArray[0][i];
                    return 1;
                }
            }
            if ( positionsArray[0][0] != ' ' &&  (positionsArray[0][0] == positionsArray[1][1]) && (positionsArray[1][1] == positionsArray[2][2])){
                winner = positionsArray[0][0];
                return 1;
            }
            else if( positionsArray[0][2] != ' ' && (positionsArray[0][2] == positionsArray[1][1]) && (positionsArray[1][1] == positionsArray[2][0])){
                winner = positionsArray[0][2];
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
