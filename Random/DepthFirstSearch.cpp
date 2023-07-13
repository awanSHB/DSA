#include <iostream>
#include <stack>
#include <list>
using namespace std;

class Edge;

class Vertex{
	public:
		char name;
		list<Edge*> edge_list;
		Vertex(char n){
			name = n;
		}
};

class Edge{
	public:
		Vertex *start;
		Vertex *end;
		int weight;
		
		Edge(Vertex *first, Vertex* last, int value){
			start = first;
			end = last;
			weight = value;
		}
};

class Graph{
	private:
		list <Vertex*> vertex_list;
	public:
		Graph(){}
	
	void addVertex(char n){
		Vertex *v = new Vertex(n);
		vertex_list.push_back(v);
	}
	
	void addVertex(Vertex *vt){
		vertex_list.push_back(vt);
	}
	
	void addEdge(Vertex *first, Vertex *last, int val){
		Edge *e1 = new Edge(first, last, val);
		Edge *e2 = new Edge(last, first, val);
		first->edge_list.push_back(e1);
		last->edge_list.push_back(e2);
	}
	
	Vertex *find(char st){
		for(Vertex *v: vertex_list){
			if(v->name == st)
				return v;
		}
		return NULL;
	}
	
	void DFS(char start){
		stack <Vertex*> stk;		//Stack that stores the vertex 
		int N = vertex_list.size();
		int visited[N];
		for(int i=0; i<N; i++)
			visited[i] = 0;
		
		Vertex *vx = find(start);
		if(vx==NULL)
			return;
		
		stk.push(vx);
		
		while(!stk.empty()){
			Vertex *x = stk.top();
			stk.pop();
			int index = x->name-'A';
			if(!visited[index]){
				cout<<x->name<<"  ";
				visited[index] = 1;
			}
			
			for(Edge *e: x->edge_list){
				int k = e->end->name-'A';
				if(!visited[k])
					stk.push(e->end);
			}
		}
	}
	
	void display(){
		for(Vertex *v : vertex_list){
			cout<<v->name<<" ---> ";
			for(Edge *e: v->edge_list){
				cout<<"["<<e->end->name<<", "<<e->weight<<"]-->";
			}
			cout<<"NULL\n\n";
		}
	}
};

int main(){
	Graph g;
	
	Vertex a('A');
	Vertex b('B');
	Vertex c('C');
	Vertex d('D');
	Vertex e('E');
	
	g.addVertex(&a);
	g.addVertex(&b);
	g.addVertex(&c);
	g.addVertex(&d);
	g.addVertex(&e);
	
	g.addEdge(&a, &b, 4);
	g.addEdge(&a, &c, 2);
	g.addEdge(&b, &d, 1);
	g.addEdge(&d, &e, 3);
	g.addEdge(&d, &c, 2);
	
	g.display();
	
	g.DFS('A');
		
}




