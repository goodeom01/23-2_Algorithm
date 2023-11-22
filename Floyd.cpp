#include <iostream>
#define N 5
#define INF 10000000
using namespace std;

void floyd2(int n, const int W[N][N], int D[N][N], int P[N][N]);
void path(int q, int r);

const int W[N][N] = {                           //데이터를 배열로 입력
    {   0,   5,   2, INF, INF},
    {   2,   0, INF,   3,   4},
    {   4, INF,   0,   7, INF},
    { INF, INF, INF,   0,   1},
    { INF,   9, INF, INF,   0}
    };

    int P[N][N];

int main(void){

    int D[N][N];

    floyd2(N, W, D, P);

    int i, j;

    cout << "최종 D배열" << endl;
    for(i = 0; i < N ; i ++){
        for(j = 0; j < N ; j ++)
            cout << "  " << D[i][j];
        cout << endl;
        }                                               //최종 D배열 출력

    cout << "최종 P배열" << endl;
        for(i = 0; i < N ; i ++){
            for(j = 0; j < N ; j ++)
                cout << "  " << P[i][j];
        cout << endl;
         }                                              //최종 P배열 출력

    for(i = 0; i < N ; i ++)
        for(j = 0; j < N ; j ++){
            cout << i ;
             path(i,j);
             cout << " " << j << endl;
        }      
    return 0;
}

void floyd2(int n, const int W[N][N], int D[N][N], int P[N][N]){
    int i, j, k;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            P[i][j] = 0;
            D[i][j] = W[i][j];
        }                                          // P배열의 모든 요소 = 0, D = W

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(D[i][k] + D[k][j] < D[i][j]) { // 정점 V_k를 거치는 경우가 원래의 경우보다 더 최적인 경우
                    P[i][j] = k + 1;                  //P배열 갱신
                    D[i][j] = D[i][k] + D[k][j];  //D배열 갱신
                }
    return;
}

void path(int q, int r){
    if (P[q][r] != 0) {
        path(q,P[q][r] - 1);
        cout << " v" << P[q][r];
        path(P[q][r] - 1,r);
    }
}