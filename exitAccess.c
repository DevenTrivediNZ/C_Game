#include <stdio.h>
#include <stdlib.h>
# define CAVE_SIZE 10


void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE]){

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
  
    int exitCounter = 0;
    int cornerExit = 0;
// counts the total amount of exits in the whole array
     int countExit = 0;
        for(int i = 0; i<CAVE_SIZE; i++){
            for(int j = 0; j<CAVE_SIZE; j++){
                if(cave[i][j] == 2){
                    countExit++;
                }
            }
        }
    // counts the number of exits on the borders 
    for(int i = 0; i<CAVE_SIZE; i++){
        for(int j = 0; j<CAVE_SIZE; j++){
            if(i == 0){              
                if(cave[0][j] == 2){
                    exitCounter++;
                }   
            }
            if(i == 9){            
                if(cave[9][j] == 2){
                    exitCounter++;
                }
                
            }
                if(j == 0){            
                if(cave[i][0] == 2){
                    exitCounter++;
                }               
            }

                if(j == 9){               
                if(cave[i][9] == 2){
                    exitCounter++;
                }              
            }
            // counts the exits for the corners of the array
            if(i == 0 && j == 0){              
                if(cave[0][0] == 2){
                    cornerExit++;
                }                               
            }

              if(i == 9 && j == 0){               
                if(cave[9][0] == 2){
                    cornerExit++;
                }               
            }
              if(i == 0 && j == 9){
                if(cave[0][9] == 2){
                    cornerExit++;
                }   
            }

              if(i == 9 && j == 9){
                 if(cave[9][9] == 2){
                    cornerExit++;
                }   
            } 
        }
    }
 // it returns 1 if there are no corner exits and only 1 exit otherwise returns 0   
 if(countExit == 1 && cornerExit == 0 && exitCounter == 1){
    return 1;

 }
 else{
    return 0;
 }

}

int main(void){

	
int caveA[CAVE_SIZE][CAVE_SIZE] = {
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
   {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
PrintCave(caveA);
printf("Accessible? %d\n", IsExitAccessible(caveA));
}