/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "ScoreCard.h"

ScoreCard::ScoreCard(){
    upperName.push_back("Aces");
    upperName.push_back("Twos");
    upperName.push_back("Threes");
    upperName.push_back("Fours");
    upperName.push_back("Fives");
    upperName.push_back("Sixes");
    upperName.push_back("Total Score");
    upperName.push_back("Bonus");
    upperName.push_back("Total");
    
    lowerName.push_back("3 Of A Kind");
    lowerName.push_back("4 Of A Kind");
    lowerName.push_back("Full House");
    lowerName.push_back("Sm Straight");
    lowerName.push_back("Lg Straight");
    lowerName.push_back("YAHTZEE");
    lowerName.push_back("Chance");
    lowerName.push_back("YAHTZEE BONUS");
    lowerName.push_back("Total Lower");
    lowerName.push_back("Total Upper");
    lowerName.push_back("Grand Total");
    
    bit_vector = {0,0,0,0,0,0,0,0,0,0,0,0,0};
    IVector fillUp(9);
    IVector fillLw(11);
    fill(fillUp.begin(),fillUp.end(),0);
    fill(fillLw.begin(),fillLw.end(),0);
    
    //Initialize Upper Section scores
    for(int i=0;i<numGames;i++){
        upperSec.push_back(fillUp);
    }
    //Initialize Lower Section scores
    for(int i=0;i<numGames;i++){
        lowerSec.push_back(fillLw);
    }
}

bool ScoreCard::setScoreCell(string scoreSec, Dice dice){
    hash<string> matchHash;
    hash<string> getHash;
    Face val;
    int score;

    string ones     =upperName.at(0);
    string twos     =upperName.at(1);
    string threes   =upperName.at(2);
    string fours    =upperName.at(3);
    string fives    =upperName.at(4);
    string sixes    =upperName.at(5);
    string threeKind=lowerName.at(0);
    string fourKind =lowerName.at(1);

    //Upper Section
    //Count all ones
    if(matchHash(scoreSec)==getHash(upperName[0]) && bit_vector[0]!=1){
        val=Face::ONE; upperSec[currGame][0]=dice.getDiceVal(val);
        bit_vector[0]=1;
        return true;
    }
    //Count all twos
    else if(matchHash(scoreSec)==getHash(upperName[1]) && bit_vector[1]!=1){
        val=Face::TWO; upperSec[currGame][1]=dice.getDiceVal(val);
        bit_vector[1]=1;
        return true;
    }
    //Count all Threes
    else if(matchHash(scoreSec)==getHash(upperName[2]) && bit_vector[2]!=1){
        val=Face::THREE; upperSec[currGame][2]=dice.getDiceVal(val);
        bit_vector[2]=1;
        return true;
    }
    //Count all Fours
    else if(matchHash(scoreSec)==getHash(upperName[3]) && bit_vector[3]!=1){
        val=Face::FOUR; upperSec[currGame][3]=dice.getDiceVal(val);
        bit_vector[3]=1;
        return true;
    }
    //Count all Fives
    else if(matchHash(scoreSec)==getHash(upperName[4]) && bit_vector[4]!=1){
        val=Face::FIVE; upperSec[currGame][4]=dice.getDiceVal(val);
        bit_vector[4]=1;
        return true;
    }
    //Count all Sixes
    else if(matchHash(scoreSec)==getHash(upperName[5]) && bit_vector[5]!=1){
        val=Face::SIX; upperSec[currGame][5]=dice.getDiceVal(val);
        bit_vector[5]=1;
        return true;
    }
    //Lower Section
    //3 of a kind
    else if(matchHash(scoreSec)==getHash(lowerName[0]) && bit_vector[6]!=1){
        //Check if at least 3 faces are the same
        if(!dice.is3Kind()) lowerSec[currGame][0]=0;
        else{val=Face::ALL; lowerSec[currGame][0]=dice.getDiceVal(val);}
        bit_vector[6]=1;
        return true;
    }
    //4 of a kind
    else if(matchHash(scoreSec)==getHash(lowerName[1]) && bit_vector[7]!=1){
        //Check if at least 4 faces are the same
        if(!dice.is4Kind()) lowerSec[currGame][1]=0;
        else{val=Face::ALL; lowerSec[currGame][1]=dice.getDiceVal(val);}
        bit_vector[7]=1;
        return true;
    }
    //Full House
    else if(scoreSec==lowerName[2] && bit_vector[8]!=1){
        //Check if 3/2 dice are the same
        if(!dice.isFullHouse()) lowerSec[currGame][2]=0;
        else lowerSec[currGame][2]=25;
        bit_vector[8]=1;
        return true;
    }
    //Small Straight
    else if(scoreSec==lowerName[3] && bit_vector[9]!=1){
        //Check if 4 dice are in ascending order
        if(!dice.isSStraight())lowerSec[currGame][3]=0;
        else lowerSec[currGame][3]=30;
        bit_vector[9]=1;
        return true;
    }
    //Large Straight
    else if(scoreSec==lowerName[4] && bit_vector[10]!=1){
        //Check if 5 dice are in ascending order
        if(!dice.isLStraight()) lowerSec[currGame][4]=0;
        else lowerSec[currGame][4]=40;
        bit_vector[10]=1;
        return true;
    }
    //YAHTZEE
    else if(scoreSec==lowerName[5]){
        //Check all 5 die are the same
        if(dice.isYahtzee() && bit_vector[11]!=1){
            lowerSec[currGame][5]=50;
            bit_vector[11]=1;
        }
        //Check if YAHTZEE has been filled, if so push onto bonus stack
        else if(dice.isYahtzee() && bit_vector[11]==1){bonus.push(100);}
        else{lowerSec[currGame][5]=0;}
        return true;
    }
    //Chance
    else if(scoreSec==lowerName[6] && bit_vector[12]!=1){
        //Add up all the die
        val=Face::ALL; lowerSec[currGame][6]=dice.getDiceVal(val);
        bit_vector[12]=1;
        return true;
    }
    else{
        cout<<scoreSec<<":"<<endl;
        cout<<"Section Filled/Not Correct Selection"<<endl;
        cout<<"Make another selection"<<endl;
    }
    return false;
}

