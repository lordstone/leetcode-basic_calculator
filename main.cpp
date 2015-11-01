class Solution {
public:

    int calc(string s, int *ptr){
        if(s.length() == 0 || *ptr >= s.length()) return 0;
        int sum = 0, sign = 1, tmpsum = 0;
        //if(*ptr > 0) return *ptr;
        while((*ptr) < s.length()){
            if(s[(*ptr)] >= '0' && s[(*ptr)] <= '9' ){
                tmpsum *= 10;
                tmpsum += s[(*ptr)] - '0';
            }else if(s[(*ptr)] == '+'){
                sum += sign * tmpsum;
                tmpsum = 0;
                sign = 1;
            }else if(s[(*ptr)] == '-'){
                sum += sign * tmpsum;
                tmpsum = 0;
                sign = -1;
            }else if(s[(*ptr)] == '('){
                (*ptr)++;
                tmpsum = calc(s, ptr);
                //(*ptr)++;
                sum += sign * tmpsum;
                sign = 1;
                tmpsum = 0;
            }else if(s[(*ptr)] == ')'){
                sum += sign * tmpsum;
                return sum;
            }//end if
            (*ptr)++;
        }//end while
        sum += sign * tmpsum;
        return sum;
    }
    
    int calculate(string s) {
        int myptr = 0;
        return calc(s, &myptr);
    }
};
