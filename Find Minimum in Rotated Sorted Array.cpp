/*Find Minimum in Rotated Sorted Array Total Accepted: 16381 Total Submissions: 51498 

My Submissions Question Solution 
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Show Tags
*/

class Solution {
public:
    int findMin(vector<int> &num) {
        int retMinVal=1000;
        int begin=0;
        int end=num.size()-1;
        int mid=0;
        
        if(num.size()<2)
            return num[0]; //special case return.
        while(begin<end)
        {
            mid=begin+(end-begin)/2;
            if(num[mid]>num[begin]) //the left part is a sorted array
            {
                retMinVal=num[begin]<retMinVal?num[begin]:retMinVal; //set the Minval as the minium of left part array
                begin=mid+1;
                end=end;
                continue;
            }
            else
            {
                retMinVal=num[mid+1]<retMinVal?num[mid+1]:retMinVal; 
                begin=begin;
                end=mid;
                continue;
            }
        }
        
        retMinVal=num[begin]<retMinVal?num[begin]:retMinVal;
        return retMinVal;
        
    }
};
