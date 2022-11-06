/* 
 * File:   main.cpp
 * Author: Joseph Hernandez
 * Created on November 3, 2022, 5:29 PM
 */

#include "Player.h"
#include "Dice.h"

using namespace std;



//Check if each player is done
bool gameOver(queue<Player>);

int main(int argc, char** argv) {
    srand((unsigned int)time(0));
    
    Dice dice(5);
    
    Player player("Joey");
    
    while(!player.isPlayerDone()){
        player.takeTurn(dice);
    }
    
    player.printCard();
    return 0;
}

bool gameOver(queue<Player> players,int numP){
    Player player;
    bool gameOver;
    int count=0;
    
    while(count<numP){
        player=players.front();
        //Check if player has finished scoring
        if(!player.isPlayerDone()){
            //Put front player in back of queue
            players.push(player);
            gameOver=false;
            //Pop front player
            players.pop();
        }
        else gameOver=true;
        count++;
    }
    //Return if queue is empty or not
    return gameOver;
}
