You have an initial power of power, an initial score of 0, and a bag of tokens where tokens[i] is the value of the ith token (0-indexed).

Your goal is to maximize your total score by potentially playing each token in one of two ways:

If your current power is at least tokens[i], you may play the ith token face up, losing tokens[i] power and gaining 1 score.
If your current score is at least 1, you may play the ith token face down, gaining tokens[i] power and losing 1 score.
Each token may be played at most once and in any order. You do not have to play all the tokens.

Return the largest possible score you can achieve after playing any number of tokens.


code 

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j,score=0,res=0;
        j=tokens.size()-1;
        while(i<=j)
        {
            if(power>=tokens[i])
            {
                score++;
                power-=tokens[i];
                i++;
            }
            else if(score>0)
            {
                score--;
                power+=tokens[j];
                j--;
            }
            else
            {
                break;
            }
            res=max(res,score);
        }
        return res;
    }
};
    


