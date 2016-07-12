/*
 Name: Joel Graham 
 Course: CS 163
 Programming Assignment #1

 File: quiz_question.cpp

 Purpose: This file contains the function definitions for the class "quiz_question" found in "quiz_question.h".
          These functions are used to carry out proccess that deal wth dynamically allocating memory for each
          member variable as well as functions to "get" and "set" the data which the member variables point to.

 Input:   Since the member variables are private, "set" functions are used to set the data that the member variables
          are pointing to. This file utilizes input provided from the local .txt file as determined by calls made within the
          "quiz_list" class member functions, namely quiz_list::load_data.

 Output:  Member variables are private thus their access is limited to "getting" them out and setting them to some local variable
          where the "get" function is called from.
 */

#include "quiz_question.h"
#include <cstring> //Included to allow the use of strcpy, strlen in member functions. Also was required for Unix g++ compile.

//Points the member variables to a new memory location on construction of an object
quiz_question::quiz_question(void)
{
	answer = new char;
    number = new int;
	question = new char[NULL];
}


//Deallocates memory for each member variable.
quiz_question::~quiz_question(void)
{
	if(number)
		delete number;
	if(question)
		delete [] question;
    if(answer)
        delete answer;
}


//The passed in reference argument out_number is assigned the value pointed to by the member variable "number"
void quiz_question::get_number(int& out_number) const
{
	out_number = *number;
}


//The passed in reference argument out_answer is assigned the value pointed to by the member variable "answer"
void quiz_question::get_answer(char& out_answer) const
{
    out_answer = *answer;
}


//The passed in reference argument out_question is assigned the value pointed to by the member variable "question"
void quiz_question::get_question(char out_question[]) const
{
	strcpy(out_question, question);
}


/* This function checks to see if member variable "number" is null, deallocateing that memory if it is not.
It then points "number" to a new int memory location and assigns it the value passed in by in_number. */

void quiz_question::set_number(const int in_number)
{
	if(number!=NULL)
		delete number;
	this->number = new int;
	*number = in_number;
}


/* This function checks to see if member variable "answer" is null, deallocating that memory if it is not.
 It then points "answer" to a new char memory location and assigns it the value passed in by in_answer. */

void quiz_question::set_answer(const char in_answer)
{
    if(answer!=NULL)
        delete answer;
    this->answer = new char;
    *answer = in_answer;
}


/* This function checks to see if member variable "question" is null, deallocating that memory if it is not.
 It then points "question" to a new char memory location with an array size exaclty as large as it need to be in
 order to hold the question. Using strlen, it measures the length of the character array in_question being passed
 in and sets the new memory location to that value + 1 to accomodate the null character. Then the in_question
 is copied in to the new memory location that "question" points to. */

void quiz_question::set_question(const char in_question[])
{
	if(question!=NULL)
		delete [] question;
	this->question = new char[strlen(in_question)+1];
	strcpy(question, in_question);
}
