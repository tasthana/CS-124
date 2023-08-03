#ifndef SORTING_SELECTIONSORT_H
#define SORTING_SELECTIONSORT_H

#include "printVec.h"

template<typename Comparable>
void selectionSort(vector<Comparable> &vec, int &reads1, int &writes1) {
    int swapIndex, i, minIndex;
    Comparable temp;
    for (swapIndex = 0; swapIndex < vec.size()-1; ++swapIndex) {
        // Loop through vector starting at swapIndex and keep track of min
        minIndex = swapIndex;
        for (i = swapIndex+1; i < vec.size(); ++i) {
            reads1 +=1;
            if (vec[i] < vec[minIndex]) {
                // We have a new minimum
                minIndex = i;
                reads1 +=1;
                writes1 +=1;
            }
        }
        // Swap min value into swapIndex spot in vector
        temp = vec[swapIndex];
        reads1 +=1;
        writes1 +=1;
        vec[swapIndex] = vec[minIndex];
        reads1 +=1;
        writes1 +=1;
        vec[minIndex] = temp;
        reads1 +=1;
        writes1 +=1;
    }

}

#endif
