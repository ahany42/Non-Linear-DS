#pragma once
class MatrixGraph
{
	bool** matrix;
	int vercicesCnt;
public:
	MatrixGraph(int vercicesCnt);
	void addEdge(int i, int j);
	void removeEdge(int i, int j);
	void print();
	~MatrixGraph();
		
	
};

