#include <iostream>
#include <array>
#include <iomanip>

using namespace std;

bool isWon(char, char[][3]);

bool isDraw(char[][3]);

void displayBoard(char[][3]);

void makeAMove(char[][3], char);


//@formatter:off
int main() {
	//
	//	PLEASE DO NOT CHANGE function main
	//
	char board[3][3] = { { ' ', ' ', ' ' },{ ' ', ' ', ' ' },{ ' ', ' ', ' ' } };
	displayBoard(board);

	while (true) {

		// The first player makes a move
		makeAMove(board, 'X');
		displayBoard(board);

		if (isWon('X', board)) {
			cout << "X player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}

		// The second player makes a move
		makeAMove(board, 'O');
		displayBoard(board);

		if (isWon('O', board)) {
			cout << "O player won" << endl;
			exit(0);
		}
		else if (isDraw(board)) {
			cout << "No winner" << endl;
			exit(0);
		}
	}

	return 0;
}
//@formatter:on

bool isWon(char team, char board[][3]) {
    for (int i = 0; i < 3; ++i) {
        // Vertical
        if (board[i][0] == team &&
            board[i][1] == team &&
            board[i][2] == team) {
            return true;
        }
        // Horizontal
        if (board[0][i] == team &&
            board[1][i] == team &&
            board[2][i] == team) {
            return true;
        }
    }

    // Diagonal
    if (board[0][0] == team &&
        board[1][1] == team &&
        board[2][2] == team) {
        return true;
    }
    if (board[0][2] == team &&
        board[1][1] == team &&
        board[2][0] == team) {
        return true;
    }
    return false;
}

bool isDraw(char board[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') { return false; }
        }
    }
    return true;
}

void displayBoard(char board[][3]) {
    std::cout << "\n-------------\n";
    for (int row = 0; row < 3; ++row) {
        std::printf("| %c | %c | %c |\n-------------\n",
                    board[row][0], board[row][1], board[row][2]);
    }
}

int promptMove(char team, std::string const &location) {
    while (true) {
        std::cout << setw(37) << std::left
                  << (std::string("Enter a ") + location + " (0, 1, 2) for player " + team) << ": ";

        int value;
        std::cin >> value;

        if (value < 0 || value > 2) {
            std::cout << "Invalid move\n";
            continue;
        }

        return value;
    }
}

void makeAMove(char board[][3], char team) {
    while (true) {
        int row = promptMove(team, "row");
        int col = promptMove(team, "column");

        if (board[row][col] == ' ') {
            board[row][col] = team;
            return;
        }

        std::cout << "This cell is already occupied. Try a different cell\n";
    }
}