#include"EasyTcpServer.hpp"
#include<thread>

bool g_bRun = true;
void cmdThread()
{
	while (true)
	{
		char cmdBuf[256] = {};
		scanf("%s", cmdBuf);
		if (0 == strcmp(cmdBuf, "exit"))
		{
			g_bRun = false;
			printf("�˳�\n");
			break;
		}
		else
		{
			printf("not support cmd\n");
		}

	}

}

int main()
{
	EasyTcpServer server;
	server.InitSocket();
	server.Bind(nullptr,4567);
	server.Listen(5);
	server.Start();
		//����UI�߳�
	std::thread t1(cmdThread);
	t1.detach();//�����̷߳���
	while (g_bRun)
	{
		server.OnRun();

	}
	server.Close();
	getchar();
	return 0;
}