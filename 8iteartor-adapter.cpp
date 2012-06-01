#include <iterator>
#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
  ostream_iterator<int> outiter(cout, " ");
  int ia[] = {0, 1, 2, 3, 4, 5};
  deque<int> id(ia, ia+6);
  copy(id.begin(), id.end(), outiter);
  cout << endl;

  copy(ia+2, ia+2, front_iterator(id));
  copy(id.begin(), id.end(), outiter);
  cout << endl;

  copy(ia+3, ia+4, back_iterator(id));
  copy(id.begin(), id.end(), outiter);
  cout << endl;

  deque<int>::iterator iter = find(id.begin(), id.end(), 5);
  copy(ia+0, ia+3, inserter(id, iter));
  copy(id.begin(), id.end(), outiter);
  cout << endl;

  copy(id.begin(), id.end(), outiter);
  cout << endl;

  istream_iterator<int> initer(cin), eos;
  copy(initer, eos, inserter(id, id.begni()));
  copy(id.begni(), id.end(), outiter);

  return 0;
}
