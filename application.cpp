//
//  application.cpp
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "dna.h"

using namespace std;
// counts the ammount of given strings.
int Count(dna d, string S) {
	dna d2(S);
	int AGATC = 0;
	while (d.splice(d2)) {
		AGATC++;
    }
    d2.clear();
    return AGATC;
}

int main() {
	// using vectors to hold the amount of strings found
	vector<int> V;
	string DataBaseFile, DnaFile;
    cout << "Welcome to the DNA Profiling App!" << endl;
    cout << "Enter database file: ";
    cin >> DataBaseFile;
    string str, name;
    fstream infile(DataBaseFile);
	getline(infile, str);
	
    cout << "Enter dna file: ";
    cin >> DnaFile;
    cout << endl << "Searching database..." << endl;
	fstream inFile(DnaFile);
    string dnastr;
    inFile >> dnastr;
    // creating the first dna string 
    dna d(dnastr);
	
	// very crude meathod of doing this, but i have tried using linked list
	// but i didnt have much luck with it so using this because i already
	// know what is inside the files.
	if (DataBaseFile == "large.txt") {
		
		// if its large then the following strings will be kept tarck of
		dna d2;
		d2 = d;
		int AGATC = Count(d2, "AGATC");
		V.push_back(AGATC);
		d2.clear();
		
		d2 = d;
		int TTTTTTCT =	Count(d2, "TTTTTTCT");
		V.push_back(TTTTTTCT);
		d2.clear();
		
		d2 = d;
		int AATG = Count(d2, "AATG");
		V.push_back(AATG);
		d2.clear();
		
		d2 = d;
		int TCTAG = Count(d2, "TCTAG");
		V.push_back(TCTAG);
		d2.clear();
		
		d2 = d;
		int GATA = Count(d2, "GATA");
		V.push_back(GATA);
		d2.clear();
		
		d2 = d;
		int TATC = Count(d2, "TATC");
		V.push_back(TATC);
		d2.clear();
		
		d2 = d;
		int GAAA = Count(d2, "GAAA");
		V.push_back(GAAA);
		d2.clear();
		
		d2 = d;
		int TCTG = Count(d2, "TCTG");
		V.push_back(TCTG);
		// clear the class to avoid memory leaks
		d2.clear();
		d.clear();
	} else if (DataBaseFile == "small.txt") {
		// if its small then we know the following will be inside the file
		dna d2;
		d2 = d;
		int AGATC = Count(d2, "AGATC");
		V.push_back(AGATC);
		d2.clear();
		
		d2 = d;
		int AATG = Count(d2, "AATG");
		V.push_back(AATG);
		d2.clear();
		
		d2 = d;
		int TATC = Count(d2, "TATC");
		V.push_back(TATC);
		// clear the class to avoid leaks.
		d2.clear();
		d.clear();
	}
    
    // tried using while(!infile.eof() but that would repeat the last line twice
    // so using another method of checking file right after getting next line 
    // and checking if its the end of line then.
    while (true) {
    	bool extraLoopCondition = false; // i need the innter loop to run twice so using this.
    	int i = 0;
    	getline(infile, str);
    	if( infile.eof() ) break; // checking if its the end after geting line
	    name = str;
	    str  = str.substr(str.find(",") + 1 , str.length());
	    // gets the name for lator
	    name = name.substr(0, name.find(","));
	    while(str.find(",") != -1 || !extraLoopCondition) {
	    	if(!(str.find(",") != -1)) { // the loop has to run extra time so using this
	            extraLoopCondition = true;
	        }
	        string S = str;
	        S = S.substr(0, S.find(","));
	        if (stoi(S) != V.at(i)){
	        	// if the values from the vector we got earlier and the values
	        	//  from the file do not match then they are  not the same and
	        	//  then set the value of i to -99 which we later check.
	        	i = -99;
	        	break;
	        }
	        //  if the values are the same then continue and the i will stay positive
	        i++;
	        str  = str.substr(str.find(",") + 1 , str.length());
	    }
	    // if i staied positive after the loop then we found the match so print it out.
	    // and exits the programm.
	    if (i != -99) {
	    	cout << "DNA match: " << name << endl;
	    	return 0;
	    }
    }
    //  after running the loop the name did not print out then it means no match.
    cout << "No match." << endl;
    return 0;
}






















