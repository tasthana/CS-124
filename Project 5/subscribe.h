
#ifndef PROJECT1_SUBSCRIBE_H
#define PROJECT1_SUBSCRIBE_H

//include statements

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>

using std::cout, std::endl, std::ifstream, std::left, std::ostream;
using std::right, std::setw, std::string, std::vector;

class Subscribe{

    //declare all varibles
private:
    int rank;
    string channel;
    int subscribers;
    int videoViews;
    int videoCount;
    string category;
    int started;

    // constructor
public:
    Subscribe(){

    }

    // non default constructor
    Subscribe(int rank, string channel, int subscribers, int videoViews, int videoCount, string category, int started)
    {
        this->rank = rank;
        this->channel = channel;
        this->subscribers = subscribers;
        this->videoViews = videoViews;
        this->videoCount = videoCount;
        this->category = category;
        this->started = started;
    }

    //getters
    int getRank() const {
        return rank;
    }

    string getChannel() const {
        return channel;
    }

    int getSubscribers() const {
        return subscribers;
    }

    int getVideoViews() const {
        return videoViews;
    }

    int getVideoCount() const {
        return videoCount;
    }

    string getCategory() const {
        return category;
    }

    int getStarted() const {
        return started;
    }

    // Setters
    void setRank(int rank) {
        this->rank = rank;
    }

    void setChannel(string channel) {
        this->channel = channel;
    }

    void setSubscribers(int subscribers) {
        this->subscribers = subscribers;
    }

    void setVideoViews(int videoViews) {
        this->videoViews = videoViews;
    }

    void setVideoCount(int videoCount) {
        this->videoCount = videoCount;
    }

    void setCategory(string category) {
        this->category = category;
    }

    void setStarted(int started) {
        this->started = started;
    }


    //overload operator and setw function to format output
    friend std::ostream& operator << (std::ostream& outs, const Subscribe& sub)
    {
        outs << left << setw(10) << sub.getRank();
        outs << setw(30) << sub.getChannel();
        outs << right << setw(30) << sub.getSubscribers();
        outs << setw(30) << sub.getVideoViews();
        outs << setw(25) << sub.getVideoCount();
        outs << setw(80) << sub.getCategory();
        outs << setw(10) << sub.getStarted();
        return outs;
    }

    friend bool operator == (const Subscribe& lhs, const Subscribe& rhs)
    {
        // Compare the unique attribute to determine equality
        return lhs.rank == rhs.rank;
    }
};


void getDataFromFile(string filename, vector<Subscribe>& subs) {
    // Create a file handler object
    ifstream inFile;
    // Open the file
    inFile.open(filename);
    string header;
    // Check if the file can be read from
    if (inFile) {
        // Read a full line from the file into the header string
        getline(inFile, header);
    }

    // Declare variables to be read in
    string channel = "", category = "", junk;
    int rank = -1, subscribers = -1, videoViews = -1, videoCount = -1, started = -1;
    char comma, quote;

    // While the file is still in a good state to be read from
    // and we're not at the end of the file yet
    while (inFile && inFile.peek() != EOF) {

        //rank
        inFile>> rank;
        inFile >> comma;

        // channel
        if (inFile.peek() == '"') {
            inFile >> quote;
            getline(inFile, channel, '"');
            inFile >> comma;
        } else {
            getline(inFile, channel, ',');
        }

        // subscribers
        inFile >> subscribers >> comma;

        // total number of views
        inFile >> videoViews >> comma;

        // video count
        inFile >> videoCount >> comma;

        // category
        if (inFile.peek() == '"') {
            inFile >> quote;
            getline(inFile, category, '"');
            inFile >> comma;
        } else {
            getline(inFile, category, ',');
        }

        // Date Started
        inFile >> started >> comma;

        // If the file is no longer in a good state
        if (!inFile) {
            started = 0000;
            // Clear the file stream
            inFile.clear();
        }
        inFile >> comma;

        // Create a Subscribe object and add it to the vector
        subs.push_back(Subscribe(rank, channel, subscribers, videoViews, videoCount, category, started));
        //get rid of newline character at the end of line
        getline(inFile, junk);

    }

        inFile.close();



}
#endif //PROJECT1_SUBSCRIBE_H
