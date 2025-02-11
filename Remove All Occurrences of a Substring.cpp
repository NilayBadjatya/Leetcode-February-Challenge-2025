// O(n^2) Approach
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = part.size();
        for(int i = 0; i < s.size(); i++){
            if(s[i] == part[0]){
                if(s.substr(i, n) == part){
                    s.erase(i, n);
                    i = -1;
                }
            }
        }
        return s;
    }
};
