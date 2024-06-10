#include "MatrixGraph.h"
#include<iostream>
using namespace std;
MatrixGraph::MatrixGraph(int verticesCnt) {
	this->vercicesCnt = verticesCnt;
	matrix = new bool* [verticesCnt];
	for (int i = 0; i < vercicesCnt; i++) {
		matrix[i] = new bool[verticesCnt];
		for (int j = 0; j < verticesCnt; j++)
			matrix[i][j] = false;
	}
		
}
void MatrixGraph::addEdge(int i, int j) {
	//undirected graph
	matrix[i][j] = true;
	matrix[j][i] = true;
}
void MatrixGraph::removeEdge(int i, int j) {
	matrix[i][j] = false;
	matrix[j][i] = false;
}
void MatrixGraph::print() {
	for (int i = 0; i < vercicesCnt; i++)
		for (int j = 0; j < vercicesCnt; j++)
			cout << matrix[i][j] << " ";
	cout << endl;
}
MatrixGraph::~MatrixGraph() {
	for (int i = 0; i < vercicesCnt; i++)
		delete[] matrix[i];
	delete[] matrix;
}
