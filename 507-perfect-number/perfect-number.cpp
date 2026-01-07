// Solved by Tarun

class Solution {
public:
    bool checkPerfectNumber(int num) {
        

        if(num == 1){
            return false;
        }

        int sum = 1;
        for (int i = 2; i*i < num; i++){
            
            if(num%i == 0){
                sum = sum + i;

                int paired = num/i;
                if (paired != i){
                    sum = sum + paired;
                }
            }
        }

        return sum == num;
    }
};