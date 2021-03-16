#include<stdio.h>
#include<string.h>
#include<assert.h>
#include "stdlib.h "

//int main()
//{
//	//int len = strlen("abcdef");
//	char arr[] = { 'a', 'b', 'c', 'd' };
//	int len = strlen(arr);
//	printf("%d\n", len);
//	return 0;
//}


//strlen

//unsigned int my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while(*str) //while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
////int main()
////{
////	int len = my_strlen("abcdef");
////	printf("%d\n", len);
////	return 0;
////}
//
//int main()
//{
//	if (my_strlen("abc") - my_strlen("abcdef")>0)
//	{
//		printf("1\n");
//	}
//	else
//	{
//		printf("2\n");
//	}
//}



//strcpy



//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (*src!='\0')
//	{
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	*dest = *src; //'\0'
//}

//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL);
//	assert(src != NULL);
//	char* ret = dest;
//	//拷贝src指向的字符串到dest指向的空间，包含'\0'
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	//返回目的空间的起始地址
//	return ret;
//}
//int main()
//{
//	char arr1[] = "abcdef" ;
//	char arr2[] = "bit";
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	printf("%s\n", arr2);
//	return 0;
//}



//strcat
//char* my_strcat(char* dest, const char* src)
//{
//	char* ret = dest;
//	assert(dest != NULL);
//	assert(src);
//	//assert(dest&&src);
//
//	//1.找到目的字符串的'\0'
//	while (*dest!='\0')//(*dest)
//	{
//		dest++;
//	}
//	//2.追加
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char arr1[30] = "hello";
//	char arr2[] = "world";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}


//strcmp


//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1&&str2);
//	//比较
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1&&str2);
//	//比较
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//	return(*str1 - *str2);
//}
//int main()
//{
//	char *p1 = "abcde";
//	char *p2 = "abcd";
//	int ret = my_strcmp(p1, p2);
//	printf("ret=%d\n", ret);
//	return 0;
//}




////strncpy
//int main()
//{
//	char arr1[] = "abe";
//	char arr2[] = "hello";
//	strncpy(arr1, arr2, 6);
//	printf("%s\n", arr1);
//	system("pause");
//	return 0;
//}


//int main()
//{
//	const char* p1 = "abcdef";
//	char* p2 = "abceew";
//	int ret = strncmp(p1, p2,4);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//
//}

//strstr

//char* my_strstr(const char* p1, const char* p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	char* s1 = NULL;
//	char* s2 = NULL;
//	char* cur = (char*)p1;
//	if (*p2 == '\0')
//	{
//		return (char*)p1;
//	}
//	while (*cur)
//	{
//		s1 = cur;
//		s2 = (char*)p2;
//		if (*s1 && *s2 && *s1 == *s2)//((*s1 != '\0')&&(*s2 != '\0') && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return cur;//找到子串
//		}
//		cur++;
//	}
//	return NULL;//找不到子串
//}
//
//int main()
//{
//	char* p1 = "abcdefghi";
//	char* p2 = "cdd";
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//	{
//		printf("子串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}

//strtok

//int main()
//{
//	char arr[] = "192.168.31.121";
//	char*p = ".";
//
//	char buf[1024] = { 0 };
//	strcpy(buf, arr);
//	//切割buf中的字符串
//
//	char* ret = NULL;
//	for (ret = strtok(arr, p); ret != NULL;ret=strtok(NULL,p))
//	{
//		printf("%s\n", ret);
//	}
//
//
//	/*char*ret = strtok(arr, p);
//	printf("%s\n",ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//
//	ret = strtok(NULL, p);
//	printf("%s\n", ret);
//*/
//	system("pause");
//	return 0;
//
//}


//strerror
//#include<errno.h>
//
//int main()
//{
//	//char*str = strerror(errno);
//	//printf("%s\n",str);
//
//	FILE*pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("open file success\n");
//	}
//
//	system("pause");
//	return 0;
//} 


////#include<ctype.h>
//int main()
//{
////	int i = 0;
////	char str[] = "Test String.\n";
////	char c;
////	while (str[i])
////	{
////		c = str[i];
////		if (isupper(c))
////			c = tolower(c);
////		putchar(c);
////		i++;
////	}
//	return 0;
//}



//memecpy
//void* my_memcpy(void* dest, const void*src, size_t num)
//{
//	void* ret = dest;
//	assert(dest != NULL);
//	assert(src != NULL);
//	while (num--)
//	{
//		*(char*)dest = *(char*)src;
//		++(char*)dest;
//		++(char*)src;
//	} 
//	return ret;
//}
//int main()
//{
//	//int arr1[] = { 1, 2, 3, 4, 5 };
//	//int arr2[5] = { 0 };
//	//memcpy(arr2, arr1,sizeof(arr1));
//	struct S arr3[] = { {"张三"，20}, {"李四"，30} }
//	struct S arr4[3] = { 0 };
//	my_memcpy(arr4, arr3, sizeof(arr3));
//
//	system("pause"); 
//	return 0;   
//}


//memmove
//void* my_memmove(void* dest, const void* src, size_t num)
//{
//	void* ret = dest;
//	assert(dest&&src);
//	if (dest < src)
//	{
//		//前->后	
//		while (count--)
//		{
//			*(char*)dest = *(char*)src;
//
//		}
//	}
//	else
//	{
//		while (count--)
//		{
//			*((char*)dest + count) = *((char*)src + count);
//		}
//		//后->前
//	}
//	return ret;
//}
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//	my_memmove = (arr + 2, arr, 20);
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	system("pause");
//	return 0;
//}




//memcmp
int main()
{
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 1, 2, 5, 4, 3 };
	int ret = memcmp(arr1, arr2, 9);
	printf("%d\n", ret);
	return 0;
}


//memset
int main()
{
	char arr[10] = "";
	memset(arr, '#', 10);
	return 0;
}