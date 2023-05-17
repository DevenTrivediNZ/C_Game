#include <stdio.h> 
#include <string.h>

/* ENGGEN131 C Project 2022 - Boulder Break */
#define _CRT_SECURE_NO_WARNINGS


#define CAVE_SIZE 10

void InitialiseStory(char* story){

   char tempStory[2000] = "It is a dark day and you're on a hike and fall into a cave. All of a sudden you see tonnes of gold laying there. It is\nyour choice, Do you want to get out quick or risk your life to be richer than any man or woman to have walked on this\nplanet. The choice is yours! Dont fall into the holes or you might end up losing your life";
    strcpy(story, tempStory);


}

// Task Two: PrintCave
// if there is a 1 in the array it prints a # for the border
// if there is a 0 or a 2 it prints out a empty space " "

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


    if(borderCounter > 1 && emptySpace == 0 ){
       
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
       // goes through the cave 2D array and find the unique identifier and counts it
        for(int i = 0; i<CAVE_SIZE; i++){
            for(int j = 0; j<CAVE_SIZE; j++){
                if(cave[i][j] == 2){
                    countExit++;
                }
            }
        }
    // if there is only 1 exit it will return 1 else it will return a 0
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
        
        
            for(int i = 0; i<CAVE_SIZE; i++){
                for(int j = 0; j<CAVE_SIZE; j++){
                    // only updates the array if there is an empty space and the rows and cols match
                        if(i == row && j == col && cave[i][j] == 0 && player == 0){
                            cave[i][j] = 3;
                            
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
               


void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE]){

int temp[CAVE_SIZE][CAVE_SIZE];

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
    int positionX2Temp = 0;
    int positionY2Temp = 0;
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
                positionX2Temp = j;
                positionY2Temp = i;
                if(cave[positionYTemp-1][positionXTemp ] == 0){
                    temp1 = cave[positionYTemp][positionXTemp];
                    cave[positionYTemp][positionXTemp] = 0;
                    cave[positionYTemp-1][positionXTemp] = temp1;
                        
                        return 0;
                    }
                      if(cave[positionYTemp - 1][positionXTemp] == 2){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp - 1][positionXTemp] = 0;
                        cave[positionYTemp - 1][positionXTemp] = temp1;
                        return 2;
                    }
                     if(cave[positionYTemp - 1][positionXTemp] == 4 && cave[positionYTemp -2][positionXTemp] == 0){
                       temp1 = cave[positionY2Temp][positionX2Temp];
                       cave[positionY2Temp - 1][positionX2Temp] = 0;
                        cave[positionY2Temp][positionX2Temp] = temp1;
                       while(cave[positionYTemp -2][positionXTemp] == 0 || cave[positionYTemp - 2][positionXTemp] == 5){
                        
                        temp2 = cave[positionYTemp -1][positionXTemp];                      
                        positionYTemp--;
                        if(cave[positionYTemp - 1][positionXTemp] == 5){
                            temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        
                        cave[positionYTemp - 1][positionXTemp] = 0;
                        return 0;
                        
                        
                    }
                        
                       }
                       cave[positionYTemp - 1][positionXTemp] = 4;
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
                positionX2Temp = j;
                positionY2Temp = i;
                if(cave[positionYTemp][positionXTemp-1 ] == 0){
                    temp1 = cave[positionYTemp][positionXTemp];
                    cave[positionYTemp][positionXTemp - 1] = 0;
                    cave[positionYTemp][positionXTemp - 1] = temp1;
                        
                        return 0;
                    }
                      if(cave[positionYTemp][positionXTemp - 1] == 2){
                        temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        cave[positionYTemp][positionXTemp - 1] = temp1;
                        return 2;
                    }
                    if(cave[positionYTemp ][positionXTemp - 1] == 4 && cave[positionYTemp][positionXTemp - 2] == 0){
                       temp1 = cave[positionY2Temp][positionX2Temp];
                       cave[positionY2Temp][positionX2Temp - 1] = 0;
                        cave[positionY2Temp][positionX2Temp] = temp1;
                       while(cave[positionYTemp][positionXTemp - 2] == 0 || cave[positionYTemp][positionXTemp - 2] == 5){
                        
                        temp2 = cave[positionYTemp][positionXTemp -1];                      
                        positionXTemp--;
                        if(cave[positionYTemp][positionXTemp - 1] == 5){
                            temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        
                        cave[positionYTemp][positionXTemp - 1] = 0;
                        return 0;
                        
                        
                    }
                        
                       }
                       cave[positionYTemp][positionXTemp - 1] = 4;
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
                     
                     if(cave[positionYTemp + 1 ][positionXTemp ] == 4 && cave[positionYTemp + 2][positionXTemp ] == 0){
                       temp1 = cave[positionY2Temp][positionX2Temp];
                       cave[positionY2Temp + 1][positionX2Temp] = 0;
                        cave[positionY2Temp][positionX2Temp] = temp1;
                       while(cave[positionYTemp + 2][positionXTemp] == 0 || cave[positionYTemp][positionXTemp  + 2] == 5){
                        
                        temp2 = cave[positionYTemp + 1][positionXTemp];                      
                        positionYTemp++;
                        if(cave[positionYTemp + 1][positionXTemp ] == 5){
                            temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        
                        cave[positionYTemp + 1 ][positionXTemp] = 0;
                        return 0;
                        
                        
                    }
                        
                       }
                       cave[positionYTemp + 2][positionXTemp ] = 4;
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
                
                      if(cave[positionYTemp ][positionXTemp + 1] == 4 && cave[positionYTemp][positionXTemp + 1] == 0){
                       temp1 = cave[positionY2Temp][positionX2Temp];
                       cave[positionY2Temp][positionX2Temp  + 1] = 0;
                        cave[positionY2Temp][positionX2Temp] = temp1;
                       while(cave[positionYTemp][positionXTemp + 2] == 0 || cave[positionYTemp][positionXTemp + 2] == 5){
                        
                        temp2 = cave[positionYTemp][positionXTemp - 1];                      
                        positionXTemp++;
                        if(cave[positionYTemp][positionXTemp + 1] == 5){
                            temp1 = cave[positionYTemp][positionXTemp];
                        cave[positionYTemp][positionXTemp] = 0;
                        
                        cave[positionYTemp][positionXTemp + 1] = 0;
                        return 0;
                        
                        
                    }
                        
                       }
                       cave[positionYTemp][positionXTemp + 1] = 4;
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
    return 0;

}



char GetMove(void){
	char move;
	printf("\nEnter move: ");
	scanf("%c", &move);
	// Ignore any characters that are invalid
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}

/* The Boulder Break simulation */
int main(void)
{
	char story[2000];
	char layout[200] = "1111111111100000000110000000011000000001100000000E10000000011000000001100000000110000000011111111111";
	int cave[CAVE_SIZE][CAVE_SIZE] = {0};
	int gameOver = 0;

	InitialiseStory(story);
	

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
AddItem(cave, 1, 8, "hole");
AddItem(cave, 6, 1, "hole");
 
	printf("ENGGEN131 - C Project 2022\n");
	printf("                          ... presents ...\n");
	printf("______   _____  _     _        ______  _______  ______\n");
	printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
	printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
	printf("______   ______ _______ _______ _     _\n");
	printf("|_____] |_____/ |______ |_____| |____/ \n");
	printf("|_____] |    \\_ |______ |     | |    \\_\n");
	printf("\n");
	printf("%s\n", story);
	printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
	printf("Good luck!\n\n\n");

	/* Main game loop */
	PrintCave(cave);
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
		}
	}

	return 0;
}


/***********************************************************/
/***********************************************************/
/******* A SIMPLE MAIN FUNCTION TO TEST YOUR PROGRESS ******/
/***********************************************************/
/***********************************************************/

/* You should add your own tests in here */
/* int main(void)
{
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
} */