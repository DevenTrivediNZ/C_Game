#include <stdio.h>
# include <string.h>

# define CAVE_SIZE 10

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE]){
    int countPlayer = 1;

    
    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<=CAVE_SIZE; j++){
            
            if(j != CAVE_SIZE){
            // if it == 1 then it prints the border
            if(cave[i][j]==1){
                printf("#");
            }
            // if it = 0 then the code prints out an empty space " "
            if(cave[i][j] == 0){
                printf(" ");
            }
            // 2 is the unique interger for the exit and prints out as an empty space
            if(cave[i][j] == 2)
               printf(" ");
            
            // 3 is the unique interger for the player only prints out for 1 player else it prints out an empty space
            if(cave[i][j] == 3){
                if(countPlayer == 1){
                    printf("X");
                    countPlayer++;

                }
                else{
                    if(cave[i][j] == 3){
                    printf(" ");
                    }
                }
            }
           // 4 is the unique interger for the boulder prints out an O
            if(cave[i][j] == 4){
                
                printf("O");
                
            }
            // 5 is the special interger for the hole prints out an *
            if(cave[i][j] == 5){
                printf("*");
            }
            // 6 is the unique interger for the tressure prints out an +
            if(cave[i][j] == 6){
                printf("+");
            }
            }
            // if it is = to the cave size it will print out a new line
            else{

                printf("\n");
            }
        }

    }
    
    
    

}

void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout){

    int countString = 0;
    

    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<CAVE_SIZE; j++){
            
                // marks a unique number for each exit border or empty space 
                // depending on the layout
                // E is 2
                // 1 = 1 and 0 = 0
                if(layout[countString] == 'E'){
                    cave[i][j] = 2;
                    countString++;
                }
                else if(layout[countString] == '1'){
                    cave[i][j] = 1; 
                    countString++;
                } 
                else if(layout[countString] == '0'){
                    cave[i][j] = 0;
                    countString++;
                }  
           
        }
           
    }
        
       
 }
 
 void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element){  
    // predetermined number of players only 1
    int player = 0;
    // for the player
    int playerCheck = strncmp(element, "player", strlen(element));
    // for the boulder
    int boulder = strncmp(element, "boulder", strlen(element));
    // for the hole
    int hole = strncmp(element, "hole", strlen(element));
    // for the tressure
    int treasure = strncmp(element, "treasure", strlen(element));
    // four different independant loops 

    // for player  
        for(int i = 0; i<CAVE_SIZE; i++){
                for(int j = 0; j<CAVE_SIZE; j++){
                    if(cave[i][j] == 3){
                        player++;
                    }
               }
        }
        
        if(playerCheck == 0){
            for(int i = 0; i<CAVE_SIZE; i++){
                for(int j = 0; j<CAVE_SIZE; j++){
                    // only updates the array if there is an empty space and the rows and cols match
                        if(i == row && j == col && cave[i][j] == 0 && player == 0){
                            cave[i][j] = 3;
                            
                        }
                    
                
                }  
            }
        }
        
    
        // for the boulder
        // number 4 for the boulder
    if(boulder == 0){
        for(int k = 0; k<CAVE_SIZE; k++){
                for(int l = 0; l<CAVE_SIZE; l++){
                    
                        if(k == row && l == col && cave[row][col] == 0){
                            cave[k][l] = 4;
                        }
                    }
                
                
            }
    }

    // for the hole
    // number 5 for the hole
    if(hole == 0){
        for(int a = 0; a<CAVE_SIZE; a++){
                for(int b = 0; b<CAVE_SIZE; b++){
                    if(a == row && b == col && cave[row][col] == 0){
                    cave[a][b] = 5;
                }
                    
                
            }  
       }
    }
    // for the tressure 
    // number 6 for tressure
     if(treasure == 0){
        for(int c = 0; c<CAVE_SIZE; c++){
                for(int d = 0; d<CAVE_SIZE; d++){
                    if(c == row && d == col && cave[row][col] == 0){
                    cave[c][d] = 6;
                }
                    
                
            }  
       }
    }
       
        


}

// This function rotates the cave by 90 degrees everytime
// the way to go at this would be to create a temp array with some sort of mathematical equation which helps rotate the array by 90 
// degrees 
// then update the cave function with that 
// use i as j and j as i 

