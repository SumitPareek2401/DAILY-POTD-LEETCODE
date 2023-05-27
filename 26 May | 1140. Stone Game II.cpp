class Solution {
public:

    int solve(vector<int> & piles, vector<vector<vector<int>>>&dp, int turn, int i, int m){
        int n = piles.size();
        if(i == n){
            return 0;
        }

        if(dp[turn][i][m] != -1){
            return dp[turn][i][m];
        }

        int res = turn == 1 ? 1000000 : -1;
        int score = 0;

        for(int x = 1; x <= min(2*m, n-i); x++){
            score += piles[i + x - 1];
            if(turn == 0){
                res = max(res, score + solve(piles, dp, 1, i+x, max(m,x)));
            }
            else{
                res = min(res, solve(piles, dp, 0, i+x, max(m,x)));
            }
        }
        return dp[turn][i][m] = res;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>>dp(2, vector<vector<int>>(n+1, vector<int>(n+1, -1)));
        return solve(piles, dp, 0, 0, 1);
    }
};
