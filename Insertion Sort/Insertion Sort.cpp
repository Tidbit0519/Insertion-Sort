#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include "Person.h"
#include <sstream>

using namespace std;
vector<Person> record;
int comparisons;

// Match the attributes of Person class to the method parameters.
Person::Person(string n, int i, int a, string j, int h) {
    name = n;
    id = i;
    age = a;
    job = j;
    hireyear = h;
}

// A helper function that prints the ID to show the Bubble Sort process.
void printIdOnly() {
    for (Person person : record)
    {
        cout << person.getId() << " ";
    }
    cout << endl;
}

// Insertion Sort algorithm
void insertionSort() {
    // starting from the second index down to the last index.
    for (int i = 1; i < record.size(); i++) {
        // key is used as comparison
        Person key = record[i];
        // j is the one before key
        int j = i - 1;
        // Swaps j and key if the id of j is larger than the id of key.
        while (j >= 0 && record[j].getId() > key.getId()) {
            comparisons += 1;
            swap(record[j + 1], record[j]);
            j = j - 1;
        }
        // printIdOnly();
        // Moves the key pointer to the next index if id of j is not larger than the id of key.
        record[j + 1] = key;
    }
}


// writes the sorted record to a .txt file
void writeToFile() {
    ofstream ofs;
    ofs.open("C:/Users/Jason Tan/OneDrive - Brigham Young University Hawaii/Documents/output.txt");
    for (Person person : record) {
        ofs << person.getName() << "|" << person.getId() << "|" << person.getAge() << "|" << person.getJob() << "|" << person.getHireYear() << endl;
    }
}

// agrc = total argument count, argv = the arguments passed into the function
int main(int argc, char** argv) {

    // check for errors: missing argument or file not found
    if (argc == 1) {
        cout << "You forgot the command line parameter" << endl;
        exit(0);
    }
    ifstream ifs;
    ifs.open(argv[1], ios::in);
    if (!ifs) {
        cout << "could not find file " << argv[1] << endl;
        exit(0);
    }

    // checks the first line of the file to determine the number of records in the file, and the number of times to be looped.
    string firstLine;
    // getline gets the first line from the ifstream and stores it into a string variable
    getline(ifs, firstLine);
    // Convert firstLine into an int
    int recordNum = stoi(firstLine);


    for (int i = 0; i < recordNum; i++)
    {
        string nextLine;
        // gets the nextline
        getline(ifs, nextLine);

        string name;
        int id;
        int age;
        string job;
        int hireyear;

        char delimiter = '|';
        string words;
        stringstream ss(nextLine);
        // gets the next word until it spots a pipe "|" delimeter
        // initializing each object's fields with data from the file
        getline(ss, words, delimiter);
        name = words;
        getline(ss, words, delimiter);
        id = stoi(words);
        getline(ss, words, delimiter);
        age = stoi(words);
        getline(ss, words, delimiter);
        job = words;
        getline(ss, words, delimiter);
        hireyear = stoi(words);

        // instantiating a new object for each record in the file
        Person employee(name, id, age, job, hireyear);
        record.push_back(employee);
    }
    insertionSort();
    cout << "It took " << comparisons << " comparisons to sort this list.";
    //writeToFile();
}

// Big O of Binary Search is O(log2 n) because it cuts the search in half every time it searches.