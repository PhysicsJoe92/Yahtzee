/* 
 * File:   main.cpp
 * Author: Joseph Hernandez
 *
 * Created on October 23, 2022, 4:28 PM
 */

#include <iostream>
#include <list>
#include <ctime>

using namespace std;

struct Die{
    int face;
    int side[6] = {1,2,3,4,5,6};
    
    int rollDie(){
        face=side[rand()%6];
        return face;
    }
    
    void setFace(int nFace){
        face = nFace;
    }
    
    int getFace(){return face;}
};

void sortDie(Die[],int);
void rollAgain(Die[],int);
void printDice(Die[],int);
void rollDie(Die[],int);

int main(int argc, char** argv) {
    srand((unsigned int)time(0));
    
    int SIZE=5;
    int MAXROLL=3;
    int keep;
    int rolls=1;
    Die dice[SIZE];
    
    rollDie(dice,SIZE);
    
    sortDie(dice,SIZE);
    
    printDice(dice,SIZE);

    cout<<"How many die would you like to keep?"<<endl;
    cin>>keep;
    
    while(keep!=SIZE && rolls<MAXROLL){
        rolls++;
        
        rollAgain(dice,keep);
        
        //printDice(dice,SIZE);

        cout<<"Sorting Die...";
        sortDie(dice,SIZE);
        
        cout<<endl;
        printDice(dice,SIZE);
        
        if(rolls==3) break;
        cout<<"How many die would you like to keep?"<<endl;
        cin>>keep;
    }
    if(rolls==3) cout<<"No More Rolls bud..."<<endl;
    
    return 0;
}

void sortDie(Die dice[],int SIZE){
    for(int i=0;i<(SIZE-1);i++){
        for(int j=(i+1);j<SIZE;j++){
            if(dice[i].getFace()>dice[j].getFace()){
                int temp = dice[i].getFace();
                dice[i].setFace(dice[j].getFace());
                dice[j].setFace(temp);
            }
        }
    }
}

void printDice(Die dice[],int SIZE){
    cout<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"Die "<<i+1<<": ";
        cout<<"[ "<<dice[i].face<<" ]"<<endl;
    }
    cout<<endl;
}

void rollDie(Die dice[],int SIZE){
    Die die;
    for(int i=0;i<SIZE;i++){
        die.rollDie();
        dice[i]=die;
    }
}

void rollAgain(Die dice[],int keep){
    int *dieKept;
    int dK;
    int index=0;
    
        dieKept = new int[keep];
        cout<<"Which die would you like to keep?"<<endl;
        
        for(int i=0;i<keep;i++){
            cin>>dK;
            dieKept[i]=dK;
        }
        
        // Sort the die keep 
        for(int i=0;i<keep-1;i++){
            for(int j=i+1;j<keep;j++){
                if(dieKept[i]>dieKept[j]){
                    int temp=dieKept[i];
                    dieKept[i]=dieKept[j];
                    dieKept[j]=temp;
                }
            }
        }

        for(int i=0;i<5;i++){
            if(i!=(dieKept[index]-1)){
                dice[i].rollDie();
            }
            else{
                index++;
            }
        }
     
        delete dieKept;
}