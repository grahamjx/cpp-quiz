##C++ - Quiz App

###Foreword
Repos like this one contain old work that I did during my time at Portland State University. Most of these projects were completed in the Data Structures or Computer Systems Programming courses. These projects demonstrate my solid understanding of programming basics as well as familiarity with fundamental system architectures. Each project is meticulously commented and the provided design write-up discusses some of the implementation choices I made when creating these projects.

###Getting Started

Simply run the compiled executable from any unix-based terminal

```bash
  $> cd /path/to/your-project-folder
  $> ./cs-quiz
  ```
Of course if you want to compile it from source a simple ```$> make run ``` from the source directory will do the trick.

### Design Write-Up

Following the guidelines of the assignment, I created a class that acted as my manager for my data structure, in this case an ordered linked list. For setting up of the data structure I used a struct to assemble each node and have it set the data and establish the link to the next node. I opted to nest my node structure inside my list class private section. From a design consideration stand point, it made sense. I thought about what actually needed to have direct access to the underlying structure. Since a separate class was also managing my data, I could just let my list class manage the building of the nodes based upon what I wanted to pass into the private structure.

For the data that contained each question and answer, I decided to create a class instead of a struct and separate it into its own .h and .cpp file. This was helpful from a workflow standpoint, having the ability to segment my program into smaller, workable chunks. From a design consideration standpoint, this one turned out to be somewhat of a hassle. Although, I did find the experience with using additional classes a good learning experience, it added a considerable amount of additional code just to simply display the information in a node or set the information in a node when creating the linked list from the data file. Overall, it behaves very similar to a struct but it did allow me to easily organize my member functions and made the process of allocating and deallocating memory easier for me personally.

One puzzling hurdle that arose during implementation was how to only display one question to the user at a time instead of traversing the whole list and outputting all the questions. I had to construct a way, that when I called the display function, it would only show one question and then let the user provide an answer to it. Furthermore, after the user had provided their answer, I needed the list to go to the next corresponding node based on the user's answer and then display that new question. In my implementation, I separated the displaying of questions and the moving of my node pointers into two separate functions. I also created a third node pointer in addition to head and tail that, after each iteration of the function call, would store the location of the next node. That way, when the function was called again while in the quiz loop located in main, it would output the active node. The active pointer would update depending on if the answer was right or wrong, moving to the next question or skipping the next question respectively. Given the troubles of managing the data output for each individual node, this solution seems to work well.

As far as using a linked list as the data structure for this assignment, I found that it was more than capable of handling this simple quiz application. The ability to load my questions in from the data file and pass my data object into the private node structure for construction worked very well. I was essentially able to build each node on the fly and it saved a lot of time and additional coding when compared to entering in each question and answer in from the client before building each node in the list.

I think that for a quiz or survey application like this; a static array would work better. Having the quick ability to go straight to a question no matter if it is before or after the current one would be very useful. I imagine if the application was designed to be used on a test like the GMAT, where a wrong answer proceeds to a set of questions that are easier and right answer does the opposite, an array of data that had a member variable that gauged question difficulty could be used to call certain elements. Also a quiz, exam or survey is in most cases a static creation with a clear beginning and end. The ability to expand by adding additional questions is nice but at the cost of quick access to any element doesn't seem worth it in this case.

Looking at overall inefficiency, my program ultimately suffers in a couple of areas. I have already mentioned the hassle of pulling information out of each data object because they are associated with a class and are private member variables. Declaring local variables just to hold information for display purposes is also a bit redundant. Also, if I would have made my underlying data a struct, I would have been able to remove a considerable amount of functions and handle the setting of data and construction of nodes with fewer function calls.

Overall, If I had more time to work on this assignment I would like to find an efficient way of keeping all pertinent data private but still have the ability to pass that information all the way out to the main function so that displaying information can be handled by the client. Maybe there is a solution I have just overlooked thus far, but discovering a way to have accessible but safe access to stored data is something I'm very much interested in learning more about.
