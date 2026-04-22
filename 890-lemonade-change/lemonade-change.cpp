class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int bill_5 = 0;
        int bill_10 = 0;

        for(int i=0; i<n; i++){
            
            if(bills[i]==5) bill_5++;
            
            else if(bills[i]==10){                
                if(bill_5==0) return false;
                    bill_5--;
                    bill_10++;
            }

            else{
                if(bill_10>0 && bill_5>0){
                    bill_10--;
                    bill_5--;
                }
                else if(bill_5>2) bill_5 -= 3;
                else return false;
            }
        }
        return true;        
    }
};