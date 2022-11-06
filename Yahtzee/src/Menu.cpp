/*
 * File: Menu.cpp
 * Author: Joseph Hernandez
 * Created on November 4, 2022, 10:48 PM
 * 
 */

#include "Menu.h"

Menu::Menu(){
    string mainMenu;
    string rules;
    string ending;
    getline(fstream("res/Menu/MainMenu.txt"),mainMenu,'\0');
    menuSys[0]=mainMenu;
    getline(fstream("res/Menu/Rules.txt"),rules,'\0');
    menuSys[1]=rules;
    getline(fstream("res/Menu/End.txt"),ending,'\0');
    menuSys[2]=ending;
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
    cout<<endl<<endl;
    cout<<menuSys[2];
    cout<<endl;
}