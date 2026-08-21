class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> stack;

        int sum = 0;

        for(string& ch: operations){
            if(ch == "+"){
                int top= stack.back(); stack.pop_back();
                int newTop = stack.back() + top;
                stack.push_back(top);
                stack.push_back(newTop);
            }else if(ch == "C"){
                stack.pop_back();
            }else if(ch == "D"){    
                stack.push_back(2*stack.back());
            }else{
                stack.push_back(stoi(ch));
            }
        }

        return accumulate(stack.begin(), stack.end(), 0);
    }

};