#include "GameBoard.h"
#define BOARD_X 47
#define BOARD_Y 9

GameBoard::GameBoard() {
	
	board.resize(8);

	for (int i = 0; i < 8; i++) {

		board[i].resize(8);

		for (int j = 0; j < 8; j++) {

			board[i][j] = 0;

		}

	}

	board[3][3] = -2;

	board[3][4] = -1;

	board[4][3] = -1;

	board[4][4] = -2;

	selfDefineBoard = board;

	turn = false;

	hint = false;

	gameStatus = true;

	winner = 3;

	blackNum = 0;

	whiteNum = 0;

	blackChance = 3;

	whiteChance = 3;

	blackTurn = 0;

	whiteTurn = 0;

	x = 0;

	y = 0;

	srand(time(NULL));

}

void GameBoard::gameStart(int mode) {

	bool prePass = false;

	string gameText;

	PlaySound(TEXT("Quiet.wav"), NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);

	gameMode = mode;

	printBasic();
	
	while (true) {

		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 8; j++) {

				if (board[i][j] >= 0) {

					canMove(i, j);

				}

			}

		}

		bool curPass = isPass(turn);

		if ((counting() || prePass && curPass) || !gameStatus) {

			break;

		}

		log();

		printGameInfo();

		goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

		prePass = curPass;

		if (curPass) {

			if (turn) {

				goTo(92, 9);

				cout << "P A S S ! !";;

			}
			else {

				goTo(7, 9);

				cout << "P A S S ! !";

			}

			turn = 1 - turn;

			Sleep(1500);

			continue;

		}

		if (turn && mode == 1) {

			int eatMost = 0;

			vector<int> indexX, indexY;

			for (int i = 0; i < 8; i++) {

				for (int j = 0; j < 8; j++) {

					if (board[i][j] > eatMost) {

						eatMost = board[i][j];

						indexX.resize(1);

						indexY.resize(1);

						indexX[0] = i;

						indexY[0] = j;

					}
					else if (board[i][j] == eatMost) {

						indexX.push_back(i);

						indexY.push_back(j);

					}
					
				}

			}

			int index = rand() % indexX.size();

			x = indexY[index];

			y = indexX[index]; 

			deal();

			turn = false;

			goTo(92, 11);

			cout << "思考中...";

			Sleep(rand() % 2000 + 500);

			char text = 97 + x, num = 48 + y;

			string turnText = turn ? "白棋" : "黑棋";

			messageBox.push_back(turnText + " 落子在 " + text + num);

			message();

			goTo(92, 11);

			cout << "            ";

			continue;

		}

		while (true) {

			if (_kbhit()) {

				if (turn) {

					goTo(92, 11);

					cout << "            ";

				}
				else {

					goTo(7, 11);

					cout << "            ";

				}

				int input = _getch();

				if (input == 224) {

					input = _getch();

					if (input == 72) {

						y = y == 0 ? 7 : y - 1;

					}
					else if (input == 75) {

						x = x == 0 ? 7 : x - 1;

					}
					else if (input == 77) {

						x = x == 7 ? 0 : x + 1;

					}
					else if (input == 80) {

						y = y == 7 ? 0 : y + 1;

					}

					goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

				}
				else if (input == 13) {

					if (board[y][x] > 0) {

						deal();

						char text = 97 + x, num = 49 + y;

						string turnText = turn ? "白棋" : "黑棋";

						messageBox.push_back(turnText + " 落子在 " + text + num);

						message();

						break;

					}
					else {

						if (turn) {

							goTo(92, 11);

							cout << "此處無法落棋";

						}
						else {

							goTo(7, 11);

							cout << "此處無法落棋";

						}

						goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

					}

				}
				else if (input == 'u') {

					regret();

					message();

				}
				else if (input == 'r') {

					redo();

					message();

				}
				else if (input == 'e') {

					gameStatus = false;

					winner = turn ? 1 : 2;

					break;

				}
				else if (input == 'h') {

					hint = hint == true ? false : true;

					printGameInfo();

					goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

				}
				else if (input == 's') {

					restart();

					break;

				}
				else if (input == 'g') {

					if (blackTurn == 5 && !turn) {

						blackTurn = -1;

						skill();

					}
					else if (whiteTurn == 5 && turn) {

						whiteTurn = -1;

						skill();

					}
					else if ((blackTurn != 5 && !turn) || (whiteTurn != 5 && turn)) {

						int positionX = turn ? 92 : 7;

						goTo(positionX, 11);

						cout << "充能尚未完成";

					}

					goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

				}

			}

		}

		turn = 1 - turn;

	}

	counting();

	printGameInfo();

	gameOver();

}

