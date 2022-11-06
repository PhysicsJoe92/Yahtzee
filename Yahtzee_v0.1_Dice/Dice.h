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

using namespace std;

enum class FACE{ONE,TWO,THREE,FOUR,FIVE,SIX};

class Dice{
    using DiceType = list<FACE>::iterator;
    public:
        Dice(int);
        void printDice();
        void rollDice(int[],int);
    private:
        list<FACE> dice;
        size_t size;
};

#endif /* DICE_H */

