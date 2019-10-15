#include <iostream>
#include <bits/stdc++.h>


using namespace std;
#define N 5


int tmp[N][N];


int DP(int Wines[], int L, int R){
    int maximum;
    int year;


    if ( L > R)
          return 0;
    else if ( tmp[L][R] != -1)
          return tmp[L][R];


    else{

      year = N - R + L;
      maximum = max( year * Wines[L] + DP(Wines,L+1, R)  ,
                  year * Wines[R] + DP(Wines,L, R-1) );
      tmp[L][R] = maximum;
      return maximum;
    }
}


int main(int argc, char const *argv[]) {
  tmp[N][N] ;
  memset(tmp,-1,sizeof(tmp));
  int L;
  int R;
  int Wines[N] = { 2, 4, 6, 2, 5};
  std::cout << DP(Wines,0,N-1) << '\n';
  return 0;
}
