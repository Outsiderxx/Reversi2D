#include "GameBoard.h"
#include "Print.h"



int main() {

	GameBoard game;

	int toDo = 0, previous;

	printMenu();

	while (true) {

		if (_kbhit()) {

			int input = _getch();

			if (input == 224) {

				input = _getch();

				previous = toDo;

				if (input == 72) {

					toDo = toDo == 0 ? 3 : toDo - 1;

				}
				else if (input == 80) {

					toDo = toDo == 3 ? 0 : toDo + 1;

				}

				changePointTo(48, 66, 17, toDo, previous);

			}
			else if (input == 13) {

				if (toDo == 0) {

					game.gameStart(0);

				}
				else if (toDo == 1) {

					game.gameStart(1);

				}
				else if (toDo == 2) {

					if (game.selfDefine()) {

						game.gameStart(2);

					}

				}
				else {

					printExit();

					break;

				}

			}

		}

	}

	return 0;
}

