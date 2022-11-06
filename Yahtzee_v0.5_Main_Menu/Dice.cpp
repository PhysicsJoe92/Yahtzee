/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Dice.h"

Dice::Dice(){
    size=0;
    string one,two,three,four,five,six;
    
    getline(fstream("res/Faces/One.txt"),one,'\0');
    getline(fstream("res/Faces/Two.txt"),two,'\0');
    getline(fstream("res/Faces/Three.txt"),three,'\0');
    getline(fstream("res/Faces/Four.txt"),four,'\0');
    getline(fstream("res/Faces/Five.txt"),five,'\0');
    getline(fstream("res/Faces/Six.txt"),six,'\0');
    
    picDie[Face::ONE]=one;
    picDie[Face::TWO]=two;
    picDie[Face::THREE]=three;
    picDie[Face::FOUR]=four;
    picDie[Face::FIVE]=five;
    picDie[Face::SIX]=six;
}

Dice::Dice(int s){
    size=s;
    string one,two,three,four,five,six;
    
    getline(fstream("res/Faces/One.txt"),one,'\0');
    getline(fstream("res/Faces/Two.txt"),two,'\0');
    getline(fstream("res/Faces/Three.txt"),three,'\0');
    getline(fstream("res/Faces/Four.txt"),four,'\0');
    getline(fstream("res/Faces/Five.txt"),five,'\0');
    getline(fstream("res/Faces/Six.txt"),six,'\0');
    
    picDie[Face::ONE]=one;
    picDie[Face::TWO]=two;
    picDie[Face::THREE]=three;
    picDie[Face::FOUR]=four;
    picDie[Face::FIVE]=five;
    picDie[Face::SIX]=six;
    
}

void Dice::setSize(int s){
    size=s;
    
}

void Dice::printDice(){
    DiceType itr = dice.begin();

    int counter=1;
    cout<<endl;
    for(itr;itr!=dice.end();itr++){
        cout<<"  Dice "<<counter++<<endl;
        cout<<picDie[*itr]<<endl;
    }
}

void Dice::rollDice(int keep[],int length){
    list<Face> temp;
   
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
            int rnd=rand()%6;
            Face val=static_cast<Face>(rnd);
            *ditr=val;
        }
        else titr++;
    }
    dice.sort();
}

int Dice::getDiceVal(Face val){
    DiceType itr = dice.begin();
    int score=0;
    switch(val){
        //Add all the ones in dice
        case Face::ONE:{
            for(itr;itr!=dice.end();itr++){
                if(*itr==Face::ONE){
                    score+=1;
                }
            }
            break; 
        }
        //Add all the twos in dice
        case Face::TWO:{
            for(itr;itr!=dice.end();itr++){
                if(*itr==Face::TWO){
                    score+=2;
                }
            }
            break;
        }
        //Add all the threes in dice
        case Face::THREE:{
            for(itr;itr!=dice.end();itr++){
                if(*itr==Face::THREE){
                    score+=3;
                }
            }
            break;
        }
        //Add all the fours in dice
        case Face::FOUR:{
            for(itr;itr!=dice.end();itr++){
                if(*itr==Face::FOUR){
                    score+=4;
                }
            }
            break;
        }
        //Add all the fives in dice
        case Face::FIVE:{
            for(itr;itr!=dice.end();itr++){
                if(*itr==Face::FIVE){
                    score+=5;
                }
            }
            break;
        } 
        case Face::SIX:{
            for(itr;itr!=dice.end();itr++){
                if(*itr==Face::SIX){
                    score+=6;
                }
            }
            break;
        }
        //Add all dice
        case Face::ALL: {
            for(itr;itr!=dice.end();itr++){
                //Count ones
                if(*itr==Face::ONE)         score+=1;
                else if(*itr==Face::TWO)    score+=2;
                else if(*itr==Face::THREE)  score+=3;
                else if(*itr==Face::FOUR)   score+=4;
                else if(*itr==Face::FIVE)   score+=5;
                else if(*itr==Face::SIX)    score+=6;
            }
        }break;//add all dice
    }
    return score;
}

bool Dice::is3Kind(){
    //At least 3 are the same face
    DiceType itr = dice.begin();
    Face face=*itr;
    itr++;
    int count=1;
    for(itr;itr!=dice.end();itr++){
        if(*itr==face) count++;
        else{ face=*itr; count=1;}
    }
    if(count==3) return true;
    return false;
}

bool Dice::is4Kind(){
    DiceType itr = dice.begin();
    Face face=*itr;
    itr++;
    int count=1;
    for(itr;itr!=dice.end();itr++){
        if(*itr==face)count++;
        else{ face=*itr; count=1;}
    }
    if(count==4) return true;
    return false;
}

bool Dice::isFullHouse(){
    //Full House
    //3 of one die 2 of another
    DiceType itr = dice.begin();
    Face fFace = *itr;
    Face sFace;
    itr++;
    
    int frst=1;
    int scnd=1;
    for(itr;itr!=dice.end();itr++){
        if(*itr==fFace){
            frst++;
        }
        else{
            sFace=*itr;
            itr++;
            break;
        }
    }
    
    for(itr;itr!=dice.end();itr++){
        if(*itr==sFace){
            scnd++;
        }
    }
    
    if(frst==2 && scnd==3 || frst==3 && scnd==2) return true;
    
    return false;
}

bool Dice::isSStraight(){
    //Small Straight
    //4 Consecutive face values
    DiceType itr=dice.begin();
    //Find starting face value
    Face val = *itr;
    //Iterate to the next die
    itr++;
    //So we can increment through the enum face class
    int temp=(int)val;
    //Number of consecutive face values
    int consec=0;
    for(itr;itr!=dice.end();itr++){
        if((Face)(temp+1)==*itr){
            consec++;
            temp++;
            val=(Face)temp;
        }
    }
    if(consec==3)return true;
    
    return false;
}

bool Dice::isLStraight(){
    //large Straight
    //5 Consecutive face values
    DiceType itr=dice.begin();
    //Find starting face value
    Face val = *itr;
    //Iterate to the next die
    itr++;
    //So we can increment through the enum face class
    int temp=(int)val;
    //Number of consecutive face values
    int consec=0;
    for(itr;itr!=dice.end();itr++){
        if((Face)(temp+1)==*itr){
            consec++;
            temp++;
            val=(Face)temp;
        }
    }
    if(consec==4)return true;
    
    return false;
}

bool Dice::isYahtzee(){
    //All 5 die the same
    DiceType itr=dice.begin();
    Face face=*itr;
    int yahtzee=1;
    for(itr;itr!=dice.end();itr++){
        if(*itr==face)yahtzee++;
    }
    if(yahtzee==5)return true;
    return false;
}

void Dice::roll(){
    dice.clear();
    Face val;
    int rnd;
    for(int i=0;i<size;i++){
        rnd=rand()%6;
        val=static_cast<Face>(rnd);
        dice.push_back(val);
    }
    dice.sort();
}

void Dice::debug(){
    dice.push_back(Face::ONE);
    dice.push_back(Face::ONE);
    dice.push_back(Face::ONE);
    dice.push_back(Face::ONE);
    dice.push_back(Face::ONE);
}