#pragma once

#include <iostream>
#include <string>

using namespace std;

class dna {
private:
    //
    // This implementation is a doubly-linked structure.  The nodes are structs
    // called Nucleotides.  Size could keep track of how many Nucleotides are
    // currently in the list.  front should always point to the first
    // Nucleotide and back should point to the last one.
    struct Nucleotide {
        char value;
        Nucleotide *next;
        Nucleotide *prev;
    };
    int Size;
    Nucleotide *front;
    Nucleotide *back;
    
    //
    // findFirst: (private)
    //
    // Searches dna for the first copy of the sequence target, returning a
    // pointer to that occurrence or nullptr if the target sequence isn't
    // present.
    // Performance requirement:  this function doesn't have a set Big O target,
    // but should not time out on test cases and be reasonable.
    //
    //  using the target front and front to track down the first instance of target. 
    //  it uses two while loop. first to loop through the string and the second to
    //  loop through the target. if it does not find the instace it returns the 
    // nullptr
    Nucleotide* findFirst(dna target) {
    	Nucleotide *F = front;
    	int index = 0;
    	while (F != nullptr) {
    		Nucleotide *S = target.front;
    		Nucleotide *T = F;
    		while (S != nullptr) {
    			if (T == nullptr || S == nullptr) {
    				return nullptr;
    			}
    			if (T->value == S->value) {
    				index++;
    			} else {
    				break;
    			}
    			T = T->next;
    			S = S->next;
    		}
    		if (index == target.size()) {
    			return F;
    		}
    		index = 0;
    		F = F->next;
    	}
    	return nullptr;
    }
    
public:
    //
    // default constructor:
    //
    // Called automatically by C++ to create an empty dna object with two
    // Nucleotides, each with the value of 'X'.
    //
    
    //  creates two nodes and links them togather with the value of X
    dna() {
    	Size = 0;
        Nucleotide *F = new Nucleotide;
        Size++;
        Nucleotide *S = new Nucleotide;
        Size++;
        front = F;
        back = S;
        F->value = 'X';
        S->value = 'X';
        F->next = S;
        S->next = nullptr;
        S->prev = F;
        F->prev = nullptr;
    }
    
    
    //
    // second constructor:
    //
    // Produces a new strand of nucleotides spelled out in the sequence given
    // by str.
    // Performance requirement: O(n)
    //
    
