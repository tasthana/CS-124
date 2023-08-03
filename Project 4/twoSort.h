//
// Created by Tushar Asthana  on 4/4/23.
//

#ifndef PROJECT4_TWOSORT_H
#define PROJECT4_TWOSORT_H
#include "printVec.h"
#include "selectionSort.h"
#include "subscribe.h"

    void mergeSortRec(vector<Subscribe> &vec, int startIndex, int endIndex, int &read2, int &write2 ) {
        // Recursive base case
        if (startIndex >= endIndex) {
            return;
        }

        // Recursive calls for the left and right halves
        int centerIndex = (startIndex + endIndex) / 2;
        mergeSortRec(vec, startIndex, centerIndex, read2, write2 );
        mergeSortRec(vec, centerIndex + 1, endIndex, read2, write2 );

        // Merge
        vector<Subscribe> temp;
        int leftIndex = startIndex;
        int rightIndex = centerIndex + 1;
        // While leftIndex and rightIndex are in bounds of their half
        while (leftIndex <= centerIndex && rightIndex <= endIndex) {
            if (vec[leftIndex].getChannel() <= vec[rightIndex].getChannel()) {
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


    void mergeSort(vector<Subscribe> vec, int &read2, int &write2) {
        mergeSortRec(vec, 0, vec.size() - 1, read2, write2 );
    }

    template<typename Comparable>
    void twoSort(vector<Comparable> vec, int &read2, int &write2) {
        selectionSort(vec, read2, write2);
        mergeSort(vec, read2, write2);

    }










#endif //PROJECT4_TWOSORT_H
