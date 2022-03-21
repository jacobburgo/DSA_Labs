/*
File:			DList.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Created:		12.27.2020
Last Modified:	02.26.2021
Purpose:		A doubly-linked list (similar to std::list)
Notes:			Property of Full Sail University
*/

//Header protection
#pragma once

/***********/
/* Defines */
/***********/

/*
How to use:

	When working on a lab, turn that lab's #define from 0 to 1

		Example:	#define LAB_1	1

	When working on an individual unit test, turn that #define from 0 to 1

		Example:	#define DYNARRAY_DEFAULT_CTOR	1

NOTE: If the unit test is not on, that code will not be compiled!
*/

// Master toggle
#define LAB_3	0

// Individual unit test toggles
#define LIST_CTOR						0
#define LIST_NODE_CTOR_DEFAULT			0
#define LIST_NODE_CTOR					0
#define LIST_ADDHEAD_EMPTY				0
#define LIST_ADDHEAD					0
#define LIST_ADDTAIL_EMPTY				0
#define LIST_ADDTAIL					0
#define LIST_CLEAR						0
#define LIST_DTOR						0
#define LIST_ITER_BEGIN					0
#define LIST_ITER_END					0
#define LIST_ITER_INCREMENT_PRE			0
#define LIST_ITER_INCREMENT_POST		0
#define LIST_ITER_DECREMENT_PRE			0
#define LIST_ITER_DECREMENT_POST		0
#define LIST_INSERT_EMPTY				0
#define LIST_INSERT_HEAD				0
#define LIST_INSERT						0
#define LIST_ERASE_EMPTY				0
#define LIST_ERASE_HEAD					0
#define LIST_ERASE_TAIL					0
#define LIST_ERASE						0
#define LIST_COPY_CTOR_INT				0
#define LIST_COPY_CTOR_USER_DEFINED		0
#define LIST_ASSIGNMENT_OP_INT			0
#define LIST_ASSIGNMENT_OP_USER_DEFINED	0

#if LAB_3

template<typename T>
class DList {
	friend class DSA_TestSuite_Lab3;	// Giving access to test code

	struct Node {
		T data;
		Node* next, * prev;
		Node(const T& _data, Node* _next = nullptr, Node* _prev = nullptr) {
			// TODO: Implement this method
			data = _data;
			next = _next;
			prev = _prev;
		}
		Node() {
			next = nullptr;
			prev = nullptr;
		}
	};

public:

	class Iterator {
	public:

		Node* mCurr;

		// Pre-fix increment operator
		//
		// Return: Invoking object with curr pointing to next node
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
							I
							R
		*/
		Iterator& operator++() {
			// TODO: Implement this method
			mCurr = mCurr->next;
			this->mCurr = mCurr;
			return *this;
		}

		// Post-fix increment operator
		//
		// In:	(unused)		Post-fix operators take in an unused int, so that the compiler can differentiate
		//
		// Return:	An iterator that has its curr pointing to the "old" curr
		// NOTE:	Will need a temporary iterator
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
					  R		I

		*/
		Iterator operator++(int) {
			// TODO: Implement this method
			Iterator* tempIter = new Iterator;
			tempIter->mCurr = mCurr;
			mCurr = mCurr->next;
			return *tempIter;
		}

		// Pre-fix decrement operator
		//
		// Return: Invoking object with curr pointing to previous node
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
				I
				R
		*/
		Iterator& operator--() {
			// TODO: Implement this method
			mCurr = mCurr->prev;
			this->mCurr = mCurr;
			return *this;
		}

		// Post-fix decrement operator
		//
		// In:	(unused)		Post-fix operators take in an unused int, so that the compiler can differentiate
		//
		// Return:	An iterator that has its curr pointing to the "old" curr
		// NOTE:	Will need a temporary iterator
		//
		// Example:
		//		I - Iterator's curr
		//		R - Return
		/*
			Before

			0<-[4]<->[5]<->[6]->0
					  I

			After

			0<-[4]<->[5]<->[6]->0
				I	  R

		*/
		Iterator operator--(int) {
			// TODO: Implement this method
			mCurr = mCurr->prev;
			return this;
		}

		// Dereference operator
		//
		// Return: The data the curr is pointing to
		T& operator*() {
			// TODO: Implement this method
			return mCurr.data;
		}

		// Not-equal operator (used for testing)
		//
		// In:	_iter		The iterator to compare against
		//
		// Return: True, if the iterators are not pointing to the same node
		bool operator != (const Iterator& _iter) const {
			return mCurr != _iter.mCurr;
		}
	};

	// Data members
	Node* mHead;		// The head (first node) of the list
	Node* mTail;		// The tail (last node) of the list
	size_t mSize;		// Current number of nodes being stored

public:

	// Default constructor
	//		Creates a new empty linked list
	DList() {
		// TODO: Implement this method
		mHead = nullptr;
		mTail = mHead;
	}

	// Destructor
	//		Cleans up all dynamically allocated memory
	~DList() {
		// TODO: Implement this method
		for (Node* walk = mHead; walk != nullptr; walk = mHead) {
			mHead = mHead->next;
			delete walk;
		}
	}

	// Copy constructor
	//		Used to initialize one object to another
	//
	// In:	_copy			The object to copy from
	DList(const DList& _copy) {
		// TODO: Implement this method
		for (Node* walk = _copy.mHead; walk != nullptr; walk = walk->next) {
			AddHead(walk->data);
		}
	}