void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE]){



 for (int i = 0; i < CAVE_SIZE / 2; i++) {
        for (int j = i; j < CAVE_SIZE - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = cave[i][j];
            cave[i][j] = cave[CAVE_SIZE - 1 - j][i];
            cave[CAVE_SIZE - 1 - j][i] = cave[CAVE_SIZE - 1 - i][CAVE_SIZE - 1 - j];
            cave[CAVE_SIZE - 1 - i][CAVE_SIZE - 1 - j] = cave[j][CAVE_SIZE - 1 - i];
            cave[j][CAVE_SIZE - 1 - i] = temp;
        }
    }
}

int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
    int temp1 = 0;
    int temp2 = 0;
    int positionXTemp = 0;
    int positionYTemp = 0;
    char foward = 'w';
    char back = 's';
    char right = 'd';
    char left = 's';

if(move == 'w'){
    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<CAVE_SIZE; j++){
            if(cave[i][j] == 3){            
                positionXTemp = j;
                positionYTemp = i;
                if(cave[positionYTemp-1][positionXTemp ] == 0){
                    temp1 = cave[positionYTemp][positionXTemp];
                    cave[positionYTemp][positionXTemp] = 0;
                    cave[positionYTemp-1][positionXTemp] = temp1;
                        
                        return 0;
                    }
                      if(cave[positionYTemp - 1][positionXTemp] == 2){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp - 1][positionXTemp] = temp1;
                        return 2;
                    }
                     if(cave[positionYTemp - 1][positionXTemp] == 4 && cave[positionYTemp -2][positionXTemp] == 0){
                        temp1 = cave[positionYTemp][positionXTemp];
                        temp2 = cave[positionYTemp -1][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp - 1][positionXTemp] = temp1;
                        cave[positionYTemp - 2][positionXTemp] = temp2;
                        return 0;
                    }
                      if(cave[positionYTemp - 1][positionXTemp] == 4 && cave[positionYTemp -2][positionXTemp] == 5){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp - 1][positionXTemp] = temp1;
                        cave[positionYTemp - 2][positionXTemp] = 0;
                        return 0;
                    }
                    if(cave[positionYTemp - 1][positionXTemp] == 6){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp - 1][positionXTemp] = temp1;
                        return 0;
                    }
                    if(cave[positionYTemp - 1][positionXTemp] == 5){
                        cave[positionYTemp][positionXTemp] = 0;
                        
                        return 1;
                    }
                }

        }
    }




} 


if(move == 'a'){
    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<CAVE_SIZE; j++){
            if(cave[i][j] == 3){            
                positionXTemp = j;
                positionYTemp = i;
                if(cave[positionYTemp][positionXTemp-1 ] == 0){
                    temp1 = cave[positionYTemp][positionXTemp];
                    cave[positionYTemp][positionXTemp] = 0;
                    cave[positionYTemp][positionXTemp - 1] = temp1;
                        
                        return 0;
                    }
                      if(cave[positionYTemp][positionXTemp - 1] == 2){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp][positionXTemp - 1] = temp1;
                        return 2;
                    }
                     if(cave[positionYTemp][positionXTemp - 1] == 4 && cave[positionYTemp][positionXTemp - 2] == 0){
                        temp1 = cave[positionYTemp][positionXTemp];
                        temp2 = cave[positionYTemp][positionXTemp - 1];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp][positionXTemp - 1] = temp1;
                        cave[positionYTemp][positionXTemp - 2] = temp2;
                        return 0;
                    }
                      if(cave[positionYTemp ][positionXTemp - 1] == 4 && cave[positionYTemp ][positionXTemp - 2] == 5){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp][positionXTemp - 1] = temp1;
                        cave[positionYTemp][positionXTemp - 2] = 0;
                        return 0;
                    }
                    if(cave[positionYTemp][positionXTemp - 1] == 6){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp ][positionXTemp - 1] = temp1;
                        return 0;
                    }
                    if(cave[positionYTemp][positionXTemp - 1] == 5){
                        cave[positionYTemp][positionXTemp] = 0;
                        
                        return 1;
                    }
                    
                }

        }
    }




}


