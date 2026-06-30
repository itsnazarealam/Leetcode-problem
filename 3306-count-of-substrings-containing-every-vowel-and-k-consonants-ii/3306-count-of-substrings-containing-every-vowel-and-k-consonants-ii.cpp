class Solution {
public:
    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
    }
    long long countOfSubstrings(string word, int k) {
        
        int n = word.length();

        unordered_map<char, int> mp;
        vector<int> nextCons(n);
        int lastInd = n;
        
        for(int i=n-1; i>=0; i--){
            nextCons[i] = lastInd;
            if(!isVowel(word[i])){
                lastInd = i;
            }
        }

        int cons=0;
        long long count=0;
        int i=0, j=0;
        while(j<n){
            char ch = word[j];
            if(isVowel(ch)){
                mp[ch]++;
            }
            else{
                cons++;
            }
            while(cons > k){
                if(isVowel(word[i])){
                    mp[word[i]]--;
                    if(mp[word[i]]==0)
                        mp.erase(word[i]);
                }else{
                    cons--;
                }
                i++;
            }
            while(i<n && mp.size()==5 && cons==k){
                int idx = nextCons[j];
                count += idx - j;
                char ch = word[i];
                if(isVowel(word[i])){
                    mp[word[i]]--;
                    if(mp[word[i]]==0)
                        mp.erase(word[i]);
                }else{
                    cons--;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};