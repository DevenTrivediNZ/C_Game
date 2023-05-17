# include <stdio.h>
# include <string.h>    

# define CAVE_SIZE 10

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE]){
    int countPlayer = 1;

    
    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<=CAVE_SIZE; j++){
            
            if(j != CAVE_SIZE){
            if(cave[i][j]==1){
                printf("#");
            }
            if(cave[i][j] == 0){
                printf(" ");
            }
            if(cave[i][j] == 2)
               printf(" ");
            
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
           
            if(cave[i][j] == 4){
                
                printf("O");
                
            }
            if(cave[i][j] == 5){
                printf("*");
            }
            if(cave[i][j] == 6){
                printf("+");
            }
            }
            else{

                printf("\n");
            }
        }

    }

}





void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout){

    int countString = 0;
    int lengthString = strlen(layout);

    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<CAVE_SIZE; j++){
            //if(countString != lengthString){
                
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
            //}
        }
           
    }
        
       
 }




int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE]){
    
    // completely read through the 2D array
    // there can only be 1 exit that cant be on the corners eg (row 1, col 0,9), (row 9, col 0,9)
    // if there is more than one exit it returns 0
    // the rest of the borders should be all 1
    // borderCounter counts the amount of 1s or # in the border 
    // exitCounter counts the number of hastags

    int borderCounter = 0;
    int exitCounter = 0;
    int cornerExit = 0;
    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<CAVE_SIZE; j++){
            if(i == 0){
                if(cave[0][j] == 1){
                    borderCounter++;
                }
                if(cave[0][j] == 2){
                    exitCounter++;
                }
            }
            if(i == 9){
                if(cave[9][j] == 1){
                    borderCounter++;
                }
             
                if(cave[9][j] == 2){
                    exitCounter++;
                }
            }
                if(j == 0){
                if(cave[i][0] == 1){
                    borderCounter++;
                }
                if(cave[i][0] == 2){
                    exitCounter++;
                }
            }

                if(j == 9){
                if(cave[i][9] == 1){
                    borderCounter++;
                }
                if(cave[i][9] == 2){
                    exitCounter++;
                }
            }

            if(i == 0 && j == 0){
                if(cave[0][0] == 1){
                    borderCounter--;
                }
                if(cave[0][0] == 2){
                    cornerExit++;
                }
                
            }

              if(i == 9 && j == 0){
                if(cave[9][0] == 1){
                    borderCounter--;
                }
                if(cave[9][0] == 2){
                    cornerExit++;
                }
                
            }
              if(i == 0 && j == 9){
                if(cave[0][9] == 1){
                    borderCounter--;
                }
                if(cave[0][9] == 2){
                    cornerExit++;
                }
                
            }

              if(i == 9 && j == 9){
                if(cave[9][9] == 1){
                    borderCounter--;
                }
                if(cave[9][9] == 2){
                    cornerExit++;
                }
                
            }


            
        }
    }
    
    if(cornerExit >= 1){
        return 0;
    }

    if(borderCounter >= 35){
        return 1;
    }
    else{
        return 0;
    }

}

// counts the number of exits in the cave, there can only be one exit 
// can only be true if the exit isnt on the corner 
// returns 1 or 0; 
// intallise a variable to go through the isBorderComplete 
// if it is true then it counts for the number 2 in the array
// if there is only 1 E it returns true
int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE]){
    
    int countExit = 0;
        for(int i = 0; i<CAVE_SIZE; i++){
            for(int j = 0; j<CAVE_SIZE; j++){
                if(cave[i][j] == 2){
                    countExit++;
                }
            }
        }
    
        if(countExit == 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    
 

// This function must return a 1 if the exit position is on the outside border of the cave
// This function returns a 0 if the exit is located on the outer corners of the cave or if it is on the internal of the cave
// use the function isBorderComplete and the is exit unique function 
// if both functions return 1 then return a 1 if not then return 0
int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE]){
    int borderComplete = (IsBorderComplete(cave));
    int exitUnique = (IsExitUnique(cave));
    
        if(borderComplete == 1 && exitUnique == 1){
            return 1;
        }
        else{
            return 0;
        }


}




// this function adds items onto the the cave 
// Cases
// Player: "X" there can only be one player no more 
// Hole: "*" holes >= 0
// Tressure: "+" tressure >= 0, When the player steps on the tressure it dissapears
// Boulder: "o" Boulder >= 0, player pushes the boulders when they fall into the hole it covers the hole

// solution for tomorrow 

/* Might need to modify Task2 if that is allowed just need to give each item a unique number and when it reaches the print cave
just need to print out the specific symbol*/

/* This code prints out two X / player (it is only supposed to print 1)*/


void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char *element){  
    // predetermined number of players only 1
    int player = 1;
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
    
        if(playerCheck == 0 ){
            for(int i = 0; i<CAVE_SIZE; i++){
                for(int j = 0; j<CAVE_SIZE; j++){
                    // only updates the array if there is an empty space and the rows and cols match
                        if(i == row && j == col && cave[i][j] == 0){
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


int main(void){

char layout[200] = "1111111111100000000110000000011000000001100000000E10000000011000000001100000000110000000011111111111"; 
 int cave[CAVE_SIZE][CAVE_SIZE] = {0}; 
 InitialiseCave(cave, layout); 
 AddItem(cave, 5, 5, "boulder"); 
 AddItem(cave, 5, 6, "boulder"); 
 AddItem(cave, 5, 7, "boulder"); 
 AddItem(cave, 2, 2, "player"); 
 printf("Original position:\n"); 
 PrintCave(cave); 
 printf("First rotation:\n"); 
 RotateCave(cave); 
 PrintCave(cave); 
 printf("Second rotation:\n"); 
 RotateCave(cave); 
 PrintCave(cave); 
 printf("Third rotation:\n"); 
 RotateCave(cave); 
 PrintCave(cave); 
 printf("Fourth rotation:\n"); 
 RotateCave(cave); 
 PrintCave(cave);

    return 0;
}