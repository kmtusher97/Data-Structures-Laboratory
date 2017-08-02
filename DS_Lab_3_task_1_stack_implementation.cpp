/*
        Data Structure Lab 3 
        Task 1
                * Implement stack using manually
                * Perform PUSH(), POP() operations
*/
#include <iostream>
using namespace std;

const int MX = 10;

struct STACK {
        int tp, lst = 0, arr[MX+3];

        void PUSH( int vlu ) {
                if( lst == MX ) {
                        cout << "Overflow !!!!" << endl;
                        return ;
                }
                arr[lst++] = vlu;
        }

        void POP() {
                if( lst == 0 ) {
                        cout << "Underflow !!!!" << endl;
                        return ;
                }
                tp = arr[lst-1];
                cout << "Top = " << tp << endl;
                lst--;
        }

        bool EMPTY() {
                return lst == 0;
        }

        void TRAVERSE() {
                if( lst == 0 ) {
                        cout << "The stack is empty !!!!" << endl;
                        return ;
                }
                cout << "Stack Elements are : ";
                for(int i=0; i<lst; i++) {
                        cout << arr[i] << " ";
                }
                cout << endl;
        }
};

void menu() {
        cout << endl << "Stack operations : " << endl << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. Empty" << endl;
        cout << "4. Traverse" << endl;
        cout << "0. Exit" << endl;
}

int main() {

        STACK stk;
        int coic, n;
        while( true ) {
                menu();
                cout << "Enter your choice : ";
                cin >> coic;
                if( coic == 1 ) {
                        cin >> n;
                        stk.PUSH( n );
                        stk.TRAVERSE();
                }
                else if( coic == 2 ) {
                        stk.POP();
                        stk.TRAVERSE();
                }
                else if( coic == 3 ) {
                        if( stk.EMPTY() == true ) {
                                cout << "The stack is empty !!!" << endl;
                        }
                        else {
                                cout << "The stack is not empty !!!" << endl;
                        }
                }
                else if( coic == 4 ) {
                        stk.TRAVERSE();
                }
                else {
                        break;
                }
        }


        return 0;
}
