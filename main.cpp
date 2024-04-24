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
        char dottedString[15*2 + 9];
        int posY , posX;
    public :
        Grid(){ // Setting the each item to ' ' to show nothing
            posX = 0 ;
            posY = 0 ;
            gridSize = 5;
            memset(positionsArray, ' ', sizeof(positionsArray));
            memset(displayArray, ' ', sizeof(displayArray));
            memset(dottedString, '.', sizeof(dottedString));
        }
        bool fill(int player){
            if (posY<0 || posY>2 || posX < 0 || posX>2 ){
                return 0;
            }
            if (positionsArray[posY][posX] == ' '){
                for (int i=posY*gridSize; i<posY*gridSize+gridSize; i++){
                    for (int j = posX*gridSize; j<posX*gridSize+gridSize; j++){     
                        if (player){  // filling X in the X pattern
                            if (i - posY*gridSize == j - posX*gridSize){  // find each location (between 0 - gridSize) in selected block of grid then turn 'X' digonally
                                displayArray[i][j]=219; // 219 ascii char black box
                            }
                            if(i - posY*gridSize == (gridSize - (j - posX*gridSize + 1))){   //  setting 'X' to location where (0  = gridSize - 0 - 1) digonal from other side 
                                displayArray[i][j]=219; // 219 ascii char black box
                            }
                        }
                        else if(!(player) && (i==posY*gridSize || i==posY*gridSize + gridSize - 1 || j==posX*gridSize || j==posX*gridSize + gridSize - 1 )) {   // setting the position of outside||border of the grid with 'O' if player is 'O'
                            displayArray[i][j] = 219; 
                            // 219 ascii char black box
                        }
                    }
                }
                positionsArray[posY][posX] = player?'X':'O';  // setting player piece to the specific location
                return 1;
            }
            return 0;
        }
        void show(char* statement){    // Temperary code to show the basic grid of the game
            system("cls");
            cout<<endl<<endl;
            for (int i=0 ; i<3*gridSize ; i++){
                if (i%gridSize == 0 && i!= 0){
                    cout<<dottedString<<endl; // Giving horizontal line for the better look
                }
                for (int j = 0 ; j<3*gridSize ; j++){
                    if(j%gridSize == 0  && j!= 0){
                        cout<<"  :  ";   // giving vertical look for better view
                    }
                    cout<<displayArray[i][j]<<displayArray[i][j];
                }
                cout<<endl;                
            }
            cout<<endl<<endl;
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
            while(!checkWin() && !checkDraw()){
                this->input(statement);
                if (this->fill(player)) {
                    ++player %= 2;  // this means increase value then mod by 2 :- (0+1 % 2 = 1 OR 1+1 % 2 = 0)
                    strcpy(statement, player ? "X" : "O");
                    strcat(statement, " Player Turn");
                }
                else {
                    strcpy(statement, "Invalid Move try again");
                }
            }
            if (!checkDraw()){
                strcpy(statement, player ? "O" : "X");  // swaped player as player is change in the last round
                strcat(statement, " Player Won!\n Congracts");
            }
            else {
                strcpy(statement , "Its a draw");
            }
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
        bool checkDraw(){
            for (int i = 0 ; i<3 ; i++){
                for (int j=0 ; j<3 ; j++){
                    if (positionsArray[i][j] == ' '){
                        return 0;
                    }
                }
            }
            return 1;
        }
        bool input(char* statement){
            int op = 0 , prevop = 0;
            while(1){
                tempOptionFill();
                this->show(statement);
                op = _getch();
                int temp;
                if (op == 72){         // top
                    emptyLocationSet(-1,0);
                }
                else if (op == 75){   // left
                    emptyLocationSet(-1,1);
                }
                else if (op == 77){   // right
                    emptyLocationSet(1,1);
                }
                else if (op == 80){   // down
                    emptyLocationSet(1,0);
                }
                else if(op == 13){
                    return 1;
                }
            }
        }
        void normalisePos(){
            if (posX == -1){  // normalising X
                posX = 2;
            }
            else if(posX == 3) {
                posX = 0;
            } 
            if (posY == -1){  // normalising Y
                posY = 2;
            }
            else if(posY == 3) {
                posY = 0;
            } 
        }
        void emptyLocationSet(int value, bool changeX){
            if (changeX){
                posX += value;
                normalisePos();  // normalising the value of the posX between 0 - 2
                if (!(positionsArray[posY][posX]==' ')){
                    posX += value;
                    normalisePos();     // normalising the changes
                }
                if (!(positionsArray[posY][posX] == ' ')){
                    posY += value;
                    normalisePos();
                    emptyLocationSet( 0, 1);
                }
            }
            else {
                posY += value;
                normalisePos();
                if (!(positionsArray[posY][posX]==' ')){
                    posY += value;
                    normalisePos();  // normalising again
                }
                if (!(positionsArray[posY][posX] == ' ')){
                    posX += value;
                    normalisePos();
                    emptyLocationSet( 0, 0);
                }
            }
        }

        void tempOptionFill(){  // 1 for left 2 for rigth 3 for up and 4 for down step
            int temp = 0;
            for (int i = 0 ; i<3 ; i++){
                for(int j = 0 ; j<3 ; j++){
                    if (positionsArray[i][j] == ' '){
                        displayArray[i*gridSize][j*gridSize] = ' ';
                    } 
                }
            }
            if (positionsArray[posY][posX] == ' '){
                displayArray[posY*gridSize][posX*gridSize] = 127;
            }
        }
        bool isLineEmpty(int line , bool direction){  // direction 0 -> row 1 -> column
            if (direction){
                if (positionsArray[0][line] != ' ' && positionsArray[1][line] != ' ' && positionsArray[2][line] != ' '  ){
                    return 0;
                }
                return 1;
            }
            if (positionsArray[line][0] != ' ' && positionsArray[line][1] != ' ' && positionsArray[line][2] != ' '  ){
                return 0;
            }
            return 1;
        }
};

int main(){
    play a;
    a.start();
    return 0;
}