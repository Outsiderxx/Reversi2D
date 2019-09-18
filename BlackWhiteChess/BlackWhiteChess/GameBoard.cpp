#include "GameBoard.h"

GameBoard::GameBoard() {
	
	board.resize(8);

	for (int i = 0; i < 8; i++) {

		board[i].resize(8);

		for (int j = 0; j < 8; j++) {

			board[i][j] = -1;

		}

	}

	board[3][3] = 1;

	board[3][4] = 0;

	board[4][3] = 0;

	board[4][4] = 1;

	gameRecord.push_back(board);

	turn = false;

	hint = false;

	gameStatus = true;

	blackNum = 0;

	whiteNum = 0;

	blackChance = 3;

	whiteChance = 3;

	x = 0;

	y = 0;

}

void GameBoard::gameStart(int mode) {

	bool prePass = false;

	while (true) {

		printBoard();

		log();

		bool curPass = isPass(turn);

		if ((counting() || prePass && curPass) || !gameStatus) {

			break;

		}

		prePass = curPass;

		if (curPass) {

			turn = 1 - turn;

			log();

			continue;

		}

		while (true) {

			if (_kbhit()) {

				int input = _getch();

				if (input == 224) {

					input = _getch();

					if (input == 72) {

						up();

					}
					else if (input == 75) {

						left();

					}
					else if (input == 77) {

						right();

					}
					else if (input == 80) {

						down();

					}

				}
				else if (input == 13) {

					if (canMove(x, y)) {

						deal();

						break;

					}
					else {



					}

				}
				else if (input = 'u') {

					if (!regret()) {



					}

				}
				else if (input == 'r') {

					if (!regret()) {



					}

				}
				else if (input == 'e') {

					gameStatus = false;

					break;

				}
				else if (input == 'h') {

					hint = true;

					printBoard();

				}
				else if (input == 's') {

					restart();

					break;

				}

			}

		}

		turn = 1 - turn;

	}

	gameOver();
}

int GameBoard::gameOver() {

	if (blackNum > whiteNum) {

		return 0;

	}
	else if (blackNum < whiteNum) {

		return 1;

	}
	else {

		return -1;

	}

}

void GameBoard::log() {

	gameRecord.push_back(board);

}

bool GameBoard::counting() {

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			if (board[i][j] == 0) {

				blackNum++;

			}
			else {

				whiteNum++;

			}

		}

	}

	if (blackNum + whiteNum == 64) {

		return true;

	}
	else {

		return false;

	}

}

bool GameBoard::canMove(int x, int y) {

	if (x >= 8 || x < 0 || y >= 8 || y < 0) {

		return false;

	}

	if (board[x][y] != -1) {

		return false;

	}



	return true;

}


bool GameBoard::isPass(bool turn) {

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			if (board[i][j] == turn ) {

				if (canMove(i, j)) {

					return false;

				}
			}

		}

	}

	return true;

}

bool GameBoard::up() {

	return true;

}

bool GameBoard::down() {

	return true;

}

bool GameBoard::left() {

	return true;

}

bool GameBoard::right() {

	return true;

}

void GameBoard::deal() {

}

void GameBoard::printBoard() {



}

int GameBoard::regret() {

	if (gameRecord.size() < 2) {

		return false;

	}
	else {

		gameRecord.pop_back();

		board = gameRecord[gameRecord.size() - 1];

		return true;

	}
}

bool GameBoard::redo() {

	return true;

}

void GameBoard::replay() {

}

void GameBoard::restart() {

}

bool GameBoard::selfDefine() {

	return true;
}

bool GameBoard::getTurn() {

	return turn;

}

void GameBoard::setTurn(bool setTurn) {

	turn = setTurn;

}

int GameBoard::getX() {

	return x;

}

int GameBoard::getY() {

	return y;

}
