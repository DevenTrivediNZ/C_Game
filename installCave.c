#include <stdio.h>
#include <stdlib.h>

#define CAVE_SIZE 10

// print cave function 
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
                    cave[i][j] = 0;
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

int main(void){

    char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111"; 
 int cave[CAVE_SIZE][CAVE_SIZE] = {0}; 
 InitialiseCave(cave, layout); 
 PrintCave(cave); 

}