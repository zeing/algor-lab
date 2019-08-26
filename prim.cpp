#include<iostream>
using namespace std;
#define INFINITY  999  /* __builtin_inf()*/;
class graph {
    private :
        int **g;
        int n;
        int *visit;
    public :
        graph(int n) {
            this->n=n+1;
            g = new int* [this->n];
            for(int i=1; i<this->n; i++) {
                g[i] = new int [n];
            }

            for(int i=1; i<this->n; i++) {
               for(int j=1; j<this->n; j++) {
                    if(i == j)
                        g[i][j]=0;
                    else g[i][j]=INFINITY;
               }
           }
            visit = new int [this->n];
            for(int i=1; i<this->n; i++) {
                visit[i]=0;
            }
        }
        void insert_edge(int x,int y,int w) {
            g[x][y]=w;
            g[y][x]=w;
        }
        bool min(int x,int y){
            if(x<y)
                return true;
            else return false;
        }
        void prim(int start) {
            int buffer,sum=0;
            visit[start]=1;
            for(int k=1; k<n-1; k++) {
                    int num_min=INFINITY;
                for(int i=1; i<n; i++) {
                    if(visit[i]==1) {
                       for(int j=1; j<n; j++) {
                            if(visit[j]==0 && g[i][j]>0) {
                                if(min(g[i][j],num_min)) {
                                   num_min=g[i][j];
                                    buffer=j;
                                   // cout<<"k: "<<k<<" i : "<<i<<" j: "<<j<<" visit[j] : "<<visit[j]<<endl;
                                }

                            }
                        }

                    }
                }
                visit[buffer]=1;
                sum+=num_min;
            }
            cout<<"sum : "<<sum;
        }
        void print_graph() {
            for(int i=1; i<n; i++) {
                for(int j=1; j<n; j++)
                    cout<<g[i][j]<<" ";
                cout<<endl;
            }

        }

};
int main() {
    int n;
    cout<<"n: ";
    cin>>n;
    graph eing(n);
    int x,y,w;
    cin>>x>>y>>w;
    while(x != -1 && y!=-1) {
        eing.insert_edge(x,y,w);
        cin>>x>>y>>w;
    }
    int start;
    cin>>start;
    eing.prim(start);

}
