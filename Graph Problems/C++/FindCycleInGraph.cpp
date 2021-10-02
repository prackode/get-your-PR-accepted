//Find Cycle

#include <bits/stdc++.h>
using namespace std;

int c;
//function to check if cycle is present in thr graph, return true if cycle is found else gives out false
bool hasCycle(int **adj, bool *visited, int n, int startVertex)
{
	visited[startVertex] =  true;
	c++;//used to find the complexity

	//loop to traverse the graph
	for(int i = 0 ; i < n ; i++, c++)
		if(adj[startVertex][i] == 1)
		{
			c++;
			/*checks for the visited array, which has the indices of all the vertices traversed before, returns true if cycle is found else checks again
			 using recursion*/
			if(visited[i])
				return true;
			else
				return hasCycle(adj, visited, n, i);//recursion, will run(check) again
			c++;//to find complexity
		}
		c++;//to find complexity
		return false;//returns false if cycle isnt found
		
		
}

int main()
{	
	// Driver Code
	// input vertices and edges of graph
	int v, e;
	cin >> v >> e;
	cout << endl;

	c = 0;
	c++;//to find complexity

	int **adj = new int*[v];

	for(int i = 0 ; i < v ; i++)
		adj[i] = new int[v];

		for(int i = 0 ; i < v ; i++, c++)
			for(int j = 0 ; j < v ;j++, c++)
				adj[i][j] = 0;


			for(int i = 0 ; i < e ; i++, c++)
			{
				c++;
				int l, r;
				cin >> l >> r;
				adj[l][r] = 1;
			}

			bool *visited = new bool[v];
			for(int i = 0 ; i < v ; i++, c++)
				visited[i] = false;

			c++;
			int startVertex;
			c++;
			c++;


			for(int i = 0 ; i < v ; i++)
			{
				bool ans = hasCycle(adj, visited, v, i);
				if(ans)
				{

					cout << "Cycle exists";
					cout << "\nStep count: " << c;
					return 0;
				}

				for(int j = 0 ; j < v ; j++)
					visited[j] = false;


			}

			cout << "No cycle";
			c++;
			cout << "\nStep count: " << c;

			return 0;
}
