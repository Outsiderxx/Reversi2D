#include <vector>
#include <conio.h>
using namespace std;

class GameBoard {

public:

	GameBoard();

	void gameStart(int mode);

	int gameOver();

	void log();

	bool counting();

	bool canMove(int x, int y);

	bool isPass(bool turn);

	bool up();

	bool down();

	bool left();

	bool right();

	void deal();

	void printBoard();

	int regret();

	bool redo();

	void replay();

	void restart();

	bool selfDefine();

	bool getTurn();

	void setTurn(bool turn);

	int getX();

	int getY();

private:

	bool turn;

	bool hint;

	bool gameStatus;

	int gameMode;

	int x, y;

	int blackNum;

	int whiteNum;

	int blackChance;

	int whiteChance;

	vector<vector<int>> board;

	vector<vector<vector<int>>> gameRecord;

};