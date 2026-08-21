class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;

        for(int& ast: asteroids){
            while(!result.empty() && ast < 0 && result.back() > 0){
                int diff = ast + result.back();
                if(diff < 0){
                    result.pop_back();
                }else if(diff > 0){
                    ast = 0;
                }else{
                    ast = 0;
                    result.pop_back();
                }
            }
            if(ast != 0){
                result.push_back(ast);
            }
        }

        return result;
    }
};