#include <iostream>
#include "subscribe.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "string.h"
#include "SeparateChaining.h"
#include "OpenAddressing.h"

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

string getKey(Subscribe subs){
    return (subs.getChannel());
}

string getKey2(Subscribe subs){
    return to_string(subs.getRank());
}
// main function
int main() {
    // entire file vector
    vector<Subscribe> subs;
    getDataFromFile("../topSubscribed.csv", subs);


    // ---------------------------------- start of project 5 code----------------------------------------- //

    // declare constant
    int numReads =0;

    // Separate Chaining Tables using key
    SeparateChaining<Subscribe> sepChain1(923, getKey, numReads);
    SeparateChaining<Subscribe> sepChain2(1500, getKey, numReads);
    SeparateChaining<Subscribe> sepChain3(2000, getKey, numReads);
    SeparateChaining<Subscribe> sepChain4(2500, getKey, numReads);
    SeparateChaining<Subscribe> sepChain5(3000, getKey, numReads);

    // Separate Chaining Tables using key2
    SeparateChaining<Subscribe> sepChain6(923, getKey2, numReads);
    SeparateChaining<Subscribe> sepChain7(1500, getKey2, numReads);
    SeparateChaining<Subscribe> sepChain8(2000, getKey2, numReads);
    SeparateChaining<Subscribe> sepChain9(2500, getKey2, numReads);
    SeparateChaining<Subscribe> sepChain10(3000, getKey2, numReads);

    // Quad Probing using key
    QuadraticProbing<Subscribe> quadProb1(923, getKey);
    QuadraticProbing<Subscribe> quadProb2(1500, getKey);
    QuadraticProbing<Subscribe> quadProb3(2000, getKey);
    QuadraticProbing<Subscribe> quadProb4(2500, getKey);
    QuadraticProbing<Subscribe> quadProb5(3000, getKey);

    // Quad Probing using key2
    QuadraticProbing<Subscribe> quadProb6(1000, getKey2);
    QuadraticProbing<Subscribe> quadProb7(1500, getKey2);
    QuadraticProbing<Subscribe> quadProb8(2000, getKey2);
    QuadraticProbing<Subscribe> quadProb9(2500, getKey2);
    QuadraticProbing<Subscribe> quadProb10(3000, getKey2);


     // open file 1 and insert num Reads
    ofstream f_out;
    f_out.open("../sepchain1.csv");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        sepChain1.insert(subs[i], numReads);
        if (f_out) {
            // use get num reads function
            f_out << numReads << endl;
        }
        numReads = 0;
    }
    f_out.close();


    // open file 2 and insert num Reads
    ofstream f_out2;
    f_out2.open("../sepchain2.csv");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        sepChain2.insert(subs[i], numReads);
        if (f_out2) {
            // use get num reads function
            f_out2 << numReads << endl;
        }
        numReads = 0;
    }
    f_out2.close();


    // open file 3 and insert num Reads
    ofstream f_out3;
    f_out3.open("../sepchain3.csv ");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        sepChain3.insert(subs[i], numReads);
        if (f_out3) {
            // use get num reads function
            f_out3 << numReads << endl;
        }
        numReads = 0;
    }
    f_out3.close();


    // open file 4 and insert num Reads
    ofstream f_out4;
    f_out4.open("../sepchain4.csv ");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        sepChain4.insert(subs[i], numReads);
        if (f_out4) {
            // use get num reads function
            f_out4 << numReads << endl;
        }
        numReads = 0;
    }
    f_out4.close();


    // open file 5 and insert num Reads
    ofstream f_out5;
    f_out5.open("../sepchain5.csv ");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        sepChain5.insert(subs[i], numReads);
        if (f_out5) {
            // use get num reads function
            f_out5 << numReads << endl;
        }
        numReads = 0;
    }
    f_out5.close();


    // open file 6 and insert num Reads
    ofstream f_out6;
    f_out6.open("../sepchain6.csv ");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        sepChain6.insert(subs[i], numReads);
        if (f_out6) {
            // use get num reads function
            f_out6 << numReads << endl;
        }
        numReads = 0;
    }
    f_out6.close();


    // open file 7 and insert num Reads
    ofstream f_out7;
    f_out7.open("../sepchain7.csv ");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        sepChain7.insert(subs[i], numReads);
        if (f_out7) {
            // use get num reads function
            f_out7 << numReads << endl;
        }
        numReads = 0;
    }
    f_out7.close();


    // open file 8 and insert num Reads
    ofstream f_out8;
    f_out8.open("../sepchain8.csv ");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        sepChain8.insert(subs[i], numReads);
        if (f_out8) {
            // use get num reads function
            f_out8 << numReads << endl;
        }
        numReads = 0;
    }
    f_out8.close();


    // open file 9 and insert num Reads
    ofstream f_out9;
    f_out9.open("../sepchain9.csv ");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        sepChain9.insert(subs[i], numReads);
        if (f_out9) {
            // use get num reads function
            f_out9 << numReads << endl;
        }
        numReads = 0;
    }
    f_out9.close();


    // open file 10 and insert num Reads
    ofstream f_out10;
    f_out10.open("../sepchain10.csv ");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        sepChain10.insert(subs[i], numReads);
        if (f_out10) {
            // use get num reads function
            f_out10 << numReads << endl;
        }
        numReads = 0;
    }
    f_out10.close();



    // open quad file 1
    ofstream f_outQ1;
    f_outQ1.open("../QuadProb1.csv ");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        quadProb1.insert(subs[i], numReads);
        if (f_outQ1) {
            // use get num reads function
            f_outQ1 << numReads << endl;

        }
        numReads = 0;
    }
    cout << "table 1 size :" << quadProb1.getTableSize() << endl;
    f_outQ1.close();


    // open quad file 2
    ofstream f_outQ2;
    f_outQ2.open("../QuadProb2.csv ");

    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        quadProb2.insert(subs[i], numReads);
        if (f_outQ2) {
            // use get num reads function
            f_outQ2 << numReads << endl;

        }
        numReads = 0;
    }
    cout << "table 2 size :" <<quadProb2.getTableSize() << endl;
    f_outQ2.close();


    // open quad file 3
    ofstream f_outQ3;
    f_outQ3.open("../QuadProb3.csv ");
    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        quadProb3.insert(subs[i], numReads);
        if (f_outQ3) {
            // use get num reads function
            f_outQ3 << numReads << endl;
        }
        numReads = 0;
    }
    cout << "table 3 size :" <<quadProb3.getTableSize() << endl;
    f_outQ3.close();

    // open quad file 4
    ofstream f_outQ4;
    f_outQ4.open("../QuadProb4.csv ");
    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        quadProb4.insert(subs[i], numReads);
        if (f_outQ4) {
            // use get num reads function
            f_outQ4 << numReads << endl;
        }
        numReads = 0;
    }
    cout << "table 4 size :" <<quadProb4.getTableSize() << endl;
    f_outQ4.close();

    // open quad file 5
    ofstream f_outQ5;
    f_outQ5.open("../QuadProb5.csv ");
    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        quadProb5.insert(subs[i], numReads);
        if (f_outQ5) {
            // use get num reads function
            f_outQ5 << numReads << endl;
        }
        numReads = 0;
    }
    cout << "table 5 size :" <<quadProb5.getTableSize() << endl;
    f_outQ5.close();

    // open quad file 6
    ofstream f_outQ6;
    f_outQ6.open("../QuadProb6.csv ");
    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        quadProb6.insert(subs[i], numReads);
        if (f_outQ6) {
            // use get num reads function
            f_outQ6 << numReads << endl;
        }
        numReads = 0;
    }
    cout << "table 6 size :" <<quadProb6.getTableSize() << endl;
    f_outQ6.close();


    // open quad file 7
    ofstream f_outQ7;
    f_outQ7.open("../QuadProb7.csv ");
    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        quadProb7.insert(subs[i], numReads);
        if (f_outQ7) {
            // use get num reads function
            f_outQ7 << numReads << endl;
        }
        numReads = 0;
    }
    cout <<  "table 7 size :" << quadProb7.getTableSize() << endl;
    f_outQ7.close();

    // open quad file 8
    ofstream f_outQ8;
    f_outQ8.open("../QuadProb8.csv ");
    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        quadProb8.insert(subs[i], numReads);
        if (f_outQ8) {
            // use get num reads function
            f_outQ8 << numReads << endl;
        }
        numReads = 0;
    }
    cout << "table 8 size :" <<quadProb8.getTableSize() << endl;
    f_outQ8.close();

    // open quad file 9
    ofstream f_outQ9;
    f_outQ9.open("../QuadProb10.csv ");
    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        quadProb9.insert(subs[i], numReads);
        if (f_outQ9) {
            // use get num reads function
            f_outQ9 << numReads << endl;
        }
        numReads = 0;
    }
    cout << "table 9 size :" <<quadProb9.getTableSize() << endl;
    f_outQ9.close();


    // open quad file 10
    ofstream f_outQ10;
    f_outQ10.open("../QuadProb10.csv ");
    // Single loop to add everything into tables
    for (int i = 0; i < subs.size(); i++) {
        quadProb10.insert(subs[i], numReads);
        if (f_outQ10) {
            // use get num reads function
            f_outQ10 << numReads << endl;
        }
        numReads = 0;
    }
    cout << "table 10 size :" << quadProb10.getTableSize() << endl;
    f_outQ10.close();




}