void GameBoard::gameOver() {

	goTo(7, 9);

	cout << "                    ";

	goTo(92, 9);

	cout << "                    ";

	goTo(7, 11);

	cout << "YOU  WIN  !!!";

	goTo(92, 11);

	cout << "YOU  WIN  !!!";

	

	if (winner == 1 || blackNum > whiteNum) {

		goTo(92, 11);

		cout << "             ";

	}
	else if (winner == 2 || blackNum < whiteNum) {

		goTo(7, 11);

		cout << "             ";

	}

	replay();

}

void GameBoard::log() {

	gameRecord.push_back(board);

}

bool GameBoard::counting() {

	blackNum = 0;

	whiteNum = 0;

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			if (board[i][j] == -1) {

				blackNum++;

			}
			else if(board[i][j] == -2){

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

	int canEat[8], pass[8], eat = turn ? -1 : -2, chess = turn ? -2 : -1;

	for (int u = 0; u < 8; u++) {

		canEat[u] = 0;

		pass[u] = 0;

	}

	for (int u = 1; u < 8; u++) {

		if (x - u >= 0 && y - u >= 0 && pass[0] != -1) {

			if (board[x - u][y - u] == eat) {

				pass[0]++;

			}
			else if (board[x - u][y - u] >= 0) {

				pass[0] = -1;

			}
			else if (board[x - u][y - u] == chess) {

				if (pass[0] != 0) {

					canEat[0] = pass[0];

					pass[0] = -1;

				}
				else {

					canEat[0] = 0;

					pass[0] = -1;

				}

			}
			

		}

		if (y - u >= 0 && pass[1] != -1) {

			if (board[x][y - u] == eat) {

				pass[1]++;

			}
			else if (board[x][y - u] >= 0) {

				pass[1] = -1;

			}
			else if (board[x][y - u] == chess) {

				if (pass[1] != 0) {

					canEat[1] = pass[1];

					pass[1] = -1;

				}
				else {

					canEat[1] = 0;

					pass[1] = -1;

				}

			}

		}

		if (x + u < 8 && y - u >= 0 && pass[2] != -1) {

			if (board[x + u][y - u] == eat) {

				pass[2]++;

			}
			else if (board[x + u][y - u] >= 0) {
			
				pass[2] = -1;
			
			}
			else if(board[x + u][y - u] == chess) {

				if (pass[2] != 0) {

					canEat[2] = pass[2];

					pass[2] = -1;

				}
				else {

					canEat[2] = 0;

					pass[2] = -1;

				}

			}

		}

		if (x + u < 8 && pass[3] != -1) {

			if (board[x + u][y] == eat) {

				pass[3]++;

			}
			else if (board[x + u][y] >= 0) {

				pass[3] = -1;

			}
			else if (board[x + u][y] == chess) {

				if (pass[3] != 0) {

					canEat[3] = pass[3];

					pass[3] = -1;

				}
				else {

					canEat[3] = 0;

					pass[3] = -1;

				}

			}

		}

		if (x + u < 8 && y + u < 8 && pass[4] != -1) {

			if (board[x + u][y + u] == eat) {

				pass[4]++;

			}
			else if (board[x + u][y + u] >= 0) {

				pass[4] = -1;

			}
			else if (board[x + u][y + u] == chess) {

				if (pass[4] != 0) {

					canEat[4] = pass[4];

					pass[4] = -1;

				}
				else {

					canEat[4] = 0;

					pass[4] = -1;

				}

			}

		}

		if (y + u < 8 && pass[5] != -1) {

			if (board[x][y + u] == eat) {

				pass[5]++;

			}
			else if (board[x][y + u] >= 0) {
			
				pass[5] = -1;
 			
			}
			else if (board[x][y + u] == chess) {

				if (pass[5] != 0) {

					canEat[5] = pass[5];

					pass[5] = -1;

				}
				else {

					canEat[5] = 0;

					pass[5] = -1;

				}

			}

		}

		if (x - u >= 0 && y + u < 8 && pass[6] != -1) {

			if (board[x - u][y + u] == eat) {

				pass[6]++;

			}
			else if (board[x - u][y + u] >= 0) {

				pass[6] = -1;

			}
			else if (board[x - u][y + u] == chess) {

				if (pass[6] != 0) {

					canEat[6] = pass[6];

					pass[6] = -1;

				}
				else {

					canEat[6] = 0;

					pass[6] = -1;

				}

			}

		}

		if (x - u >= 0 && pass[7] != -1) {

			if (board[x - u][y] == eat) {

				pass[7]++;

			}
			else if (board[x - u][y] >= 0) {
			
				pass[7] = -1;
			
			}
			else if (board[x - u][y] == chess) {

				if (pass[7] != 0) {

					canEat[7] = pass[7];

					pass[7] = -1;

				}
				else {

					canEat[7] = 0;

					pass[7] = -1;

				}

			}

		}

	}

	board[x][y] = 0;

	for (int i = 0; i < 8; i++) {

		if (canEat[i] != 0) {

			board[x][y] += canEat[i];

		}

	}

	if (board[x][y] == 0) {
		
		return false;

	}
	else {

		return true;

	}

}

bool GameBoard::isPass(bool turn) {

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			if (board[i][j] > 0) {

				return false;

			}

		}

	}

	return true;

}