    // creates a linked list of the string passed in using the length of the string.
    // also handles the case when the string might be an empty string.
    dna(const string& str) {
    	if (str.length() == 0 ){
    		front = nullptr;
    		back = nullptr;
    		Size = 0;
    	} else {
	    	Size = 0;
	        Nucleotide *curr = new Nucleotide;
	        Size++;
	        Nucleotide *prev = nullptr;
	        curr->value = str.at(0);
	        front = curr;
	        curr->prev = nullptr;
	        curr->next = nullptr;
	        for (size_t i = 1; i < str.length(); i++) {
	        	prev = curr;
	        	curr = new Nucleotide;
	        	Size++;
	        	curr->value = str.at(i);
	        	prev->next = curr;
	        	curr->prev = prev;
	        }
	        curr->next = nullptr;
	        back = curr;
    	}
    }
    
    
    //
    // copy constructor:
    //
    // Called automatically by C++ to create a dna object that contains a copy
    // of an existing dna object.
    // Performance requirement: O(n)
    //
    // creates a copy of the string using the second constructor.
    dna(const dna &other) : dna(other.toString())
    {
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by
    // the dna object.
    // Performance requirement: O(n)
    //
    // calls on the clear function which will free all the allocated nodes
    virtual ~dna() {
        clear();
    }
    
    //
    // clear:
    //
    // Frees all memory in the chain of nucleotides in the dna obeject.  This
    // function should also set front, back, and Size, appropriately.
    // Performance requirement: O(n)
    //
    //loops through the linked list and deletes the notes
    void clear() {
    	Nucleotide *curr = front;
    	Nucleotide *temp = nullptr;
		while(curr != nullptr)
		{
			temp = curr->next;
			delete curr;
			Size--;
			curr = temp;
		}
		front = nullptr;
		back = nullptr;
    }
    
    //
    // operator=
    //
    // Called when you assign one dna object into another, i.e. this = other;
    // Performance requirement: O(n)
    //
    //  copies the linked list on to the other. majority of the code is the
    //  same as the second constructor but i found no way to use the second
    //  constructor to make it shorter.
    dna& operator=(const dna& other) {
    	clear();
    	if (other.front == nullptr && other.back == nullptr) {
    		front = nullptr;
    		back = nullptr;
    		Size = 0;
    		return *this;
    	}
		if (this == & other) {
               return *this;
        }
        clear();
        Size = other.size();
        front = nullptr;
        back = nullptr;
        Size = 0;
        string str = other.toString();
        Nucleotide *curr = new Nucleotide;
        Size++;
        Nucleotide *prev = nullptr;
        curr->value = str.at(0);
        front = curr;
        curr->prev = nullptr;
        curr->next = nullptr;
        for (size_t i = 1; i < str.length(); i++) {
        	prev = curr;
        	curr = new Nucleotide;
        	Size++;
        	curr->value = str.at(i);
        	prev->next = curr;
        	curr->prev = prev;
        }
        curr->next = nullptr;
        back = curr;
        return *this;
    }
    
    //
    // size:
    //
    // Returns the # of Nucleotides currently in the dna strand.
    // Performance requirement: O(1)
    //
    // returns the size
    int size() const {
        return Size;  // TO DO: update this.
    }
    
    //
    // at(i):
    //
    // Returns a reference to the ith Nucleotide's value, which allows
    // you to read (access) or write (modify) this value.  If i is out of
    // bounds, an exception is thrown.
    // Performance requirement: O(n)
    //
    
    //  returns the value and can be used as getter and setter.
    char& at(int i) {
    	if (i < 0 || i >= Size) {
    		throw out_of_range("DNA.H: " + to_string(i) +
        					  " out of bounds");
    	}
        Nucleotide *F = front;
        int n = 0;
    	while (F != nullptr && i != n) {
    		F = F->next;
    		n++;
    	}
    	return F->value;
    }
    
    //
    // toString:
    //
    // Returns a string spelling out the contents of the dna sequence.
    // Performance requirement: O(n)
    //
    //  converts the linked list back to string and returns it.
    string toString() const {
        if (Size < 0) {
        	return "";
        }
        Nucleotide *F = front;
        string S = "";
        while (F != nullptr) {
        	S = S + F->value;
        	F = F->next;
        }
        return S;  // TO DO: update this.
    }
    
    //
    // operator==
    //
    // This operator determines how you define equality between two operators.
    // In this function, you should compare other and this.  The two objects
    // should be considered equal if they have the same sequence of values and
    // in the same order.
    // Performance requirement: O(n)
    //
    // checks weather two dna objects are the same.
    bool operator==(const dna& other) const {
        if (Size != other.size()) {
        	return false;
        }
        Nucleotide *A = front;
        Nucleotide *B = other.front;
        
        for (int i = 0; i < Size; i++) {
        	if (A->value != B->value) {
        		return false;
        	}
        	A = A->next;
        	B = B->next;
        }
        
        return true;
    }
    
    //
    // splice:
    //
    // Removes the first copy of the sequence in target that appears in the
    // dna sequence of current object.  This requires the linked structure to
    // be properly re-wired after removal.
    // Performance requirement: this function doesn't have a set Big O target,
    // but should not time out on test cases and be reasonable.
    //
    //  has 3 cases. front middle and back. if its front delete the given
    //  target and move the front. if its middle then just rewire the linked list.
    //  lastly if its back then delete the back and update the backpointer.
    bool splice(dna target) {
        Nucleotide *curr = findFirst(target);
        if(curr == nullptr) { // if find first returns null
        	return false;
        }
        
        Nucleotide *NCheck = curr;
        for (int i = 0; i < target.Size; i++) {
        	// used for the condions of front middle and back to check if its last.
        	NCheck = NCheck->next;
        }
        if (curr->prev == nullptr) {
        	Nucleotide *next = nullptr;
        	for (int i = 0; i < target.Size; i++) {
        		next = curr->next;
        		delete curr;
        		Size--;
        		curr = next;
        	}
        	front = curr;
        	curr->prev = nullptr;
        } else if (NCheck == nullptr) {
        	Nucleotide *prev = curr->prev;
        	prev->next = nullptr;
        	back = prev;
        	Nucleotide *next = nullptr;
        	for (int i = 0; i < target.Size; i++) {
        		next = curr->next;
        		delete curr;
        		Size--;
        		curr = next;
        	}
        } else {
        	Nucleotide *prev = curr->prev;
        	Nucleotide *next = nullptr;
        	for (int i = 0; i < target.Size; i++) {
        		next = curr->next;
        		delete curr;
        		Size--;
        		curr = next;
        	}
        	prev->next = curr;
        	curr->prev = prev;
        }
        return true;
    }
    
    //
    // isLinked()
    //
    // Checks if a strand is linked correctly.  This is provided for you.
    // You should use it to test your linked structure often.
    // Performance requirement: O(n)
    //
    bool isLinked() {
        Nucleotide* start = front;
        // If we're at the start of a strand,
        // we should not have a previous pointer.
        if (start != nullptr && start->prev != nullptr) {
            return false;
        }
        // Walk the list, ensuring at each point that the next/prev pointers
        // are consistent with one another.
        for (Nucleotide* curr = start; curr != nullptr; curr = curr->next) {
            if (curr->next != nullptr && curr->next->prev != curr) return false;
            if (curr->prev != nullptr && curr->prev->next != curr) return false;
        }
        return true;
    }
};