if(move == 's'){
    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<CAVE_SIZE; j++){
            if(cave[i][j] == 3){            
                positionXTemp = j;
                positionYTemp = i;
                if(cave[positionYTemp + 1][positionXTemp ] == 0){
                    temp1 = cave[positionYTemp][positionXTemp];
                    cave[positionYTemp][positionXTemp] = 0;
                    cave[positionYTemp + 1][positionXTemp] = temp1;
                        
                        return 0;
                    }
                    if(cave[positionYTemp + 1][positionXTemp] == 2){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp + 1][positionXTemp] = temp1;
                        return 2;
                    }
                     if(cave[positionYTemp + 1][positionXTemp] == 4 && cave[positionYTemp + 2][positionXTemp] == 0){
                        temp1 = cave[positionYTemp][positionXTemp];
                        temp2 = cave[positionYTemp + 1][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp + 1][positionXTemp] = temp1;
                        cave[positionYTemp + 2][positionXTemp] = temp2;
                        return 0;
                    }
                       if(cave[positionYTemp + 1 ][positionXTemp] == 4 && cave[positionYTemp + 2][positionXTemp] == 5){
                        temp1 = cave[positionYTemp][positionXTemp];                        
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp + 2][positionXTemp ] = 0;                        
                        cave[positionYTemp + 1][positionXTemp] = temp1;
                        return 0;
                    } 
                     if(cave[positionYTemp + 1][positionXTemp] == 6){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp + 1 ][positionXTemp] = temp1;
                        return 0;
                    }
                      if(cave[positionYTemp + 1][positionXTemp ] == 5){
                        cave[positionYTemp][positionXTemp] = 0;
                        
                        return 1;
                    }
                    
                }

        }
    }




}


if(move == 'd'){
    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<CAVE_SIZE; j++){
            if(cave[i][j] == 3){            
                positionXTemp = j;
                positionYTemp = i;
                if(cave[positionYTemp][positionXTemp + 1] == 0){
                    temp1 = cave[positionYTemp][positionXTemp];
                    cave[positionYTemp][positionXTemp] = 0;
                    cave[positionYTemp][positionXTemp + 1] = temp1;
                        
                        return 0;
                    }
                    if(cave[positionYTemp][positionXTemp + 1] == 2){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp ][positionXTemp + 1] = temp1;
                        return 2;
                    }
                    if(cave[positionYTemp][positionXTemp + 1] == 4 && cave[positionYTemp][positionXTemp + 2] == 0){
                        temp1 = cave[positionYTemp][positionXTemp];
                        temp2 = cave[positionYTemp][positionXTemp + 1];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp][positionXTemp + 1] = temp1;
                        cave[positionYTemp][positionXTemp + 2] = temp2;
                        return 0;
                    }
                      if(cave[positionYTemp ][positionXTemp + 1] == 4 && cave[positionYTemp][positionXTemp + 2] == 5){
                        temp1 = cave[positionYTemp][positionXTemp];                        
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp ][positionXTemp + 2 ] = 0;                        
                        cave[positionYTemp ][positionXTemp + 1] = temp1;
                        return 0;
                    } 
                    if(cave[positionYTemp][positionXTemp + 1] == 6){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp][positionXTemp + 1] = temp1;
                        return 0;
                    }
                      if(cave[positionYTemp][positionXTemp + 1] == 5){
                        cave[positionYTemp][positionXTemp] = 0;
                        
                        return 1;
                    }

                }


        }
    }




}
if(move != foward || move != back || move != right || move != left ){
    return 0;
}
    

}

int main(void){


char layout[200] = "1111111111100000000110000000011000000001100000000E10000000011000000001100000000110000000011111111111";
int cave[CAVE_SIZE][CAVE_SIZE] = {0};
InitialiseCave(cave, layout);
AddItem(cave, 7, 3, "player");
AddItem(cave, 2, 2, "boulder");
AddItem(cave, 2, 3, "boulder");
AddItem(cave, 4, 6, "boulder");
AddItem(cave, 5, 7, "boulder");
AddItem(cave, 6, 8, "boulder");
AddItem(cave, 7, 1, "hole");
AddItem(cave, 8, 3, "hole");
AddItem(cave, 6, 4, "treasure");
AddItem(cave, 3, 5, "treasure");
AddItem(cave, 1, 1, "treasure");
AddItem(cave, 8, 8, "treasure");
AddItem(cave, 5, 1, "hole");
AddItem(cave, 6, 1, "hole");

MakeMove(cave, 'w');
MakeMove(cave, 'd');
MakeMove(cave, 'd');
MakeMove(cave, 'd');
MakeMove(cave, 'd');
MakeMove(cave, 'w');
MakeMove(cave, 's');
MakeMove(cave, 'd');
MakeMove(cave, 'w');
MakeMove(cave, 's');
MakeMove(cave, 'a');

PrintCave(cave);
}