#include "Print.h"

void printBasic() {

	system("cls");

	system("color 0f");

	goTo(5, 2);

	cout << "玩 家 一 ( 黑 棋 )";

	goTo(95, 2);

	cout << "玩 家 二 ( 白 棋 )";

	goTo(55, 2);

	cout << "比   數";

	goTo(49, 4);

	cout << "○       :       ●";

	goTo(3, 14);

	cout << "說 明";

	goTo(0, 16);

	cout << "  = = = = = = = = = = = = = = = =";

	goTo(86, 14);

	cout << "戰 況";

	goTo(85, 16);

	cout << "= = = = = = = = = = = = = = = =  ";

	goTo(3, 18);

	cout << "控制游標 : ↑←↓→";

	goTo(3, 20);

	cout << "開啟提示 : 'h'";
	
	goTo(3, 22);

	cout << "悔棋 : 'u', 三次機會";

	goTo(3, 24);

	cout << "取消悔棋 : 'r'";

	goTo(3, 26);

	cout << "重新開始 : 's'";

	goTo(3, 28);

	cout << "投降 : 'e'";

	goTo(15, 28);

	cout << "技能 : 'g', 搶奪敵方一個旗子";

	goTo(46, 8);

	cout << "  a  b  c  d  e  f  g  h ";

	goTo(45, 9);

	cout << "1                         1";

	goTo(46, 10);
	 
	cout << "   +  +  +  +  +  +  +   ";

	goTo(45, 11);

	cout << "2                         2";

	goTo(46, 12);

	cout << "   +  +  +  +  +  +  +   ";

	goTo(45, 13);

	cout << "3                         3";

	goTo(46, 14);

	cout << "   +  +  +  +  +  +  +   ";

	goTo(45, 15);

	cout << "4                         4";

	goTo(46, 16);

	cout << "   +  +  +  +  +  +  +   ";

	goTo(45, 17);

	cout << "5                         5";

	goTo(46, 18);

	cout << "   +  +  +  +  +  +  +   ";

	goTo(45, 19);

	cout << "6                         6";

	goTo(46, 20);

	cout << "   +  +  +  +  +  +  +   ";

	goTo(45, 21);

	cout << "7                         7";

	goTo(46, 22);

	cout << "   +  +  +  +  +  +  +   ";

	goTo(45, 23);

	cout << "8                         8";

	goTo(46, 24);

	cout << "  a  b  c  d  e  f  g  h ";

	goTo(117, 29);

}

void goTo(int x, int y) {

	COORD point;

	point.X = x;

	point.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);

}

void printMenu() {

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

	PlaySound(TEXT("Electro_Cabello.wav"), NULL, SND_ASYNC | SND_NODEFAULT | SND_LOOP);

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

	Sleep(5000);

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

