#include <iostream>
#include <string>
using namespace std;

int Total = 0; // Initialize Total

class Question
{
private:
    string Question_Text;
    string Answer_1;
    string Answer_2;
    string Answer_3;
    string Answer_4;

    int Correct_Answer;
    int Question_Score;

    int Guess; // Declare Guess within the class

public:
    void setValues(string, string, string, string, string, int, int);
    void askQuestion(string playerName);
};

void Question::setValues(string q, string a1, string a2, string a3, string a4, int ca, int pa)
{
    Question_Text = q;
    Answer_1 = a1;
    Answer_2 = a2;
    Answer_3 = a3;
    Answer_4 = a4;
    Correct_Answer = ca;
    Question_Score = pa;
}

void Question::askQuestion(string playerName)
{
    cout << playerName << ", " << Question_Text << endl;
    cout << "1. " << Answer_1 << endl;
    cout << "2. " << Answer_2 << endl;
    cout << "3. " << Answer_3 << endl;
    cout << "4. " << Answer_4 << endl;

    cout << "What is your answer? ";
    cin >> Guess;

    if (Guess == Correct_Answer)
    {
        cout << "Great! You are correct." << endl;
        Total = Total + Question_Score;

        cout << "Score: " << Question_Score << " Out of " << Question_Score << "!" << endl;
    }
    else
    {
        cout << "Oh No! You are Wrong." << endl;
        cout << "Score: 0 Out of " << Question_Score << "!" << endl;
        cout << "The correct answer is " << Correct_Answer << "." << endl;
    }
}

int main()
{
    string Name1;
    cout << "What's your first name player 1? ";
    cin >> Name1;

    string Name2;
    cout << "What's your first name player 2? ";
    cin >> Name2;

    Question q1;
    Question q2;

    q1.setValues("What is the only function all C++ programs must contain?",
        "start*()",
        "system()",
        "main()",
        "program()",
        3,
        10);

    q2.setValues("Which of the following is the correct comment to use?",
        "*/ comments */",
        "/* comments */",
        "** comments **",
        " { comments } ",
        2,
        10);

    q1.askQuestion(Name1);
    q2.askQuestion(Name2);

    cout << "Your total score is " << Total << " out of 100." << endl;
    cout << endl;

    return 0;
}
