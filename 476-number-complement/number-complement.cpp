// Solved by Tarun

class Solution {
public:
    int findComplement(int num) {

        int complement_num = 0;
        int power = 1;
        
        for(int i = 0; num > 0; i++){
            
            int bit = 1 - num%2;
            complement_num = complement_num + bit * power;
            num = num/2;
            power = power << 1; // multiply by 2
        }

        return complement_num;
    }
};