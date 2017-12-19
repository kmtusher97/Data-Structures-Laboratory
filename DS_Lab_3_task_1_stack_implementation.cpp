#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

#define MX 1000
///////////////////////////////////////////////////////////////////////////////////
template<class _T>   ///stack
class _stack {
private:
  _T arr[MX];
  int rare;
public:
  _stack() : rare(0) { }

  void traverse() {
    if( _empty() ) {
      cout<<"Empty"<<endl;
      return;
    }
    for(int i=1; i<=rare; i++) {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }

  void _push( _T x ) {
    arr[++rare] = x;
  }

  void _pop() {
    if( _empty() ) {
      cout<<"Error"<<endl;
      return;
    }
    _T tmp = _top();
    rare--;
  }

  int _size() {
    return rare;
  }

  _T _top() {
    if( _empty() ) {
      cout<<"Error"<<endl;
      return 0;
    }
    return arr[rare];
  }

  bool _empty() {
    return !rare ? 1 : 0;
  }

  ~_stack() { };
};
/////////////////////////////////////////////////////////////////////////////////////////
///evaluation of postfix expression
bool _is_operator( char c ) {
  if( c=='+' || c=='-' || c=='*' || c=='/' || c=='^' ) return true;
  return false;
}

int operation( int a, int b, char c ) {
  if( c=='^' ) {
    int ans = 1;
    for(int i=1; i<=b; i++) {
      ans *= a;
    }
    return ans;
  }
  if( c=='*' ) {
    return a*b;
  }
  if( c=='/' ) {
    return a/b;
  }
  if( c=='+' ) {
    return a+b;
  }
  if( c=='-' ) {
    return a-b;
  }
}

void postorder_evaluation() {
  char s[MX];
  cin>>s;
  _stack<int> stk;
  for(int i=0; i<strlen(s); i++) {
    if( _is_operator( s[i] ) ) {
      int a, b;
      a = stk._top(); stk._pop();
      b = stk._top(); stk._pop();
      stk._push( operation(a, b, s[i]) );
    }
    else if( s[i]>='0' && s[i]<='9' ) {
      stk._push(s[i]-'0');
    }
  }
  cout<<stk._top()<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////
void stackoperation() {
  _stack<int> s;
  s._push(5);
  s._push(6);
  s.traverse();
  cout<<s._empty()<<endl;
  s._pop();
  s.traverse();
  s._push(21);
  cout<<s._top()<<endl;
  cout<<s._size()<<endl;
}
///////////////////////////////////////////////////////////////////////////////////////
///infix to postfix
bool chk( char c1, char c2 ) {
  if( c1=='^' && c2!='^' ) return true;
  if( (c1=='/' || c1=='*') && (c2=='+' || c2=='-') ) return true;
  return false;
}

void infix_to_postfix() {
  char s[MX], s1[MX];
  cin>>s;
  _stack<char> stk;

  for(int i=0; i<strlen(s); i++) {
    if( s[i]=='(' ) stk._push(s[i]);
    else if( s[i]==')' ) {
      while( !stk._empty() && stk._top()!='(' ) {
        char ch[2];
        ch[0] = stk._top(), ch[1] = '\0';
        strcat(s1, ch);
        stk._pop();
      }
      stk._pop();
    }
    else if( _is_operator(s[i]) ) {
      if( stk._empty() ) stk._push(s[i]);
      else {
        if( _is_operator(s[i]) ) {
          if( chk(stk._top(), s[i]) ) {
            char ch[2];
            ch[0] = stk._top(), ch[1] = '\0';
            strcat(s1, ch), stk._pop();
            stk._push(s[i]);
          }
          else {
            stk._push(s[i]);
          }
        }
      }
    }
    else {
      char ch[2];
      ch[0] = s[i], ch[1] = '\0';
      strcat(s1, ch);
    }
  }
  cout<<s1<<endl;
}
///////////////////////////////////////////////////////////////////////////////////////
int main() {
  stackoperation();
  postorder_evaluation();
  infix_to_postfix();

  return 0;
}
