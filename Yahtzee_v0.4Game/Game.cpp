/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */
#include "Game.h"

Game::Game(){
    numP=1;
    dice.setSize(5);
}

void Game::start(){
    int temp;
    int highRoll;
    string name;
    vector<string> names;
    
    //Get the number of players
    cout<<"Enter the number of players: ";
    cin>>temp;
    while(temp<1 || temp>4){
        if(temp<1)cout<<"Needs at least 1 player."<<endl;
        else cout<<"Maximum number of 4 players."<<endl;
        cin>>temp;
    }
    numP=temp;
    cout<<"Enter player name"<<endl;
    for(int i=0;i<numP;i++){
        //Get name of each player
        cin.ignore(1000,'\n');
        getline(cin,name);
        //Put players into vector
        names.push_back(name);
    }
    int len=names.size();
    if(numP>1){
        cout<<"Randomizing player rotation"<<endl;
        for(int i=0;i<5;i++){
            for(int j=0;j<len;j++){
                //Swap names
                int indx1=rand()%len;
                int indx2=rand()%len;
                while(indx2==indx1)indx2=rand()%len;

                //Swap
                string tName=names[indx1];
                names[indx1]=names[indx2];
                names[indx2]=tName;

            }
        }
    }
    //Put players into queue
    for(int i=0;i<len;i++){
        Player player(names[i]);
        players.push(player);
    }
}

void Game::play(){
    bool endGame=gameOver();
    while(!endGame){
        Player currPlayer = players.front();
        currPlayer.takeTurn(dice);
        players.push(currPlayer);
        players.pop();
        endGame=gameOver();
    }
}

void Game::finish(){
    string winner;
    int highScore;
    
    Player currPlayer = players.front();
    winner=currPlayer.getName();
    highScore=currPlayer.getScore();
    
    players.push(currPlayer);
    players.pop();
    
    for(int i=1;i<players.size();i++){
        currPlayer = players.front();
        int score=currPlayer.getScore();
        if(score>highScore){
            winner=currPlayer.getName();
            highScore=score;
        }
        players.push(currPlayer);
        players.pop();
    }
    cout<<"Game winner: "<<winner<<endl;
    cout<<"Total Score: "<<highScore<<endl;
}

bool Game::gameOver(){
    Player player;
    bool gameOver;
    int count=0;
    
    while(count<numP){
        player=players.front();
        //Check if player has finished scoring
        if(!player.isPlayerDone()){
            //Put front player in back of queue
            players.push(player);
            //Pop front player
            players.pop();
            gameOver=false;
        }
        else gameOver=true;
        count++;
    }
    //Return if queue is empty or not
    return gameOver;
}