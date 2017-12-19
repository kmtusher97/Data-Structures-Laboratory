#include <iostream>

using namespace std;

#define MX 10000
/////////////////////////////////////////////////////////////////
template<class _T>
class _queue {
private:
  _T arr[MX];
  int frnt, rare;
public:
  _queue() : frnt(0), rare(0) { }
  bool _empty() {
    return frnt==rare ? 1 : 0;
  }
  void _push( _T x ) {
    arr[rare++] = x;
  }
  void _pop() {
    if( _empty() ) {
      cout<<"Error"<<endl;
      return;
    }
    _T tmp = arr[frnt++];
  }
  _T _front() {
    if( _empty() ) {
      cout<<"Empty"<<endl;
      return 0;
    }
    return arr[frnt];
  }
  int _size() {
    return rare-frnt;
  }
  void traverse() {
    for(int i=frnt; i<rare; i++) {
      cout<<arr[i]<<" ";
    }
    cout<<endl;
  }
  ~_queue() { }
};
///////////////////////////////////////////////////////////////////////////
int main() {
  _queue<int> q;
  q._push(4);
  q._push(6);
  q._push(11);
  cout<<q._size()<<endl;
  q.traverse();
  cout<<q._front()<<endl;
  q._pop();
  q.traverse();
  q._pop();
  cout<<q._front()<<endl;
  q._pop();
  cout<<q._size()<<endl;
  return 0;
}
