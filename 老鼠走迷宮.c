#include <stdio.h>

#define max_size 10

int dirx[8]={0,1,1,1,0,-1,-1,-1};
int diry[8]={-1,-1,0,1,1,1,0,-1};

int steakx[max_size*max_size],steaky[max_size*max_size],top=0;   //�]�w���|�j�p 
int maze[max_size][max_size]={{0,0,0,0,0,0,0,0,0,0},  //maze[y][x]
							  {1,0,1,1,1,1,0,0,0,0},
							  {0,1,0,0,1,0,1,0,1,0},
							  {0,0,1,1,0,0,0,1,0,0},
							  {0,0,0,0,1,1,0,0,1,0},
							  {0,1,1,0,0,1,0,0,1,0},
							  {0,1,0,1,0,1,0,1,0,0},
							  {0,1,0,1,0,1,0,0,0,0},
							  {0,1,0,1,1,0,1,1,1,0},
							  {0,0,0,0,0,0,0,0,0,0}};    //  1�O�g�c���|  0�O����� 
int mark[max_size][max_size]={};
int x=0,y=1,found=0;

void back(void);       //�ŧi�� 
void walk(int);
void move(void);
void pop(void);
void push(void);
void prt(void);

int main(void){
	move();    //�}�l����
	int i,j;
	prt();     //���
	for (i=0;i<=9;i++){             //�ݦa�ϵe�o��ˤ]�n��A��??
		for (j=0;j<=9;j++){
			printf("%d ",mark[i][j]);
		}
		printf("\n");
	}
	system("pause");   //������ �O��������R
}

void back(void){      // ��h 
	if (top!=0){      //��� �ڦ��o��h�] 
		maze[y][x]=1; //X! �o�������r 
		pop();        //��e�@��xy���� 
	}
	//prt();
}

void walk(int dir){
	push();        //�O���ڷ�e��xy 
	x=x+dirx[dir]; //�ڨ��U�@�B�F 
	y=y+diry[dir]; //�P�W 
	maze[y][x]=2;  //�J�M���F �N�N��ڭn�d�U���� 
	mark[y][x]=1;  //�a�Ϥ]�O�@�˰� 
	//prt();
}

void move(void){
	maze[y][x]=2;    //��(0,1)�O���L�x 
	mark[y][x]=1;    //�e�a��(0,1)���گu�����L�{ 
	int dir=0;
	push();
	while (found!=1){     //�ݧA�n���n�^�Ѯa  ==1�N�^�h�� 
		if (x==9 && y==8 && top!=0){   //����I�� �b���N�n���a�V�F 
			found=1;
			printf("found\n");
			return;
		}else if (top==0){             //�o�g�c�O����R  �b�h�ڴN�n�^�Ѯa�F 
			printf("not found\n");
			return;
		}
		if (maze[y+diry[dir]][x+dirx[dir]]==1 && mark[y+diry[dir]][x+dirx[dir]]==0 && dir<8){        //�X�k���| 
			walk(dir);
			dir=0;
		}else if (maze[y+diry[dir]][x+dirx[dir]]==0 && mark[y+diry[dir]][x+dirx[dir]]==0&& dir<8){  //����� 
			dir++;
		}else if (maze[y+diry[dir]][x+dirx[dir]]==1 && mark[y+diry[dir]][x+dirx[dir]]==1&& dir<8){  //���L�� �O���ӥ�è�@�˨����L���� 
			dir++;
		}else if (maze[y+diry[dir]][x+dirx[dir]]==2 && mark[y+diry[dir]][x+dirx[dir]]==1&& dir<8){  //���D �A�n�����L�Ӫ���?? �O�̰� �Ĥl �b���N�L��LOOP�� 
			dir++;
		}else{        //�J�M�W�����S�o�� �ڥu�n��h�S 
			back();
			dir=0;     
		}
	}
}

void pop(void){
	top--;          //top--�ٻݭn����???  
	x=steakx[top];  //���� �е��ڧڤW�@�B��x 
	y=steaky[top];  //���� �е��ڧڤW�@�B��y 
}

void push(void){
	steakx[top]=x;  //�O��x 
	steaky[top]=y;  //�O��y 
	top++;          //top++�ٻݭn����??? 
}

void prt(void){    //�o�٭n���� �ڤ]�O�K�F 
	int i,j;
	for (i=0;i<=9;i++){
		for (j=0;j<=9;j++){
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
	printf ("--------------------------------------------\n");
}
