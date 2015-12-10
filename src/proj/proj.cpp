#include "proj.hpp"

namespace proj
{

	// Constructor
	rope::rope():data(""),weight(0),left(nullptr),right(nullptr),height(0)
	{}
	// Constructor for leaf with data
	rope::rope(std::string data)
	:data(data),weight(data.length()),height(0),left(nullptr),right(nullptr)
	{}
	// Constructor for Internal rope with two children
	rope::rope(rope& l, rope& r)
		:data(""),weight(l.length())
	{
		height = std::max(l.height,r.height) + 1;
		left = std::make_shared<rope>(l);
		right = std::make_shared<rope>(r);
	}
	// Return the length of the rope
	size_t rope::length()
	{
		if(left == nullptr){
			return data.length();
		}
		size_t result = weight;
		rope* raw = right.get();
		while(raw)
		{
			result += raw->weight;
			raw = raw->right.get();
		}
		return result;
	}
	// Return the string type of the rope
	std::string rope::toString() const
	{
		std::string result = "";

		if(left != nullptr)
			result += left->toString();
		if(data != "")
			result += data;
		if(right != nullptr)
			result += right->toString();
		return result;
	}
	// Return the character at index i
	char& rope::index(size_t i)
	{
		if(weight <= i)
			if(right != nullptr)
				return right->index(i - weight);
			else{
				if(i >= data.length())
				{
					throw std::length_error("Out of boundry error.");
				}
				return data[i];
			}
		else{
			if(left != nullptr)
				return left->index(i);
			else{
				if(i >= data.length()){
					throw std::length_error("Out of boundry error.");
				}
				return data[i];
			}
		}
	}
	// Operator overlaoding
	// index access operator []
	char& rope::operator[](size_t i)
	{
		return index(i);
	}
	// check to rope is equal
	bool rope::equal(const rope& r)
	{
		return this->toString().compare(r.toString()) == 0;
	}
	
	// deep copy a rope
	rope rope::copy()
	{	
		if(data == "")
		{
			rope res("");
			res.weight = weight;
			res.height = height;

			if(right == nullptr)
				res.right = nullptr;
			else
				res.right = std::make_shared<rope>(right->copy());

			if(left == nullptr)
				res.left = nullptr;
			else 
				res.left = std::make_shared<rope>(left->copy());

			return res;
		}
		else
		{
			rope* res = new rope(data);
			return *res;
		}
	}
	// concat a rope at last
	rope rope::concat(rope& last)
	{	
		rope res(*this,last);
		return res.rough_balance();
	}
	// concat a string at last;
	rope rope::concat(std::string str)
	{
		rope last(str);
		return this->concat(last);
	}
	
	// Left inclusive and right exclusive
	// Generate a new array of rope
	// split rope into two ropes
	std::vector<rope> rope::split(size_t i)
	{
		if(i > this->length()){
			throw std::length_error("Out of boundry error.");
		}
		std::vector<rope> res;
		std::stack<rope> sta;
		rope root = this->copy();
		// edge case like split as rope length;
		if(i == 0){
			rope empty;
			res.push_back(empty);
			res.push_back(root);
			return res;
		}
		if(i == this->length()){
			res.push_back(root);
			rope empty;
			res.push_back(empty);
			return res;
		}
		rope* cur = &root;

		while(cur->left != nullptr && cur->right != nullptr)
		{	
			// If current rope weight greater i
			// modify its weight
			// cut the right branch and put it in stack
			if(cur->weight > i)
			{	
				cur->weight = i;
				if(cur->right != nullptr)
				{	
					sta.push(*(cur->right));
					cur->right = nullptr;
				}
				cur = cur->left.get();
			}
			// else
			// go find the right branch
			else if(cur->weight <= i)
			{   
				i -= cur->weight;
				cur = cur->right.get();
			}
		}
		//reach leaf 
		if(i < cur->weight)
		{
			std::string rest = cur->data.substr(i);
			cur->data = cur->data.substr(0,i);
			rope temp(rest);
			sta.push(temp);
		}

		res.push_back(root);

		if(sta.size() == 0)
			return res;
		else if(sta.size() == 1)
		{	
			res.push_back(sta.top());
			return res;
		}
		else{
			rope sec = sta.top();
			sta.pop();
			while(!sta.empty()){
				sec = sec.concat(sta.top());
				sta.pop();
			}
			res.push_back(sec);
		}

		return res;
	}
	// insert a string at index
	rope rope::insert(size_t i, std::string str)
	{
		rope mid{str};
		return this->insert(i, mid);
	}
	// insert a rope at index
	rope rope::insert(size_t i, rope& n)
	{
		if(i == 0)
		{
			return n.concat(*this);
		}
		std::vector<rope> spt = this->split(i);
		rope res = spt[0].concat(n).concat(spt[1]);
		return res;
	}

