#pragma once
#include <string>
#include <iomanip>;

using namespace std;

class Person
{
private:
	string name;
	int id;
	int age;
	string job;
	int hireyear;

public:
	Person(string, int, int, string, int);

	int getId() {
		return id;
	}

	string getName() {
		return name;
	}

	int getAge() {
		return age;
	}

	string getJob() {
		return job;
	}

	int getHireYear() {
		return hireyear;
	}


	// print out all the records in a pretty human - readable format
	// returns the information of each person identified by the IDs in the query file.
	void printRecord() {
		cout << "Name: " << name << " ID: " << id << ", Age: " << age << ", Job : " << job << ", Hired : " << hireyear << endl;
	}
};