	// Assignment operator
	//		Used to assign one object to another
	// In:	_asign			The object to assign from
	//
	// Return: The invoking object (by reference)
	//		This allows us to daisy-chain
	DList& operator=(const DList& _assign) {
		// TODO: Implement this method
		for (Node* walk = _assign.mHead; walk != nullptr; walk = walk->next) {
			AddHead(walk->data);
		}
		return *this;
	}

private:

	// Optional recursive helper method for use with Rule of 3
//
// In:	_curr		The current Node to copy
	void RecursiveCopy(const Node* _curr) {
		// TODO (optional): Implement this method
	}

public:

	// Add a piece of data to the front of the list
//
// In:	_data			The object to add to the list
	void AddHead(const T& _data) {
		// TODO: Implement this method
		Node* tempNode = new Node(_data);
		if (mHead == nullptr) {
			mHead = tempNode;
			mTail = tempNode;
		}
		else {
			tempNode->next = mHead;
			mHead = tempNode;
		}
		mSize += 1;
	}

	// Add a piece of data to the end of the list
//
// In:	_data			The object to add to the list
	void AddTail(const T& _data) {
		// TODO: Implement this method
		Node* tempNode = new Node(_data);
		if (mHead == nullptr) {
			mTail = tempNode;
			mHead = mTail;
		}
		else {
			tempNode->next = mTail;
			mTail = tempNode;
		}
		mSize += 1;
	}

	// Clear the list of all dynamic memory
	//			Resets the list to its default state
	void Clear() {
		// TODO: Implement this method
		// JACOB'S COMMENT: I tried this one before I watched the lecture since this and the destructor gave me so many problems last time.
		Node* walk = mHead;
		while (walk != nullptr) {
			if (walk->next == nullptr) break;
			walk = walk->next;
			delete walk->prev;
		}
		delete walk;
		mSize = 0;
		mTail = nullptr;
		mHead = nullptr;
	}

private:

	// Optional recursive helper method for use with Clear
	//
	// In:	_curr		The current Node to clear
	void RecursiveClear(const Node* _curr) {
		// TODO (Optional): Implement this method
		// I should have re-read the lab before I started hacking away at it.
		// I forgot about this one.
	}

public:

	// Insert a piece of data *before* the passed-in iterator
	//
	// In:	_iter		The iterator
	//		_data		The value to add
	//
	// Example:
	/*
		Before

			0<-[4]<->[5]<->[6]->0
					  I

		After

			0<-[4]<->[9]<->[5]<->[6]->0
					  I
	*/
	// Return:	The iterator
	// SPECIAL CASE:	Inserting at head or empty list
	// NOTE:	The iterator should now be pointing to the new node created
	Iterator Insert(Iterator& _iter, const T& _data) {
		if (mHead == nullptr) {
			Node* tempNode = new Node(_data);
			_iter.mCurr = tempNode;
			mHead = _iter.mCurr;
			mTail = _iter.mCurr;
			mSize += 1;
		}
		else if (_iter.mCurr == mHead) {
			this->AddHead(_data);
			_iter.mCurr = mHead;
		}
		else {
			Node* tempNode = new Node(_data, _iter.mCurr->next, _iter.mCurr->prev);
			_iter.mCurr = tempNode;
			mSize += 1;
		}
		return _iter;
	}

	// Erase a Node from the list
	//
	// In:	_iter		The iterator
	//
	// Example
	/*

		Before

			0<-[4]<->[5]<->[6]->0
					  I

		After

			0<-[4]<->[6]->0
					  I
	*/
	// Return:	The iterator
	// SPECIAL CASE:	Erasing head or tail
	// NOTE:	The iterator should now be pointing at the node after the one erased
	Iterator Erase(Iterator& _iter) {
		// TODO: Implement this method
		if (_iter.mCurr == mHead && _iter.mCurr == mTail) {
			return _iter;
		}
		else if (_iter.mCurr == mHead) {
			mHead = mHead->next;
			delete mHead->prev;
			mHead->prev = nullptr;
			_iter.mCurr = mHead;
			mSize--;
		}
		else if (_iter.mCurr == mTail) {
			mTail = mTail->prev;
			delete mTail->next;
			mTail->next = nullptr;
			_iter.mCurr = mTail->next;;
			mSize--;
		}
		else {
			Node* prevNode = _iter.mCurr->prev;
			Node* nextNode = _iter.mCurr->next;
			Node* delNode = _iter.mCurr;
			prevNode->next = nextNode;
			nextNode->prev = prevNode;
			_iter.mCurr = nextNode;
			delete delNode;
			mSize--;
		}
		return _iter;
	}

	// Set an Iterator at the front of the list
	//
	// Return: An iterator that has its curr pointing to the list's head
	Iterator Begin() {
		// TODO: Implement this method
		Iterator* tempIter = new Iterator;
		tempIter->mCurr = mHead;
		return *tempIter;
	}

	// Set an Iterator pointing to the end of the list
	//
	// Return: An iterator that has its curr pointing to a null pointer
	Iterator End() {
		// TODO: Implement this method
		Iterator* tempIter = new Iterator;
		tempIter->mCurr = mTail->next;
		return *tempIter;
	}
};

#endif	// End LAB_3
