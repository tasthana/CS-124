#include <iostream>
#include "subscribe.h"
#include "Stack.h"
#include "Node.h"
#include "Queue.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// Vector function to perform addition calculation
int getTotalVideoCount(vector<Subscribe> subs)
{
    int total = 0;
    for (int i =0; i < subs.size(); i++)
    {
        total += subs[i].getVideoCount();

    }
    cout << "This is the total of all video counts :  " << endl;
    return total;

}

// main function
int main() {
    // entire file vector
    vector<Subscribe> subs;

    //Two Queue objects: one of integers and one of strings
    Queue<int> test1;
    Queue<std::string > test2;


    // declaring variables for int + string
    int int1 = 1;
    int int2 = 2;
    int int3 = 3;
    string string1 = "Drake is the best commercial rapper ever";
    string string2 = "Jermaine Cole is the best lyrical rapper ever";
    string string3 = "Bryson Tiller walked so Brent Faiyaz could run";

    //Queue Enqueue Int Function
    test1.enqueue(int1);
    test1.enqueue(int2);
    test1.enqueue(int3);

    //Queue Enqueue String Function
    test2.enqueue(string1);
    test2.enqueue(string2);
    test2.enqueue(string3);

    //Search function in both Int + String Variables
    assert(test1.search(int2));
    assert(test2.search(string3));

    //Print Statements
    test1.print();
    cout << "" << endl;
    test2.print();

    //Dequeue Statements
    test1.dequeue();
    test2.dequeue();

    //Create Stack & Queue from Project 1 file
    //Create two Queue vectors for int + string manipulation
    Stack<Subscribe> subStack;
    Queue<Subscribe> subQueue;



    //loop to print and enqueue the first 10 objects from your vector (from Project 1) onto the Queue
    getDataFromFile("../topSubscribed.csv", subs);
    for (int i = 0; i < 10; ++i)
    {
        subQueue.enqueue(subs[i]);
        cout << subs[i] << endl;
    }

    //second loop to dequeue the 10 objects off the Queue and push them onto the Stack
    for(int i = 0; i<10; i++)
    {
        subStack.push(subQueue.dequeue());
    }

    //third loop to pop the 10 objects off the Stack and print them
    for(int i = 0; i<10; i++)
    {
        cout << subStack.pop() <<endl;
    }



};
