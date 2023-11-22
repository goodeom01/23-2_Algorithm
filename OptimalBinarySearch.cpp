#include <iostream>
#define N 4
#define INF 1000000

using namespace std;

void optsearchtree(int n, const float p[N], float &minavg,  int R[N+1][N+1]);

int main(void){
    const float p[N] = {(float)3/8, (float)3/8, (float)1/8, (float)1/8};
    int R[N+1][N+1];
    float minavg;

    optsearchtree(N, p, minavg, R);

    cout << minavg << endl;
}

void optsearchtree(int n, const float p[N], float &minavg, int R[N+1][N+1]){
    int i, j, k, diagonal;
    float A[n+1][n+1] = {0, };
    float min, sum;

    for(i = 0; i < n; i++){
        A[i][i] = 0; A[i][i+1] = p[i];
         R[i][i] = 0; R[i][i+1] = i+1;
    }
    A[n][n] = 0; R[n][n] = 0;

    for(diagonal = 1; diagonal <= n-1; diagonal++)
        for(i = 0; i < n-diagonal; i++){
            j = i + diagonal;
            min = INF;
            for(k = i; k <= j; k++){
                if(A[i][k] + A[k+1][j+1] < min){    //최적의 A[i][k]+A[k+1][j]
                    min = A[i][k] + A[k+1][j+1];
                    R[i][j+1] = k + 1;
                }
            }
            sum = 0;
            for(int r = i; r <= j; r++)             // p[i]부터 p[j]까지의 합을 구하는 과정
                sum += p[r];
            A[i][j+1] = min + sum;
        }

    for(int i = 0; i <= n; i++){             // 최종 A배열 확인
        for(int j = 0; j <= n; j++){
            cout.width(6);
            if(i <= j)
                cout << A[i][j];
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    for(int i = 0; i <= n; i++){             // 최종 R배열 확인
        for(int j = 0; j <= n; j++){
            cout.width(4);
            if(i <= j)
                cout << R[i][j];
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << endl;

    minavg = A[0][n];
}