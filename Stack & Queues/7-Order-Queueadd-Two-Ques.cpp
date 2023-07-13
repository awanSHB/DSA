#include<iostream>
#include<queue>
using namespace std;

class Q{
	public:
		queue<int> q1;
		queue<int> q2;
		queue<int> q3;
		
		void Order(int A[], int n){
			for(int t=0; t<n;t++)
				q1.push(A[t]);
			int a = 0;
			while(!q1.empty()){
				a = q1.front();
				q1.pop();
				
				if(q2.empty()){
					q2.push(a);
				}else{
					if(a>q2.front()){
						while(!q2.empty() && a > q2.front()){
							q3.push(q2.front());
							q2.pop();
						}
					}
					q3.push(a);
					while(!q2.empty()){
						q3.push(q2.front());
						q2.pop();
					}
					
					while(!q3.empty()){
						q2.push(q3.front());
						q3.pop();
					}
				}
			}
			
			while(!q2.empty()){
				q1.push(q2.front());
				q2.pop();
			}
			
			display(q1);
		}
		
		void display(queue<int> T){
			cout<<"\n\n\t\t\t[";
			while(!T.empty()){
				cout<<T.front()<<" | ";
				T.pop();
			}
			cout<<"\b\b]";
		}
};

int main(){
	Q q;
	
	int A[6] = {3, 2, 5, 1, 6, 4};
	q.Order(A, 6);
}