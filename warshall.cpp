#include<iostream>
using namespace std;
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
                    g[i][j]=0;
               }
           }
        }
        void insert_edge(int x,int y) {
            g[x][y]=1;
        }
        void warshall() {
            cout<<"input: "<<endl;
            print_graph();
            for(int k=0; k<n; k++)
                for(int i=0; i<n; i++)
                    for(int j=0; j<n; j++)
                        g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);
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
    int x,y;
    cin>>x>>y;
    while(x != -1 && y!=-1) {
        eing.insert_edge(x,y);
        cin>>x>>y;
    }
    eing.warshall();


}
