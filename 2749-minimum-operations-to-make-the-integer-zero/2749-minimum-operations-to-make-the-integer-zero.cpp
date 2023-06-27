class Solution {
public:
    // logic is we have to make num1 to 0. Suppose we can make it zero in k steps
    // num1-k*num2-[2^i1+2^i2+2^i3.............+2^ik]
    // we have to make this value zero
    // means num1-k*num2 should be equal to [2^i1+2^i2+2^i3.............+2^ik]
    // we will check for all possibility of k
    // any number can be written in this form (summation of powers of 2)
    // like 13 (1110) can be written in that form 2^3+2^2+2^1 means here k is 3=setbits
    // or it can further be written as 2^3+2^2+2^0+2^0 means here k is 4
    // we can also write it as 13*2^0 here k=13 means range of k can be [setbit,number]
    
    int makeTheIntegerZero(int num1, int num2) {
        if(num1<=num2) return -1;
        if(num1==num2) return 0;
        for(int k=0;k<100;k++){
            long long diff=(long long)num1-(long long)k*num2;
            if(diff<0) return -1;
            int setBits=__builtin_popcountll(diff);
            if(k>=setBits && k<=diff) return k;
        }
        return -1;
    }
};