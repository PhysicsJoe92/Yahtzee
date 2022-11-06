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

#include <fstream>
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
        ScoreCard();//Default Constructor
        ~ScoreCard(){}
        void printScoreCard();
        void printCategories();
        void saveCard(string);
        void replaceCard(string);
        int getScore();
        
        bool setScoreCell(string,Dice);
        bool isCardFull();
        
        static string format(string);
        
        inline int getCurrGame(){return currGame;}
        
    private:
        int currGame = 0;
        int numGames = 5;
        int upRows   = 9;
        int lwRows   = 11;
        int bSize    = 13;
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

