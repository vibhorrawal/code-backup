#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


  int minimizeMeetingCost(int N, int M, vector<vector<int>> costs) {
    int maxsofar = 0;
    int currmax = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M;  j++) {
      costs[i][j] = -1 * costs[i][j];
    }
  }
  int row,col;
  int begr,endr,begc,endc;
  int maxrow = -1000;
  int globalrowend ,globalrowstart;
  int beg,end;
  for (int i = 0; i < N; i++)
  {
    currmax = costs[i][0];
    begr = endr = 0;
    for (int j = 1; j < M; j++)
    {
      // currmax = max(costs[i][j],currmax+costs[i][j]);
      if(costs[i][j] > currmax+costs[i][j])
      {
        currmax = costs[i][j];
        begr = j;
      }
      else
      {
      currmax =  currmax + costs[i][j];
      endr = j;
      }

      if(maxsofar < currmax)
      {
        maxsofar = currmax;
        beg = begr;
        end = endr;
      }
    }
    if(maxrow < maxsofar)
    {
      row = i;
      globalrowstart = beg;
      globalrowend = end;
      maxrow = maxsofar;
    }
  }
  // printf("%d %d %d\n", maxrow,globalrowstart,globalrowend);
  curr_max = maxsofar = costs[0][0];
  int globalcolend,globalcolstart,begc,endc,maxcol;
  for (int j = 0; j < M; j++)
  {
    currmax = costs[0][j];
    begc = endc = 0;
    for (int i = 1; i < N; i++)
    {
      // currmax = max(costs[i][j],currmax+costs[i][j]);
      if(costs[i][j] > currmax+costs[i][j])
      {
        currmax = costs[i][j];
        begc = i;
      }
      else
      {
      currmax =  currmax + costs[i][j];
      endc = i;
      }

      if(maxsofar < currmax)
      {
        maxsofar = currmax;
        beg = begc;
        end = endc;
      }
    }
    if(maxcol < maxsofar)
    {
      col = j;
      globalcolstart = beg;
      globalcolend = end;
      maxcol = maxsofar;
    }
  }


  return -1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    string M_temp;
    getline(cin, M_temp);

    int M = stoi(ltrim(rtrim(M_temp)));

    string costs_rows_temp;
    getline(cin, costs_rows_temp);

    int costs_rows = stoi(ltrim(rtrim(costs_rows_temp)));

    string costs_columns_temp;
    getline(cin, costs_columns_temp);

    int costs_columns = stoi(ltrim(rtrim(costs_columns_temp)));

    vector<vector<int>> costs(costs_rows);

    for (int i = 0; i < costs_rows; i++) {
        costs[i].resize(costs_columns);

        string costs_row_temp_temp;
        getline(cin, costs_row_temp_temp);

        vector<string> costs_row_temp = split(rtrim(costs_row_temp_temp));

        for (int j = 0; j < costs_columns; j++) {
            int costs_row_item = stoi(costs_row_temp[j]);

            costs[i][j] = costs_row_item;
        }
    }

    int result = minimizeMeetingCost(N, M, costs);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
