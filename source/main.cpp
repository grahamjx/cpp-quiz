/*
 Name: Joel Graham
 Course: CS 163
 Programming Assignment #1

 File: main.cpp

 Purpose: This program creates a True or False quiz. Each "true" answer will send the user to the
          next question while each "false" answer will skip the next question and point the user to the question
          after that. At the end of the quiz (when there is no remaining nodes in the list), the quiz is over and it
          returns the user to the main menu.

 Input:   When executing this program, the quiz is generated by building a Linked List with each corresponding
          question and answer being stored in each node. The data provided to the Linked List is managed by the
          class "questions" (See quiz_question.h). The questions and answers are stored in a local file "quiz.txt".
          The overall quiz structure is managed by the class "quiz_lists" (See quiz_list.h).

 Output:  The output of each question in the list is displayed by using a quiz_list member function called
          displayQuestion(). All additional output comes from this main.cpp file and relates to the user menu,
          file loading errors and other user prompts.

 */

#include "quiz_list.h"
#include <iostream>

using namespace std;

void call_menu(void);
char read_input(const char prompt[]);
void run_input(char command, quiz_list& a_quiz);
void run_quiz(quiz_list& a_quiz);

/* The function primarily handles how the client side of the program is structured. After declaring some variables, the function does error
 checking to see if the local .txt was loaded before proceeding to displaying the menu screen. User input from the menu is processed
 through the function 'read_input' before passing 'input' and the object 'a_quiz' as arguments into the 'run_input' function to perform additional
 processes. When the user is ready to quit the program, the input of 'q' will cause the program to terminate. */

int main ()
{
    quiz_list a_quiz;
    bool load;
    char input;
	  char file_name[] = "quiz.txt";

    load = a_quiz.load_data(file_name);
    if (load == false)
    {
        cout << "Could not open" << file_name << ",make sure to have the file in the current directory" << endl;
    }

    call_menu();
	input = read_input("Please enter an option from the list: ");
	while (input != 'q')
	{
		run_input(input, a_quiz);
		call_menu();
		input = read_input("Please enter an option from the list: ");
	}
    return 0;
}


//Displays the menu options to the user.
void call_menu(void)
{
	cout << "\nWelcome to Joel's Quiz Application!" << endl
    << "S. Start the Quiz" << endl
    << "Q. Quit the program" << endl << endl;
}

/* Accepts a prompt from the main() function and displays it. Accepts user input, converts it to lower case
and passes it back to the main() function. */

char read_input(const char prompt[])
{
	char cmd;
	cout << prompt;
	cin >> cmd;

	cin.clear();
	cin.ignore(100, '\n');
	return tolower(cmd);
}

/* User input and object 'a_quiz' is passed into the function. A switch statement is used to process
 the command argument. The object is passed to this function and then passed again to runQuiz in order
 to start the quiz. Any command other than the ones outlined in the menu is considered invalid and it returns
 back to main() */

void run_input(char command, quiz_list& a_quiz)
{
	switch (command)
        {
        case 's': run_quiz(a_quiz);
            break;
        default: cout << "\nInvalid option, please select again." << endl;
            break;
        }
}

/* Object 'a_quiz' is passed by reference to this function to handle the actual taking of the quiz.
 a while loop is used to to run the quiz and the bool variable 'working' is used as it's control variable.
 Working is assigned based upon a true or false return by the member function display_question. The function
 provides a prompt to the user in order to answer the given question and then feeds the input as an argument into the
 "quiz_lists" member function answer_question. Local error checking on input is done using some of the previous functions.
 If 'working' is ever equal to false then that signals the end of the quiz. */

void run_quiz(quiz_list& a_quiz)
{
    char user_answer;
    bool working = true;
    a_quiz.initilize_quiz();

    while(working)
    {
        working = a_quiz.display_question();
        if (working == false)
        {
            break;
        }

        user_answer = read_input("Please enter True(T) or False(F): ");
        if(user_answer != 't' && user_answer != 'f')
		{
			cout << "\nInvalid input, please try again!";
            user_answer = read_input("\nPlease enter True(T) or False(F): ");
		}
            working = a_quiz.answer_question(user_answer);
    }

    cout << "\nThat is the end of the quiz, thanks for playing!" << endl;
}
