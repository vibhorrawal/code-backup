#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi  vector<int>
#define vvi vector<vector<int>>
#define M 1e9+7
#define T() int tc;cin>>tc;while(tc--)
#define all(x) x.begin(),x.end()
#define REP(i,n) for(auto i=0;i<(n);i++)
#define DEBUG 01
#define pb emplace_back
#define db(x) if (DEBUG) cout<<"[*] "<<#x<<" : "<<x<<endl;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(NULL)

map<string, vector<string>> favoriteVideoGenre(int numUsers, map<string, vector<string>> userBooksListenedTo,
  int numGenres, map<string, vector<string>> bookGenres){
    map<string, vector<string>> res;
    map<string, string> books;
    for(map<string, vector<string>>::iterator it = bookGenres.begin(); it != bookGenres.end(); it++){
      for(int i = 0; i < it->second.size(); i++){
        books[it->second[i]] = it->first;
      }
    }
    for(map<string, vector<string>>::iterator it = userBooksListenedTo.begin(); it != userBooksListenedTo.end(); it++){
      map<string, int> count;
      for(int i = 0; i < it->second.size(); i++){
        count[it->second[i]]++;
      }
      int mxc = 0;
      for(map<string, int>::iterator i = count.begin(); i != count.end(); i++){
        if(mxc < i->second) mxc = i->second;
      }
      for(map<string, int>::iterator i = count.begin(); i != count.end(); i++){
        if(mxc == i->second){
          res[it->first].push_back(i->first);
        }
      }
    }
    return res;
  }


pair<int, int> locationOfTargetValue(int rowCount, int columnCount, vector<vector<int> > matrix, int targetValue){
  for(int i = 0; i < rowCount; i++){
    for(int j = 0; j < columnCount; j++){
      if(matrix[i][j] == targetValue)
        return {i,j};
    }
  }
  return {-1,-1};
}


int32_t main(int argc, char const *argv[]){
  fastIO;

  return 0;
}
