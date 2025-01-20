// Direcciones: norte, sur, este, oeste
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool visited[N][N]; // Matriz de visitados
bool dfs(int x, int y) {
    // Si está fuera de los límites o es un obstáculo o ya fue visitado
    if (x < 0 || x >= N || y < 0 || y >= N || maze[x][y] == '#' || visited[x][y]) 
        return false;    
    // Si encontramos a Demetrio
    if (maze[x][y] == 'D') {
        return true;
    }
    // Marcar la posición como visitada
    visited[x][y] = true;
    // Explorar en las 4 direcciones
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (dfs(nx, ny)) 
        return true; // Si encontramos a Demetrio, terminar
    }
    return false; // Si no encontramos nada en este camino
}

int main() {
    // Encontrar la posición inicial de Dani ('S')
    int startX, startY;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (maze[i][j] == 'S') {
                startX = i;
                startY = j;
            }
        }
    }

    // Iniciar la búsqueda con DFS desde la posición inicial de Dani
    if (!dfs(startX, startY)) {
        cout << "No se pudo encontrar a Demetrio." << endl;
    }

    return 0;
}