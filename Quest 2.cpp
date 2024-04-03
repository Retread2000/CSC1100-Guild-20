#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void GameStart(){
    cout << "Welcome to the Labyrinth of Truths and Lies\n"
    << "Many Guardians who tell only truths or only lies guard the path ahead \n"
    << "Find your way by asking the Guardians Questions\n"
    << "Answer 5 riddles correctly to escape, or stay forever lost!\n\n";
}

int GetPathNumber(){
    int PathNumber=0;
    while (PathNumber < 1 || PathNumber > 5){
        cout << "There are 5 paths ahead. Choose a path to enter (1-5): ";
        cin >> PathNumber;
        if (PathNumber < 1 || PathNumber > 5){
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

void runChecker(int UserResponse, int GuardianType, int& correct, int& incorrect) {
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
    {"Do you collect shoes?", "Nah, I'm broke", "Absolutely!"},
    {"How many times have you been to Japan", "4 times", "2 times"},
    {"Have you seen the Gundam Statues in person", "Yes", "No"},
    {"Do you enjoy playing League of Legends", "No", "Yes"},
    {"Are you a CS major", "Yes", "No"}
    
};

string Chad_Questions[5][3] = // [PathNumber][0] for question, [PathNumber][1] for truth, [PathNumber][2]for lie
{   
    {"Do you play league of legends?", "Yes", "No"},
    {"How many seasons did you reach Gold in League of Legends", "1", "3"},
    {"Question 3", "Yes", "No"},
    {"Question 4", "Yes", "No"},
    {"Question 5", "Yes", "No"}
    
};

string Oscar_Questions[5][3] = // [PathNumber][0] for question, [PathNumber][1] for truth, [PathNumber][2]for lie
{   
    {"Do you collect pennies?", "No", "Yes"},
    {"How many days do you play video games", "I don't", "4"},
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

string guardianQuestion(int PathNumber, int Guardian, int GuardianType){
    string question;
    if (Guardian == 0) {
        question = Ephraim_Questions[PathNumber-1][0] + "?" +  '"' + "\n"
            + Guardians[Guardian] + " responds: " + Ephraim_Questions[PathNumber-1][GuardianType];
        }
    else if (Guardian == 1) {
        question = Chad_Questions[PathNumber-1][0] + "?" +  '"' + "\n"
            + Guardians[Guardian] + " responds: " + Chad_Questions[PathNumber-1][GuardianType];
        }
    else if (Guardian == 2) {
        question = Trevor_Questions[PathNumber-1][0] + "?" +  '"' + "\n"
            + Guardians[Guardian] + " responds: " + Trevor_Questions[PathNumber-1][GuardianType];
        }
    else if (Guardian == 3) {
        question = Oscar_Questions[PathNumber-1][0] + "?" + '"' + "\n"
            + Guardians[Guardian] + " responds: " + Oscar_Questions[PathNumber-1][GuardianType];
        }
    else if (Guardian == 4) {
        question = Sophia_Questions[PathNumber-1][0] + "?" +  '"' + "\n"
            + Guardians[Guardian] + " responds: " + Sophia_Questions[PathNumber-1][GuardianType];
        }
    return question;
}

int main(){
   int correct = 0;
   int incorrect = 0;
   int totalQuestions = 0;
   
   GameStart();

   while(correct < 5){
        int PathNumber;
        PathNumber=GetPathNumber();
   
        srand(time(NULL));
        int GuardianType = rand() % 2+1;
        int Guardian = rand() % 5;
        
        cout << "You have chosen Path "<< PathNumber << "\n" << endl;
        
        cout << "You ask " << Guardians[Guardian] << " the question " << '"';
        string questionResponse = guardianQuestion(PathNumber, Guardian, GuardianType);
        cout << questionResponse;

        cout << "\nIs the Guardian telling a truth or lie? " << endl;
        cout << "Your response(truth or lie): ";
   
        int UserResponse=GetUserResponse();
   
        runChecker(UserResponse, GuardianType, correct, incorrect);
    }

    totalQuestions = correct + incorrect; 
    cout << "Congrats! You made it out! It took you " << totalQuestions << " questions to get out"; 
    return 0;
}
