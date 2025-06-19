class Solution {
public:
//BF-1: For each element find another element in the array that sums to target
//use two for loops starting from i=0; j=i+1
// O(n*n) time 

//Approach-2: use a hash table
// create an unordered_map of <element,index> ht
// traverse through the array
// for each element check if the value ()= target-element) exist in the hashtable or not
// if found then return both the indexes otherwise 
// insert the element,index pair into the ht
// O(n) time 
// O(n) space
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.empty()){
            return result;
        }
        unordered_map<int,int>elemIndexMap;
        elemIndexMap.insert({nums[0],0});
        for(int i=1; i<nums.size(); ++i){
            int secElem = target - nums[i];
            auto it = elemIndexMap.find(secElem);
            if(it != elemIndexMap.end() ){
                //found the second element
                int index= it->second;
                result.push_back(index);
                result.push_back(i);
                return result;
            } else{
                elemIndexMap.insert({nums[i],i});
            }
        }
        return result;
    }
};
