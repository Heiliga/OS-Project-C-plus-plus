#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include "rlutil.h"

using namespace std;

#pragma comment (lib, "ws2_32.lib")


void main(void) 
{
	setlocale(LC_ALL, "Rus");
	rlutil::setColor(15);
	std::cout << "Добро пожаловать на Server 2." << endl;
	std::cout << "Данный сервер предоставляет информацию о свободной  памяти подкачки и общей памяти подкачки." << endl;
	std::cout << "**********************************************************************************************" << endl;
	std::cout << endl <<  endl;


	char  ClientName[30], Message[1000];
	WSAData WSADat;
	sockaddr_in sin; 
	SOCKET Sock, Client; 

	WSAStartup(0x0202,&WSADat);

	sin.sin_family = AF_INET; 
	sin.sin_addr.s_addr = 0;  
	sin.sin_port = htons(2804); 
	Sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
	bind(Sock, (sockaddr*)&sin, sizeof(sin)); 

	printf("Ожидание клиента..\n");
	
	listen(Sock, SOMAXCONN); 

	while ((Client = accept(Sock, (sockaddr*)&sin, 0)) == false) {
		Client = accept(Sock, (sockaddr*)&sin, 0); 
	}
	rlutil::setColor(2);
	printf("\nПодключение к клиенту выполнено!");
	Sleep(500);


	recv(Client, ClientName, 30, 0); 
	char buff[4096] = "";
	int bytes_recv;

	string message;
	char charMess[10000];
	char h[200];

		rlutil::setColor(9);
		sprintf(buff, "\nПолучен запрос на вывод информации от клиента - %s.", ClientName);
		std::cout << buff << endl;
		Sleep(1000);
		rlutil::setColor(15);

		MEMORYSTATUSEX s_memoryInfo;
		s_memoryInfo.dwLength = sizeof(s_memoryInfo);
		GlobalMemoryStatusEx(&s_memoryInfo);
		
		message += "\n\nРазмер файла подкачки --->  ";
		int virtVsego = s_memoryInfo.ullTotalPageFile;
		sprintf(h, "%d", virtVsego);
		message += h;
		message += "  байт";
		
		message += "\nКоличество свободных байтов файла подкачки --->  ";
		int virtFree = s_memoryInfo.ullAvailVirtual / (1024 * 1024);
		sprintf(h, "%d", virtFree);
		message += h;
		message += "  байт";


		rlutil::setColor(14);
		std::cout << message;

		strcpy(charMess, message.c_str());

		if (send(Client, charMess, strlen(charMess) + 1, 0) != SOCKET_ERROR)
		{
			printf("\n\n\nОтправлено!\n");
		}
		else
		{
			rlutil::setColor(4);
			printf("Ошибка отправки!");
			rlutil::setColor(15);
		}
		rlutil::setColor(4);

	closesocket(Sock);
	closesocket(Client);
	WSACleanup();
	_getch();
}

