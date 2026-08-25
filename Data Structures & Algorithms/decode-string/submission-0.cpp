class Solution {
public:
    string decodeString(string s) {
        vector<string> stack;

        for(char& ch: s){
            if(ch != ']'){
                stack.push_back(string(1,ch));
            }else{
                string insideString = "";
                while(!stack.empty() && stack.back() != "["){
                    insideString = stack.back() +  insideString;
                    stack.pop_back();
                }
                stack.pop_back();

                string digit;

                while(!stack.empty() && isdigit(stack.back()[0])){
                    digit = stack.back() + digit;
                    stack.pop_back();
                }

                int num = stoi(digit);
                string finString = "";
                for(int i = 0; i < num; i++){
                    finString += insideString;
                }

                stack.push_back(finString);
            }
        }

        string res = "";
        for(const string& str: stack){
            res += str;
        }

        return res;

    }
};