//include
//------------------------------------------
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <queue>
 
using namespace std;
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
 
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

int K;
int in[10], to[10];
void rot(int& x, int r){
  x = (x + r + 10) % 10;
}

int dfs(int idx, int d){
  if(idx >= K)
	return 0;
  
  int diff = (to[idx] - in[idx] + 10) % 10;
  if(diff == d) return dfs(idx+1, d);
  
  int res = 1 + dfs(idx+1, diff);
  rot(in[idx], d);
  res = min(res, 1 + dfs(idx+1, (to[idx] - in[idx]+10)%10));
  rot(in[idx], -d);

  return res;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while(cin>>K,K){
	string s1, s2; cin >> s1>> s2;
	REP(i,K)
	  in[i] = s1[i] - '0', to[i] = s2[i] - '0';
	cout << dfs(0, 0) << endl;
  }
  
  return 0;
}
