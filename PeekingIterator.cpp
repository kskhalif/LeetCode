#include <vector>

class Iterator 
{
private:
    struct Data;
    Data* data;
public:
    Iterator(const std::vector<int>& nums);
    Iterator(const Iterator& iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};
 
class PeekingIterator : public Iterator 
{
private:
    int curr;
public:    
	PeekingIterator(const std::vector<int>& nums) : Iterator(nums) 
    {
        if (Iterator::hasNext()) { curr = Iterator::next(); }
        else { curr = -1; }  
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() 
    {
        return curr;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() 
    {
        int temp = curr;
        if (Iterator::hasNext()) { curr = Iterator::next(); }
        else { curr = -1; }
        return temp;
	}
	
	bool hasNext() const 
    {
        return (curr != -1);
	}
};