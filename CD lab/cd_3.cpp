#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;
unordered_set < string > keywords;
vector < string > temp1 = {"Auto", "double", "int", "struct", "Break", "else", "long", "switch", "Case",
"enum", "register", "typedef", "Char", "extern", "return", "union", "Const", "float", "short",
"unsigned", "Continue", "for", "signed", "void", "Default", "goto", "sizeof", "volatile", "Do", "if",
"static", "while", "Asm", "dynamic_cast", "namespace", "reinterpret_cast", "Bool", "explicit", "new",
"static_cast", "Catch false", "operator", "template", "Class", "friend", "private", "this", "Const_cast",
"inline", "public", "throw", "Delete", "mutable", "protected", "true", "Try", "typeid", "typename",
"using", "virtual", "wchar_t"};

unordered_set < string > operators2;

vector < string > temp2 = {">=", "<=", "<>", ":=", "==", "++"};

unordered_set < char > operators1;
vector < char > temp3 = {'>', '<', '=', '(', ')', '+', '-', '*', '/', ';'};

bool isKeyword(string token) {
  if (keywords.count(token)) return true;
  return false;
}
int main() {
  fstream fptr;
  fptr.open("code.txt", ios:: in );
  for (auto it: temp1) keywords.insert(it);
  for (auto it: temp2) operators2.insert(it);
  for (auto it: temp3) operators1.insert(it);
  if (fptr.is_open()) {
    string line;
    while (getline(fptr, line)) {
      string buffer = "";
      int i = 0;
      while (i < line.size()) {
        // keywords and identifiers
        if (isspace(line[i])) i++;
        else if (isalpha(line[i])) {
          buffer += line[i++];
          while (i < line.size() && isalnum(line[i])) buffer += line[i++];
          if (isKeyword(buffer)) cout << "Keyword : " << buffer << "\n";
          else cout << "Identifier : " << buffer << "\n";
          buffer = "";
        }
        // character constant
        else if (line[i] == '\'') {
          if (i + 2 >= line.size() || line[i + 2] != '\'') {
            cout << "error";
            i += 2;
          } else {
            cout << "char constant : \'" << char(line[i + 1]) << "\'\n";
            i += 2;
          }
        }
        // integer constant
        else if (line[i] >= '0' && line[i] <= '9') {
          buffer += line[i++];
          while (i < line.size() && line[i] >= '0' && line[i] <= '9') buffer += line[i++];
          cout << "integer constant : " << stoi(buffer) << "\n";
          buffer = "";
        }
        // string literal
        else if (line[i] == '\"') {
          i++;
          while (i < line.size() && line[i] != '\"') buffer += line[i++];
          if (i >= line.size()) cout << "error" << "\n";
          else cout << "string literal : \"" << buffer << "\"\n";
          i++;
          buffer = "";
        }
        // comments
        else if ((i + 1 < line.size()) && line[i] == '/' && line[i + 1] == '*') {
          i += 2;
          while (i + 1 < line.size() && (line[i] != '*' || line[i + 1] != '/')) buffer += line[i++];
          if (i + 1 >= line.size() || (line[i] != '*' || line[i + 1] != '/')) cout << "error" << "\n";
          else cout << "comment : " << buffer << "\n";
          buffer = "";
          i += 2;
        }
        // operators of length 2
        else if ((i + 1 < line.size()) && operators2.count(line.substr(i, 2))) {
          cout << "operator : " << line.substr(i, 2) << "\n";
          i += 2;
        }
        // operators of length 1
        else if (operators1.count(line[i])) {
          cout << "operator : " << char(line[i]) << "\n";
          i++;
        } else {
        //   cout << "error\n";
          i++;
        }
      }
    }
  }
  fptr.close();
  return 0;
}