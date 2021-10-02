
	// Program to place N queens in 2-D array where 2 Queens can not be placed in a same row or column as well as diagonally.
public class NQueen2 {

	static int count;
	// Function to check whether we can place a queen at a specific position or not
	private static boolean kyaMainQueenRakhSaktaHun(int[][] board, int cr, int cc, int n) {
		
	// Loop to check if any queen is already present in the same colume before.
		for (int row = 0; row <= cr - 1; row++) {
			if (board[row][cc] == 1) {
				// If any queen is already present then we can not place another queen.
				return false;
			}
		}

		int row = cr;
		int col = cc;
		// To check whether any queen is present diagonally in the left direction or not.
		while (row >= 0 && col >= 0) {
			if (board[row][col] == 1) {
				return false;
			}
			row--;
			col--;
		}

		row = cr;
		col = cc;
		// To check whether any queen is present diagonally in right direction or not
		while (row >= 0 && col < n) {
			if (board[row][col] == 1) {
				return false;
			}
			row--;
			col++;
		}
		// If not any other queen present in the same row ,column and diagonally in both direction then we can place our queen here.
		return true;
	}

	private static void queenConf(int[][] board, int cr, int n) {
		// TODO Auto-generated method stub

		if (cr == n) {
                 // loop to check where the queens are placed in the array
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (board[i][j] == 1)
						// printing Q as soon as we know the position of it.
						System.out.print("Q ");
					else
						System.out.print("- ");

				}
				System.out.println();
			}
			System.out.println("----------------");
			count++;
			return;
		}

		for (int cc = 0; cc < n; cc++) {
			// To check if we can place our queen or not 
			if (kyaMainQueenRakhSaktaHun(board, cr, cc, n) == true) {
				board[cr][cc] = 1;
				queenConf(board, cr + 1, n);
				//  backtracking  our stuck solution
				board[cr][cc] = 0;
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n = 4;
		int[][] board = new int[n][n]; // All 0, no queen is placed iniitally

		count = 0;
		// Passing our 2D matrix along with our current row and value of n.
		queenConf(board, 0, n);
		System.out.println(count);

	}

}
