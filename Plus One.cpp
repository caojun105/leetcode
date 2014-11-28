/* problem Demonstration***********
Plus One Total Accepted: 27298 Total Submissions: 87794 My Submissions Question Solution 
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Show Tags
Have you met this question in a real interview? Yes  No
Discuss
*/


class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        if(digits.empty())
        {
            return res;
        }
        reverse(digits.begin(),digits.end());
        vector<int>::iterator iter=digits.begin();
        int jinwei=1;
        while(iter!=digits.end())
        {
            res.push_back((*iter+jinwei)%10);
            jinwei=(*iter+jinwei)/10;
            iter++;
        }
        if(jinwei==1)
        {
            res.push_back(1);
        }
        reverse(res.begin(),res.end());

        return res;
    }
};
