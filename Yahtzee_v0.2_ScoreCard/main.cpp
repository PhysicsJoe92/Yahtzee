/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Joseph Hernandez
 *
 * Created on November 1, 2022, 5:29 PM
 */
#include <algorithm>

#include "ScoreCard.h"
#include "Dice.h"

using namespace std;

void resetDKeep(int*,int);

int main(int argc, char** argv) {
    srand((unsigned int)time(0));
    ScoreCard myScore;

    Dice dice(5);//Create/Roll 5 dice
    int loop=0;
    //Game loop: check after each player goes to see if each players score card
    // is full. Need to put into a boolean vector where each index represents 
    // a player. This should be a function that iterates through each player 
    // score card calling isCardFull(), if any one of them is false(not filled)
    // then game will continue
    //Inside the game loop, there will be a loop that will give each player a 
    // turn at scoring. To do this, we will iterate through each player, checking
    // if their score card is full, if it not, then they will have a chance to
    // score, rolling the dice up to 3 times before choosing a category to score
    while(loop<3){
        int keep;//Number of die to keep
        int dk;//Die kept
        int rolls=0;//Number of turns for player

        cout<<"Rolling Dice..."<<endl;
        dice.roll();
        rolls++;
        
        dice.printDice();
        cout<<"How many dice would you like to keep?(0-5)"<<endl;
        cin>>keep;
        while(keep<0 || keep>5){
            cout<<"Select 0 for no dice or 5 for all dice"<<endl;
            cin>>keep;
        }
        int *dieKeep;
        //Loop for each player
        while(keep!=5 && rolls<3){
            dieKeep=new int[keep];
            resetDKeep(dieKeep,keep);
            cout<<"Which die do you want to keep (1-5)"<<endl;
            for(int i=0;i<keep;i++){
                cin>>dk;
                while(dk<1 || dk>5){
                    cout<<dk<<" NOT VALID:"<<endl;
                    cout<<"Only select dice 1-5"<<endl;
                    cin.ignore(1000,'\n');
                    cin>>dk;
                }
                if(count(dieKeep,dieKeep+keep,dk-1)>0){
                    cout<<dk<<" Already Selected"<<endl;
                    cout<<"Selection: ";
                    for(int i=0;i<keep;i++){
                        if(dieKeep[i]>=0 && dieKeep[i]<=4)
                            cout<<dieKeep[i]+1<<" ";
                    }
                    cout<<endl;
                    cout<<"Select Different Die"<<endl;
                    cin.ignore(1000,'\n');
                    cin>>dk;
                }
                dieKeep[i]=dk-1;
            }
            cout<<"Rolling Dice..."<<endl;
            dice.rollDice(dieKeep,keep);
            rolls++;
            
            dice.printDice();
            if(rolls!=3){
                cin.clear();
                cout<<"How many die would you like to keep(0-5)?"<<endl;
                cin>>keep;
                while(keep<0 || keep>5){
                    cout<<"Select 0 for no dice or 1-5 for the number of dice"<<endl;
                    cin>>keep;
                    //Reset dice kept
                    delete []dieKeep;
                    dieKeep=nullptr;
                }
            }
        }
        
        
        myScore.printCategories();
        cout<<"Which category would you like to fill?"<<endl;
        string category;
        cin.ignore(1000,'\n');
        do{
            getline(cin,category);
            category = myScore.format(category);
        }while(!myScore.setScoreCell(category,dice));

        
        
        loop++;
        delete []dieKeep;
    }
    cout<<endl;
    cout<<"Total Score:"<<endl;
    cout<<myScore.getScore()<<endl<<endl;
    myScore.printScoreCard();
    return 0;
}

void resetDKeep(int *dieKeep,int keep){
    for(int i=0;i<keep;i++){
        dieKeep[i]=8;
    }
}