#include<stdio.h>


//void test()
//{
//	printf("hehe\n");
//}
//int main()
//{
//	test();
//	return 0;
//}

//int main()
//{
//	int a = 1;
//	int* p = &a;
//	//char* p = (char*)&a;
//	if (*p == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//int check_sys()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}


//int check_sys()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	return *p;
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//int check_sys()
//{
//	int a = 1;
//	return(*(char*)&a);
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d,b=%d,c=%d", a, b, c);
//	return 0;
//}

int main()
{
	char a = 128;
	printf("%u\n", a);
	/*unsigned int i;
	for (i = 9; i >= 0; i--)
	{
	printf("%u\n", i);
	}*//*
	unsigned int a = -10;
	printf("%d\n", a);*/

	return 0;
}