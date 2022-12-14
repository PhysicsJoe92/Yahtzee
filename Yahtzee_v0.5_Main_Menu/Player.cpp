/*
 * File: Player.cpp
 * Author: Joseph Hernandez
 * Created on November 3, 2022, 9:50PM
 */

#include "Player.h"

Player::Player(){
    userName="";
}

Player::Player(string name){
    userName=name;
    //Open player save file, if no save file exist, create a new file
    fstream file;
    
    file.open("res/PlayerSaves/"+userName + ".sav", ios::in | ios::out);

    if(!isEmpty(file)){card.replaceCard(userName);}
    
    file.close();
}

Player::~Player(){
    card.saveCard(userName);
}

void Player::resetDKeep(int *dieKeep,int keep){
    for(int i=0;i<keep;i++){
        dieKeep[i]=8;
    }
}

void Player::setName(string name){
    userName=name;
    //Open player save file, if no save file exist, create a new file
    fstream file;
    
    file.open(userName + ".sav", ios::in | ios::out);

    if(isEmpty(file)){}//do nothing
    else card.replaceCard(userName);
    
    file.close();
}

void Player::throwDice(Dice& dice,int keep){
    int *diceKept=new int[keep];
    resetDKeep(diceKept,keep);
    
    if(keep==0) dice.roll();
    else{
        cout<<setw(21)<<""<<"Which die would you like to hold(1-5)?"<<endl;
        int dk;
        cout<<setw(21)<<""<<"Hold: ";
        for(int i=0;i<keep;i++){
            cin>>dk;
            while(dk<1 || dk>5){
                cout<<setw(21)<<""<<dk<<" Not Valid:"<<endl;
                cout<<setw(21)<<""<<"Select dice 1-5"<<endl;
                cout<<setw(21)<<"";
                cin.clear();
                cin.ignore(1000,'\n');
                cin>>dk;
            }
            if(count(diceKept,diceKept+keep,dk-1)>0){
                cout<<setw(21)<<""<<dk<<" already entered."<<endl;
                cout<<setw(21)<<""<<"Select Different Die"<<endl;
                cout<<setw(21)<<"";
                cin.clear();
                cin.ignore(1000,'\n');
                cin>>dk;
            }
            diceKept[i]=dk-1;
        }
        
        sort(diceKept,diceKept+keep);
        
        cout<<setw(21)<<""<<"Dice Kept: ";
        for(int i=0;i<keep;i++){
            cout<<diceKept[i]+1<<" ";
        }
        cout<<endl;
    }
    dice.rollDice(diceKept,keep);
    delete diceKept;
    diceKept=nullptr;
}

void Player::takeTurn(Dice& dice){
    int turns=0;
    int keep=0;
    cout<<setw(21)<<""<<userName<<"'s Turn:"<<endl;
    do{
        if(keep==0||turns==0){
            throwDice(dice,keep);
            turns++;
            keep=-1;
            dice.printDice();
        }
        else{
            cout<<setw(21)<<""<<"How many dice would you like to keep?"<<endl;
            cout<<setw(21)<<""<<"Keep: ";
            cin>>keep;

            while(keep<0&&keep>5){
                cout<<setw(21)<<""<<"Select number of die to keep."<<endl;
                cout<<setw(21)<<""<<"0 to roll all dice, 1-5 to hold the"
                        <<"dice you want to keep.";
                cout<<setw(21)<<""<<"5 is to hold all the dice.";
                cout<<setw(21)<<"";
                cin>>keep;
            }
            
            if(keep!=5)
                throwDice(dice,keep);
            turns++;
            dice.printDice();
        }
    }while(keep!=5 && turns<3);
    selCat(dice);
}

void Player::selCat(Dice dice){
    string category;
    card.printCategories();
    cout<<endl;
    
    cout<<setw(21)<<""<<"Select Category: ";
    
    cin.ignore(1000,'\n');
    getline(cin,category);
    
    bool filled = card.setScoreCell(category,dice);
    
    while(!filled){
        getline(cin,category);
        filled=card.setScoreCell(category,dice);
    }
}

void Player::printCard(){
    cout<<endl;
    cout<<setw(21)<<""<<userName<<": ";
    card.printScoreCard();
    cout<<endl<<endl;
}

void Player::totScore(){
    score=card.getScore();
}

bool Player::isEmpty(fstream& file){
    return file.peek() == fstream::traits_type::eof();
}

bool Player::isPlayerDone(){
    bool done=card.isCardFull();
    if(done)score=card.getScore();
    return done;
}