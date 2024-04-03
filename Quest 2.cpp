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
        cout << "There are 5 paths ahead. Choose a path to enter (1-5): " << endl;
        cin >> PathNumber;
        if (PathNumber<1 || PathNumber>5){
            cout << "There is no path in " << PathNumber << " direction! Choose again." << endl;
        }
    }
    return PathNumber;
}

int GetUserResponse(){
    string Input;
    int TL[2] = {1,2}; // 1 for truth, 2 for lie
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

string Trevor_Questions[5][3] = // [PathNumber][0] for question, [PathNumber][1] for truth, [PathNumber][2]for lie
{   {"Is '<<' an insertion or extraction operator? ", "Insertion", "Extraction" },
    {"How many bits are in a byte?", "8", "16"},
    {"Are arrays or vectors dynamic?", "Vectors", "Arrays"},
    {"Question 4", "Yes", "No"},
    {"Question 5", "Yes", "No"}
    
};

string Ephraim_Questions[5][3] = // [PathNumber][0] for question, [PathNumber][1] for truth, [PathNumber][2]for lie
{   
    {"Do I collect shoes?", "Yes", "No"},
    {"How many times have I been to Japan", "1", "4"},
    {"Have I seen the Gundam Statues in person", "Yes", "No"},
    {"Do I play League of Legends", "Yes", "No"},
    {"Am I a CS major", "Yes", "No"}
    
};

string Chad_Questions[5][3] = // [PathNumber][0] for question, [PathNumber][1] for truth, [PathNumber][2]for lie
{   
    {"Do I play league of legends?", "Yes", "No"},
    {"How many seasons did I reach Gold in League of Legends", "1", "3"},
    {"Question 3", "Yes", "No"},
    {"Question 4", "Yes", "No"},
    {"Question 5", "Yes", "No"}
    
};

string Oscar_Questions[5][3] = // [PathNumber][0] for question, [PathNumber][1] for truth, [PathNumber][2]for lie
{   
    {"Do I collect pennies?", "Yes", "No"},
    {"How many days do I play video games", "1", "4"},
    {"Question 3", "Yes", "No"},
    {"Question 4", "Yes", "No"},
    {"Question 5", "Yes", "No"}
    
};

string Sophia_Questions[5][3] = // [PathNumber][0] for question, [PathNumber][1] for truth, [PathNumber][2]for lie
{   
    {"Question 1", "Yes", "No"},
    {"Question 2", "Yes", "No"},
    {"Question 3", "Yes", "No"},
    {"Question 4", "Yes", "No"},
    {"Question 5", "Yes", "No"}
    
};

string Guardians[]= 
    {"Ephraim", "Chad", "Trevor", "Oscar", "Sophia"}
;

int main(){
   int x=0;
   GameStart();
   
   int correct = 0;
   int incorrect = 0;
   
   while(x==0){
   int PathNumber;
   PathNumber=GetPathNumber();
   
   srand(time(NULL));
   int GuardianType = rand() % 2+1;
   int Guardian = rand() % 5;
   
   //this is to determine what guardian type 1=truth 2=lie for fact checking Code
   //will delete after
   cout << "Guardian type = " << GuardianType << "\n" << endl;
   
   cout << Guardians[Guardian] << " asks you the question ";
   
    if (Guardian == 0) {
       cout << Ephraim_Questions[PathNumber-1][0] << "\n"
       << Guardians[Guardian] << " responds: " << Ephraim_Questions[PathNumber-1][GuardianType] << endl;
   }
    else if (Guardian == 1) {
       cout << Chad_Questions[PathNumber-1][0] << "\n"
       << Guardians[Guardian] << " responds: " << Chad_Questions[PathNumber-1][GuardianType];
   }
    else if (Guardian == 2) {
       cout << Trevor_Questions[PathNumber-1][0] << "\n"
       << Guardians[Guardian] << " responds: " << Trevor_Questions[PathNumber-1][GuardianType];
   }
   else if (Guardian == 3) {
       cout << Oscar_Questions[PathNumber-1][0] << "\n"
       << Guardians[Guardian] << " responds: " << Oscar_Questions[PathNumber-1][GuardianType];
   }
   else if (Guardian == 4) {
       cout << Sophia_Questions[PathNumber-1][0] << "\n"
       << Guardians[Guardian] << " responds: " << Sophia_Questions[PathNumber-1][GuardianType];
   }
   
   
   cout << "\nIs the Guardian telling a truth or lie? " << endl;
   
   
   cout << "Your response(truth or lie): ";
   int UserResponse=GetUserResponse();
   
   if (UserResponse==1 && GuardianType==1){
       cout << "\nCorrect! The Guardian was telling the truth. The Guardian points you in the right direction\n";
       correct += 1;
   }
   else if (UserResponse==2 && GuardianType==2){
       cout << "\nNice! The Guardian was lying. The Guardian points you in the right direction\n";
       correct += 1;
   }
   else {
       cout << "\nWrong! The Guardian offers no directions and you feel more lost\n";
       incorrect += 1;
   }
   
   //this will be taken out but just to count how many times they got it correct and incorrect
   cout << "Correct: " << correct << endl;
   cout << "Incorrect " << incorrect << endl;
   
   if (correct == 3){
       x = 1;
   }
   else {
       x = 0;
   }
}

cout << "Congrats! You made it out!"; 
return 0;
}
