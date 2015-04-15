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
const LL MOD = 1e9+7;


LL powm(LL a, LL b){
  if(b == 0) return 1;
  if(b%2 == 1) return powm(a*a%MOD, b/2) * a % MOD;
  return powm(a*a%MOD,b/2);
}


int S;
VI z;
void za(string s){
  S = SZ(s);
  z.assign(S, 0);
  int L = 0, R = 0;
  for (int i = 1; i < S; i++) {
	if (i > R) {
	  L = R = i;
	  while (R < S && s[R-L] == s[R]) R++;
	  z[i] = R-L; R--;
	} else {
	  int k = i-L;
	  if (z[k] < R-i+1) z[i] = z[k];
	  else {
		L = i;
		while (R < S && s[R-L] == s[R]) R++;
		z[i] = R-L; R--;
	  }
	}
  }
  z[0] = SZ(s);
}


bool ok(int i){
  return z[i] == S - i;
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  string p; cin >> p;
  int sp = SZ(p);
  VI y(M);
  REP(i,M){
	cin >> y[i];
	--y[i];
  }

  za(p);
  LL ans = 1;
  for(int l=0,r=0;l<M;){
	if(y[l]+sp-1 >= y[r]){
	  if(!ok(y[r] - y[l])) ans = 0;
	  if(r == M - 1) ++l;
	  else ++r;
	}
	else{
	  ++l;
	}
  }

  if(M > 0){
	int l = y[0] + sp;
	ans = ans * powm(26, y[0]) % MOD;
	for(int i=1;i<M;++i){
	  if(y[i-1] + sp - 1 < y[i])
		ans = ans * powm(26, y[i] - l) % MOD;
	  l = y[i] + sp;
	}
	ans = ans * powm(26, N - l) % MOD;
  }
  else
	ans = powm(26, N);

  cout << ans << endl;
  
  return 0;
}
