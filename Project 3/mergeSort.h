#ifndef MERGESORT_H
#define MERGESORT_H

#include "printVec.h"

template<typename Comparable>
void mergeSortRec(vector<Comparable> &vec, int startIndex, int endIndex, int &read2, int &write2 ) {
    // Recursive base case
    if (startIndex >= endIndex) {
        return;
    }

    // Recursive calls for the left and right halves
    int centerIndex = (startIndex + endIndex) / 2;
    mergeSortRec(vec, startIndex, centerIndex, read2, write2 );
    mergeSortRec(vec, centerIndex + 1, endIndex, read2, write2 );


    // Merge
    vector<Comparable> temp;
    int leftIndex = startIndex;
    int rightIndex = centerIndex + 1;
    // While leftIndex and rightIndex are in bounds of their half
    while (leftIndex <= centerIndex && rightIndex <= endIndex) {
        if (vec[leftIndex] <= vec[rightIndex]) {
            temp.push_back(vec[leftIndex]);
            read2 += 1;
            write2 += 1;
            ++leftIndex;
        } else {
            temp.push_back(vec[rightIndex]);
            ++rightIndex;
            read2 += 1;
            write2 += 1;
        }
    }
    // Now one of the halves is empty and the other half has at least one element left to copy into temp
    while (leftIndex <= centerIndex) {
        temp.push_back(vec[leftIndex]);
        read2 += 1;
        write2 += 1;
        ++leftIndex;
    }
    while (rightIndex <= endIndex) {
        temp.push_back(vec[rightIndex]);
        read2 += 1;
        write2 += 1;
        ++rightIndex;
    }
    // Now everything between startIndex and endIndex is copied into temp
    // Copy everything from temp back into vec
    for (int i = 0; i < temp.size(); ++i) {
        vec[i + startIndex] = temp[i];
        read2 += 1;
        write2 += 1;
    }

}

template<typename Comparable>
void mergeSort(vector<Comparable> vec, int &read2, int &write2) {
    mergeSortRec(vec, 0, vec.size() - 1, read2, write2 );
}

#endif
