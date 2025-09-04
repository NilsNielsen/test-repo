#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,Y[50];
bool column[50],downdiangonal[50],updiagonal[50];
void place(int x,int y)
{
    Y[x]=y;
    column[y]=1;
    downdiangonal[x-y+n]=1;
    updiagonal[x+y]=1;
}
void undo(int x,int y)
{
    Y[x]=0;
    column[y]=0;
    downdiangonal[x-y+n]=0;
    updiagonal[x+y]=0;
}
void show()
{
    for(int i=1; i<=n; i++)
        cout<<Y[i]<<" ";
    cout<<"\n";
    cnt++;
}
void backtrack(int x)
{
    for(int y=1; y<=n; y++)
    {
        if(!column[y]&&!downdiangonal[x-y+n]&&!updiagonal[x+y])
        {
            place(x,y);
            if(x==n)
                show();
            backtrack(x+1);
            undo(x,y);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //sieve();
    //freopen("","x",stdin);
    //freopen("","w",stdout);
    cin>>n;
    //for(int y=1;y<=n;y++)
    backtrack(1);
    cout<<cnt;
    return 0;
}
