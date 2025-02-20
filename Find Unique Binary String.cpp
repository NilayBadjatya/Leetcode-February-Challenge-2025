// Approach 1: O(2 ^ N)
class Solution {
public:

    void solve(string s, int n, unordered_set<string>& a){
        if(s.size() == n){
            a.insert(s);
            return;
        }
        if(s.size() > n){
            return;
        }
        for(auto i = '0'; i <= '1'; i++){
            s += i;
            solve(s, n, a);
            s.pop_back();
        }
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st(nums.begin(), nums.end());
        unordered_set<string> a;
        solve("", n, a);
        for(auto &s : a){
            if(st.count(s) == 0){
                return s;
            }
        }
        return "";
    }
};

// Approach 2 : Same logic as the previous one but does not generate all possible strings of length n
//Worst Case Time Complexity - O(2^N)
class Solution {
public:

    string solve(string s, int n, unordered_set<string>& st){
        if(s.size() == n){
            if(st.count(s) == 0){
                return s;
            }
            return "";
        }
        if(s.size() > n){
            return "";
        }
        for(auto i = '0'; i <= '1'; i++){
            s += i;
            string res = solve(s, n, st);
            if(!res.empty()) return res;
            s.pop_back();
        }
        return "";
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st(nums.begin(), nums.end());
        return solve("", n, st);
    }
};

//Approach 3 - Cantor's diagonal argument, O(N) (OPTIMAL)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string ans = "";
        for(int i = 0; i < n; i++){
            ans += nums[i][i] == '0' ? '1' : '0';
        }
        return ans;
    }
};
