//sin.sin_port = htons(2803); // ����� ����� ������� �������
//
//Sock1 = socket(AF_INET, SOCK_STREAM, 0); // �������� ������
//
//
//printf("����������� � ������� #1...\n");
//
//if (connect(Sock1, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
//{
//	rlutil::setColor(4);
//	printf("������ ����������� � ������� #1.\n");
//	rlutil::setColor(15);
//}
//else
//{
//	send(Sock1, PCName, strlen(PCName) + 1, 0); // �������� ����� ����� ���������� (�������)
//	recv(Sock1, ServerName, 30, 0); // ��������� ����� ���������� ������� �������
//
//	rlutil::setColor(2);
//	printf("����������� � ������� #1 ���������!\n");
//	rlutil::setColor(15);
//}
//// ���� ��������� �� ������� 1
//rlutil::setColor(14);
//if (recv(Sock1, Message, 1000, 0) != SOCKET_ERROR)
//{
//	cout << Message << endl;
//	_gettch();
//	rlutil::setColor(15);
//}
//
//else
//{
//	rlutil::setColor(4);
//	printf("������ ��������� ��������� �� ������� #1!\n");
//	rlutil::setColor(15);
//}
//closesocket(Sock1);
//sin.sin_port = htons(2804); // ����� ����� ������� �������
//
//Sock2 = socket(AF_INET, SOCK_STREAM, 0); // �������� ������
//
//printf("����������� � ������� #2...\n");
//
//if (connect(Sock2, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR) {
//	rlutil::setColor(4);
//	printf("������ ����������� � ������� #2.\n");
//	rlutil::setColor(15);
//}
//else
//{
//	send(Sock2, PCName, strlen(PCName) + 1, 0); // �������� ����� ����� ���������� (�������)
//	recv(Sock2, ServerName, 30, 0); // ��������� ����� ���������� ������� �������
//
//	rlutil::setColor(2);
//	printf("����������� � ������� #2 ���������!\n");
//}
//// ���� ��������� �� ������� �������
//rlutil::setColor(15);
//if (recv(Sock2, Message, 1000, 0) != SOCKET_ERROR)
//{
//	rlutil::setColor(5);
//	cout << Message << endl;
//	_gettch();
//	rlutil::setColor(15);
//}
//else
//rlutil::setColor(4);
//printf("������ ��������� ��������� �� ������� #2!\n");
//rlutil::setColor(15);
//closesocket(Sock2);
//break;