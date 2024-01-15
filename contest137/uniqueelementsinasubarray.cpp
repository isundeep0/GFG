#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int getFrequency(vector<int>& v){
        set<int> st;
        for (int i : v){
            st.insert(i);
        }
        return st.size();
    }
  
  
    int candyShop(int n, vector<int> &candies) {
        // code here
        vector<int> freq(1001, 0);
        int uniqueCandies = getFrequency(candies);
        
        int sum = 0, ans = INT_MAX;
        
        int start = 0, end = 0, currUnique = 0;
        
        while (start <= end && end < n){
            int candie = candies[end];
            freq[candie]++;
            sum += candie;
            
            if (freq[candie] == 1){
                ++currUnique;
            }
            
            while (currUnique == uniqueCandies){
                ans = min(ans, sum);
                candie = candies[start];
                --freq[candie];
                sum -= candie;
                if (freq[candie] == 0){
                    --currUnique;
                }
                ++start;
            }
            
            ++end;
            
        }
        
        return ans;
        
    }
};