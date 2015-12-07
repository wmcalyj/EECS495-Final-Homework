// A Ropes is a binary tree, the element of the binary tree is Rope
// A Rope contains:
//    -- data
//    -- left
//    -- right
//    -- weight

// For a leaf, data will store the actual string and left, right will be nulptr. Weight will be the length of the string stored.
// For a non-leaf, data will be empty because no string will be stored. left and right will be used to point to the 
// left child and right child. weight will be the sum of the length of the string in the left subtree.

#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <queue>



namespace proj
{
	class rope{
	public:
		using shared = std::shared_ptr<rope>;

		// Default constructor
		rope();
		// Constructor for leaf
		rope(std::string data);
		// Constructor for Internal rope
		rope(rope&, rope&);

		// Basic interface similar with string
		// Return the length of the rope
		size_t length();
		// Return the string type 
		std::string toString() const;
		// return the character at index 
		char& index(size_t); 
		// [] operator for index access
		char& operator[](size_t);

		bool equal(const rope&);
		// Core Interface as Rope
		// deep copy a rope
		rope copy();
		// concat a rope at last
		rope concat(rope&);
		// concat a string at last;
		rope concat(std::string);
		// split rope into two ropes
		std::vector<rope> split(size_t);
		// insert a string at index
		rope insert(size_t, std::string);
		// insert a rope at index
		rope insert(size_t, rope&);
		// remove string between indexes
		rope remove(size_t, size_t);
		// remove string between indexes
		// rope remove(size_t);
	
		// return the sub string between indexes
		rope substr(size_t, size_t);
		// replace rope between indexes with string 
		rope replace(size_t, size_t, std::string);
		// replace rope between indexes with rope
		rope replace(size_t, size_t, rope&);
		// ----delete this function before submit, helper
		void report();

		size_t getWeight();

	private:
		// length of string in hope_node
		size_t weight;
		// height of hope
		size_t height;
		std::string data;
		shared left;
		shared right;
		// rotate left 
		rope rotateL();
		// rotate right
		rope rotateR();
		// rebalance the rope
		rope rough_balance();
		void updateWeight();
		int traversalLength(rope*);
	};



} // namespace proj
