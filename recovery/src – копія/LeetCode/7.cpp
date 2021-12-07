class Solution {
public:
    int reverse(int x) {
            long long new_number = 0;
    while (x) {
        new_number = new_number * 10 + ( x % 10 );
        x /= 10;
    }
    if (new_number>pow(2,31)-1 || new_number < (pow(2, 31)*(-1)))
    {
        return 0;
    }
    return new_number;

    }
};