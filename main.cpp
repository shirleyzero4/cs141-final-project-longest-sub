#include <iostream>
#include <string>

using namespace std;

string LongestCommonSubsequence(string x, string y);

int main() {
  //Takes two strings as inputs
  string x;
  string y;
  cout << "String 1: " << endl;
  cin >> x;
  cout << "String 2: " << endl;
  cin >> y;
  cout << "The Longest Common Subsquence is: ";
  cout << LongestCommonSubsequence(x, y) << endl;
  return 0;
}

string LongestCommonSubsequence(string x, string y) {
  int m = x.size(); //length of string x
  int n = y.size(); //length of string y
  string c[m + 1][n + 1]; //new 2D array
  
  // Base Case, either string 1 or 2 is empty
  for (int i = 1; i <= m; ++i) {
    c[i][0] = "\0";
    c[m][n] = c[i][0];
  }
  for (int j = 0; j <= n; ++j) {
    c[0][j] = "\0";
    c[m][n] = c[0][j];
  }

  //Same string case
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (x[i] == y[j]) {
        c[i][j] = x[i];
        c[m][n] = c[i][j];
      }
    }
  }

  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (x[i] == y[j]) {
        c[i][j] = c[i - 1][j - 1] + x[i]; //if chars in x and y match, reduce size both strings by 1 and add back the matching char
      } 
      else if ((c[i - 1][j]).size() >= (c[i][j - 1]).size()) { //size of string 1 larger, reduce size by 1
        c[i][j] = c[i - 1][j];
      }
      else { //size of string 2 larger, reduce size by 1
        c[i][j] = c[i][j - 1];
      }
      c[m][n] = c[i][j];
    }
  }
  return c[m][n];
}

