#include <stdio.h>

#define max_size 10

int dirx[8]={0,1,1,1,0,-1,-1,-1};
int diry[8]={-1,-1,0,1,1,1,0,-1};

int steakx[max_size*max_size],steaky[max_size*max_size],top=0;   //設定堆疊大小 
int maze[max_size][max_size]={{0,0,0,0,0,0,0,0,0,0},  //maze[y][x]
							  {1,0,1,1,1,1,0,0,0,0},
							  {0,1,0,0,1,0,1,0,1,0},
							  {0,0,1,1,0,0,0,1,0,0},
							  {0,0,0,0,1,1,0,0,1,0},
							  {0,1,1,0,0,1,0,0,1,0},
							  {0,1,0,1,0,1,0,1,0,0},
							  {0,1,0,1,0,1,0,0,0,0},
							  {0,1,0,1,1,0,1,1,1,0},
							  {0,0,0,0,0,0,0,0,0,0}};    //  1是迷宮路徑  0是牆壁唷 
int mark[max_size][max_size]={};
int x=0,y=1,found=0;

void back(void);       //宣告啦 
void walk(int);
void move(void);
void pop(void);
void push(void);
void prt(void);

int main(void){
	move();    //開始走路
	int i,j;
	prt();     //顯示
	for (i=0;i<=9;i++){             //看地圖畫得怎樣也要跟你說??
		for (j=0;j<=9;j++){
			printf("%d ",mark[i][j]);
		}
		printf("\n");
	}
	system("pause");   //等等我 別直接結束R
}

void back(void){      // 後退 
	if (top!=0){      //原來 我有得後退也 
		maze[y][x]=1; //X! 這條路有毒 
		pop();        //抓前一個xy的值 
	}
	//prt();
}

void walk(int dir){
	push();        //記錄我當前的xy 
	x=x+dirx[dir]; //我走下一步了 
	y=y+diry[dir]; //同上 
	maze[y][x]=2;  //既然走了 就代表我要留下痕跡 
	mark[y][x]=1;  //地圖也是一樣啦 
	//prt();
}

void move(void){
	maze[y][x]=2;    //我(0,1)是走過ㄉ 
	mark[y][x]=1;    //畫地圖(0,1)→我真的走過ㄌ 
	int dir=0;
	push();
	while (found!=1){     //看你要不要回老家  ==1就回去啦 
		if (x==9 && y==8 && top!=0){   //到終點啦 在走就要跳懸崖了 
			found=1;
			printf("found\n");
			return;
		}else if (top==0){             //這迷宮是死路R  在退我就要回老家了 
			printf("not found\n");
			return;
		}
		if (maze[y+diry[dir]][x+dirx[dir]]==1 && mark[y+diry[dir]][x+dirx[dir]]==0 && dir<8){        //合法路徑 
			walk(dir);
			dir=0;
		}else if (maze[y+diry[dir]][x+dirx[dir]]==0 && mark[y+diry[dir]][x+dirx[dir]]==0&& dir<8){  //撞牆溜 
			dir++;
		}else if (maze[y+diry[dir]][x+dirx[dir]]==1 && mark[y+diry[dir]][x+dirx[dir]]==1&& dir<8){  //走過啦 別像個白癡一樣走走過的路 
			dir++;
		}else if (maze[y+diry[dir]][x+dirx[dir]]==2 && mark[y+diry[dir]][x+dirx[dir]]==1&& dir<8){  //難道 你要走走過來的路?? 別傻啦 孩子 在走就無限LOOP啦 
			dir++;
		}else{        //既然上面都沒得走 我只好後退惹 
			back();
			dir=0;     
		}
	}
}

void pop(void){
	top--;          //top--還需要解釋???  
	x=steakx[top];  //神阿 請給我我上一步的x 
	y=steaky[top];  //神阿 請給我我上一步的y 
}

void push(void){
	steakx[top]=x;  //記錄x 
	steaky[top]=y;  //記錄y 
	top++;          //top++還需要解釋??? 
}

void prt(void){    //這還要解釋 我也是醉了 
	int i,j;
	for (i=0;i<=9;i++){
		for (j=0;j<=9;j++){
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
	printf ("--------------------------------------------\n");
}
