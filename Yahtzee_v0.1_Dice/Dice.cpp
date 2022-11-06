/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Dice.h"

Dice::Dice(int s){
    size=s;
    FACE val;
    int rnd;
    for(int i=0;i<size;i++){
        rnd=rand()%6+1;
        val=static_cast<FACE>(rnd);
        dice.push_back(val);
    }
    dice.sort();
}

void Dice::printDice(){
    DiceType itr = dice.begin();
    int counter=1;
    cout<<endl;
    for(itr;itr!=dice.end();itr++){
        cout<<"Die "<<counter++<<":";
        cout<<"["<<(int)*itr<<"]"<<endl;
    }
    cout<<endl;
}

void Dice::rollDice(int keep[],int length){
    list<FACE> temp;
   
    //Sort keep array in ascending order
    for(int i=0;i<length-1;i++){
        for(int j=i+1;j<length;j++){
            if(keep[i]>keep[j]){
                int tmp=keep[i];
                keep[i]=keep[j];
                keep[j]=tmp;
            }
        }
    }
    
    DiceType ditr = dice.begin();
    
    int counter=0;
    int indx=0;
    for(ditr;ditr!=dice.end();ditr++){
        if(counter==keep[indx]){
            temp.push_back(*ditr);
            indx++;
        }
        counter++;
    }
    
    DiceType titr = temp.begin();
    ditr=dice.begin();
    
    for(ditr;ditr!=dice.end();ditr++){
        if(*ditr!=*titr){
            int rnd=rand()%6+1;
            FACE val=static_cast<FACE>(rnd);
            *ditr=val;
        }
        else titr++;
    }
    dice.sort();
}