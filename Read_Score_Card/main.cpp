/* 
 * File:   main.cpp
 * Author: Joseph Hernandez
 *
 * Created on October 23, 2022, 12:16 PM
 */

#include <iostream>
#include <list>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    string card;
    getline(fstream("Yahtzee_Score_Card.txt"),card,'\0');
    //cout<<card;
    int rowLen = 63;
    int row=34;
    int game1=21;
    int score=12;
    string val=to_string(score);
    card[(rowLen*3)+game1]=val;
    cout<<card;
    
    return 0;
}

