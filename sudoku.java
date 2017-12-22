import java.util.*;
public class sudoku {
    static boolean sudoku2(char[][] grid) {
	for(int i=0; i < 3; ++i) {

	    for(int j=0; j < 3; ++j) {
		Set<Character> exists = new HashSet<Character>();
		for(int k=0; k < 3; ++k) {
		    int row = i * 3 + k;
		    for(int k2 = 0; k2 < 3; ++k2) {
			int col = j * 3 + k2;
			char c = grid[row][col];
			if(c != '.') {
			    if(exists.contains(c)) {
				return false;
			    }
			    exists.add(c);
			}
		    }
		}
	    }
	}

	for(int i=0; i < 9; ++i) {
	    Set<Character> exists1 = new HashSet<Character>();
	    Set<Character> exists2 = new HashSet<Character>();
	    for(int j=0; j < 9; ++j) {
		char c = grid[i][j];
		if(c != '.') {
		    if(exists1.contains(c)) {
			return false;
		    }
		    exists1.add(c);
		}
		char c2 = grid[j][i];
		if(c2 != '.') {
		    if(exists2.contains(c2)) {
			return false;
		    }
		    exists2.add(c2);
		}
	    }
	}

	return true;

    }

    public static void main(String[] args) {
	// char[][] grid = {{'.', '.', '.', '.', '2', '.', '.', '9', '.'},
	// {'.', '.', '.', '.', '6', '.', '.', '.', '.'},
	// {'7', '1', '.', '.', '7', '5', '.', '.', '.'},
	// {'.', '7', '.', '.', '.', '.', '.', '.', '.'},
	// {'.', '.', '.', '.', '8', '3', '.', '.', '.'},
	// {'.', '.', '8', '.', '.', '7', '.', '6', '.'},
	// {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
	// {'.', '1', '.', '2', '.', '.', '.', '.', '.'},
	// {'.', '2', '.', '.', '3', '.', '.', '.', '.'}};
	char[][] grid = {{'.','.','.','1','4','.','.','2','.'},
	    {'.','.','6','.','.','.','.','.','.'},
	    {'.','.','.','.','.','.','.','.','.'},
	    {'.','.','1','.','.','.','.','.','.'},
	    {'.','6','7','.','.','.','.','.','9'},
	    {'.','.','.','.','.','.','8','1','.'},
	    {'.','3','.','.','.','.','.','.','6'},
	    {'.','.','.','.','.','7','.','.','.'},
	    {'.','.','.','5','.','.','.','7','.'}};

	boolean result = sudoku2(grid);
	System.out.println(result);
    }

}
