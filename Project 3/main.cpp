#include "AVLTree.h"
#include "BinarySearchTree.h"
#include "SplayTree.h"
#include <fstream>
#include <iostream>
#include "subscribe.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <random>
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

        // Project Three Main Part 1 Code ----------------------------------------------
        // initializing counter for depth value
        int depth_value=0;

        //creating vectors for first three main functions
        BinarySearchTree<int> bst1;
        AVLTree<int> avt1;
        SplayTree<int> st1;

        // adding 1 - 100 to each tree in Part 1
        for (int i = 1; i <=100; ++i) {
            bst1.add(i);
            avt1.add(i);
            st1.add(i);
        }

        // opening out file for BST 1
        // finding depth value and printing it out to output file
        // close file
        ofstream outFile;
        outFile.open("../data/bst-output-1.csv");
        for (int i = 1; i <= 100; ++i){
            bst1.find(i, depth_value);
            outFile << depth_value << endl;
            depth_value=0;
        }
        outFile.close();

        // opening out file for AVL Tree 1
        // finding depth value and printing it out to output file
        // close file
        ofstream outFile2;
        outFile2.open("../data/avl-output-1.csv");
        for (int i = 1; i <= 100; ++i){
            avt1.find(i, depth_value);
            outFile2 << depth_value << endl;
            depth_value=0;
        }
        outFile2.close();

        // opening out file for Splay Tree 1
        // finding depth value and printing it out to output file
        // close file
        ofstream outFile3;
        outFile3.open("../data/st-output-1.csv");
        for (int i = 1; i <= 100; ++i){
            st1.find(i, depth_value);
            outFile3 << depth_value << endl;
            depth_value=0;
        }
        outFile3.close();

        //checking for understanding, and printing
        depth_value = 0;
        bst1.find(0,depth_value);
        cout << depth_value << endl;

        depth_value = 0;
        bst1.find(101,depth_value);
        cout << depth_value << endl;

        depth_value = 0;
        bst1.find(102,depth_value);
        cout << depth_value << endl;


        // Project Three Main Part 2 Code ----------------------------------------------

        // declaring new trees
        BinarySearchTree<int> bst2;
        AVLTree<int> avt2;
        SplayTree<int> st2;

        // creating a new vector to be shuffled
        const int n = 100;
        std::vector<int> v(n);

        // adding to the vector by pushing back i
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }

        // shuffle function using default random engine
        std::shuffle(v.begin(), v.end(), default_random_engine(0));

        //insert the shuffled integers from 1 to 100 in order for Part 2
        for (int i = 0; i < v.size(); i++){
            bst2.add(v[i]);
            avt2.add(v[i]);
            st2.add(v[i]);
        }

        // opening out file for BST 2
        // finding depth value and printing it out to output file
        // reset depth_value to 0
        // close file
        ofstream outFile4;
        outFile4.open("../data/bst-output-2.csv");
        depth_value = 0;
        for (int i = 1; i <= 100; ++i) {
            bst2.find(i, depth_value);
            outFile4 << depth_value << endl;
            depth_value = 0;
        }
        outFile4.close();


        // opening out file for AVL Tree 2
        // finding depth value and printing it out to output file
        // reset depth_value to 0
        // close file
        ofstream outFile5;
        outFile5.open("../data/avl-output-2.csv");
        depth_value = 0;
        for (int i = 1; i <= 100; ++i) {
            avt2.find(i, depth_value);
            outFile5 << depth_value << endl;
            depth_value = 0;
        }
        outFile5.close();


        // opening out file for Splay Tree 2
        // finding depth value and printing it out to output file
        // reset depth_value to 0
        // close file
        ofstream outFile6;
        outFile6.open("../data/st-output-2.csv");
        depth_value = 0;
        for (int i = 1; i <= 100; ++i) {
            st2.find(i, depth_value);
            outFile6 << depth_value << endl;
            depth_value = 0;
        }
        outFile6.close();


        // Project Three Main Part 3 Code ----------------------------------------------
        // custom data used in trees

        // new trees
        BinarySearchTree<Subscribe> bst3;
        AVLTree<Subscribe> avt3;
        SplayTree<Subscribe> st3;

        // vector from project 1
        vector<Subscribe>subs;

        // creating a new vector to pushback into
        getDataFromFile("../topSubscribed.csv", subs);
        std::vector<Subscribe> subsData;

        // pushback function
        for (int i = 0; i < 900; ++i){
            subsData.push_back(subs[i]);
        }

        //insert the shuffled integers from 1 to 100 in order for Part 2
        for (int i = 0; i < 900; i++){
            bst3.add(subsData[i]);
            avt3.add(subsData[i]);
            st3.add(subsData[i]);
        }

        // opening out file for BST 3
        // finding depth value and printing it out to output file
        // reset depth_value to 0
        // close file
        ofstream outFile7;
        outFile7.open("../data/bst-output-3.csv");
        depth_value = 0;
        for (int i = 1; i < 900; ++i) {
            bst3.find(subs[i], depth_value);
            outFile7 << depth_value << endl;
            depth_value = 0;
        }
        outFile7.close();

        // opening out file for AVL Tree 3
        // finding depth value and printing it out to output file
        // reset depth_value to 0
        // close file
        ofstream outFile8;
        outFile8.open("../data/avl-output-3.csv");
        depth_value = 0;
        for (int i = 1; i < 900; ++i) {
            avt3.find(subs[i], depth_value);
            outFile8 << depth_value << endl;
            depth_value = 0;
        }
        outFile8.close();

        // opening out file for Splay Tree 3
        // finding depth value and printing it out to output file
        // reset depth_value to 0
        // close file
        ofstream outFile9;
        outFile9.open("../data/st-output-3.csv");
        depth_value = 0;
        for (int i = 1; i < 900; ++i) {
            st3.find(subs[i], depth_value);
            outFile9 << depth_value << endl;
            depth_value = 0;
        }
        outFile9.close();


        // Project Three Main Part 4 Code ----------------------------------------------
        // Custom Splay Tree, find 5 times

        SplayTree<Subscribe> st4;

        for (int i = 0; i < 900; i++) {
            st4.add(subsData[i]);
        }

        //opening out file for Splay Tree 3
        //finding depth value and printing it out to output file
        //reset depth_value to 0
        // close file
        ofstream outFile10;
        outFile10.open("../data/st-output-4.csv");
        depth_value = 0;
        int x = 5;
            for (int i = 1; i < 900; ++i) {
                for (int j = 1; j <= x; ++j) {
                    st4.find(subs[i], depth_value);
                    outFile10 << depth_value << endl;
                    depth_value = 0;
                }
            }

        outFile10.close();



        return 0;


    };

