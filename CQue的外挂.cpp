#include<bits/stdc++.h>
#define I inline
#define RI int
#define rep(i,a,b) for(RI i=a;i<=b;++i)
#define dow(i,a,b) for(RI i=a;i>=b;--i)
using namespace std;
const int n=10,N=12,T=1000;
const int dx[5]={0,0,1,0,-1},dy[5]={0,1,0,-1,0};
int val[N*N],a[N][N],stk[N],b[N][N],c[N][N],flag[N],score,ans0,top,tk,tp;
bool vis[N][N],avail[N][N];
pair<int,int> st[55],sT[55],ST[55],ans[55];
queue<pair<int,int> > q;
I void print(int a[N][N]){
	rep(i,1,n){
		rep(j,1,n) printf("%d ",a[i][j]);
		puts("");
	}
}
I void get_stack(int a[N][N]){
	memset(vis,0,sizeof(vis));memset(avail,0,sizeof(avail));
	queue<pair<int,int> > q;top=0;
	rep(i,1,10) rep(j,1,10) if(a[i][j]) rep(k,1,4){
		RI tx=i+dx[k],ty=j+dy[k];
		avail[i][j]|=a[i][j]==a[tx][ty];
	}
	rep(i,1,10)	rep(j,1,10) if(avail[i][j]&&!vis[i][j]){
			st[++top]=make_pair(i,j);
			vis[i][j]=1,q.push(make_pair(i,j));
			while(!q.empty()){
				RI x=q.front().first,y=q.front().second;q.pop(); 
				rep(k,1,4){
					RI tx=x+dx[k],ty=y+dy[k];
					if(a[tx][ty]==a[i][j]&&!vis[tx][ty])
						vis[tx][ty]=1,q.push(make_pair(tx,ty));
				}
			}
		}
}
I int calc(int a[N][N],int x,int y){
	RI step=0,col=a[x][y];
	q.push(make_pair(x,y)),a[x][y]=0;
	while(!q.empty()){
		RI x=q.front().first,y=q.front().second;q.pop();++step;
		rep(k,1,4){
			RI tx=x+dx[k],ty=y+dy[k];
			if(a[tx][ty]==col)
				a[tx][ty]=0,q.push(make_pair(tx,ty));
		}
	}
	return step;
}
I void move(int a[N][N]){
	rep(j,1,n){
		rep(i,1,n) if(a[i][j]) stk[++stk[0]]=a[i][j];
		RI i=n;while(stk[0]) a[i--][j]=stk[stk[0]--];
		while(i) a[i--][j]=0;
	}
	memset(flag,0,sizeof(flag));
	rep(j,1,n) rep(i,1,n) flag[j]|=a[i][j]>0;
	RI mj=1;
	for(RI j=1;j<=n;++j,++mj){
		while(mj<=n&&!flag[mj]) ++mj;
		rep(i,1,n) a[i][j]=mj>n?0:a[i][mj];
	}
}
I int ran(int now){
	RI x=rand()%top+1;
	RI res=calc(c,st[x].first,st[x].second);
	move(c);get_stack(c);
	return res*res*5+(top?ran(now-res):val[now]);
}
I void solve(){
	get_stack(a);tk=top;
	rep(i,1,tk) ST[i]=st[i];
	RI now=100,step=0;
	while(top){
		int mi,Ma=-1e9,ma=-1e9;
		rep(i,1,tk){
			rep(j,1,n) rep(k,1,n) b[j][k]=a[j][k];
			RI nx=ST[i].first,ny=ST[i].second;
			RI res=calc(b,nx,ny),t=T*(10<=step&&step<=14?10:1);
			move(b);get_stack(b);
			tp=top;rep(j,1,tp) sT[j]=st[j];
			ma=max(ma,res*res*5);
			if(tp) rep(j,1,T){
				rep(k,1,n) rep(l,1,n) c[k][l]=b[k][l];
				rep(k,1,tp) st[k]=sT[k];top=tp;
				ma=max(ma,res*res*5+ran(now-res));
			}
			if(ma>Ma) Ma=ma,mi=i;
		}
		ans[++ans0]=ST[mi],++step;
		RI result=calc(a,ST[mi].first,ST[mi].second);
		move(a),get_stack(a),tk=top;
		rep(i,1,tk) ST[i]=st[i];
		now-=result,score+=result*result*5;
	}
	score+=val[now];
}
int main(){
	ifstream ifs("/run/media/hpp/softwaredata/Code/Projects/popStar/a.in", ios::in);
//	freopen("a.out","w",stdout); 
	srand(time(NULL));
	rep(i,0,10) val[i]=2000-20*i*i;
	rep(i,1,10) rep(j,1,10) ifs>>a[i][j];
	ifs.close();
	solve();
	rep(i,1,ans0)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return printf("score: %d\n",score),0;
}
