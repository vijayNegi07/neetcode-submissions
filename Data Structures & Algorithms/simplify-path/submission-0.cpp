class Solution {
public:
    string simplifyPath(string path) {
         vector<string> stack;
        string curr;

        for(char ch : path + "/"){
            if(ch == '/'){
                if(curr == ".."){
                    if(!stack.empty()) stack.pop_back();
                }else if(!curr.empty() && curr != "."){
                    stack.push_back(curr);
                }
                curr.clear();
            }else{
                curr += ch;
            }
        }

        string res = "/";
        for(int i = 0; i < stack.size(); i++){
            if(i > 0) res+='/';
            res += stack[i];
        }


        return res;
    }
};