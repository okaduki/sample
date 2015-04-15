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
const int INF = 1e9;

int MAX_N = 101, MAX_L = 100;
int dp[MAX_N][MAX_L];
struct Edge{
  int to, cost, num;
  Edge(int t, int c, int n):
	to(t), cost(c), num(n){}
  
};
typedef vector<vector<Edge>> G;

int dijkstra(G& edges){
  fill((int)*dp, (int*)dp+MAX_N*MAX_L, INF);
  priority_queue<PII> pq;
  pq.push(MP(0,1));

  while(!pq.empty()){
	PII pii = pq.front(), pq.pop();
	if(dp[pii.second][pii.first])
	for(auto& e: edges[pii.second]){
	  
	}
  }
}

int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M, L;
  while(cin>>N>>M>>L, N){
	
  }
  
  return 0;
}
