#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <assert.h>



//void* my_memcpy(void* dst, const void* src, size_t num)
//{
//	void* ret = dst;
//	assert(dst);
//	assert(src);
//	while (num--)
//	{
//		*(char*)dst = *(char*)src;
//		dst = (char*)dst + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//void* my_memmove(void* dst, const void* src, size_t num)
//{
//	void* ret = dst;
//	assert(dst);
//	assert(src);
//	if (dst <= src || (char*)dst >= (char*)src + num)
//	{
//		while (num--)
//		{
//			*(char*)dst = *(char*)src;
//			dst = (char*)dst + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		dst = (char*)dst + num - 1;
//		src = (char*)src + num - 1;
//		while (num--)
//		{
//			*(char*)dst = *(char*)src;
//			dst = (char*)dst - 1;
//			src = (char*)src - 1;
//		}
//	}
//	return ret;
//}
//
//char* my_strstr(const char* str1, const char* str2)
//{
//	char* cp = (char*)str1;
//	char* s1, * s2;
//	if (!*str2) return (char*)str1;
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = (char*)str2;
//		while (*s1 && *s2 && !(*s1 - *s2))
//			s1++, s2++;
//		if (!*s2) return cp;
//		cp++;
//	}
//	return NULL;
//}
//
//char* he_strstr(const char* str1, const char* str2)
//{
//	char* cp = (char*)str1;
//	char* s1, * s2;
//	if (!*str2)
//		return((char*)str1);
//	while (*cp)
//	{
//		s1 = cp;
//		s2 = (char*)str2;
//		while (*s1 && *s2 && !(*s1 - *s2))
//			s1++, s2++;
//		if (!*s2)
//			return(cp);
//		cp++;
//	}
//	return(NULL);
//}
//
//int main()
//{
//	char str[] = "This is a simple string";
//	char* pch;
//	pch = my_strstr(str, "simple");
//	if (pch != NULL)
//		strncpy(pch, "sample", 6);
//	puts(str);
//	return 0;
//}

//int main()
//{
//	char str[] = "memmove can be very useful......";
//	my_memmove(str + 20, str + 15, 11);
//	puts(str);
//	return 0;
//}

//struct {
//	char name[40];
//	int age;
//} person, person_copy;
//
//int main()
//{
//	char myname[] = "Pierre de Fermat";
//
//	/* using memcpy to copy string: */
//	my_memcpy(person.name, myname, strlen(myname) + 1);
//	person.age = 46;
//
//	/* using memcpy to copy structure: */
//	my_memcpy(&person_copy, &person, sizeof(person));
//
//	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);
//
//	return 0;
//}

//int main()
//{
//	extern int sum(int, int);
//	extern int g_val;
//	printf("%d\n", g_val);
//	printf("%d\n", sum(10, 15));
//	return 0;
//}

//#define PRINT(FORMAT, VALUE) printf("the value of "#VALUE" is "FORMAT"\n", VALUE);
//#define ADD_TO_SUM(num, value) sum##num += value
//
//int main()
//{
//	//int i = 10;
//	//PRINT("%d", i+3);
//
//	int sum5 = 1;
//	// 作用: 给 sum5 增加 10
//	ADD_TO_SUM(5, 10);
//	printf("%d\n", sum5);
//}

//#define DEBUG_PRINT printf("file:%s\tline:%d\tdate:%s\ttime:%s\t",\
//							__FILE__, __LINE__, __DATE__, __TIME__)
//
//int main()
//{
//	DEBUG_PRINT;
//	return 0;
//}

//int check()
//{
//	union
//	{
//		int i;
//		char ch;
//	}un;
//	//un.i = 1;
//	un.i = 0x11223344;
//	un.ch = 0x55;
//	return un.ch;
//}
//
//int main()
//{
//	int ret = check();
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
//	//一维数组
//	//int a[] = { 1,2,3,4 };
//	//printf("%d\n", sizeof(a));
//	//printf("%d\n", sizeof(a + 0));
//	//printf("%d\n", sizeof(*a));
//	//printf("%d\n", sizeof(a + 1));
//	//printf("%d\n", sizeof(a[1]));
//	//printf("%d\n", sizeof(&a));
//	//printf("%d\n", sizeof(*&a));
//	//printf("%d\n", sizeof(&a + 1));
//	//printf("%d\n", sizeof(&a[0]));
//	//printf("%d\n", sizeof(&a[0] + 1));
//
//	//字符数组
//	char arr[] = { 'a','b','c','d','e','f' };
//	//printf("%d\n", sizeof(arr));
//	//printf("%d\n", sizeof(arr + 0));
//	//printf("%d\n", sizeof(*arr));
//	//printf("%d\n", sizeof(arr[1]));
//	//printf("%d\n", sizeof(&arr));
//	//printf("%d\n", sizeof(&arr + 1));
//	//printf("%d\n", sizeof(&arr[0] + 1));
//	printf("%d\n", strlen(arr));
//	printf("%d\n", strlen(arr + 0));
//	//printf("%d\n", strlen(*arr));
//	printf("%d\n", strlen(arr[1]));
//	printf("%d\n", strlen(&arr));
//	printf("%d\n", strlen(&arr + 1));
//	printf("%d\n", strlen(&arr[0] + 1));
//}

////由于还没学习结构体，这里告知结构体的大小是20个字节
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
////已知，结构体Test类型的变量大小是20个字节
//int main()
//{
//	printf("%p\n", p);
//	printf("%p\n", p + 0x1);
//	printf("%p\n", (unsigned long)p + 0x1);
//	printf("%p\n", (unsigned int*)p + 0x1);
//	return 0;
//}

//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d, %d", *(a + 1), *(ptr - 1));
//	return 0;
//}
////程序的结果是什么？

//int main()
//{
//	void (*pFunc)();
//	return 0;
//}

//
//void printArr(int(*pArr)[5], int row, int col)
//{
//	for (int i = 0; i < row; i++)
//	{
//		for (int j = 0; j < col; j++)
//		{
//			printf("%d ", pArr[i][j]);
//		}
//		printf("\n");
//	}
//}
//
//int main()
//{
//	int arr[3][5] = { 1,2,3,4,5,6,7,8,9,10 };
//	printArr(arr, 3, 5);
//
//	return 0;
//}