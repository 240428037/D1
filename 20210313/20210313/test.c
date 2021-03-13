#include<stdio.h>


//int main()
//{
//	/*printf("%d\n", sizeof(char*));*/
//	//int a = 0x11223344;
//	//int*pa = &a;
//	//*pa = 0;
//	//char*pc = &a;
//	//*pc = 0;
//	//int n = 10;
//	//char *pc = (char*)&n;
//	//int *pi = &n;
//	//printf("%p\n",&n );
//	//printf("%p\n", pc);
//	//printf("%p\n", pc+1);
//	//printf("%p\n", pi);
//	//printf("%p\n", pi+1);
//
//
//	return 0;
//}	


//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int*p = arr;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", *p);
//		p = p + 1;
//	}
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	printf("%d\n", &arr[0] - &arr[9]);
//	return 0;
//
//}


//int my_strlen(char*str)
//{
//	char* start = str;
//	char* end = str;
//	while (*end != '\0')
//	{
//		end++;
//	}
//	return end - start;
//}
//int main()
//{
//	char arr[] = "bit";
//	int len = my_strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	printf("%p\n", arr);
//	printf("%p\n", &arr[0]);
//	printf("%p\n", &arr);
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr[0]+1);
//	printf("%p\n", &arr+1);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int* p = arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%p ==== %p\n", p + i, &arr[i]);
//	}
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	return 0

//int main()
//{	
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	int* arr2[3] = { &a, &b, &c };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ",*(arr2[i]));
//	}
//	return 0;
//}




//指针
//
//void test(int arr[])
//{
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d", sz);
//}
//
//int main()
//{
//	/*int arr[10] = { 0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("%d ", sz);*/
//	int arr[10] = { 0 };
//	test(arr);
//	return 0;
//}

//int main()
//{
//	/*char arr[] = "abcdef";
//	char* pc = &arr;
//	printf("%s\n", arr);
//	printf("%s\n", pc);*/
//	char* ptsr = "abcdef";
//	printf("%c\n",*ptsr);
//	printf("%s\n", ptsr);
//
//	return 0;
//}


//int main()
//{
//	int arr1[] = { 1, 2, 3, 4, 5 };
//	int arr2[] = { 2, 3, 4, 5, 6 };
//	int arr3[] = { 3, 4, 5, 6, 7 };
//	int* parr[] = { arr1, arr2, arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 5; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//}

int main()
{
	//数组指针
	char* arr[5];
	char*(*pa)[5] = &arr;
	return 0;
}