#include <vector>
#include <conio.h>
#include <iomanip>
#include <cmath>
#include <time.h>
#include "print.h"
using namespace std;

class GameBoard {

public:

	GameBoard();

	void gameStart(int mode);

	void gameOver();

	void log();

	bool counting();

	bool canMove(int x, int y);

	bool isPass(bool turn);

	void deal();

	void printGameInfo();

	void regret();

	void redo();

	void replay();

	void restart();

	bool selfDefine();

	void skill();

	void message();

private:

	bool turn;

	bool hint;

	bool gameStatus;

	int gameMode;

	int x, y;

	int winner;

	int blackNum;

	int whiteNum;

	int blackChance;

	int whiteChance;

	int blackTurn;

	int whiteTurn;

	vector<vector<vector<int>>> tmpBoard;

	vector<vector<int>> selfDefineBoard;

	vector<vector<int>> board;

	vector<vector<vector<int>>> gameRecord;

	vector<string> messageBox;

	vector<string> tmpMessageBox;

};