#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
#define MP make_pair
typedef pair<int,int> PII;

int W, H;


void findconnected(int x, int y, vector<string>& vs, vector<vector<bool>>& vis, int n, vector<PII>& res){
  if(x < 0 || W <= x || y < 0 || H <= y || vis[y][x] || vs[y][x] != n) return;
  res.push_back(MP(x,y));
  vis[y][x] = true;
  findconnected(x-1,y,vs,vis,n,res);
  findconnected(x+1,y,vs,vis,n,res);
  findconnected(x,y-1,vs,vis,n,res);
  findconnected(x,y+1,vs,vis,n,res);
}

void findOn(int x, int y, vector<string>& vs, vector<vector<bool>>& vis, vector<PII>& res){
  /*
  if(vis[y][x]) return;
  vis[y][x] = true;
  */
  if(y == 0 || vs[y-1][x] == '.' || vs[y][x] == vs[y-1][x]) return;
  vector<PII> tmp;
  findconnected(x,y-1,vs,vis,vs[y-1][x],tmp);
  for(PII& pii:tmp){
	findOn(pii.first,pii.second,vs,vis,res);
	res.push_back(pii);
  }
}

int main(){
  while(cin>>W>>H,W){
	vector<string> vs(H);
	for(int i=0;i<H;++i) cin >> vs[i];

	bool ans = true;
	vector<vector<bool>> ok(H,vector<bool>(W, false));
	for(int y=H-1;y>=0;--y){
	  for(int x=0;x<W;++x){
		if(vs[y][x] == '.' || ok[y][x]){
		  ok[y][x] = true;
		  continue;
		}
		vector<PII> pos, ons;
		findconnected(x,y,vs,ok,vs[y][x],pos);
		vector<vector<bool>> use = ok;
		int sum = 0;
		double xl = 10000, xr = -1;
		for(PII pii:pos){
		  if(pii.second == H-1 || 
			 vs[pii.second+1][pii.first] != '.' && vs[pii.second][pii.first] != vs[pii.second+1][pii.first])
			xl = min(xl, 1.*pii.first), xr = max(xr, 1.*pii.first);
		  findOn(pii.first,pii.second,vs,use,ons);
		  sum += pii.first;
		}
		
		for(PII& p: ons) sum += p.first;
		double c = sum * 1. / (pos.size() + ons.size());
		xl -= 0.5, xr += 0.5;
		if(c <= xl || xr <= c){
		  ans = false;// cout << c<<","<<x << "," <<y << endl;
		}
	  }
	}
	
	cout << (ans? "STABLE": "UNSTABLE") << endl;
  }
  
  return 0;
}
