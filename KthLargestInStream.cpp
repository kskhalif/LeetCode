#include <vector>
#include <queue>

class KthLargest 
{
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    int K;
public:
    KthLargest(int k, std::vector<int>& nums) 
    {
        K = k;
        for (int i = 0; i < nums.size(); ++i)
        {
            min_heap.push(nums[i]);
            if (min_heap.size() > K) { min_heap.pop(); }
        }
    }
    int add(int val) 
    {
        min_heap.push(val);
        if (min_heap.size() > K) { min_heap.pop(); }
        return min_heap.top();
    }
};
/*
 * KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */