/* 347. Top K Frequent Elements
 * Link: https://leetcode.com/problems/top-k-frequent-elements/description/
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // i feel like the most efficient method would be to 
        // create an unordered map with pair
            // first is the number in list
            // seconed is the frequency
        
        // after that, then add the inverse of that pair to a binary heap priority queue
        // pop the first k elements from the priority queue

        std::priority_queue<std::pair<int, int>> pq;
        std::unordered_map<int, int> map;
        std::vector<int> answer;

        // create unordered map
        for (int i = 0; i < nums.size(); ++i)
        {
            map[nums.at(i)]++;
        }

        // push to priority queue
        for (const auto& _pair : map)
        {
            pq.push(std::make_pair(_pair.second, _pair.first));
        } // can use structured bindings instead to iterate through the unordered map? 
        // yes! it allows you to separate the key and value: https://www.geeksforgeeks.org/structured-binding-c/

        // pop k times from priority queue
        for (int i = 0; i < k; ++i)
        {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;

    }
};
