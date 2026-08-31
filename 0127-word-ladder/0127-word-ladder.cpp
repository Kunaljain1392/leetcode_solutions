class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        

        unordered_map<string,bool> mp;

        for(auto i:wordList) {
            mp[i] = true;
        }

        // if(mp.find(beginWord) == mp.end()) {
        //     mp[beginWord] = true;
        // }

        // if(mp.find(endWord) == mp.end()) {
        //     return 0;
        // }

        queue< pair<string,int> > q;
        q.push({beginWord,1});

        while(!q.empty()) {
            pair<string, int> front = q.front();
            q.pop();
            string s = front.first;
            int currVal = front.second;

            if(front.first == endWord) {
                return front.second;
            }

            for(int i=0;i<s.length();i++) {
                char original = s[i];
                for(char j = 'a';j <= 'z'; j++) {
                    s[i] = j;
                    if(mp.find(s) != mp.end()) {
                        q.push({s,currVal+1});
                        mp.erase(s);
                    }
                }
                s[i] = original;
            }
            
        }

        return 0;


    }
};