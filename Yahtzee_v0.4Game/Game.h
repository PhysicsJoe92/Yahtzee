
/* 
 * File:   Game.h
 * Author: Joseph Hernandez
 *
 * Created on November 4, 2022, 2:15 AM
 */

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dice.h"
#include <queue>

class Game{
    public:
        Game();
        void start();    //Start the game, init players and dice
        void play();
        void finish();
    private:
        int numP;
        Dice dice;
        queue<Player> players;
        
        //Check if each player is done
        bool gameOver();
};

#endif /* GAME_H */

