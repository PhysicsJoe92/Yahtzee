/* 
 * File:   main.cpp
 * Author: Joseph Hernandez
 * Created on November 3, 2022, 5:29 PM
 */

#include "Game.h"

int main(int argc, char** argv) {
    srand((unsigned int)time(0));
    
    Game game;
    
    //Start the game
    game.start();
    
    //Game Loop
    game.play();
    
    //End the game
    game.finish();
    
    return 0;
}

