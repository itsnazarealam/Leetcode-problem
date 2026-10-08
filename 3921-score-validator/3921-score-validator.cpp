class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        
        int score=0, count=0;
        for(auto& s : events){
            if(count<10){
                if(s == "W"){
                    count++;
                }
                else if(s == "WD" || s == "NB"){
                    score = score + 1;
                }
                else{
                    score += stoi(s);
                }
            }
        }
        return {score, count};
    }
};