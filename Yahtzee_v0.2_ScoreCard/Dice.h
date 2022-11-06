/* 
 * File:   Dice.h
 * Author: Joseph Hernandez
 *
 * Created on November 1, 2022, 5:24 PM
 */

#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "Enums.h"

using namespace std;


class Dice{
    using DiceType = list<Face>::iterator;
    public:
        Dice(int);
        void printDice();
        void roll();
        void rollDice(int[],int);
        
        int getDiceVal(Face);
        
        bool is3Kind();
        bool is4Kind();
        bool isFullHouse();
        bool isSStraight();
        bool isLStraight();
        bool isYahtzee();
    private:
        list<Face> dice;
        size_t size;
};

#endif /* DICE_H */

