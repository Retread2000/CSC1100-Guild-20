#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

void GameStart(){
    cout << "Welcome to the Labyrinth of Truths and Lies\n"
    << "Many Guardians who tell only truths or only lies guard the path ahead \n"
    << "Find your way by asking the Guardians Questions\n"
    << "Answer 3 riddles correctly to escape, or stay forever lost!\n\n";
}

int GetPathNumber(){
    int PathNumber=0;
    while (PathNumber==0 || PathNumber<1 && PathNumber>5){
        cout << "There are 5 paths ahead. Choose a path to enter (1-5): ";
        cin >> PathNumber;
        if (PathNumber<1 || PathNumber>5){
            cout << "There is no path in " << PathNumber << " direction! Choose again.";
        }
    }
    return PathNumber;
}

int GetUserResponse(){
    string Input;
    int TL[2] = {1,2}; // for truth, 2 for lie
    int FInput;
    cin >> Input;
    int x=0;
    while (x == 0)
    {
        if (Input=="truth"){
            FInput=TL[0];
            x=1;
    }
        else if (Input=="lie"){
            FInput=TL[1];
            x=1;
    }
        else {
            cout << "That's not an answer! It makes no sense. Try again. \n";
            cin >> Input;
    }
}
    return FInput;
}

string Questions[5][3] = // [PathNumber][0] for question, [PathNumber][1] for truth, [PathNumber][2]for lie
{   {"Is '<<' an isertion or extraction operator? ", "Instertion", "Extraction" },
    {"How many bits are in a byte?", "8", "16"},
    {"Are arrays or vectors dynamic?", "Vectors", "Arrays" },
    
};

int main(){
   int x=0;
   GameStart();
   while(x==0){
   int PathNumber;
   PathNumber=GetPathNumber();
   srand(time(0));
   int GuardianType = rand() % 2 + 1;
   cout << GuardianType;
   cout << Questions[PathNumber-1][0] << "\n"
   << "The Guaridan responds: " << Questions[PathNumber-1][GuardianType]
   << "\nIs the Guardian telling a truth or lie? ";
   int UserResponse=GetUserResponse();
   if (UserResponse==1 && GuardianType==1){
       cout << "Correct! The Guardian was telling the truth. The Guardian points you in the right direction\n";
   }
   else if (UserResponse==2 && GuardianType==2){
       cout << "Nice! The Guardian was lying. The Guardian points you in the right direction\n";
   }
   else {
       cout << "Wrong! The Guardian offers no directions and you feel more lost\n";
   }
   
}
return 0;
}







