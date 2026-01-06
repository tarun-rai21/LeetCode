// solved by Tarun

class Solution {
public:
    int addDigits(int num) {
        
        int rem, sum = 0;    

        if(num<=9){
            return num;
        }

        else{
            while(num != 0){
                sum = (num%10) + sum;
                num = num/10;
            }
            return addDigits(sum);
        }
    }
};