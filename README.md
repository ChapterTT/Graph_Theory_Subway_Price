# Graph_Theory_Subway_Price
基于最小生成树算法的南昌地铁票价查询C++代码(C++ code of Nanchang subway fare query based on minimum spanning tree algorithm)

---
## 在mac下的运行方式
在命令行：g++ [选项] 准备编译的文件 [选项] [目标文件]
1、编译：g++ -o run_dijkstra dijkstra_main.cpp dijkstra.cpp
2、运行：run_dijkstra

---
## 运行结果
$ run_dijkstra
请输入起始车站:绳金塔
请输入要到达的车站：秋水广场
起点站与终点站之间最短路径中的站点：滕王阁 万寿宫 八一馆 南浦路 
该路程总长度为：5.6公里
购买该段路程所需费用为2元

---
## Prim算法
### 最小生成树方法
通过修改dijstra.cpp文件中的MinEdge方法，可以得到各结点生成的最小生成树，即树中结点之间边长权重只和最小。
