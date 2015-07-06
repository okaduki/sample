#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

int main(){
  int Q; cin >> Q;
  for(int i=0;i<Q;++i){
	int C, A, N;
	cin >> C >> A >> N;
	int ans = 0;
	for(int i=0;;++i){
	  int C_ = C - i*2, A_ = A - i;
	  if(C_ < 0 || A_ < 0) break;
	  for(int j=0;;++j){
		int C__ = C_ - 3*j;
		if(C__ < 0) break;
		ans = max(ans, i+j+min(C__,min(A_,N)));
	  }
	}
	cout << ans << endl;
  }
  

  return 0;
}
