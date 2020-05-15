#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#include "rlutil.h"


using namespace std;


#pragma comment (lib, "ws2_32.lib")

int main()
{

	char PCName[30];
	rlutil::setColor(15);
	setlocale(LC_ALL, "Rus");

	char  Message[1000], IP[16] = { 0 };
	char GetSystemMetrics_1[17] = "SM_CMOUSEBUTTOMS";
	char GetSystemMetrics_2[21] = "SM_MOUSEWHEELPRESENT";

	WSAData WSADat; 
	sockaddr_in sin; 
	SOCKET Sock1; 
	SOCKET Sock2; 

	WSAStartup(0x0202, &WSADat);
	gethostname(PCName, 30);

	sin.sin_family = AF_INET; 
	sin.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	
	char buff[4096];

	int ChooseServer = 0;
	do 
	{
		cout << endl << "\tКЛИЕНТ \n\tВыберите действие " << endl
			<< "1: Вывести информацию о системных метриках (server_1)" << endl
			<< "2: Вывести информацию о памяти (server_2)" << endl
			<< "3: Отключиться от серверов и выйти." << endl
			<< "Выбор: ";

		cin >> ChooseServer;
		cout << endl;

		switch (ChooseServer)
		{

			case 1:
			{
				sin.sin_port = htons(2803); 

				Sock1 = socket(AF_INET, SOCK_STREAM, 0); 


				printf("Подключение к серверу #1...\n");
				Sleep(1000);

				if (connect(Sock1, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
				{
					rlutil::setColor(4);
					printf("Ошибка подключения к серверу #1.\n");
					rlutil::setColor(15);
				}
				else
				{
					rlutil::setColor(2);
					printf("Подключение к серверу #1 выполнено!\n");
					rlutil::setColor(15);
					Sleep(500);
					send(Sock1, GetSystemMetrics_1, strlen(GetSystemMetrics_1) + 1, 0); // Отправка имени этого компьютера (клиента)
					send(Sock1, GetSystemMetrics_2, strlen(GetSystemMetrics_2) + 1, 0);
					send(Sock1, PCName, strlen(GetSystemMetrics_2) + 1, 0);

				}
				Sleep(1000);
				rlutil::setColor(14);
				if (recv(Sock1, Message, 1000, 0) != SOCKET_ERROR)
				{
					cout << Message << endl;
					_getch();
					rlutil::setColor(15);
				}

				else
				{
					rlutil::setColor(4);
					printf("Ошибка получения сообщения от сервера #1!\n");
					rlutil::setColor(15);
				}
				closesocket(Sock1);
				break;
			}


			case 2:
			{
				sin.sin_port = htons(2804); 

				Sock2 = socket(AF_INET, SOCK_STREAM, 0); 

				printf("Подключение к серверу #2...\n");
				Sleep(1000);

				if (connect(Sock2, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) {
					rlutil::setColor(4);
					printf("Ошибка подключения к серверу #2.\n");
					rlutil::setColor(15);
				}
				else
				{
					rlutil::setColor(2);
					printf("Подключение к серверу #2 выполнено!\n");
					Sleep(500);
					send(Sock2, PCName, strlen(PCName) + 1, 0);

				}
				Sleep(1000);
				rlutil::setColor(15);
				if (recv(Sock2, Message, 1000, 0) != SOCKET_ERROR)
				{
					rlutil::setColor(5);
					cout << Message << endl;
					_getch();
					rlutil::setColor(15);
				}
				else {
					rlutil::setColor(4);
					printf("Ошибка получения сообщения от сервера #2!\n");
				}
				rlutil::setColor(15);
				closesocket(Sock2);
				break;
			}
			case 3:
			{
				rlutil::setColor(12);
				cout << "Завершение работы.Удачи!";
				Sleep(1000);
				return 0;
			}
		}

	} while (1);

	WSACleanup();
	_getch();
}
