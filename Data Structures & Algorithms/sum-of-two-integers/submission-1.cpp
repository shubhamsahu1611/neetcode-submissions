class Solution {
   public:
    int getSum(int a, int b) {
        return a+b;
        int sum = 0;
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int b1 = (a & 1);
            int b2 = (b & 1);
            a = a >> 1;
            b = b >> 1;
            int s = (carry + b1 + b2);
            carry = (s / 2);
            if (s % 2 == 1) {
                sum |= (1 << i);
            }
        }
        return sum;
    }
};
