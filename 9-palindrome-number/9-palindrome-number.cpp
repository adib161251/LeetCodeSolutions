class Solution {
public:
    bool isPalindrome(int x) {
        int num = x;
        int rev = 0;
        int digit;
        do{
            digit = num % 10;
            if (rev > INT_MAX/10 || rev == INT_MAX / 10 ) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 )) return 0;
            rev = (rev * 10)+digit;
            num = num / 10;
        }while(num != 0);
        
        if(rev < 0) rev *=-1;
        
        cout<<rev<<endl;
        if(x == rev)
        {
            return true;
        }else{
            return false;
        }
        
    }
};