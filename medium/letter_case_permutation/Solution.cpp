class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans ;
        // If the input string s is empty, the function returns an empty vector.
        if(s.size() == 0)
            return ans ;

        // If the input string s has only one character, the function converts the character to lowercase and uppercase and creates two strings from it. The function then returns a vector containing these two strings.
        if(s.size() == 1){
            string a , b ;
            a += (char)tolower(s[0]) ;
            b += (char)toupper(s[0]) ;
            ans.push_back(a) ;
            if(a != b)
                ans.push_back(b) ;
            return ans ;
        }
        // If the input string s has more than one character
        // the function recursively calls itself on the substring s.substr(1, s.size()). 
        // This recursive call generates all possible strings that can be
        vector<string> temp = letterCasePermutation(s.substr(1,s.size())) ;

        string a , b ;
        a += (char)tolower(s[0]) ;
        b += (char)toupper(s[0]) ;
        for(auto e : temp){
            ans.push_back(a+e) ;
            if(a != b)
                ans.push_back(b+e) ;
        }
        return ans ;
    }
};