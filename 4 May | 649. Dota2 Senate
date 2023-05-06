class Solution {
public:
    void ban(string senate, vector<bool>&banned, char toBan, int startAt){
        while(true){
            if(senate[startAt] == toBan && !banned[startAt]){
                banned[startAt] = true;
                break;
            }
            startAt = (startAt + 1) % senate.size();
        }
    }

    string predictPartyVictory(string senate) {
        int n = senate.size();
        vector<bool> banned(n,false);
        int rCount = 0, dCount = 0;
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R'){
               rCount++;
            }
            else{
               dCount++;
            }
        }
        int i = 0;
        while(rCount > 0 && dCount > 0){
           
            if(!banned[i]){
                if(senate[i] == 'R'){
                    ban(senate, banned, 'D', (i+1) % senate.size());
                    dCount--;
                }
                else{
                    ban(senate, banned, 'R', (i+1) % senate.size());
                    rCount--;
                }
            }
            i = (i+1) % senate.size();
        }
        return rCount == 0 ? "Dire" : "Radiant";
    }
};
