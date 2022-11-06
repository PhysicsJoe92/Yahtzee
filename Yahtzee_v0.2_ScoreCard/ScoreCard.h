/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ScoreCard.h
 * Author: Joseph Hernandez
 *
 * Created on November 3, 2022, 12:42 AM
 */

#ifndef SCORECARD_H
#define SCORECARD_H

#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <functional>
#include "Dice.h"


class ScoreCard{
    using BVector = vector<bool>;
    using IVector = vector<int>;
    using IIVector= vector<IVector>;
    using SVector = vector<string>;
    public:
        ScoreCard();
        ~ScoreCard(){}
        void printScoreCard();
        void printCategories();
        bool setScoreCell(string,Dice);
        bool isCardFull();
        string format(string);
        int getScore();
    private:
        size_t currGame = 0;
        size_t numGames = 5;
        size_t upRows   = 9;
        size_t lwRows   = 11;
        size_t bSize    = 13;
        //Bit vector to hold if section is filled
        BVector bit_vector;
        //Stack to hold YAHTZEE BONUS
        stack<int> bonus;
        // container to hold upper section values (up to 5 games)
        IIVector upperSec;
        // container to hold lower section values (up to 5 games)
        IIVector lowerSec;
        // containter to hold upper section names
        SVector upperName;
        // container to hold lower section names
        SVector lowerName;
};

#endif /* SCORECARD_H */

