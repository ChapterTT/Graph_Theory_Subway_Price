#include "dijkstra.h"
#include<iostream>
using namespace std;

template<class DataType>
MGraph<DataType>::MGraph(DataType a[], int n){
	vertexNum = n;
	
	//初始化顶点数组
	for(int i = 0; i < n; i++){
		vertex[i] = a[i];	
	}

	//初始化邻接矩阵
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			if(i == j)
				arc[i][j] = 0;
			else
				arc[i][j] = Infinite;
		}
	
	//设置地铁线路上相邻站点之间的距离
	arc[0][1]=1.2;		arc[1][0]=1.2;
	arc[1][2]=3.0;		arc[2][1]=3.0;
	arc[2][3]=1.1;		arc[3][2]=1.1;
	arc[3][4]=1.5;		arc[4][3]=1.5;
	arc[4][5]=0.8;		arc[5][4]=0.8;
	arc[5][6]=1.2;		arc[6][5]=1.2;
	arc[6][7]=1.0;		arc[7][6]=1.0;
	arc[7][8]=0.8;		arc[8][7]=0.8;
	arc[8][9]=1.9;		arc[9][8]=1.9;
	arc[9][10]=1.0;		arc[10][9]=1.0;
	arc[10][11]=0.6;	arc[11][10]=0.6;
	arc[11][12]=1.1;	arc[12][11]=1.1;
	arc[12][13]=1.0;	arc[13][12]=1.0;
	arc[13][14]=1.0;	arc[14][13]=1.0;
	arc[14][15]=0.8;	arc[15][14]=0.8;
	arc[15][16]=0.9;	arc[16][15]=0.9;
	arc[16][17]=0.8;	arc[17][16]=0.8;
	arc[17][18]=1.1;	arc[18][17]=1.1;
	arc[18][19]=1.2;	arc[19][18]=1.2;
	arc[19][20]=2.0;	arc[20][19]=2.0;
	arc[20][21]=1.7;	arc[21][20]=1.7;
	arc[21][22]=1.4;	arc[22][21]=1.4;
	arc[22][23]=1.3;	arc[23][22]=1.3;

	arc[24][25]=1.0;	arc[25][24]=1.0;
	arc[25][26]=1.0;	arc[26][25]=1.0;
	arc[26][27]=1.5;	arc[27][26]=1.5;
	arc[27][28]=1.0;	arc[28][27]=1.0;
	arc[28][29]=1.3;	arc[29][28]=1.3;
	arc[29][30]=1.5;	arc[30][29]=1.5;
	arc[30][31]=0.8;	arc[31][30]=0.8;
	arc[31][32]=1.5;	arc[32][31]=1.5;
	arc[32][7]=1.4;		arc[7][32]=1.4;
	arc[7][33]=1.0;		arc[33][7]=1.0;
	arc[33][34]=1.2;	arc[34][33]=1.2;
	arc[34][35]=2.7;	arc[35][34]=2.7;
	arc[35][36]=0.9;	arc[36][35]=0.9;
	arc[36][37]=0.7;	arc[37][36]=0.7;
	arc[37][12]=0.7;	arc[12][37]=0.7;
	arc[12][38]=0.9;	arc[38][12]=0.9;
	arc[38][39]=1.0;	arc[39][38]=1.0;
	arc[39][40]=0.9;	arc[40][39]=0.9;
	arc[40][41]=0.7;	arc[41][40]=0.7;
	arc[41][42]=2.0;	arc[42][41]=2.0;

	arc[43][44]=2.5;	arc[44][43]=2.5;
	arc[44][45]=1.3;	arc[45][44]=1.3;
	arc[45][46]=1.5;	arc[46][45]=1.5;
	arc[46][47]=0.9;	arc[47][46]=0.9;
	arc[47][48]=1.4;	arc[48][47]=1.4;
	arc[48][49]=1.3;	arc[49][48]=1.3;
	arc[49][50]=1.0;	arc[50][49]=1.0;
	arc[50][51]=1.2;	arc[51][50]=1.2;
	arc[51][52]=1.0;	arc[52][51]=1.0;
	arc[52][53]=1.0;	arc[53][52]=1.0;
	arc[53][54]=0.8;	arc[54][53]=0.8;
	arc[54][55]=1.3;	arc[55][54]=1.3;
	arc[55][11]=0.8;	arc[11][55]=0.8;
	arc[11][56]=1.3;	arc[56][11]=1.3;
	arc[56][36]=1.5;	arc[36][56]=1.5;
	arc[36][57]=1.5;	arc[57][36]=1.5;
	arc[57][58]=1.5;	arc[58][57]=1.5;
	arc[58][59]=1.5;	arc[59][58]=1.5;
	arc[59][60]=1.0;	arc[60][59]=1.0;
	arc[60][61]=1.1;	arc[61][60]=1.1;
	arc[61][62]=1.7;	arc[62][61]=1.7;

	arc[63][64]=1.5;	arc[64][63]=1.5;
	arc[64][65]=2.0;	arc[65][64]=2.0;
	arc[65][66]=1.0;	arc[66][65]=1.0;
	arc[66][67]=1.5;	arc[67][66]=1.5;
	arc[67][68]=0.9;	arc[68][67]=0.9;
	arc[68][24]=1.8;	arc[24][68]=1.8;
	arc[24][69]=1.5;	arc[69][24]=1.5;
	arc[69][70]=1.1;	arc[70][69]=1.1;
	arc[70][71]=3.0;	arc[71][70]=3.0;
	arc[71][72]=1.9;	arc[72][71]=1.9;
	arc[72][73]=2.5;	arc[73][72]=2.5;
	arc[73][74]=1.3;	arc[74][73]=1.3;
	arc[74][75]=0.9;	arc[75][74]=0.9;
	arc[75][76]=1.1;	arc[76][75]=1.1;
	arc[76][77]=1.0;	arc[77][76]=1.0;
	arc[77][78]=0.9;	arc[78][77]=0.9;
	arc[78][79]=0.8;	arc[79][78]=0.8;
	arc[79][54]=0.8;	arc[54][79]=0.8;
	arc[54][80]=1.0;	arc[80][54]=1.0;
	arc[80][39]=0.9;	arc[39][80]=0.9;
	arc[39][13]=1.1;	arc[13][39]=1.1;
	arc[13][81]=1.2;	arc[81][13]=1.2;
	arc[81][57]=1.1;	arc[57][81]=1.1;
	arc[57][82]=1.4;	arc[82][57]=1.4;
	arc[82][83]=1.2;	arc[83][82]=1.2;
	arc[83][84]=2.5;	arc[84][83]=2.5;
	arc[84][85]=1.3;	arc[85][84]=1.3;
	arc[85][86]=1.0;	arc[86][85]=1.0;
	arc[86][87]=1.6;	arc[87][86]=1.6;
	arc[87][88]=1.7;	arc[88][87]=1.7;
	arc[88][89]=1.6;	arc[89][88]=1.6;

}