void GameBoard::deal() {

	int pass[8], eat = turn ? -1 : -2, chess = turn ? -2 : -1;

	for (int u = 0; u < 8; u++) {

		pass[u] = 0;

	}

	for (int u = 1; u < 8; u++) {

		if (y - u >= 0 && x - u >= 0 && pass[0] != -1) {

			if (board[y - u][x - u] == eat) {

				pass[0]++;

			}
			else if (board[y - u][x - u] == chess) {

				if (pass[0] != 0) {

					for (int i = 0; i <= pass[0]; i++) {

						board[y - i][x - i] = chess;

					}
				}

				pass[0] = -1;

			}
			else if (board[y - u][x - u] >= 0) {

				pass[0] = -1;

			}

		}

		if (x - u >= 0 && pass[1] != -1) {

			if (board[y][x - u] == eat) {

				pass[1]++;

			}
			else if (board[y][x - u] == chess) {

				if (pass[1] != 0) {

					for (int i = 0; i <= pass[1]; i++) {

						board[y][x - i] = chess;

					}

				}

				pass[1] = -1;

			}
			else if (board[y][x - u] >= 0) {

				pass[1] = -1;

			}

		}

		if (y + u < 8 && x - u >= 0 && pass[2] != -1) {

			if (board[y + u][x - u] == eat) {

				pass[2]++;

			}
			else if (board[y + u][x - u] == chess) {

				if (pass[2] != 0) {

					for (int i = 0; i <= pass[2]; i++) {

						board[y + i][x - i] = chess;

					}
				}

				pass[2] = -1;

			}
			else if (board[y + u][x - u] >= 0) {

				pass[2] = -1;

			}

		}

		if (y + u < 8 && pass[3] != -1) {

			if (board[y + u][x] == eat) {

				pass[3]++;

			}
			else if (board[y + u][x] == chess) {

				if (pass[3] != 0) {

					for (int i = 0; i <= pass[3]; i++) {

						board[y + i][x] = chess;

					}
				}

				pass[3] = -1;

			}
			else if (board[y + u][x] >= 0) {

				pass[3] = -1;

			}

		}

		if (y + u < 8 && x + u < 8 && pass[4] != -1) {

			if (board[y + u][x + u] == eat) {

				pass[4]++;

			}
			else if (board[y + u][x + u] == chess) {

				if (pass[4] != 0) {

					for (int i = 0; i <= pass[4]; i++) {

						board[y + i][x + i] = chess;

					}
				}

				pass[4] = -1;

			}
			else if (board[y + u][x + u] >= 0) {

				pass[4] = -1;

			}

		}
		
		if (x + u < 8 && pass[5] != -1) {

			if (board[y][x + u] == eat) {

				pass[5]++;

			}
			else if (board[y][x + u] == chess) {

				if (pass[5] != 0) {

					for (int i = 0; i <= pass[5]; i++) {

						board[y][x + i] = chess;

					}
				}

				pass[5] = -1;

			}
			else if (board[y][x + u] >= 0) {

				pass[5] = -1;

			}

		}

		if (y - u >= 0 && x + u < 8 && pass[6] != -1) {

			if (board[y - u][x + u] == eat) {

				pass[6]++;

			}
			else if (board[y - u][x + u] == chess) {

				if (pass[6] != 0) {

					for (int i = 0; i <= pass[6]; i++) {

						board[y - i][x + i] = chess;

					}

					pass[6] = -1;

				}

			}
			else if (board[y - u][x + u] >= 0) {

				pass[6] = -1;

			}

		}

		if (y - u >= 0 && pass[7] != -1) {

			if (board[y - u][x] == eat) {

				pass[7]++;

			}
			else if (board[y - u][x] == chess) {

				if (pass[7] != 0) {

					for (int i = 0; i <= pass[7]; i++) {

						board[y - i][x] = chess;

					}

				}

				pass[7] = -1;

			}
			else if (board[y - u][x] >= 0) {

				pass[7] = -1;
			}

		}

	}

	if (turn && whiteTurn < 5) {

		whiteTurn++;

	}
	else if (!turn && blackTurn < 5) {

		blackTurn++;

	}

}

