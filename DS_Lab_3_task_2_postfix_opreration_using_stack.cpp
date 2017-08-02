/*
        C++ program to find the value of a post fix expression
        using stack 
*/
#include <iostream>
using namespace std;

const int MX = 100;
const int inf = 1e6;

struct STACK {
        int tp, lst = 0, arr[MX+3];

        void PUSH( int vlu ) {
                arr[lst++] = vlu, tp = vlu;
        }

        void POP() {
                tp = arr[lst-1];
                lst--;
        }

        bool EMPTY() {
                return lst == 0;
        }

        int TOP() {
                return arr[lst-1];
        }
};

int operation( char sgn, int x, int y ) {
        if( sgn == '+' ) {
                return x+y;
        }
        else if( sgn == '-' ) {
                return x-y;
        }
        else if( sgn == '*' ) {
                return x*y;
        }
        else if( sgn == '/' ) {
                return x/y;
        }
        else if( sgn == '^' ) {
                int pp = 1;
                for(int i=0; i<y; i++) {
                        pp *= x;
                }
                return pp;
        }
}

int main() {
        string exprsn;
        cin >> exprsn;
        STACK mystk;

        for(int i=0; i<exprsn.length(); i++) {
                if( exprsn[i] != ',' ) {
                        if( exprsn[i] >= '0' && exprsn[i] <= '9' ) {
                                mystk.PUSH( (int)(exprsn[i]-'0') );
                        }
                        else {
                                int a = -inf, b = -inf;
                                if( !mystk.EMPTY() ) {
                                        a = mystk.TOP();
                                        mystk.POP();
                                }
                                if( !mystk.EMPTY() ) {
                                        b = mystk.TOP();
                                        mystk.POP();
                                }

                                if( a != -inf && b != -inf ) {
                                        int p = operation( exprsn[i], b, a );
                                        mystk.PUSH( p );
                                }
                        }
                }
        }

        cout << mystk.TOP() << endl;

        return 0;
}
