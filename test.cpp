#include <iostream>
using namespace std;


int main() {
        unsigned int reverse= 0;
        unsigned int shifter = 1<<31;
        int mask = 1;
        unsigned int n = 2;
        cout<<shifter<<endl ;

        for(int i = 0; i < 32 ; i++)
        {
            if(n&mask)
            {
              cout<<reverse<<":::::";
              reverse |= (shifter>>i);
              cout<<reverse<<":"<<i<<":"<<(shifter>>i)<<endl;
            }
            mask <<= 1;
        }
        std::cout << reverse<<endl;
        return 0;
}
