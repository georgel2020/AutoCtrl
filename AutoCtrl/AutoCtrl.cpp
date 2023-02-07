#include <stdio.h>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;
int main() {
	ifstream fin("AutoCtrl.txt");

	string oper;    // Command. 
	int x, y;    // Mouse X, Y. 
	int key, time;    // Keycode, time. 
	string command;    // Command line. 
	POINT p, pLast;    // Mouse position. 
	pLast.x = 0, pLast.y = 0;

	bool debug = false;

	ShowWindow(GetConsoleWindow(), SW_HIDE);    // Hide console window. 

	while (fin >> oper) {
		if (oper == "mouse" || oper == "m") {
			fin >> x >> y;
			SetCursorPos(x, y);
			GetCursorPos(&p);
			printf("Mouse Position: %d, %d", p.x, p.y);
		}
		if (oper == "mousemove" || oper == "mm") {
			fin >> x >> y;
			mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);
			GetCursorPos(&p);
			printf("Mouse Position: %d, %d", p.x, p.y);
		}
		if (oper == "mouseleft" || oper == "ml") {
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			GetCursorPos(&p);
			printf("Mouse Left Button Click: %d, %d", p.x, p.y);
		}
		if (oper == "mouseleftdouble" || oper == "mldb") {
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			GetCursorPos(&p);
			printf("Mouse Left Button Double Click: %d, %d", p.x, p.y);
		}
		if (oper == "mouseleftdown" || oper == "mld") {
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			GetCursorPos(&p);
			printf("Mouse Left Button Down: %d, %d", p.x, p.y);
		}
		if (oper == "mouseleftup" || oper == "mlu") {
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			GetCursorPos(&p);
			printf("Mouse Left Button Up: %d, %d", p.x, p.y);
		}
		if (oper == "mouseright" || oper == "mr") {
			mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			GetCursorPos(&p);
			printf("Mouse Right Button Click: %d, %d", p.x, p.y);
		}
		if (oper == "mouserightdown" || oper == "mrd") {
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			GetCursorPos(&p);
			printf("Mouse Right Button Down: %d, %d", p.x, p.y);
		}
		if (oper == "mouserightup" || oper == "mru") {
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			GetCursorPos(&p);
			printf("Mouse Right Button Up: %d, %d", p.x, p.y);
		}
		if (oper == "key" || oper == "k") {
			fin >> key;
			keybd_event(key, 0, 0, 0);
			keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
			printf("Key Press: %d", key);
		}
		if (oper == "keydown" || oper == "kd") {
			fin >> key;
			keybd_event(key, 0, 0, 0);
			printf("Key Down: %d", key);
		}
		if (oper == "keyup" || oper == "ku") {
			fin >> key;
			keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
			printf("Key Up: %d", key);
		}
		if (oper == "command" || oper == "c") {
			fin >> command;
			system(command.c_str());
			cout << "Command: " << command;
		}
		if (oper == "sleep" || oper == "s") {
			fin >> time;
			printf("Sleep: %dms", time);
			Sleep(time);
		}
		if (oper == "exit" || oper == "e") {
			return 0;
		}
		if (oper == "debug" || oper == "d") {
			break;
		}
		if (oper == "window" || oper == "w") {
			ShowWindow(GetConsoleWindow(), SW_SHOW);
			printf("Window visible");
		}
		printf("\n");
	}

	if (!debug)return 0;

	// Debug mode
	while (true) {
		GetCursorPos(&p);
		if (p.x != pLast.x || p.y != pLast.y) {
			system("cls");
			printf("Cursor Position: \nX: %d, Y: %d\n", p.x, p.y);
			Sleep(10);
			pLast = p;
		}
	}
}