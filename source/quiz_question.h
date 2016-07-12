/*
 Name: Joel Graham
 Course: CS 163
 Programming Assignment #1

 File: quiz_question.h

 Purpose: This file declares the class "quiz_question". This class handles the construction of the data that is used in each node of the linked list.
          Since the data members are private, the public member functions of the class are made of up the constructor and destructor as well as three
          functions that "get" the data pointed to by the private member variables and three functions that "set" the data pointed to
          by the private member variables.
  */

#ifndef QUIZ_QUESTION_H
#define QUIZ_QUESTION_H

class quiz_question
{
public:
	//Constructor
	quiz_question(void);

	//Destructor
    ~quiz_question(void);

	void get_number(int& out_number) const; //Gets the number pointed to by the private member variable "number" and assigns it to the passed in int.
  void get_answer(char& out_answer) const; //Gets the answer pointed to by the private member variable "answer" and assigns it to the passed in char.
  void get_question(char out_question[]) const; //Gets the question pointed to by the private member variable "question" and assigns it to the passed in char array.

	void set_number(const int in_number); //Sets the private member variable "number" to the int value passed into the function.
	void set_answer(const char in_answer); //Sets the private member variable "answer" to the char value passed into the function.
  void set_question(const char in_question[]); //Sets the private member variable "question" to the char array passed into the function.

private:
    int*  number;
	char* question;
	char*  answer;
};
#endif
