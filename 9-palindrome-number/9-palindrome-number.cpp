class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)){
          return false;
      }
        int revernumber = 0;
          while  (x > revernumber){
              revernumber = revernumber * 10 + x  % 10;
              x = x / 10;
          }
        return x == revernumber || x == revernumber / 10;
    }
};