void GameBoard::printGameInfo() {

	for (int i = 0; i < 8; i++) {

		for (int j = 0; j < 8; j++) {

			goTo(BOARD_X + j * 3, BOARD_Y + i * 2);

			if (board[i][j] == -1) {

				cout << "○"; 

			}
			else if (board[i][j] == -2) {

				cout << "●";

			}
			else if (board[i][j] > 0) {

				if (hint) {

					cout << board[i][j];

				}
				else {

					cout << "  ";

				}

			}
			else {

				cout << "  ";

			}

		}

	}

	goTo(54, 4);

	cout << setw(2) << blackNum << "  : " << setw(2) << whiteNum;

	if (blackTurn == 0) {

		goTo(5, 4);

		cout << "                         ";

	}

	if (whiteTurn == 0) {

		goTo(89, 4);

		cout << "                         ";

	}

	goTo(5, 4);

	for (int i = 0; i < blackTurn; i++) {

		if (i < 4) {

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

		}
		else {

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);

		}
		cout << "▆▆ ";

	}

	for (int i = 0; i < whiteTurn; i++) {

		goTo(108 - i * 5, 4);

		if (i < 4) {

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);

		}
		else {

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);

		}
		cout << " ▆▆";

	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	goTo(5, 6);

	cout << "         ";

	goTo(5, 6);

	for (int i = 0; i < blackChance; i++) {

		cout << "◆ ";

	}

	goTo(104, 6);
	
	cout << "         ";

	for (int i = 0; i < whiteChance; i++) {

		goTo(110 - i * 3, 6);

		cout << " ◆";

	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	if (turn == false) {

		goTo(92, 9);

		cout << "                    ";

		goTo(7, 9);

		cout << "IT'S YOUR TURN ! ! !";
	}
	else {

		goTo(7, 9);

		cout << "                    ";

		goTo(92, 9);

		cout << "IT'S YOUR TURN ! ! !";

	}

}

