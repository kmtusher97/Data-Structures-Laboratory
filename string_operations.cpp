/*
    C++ program to
        * String concatenation
        * Substring
        * First pattern matching algorithm
        * Pattern insertion
        * Pattern deletion
    Prepared By :
        Name : Kamrul Hasan, Roll : 51;
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int stringLength( string s ) {
        int lnth  = 0;
        for(int i=0; s[i]; i++) lnth++;
        return lnth;
}

string stringConcatenation( string s1, string s2 ) {
        for(int i=0; i<s2.size(); i++) s1 += s2[i];
        return s1;
}

string subString( string s, int pos, int lnth ) {
        pos--;
        int sz = stringLength( s );
        string sbstr = "";
        if( pos+lnth-1 >= sz ) cout << "Not possible to create such substring" << endl;
        else {
                for(int i=pos; i<=pos+lnth-1; i++) {
                        sbstr += s[i];
                }
        }
        return sbstr;
}

int frstPttrnMtchingAlgo( string s, string ptrn ) {
        int sz = stringLength( s ), psz = stringLength( ptrn );
        for(int i=0; i<sz; i++) {
                bool flg = true;
                for(int j=i, k=0; i+psz-1<=sz && j<=i+psz-1; j++, k++) {
                        if( s[j] != ptrn[k] ) {
                                flg = false;
                                break;
                        }
                        if( flg ) return i+1;
        } }
        return -1;
}

string stringInsertion( string s, string ptrn, int pos ) {
        int ln1 = stringLength( s );
        string s1 = "";
        s1 = subString( s, 1, pos-1 );
        s1 = stringConcatenation( s1, ptrn );
        s1 += subString( s, pos, ln1-pos+1 );
        return s1;
}

string stringDeletion( string s, string ptrn ) {
        int pos = frstPttrnMtchingAlgo( s, ptrn );
        if( pos != -1 ) {
                int ln1 = stringLength( s ), ln2 = stringLength( ptrn );
                string s1 = subString( s, 1, pos-1 );
                s1 += subString( s, pos+ln2, ln1-(pos+ln2)+1 );
                return s1;
        }
        else return s;
}

void mainMenu() {
        cout << endl << "Select which operation do you want to perform " << endl;
        cout << endl << "1. String Length" << endl << "2. String Concatenation" << endl << "3. Substring" << endl;
        cout << "4. Insert Substring" << endl << "5. Delete Substring" << endl << "6. Pattern Searching" << endl;
        cout << "0. Exit" << endl;
        for(int i=0; i<70; i++) cout << ".";
        cout << endl;
}

bool permission() {
        cout << "If you want to continue press 1 else 0 ???? ";
        int ch;
        cin >> ch;
        return ch == 1 ? true : false;
}

int main() {
        cout << "**** String Operations ****" << endl;
        mainMenu();
        int choice;
        while( cin >> choice ) {
                if( choice == 1 ) {
                        cout << "Enter a string" << endl;
                        string s;
                        while( true ) {
                                getline(cin, s);
                                getline(cin, s);
                                int lnth = stringLength( s );
                                cout << "Length of the string = " << lnth << endl;
                                if( !permission() ) break;
                        }
                }
                else if( choice == 2 ) {
                        cout << "Enter 2 strings " << endl;
                        string ss1, ss2, ss3;
                        while( true ) {
                                getline(cin, ss1);
                                getline(cin, ss1);
                                getline(cin, ss2);
                                ss3 = stringConcatenation( ss1, ss2 );
                                cout << "The concatenated string = " << ss3 << endl;
                                if( !permission() ) break;
                        }
                }
                else if( choice == 3 ) {
                        cout << "Enter a string" << endl;
                        string ss, subss;
                        while( true ) {
                                getline(cin, ss);
                                getline(cin, ss);
                                cout << "Enter the position and length of the substring " << endl;
                                int p, ln;
                                cin >> p >> ln;
                                subss = subString( ss, p, ln );
                                cout << "The substring = " << subss << endl;
                                if( !permission() ) break;
                        }
                }
                else if( choice == 4 ) {
                        cout << "Enter a string, a pattern and the position to insert" << endl;
                        string ss, ptrn;
                        int p;
                        while( true ) {
                                getline(cin, ss);
                                getline(cin, ss);
                                getline(cin, ptrn);
                                cin >> p;
                                ss = stringInsertion( ss, ptrn, p );
                                cout << "After insertion : " << ss << endl;
                                if( !permission() ) break;
                        }
                }
                else if( choice == 5 ) {
                        cout << "Enter a string and a pattern to delete from the string " << endl;
                        string ss, ptrn;
                        while( true ) {
                                getline(cin, ss);
                                getline(cin, ss);
                                getline(cin, ptrn);
                                ss = stringDeletion( ss, ptrn );
                                cout << "After deletion : " << ss << endl;
                                if( !permission() ) break;
                        }
                }
                else if( choice == 6 ) {
                        cout << "Enter a string and a pattern to search" << endl;
                        string ss, ptrn;
                        while( true ) {
                                getline(cin, ss);
                                getline(cin, ss);
                                getline(cin, ptrn);
                                int pos = frstPttrnMtchingAlgo( ss, ptrn );
                                if( pos == -1 ) cout << endl << "Not found!!!" << endl;
                                else cout << endl << "Found at position " << pos << endl;
                                if( !permission() ) break;
                        }
                }
                else break;
                mainMenu();
        }

        return 0;
}
