#include <vector>
#include <deque>

class NestedInteger 
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};
 
class NestedIterator 
{
private:
    std::deque<int> list;
    
    void flatten(const std::vector<NestedInteger>& nestedList)
    {
        for (int i = 0; i < nestedList.size(); ++i)
        {
            if (nestedList[i].isInteger())
            {
                list.push_back(nestedList[i].getInteger());
            }
            else
            {
                flatten(nestedList[i].getList());
            }
        }
    }
public:
    NestedIterator(std::vector<NestedInteger> &nestedList) 
    {
        flatten(nestedList);
    }
    
    int next() 
    {
        int temp = list.front();
        list.pop_front();
        return temp;
    }
    
    bool hasNext() 
    {
        return (list.size());
    }
};