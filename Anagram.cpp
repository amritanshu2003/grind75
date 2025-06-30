# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
/*
Approach-1: using hash table
O(n) time & space 

Take a hash table of char & frequency in the string it has appeared
Go through the first string
check if the char is found in the table then increment its count otherwise insert the char into the table & add the count 1

Traverse the second string 
check if the char is found in the table then decrement the count;
if the count == 0 then remove the char from the hash table
At the end check the size of the hash table if its empty then s is anagram of t

Approach-2: use sorting
sort both the strings and compare
if they are equal then they are anagrams
O(nlogn) time

Q-Are these two strings are of the same length?
*/
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        std::unordered_map<char,int>charFreq;
        for(int i=0; i<s.size();++i){
            if( charFreq.count(s[i])>0){
                charFreq[s[i]]++;
            }else{
                charFreq[s[i]]=1;
            }
        }

        for(int i=0; i<t.size();++i){
            if( charFreq.count(t[i])>0){
                charFreq[t[i]]--;
                if(charFreq[t[i]]==0){
                    charFreq.erase(t[i]);
                }
            }else{
                //char not found
                return false;
            }
        }
        if(charFreq.size()==0){
            return true;
        }
        return false;
    }
};
```
