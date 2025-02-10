//Brute Force Approach O(n^2)
class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                s[i] = '#';
                int left = INT_MAX, right = INT_MAX;
                for(int j = i + 1; j < n; j++){
                    if(s[j] >= 97 && s[j] <= 122){
                        right = j;
                        break;
                    }
                }
                for(int j = i-1; j >= 0; j--){
                    if(s[j] >= 97 && s[j] <= 122){
                        left = j;
                        break;
                    }
                }
                int mini = min(left, right);
                if(mini == INT_MAX) continue;
                s[mini] = '#';
            }
        }
        string res = "";
        for(int i = 0; i < n; i++){
            if(s[i] != '#'){
                res += s[i];
            }
        }
        return res;
    }
};

//Optimal Approach O(n)
class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(isdigit(s[i])){
                if(st.empty() == true) continue;
                s[st.top()] = '*';
                s[i] = '*';
                st.pop();
            }else{
                st.push(i);
            }
        }
        string res = "";
        for(int i = 0; i < n; i++){
            if(s[i] != '*'){
                res += s[i];
            }
        }
        return res;
    }
};
