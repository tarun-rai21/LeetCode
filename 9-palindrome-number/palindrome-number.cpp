// solved by Tarun

class Solution {
public:
    bool isPalindrome(int x) {
       if(x<0){
        return false;
       }
       
       int num = x;
       long long new_num = 0, remainder = 0;
       while(num!=0){
           remainder = num%10;
           new_num = new_num*10 + remainder;
           num = num/10;
       }
       if(new_num == x){
           return true;
       }
       else{
           return false;
       }
    return{};
    }
};