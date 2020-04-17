#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include<string>

using namespace std;
const int MaxSize = 100;
const float Infinite = 100000;//定义无限大
const string name[]={"双港","蛟桥","长江路","珠江路","庐山南大道","绿茵路","会展路","地铁大厦","秋水广场","滕王阁","万寿宫",
"八一馆","八一广场","丁公路北","文教路南","彭家桥","谢家村","青山湖大道","高新大道","艾溪湖西","艾溪湖东",
"太子殿","奥体中心站","瑶湖西","站前南大道","南昌西","龙岗","国体中心","卧龙山","岭北三路","前湖大道",
"学府大道东","翠范路","雅苑路","红谷中大道","阳明公园","青山路口","福州路","永叔路","丁公路南","南昌火车站",
"洪都中大道","辛家庵","莲塘","莲西","澄湖北大道","小兰北路","昌南客运站","八大山人","京山南路站","江铃东路",
"何坊西路","建设路","十字街","绳金塔","南浦路","叠山路","二七北路","洪都北大道","上海北路","火炬广场",
"火炬大街","京东大道","望城","创新路","璜溪大道","物华南路","学院南路","学院北路","九龙大道","安丰",
"昌南新城","八月湖路","云海路","抚生路","云天路","灌婴路","洪城路","桃花路","桃苑中路","井冈山大道",
"南京西路","财大分校","青山湖西","青山湖东","民圆路","京东大道2","艾溪湖","昌东大道","尤氨公路"
};

struct element{	//定义shortEdge数组元素类型
	int adjvex;	//集合U 顶点索引
	float lowcost;	//边代价（权重）
	float lowweight;	//到起始点的值
};

template<class DataType>
class MGraph{
public:
	MGraph(DataType a[],int n);
	void Print();
	void Distance(element shortEdge[]);
	int MinEdge(element shortEdge[]);
	void Prim(int v);
	float Price(int v,int m); 
	~MGraph();
private:
	int vertex[MaxSize];
	double arc[MaxSize][MaxSize];	//图中点与点之间的距离矩阵
	int vertexNum;
};

#endif