//solved by Tarun

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool alter = true;

        while(n>0){
            int lastBit = (n & 1);
            int secondLastBit = ((n >> 1) & 1);

            if(lastBit == secondLastBit){
                return false;
            }
            n>>=1;
            
        }

        return alter;
    }
};