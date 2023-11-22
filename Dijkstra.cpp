#include <iostream>
#include <vector>
#define N 5
#define INF 100000
using namespace std;

typedef int index;
typedef int number;
struct edge {                                            //edge의 구조체
    int vertex1;
    int vertex2;
    int weight;
};

void dijkstra(int n, const number W[N][N], vector<edge>& F);
int main(void){
    number W[N][N] = {{   0,   7, INF,   3,   2},
                      { INF,   0,   2,   6, INF},
                      { INF, INF,   0, INF, INF},
                      { INF, INF,   2,   0, INF},
                      { INF,   2, INF,   5,   0}};
    vector<edge> F;

    dijkstra(N, W, F);

    for(int i = 0 ; i < F.size(); i++)
        cout << "(" << F[i].vertex1 << "," << F[i].vertex2 << ") " << F[i].weight << endl;              // 최종 집합F 출력
}

void dijkstra(int n, const number W[N][N], vector<edge>& F){
    index i, vnear;
    edge e;
    index touch[n-1];
    number length[n-1];
    int min;

    for(i=1; i < n; i++){                               //touch, length 배열 초기화
        touch[i-1] = 1;
        length[i-1] = W[0][i];
    }
    for(int j = 0; j < n-1; j++){                      //반복문 n-1회 실행
        min = INF;
        for(i = 1; i < n ; i++)                         //최소의 length를 가진 vertex 찾아서 선택
            if(0 <= length[i-1]&&length[i-1] <= min){
                min = length[i-1];
                vnear = i;
            }
        e = {touch[vnear-1], vnear+1, W[touch[vnear-1]-1][vnear]};      //touch배열을 이용해 선택된 vertex로 가는 엣지를 e로 설정
        F.push_back(e);                                                 //집합F에 edge e 추가
        for(i = 1; i < n; i++)                                          //선택된 vertex를 거쳐서 가는 경우의 weight가 더 적다면 경로 정정
            if(length[vnear-1] + W[vnear][i] < length[i-1]){
                length[i-1] = length[vnear-1] + W[vnear][i];
                touch[i-1] = vnear+1;
            } 
        length[vnear-1] = -1;                                          //선택된 vertex의 length를 -1로 해서 알고리즘에서 제외시킴
    }
}