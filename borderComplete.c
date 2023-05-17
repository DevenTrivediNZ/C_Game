#include <stdio.h>
#include <stdlib.h>

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




// this function should check wether the border of the cave is complete
// it can contain no empty spaces and no corner exits as well as only 1 exit in the function

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
    int emptySpace = 0;
    int countExit = 0;
        for(int i = 0; i<CAVE_SIZE; i++){
            for(int j = 0; j<CAVE_SIZE; j++){
                if(cave[i][j] == 2){
                    countExit++;
                }
            }
        }

    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<CAVE_SIZE; j++){
            if(i == 0){
                if(cave[0][j] == 1){
                    borderCounter++;
                }
                if(cave[0][j] == 2){
                    exitCounter++;
                    
                }
                if(cave[0][j] == 0){
                    emptySpace++;
                }
            }
            if(i == 9){
                if(cave[9][j] == 1){
                    borderCounter++;
                }
             
                if(cave[9][j] == 2){
                    exitCounter++;
                }
                 if(cave[9][j] == 0){
                    emptySpace++;
                }
            }
                if(j == 0){
                if(cave[i][0] == 1){
                    borderCounter++;
                }
                if(cave[i][0] == 2){
                    exitCounter++;
                }
                 if(cave[i][0] == 0){
                    emptySpace++;
                }
            }

                if(j == 9){
                if(cave[i][9] == 1){
                    borderCounter++;
                }
                if(cave[i][9] == 2){
                    exitCounter++;
                }
                 if(cave[i][9] == 0){
                    emptySpace++;
                }
            }

            if(i == 0 && j == 0){
                if(cave[0][0] == 1){
                    borderCounter--;
                }
                if(cave[0][0] == 2){
                    cornerExit++;
                }
                 if(cave[0][0] == 0){
                    emptySpace++;
                }
                
            }

              if(i == 9 && j == 0){
                if(cave[9][0] == 1){
                    borderCounter--;
                }
                if(cave[9][0] == 2){
                    cornerExit++;
                }
                 if(cave[9][0] == 0){
                    emptySpace++;
                }
                
            }
              if(i == 0 && j == 9){
                if(cave[0][9] == 1){
                    borderCounter--;
                }
                if(cave[0][9] == 2){
                    cornerExit++;
                }
                 if(cave[0][9] == 0){
                    emptySpace++;
                }
                
            }

              if(i == 9 && j == 9){
                if(cave[9][9] == 1){
                    borderCounter--;
                }
                if(cave[9][9] == 2){
                    cornerExit++;
                }
                  if(cave[9][9] == 2){
                    emptySpace++;
                }
                
            }
           


            
        }
    }
    // if there are any exits and there are exit corners it changes the border exit counter to 100 
    // this makes sure that there is a unique number to identify in the statements
    if(countExit == 1){
        if(exitCounter == 1){
            exitCounter = 100;
    }
    }
    
    if(cornerExit >= 1 || emptySpace > 0 || countExit > 1  ){
       
        return 0;
       
    }


    if(borderCounter > 1 && emptySpace == 0 ){
        if(exitCounter == 100  || (countExit == 0)){
        return 1;
        }
        else{
          return 0;
      }
    }
    else{
        return 0;
    }

}

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
    
 

int main(void){

int caveB[CAVE_SIZE][CAVE_SIZE] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
PrintCave(caveB);
printf("Complete? %d\n", IsBorderComplete(caveB));
}