void GameBoard::regret() {

	if (gameRecord.size() < 3 || (turn && whiteChance == 0) || (!turn && blackChance == 0)) {

		if (turn) {
		
			goTo(92, 11);

			cout << "無法悔棋";

		}
		else {

			goTo(7, 11);

			cout << "無法悔棋";

		}

	}
	else {

		if (turn) {

			whiteChance--;

		}
		else {

			blackChance--;

		}

		tmpBoard.push_back(gameRecord[gameRecord.size() - 1]);

		gameRecord.pop_back();

		tmpBoard.push_back(gameRecord[gameRecord.size() - 1]);

		gameRecord.pop_back();

		tmpMessageBox.push_back(messageBox[messageBox.size() - 1]);

		messageBox.pop_back();

		tmpMessageBox.push_back(messageBox[messageBox.size() - 1]);

		messageBox.pop_back();

		board = gameRecord[gameRecord.size() - 1];

		printGameInfo();

	}

}

void GameBoard::redo() {

	if (tmpBoard.size() != 0) {

		for (int i = 0; i < 2; i++) {

			gameRecord.push_back(tmpBoard[tmpBoard.size() - 1]);

			tmpBoard.pop_back();

			messageBox.push_back(tmpMessageBox[tmpMessageBox.size() - 1]);

			tmpMessageBox.pop_back();

		}

		board = gameRecord[gameRecord.size() - 1];

		if (turn) {

			whiteChance++;

		}
		else {

			blackChance++;

		}

		printGameInfo();

	}
	else {

		if (turn) {

			goTo(92, 11);

			cout << "尚未悔棋";

		}
		else {

			goTo(7, 11);

			cout << "尚未悔棋";

		}

	}

}

void GameBoard::replay() {

	for (int i = 0; i < 5; i++) {

		goTo(86, 18 + 2 * i);

		cout << "                          ";

	}

	goTo(93, 20);

	cout << "是否重播賽局";

	goTo(92, 22);

	cout << "→    是    ←";

	goTo(98, 24);

	cout << "否";

	goTo(117, 29);

	int choose = 0, previous;

	while (true) {

		if (_kbhit()) {

			int input = _getch();

			if (input == 224) {

				input = _getch();

				previous = choose;

				choose = 1 - choose;

				changePointTo(92, 104, 22, choose, previous);

			}
			else if (input == 13) {

				if (choose == 0) {

					int index = 0;

					turn = false;

					printBasic();

					board = gameRecord[index++];

					printGameInfo();

					goTo(90, 20);

					cout << "Press ENTER 觀看下一步";

					goTo(117, 29);

					while (true) {

						if (_kbhit()) {

							goTo(90, 20);

							cout << "Press ENTER 觀看下一步";

							goTo(117, 29);

							int input = _getch();

							if (index >= gameRecord.size()) {

								goTo(90, 20);

								cout << "Press ENTER 回到主畫面";

								goTo(117, 29);

								while (true) {

									if (_kbhit()) {

										int input = _getch();

										if(input==13) {
										
											break;

										}

									}

								}

								break;

							}

							if (input == 13) {

								turn = 1 - turn;

								board = gameRecord[index++];

								printGameInfo();

								goTo(117, 29);

							}

						}

					}

				}

				break;

			}

		}

	}

}