	// remove string between indexes
	rope rope::remove(size_t i, size_t j)
	{
		std::vector<rope> last = this->split(j);
		std::vector<rope> prev = last[0].split(i);
		rope res = prev[0].concat(last[1]);
		return res;
	}

	// return the sub string between indexes
	// left inclusive and right exclusive
	rope rope::substr(size_t i, size_t j)
	{
		if(j > this->length() || j == 0){
			throw std::length_error("Out of boundry error.");
		}
		std::vector<rope> last = this->split(j);
		std::vector<rope> prev = last[0].split(i);
		return prev[1];
	}
	// replace rope between indexes with string 
	rope rope::replace(size_t i, size_t j, std::string str)
	{
		std::vector<rope> last = this->split(j);
		std::vector<rope> prev = last[0].split(i);
		rope mid(str);
		rope res = prev[0].concat(mid).concat(last[1]);
		return res;
	}
	// replace rope between indexes with rope
	rope rope::replace(size_t i, size_t j, rope& n)
	{	
		std::vector<rope> last = this->split(j);
		std::vector<rope> prev = last[0].split(i);
		rope res = prev[0].concat(n).concat(last[1]);
		return res;
	}
	// balance function
	rope rope::rotateL()
	{
		rope res(*right.get());
		right      = res.left;
		height     = std::max(left->height,right->height) + 1;
		res.left   = std::make_shared<rope>(*this);
		res.height = std::max(res.left->height,res.right->height) + 1;
		res.updateWeight();
		return res;
	}

	rope rope::rotateR()
	{
		rope res(*left.get());
		left = res.right;
		height = std::max(left->height,right->height) + 1;
		res.right = std::make_shared<rope>(*this);
		res.height = std::max(res.left->height,res.right->height) + 1;
		res.updateWeight();
		return res;
	}

	rope rope::rough_balance()
	{	
		if(this->left == nullptr && this->right == nullptr)
			return *this;
		if(left != nullptr)
			left = std::make_shared<rope>(left->rough_balance());
		if(right != nullptr)
			right = std::make_shared<rope>(right->rough_balance());
		height = std::max(left->height,right->height) + 1;

		if(left->height > right->height +1 )
			return rotateR();
		else if(right->height > left->height + 1)
			return rotateL();
		else
			this->updateWeight();
		return *this;
	}

	void rope::updateWeight(){
		this->weight = traversalLength(this->left.get());
		traversalLength(this->right.get());
	}
	int rope::traversalLength(rope* n){
		if(n == nullptr){
			return 0;
		}
		if(n->left == nullptr){
			return n->data.length();
		}
		n->weight = traversalLength(n->left.get());
		return n->weight + traversalLength(n->right.get());
	}

	// build a rope from a string
	rope build(std::string str)
	{	
		if(str == "")
		{
			rope res;
			return res;
		}

		int i = 0;
		int size = str.length();
		std::queue<rope> q;

		srand(time(0));

		while(size)
		{	
			if(size > 1){
				int rad = rand()%size + 1;
				rope temp(str.substr(i,rad));
				q.push(temp);
				i += rad;
				size -= rad;			
			}
			else if(size == 1)
			{	
				rope temp(str.substr(i));
				size -= 1;
				q.push(temp);
			}	
		}

		if(q.size() == 1)
			return q.front();
		else{

			rope res = q.front();
			q.pop();

			while(!q.empty()){
				res = res.concat(q.front());
				q.pop();
			}
			return res;
		}
	}
}
