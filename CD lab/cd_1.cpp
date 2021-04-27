#include<bits/stdc++.h>

using namespace std;
int main() {
  map < char, vector < string >> table_nfa;
  map < string, vector < string >> table_dfa;
  queue < string > q;
  int no_of_states;
  cout << "Enter no. of states: ";
  cin >> no_of_states;
  cout << "Enter the NFA: \n";
  for (int i = 0; i < no_of_states; i++) {
    char state_name;
    cin >> state_name;
    if (!q.size()) {
      string first = "";
      first += state_name;
      q.push(first);
    }
    vector < string > transition;
    int is_final_state;
    cin >> is_final_state;
    if (!is_final_state) {
      string x[2];
      cin >> x[0];
      cin >> x[1];
      transition.push_back(x[0]);
      transition.push_back(x[1]);
    }
    table_nfa[state_name] = transition;
  }
  map < string, int > visited;
  while (!q.empty()) {
    string cur = q.front();
    q.pop();
    if (visited[cur] == 0) {
      visited[cur] = 1;
      vector < string > s;
      for (int i = 0; i <= 1; i++) {
        string transition_on_current_state = "";
        for (auto x: cur) {
          vector < string > st = table_nfa[x];
          if (st.size() > i)
            transition_on_current_state += st[i];
        }
        if (visited[transition_on_current_state] == 0) q.push(transition_on_current_state);
        table_dfa[cur].push_back(transition_on_current_state);
      }
    }
  }
  cout << "\n DFA: \n";
  cout << "State" << "\t" << "0" << "\t" << 1 << endl;
  for (auto state: table_dfa) {
    cout << state.first << "\t";
    for (auto x: state.second)
      cout << x << "\t";
    cout << endl;
  }
}