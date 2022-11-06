/*
 * File: main.cpp
 * Author: Joseph Hernandez
 * Created on November, 1 2022, 12:00PM
 */


#include "Dice.h"

using namespace std;

int main(int argc, char** argv) {
    srand((unsigned int)time(0));
    Dice dice(5);
    
    dice.printDice();
    
    int keep;
    int dk;
    cout<<"How many would you like to keep?"<<endl;
    cin>>keep;
    int kp[keep];
    
    cout<<"Keep what?"<<endl;
    for(int i=0;i<keep;i++){
        cin>>dk;
        kp[i]=dk-1;
    }
    dice.rollDice(kp,keep);
    
    dice.printDice();
    
    return 0;
}

