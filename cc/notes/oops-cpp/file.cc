#include<bits/stdc++.h>
using namespace std;

int main(){
  ofstream outfile("file.txt", ios::in); // in, out, at, app, trunc, nocreate, binary
  outfile << "Output to file";
  outfile.seekp(-10, ios::beg);
  outfile.close();

  string s;
  ifstream infile("file.txt");
  infile >> s; // infile.seekg(val, ios::);
  cout << s << endl;
}
