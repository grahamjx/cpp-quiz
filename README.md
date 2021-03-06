##C++ - Quiz App - Linked List

###Foreword
Repos like this one contain old work that I did during my time at Portland State University. Most of these projects were completed in the Data Structures or Computer Systems Programming courses. These projects demonstrate my solid understanding of programming basics as well as familiarity with fundamental system architectures. Each project is meticulously commented and the provided design write-up discusses some of the implementation choices I made when creating these projects.

###Getting Started

Simply run the compiled executable from any unix-based terminal

```bash
  $> cd /path/to/your-project-folder
  $> ./cs-quiz
  ```
Of course if you want to compile it from source a simple ```$> make run ``` from the source directory will do the trick.

###Purpose:
This program creates a True or False quiz. Each "true" answer will send the user to the next question while each "false" answer will skip the next question and point the user to the question after that. At the end of the quiz (when there is no remaining nodes in the list), the quiz is over and it returns the user to the main menu.

###Input:   
When executing this program, the quiz is generated by building a Linked List with each corresponding question and answer being stored in each node. The data provided to the Linked List is managed by the class "questions" (See quiz_question.h). The questions and answers are stored in a local file "quiz.txt". The overall quiz structure is managed by the class "quiz_lists" (See quiz_list.h).

###Output:  
The output of each question in the list is displayed by using a quiz_list member function called displayQuestion(). All additional output comes from this main.cpp file and relates to the user menu, file loading errors and other user prompts.
