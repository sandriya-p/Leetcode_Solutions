class Solution {
public:
    int smallestNumber(int n) {

    int x= 2;
    while (n >= x) {
        x *= 2;
    }
    return x - 1;
   }
};