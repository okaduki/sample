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

int as[501];
int dp[2][501][501];
int N, M, B, MOD;

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> B >> MOD;
  REP(i,N) cin >> as[i];
  sort(as, as+N);
  fill((int*)dp, (int*)dp+2*501*501, 0);

  int crt = 0, nxt = 1;
  dp[crt][0][0] = 1;
  for(int i=0;i<N;++i){
	for(int x=0;x<=B;++x)
	  for(int s=0;s<=M;++s)
		dp[nxt][x][s] = dp[crt][x][s];

	for(int x=0;x+as[i]<=B;++x){
	  for(int s=0;s+1<=M;++s){
		dp[nxt][x+as[i]][s+1] = (dp[nxt][x+as[i]][s+1] + dp[crt][x][s]) % MOD;
	  }
	}
	swap(crt, nxt);
  }

  LL ans = 0;
  REP(x,B+1)
  ans = (ans + dp[crt][x][M]) % MOD;
  cout << ans << endl;
  
  return 0;
}
