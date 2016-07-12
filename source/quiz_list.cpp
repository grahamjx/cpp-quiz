/*
 Name: Joel Graham 
 Course: CS 163
 Programming Assignment #1

 File: quiz_list.cpp

 Purpose: This file contains the function definitions for the class "quiz_list" found in "quiz_list.h".
          These functions are used to carry out proccess that deal with the linked list. Creating and destroying the list,
          traversing the list and displaying node data are some of the operations carried out by this file.

 Input:   This file utilizes input provided from the local .txt file as well as from the "quiz_question" class which supplies the
          data for each individual node.

 Output:  Displays a limited amount of information found in each node out to the user (main function).
 */

#include "quiz_list.h"
#include "quiz_question.h"
#include <iostream>
#include <fstream>

using namespace std;

//Sets the node pointers in the private section to null
quiz_list::quiz_list()
{
    head = NULL;
    tail = NULL;
    active = NULL;
}


//Sets the node pointers in the private section to null before calling the file load function
quiz_list::quiz_list(const char file_name[])
{
	head = NULL;
    tail = NULL;
    active = NULL;
	load_data(file_name);
}


//Destroys the linked list by setting current to head and then deleting each node until head is equal to null
quiz_list::~quiz_list()
{
	node * current = head;
	while(current)
	{
		head = current->next;
		delete current;
		current = head;
	}
}


/* Takes in "a_question" which was passed by reference from the load_data function. A new pointer variable is
 created that will pass the object into the node function depending on what value the private member variables
 are currently set to. If head is NULL, meaning the list is empty, then the head and tail pointers will
 point to a new node which is constructed with the a_question object that was passed in. If head is not equal to NULL,
 meaning the list is not empty, it will append at the end of the list. */

void quiz_list::add_question(const quiz_question& a_question)
{
	node * new_node = new node(a_question);

	if(head == NULL)
	{
		head = new_node;
        tail = new_node;
        active = head;
	}
	else
    {
        tail->next = new_node;
        tail = new_node;
    }
}


/* Sets node pointer "active" to head. This is done so that when the user decides to take the test again, the tracking variable
"active" is reset back to the first position. */

void quiz_list::initilize_quiz()
{
    active = head;
}


/* This function displays two data variables saved inside a particular node. The "active" node pointer found in the private section of
 this class serves as a tracking variable for my implementation. This function displays both the question and the question number of the
 active node.

 The two local variables used in this function server as holding variables to display the data. Since a class is holding my actual data members
 I need to "get" them using a member function since they are in the private section of the "quiz_question" class.

 This function, in combination with the answer_question function below, allows the user to only receive one question at a time and not require
 a new traversal everytime there is a new question to display */

bool quiz_list::display_question() const
{
    node * current = active;
    int number;
    char question[MAX_CHAR];

    if(active == NULL)
    {
        return false;
    }
    else
    {
        current->question_data.get_number(number);
        current->question_data.get_question(question);

        cout << "\nQuestion #" << number << ": " << question << endl;
    }
    return true;
}


/* This function takes in the user_answer from main, passed as reference, and compares it to the real_answer stored inside
 the active node. If the user_answer and the real_answer are the same then the active node is set to the next question. If
 the user_answer is not equal to the real_answer than the active node is set to the node two questions away rather than one.
 Essentially, a wrong answer will skip the next question and set "active" to the question after that.

 As mentioned before, active in this case is my tracking node which is saved outside of the local scope so that when the function
 is called again, it picks up from the node "saved" to active from the last iteration of the function.

 The local variable user_answer is used as a holding variable for retriving the actual private data member of the "quiz_question" class. */

bool quiz_list::answer_question(char& user_answer)
{
    node * current = active;
    char real_answer;

    if(active == NULL)
    {
        return false;
    }
    else
    {
        current->question_data.get_answer(real_answer);

        if(real_answer == user_answer)
        {
            active = current->next;
        }
        else
        {
            if (current->next == NULL)
            {
                return false;
            }
            active = current->next->next;
        }
    }
    return true;
}


/* Loads the data from the local .txt file. Uses local variables to save the information coming in from the file
before using the "quiz_question" set functions to set the data to the private member variables inside the class.
After setting the variables it passes the object as reference into the add_question function above where the object
assigned to an individual node in the linked list. */

bool quiz_list::load_data(const char file_name[])
{
	ifstream in;
	quiz_question a_question;
    int number;
    char answer;
	char question[MAX_CHAR];

	in.open(file_name);
	if(!in)
	{
		return false;
	}

    in.get(question, MAX_CHAR, ';');
	while (!in.eof())
	{
		in.get();
        in >> answer;

        in.get();
		in >> number;
		in.ignore(100, '\n');

		a_question.set_number(number);
		a_question.set_answer(answer);
        a_question.set_question(question);

		add_question(a_question);

        in.get(question, MAX_CHAR, ';');
	}
	in.close();
    return true;
}
