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
	std::cout << "����� ���������� �� Server 2." << endl;
	std::cout << "������ ������ ������������� ���������� � ���������  ������ �������� � ����� ������ ��������." << endl;
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

	printf("�������� �������..\n");
	
	listen(Sock, SOMAXCONN); 

	while ((Client = accept(Sock, (sockaddr*)&sin, 0)) == false) {
		Client = accept(Sock, (sockaddr*)&sin, 0); 
	}
	rlutil::setColor(2);
	printf("\n����������� � ������� ���������!");
	Sleep(500);


	recv(Client, ClientName, 30, 0); 
	char buff[4096] = "";
	int bytes_recv;

	string message;
	char charMess[10000];
	char h[200];

		rlutil::setColor(9);
		sprintf(buff, "\n������� ������ �� ����� ���������� �� ������� - %s.", ClientName);
		std::cout << buff << endl;
		Sleep(1000);
		rlutil::setColor(15);

		MEMORYSTATUSEX s_memoryInfo;
		s_memoryInfo.dwLength = sizeof(s_memoryInfo);
		GlobalMemoryStatusEx(&s_memoryInfo);
		
		message += "\n\n������ ����� �������� --->  ";
		int virtVsego = s_memoryInfo.ullTotalPageFile;
		sprintf(h, "%d", virtVsego);
		message += h;
		message += "  ����";
		
		message += "\n���������� ��������� ������ ����� �������� --->  ";
		int virtFree = s_memoryInfo.ullAvailVirtual / (1024 * 1024);
		sprintf(h, "%d", virtFree);
		message += h;
		message += "  ����";


		rlutil::setColor(14);
		std::cout << message;

		strcpy(charMess, message.c_str());

		if (send(Client, charMess, strlen(charMess) + 1, 0) != SOCKET_ERROR)
		{
			printf("\n\n\n����������!\n");
		}
		else
		{
			rlutil::setColor(4);
			printf("������ ��������!");
			rlutil::setColor(15);
		}
		rlutil::setColor(4);

	closesocket(Sock);
	closesocket(Client);
	WSACleanup();
	_getch();
}