bool ScoreCard::isCardFull(){
    //Iterate through bit vector to indicate whether each section is filled
    bool full;
    for(int i=0;i<bit_vector.size();i++){
        //If the current section is filled, mark as true
        if(bit_vector[i]) full=true;
        //Else mark as false(not filled)
        else full=false;
    }
    return full;
}

void ScoreCard::printScoreCard(){
    string header   ="_______________________________________________________________\n";
    string headTitle="| Upper Section  | Game 1 | Game 2 | Game 3 | Game 4 | Game 5 |\n";
    string spacer   ="|-------------------------------------------------------------|\n";
    string bSepr8r  ="|_____________________________________________________________|\n";
    string lwrSec   ="| Lower Section  |        |        |        |        |        |\n"; 
    
    //Print headers
    cout<<header;
    cout<<headTitle;
    cout<<spacer;
    //Print Upper Section
    for(int i=0;i<upRows;i++){
        if(upperName[i].length()==4)cout<<"| "<<upperName[i]<<setw(12)<<"|";
        else if(upperName[i].length()==6)cout<<"| "<<upperName[i]<<setw(10)<<"|";
        else if(upperName[i].length()==11)cout<<"| "<<upperName[i]<<setw(5)<<"|";
        else cout<<"| "<<upperName[i]<<setw(11)<<"|";
        
        for(int j=0;j<numGames;j++){
            cout<<setw(4)<<upperSec[j][i]<<setw(5)<<"|";
        }
        cout<<endl;
        if(i>=5 && i<=9)cout<<spacer;
    }
    cout<<bSepr8r;
    
    
    //Print Lower Section
    cout<<lwrSec;
    cout<<spacer;
    for(int i=0;i<lwRows;i++){
        
        if(lowerName[i].length()==6)cout<<"| "<<lowerName[i]<<setw(10)<<"|";
        else if(lowerName[i].length()==7)cout<<"| "<<lowerName[i]<<setw(9)<<"|";
        else if(lowerName[i].length()==10)cout<<"| "<<lowerName[i]<<setw(6)<<"|";
        else if(lowerName[i].length()==11)cout<<"| "<<lowerName[i]<<setw(5)<<"|";
        else if(lowerName[i].length()==12)cout<<"| "<<lowerName[i]<<setw(4)<<"|";
        else if(lowerName[i].length()==13)cout<<"| "<<lowerName[i]<<setw(3)<<"|";
        else cout<<"| "<<lowerName[i]<<setw(2)<<"|";
        
        for(int j=0;j<numGames;j++){
            cout<<setw(4)<<lowerSec[j][i]<<setw(5)<<"|";
        }
        cout<<endl;
        if(i>=7&&i<=9)cout<<spacer;
    }
    cout<<bSepr8r;
}

