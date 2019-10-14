//Dynamic Programming

#include <iostream>
#include <bits/stdc++.h>

using namespace std;



int PathsMax(vector<vector<int>> Grid, int N){

  int maximum[N*N] = {0};

  int tmp[N*N][N*N] = {};

  maximum[0] = Grid[0][0];



  int stepright, stepdown;
    for (size_t i = 0; i < N*N; i++) {

      stepright = i + 1;
      stepdown  = i + 3;



      /* Update tmp */
      if ((stepright%N > i%N) && ( stepdown/N > i/N)  && stepright < N*N && stepdown < N*N ){
        tmp[i][stepright] = maximum[i] + Grid[stepright/N][stepright%N];
        tmp[i][stepdown] = maximum[i] + Grid[stepdown/N][stepdown%N];

    }else if (stepright%N > i%N    && stepright < N*N)
            tmp[i][stepright] = maximum[i] + Grid[stepright/N][stepright%N];

    else if (stepdown/N > i/N && stepdown < N*N)
          tmp[i][stepdown] = maximum[i] + Grid[stepdown/N][stepdown%N];



      /* Update maximum */
         if ( maximum[stepright] < tmp[i][stepright] && stepright < N*N)
                maximum[stepright] = tmp[i][stepright];
         if ( maximum[stepdown] < tmp[i][stepdown] && stepdown < N*N)
              maximum[stepdown] = tmp[i][stepdown];


    }
/*    Printing tmp to check it
    for (size_t i = 0; i < N*N; i++) {

      for (size_t j = 0; j < N*N; j++) {

        std::cout << tmp[i][j] << '\t';
      }
      std::cout  << '\n';
    }*/


    return maximum[N*N-1];
}



int main (){
  int N;
  printf("Introduce N: ");
  cin >> N; // 3


  /* gives  25*/
  vector<vector<int>> Grid { { 0, 5, 8 },
                               { 1, 2, 3 },
                               { 2, 7, 9 } };
*/
/* gives 29
vector<vector<int>> Grid { { 1, 2, 3 },
                             { 4, 8, 2 },
                             { 1, 5, 3 } };*/

std::cout << PathsMax(Grid,N) << '\n';

}
