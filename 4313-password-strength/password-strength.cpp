class Solution {
public:

    string removeDuplicates(string s) {
        unordered_set<char> seen;
        string result;

        for (char ch : s) {
            if (seen.find(ch) == seen.end()) {
                result += ch;
                seen.insert(ch);
            }
        }

    return result;
    }

    int passwordStrength(string password) {
        
        //remove duplicates from the string
        string result = removeDuplicates(password);

        int strength = 0;
        int n = result.size();

        for(int i=0; i<n; i++){
            char ch = result[i];

            if(ch >= 'a' && ch <= 'z') strength += 1;
            else if(ch >= 'A' && ch <= 'Z') strength += 2;
            else if(ch >= '0' && ch <= '9') strength += 3;
            else if(ch == '!' || ch == '@' || ch == '#' || ch == '$') strength += 5;
        }

        return strength;
    }
};