//查找shortEdge数组中除0外，最小的权值的下标
template<class DataType>
int MGraph<DataType>::MinEdge(element shortEdge[]){
	float min=Infinite;//最小值
	int k;//找到的最小值下标

	//在数组中找到除0外的最小权值
	for(int i = 0; i < vertexNum; i++){
		/*	
		if(shortEdge[i].lowcost != 0 && shortEdge[i].lowcost < min){	//prime算法判断最短边
			min = shortEdge[i].lowcost;
			*/
		if(shortEdge[i].lowcost != 0 && shortEdge[i].lowweight < min){	//Dijkstra算法判断最短路径
			min = shortEdge[i].lowweight;
			k = i;
		}
	}
	return k;
}

//prim算法
//参数v是开始的顶点(顶点数组中的下标)
template<class DataType>
float MGraph<DataType>::Price(int v,int vv){
	element shortEdge[MaxSize];
	//1.初始化辅助数组shortEdge
	for(int i = 0; i < vertexNum; i++){
		shortEdge[i].adjvex = v;
		shortEdge[i].lowcost = arc[v][i];
		shortEdge[i].lowweight=arc[v][i];
	}

	//2.将顶点v加入集合U，即U = {v}
	shortEdge[v].lowcost = 0;
	int k;
	//循环通过算法找到n-1条边并将它们输出
	for(int i = 0; i < vertexNum-1; i++){
		//求出最短边的邻接点k
		k = MinEdge(shortEdge);

		//构建最小生成树过程中，输出边的选取
		// cout<<i<<"("<<vertex[shortEdge[k].adjvex]<<","<<vertex[k]<<")"<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<shortEdge[k].lowcost<<endl;

		//k并入集合U中
		shortEdge[k].lowcost = 0;

		//调整数组shortEdge
		for(int j = 0; j < vertexNum; j++){
			if(arc[k][j] < shortEdge[j].lowcost){
				shortEdge[j].lowcost = arc[k][j];
				shortEdge[j].adjvex = k;
			}
			if(shortEdge[j].lowweight>(arc[k][j]+shortEdge[k].lowweight)){
				shortEdge[j].lowweight=arc[k][j]+shortEdge[k].lowweight;
			}
		}
	}
	
	float sum=shortEdge[vv].lowweight;	//输出最短距离
	cout<<"起点站与终点站之间最短路径中的站点：";
	while(shortEdge[vv].adjvex!=v){
		vv=shortEdge[vv].adjvex;
		cout<<name[vv]<<' ';
	}
	cout<<endl;

	//打印起点站与其它站点之间的最短距离
	// Distance(shortEdge);
	return sum;
}

template<class DataType>
void MGraph<DataType>::Print(){
	int i,j;
	cout<<"当前图的邻接矩阵为："<<endl;
	cout<<"    ";
	for(i = 0; i < vertexNum; i++){
		cout<<"["<<i<<"]"<<"  ";
	}
	cout<<endl;
	for(i = 0; i < vertexNum; i++){
		cout<<"["<<i<<"]"<<"  ";
		for(j = 0; j < vertexNum; j++)
			if(arc[i][j] == Infinite)
				cout<<"∞"<<"  ";
			else
				cout<<arc[i][j]<<"  ";
		cout<<endl;
	}
}

template<class DataType>
void MGraph<DataType>::Distance(element shortEdge[]){
	cout<<"起点站与其它站点之间的最短距离："<<endl;
	for(int j = 0; j < vertexNum; j++){
		int nub = j%5;
		if(nub == 0){
			cout<<endl;
		}
		cout<<shortEdge[j].lowweight<<"  ";
	}
	cout<<endl;
}

template<class DataType>
MGraph<DataType>::~MGraph(){
}