void GameBoard::restart() {

	if(gameMode == 2) {

		board = selfDefineBoard;

	}
	else {

		for (int i = 0; i < 8; i++) {

			for (int j = 0; j < 8; j++) {

				board[i][j] = 0;

			}

		}

		board[3][3] = -2;

		board[3][4] = -1;

		board[4][3] = -1;

		board[4][4] = -2;

	}

	turn = true;

	hint = false;

	blackChance = 3;

	whiteChance = 3;

	blackTurn = 0;

	whiteTurn = 0;

	winner = 3;

	x = 0;

	y = 0;

	gameRecord.clear();

	tmpBoard.clear();

	messageBox.clear();

	tmpMessageBox.clear();

}

bool GameBoard::selfDefine() {

	bool chess = false;

	printBasic();

	printGameInfo();

	goTo(88, 20);

	cout << "'t' 切換要放置的棋種";

	goTo(85, 22);

	cout << "'c' 進入遊戲, 'b' 退回主畫面";

	goTo(85, 24);

	cout << "在有棋子的位置按ENTER取消放置";

	goTo(88, 26);

	cout << "當前選取的棋種為 : ○";

	goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

	while (true) {

		int input = _getch();

		if (input == 224) {

			input = _getch();

			if (input == 72) {

				y = y == 0 ? 7 : y - 1;

			}
			else if (input == 75) {

				x = x == 0 ? 7 : x - 1;

			}
			else if (input == 77) {

				x = x == 7 ? 0 : x + 1;

			}
			else if (input == 80) {

				y = y == 7 ? 0 : y + 1;

			}

			goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

		}
		else if(input == 13) {
		
			if (selfDefineBoard[y][x] != -1 || selfDefineBoard[y][x] != -2) {

				selfDefineBoard[y][x] = chess ? -2 : -1;

			}
			else {

				selfDefineBoard[y][x] = 0;

			}

			board = selfDefineBoard;

			printGameInfo();

			goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

		}
		else if (input == 't') {

			chess = chess ? false : true; 

			goTo(107, 26);

			if (chess) {

				cout << "●";

			}
			else {

				cout << "○";

			}

			goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

		}
		else if (input == 'c') {

			return true;

		}
		else if (input == 'b') {

			return false;

		}

	}

}

void GameBoard::skill() {

	int positionX = turn ? 92 : 7;

	goTo(positionX, 11);

	cout << "選擇敵方的一個棋子";

	goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

	while (true) {

		if (_kbhit()) {

			int input = _getch();

			if (input == 224) {

				input = _getch();

				if (input == 72) {

					y = y == 0 ? 7 : y - 1;

				}
				else if (input == 75) {

					x = x == 0 ? 7 : x - 1;

				}
				else if (input == 77) {

					x = x == 7 ? 0 : x + 1;

				}
				else if (input == 80) {

					y = y == 7 ? 0 : y + 1;

				}

				goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

			}
			else if (input == 13) {

				if (board[y][x] != (turn ? -1 : -2)) {

					goTo(positionX, 11);

					cout << "                  ";

					goTo(positionX, 11);

					cout << "此處無法落棋";

					goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

				}
				else {

					board[y][x] = turn ? -2 : -1;

					for (int i = 0; i < 8; i++) {

						for (int j = 0; j < 8; j++) {

							if (board[i][j] >= 0) {

								canMove(i, j);

							}

						}

					}

					goTo(positionX, 11);

					cout << "                  ";

					break;

				}
				
			}

		}

	}

	printGameInfo();

}

void GameBoard::message() {

	for (int i = 0; i < 5; i++) {

		goTo(86, 18 + 2 * i);

		cout << "                          ";

	}

	int num = messageBox.size() > 5 ? 5 : messageBox.size();

	for (int i = 0; i < num; i++) {

		goTo(86, 18 + 2 * i);

		cout << messageBox.size() + i - num + 1 << "  " << messageBox[messageBox.size() + i - num];

	}

	goTo(BOARD_X + x * 3, BOARD_Y + y * 2);

}
