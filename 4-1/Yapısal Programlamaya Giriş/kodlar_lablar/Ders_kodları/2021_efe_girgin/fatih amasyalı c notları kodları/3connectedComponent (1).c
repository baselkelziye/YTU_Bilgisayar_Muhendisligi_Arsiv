void dfs(int x, int y, int current_label,int m[][10],int row_count,int col_count,int label[][10]) {
	int direction;
	// direction vectors
	int dx[] = {+1, 0, -1, 0};
	int dy[] = {0, +1, 0, -1};

  	if (x < 0 || x == row_count) return; // out of bounds
  	if (y < 0 || y == col_count) return; // out of bounds
  	if (label[x][y] || !m[x][y]) return; // already labeled or not marked with 1 in m

	// mark the current cell
	label[x][y] = current_label;
	// recursively mark the neighbors
	for (direction = 0; direction < 4; ++direction)
		dfs(x + dx[direction], y + dy[direction], current_label,m,row_count,col_count,label);
}

void main() {
  // the input matrix
  int m[8][10]=					{	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
									{1, 1, 0, 0, 1, 1, 1, 0, 0, 1},
									{0, 1, 1, 0, 1, 1, 1, 0, 1, 1},
									{0, 0, 1, 0, 0, 1, 1, 0, 0, 0},
									{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
									{0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
									{1, 1, 1, 1, 0, 1, 1, 0, 0, 0},
									{0, 1, 0, 0, 0, 0, 1, 0, 0, 0}};
  // the labels, 0 means unlabeled
  static int label[8][10];
  int component = 1;
  int row_count=8;
  int col_count=10;
  int i,j;
  for (i = 0; i < row_count; i++) 
    for (j = 0; j < col_count; j++) 
      if (!label[i][j] && m[i][j]) dfs(i, j, component++, m,row_count,col_count,label);
   for (i = 0; i < row_count; i++) 
   {
    	for (j = 0; j < col_count; j++) 
    		printf("%d ",label[i][j]);
     	printf("\n");
	}
}
