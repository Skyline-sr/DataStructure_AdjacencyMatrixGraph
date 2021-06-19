#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "main.h"

#define MVNum 100
#define MaxInt pow(2,4*8-1)-1

typedef char VerTexType;
typedef int ArcType;

typedef struct {
	VerTexType vertexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vertex_num, arc_num;
}AMGraph;

Status CreateUDN(AMGraph* G);
int LocateVertex(AMGraph G, VerTexType v);
void PrintGraph(AMGraph G);

void main() {
	AMGraph G;
	CreateUDN(&G);
	PrintGraph(G);
}

Status CreateUDN(AMGraph* G) {
	int i, j, k, w;
	VerTexType v1, v2;
	printf("请输入顶点数：");
	scanf("%d", &(G->vertex_num));
	printf("请输入边数：");
	scanf("%d", &(G->arc_num));
	for (i = 0; i < G->vertex_num; i++)
	{
		printf("请输入第%d顶点内容：", i + 1);
		getchar();
		scanf("%c", &(G->vertexs[i]));
	}
	for (i = 0; i < G->vertex_num; i++)
	{
		for (j = 0; j < G->vertex_num; j++)
		{
			G->arcs[i][j] = MaxInt;
		}
	}
	for (k = 0; k < G->arc_num; k++)
	{
		printf("请输入要连接的两个顶点的信息：");
		getchar();
		scanf("%c %c", &v1, &v2);
		printf("请输入边的权值：");
		scanf("%d", &w);
		i = LocateVertex(*G, v1);
		j = LocateVertex(*G, v2);
		G->arcs[i][j] = G->arcs[j][i] = w;
	}
	return OK;
}

int LocateVertex(AMGraph G, VerTexType v) {
	int i;
	for (i = 0; i < G.vertex_num; i++)
	{
		if (v == G.vertexs[i])
		{
			return i;
		}
	}
	return -1;
}

void PrintGraph(AMGraph G) {
	int i, j;
	printf("图中顶点信息如下：\n");
	for (i = 0; i < G.vertex_num; i++)
	{
		printf("%c ", G.vertexs[i]);
	}
	printf("\n");
	printf("图中边的权值如下：\n");
	for (i = 0; i < G.vertex_num; i++)
	{
		for (j = 0; j < G.vertex_num; j++)
		{
			printf("%10d ", G.arcs[i][j]);
		}
		printf("\n");
	}
}