//solved by Tarun

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        
        vector<int> answer;
        for(int i =left; i<=right; i++){
            
            int num = i;
            bool self_dividing = true;
            
            while(num>0){
                int rem = num%10;
                num = num/10;
                if(rem==0 || i%rem != 0){
                    self_dividing = false;
                    break;
                }
            }
            if(self_dividing){
                answer.push_back(i);
            }
        }
        return answer;
    }
};