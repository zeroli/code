#include <cstdio>
#include <cstdlib>
#include <queue>

struct Position {
	int row, col;
	Position()
		: row(0), col(0)
	{ }
	bool operator == (const Position& pos) {
		return (row==pos.row && col==pos.col);
	}
	bool operator != (const Position& pos) {
		return !(operator==(pos));
	}
	Position& operator =(const Position& pos) {
		if (&pos == this)
			return *this;
		this->row = pos.row;
		this->col = pos.col;
		return *this;
	}
	friend Position operator +(const Position& pos1, const Position& pos2) {
		Position retval;
		retval.row = pos1.row + pos2.row;
		retval.col = pos1.col + pos2.col;
		return retval;
	}
	Position& operator += (const Position& pos) {
		this->row += pos.row;
		this->col += pos.col;
		return *this;
	}
}; 

static int grid[9][9];

void initGrid()
{
	for (int i = 1; i < 8; i++) {
		for (int j = 1; j < 8; j++) {
			grid[i][j] = 0;
		}
	}
	grid[5][1] = 1;
	grid[6][1] = 1;
	grid[7][1] = 1;
	grid[1][3] = 1;
	grid[2][3] = 1;
	grid[2][4] = 1;
	grid[3][5] = 1;
	grid[4][4] = 1;
	grid[4][5] = 1;
	grid[5][5] = 1;
	grid[6][2] = 1;
	grid[7][2] = 1;
	grid[6][3] = 1;
	grid[7][3] = 1;
}

bool FindPath(Position start, Position finish, int& PathLen, Position*& path)
{
	if (start==finish) {
		PathLen = 0; 
		return true;
	}
	int m = 7;
	for (int i = 0; i <=m+1; i++) {
		grid[0][i] = grid[m+1][i] = 1;
		grid[i][0] = grid[i][m+1] = 1;
	}
	Position offset[4];
	offset[0].row = 0; offset[0].col = 1;
	offset[1].row = 1; offset[1].col = 0;
	offset[2].row = 0; offset[2].col = -1;
	offset[3].row = -1; offset[3].col = 0;
	int NumOfNbrs = 4;
	Position here, nbr;
	here = start;
	grid[start.row][start.col] = 2;
	
	std::queue<Position> Q;
	do {
		for (int i = 0; i < NumOfNbrs; i++) {
			nbr = here + offset[i];
			//printf("nbr = [%d,%d]\n", nbr.row, nbr.col);
			if (grid[nbr.row][nbr.col]==0) {
				grid[nbr.row][nbr.col] = grid[here.row][here.col]+1;
				if (nbr == finish)
					break;
				Q.push(nbr);
				printf("push [%d,%d] into queue: %d.\n", nbr.row, nbr.col, 
					grid[nbr.row][nbr.col]-2);
			}
		}
		if (nbr == finish)
			break;
		if (Q.empty())
			return false;
		here = Q.front();
		Q.pop();			
		printf("pop [%d,%d] out from queue.\n", here.row, here.col);
	} while (1);
	printf("finish = [%d,%d] : %d\n", finish.row, finish.col, grid[finish.row][finish.col]-2);
	PathLen = grid[finish.row][finish.col]-2;
	path = new Position[PathLen];
	here = finish;
	for (int j = PathLen-1; j >= 0; j--) {
		path[j] = here;
		printf("current at [%d,%d], j = %d\n", here.row, here.col, j);
		for (int i = 0; i < NumOfNbrs; i++) {
			nbr = here + offset[i];
			printf("look up [%d,%d]\n", nbr.row, nbr.col);
			if (grid[nbr.row][nbr.col] == j+2)
				break;
		}
		here = nbr;
	}
	return true;
}

int main()
{
	Position start, finish;
	Position* path = 0;
	start.row = 3; start.col = 2;
	finish.row = 4; finish.col = 6;
	int PathLen = 0;
	initGrid();
	if (FindPath(start, finish, PathLen, path)) {
		printf("Find the shortest paths: \n");
		for (int i = 0; i < PathLen; i++)
			printf("[%d,%d]  ", path[i].row, path[i].col);
		printf("\n");
	} else {
		printf("Failed to find the shortest paths.\n");
	}
	
	return 0;
}
