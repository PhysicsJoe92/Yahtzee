/* 
 * File:   main.cpp
 * Author: Joseph Hernandez
 * Created on November 3, 2022, 5:29 PM
 */

#include <set>

#include "Game.h"

class Menu{
    public:
        Menu();
        void printMainMenu();
        void printRules();
        void printExit();
    private:
        vector<string> menuSys;
};

int main(int argc, char** argv) {
    Game game;
    Menu menSys;
    int dec;
_start:
    menSys.printMainMenu();
    cout<<setw(32)<<"Selection: ";
    cin>>dec;
    while(dec>3 || dec < 1){
        cout<<"INVALID SELECTION:"<<endl;
        cout<<"Try again: ";
        cin>>dec;
    }
    if(dec==2){
        menSys.printRules();
        cout<<endl<<endl<<endl;
        goto _start;
    }
    else if(dec==1){
        game.start();
        
        game.play();
        
        game.finish();
        
        cout<<"Would you like to play another game?(Yes/No)"<<endl;
        string ans;
        cin.ignore(1000,'\n');
        getline(cin,ans);
        ans=ScoreCard::format(ans);
        if(ans=="Yes")goto _start;
    }
    menSys.printExit();
    return 0;
}

Menu::Menu(){
    string mainMenu;
    string rules;
    string ending;
    getline(fstream("res/Menu/MainMenu.txt"),mainMenu,'\0');
    menuSys.push_back(mainMenu);
    getline(fstream("res/Menu/Rules.txt"),rules,'\0');
    menuSys.push_back(rules);
    getline(fstream("res/Menu/End.txt"),ending,'\0');
    menuSys.push_back(ending);
}

void Menu::printMainMenu(){
    cout<<menuSys[0];
    cout<<endl;
}

void Menu::printRules(){
    cout<<menuSys[1];
    cout<<endl;
}

void Menu::printExit(){
    cout<<menuSys[2];
    cout<<endl;
}