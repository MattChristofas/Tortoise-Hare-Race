//Matthew Christofas
//March 16, 2023
//CIS2017 Lab 7: Race
//The purpose of this program is to simulate and display the race between the
//tortoise and the hare using a random number
//generator and preset move types. The animal positions are accessed and modified
//using pointers, and the display is
//controlled using the sleep() function. Sometimes it takes a while due to slippage.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define RAND_MIN 0
#define RAND_MAX 100

#define INT_MIN 1
#define INT_MAX 10

int randomNumberGenerator(int min, int max);
void tortMove(int *tPtr);
void hareMove(int *hPtr);
void printRace(int hPos,int tPos);
int min(int hMin, int tMin);


int main(){

    srand((unsigned)time(NULL));

    
    int hPos =1; //hare start position is 1, cannot slip past 1
    int tPos = 1; //tortoise start position is 1,cannot slip past 1
    int *const tPtr = &tPos;
    int *const hPtr = &hPos;

    puts("\tON YOUR MARK, GET SET");
    puts("\tBANG !!!!"); //the spacing is modeled after the sample
    puts("\tAND THEY'RE OFF !!!!"); //the spacing is modeled after the sample
   

    while(hPos != 70 && tPos!=70){
        sleep(1); //slows down the race
        hareMove(&hPos);
        tortMove(&tPos);
        printRace(hPos,tPos);
        puts("");

        if (hPos >= 70){
            puts("\nHare wins. Yuch.\n");
            exit(0);
        }
        if (tPos >= 70){
            puts("\nTORTOISE WINS!!! YAY!!!\n");
            exit(0);
        }
        if (hPos >= 70 && tPos >= 70){
            puts("It's a tie!");
            exit(0);
        }
    }
}

//Finds minimum of hare or tortoise position to decide which position to print first

int min(int hMin, int tMin){

  if (hMin < tMin) {
        return hMin;
    } else {
        return tMin;
    }

}

//Prints the position of the H and T
void printRace(int hPos,int tPos){

 int minPos = min(hPos, tPos);

    for (int i = 1; i <= 70; i++) {
        if (i == hPos && i == tPos) {
            printf("OUCH!!!");
        } else if (i == hPos) {
            printf("H");
        } else if (i == tPos) {
            printf("T");
        } else {
            printf(" ");
        }
    }
}

//Controls the tortoise movement
void tortMove(int *tPtr){

int moveType = randomNumberGenerator(INT_MIN, INT_MAX);

    if (moveType >= 1 && moveType <= 5) {
        *tPtr += 3; // Fast plod
    } else if (moveType >= 6 && moveType <= 7) {
        *tPtr -= 6; // Slip
    } else {
        *tPtr += 1; // Slow plod
    }

    if (*tPtr < 1) {
        *tPtr = 1;
    }
}

//Controls the hare movement
void hareMove(int *hPtr){
    int moveType = randomNumberGenerator(INT_MIN, INT_MAX);

    if (moveType >= 1 && moveType <= 2){
        sleep(1); //sleep
    } else if (moveType >= 3 && moveType <= 4){
        *hPtr += 9; //Big hop
    } else if (moveType == 5){
        *hPtr -= 12; //Big slip
    } else if(moveType >= 6 && moveType <= 8){
        *hPtr += 1; //Small hop
    } else{
        hPtr -= 2; //Small slip
    }

    if (*hPtr < 1) {
    *hPtr = 1;
    }
    
}

//Generates random number from 1-10
int randomNumberGenerator(int min, int max){
    int num;

    num = rand() % (max - min + 1) + min;

    return num;
}