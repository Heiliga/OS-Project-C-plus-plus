#include <windows.h>
#include<iostream>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#include <LM.h>
#include <string>
#include <stdio.h>
#include "rlutil.h"


using namespace std;

#pragma comment (lib, "ws2_32.lib")


void main(void) 

{
	rlutil::setColor(15);
	setlocale(LC_ALL, "rus");


	cout << "����� ���������� �� Server 1." << endl;
	cout << "������ ������ ������������� ���������� � ��������� �������� ��." << endl;
	cout << "**********************************************************************************************" << endl;
	cout << endl << endl;

	char Message[1000];
	char ClientName[30];
	char GetSystemMetrics_1[30];
	char GetSystemMetrics_2[30];
	WSAData WSADat; // �������� WinSock (��������� ������� WSAStartup)
	sockaddr_in sin;
	SOCKET Sock, Client; 

	WSAStartup(0x0202,&WSADat); // ������������� WinSock
								// 0x0202 - ������ WinSock. ����� ���� 1.0, 1.1, 2.0, 2.2
								// WSADat - ���������, ���� ����� �������� ���. �������������


	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = 0; 
	sin.sin_port = htons(2803); 
	Sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
	bind(Sock, (sockaddr*)&sin, sizeof(sin)); 


	listen(Sock, SOMAXCONN);

	printf("�������� �������..\n");

	while((Client = accept(Sock, (sockaddr*)&sin, 0)) == false){
		Client = accept(Sock, (sockaddr*)&sin, 0); 
	}
	rlutil::setColor(2);
	printf("\n����������� � ������� ���������!");
	Sleep(500);
	string message;
	recv(Client, GetSystemMetrics_1, 30, 0); 
	recv(Client, GetSystemMetrics_2, 30, 0); 
	recv(Client, ClientName, 30, 0);

	char buff[4096] = "";
	char charMess[10000];
	char h[100];


	rlutil::setColor(9);
	sprintf(buff, "\n������� ������ �� ����� ���������� �� ������� - %s.", ClientName);
	std::cout << buff << endl;
	Sleep(1000);
	rlutil::setColor(15);

	message += "\n\n���������� ������ ���� --->  ";
	sprintf(h, "%d", GetSystemMetrics_1);
	message += h;�


	message += "\n���� �� ������ ��������� --->  ";
	GetSystemMetrics_2 ? sprintf(h, "%s", "��") : sprintf(h, "%s","���");
	message += h;


	strcpy(charMess, message.c_str());

	rlutil::setColor(3);
	std::cout << message;

	if (send(Client, charMess, strlen(charMess) + 1, 0) != SOCKET_ERROR)
		printf("\n\n\n����������!\n");
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

