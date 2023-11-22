#include <iostream>
#define N 6
#define INF 100000000

using namespace std;

int P[N][N];

int minmult(int n, const int d[N], int P[N][N]);
void order(int i, int j);

int main(void){
    const int d[N+1] = { 5, 2, 3, 4, 6, 7, 8};

    minmult(N, d, P);
    
    for(int i = 0; i < N; i++){                 //최종 P배열 확인
        for(int j = 0; j < N; j++)
            cout << " " << P[i][j];
        cout << endl;
    }

    order(1,6);

    return 0;
}

int minmult(const int n, const int d[N+1], int P[N][N]){
    int i, j, k, diagonal;
    int M[n][n];
    int min;

    for(i = 0 ; i < n; i++)                                                        //M[i][i] = 0로 초기화
        M[i][i] = 0;

    for(diagonal = 1; diagonal <= n-1; diagonal++)
        for(i = 0; i < n - diagonal; i++){
            j = i + diagonal;
            min = INF;
            for(k = i; k < j; k++){
                if(M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1] < min){                // 최적의 M[i][j]를 구하는 과정
                    min = M[i][k] + M[k+1][j] + d[i]*d[k+1]*d[j+1];                 // 최솟값 갱신
                    P[i][j] = k + 1;
                } 
            }
            M[i][j] = min;                                                          //최솟값(최적화값) 입력
        }

    for(int i = 0; i < N; i++){             // 최종 M배열 확인
        for(int j = 0; j < N; j++){
            cout.width(4);
            if(i <= j)
                cout << M[i][j];
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return M[0][n-1];
}

void order(int i, int j){
    int k;

    if(i == j)
        cout << "A" << i;
    else{
        k = P[i-1][j-1];
        cout << "(";
        order(i,k);
        order(k+1, j);
        cout << ")";
    }
}