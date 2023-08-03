#include "subscribe.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <random>
#include "bubbleSort.h"
#include "printVec.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "radixSort.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "heapSort.h"
#include "twoSort.h"

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
    // vector holding 1000 items
    vector<Subscribe> subs;

    // getting data from file
    getDataFromFile("../topSubscribed.csv", subs);

    // shuffle function using default random engine
    std::shuffle(subs.begin(), subs.end(), default_random_engine(0));


    for (int i = 1000; i >= 100; i = i - 100){
        subs.resize(i);
        cout << " For a vector of size : " << subs.size() << endl ;

        //bubbleSort constants & call
        int read1 = 0;
        int write1 = 0;
        bubbleSort<Subscribe>(subs, read1, write1);

        // selectionSort constants & call
        int read2 = 0;
        int write2 = 0;
        selectionSort(subs,read2, write2);
        cout << "The number of reads and writes in Selection Sort, respectively : " << endl ;
        cout << read2 << endl;
        cout << write2 << endl;

        // mergeSort constants & call
        int read3 = 0;
        int write3 = 0;
        mergeSort(subs, read3, write3);
        cout << "The number of reads and writes in Merge Sort, respectively : " << endl ;
        cout << read3 << endl;
        cout << write3 << endl;

        // heap sort
        int read4 = 0;
        int write4 = 0;
        heapSort<Subscribe>(subs, read4, write4);
        cout << "The number of reads and writes in Heap Sort, respectively : " << endl;
        cout << read4 << endl;
        cout << write4 << endl;

        int read5  = 0;
        int write5 = 0;
        twoSort(subs, read5, write5);
        cout << "The number of reads and writes in Two Sort, respectively : " << endl;
        cout << read5 << endl;
        cout << write5 << endl;

        int read6 = 0;
        int write6= 0;
        heapSort<Subscribe>(subs, read6, write6);
        cout << "The number of reads and writes in the resize method loop : " << endl;
        cout << read6 << endl;
        cout << write6 << endl;


    }







    return 0;
};
