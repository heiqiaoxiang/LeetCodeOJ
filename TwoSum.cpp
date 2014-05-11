class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> mapping;//hash talbe
        vector<int> result;
        for(int i = 0; i < numbers.size(); i ++)
        {
            mapping[numbers[i]] = i;//hash,store every number's index-1
        }
        for(int i = 0; i < numbers.size(); i ++)
        {
            const int gap = target - numbers[i];
            //  cout<<gap<<endl;
            if(mapping.find(gap) != mapping.end())
            {
                if(i == mapping[gap]) continue;
                result.push_back(i + 1);
                result.push_back(mapping[gap] + 1);
                // cout<<"heihei";
                break;
            }
        }
        return result;
    }
};