void ScoreCard::printCategories(){
    cout<<setw(35)<<"|---------------|"<<endl;
    cout<<setw(35)<<"| Upper Section |"<<endl;
    cout<<setw(35)<<"|---------------|"<<endl<<endl;
    cout<<setw(5);
    int lmt=upperName.size()-3;
    for(int i=0;i<lmt;i++){
        cout<<" | "<<upperName[i]<<" | ";
        if(i==4)cout<<endl<<setw(5);
    }
    cout<<endl<<endl;

    cout<<setw(35)<<"|---------------|"<<endl;
    cout<<setw(35)<<"| Lower Section |"<<endl;
    cout<<setw(35)<<"|---------------|"<<endl<<endl;
    cout<<setw(5);
    lmt=lowerName.size()-4;
    for(int i=0;i<lmt;i++){
        cout<<" | "<<lowerName[i]<<" | ";
        if(i==2)cout<<endl<<setw(5);
    }
    cout<<endl;
}

string ScoreCard::format(string word){
    string cellScore=word;
    //Capitalize first character
    bool cap = true;//Indicate whether a letter has been capitalized
    for(int i=0;i<cellScore.length();i++){
        //Check if character is in the alphabet
        // and that we have not capitalized a letter yet.
        if(isalpha(cellScore[i]) && cap==true){
            //set character to upper case (letter - 32)
            cellScore[i] = toupper(word[i]);
            cap=false;
        }else if(isspace(cellScore[i])){
            cap=true;
        }
    }
    return cellScore;
}

int ScoreCard::getScore(){
    //Add ace-six score
    int rows=upRows-3;
    for(int i=0;i<rows;i++){
        for(int j=currGame;j<=currGame;j++){
            upperSec[currGame][6]+=upperSec[j][i];
        }
    }
    //Check if bonus is applicable(score >= 63)
    if(upperSec[currGame][6]>=63) upperSec[currGame][7]=35;
    //Add Upper Score Total
    upperSec[currGame][8]=upperSec[currGame][7]+upperSec[currGame][6];
    //Add Lower Section Total
    rows=lwRows-4;
    //Add lower section scores
    for(int i=0;i<rows;i++){
        for(int j=currGame;j<=currGame;j++){
            lowerSec[currGame][8]+=lowerSec[currGame][i];
        }
    }
    //Count Yahtzee bonus (if any)
    while(!bonus.empty()){
        lowerSec[currGame][8]+=bonus.top();
        bonus.pop();
    }
    //Get Totals
    //Upper Section Total
    lowerSec[currGame][9]=upperSec[currGame][8];
    lowerSec[currGame][10]=lowerSec[currGame][9]+lowerSec[currGame][8];
    
    //Return total score
    return lowerSec[currGame][10];
}