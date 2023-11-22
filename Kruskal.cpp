#include <iostream>
#include <vector>
#define N 5

using namespace std;

typedef int index;
typedef index set_pointer;
struct nodetype {
    index parent;
    int depth;
};
typedef nodetype universe[N];
struct edge {
    int vertex1;
    int vertex2;
    int weight;
};

class DSDS2 {
    private:
        universe U;
    public:
        void makeset (index i) { U[i].parent = i; U[i].depth = 0; }
        set_pointer find (index i) { index j; j = i;
            while (U[j].parent != j) j=U[j].parent; return j; }
        void merge (set_pointer p, set_pointer q) {
            if (U[p].depth == U[q].depth) { U[p].depth =+1; U[q].parent =p; }
            else if (U[p].depth < U[q].depth) U[p].parent =q;
            else U[q].parent = p;
        }
        bool equal(set_pointer p, set_pointer q) {
            if (p == q) return true; else return false; }
        void initial (int n) { index i;
            for (i=0; i<n; i++) makeset(i); }
};

void kruskal(int n, int m, vector<edge> E, vector<edge>& F);
int main(void) {
    vector<edge> E = {{1,2,4}, {1,3,5}, {1,4,2}, {2,4,6}, {3,4,1}, {3,5,4}, {4,5,3}};   
    vector<edge> F;
    kruskal(N, E.size(), E, F);

    for(int i = 0; i < F.size(); i++)
        cout << "(" << F[i].vertex1 << "," << F[i].vertex2 << ") " << F[i].weight << endl;
}

void kruskal(int n, int m, vector<edge> E, vector<edge>& F){
    index i, j;
    set_pointer p, q;
    edge e, temp;
    DSDS2 dsds2;
    for(i = 1; i < m; i++)
        for(j = 0; j < m-1; j++){
            if(E[j].weight > E[j+1].weight){
                temp = E[j];
                E[j] = E[j+1];
                E[j+1] = temp;
            }
        }
    dsds2.initial(n);

    while(F.size() < n-1){
        e = E.front(); E.erase(E.begin());
        i = e.vertex1;
        j = e.vertex2;
        p = dsds2.find(i-1);
        q = dsds2.find(j-1);
        if (!dsds2.equal(p,q)) {
            dsds2.merge(p,q);
            F.push_back(e);
        }
    }
}