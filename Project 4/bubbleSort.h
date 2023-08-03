#ifndef SORTING_BUBBLESORT_H
#define SORTING_BUBBLESORT_H

#include "printVec.h"

template<typename Comparable>
void bubbleSort(vector<Comparable> vec, int &reads, int &writes) {
    int numPasses = 0, i;
    Comparable temp;
    bool haveSwapped = true;
    while (haveSwapped) {
        haveSwapped = false;
        for (i = 0; i+1 < vec.size()-numPasses; ++i) {
            reads += 2;
            // Compare items at indices i and i+1 and swap if necessary
            if (vec[i] > vec[i+1]) {

                temp = vec[i]; // read and write
                reads += 1;
                writes +=1;
                vec[i] = vec[i+1]; // read and write
                reads += 1;
                writes +=1;
                vec[i+1] = temp; // read and write
                reads += 1;
                writes +=1;
                // Update haveSwapped
                haveSwapped = true;
            }
        }
        // Update numPasses
        ++numPasses;


    }
    cout << "This is the number of reads and writes in Bubble Sort, respectively :"  << endl;
    cout << reads << endl;
    cout << writes << endl;
}

#endif
