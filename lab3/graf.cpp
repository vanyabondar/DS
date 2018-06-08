#include "graf.h"

void input(int**a, int n) {
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		a[i] = new int[m + 1];
		a[i][0] = m;
		for (int j = 1; j <= m; j++) {
			int v;
			cin >> v;
			a[i][j] = v;
		}
	}
}
void dfs(int** a, bool* visited, int v) {
	for (int i = 1; i <= a[v][0]; i++) {
		if (!visited[a[v][i]]) {
			visited[a[v][i]] = true;
			dfs(a, visited, i);
		}
	}
}
	
bool checkForEulerPath(int** a, int n) {
	int OddVertex = 0;
	for (int v = 0; v < n; v++) {
		if (a[v][0] % 2 == 1)
			OddVertex++;
		//if (OddVertex > 2)// если количество вершин с нечетной степенью больше двух, то граф не является эйлеровым
		if (OddVertex > 0)
			return false;
	}
	bool* visited = new bool[n];
	for (int v = 0; v < n; v++)
		visited[v] = false;
	visited[0] = true;
	dfs(a, visited, 0);
	bool rez = true;
	for (int v = 0; v < n; v++)
		rez = rez && visited[v];
	return rez;      // если количество компонент связности, содержащие ребра, больше одной,то граф не является эйлеровым
}

void findEulerPath(int** a, int n) {   // если граф является полуэйлеровым, то алгоритм следует запускать из вершины нечетной степени 
	int v = -1;
	for (int i = 0; i < n; i++)
		if (a[i][0] % 2 == 1)
			v = i;
	if (v < 0)
		v = 0;
	stack <int> S;
	S.push(v);  // S — стек
	
	bool** go = new bool*[n];
	for (int i = 0; i < n; i++) {
		go[i] = new bool[n];
		for (int j = 0; j < n; j++)
			go[i][j] = false;
	}
	for (int i = 0; i <n ; i++)
		for (int j = 1; j <= a[i][0]; j++) {
			go[i][a[i][j]] = true;
			go[a[i][j]][i] = true;
		}
	while (!S.empty()) {
		int v = S.top();
		for (int i = 0; i < n; i++)
			if (go[v][i]) {   // нашли ребро, по которому ещё не прошли
				S.push(i);  // добавили новую вершину в стек
				go[v][i] = false;
				go[i][v] = false;
				break;
			}
		if (v == S.top()) {
			S.pop();  // не нашлось инцидентных вершине v рёбер, по которым ещё не прошли
			cout << v << " <-- ";
		}
	}
	for (int i = 0; i < n; i++)
		delete[]go[i];
	delete[] go;
}
