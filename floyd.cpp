#include<iostream>
using namespace std;
#define INFINITY  999  /* __builtin_inf()*/;
class graph {
    private :
        int **g;
        int n;
    public :
        graph(int n) {
            this->n=n;
            g = new int* [n];
            for(int i=0; i<this->n; i++) {
                g[i] = new int [n];

            }
            for(int i=0; i<n; i++) {
               for(int j=0; j<n; j++) {
                    if(i == j)
                        g[i][j]=0;
                    else g[i][j]=INFINITY;
               }
           }
        }
        void insert_edge(int x,int y,int w) {
            g[x][y]=w;
        }
        int min(int x,int y){
            if(x<y)
                return x;
            else return y;
        }
        void floyd() {
            cout<<"input: "<<endl;
            print_graph();
            for(int k=0; k<n; k++) {
                for(int i=0; i<n; i++)
                    for(int j=0; j<n; j++)
                        g[i][j]=min(g[i][j],(g[i][k]+g[k][j]));
                }

            cout<<"output: "<<endl;
            print_graph();
        }
        void print_graph() {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++)
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
    eing.floyd();

}
