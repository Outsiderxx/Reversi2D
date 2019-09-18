#include "Print.h"

void printBasic() {

	



}

void goTo(int x, int y) {

	COORD point;

	point.X = x;

	point.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);

}

void printMenu() {
		
	system("mode con cols=118 lines=30");

	system("cls");

	// "http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20" ASCII art 字型產生器

	goTo(18, 6);

	cout << " ________  _______            _______  _______  _______ _________ _______  ______";

	goTo(18, 7);

	cout << "(  _____ )(  ____ \\ |\\     /|(  ____ \\(  ____ )(  ____ \\\\__   __// ___   )(  __  \\ ";

	goTo(18, 8);

	cout << "| (     )|| (    \\/ | )   ( || (    \\/| (    )|| (    \\/   ) (   \\/   )  || (  \\  )";

	goTo(18, 9);

	cout << "| (____ )|| (__     | |   | || (__    | (____)|| (_____    | |       /   )| |   ) |";

	goTo(18, 10);

	cout << "|      __)|  __)    ( (   ) )|  __)   |     __)(_____  )   | |     _/   / | |   | |";

	goTo(18, 11);

	cout << "| (\\ (   || (        \\ \\_/ / | (      | (\\ (         ) |   | |    /   _/  | |   ) |";

	goTo(18, 12);

	cout << "| ) \\ \\__|| (____/\\   \\   /  | (____/\\| ) \\ \\__/\\____) |___) (___(   (__/\\| (__/  )";

	goTo(18, 13);

	cout << "|/   \\__/ (_______/    \\_/   (_______/|/   \\__/\\_______)\\_______/\\_______/(______/";

	goTo(48, 17);

	cout << "→    玩家對戰    ←"; //48 66

	goTo(54, 19);

	cout << "電腦對戰";

	goTo(53, 21);

	cout << "自定義對戰";

	goTo(56, 23);

	cout << "離開";

	goTo(117, 29);

}

void printExit() {

	system("cls");

	// "http://patorjk.com/software/taag/#p=display&f=Graffiti&t=Type%20Something%20" ASCII art 字型產生器

	goTo(28, 10);

	cout << " _______  _______  _______  ______       ______            _______";

	goTo(28, 11);

	cout << "(  ____ \\(  ___  )(  ___  )(  __  \\     (  ___ \\ |\\     /|(  ____ \\";

	goTo(28, 12);

	cout << "| (    \\/| (   ) || (   ) || (  \\  )    | (   ) )( \\   / )| (    \\/";

	goTo(28, 13);

	cout << "| |      | |   | || |   | || |   ) |    | (__/ /  \\ (_) / | (__";

	goTo(28, 14);

	cout << "| | ____ | |   | || |   | || |   | |    |  __ (    \\   /  |  __)";

	goTo(28, 15);

	cout << "| | \\_  )| |   | || |   | || |   ) |    | (  \\ \\    ) (   | (";

	goTo(28, 16);

	cout << "| (___) || (___) || (___) || (__/  )    | )___) )   | |   | (____/\\ ";

	goTo(28, 17);

	cout << "(_______)(_______)(_______)(______/     |/ \\___/    \\_/   (_______/";
                                                                   
	goTo(117, 29);

	Sleep(2000);

}

void changePointTo(int startX,int endX, int y, int curIndex, int preIndex) {

	goTo(startX, y + 2 * preIndex);

	cout << "  ";

	goTo(endX, y + 2 * preIndex);

	cout << "  ";

	goTo(startX, y + 2 * curIndex);

	cout << "→";

	goTo(endX, y + 2 * curIndex);

	cout << "←";

	goTo(117, 29);

}