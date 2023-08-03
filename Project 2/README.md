# CS 124 Project 2
Create a Queue class and explore big-Oh complexities!

For this project, you will write a C++ program that uses Stack and Queue data structures to store objects of varying data types.

## Requirements
It is recommended that you use the data and program from Project 1 as a starting point.

### Stack Class
The Stack class from lecture is included in the starter code for this project.

### Queue Class
Create a Queue class that uses the Node class (also included in the starter code) to create a functioning queue data structure.
* Your Queue should keep track of where the front and back Nodes are.
* Your Queue should be able to:
  * `enqueue` (push Objects onto its back),
  * `dequeue` (pop and return Objects off its front),
  * `search` (determine if an Object is in the Queue or not), and
  * `print` (list all of the items in the Queue object, ordered from front to back).
* Your Queue must be able to be used with any data type.
* Your Nodes must be stored in heap memory.
* Your program must not have any memory leaks.

### Main function
Create two Queue objects: one of integers and one of strings. Demonstrate that the Queue methods work correctly by calling methods on the integer and string Queues and printing out to the console when appropriate.

Perform the following operations:
* Create a third Queue object and a Stack object, both of the type you created in Project 1.
* Use a loop to print and enqueue the first 10 objects from your vector (from Project 1) onto the Queue.
* Use a second loop to dequeue the 10 objects off the Queue and push them onto the Stack.
* Use a third loop to pop the 10 objects off the Stack and print them.

What is the order of the objects before and after adding them to the Queue and Stack?When and why did it change?

### Design
Consider the following questions:
* Using the Node class, will the links point from the front to the back of the Queue or from the back to the front? Which way will make the push and pop methods more efficient?
* How will you make sure there are no memory leaks?
* How will you print the objects in the main function? Should you overload an operator?

### Test
How can you demonstrate in your code that your Queue class works correctly? How can you use the integer and string Queue objects to show this?

## Report
You must write a report about your project. Answer the following questions directly in this section of the README file:
* Information about your data set (you will be assigned a different grader for this project)
* I have seven total attributes in this dataset, it's all about the top 1000 Youtube Channels! 
* Rank, which is decided by number of subscribers per channel on Youtube.
* Youtube Channel, which is the name of the channel.
* Subscribers, which gives us the number of subs per channel.
* Video Views, the total amount of times an audience views a video.
* Video Counts, the number of videos a channel has.
* Category, which is a youtube stat to define which category each channel falls into.
* Started is the year that the channel was started.

* The time complexities of each method in the Stack and Queue classes
* I believe that the time complexity for the funcitons: push, pop, dequeue, and enqueue are Constant. Search and Print functions are linear, beacuse they have to travese the entire class.

* Justify your use of pointers in the Queue (i.e. the direction of the arrows between the Nodes) as it relates to the complexity of the enqueue and dequeue methods
* The pointers in Queue were the difference between Stack and Queue classes. Adding a back pointer to Queue, enables the nodes to be pushed back and replaced with a new front node, which is a single step within the function, thus being constant.

* An explanation of when and why the 10 objects in the main function changed their order
* The 10 objects in the main function changed their order, because the difference between Stack, which simply adds a node, versus Queue, which points to a new back node after adding an nullPtr to push the node. 
* That is why, when printed in Stack, the order is ascending, whilst being printed in Queue, it descends. 

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**

## Submit

You must include your source files, your data file(s), CMakeLists.txt, and your updated README.md file that contains your report to your repository. Submit to Gradescope using the GitHub repository link, double-check that all the correct files are there, and wait for the autograder to provide feedback.

## Grading
The project is out of 60 points.

| Points Possible | Description of requirement |
|------------------- | ----------------------------- |
| 5 pts | Program compiles and runs. |
| 5 pts | Code style. Readable, naming style is consistent, comments where appropriate. |
| 20 pts | Queue class satisfies requirements. |
| 5 pts | You create at least two Queue objects of different types, as described above. |
| 5 pts | You test your code to demonstrate that everything works correctly. |
| 10 pts | You perform the operations with the Stack and the Queue as described above. |
| 10 pts | Report satisfies requirements, is easily readable, and is professional. |