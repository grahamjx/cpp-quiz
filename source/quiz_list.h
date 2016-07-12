/*
 Name: Joel Graham
 Course: CS 163
 Programming Assignment #1

 File: quiz_list.h

 Purpose: This file declares the class "quiz_lists". This class handles the construction of the linked list, loading the information
          from the text file, transversing of the list, displaying the data in a particular node, handling the answer passed in by
          the user, and destroying the linked list.

          This file also declares the struct "node". This struct is used to build the linked list and store the data provided in the
          "question" class into each node (see quiz_question.h). It uses an in-declaration function to grab the data out of the passed
          in object "a_question" and set it to the corresponding data object "question_data" for each new node. This allows the program to build
          a node based upon each incoming line of text during the load_data function.
 */

#ifndef QUIZ_LIST_H
#define QUIZ_LIST_H

#include "quiz_question.h"
#include <iostream>

using namespace std;
const int MAX_CHAR = 101; //Used on local variables found in display_question and load_data. This is merely to hold information coming out of the quiz_question data class.

class quiz_list
{
public:
    //Constructor(s)
	quiz_list();
    quiz_list(const char file_name[]); //Constructs an object based upon the supplied text file

	//Destructor
	~quiz_list();

	void add_question(const quiz_question& a_question); //Adds a question to the linked list
	void initilize_quiz(); //Initializes the node pointer "active"
  bool display_question() const; //Displays one question based on the position in the linked list
  bool answer_question(char& user_answer); //Takes in the user's answer from main and points to certain question depending how it compares to the actual answer in the list.
	bool load_data(const char file_name[]); //Reads the data from the text file and assigns it to a "quiz_question" data object.

private:

    struct node
    {
        quiz_question question_data;
        node * next;

        node(const quiz_question& a_question)
        {
            int number;
            char answer;
            char question[MAX_CHAR];

            a_question.get_number(number);
            a_question.get_answer(answer);
            a_question.get_question(question);


            question_data.set_number(number);
            question_data.set_answer(answer);
            question_data.set_question(question);

            next = NULL;
        }

    };

    node * active;
    node * head;
    node * tail;
};
#endif
