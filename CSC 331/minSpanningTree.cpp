/*
 COURSE ID:             CSC 331
 FULL NAME:             Samuel Zaldivar
 SECTION:               0900
 FILE NAME:             csc331-0900_zaldivar_prog5.cpp
 ASSIGNMENT NUMBER:     5
 DUE DATE:              05/08/2019
 PROGRAM PURPOSE:       Input a tree and generate the minimum spanning tree
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

struct Edge{
	int startVertex;
	int endVertex;
	int weight;
	
	Edge(int s, int e, int w){
		this->startVertex = s;
		this->endVertex = e;
		this->weight = w;
	}
	
	Edge(){}
};

class Tree{
private:
	vector<int>verticies;
    vector<Edge>edges;
	
	//Vectors for minimum spaning tree
	vector<int>minVerticies;
	vector<Edge>minEdges;
	
	void addVerticies(int, int);
	bool minTreeContainVertex(int);
	int getEdgeIndexForVerticies(int, int);
public:
    void addEdge(int, int, int);
    void displayTree();
	void createMinimumSpaningTree();
	void displayMinimumSpaningTree();
	void writeMinimumSpaningTreeToFile(char[]);
	bool isTreeEmpty();
};

/* TREE CLASS DEFINITION */

	/* PRIVATE FUNCTIONS */

/*
 This function will only add verticies that are not
 yet in the verticies vector
 */
void Tree::addVerticies(int v1, int v2){
	bool foundV1 = false, foundV2 = false;
	for(auto &vertex: verticies){
		if(vertex == v1)
			foundV1 = true;
		if(vertex == v2)
			foundV2 = true;
		if(foundV1 && foundV2)
			return;
	}
	
	if(!foundV1)
		verticies.push_back(v1);
	if(!foundV2)
		verticies.push_back(v2);
}

/*
 Check to see if the vertex is already in the minimum spaning tree verticies
 */
bool Tree::minTreeContainVertex(int v){
	for(auto &vertex : minVerticies)
		if(vertex == v) return true;
	return false;
}

/*
 Returns the index of an edge that has the verticies in either end.
 Return -1 if no edge was found
 */
int Tree::getEdgeIndexForVerticies(int startVertex, int endVertex){
	for(int i = 0; i < edges.size(); i++){
		if( (edges[i].startVertex == startVertex && edges[i].endVertex == endVertex) ||
			 (edges[i].startVertex == endVertex && edges[i].endVertex == startVertex)) return i;
	}
	return -1;
}
/****************************************************************************************/


	/* PUBLIC FUNCTIONS */
void Tree::addEdge(int v1, int v2, int w){
	if(edges.size() <= 100){
		edges.push_back(Edge(v1, v2, w));
		addVerticies(v1, v2);
	}
}

void Tree::createMinimumSpaningTree(){
	minVerticies.push_back(verticies[0]); //starting vertex
	
	//Loop unil the number of verticies in the tree
	for(int i = 0; i < verticies.size() - 1; i++){
		int minWeight = 999;
		int minEndVertex = 0;
		Edge minEdge;
		
		//Loop all verticies that are part of the min spanning tree
		for(auto &startVertex : minVerticies){
			//Loop all verticies
			for(auto &endVertex : verticies){
				if(!minTreeContainVertex(endVertex)){ //Continue only if the end vertex is not in the min spanning tree
					int edgeIndex = getEdgeIndexForVerticies(startVertex, endVertex);
					if(edgeIndex >= 0){
						if(edges[edgeIndex].weight < minWeight){
							minEndVertex = endVertex;
							minEdge = Edge(startVertex, endVertex, edges[edgeIndex].weight);
							minWeight = edges[edgeIndex].weight;
						}
					}
				}
			}
		}
		//Add the minimum endge to the min spanning tree
		minVerticies.push_back(minEndVertex);
		minEdges.push_back(minEdge);
	}
}

bool Tree::isTreeEmpty(){
	return (edges.size() == 0 || verticies.size() == 0);
}

void Tree::writeMinimumSpaningTreeToFile(char fileName[]){
	ofstream outputFile;
	outputFile.open(fileName);
	
	if(!outputFile){
		cout << "Unable to write to file: " << fileName << endl;
		return;
	}
	
	for(auto edge : minEdges){
		outputFile << edge.startVertex << " " << edge.endVertex << " " << edge.weight << endl;
	}
	outputFile.close();
}





//Display Tree
void Tree::displayMinimumSpaningTree(){
	cout << endl << "Minimum Spaning Tree:" << endl;
	int totalWeight = 0;
	for(auto &edge : minEdges){
		totalWeight += edge.weight;
		cout << edge.startVertex << " " <<  edge.endVertex << endl;
	}
	cout << "Edge weight total: " << totalWeight << endl;
}

void Tree::displayTree(){
	cout << endl << "Tree" << endl;
	cout << "Edges: " << endl;
	for(auto &edge : edges){
		cout << edge.startVertex << " " <<  edge.endVertex << " " << edge.weight << endl;
	}
	
	cout << "Verticies:" << endl;
	for(auto &vertex : verticies){
		cout << vertex << endl;
	}
	cout << endl;
}
/****************************************************************************************/





void processInput(string, int[]);
void readFromFile(char[], char[]);
void readFromUserInput();

int main(int argc, char** argv){
	
	cout << "Minimum Spanning Tree Program" << endl;
	
	if(argc == 3){
		readFromFile(argv[1], argv[2]);
	}
	else{
		readFromUserInput();
	}
}

void readFromFile(char inputFileName[], char outputFileName[]){
	
	cout << "Reading from file.." << endl;
	
	Tree t;
	int inputArr[3];
	
	ifstream inputFile;
	inputFile.open(inputFileName);
	
	if(!inputFile){
		cout << "Unable to open file: " << inputFileName << endl;
		return;
	}
	
	string line;
	while(getline(inputFile, line)){
		
		if(line == "end-of-file") break;
		
		processInput(line, inputArr);
		t.addEdge(inputArr[0], inputArr[1], inputArr[2]);
	}
	
	inputFile.close();
	
	if(!t.isTreeEmpty()){
		t.createMinimumSpaningTree();
		t.writeMinimumSpaningTreeToFile(outputFileName);
		t.displayMinimumSpaningTree();
	}
	else{
		cout << "Tree is empty. Can not make minimum spanning tree" << endl;
	}
}



void readFromUserInput(){
	
	cout << "To enter an edge input: [START VERTEX] [END VERTEX] [WEIGHT]" << endl;
	cout << "Enter end-of-file to finish" << endl;
	
	int inputArr[3];
	string input;
	Tree t;
	
	do{
		getline(cin, input);
		
		if(input == "end-of-file") break;
		
		processInput(input, inputArr);
		t.addEdge(inputArr[0], inputArr[1], inputArr[2]);
		
	}while(input != "end-of-file");
	
	if(!t.isTreeEmpty()){
		t.createMinimumSpaningTree();
		t.displayMinimumSpaningTree();
	}
	else{
		cout << "Tree is empty. Can not make minimum spanning tree" << endl;
	}
}

void processInput(string input, int numArr[]){
    int numIndex = 0;
    
    string num = "";
    for(int i = 0; i < input.size(); i++){
        if(input[i] != ' '){
            num.push_back(input[i]);
        }
		else{
			numArr[numIndex] = stoi(num);
			num = "";
			numIndex++;
		}
    }
	numArr[numIndex] = stoi(num);
}
