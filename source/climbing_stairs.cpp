class Solution {
public:
    //based on fibonacci series
    int climbStairs(int n) {

      if (n < 3) return n;
      int a = 1;
      int b = 1;
      for(int i = 2; i <= n; i++) {
        int temp = b;
        b = a + b;
        a = temp;
      }
      return b;
    }

    //bottom up solution
    int climbStairs(int n) {
      if (n < 3) return n;
      int arr[n + 1];
      arr[0] = 0;
      arr[1] = 1;
      arr[2] = 2;

      for(int i = 3; i <= n; i++) {
        arr[i] = arr[i-1] + arr[i - 2] ;
      }
      return arr[n];
    }
    //recursive solution
    int climbStairs(int n) {  // will run outa memory after n = 40

      if (n <= -1) return 0;
      if (n < 3) return n;
      return climbStairs(n - 1) + climbStairs(n - 2);

    }
};
