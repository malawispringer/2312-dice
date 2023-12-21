/* Malawi Springer - December 2023
* This is a simple program that emulates a dice roll by randomly picking
* a number 1-6. It will also ask the user how many times it wants to roll and
* provide a number
*/
#include <string>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector> 

using namespace std;

vector<int> rollDice(int dice, int roll); 
void printSummary(vector<int> rolls);


int main(){
    cout << "How many 6 sided dice would you like to roll?\n";
    int diceNumber;
    cin >> diceNumber;
    cout << "How many times do you want to roll the dice?\n"; 
    int rollNumber; 
    cin >> rollNumber; 
    vector<int> rollOutputs; 
    rollOutputs = rollDice(diceNumber, rollNumber);
    printSummary(rollOutputs); 

    return 0;
}

vector<int> rollDice(int dice, int roll){
    //find my range of possible numbers
    int range = 0;
    for (int i = 0; i < dice; i++){
        range = 6 + range;
    }

    // roll dice for /roll/ number of times
    vector<int> rollOutputs;
    int min = 1 * dice;
    for (int i = 0; i < roll; i++){ 
    int output = ((rand() % (range-min + 1)) + min); 
    rollOutputs.push_back(output); 
    }
    return rollOutputs; 
}

void printSummary(vector<int> rolls){
    /*//keep it simple for now, just print the numbers
    cout << "Your rolls:\n";
    cout << "< ";
    for (int i = 0; i < rolls.size(); i++){
        cout << rolls[i] << " "; 
    }
    cout << ">\n"; 
*/
    //more complicated version, count freq
    vector <pair<int,int>> frequencyList; 
    for (int i = 0; i < 100; i++){
        int count = 0;
        for (int j = 0; j < rolls.size(); j++){
            if (rolls[j] == i) count++; 
        }
        if (count > 0) frequencyList.push_back(pair<int, int> {i, count});
    }
    for (int i = 0; i < frequencyList.size(); i++){
        if (frequencyList[i].second == 1){
            cout << "There is  " << frequencyList[i].second << " instance  of ";
        } else {
            cout << "There are " << frequencyList[i].second << " instances of ";
        }
        cout << frequencyList[i].first << ".\n"; 
    }
}