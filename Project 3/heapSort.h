#ifndef SORTING_HEAPSORT_H
#define SORTING_HEAPSORT_H

#include "printVec.h"
#include <vector>

using std::vector;

// Helper function for heapSort
inline int leftChild(int i) {
    return 2 * i + 1;
}

// Helper function for heapSort
// i is the index of the value being percolated down
// n is the number of items in the heap
template <typename Comparable>
void percolateDown(vector<Comparable> &items, int& i, unsigned long& n, int& child, Comparable& tmp, int &read3, int &write3) {
    for(tmp = items[i]; leftChild(i) < n; i = child) {
        child = leftChild(i); // read and write
        read3 += 1;
        write3 +=1;
        // choose the child with the larger value
        read3 +=2;   // 2 reads
        if (child != n - 1 && items[child] < items[child + 1]) {
            ++child;
        }
        // if the parent is less than the child, swap them
        read3 +=1 ;
        if (tmp < items[child]) {
            items[i] = items[child];
            read3 += 1;
            write3 +=1;
        } else {
            // parent is >= both children. nothing more to do.
            break;
        }
    }
    items[i] = tmp;
    read3 += 1;
    write3 +=1;
}

template <typename Comparable>
vector<Comparable> heapSort(vector<Comparable> items, int &read3, int &write3) {
    int i, child;
    Comparable temp, tmp;
    unsigned long j, n;
    // build the heap (with max value at root)
    for (i = items.size() / 2 - 1; i >= 0; --i) {
        n = items.size();
        percolateDown(items, i, n, child, tmp, read3, write3);

    }
    // keep deleting the max
    for (j = items.size() - 1; j > 0; --j) {
        // swap the maximum out
        temp = items[0];
        read3+=1;
        write3 +=1;
        items[0] = items[j];
        read3+=1;
        write3 +=1;
        items[j] = temp;
        read3+=1;
        write3 +=1;

        // make it into a heap again
        i = 0;
        percolateDown(items, i, j, child, tmp, read3, write3);
        read3+=1;
        write3 +=1;

    }

    return items;
}

#endif
