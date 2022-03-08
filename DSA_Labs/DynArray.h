/*
File:			DynArray.h
Author(s):
	Base:		Justin Tackett
				jtackett@fullsail.com
	Student:

Created:		11.21.2020
Last Modified:	02.26.2021
Purpose:		A dynamically-allocated resizeable array (similar to std::vector)
Notes:			Property of Full Sail University
*/

// Header protection
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
#define LAB_1	1

// Individual unit test toggles
#define LAB1_DYNARRAY_DEFAULT_CTOR						1
#define LAB1_DYNARRAY_CONSTRUCTOR_WITH_ARGS				1
#define LAB1_DYNARRAY_BRACKET_OP_READ_ONLY_BUILT_IN		1
#define LAB1_DYNARRAY_BRACKET_OP_WRITE_BUILT_IN			1
#define LAB1_DYNARRAY_SIZE								1
#define LAB1_DYNARRAY_CAPACITY							1
#define LAB1_DYNARRAY_RESERVE_ZERO						1
#define LAB1_DYNARRAY_RESERVE_DOUBLE					1
#define LAB1_DYNARRAY_RESERVE_VALUE						1
#define LAB1_DYNARRAY_RESERVE_SMALLER					1
#define LAB1_DYNARRAY_APPEND_NO_RESIZE					1
#define LAB1_DYNARRAY_APPEND_RESIZE						1
#define LAB1_DYNARRAY_CLEAR								1
#define LAB1_DYNARRAY_DTOR								1
#define LAB1_DYNARRAY_COPY_CTOR_BUILT_IN				1
#define LAB1_DYNARRAY_COPY_CTOR_CLASS					1
#define LAB1_DYNARRAY_ASSIGNMENT_BUILT_IN				1
#define LAB1_DYNARRAY_ASSIGNMENT_CLASS					1

#if LAB_1

// Our implementation of a vector (simplified)
template<typename Type>
class DynArray {
	// Gives access to test code
	friend class DSA_TestSuite_Lab1;

	// Data members
	Type* mArray;			// The dynamic array that will be managed within the class
	size_t mSize;			// The number of elements currently storing valid data
	size_t mCapacity;		// The total number of elements available in the currently allocated array

public:

	// Default constructor
	//		Creates an empty object
	//
	// In:	_startingCap		An initial size to start the array at
	//
	// Note: Do not allocate any memory if the _startingCap is 0
	DynArray(size_t _startingCap = 0) {
		// TODO: Implement this method
		if (_startingCap > 0) {
			mArray = new Type[_startingCap];
			mCapacity = _startingCap;
		}
		else if (_startingCap <= 0) {
			return;
		}
	}

	// Destructor
	//		Cleans up all dynamically allocated memory
	~DynArray() {
		// TODO: Implement this method
		delete[] mArray;
	}

	// Copy constructor
	//		Used to initialize one object to another
	// In:	_da				The object to copy from
	DynArray(const DynArray& _copy) : mArray(nullptr) {
		// TODO: Implement this method
		*this = _copy;
	}

	// Assignment operator
	//		Used to assign one object to another
	// In:	_da				The object to assign from
	//
	// Return: The invoking object (by reference)
	//		This allows us to daisy-chain
	DynArray& operator=(const DynArray& _assign) {
		// TODO: Implement this method
	}

	// Clear
	//		Cleans up all dynamically allocated memory
	//		Sets all data members back to default values
	void Clear() {
		// TODO: Implement this method
		delete[] mArray;
		mArray = nullptr;
		mSize = 0;
		mCapacity = 0;
	}

	// Overloaded [] operator
	//		Used to access an element in the internal array (read-only)
	// In:	_index			The index to access at
	//
	// Return: The item at the specified index (by reference)
	const Type& operator[](int _index) const {
		// TODO: Implement this method
		return mArray[_index];
	}

	// Overloaded [] operator
	//		Used to access an element in the internal array (writeable)
	// In:	_index			The index to access at
	//
	// Return: The item at the specified index (by reference)
	Type& operator[](int _index) {
		// TODO: Implement this method
		return mArray[_index];
	}

	// Get the current number of elements actively being used
	//
	// Return: The current number of elements used
	size_t Size() const {
		// TODO: Implement this method
		return mSize;
	}

	// Get the current capacity of the internal array
	//
	// Return: The capacity of the array
	size_t Capacity() const {
		// TODO: Implement this method
		return mCapacity;
	}

	// Add an item to the end of the array
	//		Should resize the array if needed
	//
	// In:	_data			The item to be added
	void Append(const Type& _data) {
		// TODO: Implement this method
		if (mSize >= mCapacity) {
			Reserve();
		}
		mArray[mSize] = _date;
		mSize += 1;
	}

	// Resizes the internal array, and copies all data over
	// In: _newCapacity		The new capacity of the array
	//		NOTE:	If 0 is passed, the array should double in size
	//				If _newCapacity < mCapacity, do nothing
	//
	//	SPECIAL CASE: If mCapacity is 0, then it should be set to 1
	void Reserve(size_t _newCapacity = 0) {
		// TODO: Implement this method
		if (_newCapacity == 0) {
			if (mCapacity == 0) {
				mCapacity = 1;
				mArray = new Type[mCapacity];
			}
			else {
				mCapacity *= 2;
				Type* newArray = new Type[mCapacity];
				for (size_t i = 0; i < mCapacity; i++)
				{
					newArray[i] = mArray[i];
				}
				delete[] mArray;
				mArray = newArray;
			}
		}
		else {
			if (_newCapacity < mCapacity) {
				return;
			}
			else {
				mCapacity = _newCapacity;
				Type* newArray = new Type[mCapacity];
				for (size_t i = 0; i < mCapacity; i++)
				{
					newArray[i] = mArray[i];
				}
				delete[] mArray;
				mArray = tempArray;
			}
		}
	}
};

#endif	// End LAB_1
