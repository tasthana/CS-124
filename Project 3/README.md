# CS 124 Project 3

Explore Binary Search trees, AVL trees, and Splay trees!

For this project, you will store your 1000+ objects in a Binary Search Tree, an AVL Tree, and a Splay Tree. You will search for objects in the tree and record how many objects you had to visit to complete the search. You will analyze your results from the different data structures.

## Setup
You will want to start at the end of Project 1. You should have a vector of 1000+ objects in your main function.
* You will need to overload the <, >, <=, >=, and == operators of your class from Project 1. Use the unique field to compare objects of your class to ensure that all objects get stored in the trees.

## Requirements

### Tree Classes
Modify the find methods of each tree class (Binary Search Tree, AVL Tree, and Splay Tree) so that a search of the tree also stores the depth of the last node visited. To do this without losing information, pass an integer by reference into both find methods and modify the integer inside the methods.
* The root node is at depth 0.
* Even if the search fails, you should still record the depth of the last node visited.

### Main Function
Create a Binary Search Tree, an AVL Tree, and a Splay Tree all of type integer. Using a loop, insert the integers from 1 to 100 in order. In a second loop, find each integer in order and record the depths to a file in the data folder.
* Check for understanding: print the return values and depths you get from the BST find method if you search for 0, 101, and 102 (you should get 1, 100, and 100, respectively).

Create a Binary Search Tree, an AVL Tree, and a Splay Tree all of type integer. Using a loop, insert the integers from 1 to 100 in a random order. In a second loop, find each integer in order and record the depths to a file in the data folder.
* You can get a random sequence either from random.org or by shuffling a vector of numbers (C++ has a shuffle function).

Create a Binary Search Tree, an AVL Tree, and a Splay Tree all of your custom data type. Using a loop, insert all 1000+ objects into the trees in the order they appear in your vector. In a second loop, find each custom object in the same order and record the depths to a file in the data folder.

Create another Splay Tree of your custom data type. Using a loop, insert all 1000+ objects in the order they appear in your vector. In a second loop, find each object five times in a row before searching for the next object and record the depths to a file in the data folder.
* You should have 5000+ depths stored in the file for this tree.
* You should have a total of 10 tree objects in main.

### Report
You must write a report about your project. Answer the following questions directly in this section of the README file:
* You will have a different grader again, so make sure your report includes information about your dataset.
* I have seven total attributes in this dataset, it's all about the top 1000 Youtube Channels!
* Rank, which is decided by number of subscribers per channel on Youtube.
* Youtube Channel, which is the name of the channel.
* Subscribers, which gives us the number of subs per channel.
* Video Views, the total amount of times an audience views a video.
* Video Counts, the number of videos a channel has.
* Category, which is a youtube stat to define which category each channel falls into.
* Started is the year that the channel was started.
* 
* How do the depths of the random-ordered integers compare to the depths of the ordered integers for each tree? Why?
* They are pretty much the same. Both have a vector of n = 100 total, and they are both counting the depths equally.

* How do the depths of each custom-data-type tree compare to each other?
* For the custom data type trees, the BST is what to be expected, a linear function that graphs positively for my data set, which compares rankings. 
* For the custom data type trees, the AVL Tree graph shows that the depths increase by stepping through the data. It is not as high as the BST, and tops off at depth of 9.
* For the custom data type trees, the Splay Tree numbers make sense as the highest values come first, as that is what splaying does. The rest of the values are quite low as it doesn't take that much movement to splay. 

* Why do the depths of the second custom-data-type Splay Tree make sense?
*    The depths of the second custom data splay make sense because of the way splaying works. Over a vector that is 900+, it takes a few more moves to splay a tree then with the random/ordered tree vectors set to 100.
* There are many more moves necessary, and that's why there are many more zeros. 

* Graph the Binary Search Tree, AVL Tree, and Splay Tree depths for the custom data type trees. Do not use C++ to graph, you can use whatever spreadsheet application or graphical programming language you prefer. You can use whatever graph is most readable to you (e.g. scatter plot, histogram, etc.).
* ![AVL_Tree](graphs/AVL%20Tree.png)
* ![splay_tree](graphs/splay%20tree.png)
* ![BST](graphs/BST.png)
 
* Compare and contrast the graphs and explain the differences based on what you know about the structure and behavior of the trees. Justify the time complexity of searching the trees based on the results.
* The insertion time of an AVL tree is O(log n), which makes it faster and more efficient than the Binary Search Tree. The splay tree is better if there are going to be nodes that are accessed multiple times in a short period of time, which is why we did the custom data type tree 5 times. 
* The complexity of a BST is O(1), and depends on the height of the tree, which would make it the least efficient in searching through a vector that is as long as mine.
* As noted in the graphs above, a BST would take much longer than an AVL tree would to search, as AVL is self-balancing and has a much shorter height. 

**Note: Any code that was not authored by yourself or the instructor must be cited in your report. This includes the use of concepts not taught in lecture.**
* There is something wrong with my data set, as it prints a full data set with multiple errors and an extra 100 zero values. TA's and I couldn't figure it out, so that is why my custom data types are capped at 900 rather then a 1000. 
* If possible, while grading, if it could be noted that I couldn't figure it out myself, and TA's couldn't either, that would be appreciated. 
## Submit
You must include your source files (including the three modified tree header files, your class header file, and the main program file), your data files (including your .csv data file and all of the output depth files), your image files (including all graphs you analyze in your report), CMakeLists.txt, and your updated README.md file that contains your report to your repository. Submit to Gradescope using the GitHub repository link, double-check that all the correct files are there, and wait for the autograder to provide feedback.

## Extra Credit
To earn up to 10 extra credit points (at the grader’s discretion), you can get more thorough results. This can include:
* Setting timers to record how long it takes you to search for the objects in each data structure and analyzing the results
* Performing more experiments with the order of insertions/searches and analyzing the results
* Performing the same experiments on 100, 200, 300, …N objects and graphing the results

Note that if you add this logic to your code but do not analyze it in your report, it will not count towards extra credit. If you choose to complete extra credit, include an analysis in this section of your README.md file.

## Grading
The project is out of 80 points.

| Points Possible | Description of requirement |
|------------------- | ----------------------------- |
| 5 pts | Program compiles and runs. |
| 5 pts | Code style. Readable, naming style is consistent, comments where appropriate. |
| 15 pts | The three BSTs in the main function are complete and correct |
| 15 pts | The three AVL Trees in the main function are complete and correct |
| 20 pts | The four Splay Trees in the main function are complete and correct |
| 20 pts | Report: analysis of results, professional, grammatically correct, cites sources. |
