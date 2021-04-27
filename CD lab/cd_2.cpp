#include <bits/stdc++.h>

using namespace std;
void checkerfunction(string s) {
  int initial = 0;
  int final;
  int previous = 0;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if ((s[i] == '0' && previous == 0) || (s[i] == '1' && previous == 3)) {
      final = 1;
    } else if ((s[i] == '0' && previous == 3) || (s[i] == '1' && previous == 0)) {
      final = 2;
    } else if ((s[i] == '0' && previous == 1) || (s[i] == '1' && previous == 2)) {
      final = 0;
    } else if ((s[i] == '0' && previous == 2) || (s[i] == '1' && previous == 1)) {
      final = 3;
    }
    previous = final;
  }
  if (final == 3) {
    cout << "Accepted" << endl;
  } else {
    cout << "Not Accepted" << endl;
  }
}
int main() {
  cout << "Enter string for which you want to check that it is accepted by DFA:  ";
  string s;
  cin >> s;
  checkerfunction(s);
  return 0;
}