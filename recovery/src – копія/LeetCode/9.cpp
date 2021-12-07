class Solution {class Solution {
public:
    bool isPalindrome(int x) {
        int start=x;
        long long y=0;
        if (x<0) return false; else{
            while(x>0){
                y=y*10+x%10;
                x=x/10;
            }
        }
        if (y==start) return true;
        else return false;
    }
};