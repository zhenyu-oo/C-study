#include <stdio.h>
#include<stdlib.h>
//int main() {
//
//	int a = 100;
//	char ch = 'w';
//	char* p = &ch;
//	int *p1= &a;
//	printf("%p\n", &ch);
//	printf("%p\n", p);
//	printf("%d\n", *p1);
//	return 0;
//
//}
//int main() {
//	printf("%zu\n", sizeof(char*));
//	printf("%zu\n", sizeof(short*));
//    printf("%zu\n", sizeof(int*));
//	printf("%zu\n", sizeof(long*));
//	printf("%zu\n", sizeof(float*));
//	return 0;
//}

//指针类型会影响指针解引用时的权限，也就是操作字节数目的不同；
//int main() {
//	int a = 0x1234;
//	int b = 0x3334;
//	printf("%x\n", a);
//	printf("%x\n", b);
//	int* p = &a;
//	char* p1 = &b;
//	*p = 0;
//	*p1 = 0;
//	printf("%x\n", a);
//	printf("%x\n", b);
//}
//
//int main() {
//	int a = 0x11223344;
//	int* pa = &a;
//	char* pc = &a;
//	//int类型跳过4个字节，char类型跳过一个字节
//	printf("pa =%p\n", pa);
//	printf("pa+1 =%p\n", pa + 1);
//	printf("pc =%p\n", pc);
//	printf("pc+1 =%p\n", pc + 1);
//	printf("*(pa+1) =%p\n", *(pa + 1));
//	printf("*(pc+1) =%p\n", *(pc + 1));
//}

//size_t my_lenth(char* p) {
//	char* star = p;
//	while (*p != '\0')
//		p++;
//	return p - star;
//}
//
//int main() {
//	//int arr[10] = "abcdefghijklmnopqrst";
//	//int* p = arr;
//	//int i = 0;
//	//for (i = 0;i < 10;i++) {
//	//	printf("%d", *p);
//	//	p++;
//	//}
//	//return 0;
//
//	char arr[] = "abcdefghijklmnopqrst";
//	size_t len = my_lenth(arr);
//	printf("%zu\n", len);
//
//	return 0;
//}


//int main() {
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int* p = arr;
//	while (p < &arr[10]) {
//		printf("%d", *p);
//		p++;
//	}
//	return 0;
//}


//对const修饰指针的理解
//int main() {
//	const int a = 10;
//	int* p = &a;
//	//在常变量中，可以再强制使用指针修改其值，但是这种行为是未定义的，可能会导致程序崩溃或者其他不可预知的行为。
//	const int* p = &a;
//	//可以修改指向，但是不可以修改指针指向的值，使其指向其他地址。
//	int* const p = &a;
//	//不能修改其指向，但是可以修改指针指向的值，使其指向的值发生改变。
//	const int* const p = &a;
//	//不能修改其指向的值，也不能修改指针本身的值。
//	*p = 100;
//	printf("%d\n", a);
//	return 0;
//}

//断言的使用
//#define NDEBUG
//#include<assert.h>
//int main() {
//	int a = 10;
//	int* p = &a;
//	assert(p != NULL);
//	printf("%d\n", *p);；
//}


//值传递和地址传递

//值传递
//swap1(int a, int b) {
//	int temp = a;
//	a = b;
//	b = temp;
//}
//
////地址传递
//swap2(int* a, int* b) {
//	int p = *a;
//	*a = *b;
//	*b = p;
//}
//
//
//int main() {
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("交换前: a =%d, b = %d\n", a, b);
//	swap1(a, b);
//	printf("值传递交换后: a =%d, b = %d\n", a, b);
//	swap2(&a, &b);
//	printf("地址交换后: a =%d, b = %d\n", a, b);
//
//	return 0;
//}


//通常情况下，数组名代表的是数组首地址，但是在两种情况下，数组名代表的是整个数组的地址：1. sizeof(数组名) 2. &数组名
//int main() {
//	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("&a[0]=%p\n", &a[0]);
//	printf("&a[0]+1=%p\n", &a[0] + 1);
//	printf("arr =%p\n", a);
//	printf("arr+1=%p\n", a + 1);
//	//&数组名代表的是整个数组的地址
//	printf("&a  =%p\n", &a);
//	printf("&a+1=%p\n", &a + 1);
//
//	//sizeof(数组名)代表的是整个数组的大小
//	int b[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	printf("sizeof(a) = %zu\n", sizeof(b));
//	printf("sizeof(b) = %zu\n", sizeof(b[0]));
//}

//一维数组传参的本质是地址
//void test(int arr[10]) {
//	//在函数中，数组名代表的是数组首地址，所以sizeof(arr)代表的是指针的大小，而不是整个数组的大小。
//	//所以这里的sizeof(arr) / sizeof(arr[0])的结果是2，而不是10。
// int sz2 = sizeof(arr) / sizeof(arr[0]);
//	printf("sz2=%d\n", sz2);
//}
//int main() {
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz1 = sizeof(arr) / sizeof(arr[0]);
//	printf("sz1=%d\n", sz1);
//	test(arr);
//	return 0;
//}

//冒泡排序
//void maopao(int* a, int n) {
//	for (int i = 0;i < n;i++) {
//		//每一轮排序都将最大的数放到最后，所以每一轮排序的次数都比上一轮少一次
//		for (int j = 0;j < n-1;j++) {
//			if (a[j] > a[j + 1]){
//				int temp = a[j];
//			    a[j] = a[j + 1];
//			    a[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main() {
//	int n = 0;
//	printf("排序所需数字个数：\n");
//	scanf("%d", &n);
//	int* a = (int *)malloc(sizeof(int) * n);//(int*)是强制转换，因为malloc返回的是泛型指针（void *)，sizeof（int)*n是需要开辟的单元大小
//	for (int i = 0;i < n;i++){
//		printf("请输入第%d个数字：\n", i+1 );
//		scanf("%d", &a[i]);
//	}
//	//排序
//	maopao(a, n);
//	printf("冒泡排序后的结果为:\n");
//	for (int i = 0;i < n;i++) {
//		printf("%d  ", a[i]);
//	}
//	free(a);//释放堆内存
//	a = NULL;//将指针变为NULL，预防野指针
//	return 0;
//}


//二级指针的使用
//int main() {
//	int a = 10;
//	int* p = &a;
//	int** pp = &p;
//	//int **pp=&p;存放的是p的地址，*pp（一次解引用）就是p，**pp（两次解引用）就是a
//}


//指针数组其实是实现了类似于二维数组的功能，但不是二维数组，二维数组是一个整体，而指针数组是一个个的指针变量组成的数组
//int main() {
//	int arr1[] = {1,2,3,4,5};
//	int arr2[] = { 2,3,4,5,6 };
//	int arr3[] = { 3,4,5,6,7 };
//	int* prr[3] = { arr1,arr2,arr3 };
//	for (int i = 0;i < 3;i++) {
//		for (int j = 0;j < 5;j++) {
//			printf("%d\n", prr[i][j]);
//		}
//	}
//	return 0;
//}


//字符指针变量
//int main() {
//	const char* ps = "abcdef";//“abcdef”是一个常量字符串，存放在常量区，ps是一个指针变量，存放的是字符串常量的首地址
//	//*ps = 'w';
//	//ps[0] = 'w';//不能修改字符串常量的值，因为字符串常量是存放在只读区的，修改只读区的值会导致程序崩溃
//	//所以一般加上cosnt修饰字符指针变量来防止修改字符串常量的值
//	printf("%c\n", *ps);
//	printf("%s\n", ps);
//
//	return 0;
//}

//int main() {
//	char str1[] = "hello world";
//	char str2[] = "hello world";
//
//	char* str3 = "hello world";
//	char* str4 = "hello world";
//
//	if (str1 == str2)
//		printf("str1 and str2 are same\n");
//	else
//		printf("str1 and str2 are different\n");
//
//	if (str3 == str4)
//		printf("str3 and str4 are same\n");
//	else
//		printf("str3 and str4 are different\n");
//	//结果是str1和str2不同，str3和str4相同，因为str1和str2是两个不同的数组，存放在栈区，而str3和str4是两个指针变量，指向的是同一个字符串常量，存放在常量区。
//	return 0;
//}

//数组指针变量
//int main() {
//	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	int (*p)[10] = &a;//p是一个指向数组的指针变量，指向的是一个包含10个int类型元素的数组)[10]
//	//p就是数组指针变量
//
//	char ch[5] = { 'a','b' };
//	char (*p1)[5] = &ch;
//	return 0;
//}


//二维数组传参的本质是指针-->数组指针变量
//void print(int(*arr)[3], int r, int j) {
//	int i = 0;
//	for (i = 0;i < r;i++) {
//		int j = 0;
//		for (j = 0;j < j;j++) {
//			printf("%d ", arr[i][j]);
//			//arr[i][j]=*(*(arr+i)+j)   *(arr+i)就是arr[i]，所以*(*(arr+i)+j)就是arr[i]偏移j,就是arr[i][j]
//			//arr[i][j]==arr[i * j + j]，因为二维数组在内存中是按行优先存储的，所以arr[i][j]就是第i行第j列的元素，arr[i * j + j]就是第i行第j列的元素
//		}
//		printf("\n");
//	}
//}
//
//int main() {
//	int arr[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
//	print(arr, 3, 4);
//	return 0;
//}

//函数名就是函数的地址，&函数名就是函数的地址，函数指针就是指向函数的指针变量
//void test() {
//	printf("hehe\n");
//}
//
//
//int main() {
//	//printf("%p\n", test);
//	//printf("%p\n", &test);
//	void (*p)() = test;
//	//p就是函数指针变量，指向的是test函数的地址
//	//void 是函数的返回值类型，()是函数的参数类型，*p是指针变量，p是指针变量的名字
//	int (*p1)(int, int) = NULL;
//	//p1就是函数指针变量，指向的是一个返回值类型为int，参数类型为int,int的函数的地址
//	return 0;
//}

//函数指针变量的使用
//int add(int a, int b) {
//	return a + b;
//}
//
//int main() {
//	int (*p)(int, int) = add;
//	int r = (*p)(10, 20);
//	printf("%d", r);
//	return 0;
//}

//int main() {
//	( *(void(*)())0)();
//	//void(*p)()是函数变量指针，void(*)()是一个函数指针类型,0是int类型，(void(*)())0是将0强制转换为一个函数指针类型，然后解引用这个函数指针并调用它。
//	//这行代码的意思是将0强制转换为一个函数指针类型，然后解引用这个函数指针并调用它。也就是说，这行代码试图调用地址为0的函数。
//	void(*signal(int, void(*)(int)))(int);
//	//signal是一个参数为int和一个函数指针，返回值为一个函数指针的函数。这个函数的作用是注册一个信号处理函数，当指定的信号发生时，调用指定的信号处理函数。
//	//这个只是一个函数的声明，并没有定义这个函数的实现。
//}


//typedef的使用与define的区别
//#define dpint int*  //define是一个预处理指令，定义了一个宏pint，代表的是int*类型
//typedef int* pint;
//typedef int (*ptr)(int ,int );
//int main() {
//	int* p1, p2;
//	//p1是一个指针变量，p2是一个int类型的变量。因为在C语言中，*的优先级比,低，所以*p1是一个指针变量，p2是一个int类型的变量。
//	dpint p3, p4;
//	//p3是一个指针变量，p4是一个int类型的变量。因为define只是一个预处理指令，在编译时会被替换为int*，所以p3是一个指针变量，p4是一个int类型的变量。
//	//p3和p4都是指针变量
//	pint p5, p6;
//	//p5和p6都是指针变量，因为pint是一个类型别名，代表的是int*类型，所以p5和p6都是int*类型的变量。
//}

//int add(int a, int b) {
//	return a + b;
//}
//
//typedef int (*pdf)(int, int);
//int main() {
//	int (*ptr1)(int, int) = add;
//	pdf ptr2 = add;
//	//这两个指针变量都是指向add函数的指针变量，
//	return 0;
//}

//实现计算器
// //(冗余版本）
//int sub(int x, int y) {
//	return x - y;
//}
//int add(int x, int y) {
//	return x + y;
//}
//int mul(int x, int y) {
//	return x * y;
//}
//int sdiv(int x, int y) {
//	return x / y;
//}
//void menu() {
//	printf("*************************\n");
//	printf("***** 1.add 2.sub *****\n");
//	printf("***** 3.mul 4.div *****\n");
//	printf("***** 0.exit **********\n");
//	printf("*************************\n");
//}
//int main() {
//	int x = 0;
//	int y = 0;
//	int r = 0;
//	int input = 0;
//  int (*arr[4])(int, int) = { add,sub,mul,sdiv };
//	//其实就是在函数指针上加上了数组的概念，arr是一个函数指针数组，里面存放的是4个函数指针，分别指向add、sub、mul、div函数。
//	do {
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		switch (input) {
//		case 1:
//			printf("请输入两个操作数:");
//			scanf("%d%d", &x, &y);
//			r = add(x, y);
//			printf("%d + %d = %d\n", x, y, r);
//			break;
//		case 2:
//			printf("请输入两个操作数:");
//			scanf("%d%d", &x, &y);
//			r = sub(x, y);
//			printf("%d - %d = %d\n", x, y, r);
//			break;
//		case 3:
//			printf("请输入两个操作数:");
//			scanf("%d%d", &x, &y);
//			r = mul(x, y);
//			printf("%d * %d = %d\n", x, y, r);
//			break;
//		case 4:
//			printf("请输入两个操作数:");
//			scanf("%d%d", &x, &y);
//			r = sdiv(x, y);
//			printf("%d / %d = %d\n", x, y, r);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//函数指针数组--实现计算器
//int sub(int x, int y) {
//	return x - y;
//}
//int add(int x, int y) {
//	return x + y;
//}
//int mul(int x, int y) {
//	return x * y;
//}
//int sdiv(int x, int y) {
//	return x / y;
//}
//void menu() {
//	printf("*************************\n");
//	printf("***** 1.add 2.sub *****\n");
//	printf("***** 3.mul 4.div *****\n");
//	printf("***** 0.exit **********\n");
//	printf("*************************\n");
//}
//int main() {
//	int x = 0;
//	int y = 0;
//	int r = 0;
//	int input = 0;
//	//其实就是在函数指针上加上了数组的概念，arr是一个函数指针数组，里面存放的是4个函数指针，分别指向add、sub、mul、div函数。
//	int (*arr[4])(int, int) = { add,sub,mul,sdiv };
//	//函数指针数组---转移表
//	do {
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4) {
//			printf("请输入两个操作数:");
//			scanf("%d%d", &x, &y);
//			r = arr[input - 1](x, y);
//			printf("%d / %d = %d\n", x, y, r);
//		}
//		else if (input == 0) {
//			printf("退出程序\n");
//		}
//		else {
//			printf("输入错误，请重新输入\n");
//		}
//	} while (input);
//	return 0;
//}



//回调函数--比最初的版本更简洁
//void menu() {
//	printf("*************************\n");
//	printf("***** 1.add 2.sub *****\n");
//	printf("***** 3.mul 4.div *****\n");
//	printf("***** 0.exit **********\n");
//	printf("*************************\n");
//}
//int sub(int x, int y) {
//	return x - y;
//}
//int add(int x, int y) {
//	return x + y;
//}
//int mul(int x, int y) {
//	return x * y;
//}
//int sdiv(int x, int y) {
//	return x / y;
//}
////没有直接调用add、sub、mul、div函数，而是通过函数指针变量p来调用这些函数，add,sub,mul,div他们就是回调函数。回调函数就是通过函数指针变量来调用的函数。
//void calc(int (*p)(int, int)) {
//	int x = 0;
//	int y = 0;
//	int r = 0;
//	printf("请输入两个操作数:");
//	scanf("%d%d", &x, &y);
//	r = p(x, y);
//	printf("结果为:%d\n", r);
//}
//
//int main() {
//	int x = 0;
//	int y = 0;
//	int r = 0;
//	int input = 0;
//  int (*arr[4])(int, int) = { add,sub,mul,sdiv };
//	//其实就是在函数指针上加上了数组的概念，arr是一个函数指针数组，里面存放的是4个函数指针，分别指向add、sub、mul、div函数。
//	do {
//		menu();
//		printf("请选择：\n");
//		scanf("%d", &input);
//		switch (input) {
//		case 1:
//			calc(add);
//			break;
//		case 2:
//			calc(sub);
//			break;
//		case 3:
//			calc(mul);
//			break;
//		case 4:
//			calc(sdiv);
//			break;
//		case 0:
//			printf("退出程序\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//qsort函数（库函数）--快速排序
//一个冒泡排序函数只能排序一种类型，但qsort函数可以排序任意类型的数据，因为qsort函数是通过回调函数来实现的，回调函数就是比较函数，比较函数的参数是两个const void*类型的指针，返回值是一个int类型的值，表示两个元素的大小关系。
//void qsort(void* base,//指向要排序的数组的首地址
//	size_t num,   //要排序的元素个数
//	size_t size, //每个元素的大小
//	int (*compar)(const void*, const void*));//函数指针--应该指向一个行数，指向的这个函数用来比较base指向的数组中任意两个元素的大小关系，返回值是一个int类型的值，表示两个元素的大小关系。


//qsort函数的使用--升序
//比较，qsort自己写了交换和比较函数调用的逻辑，我们只需要写比较函数就可以了，比较函数的参数是两个const void*类型的指针，返回值是一个int类型的值，表示两个元素的大小关系。
//int cmp_int(const void* p1, const void* p2) {
//	return *(int*)p1 - *(int*)p2;
//}
//void print_arr(int* arr, int sz) {
//	for (int i = 0;i < sz;i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void test1() {
//	int arr[] = { 9,8,7,6,5,4,1,2,3,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr,sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//}
////对结构体进行比较排序
//struct stu {
//	char name[20];
//	int age;
//};
////比年龄
////int cmp_stu(const void* p1, const void* p2) {
////	return  (*(struct stu*)p1).age - (*(struct stu* )p2).age;
////}
//// 
//// 比名字
//int cmp_name(const void* p1, const void* p2) {
//	return   strcmp((*(struct stu*)p1).name ,(*(struct stu* )p2).name);
//}
//void print_arr1(struct stu* a, int sz) {
//	for (int i = 0;i < sz;i++) {
//		printf("%s  %d\n", a[i].name,a[i].age);
//	}
//	printf("\n");
//}
//void test2() {
//	struct stu a[] = {{"zhangsan",18},{"lisi",19} ,{ "wangwu",17 } ,{"xietiantian",20}};
//	int sz1 = sizeof(a) / sizeof(a[0]);
//	//qsort(a, sz1, sizeof(a[0]), cmp_stu);
//	qsort(a, sz1, sizeof(a[0]), cmp_name);
//	print_arr1(a, sz1);
//
//}
//int main() {
//	test1();
//	test2();
//	return 0;
//}


//冒泡排序模拟成qsort函数（通用排序算法）
/**
 * @brief 比较两个int整数的回调函数，用于通用排序
 * @param p1 第一个元素的地址(void*万能指针)
 * @param p2 第二个元素的地址(void*万能指针)
 * @return 大于0:p1>p2；等于0相等；小于0:p1<p2
 */
//int cmp_int(const void* p1, const void* p2) {
//	// void*不能直接解引用，强制转为int*，再取内容做减法
//	return *(int*)p1 - *(int*)p2;
//}
//
///**
// * @brief 按字节交换两块内存，实现通用交换，支持任意数据类型
// * @param buf1 待交换内存1的起始地址
// * @param buf2 待交换内存2的起始地址
// * @param width 单个元素占用多少字节
// */
//void swap(char* buf1, char* buf2, size_t width) {
//	size_t i = 0;
//	// width个字节，逐个字节交换
//	for (i = 0;i < width;i++) {
//		char tmp = *buf1;   // 取出buf1当前字节
//		*buf1 = *buf2;      // buf2字节赋值给buf1
//		*buf2 = tmp;        // tmp存的旧buf1赋值给buf2
//		buf1++;             // 指针向后移动1字节
//		buf2++;
//	}
//}
//
///**
// * @brief 打印int类型数组
// * @param arr int数组首地址
// * @param sz 数组元素个数
// */
//void print_arr(int* arr, int sz) {
//	for (int i = 0;i < sz;i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
///**
// * @brief 手写通用冒泡排序，模拟库函数qsort，支持任意类型数组
// * @param base   数组首地址，void*可以接收任意类型数组
// * @param sz     数组元素总个数
// * @param width  数组中单个元素占用字节数
// * @param cmp    函数指针：回调比较函数，由使用者提供，判断两个元素大小
// */
//void bubble(void* base, size_t sz, size_t width, int (*cmp)(const void* p1, const void* p2)) {
//	size_t i = 0;
//	// 外层循环：冒泡总轮数，最多sz‑1轮就可以完成排序
//	for (i = 0;i < sz - 1;i++) {
//		size_t j = 0;
//		// 内层循环：每一轮内部相邻元素两两对比
//		// j最大取sz‑2，保证 j+1 <= sz‑1 不越界，条件写 j < sz‑1
//		for (j = 0;j < sz - 1;j++) {
//			/*
//				1. (char*)base：转char*，实现按1字节做地址偏移
//				2. j*width：跳过前面j个元素，拿到第j个元素起始地址
//				3. cmp(元素j地址,元素j+1地址) > 0：代表前一个 > 后一个，需要交换
//				⚠️注意：> 必须写在cmp()括号外面！
//			*/
//			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {
//				// 两个元素内存地址交给swap，按字节完成交换
//				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//	}
//}
//
//void test1() {
//	int arr[] = { 9,8,7,6,5,4,1,2,3,0 };
//	// 计算数组元素总个数：总字节 / 单个元素字节
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	/*
//		调用手写bubble排序
//		参数1：数组首地址
//		参数2：元素数量
//		参数3：单个元素字节大小
//		参数4：传入比较回调函数cmp_int，告诉bubble怎么比较int
//	*/
//	bubble(arr, sz, sizeof(arr[0]), cmp_int);
//	print_arr(arr, sz);
//}
//
//int main(void)
//{
//	test1();
//	return 0;
//}


//sizeof与strlen的区别
//sizeof是操作符，他只关心操作数的内存大小，不在意类型
//strlen是库函数，它求的是‘\0’之前的字数数量，会越界，需要头文件
//int main() {
//	char arr1[] = { 'a','b','c' };//[a,b,c]
//	char arr2[] = "abc";          //[a,b,c,\0]
//	printf("%d\n", strlen(arr1));//未知数
//	printf("%d\n", strlen(arr2));//3
//
//	printf("%d\n", sizeof(arr1));//3
//	printf("%d\n", sizeof(arr2));//4
//
//	return 0;
//}


//指针的具体表现

//分清楚求得是什么类型，是整型还是地址,还是整个数组
//64位中地址占8个字节，32位中占的是4个字节
//int main() {
//	int a[] = { 1,2,3,4 };
//	printf("%zu\n", sizeof(a));//16
//	printf("%zu\n", sizeof(a+0));//4/8
//	printf("%zu\n", sizeof(*a));//4
//	printf("%zu\n", sizeof(a+1));//4/8
//	printf("%zu\n", sizeof(a[1]));//4
//	printf("%zu\n", sizeof(&a));//4/8 --&数组名是取整个数组的地址,但依然是地址
//	printf("%zu\n", sizeof(*&a));//16
//	//*&a---a
//	//&a --int(*)[4]
//	printf("%zu\n", sizeof(&a+1));//4/8
//	printf("%zu\n", sizeof(&a[0]));//4/8
//	printf("%zu\n", sizeof(&a[0]+1));//4/8
//}
//字符型
//int main() {
//	char arr[] = { 'a','b','b','d','e','f'};
//	printf("%zu\n", sizeof(arr));//6
//	printf("%zu\n", sizeof(arr + 0));//4/8
//	printf("%zu\n", sizeof(*arr));//1
//	printf("%zu\n", sizeof(arr + 1));//4/8
//	printf("%zu\n", sizeof(arr[1]));//1
//	printf("%zu\n", sizeof(&arr));//4/8
//	printf("%zu\n", sizeof(*&arr));//6
//	printf("%zu\n", sizeof(&arr + 1));//4/8
//	printf("%zu\n", sizeof(&arr[0]));//4/8
//	printf("%zu\n", sizeof(&arr[0] + 1));//4/8
//
//	return 0;
//}

//int main() {
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%zu\n", strlen(arr));//随机值，因为没有'\0';
//	printf("%zu\n", strlen(arr + 1));//随机数
//	//printf("%zu\n", strlen(*arr));//*arr=arr[0]=='a'==97，会报错，是一个野指针,strlen是接受到的是地址，不是字符，所以会找到97的地址访问，出现报错
//	//printf("%zu\n", strlen(arr[1]));//也会崩溃
//	printf("%zu\n", strlen(&arr));//随机数 x
//	printf("%zu\n", strlen(&arr+1));//随机数 x-6
//	printf("%zu\n", strlen(&arr[0]+1));//随机数
//
//	return 0;
//}

//int main() {
//	char arr[] = "abcdef";
//	printf("%zu\n", strlen(arr));//6
//	printf("%zu\n", strlen(arr + 1));//6
//	//printf("%zu\n", strlen(*arr));//*arr=arr[0]=='a'==97，会报错，是一个野指针,strlen是接受到的是地址，不是字符，所以会找到97的地址访问，出现报错
//	//printf("%zu\n", strlen(arr[1]));//崩溃
//	printf("%zu\n", strlen(&arr));//6
//	printf("%zu\n", strlen(&arr+1));//未知数
//	printf("%zu\n", strlen(&arr[0] + 1));//5
//
//	return 0;
//}

//szieof连'\0'都计算在其中
//int main() {
//	char arr[] = "abcdef";
//	printf("%zu\n", sizeof(arr));//7
//	printf("%zu\n", sizeof(arr + 0));//4/8
//	printf("%zu\n", sizeof(*arr));//1
//	printf("%zu\n", sizeof(arr + 1));//4/8--地址
//	printf("%zu\n", sizeof(arr[1]));//1
//	printf("%zu\n", sizeof(&arr));//4/8--地址
//	printf("%zu\n", sizeof(*&arr));//7
//	printf("%zu\n", sizeof(&arr + 1));//4/8
//	printf("%zu\n", sizeof(&arr[0]));//4/8
//	printf("%zu\n", sizeof(&arr[0] + 1));//4/8
//
//	return 0;
//}

//int main() {
//	char* p = "abcdef";
//	printf("%zu\n", sizeof(p));//4/8
//	printf("%zu\n", sizeof(p+1));//4/8,p+1是b的地址
//	printf("%zu\n", sizeof(*p));//1
//	printf("%zu\n", sizeof(p[0]));//1
//	//p[0] == *(p+0)=='a'
//	printf("%zu\n", sizeof(&p));//4/8
//	printf("%zu\n", sizeof(&p+1));//4/8
//	printf("%zu\n", sizeof(&p[0]+1));//4/8
//
//	return 0;
//}

//strlen与指针
//int main() {
//	char* p = "abcdef";
//	printf("%zu\n", strlen(p));//6
//	printf("%zu\n", strlen(p + 1));//5
//	printf("%zu\n", strlen(*p));//崩溃
//	printf("%zu\n", strlen(p[0]));//崩溃
//	//p[0] == *(p+0)=='a'
//	printf("%zu\n", strlen(&p));//未知数
//	printf("%zu\n", strlen(&p + 1));//未知数
//	printf("%zu\n", strlen(&p[0] + 1));//5
//
//	return 0;
//}

//sizeof与二位数组
//int main()
//{
//    int a[3][4] = { 0 };
//    printf("%zu\n", sizeof(a));//3*4*4=48
//    printf("%zu\n", sizeof(a[0][0]));//4
//    printf("%zu\n", sizeof(a[0]));//16--计算的是第一行的大小
//    printf("%zu\n", sizeof(a[0] + 1));//a[0]+1==&a[0][1],所以得到的是4/8
//    printf("%zu\n", sizeof(*(a[0] + 1)));//4
//    printf("%zu\n", sizeof(a + 1));//a其实得到的是第一行的地址，a+1得到的是第二行的地址  4/8
//    printf("%zu\n", sizeof(*(a + 1)));//16
//    printf("%zu\n", sizeof(&a[0] + 1));//&a[0]+1是第二行的地址 4/8
//    printf("%zu\n", sizeof(*(&a[0] + 1)));//16
//    printf("%zu\n", sizeof(*a));//16
//    printf("%zu\n", sizeof(a[3]));//16--不会越界
//    //a[3]-->a[0],因为sizeof不会计算的，只会查看类型，所以看到a[3]就知道 int[4]
//    return 0;
//}


//练习1
//int main()
//{
//    int a[5] = { 1, 2, 3, 4, 5 };
//    int* ptr = (int*)(&a + 1);
//    //&a取整个数组的地址
//    printf("%d,%d", *(a + 1), *(ptr - 1));
//    //2,5
//    return 0;
//}

//练习2--指针加减整数
//结构体字节数是32个字节
//内存对齐两条铁律：
//1. 每个成员，存放起始地址必须是 * *自身大小的整数倍 
//2. 结构体总大小，必须是 * *结构体最大成员大小的整数倍 
//struct Test
//{
//    int Num;
//    char* pcName;
//    short sDate;
//    char cha[2];
//    short sBa[4];
//}* p = (struct Test*)0x100000;
//
//int main()
//{
//    printf("%p\n", p + 0x1);//地址加上32个字节
//    //0x100020
//    printf("%p\n", (unsigned long)p + 0x1);//强制类型转换成整型，+1就是+1
//    //0x100001
//    printf("%p\n", (unsigned int*)p + 0x1);//强制类型转换从无符号整型指针，+1跳过一个int类型大小
//    //0x100004
//    return 0;
//}

//练习3--逗号表达式
//int main() {
//	int a[3][2] = { (0,1),(2,3),(4,5) };
//	int* p = a[0];
//	printf("%d\n", p[0]);//实际输出结果是1，因为在数组初始化时，元素用的是()，(0,1)实际是个逗号表达式，结果是1
//	//数组实际存的是1，3，5，0，0，0
//	return 0;
//}

//练习4--数组指针
//int main()
//{
//    int a[5][5];
//    int(*p)[4];   //数组指针：p指向[大小为4个int的数组]
//    p = a;
//    //传进来的是a的首地址,所以p和a指向同一个地址,但是p认为数组4个元素就是一行
//    printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//    //所以p[4][2]就相当于a[3][3]
//    //指针-指针得到的是指针和指针之间的元素个数
//    return 0;
//}


//练习5
//int main()
//{
//    int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//    int* ptr1 = (int*)(&aa + 1);
//    //解引用之后，aa的类型退化得到一个int(*)[5],
//    int* ptr2 = (int*)(*(aa + 1));//在这里的取值符号不是得到6，而是发生了数组退化了，aa[1]变成了这一行首元素的地址
//    //形容起来就是在(aa+1)之后,得到的是这一行aa[1][0]这一行数组的地址，必须解引用之后才会得到a[1][0]这个元素的地址，写了解引用后，这里的强制类型转换都可以不写
//    //*(aa+1)==aa[1]==&aa[1][0]
//    printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//    //10，5
//    return 0;
//}


//练习6
//int main()
//{
//    char* a[] = { "work", "at", "alibaba" };
//    char** pa = a;
//    pa++;
//    printf("%s\n", *pa);
//    return 0;
//}


//练习7
//int main()
//{
//    char* c[] = { "ENTER", "NEW", "POINT", "FIRST" };
//    char** cp[] = { c + 3, c + 2, c + 1, c };
//    char*** cpp = cp;
//
//    printf("%s\n", **++cpp);
//    //point
//    //cpp已经自加过了
//    printf("%s\n", *-- * ++cpp + 3);
//    //ER
//    //cpp再次自加，指向c+1，对cpp解引用，得到c+1的值，再--，得到c,对c解引用，得到ENTER,+3就是地址移动三个字符，得到ER
//    printf("%s\n", *cpp[-2] + 3);
//    //ST
//    //cpp[-2]就是*(cpp-2),得到的cpp指向c+3
//    printf("%s\n", cpp[-1][-1] + 1);
//    //*(*(cpp-1)-1)+1
//    //E
//    return 0;
//}



//字符分类函数--可以多了解
//#include<ctype.h>
//int main() {
//	int r=isdigit('3');
//	printf("%d\n", r);
//	return 0;
//}

//将字符串中的小写字母转化成大写字母
//int main() {
//	char arr[] = "I am a Student";
//	int i = 0;
//	while (arr[i]) {
//		if (islower(arr[i]))
//		{
//			arr[i] -= 32;
//		}
//		printf("%c", arr[i]);
//		i++;
//	}
//	return 0;
//}

//字符转换函数--tolower:大写变小写, toupper:小写变成大写
//int main() {
//	int r = tolower('x');
//	printf("%c\n", r);
//	putchar(r);
//
//	return 0;
//}

//int main() {
//	int r = getchar();//等价于scanf("%c",&r)
//	putchar(r);//printf("%c\n",r)
//
//	return 0;
//}

//////////////////////////////字符串相关函数////////////////////////////
// 包含头文件<string.h>
//strlen--统计字符串在\0之前的长度，返回类型是size_t,是无符号的
/*int main() {
	if (strlen("abc") - strlen("abcdef") > 0) {
		printf(">\n");
	}
	else {
		printf("<=");
	}
	//输出的结果是>，因为返回类型是无符号整数，3-6=-3，但是它会把-3转化成一个无符号整型，就是一个很大的正数，结果大于0
	//可以比较大小，非要减法的话在前面加入强制类型转换从整型，就可以正确输出
	return 0;
}*/

//strlen的模拟实现
//递归
//#include<string.h>
//size_t my_strlen(const char * s) {
//	if (*s != '\0')
//		return 1 + my_strlen(s + 1);
//	else
//		return 0;
//}
//int main() {
//	size_t len = my_strlen("abcdef");
//	printf("%zu\n", len);
//
//	return 0;
//}

//strcpy--字符串拷贝，直到\0为止，这个\0也拷贝\0
//strcpy(1,2)--把2的值拷贝给1
//#include<string.h>
//int main() {
//	char arr1[] = "abcdef";
//	char arr2[20] = { 0 };
//	//arr2 = arr1;//数组名是一个常量地址，不能这样拷贝
//	strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//
//	return 0;
//}


//strcpy模拟实现
//自己写的
//char* my_strcpy(char *arr1,char * arr2) {
//	int size = strlen(arr1);
//	for (int i = 0;i <= size;i++) {
//		arr2[i] = arr1[i];
//	}
//	return arr2;
//}
//标准
//char* my_strcpy(char* src, char* dest) {
// char* ret=dest;
// while (*src != '\0') {
//		*dest = *src;
//		dest++;
//		src++;
//	}
//  *dest='\0';\\解决了\0
//  return ret;
//}
//
//标准优化--极简版
//#include<assert.h>
//char* my_strcpy(char* src, char* dest) {
//	char* ret = dest;
//	assert(dest && src);
//	//判断是否为空指针，空就终止
//	while (*dest++ = *src++)//判断是否是\0，while判断的是赋值表达式结果对应的值
//	{
//		;
//	}
//
//	return ret;
//}
////
//int main() {
//	char arr1[] = "abcdef";
//	char arr2[20] = "------------";
//	my_strcpy(arr1, arr2);
//	printf("%s\n", arr2);
//
//	return 0;
//}

//strcat--追加
//找到目标字符串中的\0,从源字符串中拷贝数据，在目标字符串中\0的位置依次覆盖
//int main() {
//	char arr1[] = "hello word ";
//	char arr2[] = "welcome";
//	strcat(arr1, arr2);
//	printf("%s\n", arr1);
//
//	return 0;
//}

//strcat模拟实现
//#include<assert.h>
//char* my_strcat(char* dest, char* src) {
//	char* ret = dest;
//	assert(dest && src);
//	//1.找到\0
//	while(*dest) {
//		dest++;//修改指针的指向，变为了指向\0
//	}
//	//2.数据的拷贝
//	while (*dest ++ = *src++) {
//		;
//	}
//	return ret;
//}
//
//
//int main() {
//	char arr1[] = "hello word ";
//	char arr2[] = "welcome";
//	my_strcat(arr1, arr2);
//	printf("%s\n", arr1);
//
//	return 0;
//}

//strcmp--比较(针对前面相对于后面的大小）
//按照字典顺序来依次比较对应位置上的字符，直到出现不同的字符，比较出大小,
//返回类型是int，大返回正数，等于返回0，小于返回负数
//int main() {
//	char arr1[] = "helloword";
//	char arr2[] = "hellowomen";
//	char arr3[] = "helloword";
//	char arr4[] = "helloxard";
//	//不比较长度
//	int r = strcmp(arr1, arr2);
//	int s = strcmp(arr1, arr3);
//	int t = strcmp(arr1, arr4);
//	printf("%d\n", r);
//	printf("%d\n", s);
//	printf("%d\n", t);
//
//	return 0;
//}

//strcmp的模拟实现
//#include<assert.h>
//int my_strcmp(char* arr1, char* arr2) {
//	int r = 0;
//	assert(arr1 && arr2);
//	//while (*arr1++ == *arr2++) {
//	//	r=0;
//	//}
//	//不能这么写，因为这样的话，在某一个指向\0之后，跳出循环，指针还会加一，就出现了越界
//	while (*arr1 == *arr2) {
//		if (*arr1 == '\0')
//			return r;
//		arr1++;
//		arr2++;
//	}
//	if (*arr1 > *arr2) {
//		r = 1;//其实也可以写成*arr1-*arr2，毕竟存放的是ASCll码的值,strcmp的底层就是用的这样
//	}
//	else
//		r = -1;
//
//	return r;
//}
//
//
//int main() {
//	char arr1[] = "helloword";
//	char arr2[] = "hellowomen";
//	char arr3[] = "helloword";
//	char arr4[] = "helloxard";
//	int r = my_strcmp(arr1, arr2);
//	int s = my_strcmp(arr1, arr3);
//	int t = my_strcmp(arr1, arr4);
//	printf("%d\n", r);
//	printf("%d\n", s);
//	printf("%d\n", t);
//
//	return 0;
//}



//长度不受限制函数 strcpy strcat strcmp
//长度受到限制函数 strncpy strncat strncmp
//n就是他们受到的限制字符数，就代表最多只能改变n个字符

//strncpy
//它不会给你处理\0，也就是说输出的是abcdef-----
//int main() {
//	char arr1[20] = "-------------";
//	char arr2[] = "abcdef";
//	strncpy(arr1, arr2, 3);
//	printf("%s\n", arr1);
//
//	return 0;
//}
//如果n的大小大于可操作的拷贝数，那就会补\0
//int main() {
//	char arr1[20] = "-------------";
//	char arr2[] = "abc";
//	strncpy(arr1, arr2, 6);
//	printf("%s\n", arr1);
//	//输出的是abc,因为补全的是\0
//	return 0;
//}
//strcpy 函数拷贝到 \0 为止，如果目标空间不够的话，容易出现越界行为。
//strncpy 函数指定了拷贝的长度，源字符串不一定要有 \0，同时在设计参数的时候，
// 就会多一层思考：目标空间的大小是否够用，strncpy 相对 strcpy 函数更加安全。



//strncat
//会在末尾自动追加\0,因为它把追加前的\0给覆盖了，要补全
//int main() {
//	char arr1[20] = "hello";
//	char arr2[] = "wordddd";
//	strncat(arr1, arr2, 3);
//	printf("%s\n", arr1);
//	return 0;
//}


//strncmp
//int main() {
//	char arr1[20] = "abcde";
//	char arr2[] = "abcdf";
//	int r=strncmp(arr1, arr2, 4);
//	int s = strncmp(arr1, arr2, 5);
//	printf("%d\n", r);
//	printf("%d\n", s);
//	//0  -1
//	//因为给了比较字符的数量
//	return 0;
//}



/////////////////长度受限制函数的模拟实现/////////////

//1.strncpy的模拟实现
//#include<assert.h>
//char* my_strncpy(char* arr1, char* arr2, int n) {
//	char* ret = arr1;
//	assert(arr1 && arr2);
//	int i = 0;
//	while (*arr2 != '\0' && i<n) {
//		i++;
//		*arr1++ = *arr2++;
//	}
//	//n比源串长，剩余填充\0，库strncpy要做
//	while (i < n) {
//		*arr1++= '\0';
//		i++;
//	}
//	return  ret;
//}
//
//int main() {
//	char  arr1[] = "efdddghcb";
//	char arr2[] = "abcdef";
//	int n = 0;
//	and ://标签后面不能放变量声明
//	printf("请输入要拷贝的字符数：\n");
//	int red=scanf("%d", &n);
//	if (n < 0 || n > 9) {
//		printf("输入错误，请重新输入");
//		goto and;
//	}
//	my_strncpy(arr1, arr2, n);
//	printf("%s\n", arr1);
//}

//strncat的模拟实现
//#include<assert.h>
//char* my_strncat(char* arr1, char* arr2,int n) {
//	char* ret = arr1;
//	assert(arr1 && arr2);
//	while (*arr1 != '\0') {
//		arr1++;
//	}
//	int i = 0;
//	while (*arr2 != 0 && i < n) {
//		*arr1++ = *arr2++;
//		i++;
//	}
//	*arr1 = '\0';
//	return ret;
//}
//
//int main() {
//	char  arr1[100] = "abcd";
//	char  arr2[] = "adcedgg";
//	int n = 0;
//	printf("请输入需要追加的字符数:\n");
//	int res=scanf("%d", &n);
//	char * ret=my_strncat(arr1, arr2, n);
//	printf("%s", ret);
//}
//

//strncmp的模拟实现
//#include<assert.h>
//
//int my_strncmp(char* arr1, char* arr2, int n)
//{
//    assert(arr1 != NULL && arr2 != NULL);
//    if (n <= 0)
//    {
//        return 0;
//    }
//    // n个字符循环
//    while (n > 0 && *arr1 != '\0' && *arr2 != '\0')
//    {
//        if (*arr1 != *arr2)
//        {
//            // 字符不等，返回差值
//            return *arr1 - *arr2;
//        }
//        // 指针后移，待比较字符数减一
//        arr1++;
//        arr2++;
//        n--;
//    }
//    return *arr1 - *arr2;
//}
//
//int main()
//{
//    char arr1[] = "abcdef";
//    char arr2[] = "abccde";
//    int n = 0;
//    printf("请输入要比较的字符数：\n");
//    scanf("%d", &n);
//    int r = my_strncmp(arr1, arr2, n);
//    printf("结果：%d\n", r);
//    return 0;
//}

//strncmp--自己写
//#include<assert.h>
//int my_strncmp(char* arr1, char* arr2, int n) {
//	int i = 1;
//	assert(arr1 && arr2);
//	if (n <= 0)
//		return 0;
//	while (i < n && *arr1 != '\0' && *arr2 != '\0') {
//		if (*arr1 != *arr2) {
//			return *arr1 - *arr2;
//		}
//		i++;
//		arr1++;
//		arr2++;
//	}
//	return *arr1 - *arr2;
//}
//
//int main() {
//	char arr1[] = "abcedf";
//	char arr2[] = "abbced";
//	int n = 0;
//	int res = scanf("%d", &n);
//	int r = my_strncmp(arr1, arr2, n);
//	printf("%d", r);
//
//	return 0;
//}



//////////////////////
//strstr---查找子字符串（1，2）在1中能不能找到2的字符串，查找的是这个字符串出现的第一个位置
//1是指向被查找的，2是要查找的
//找到就返回第一次出现的指针，没找到返回NULL
//#include<string.h>
//int main() {
//	char arr1[] = "abcdabcd";
//	char arr2[] = "abcd";
//	char arr3[] = "adec";
//	char * p1=strstr(arr1, arr2);
//	char * p2=strstr(arr1, arr3);
//	if (p1 != NULL) {
//		printf("%s\n", p1);
//	}
//	else{
//		printf("没有找到\n");
//	}
//	if (p2 != NULL) {
//		printf("%s\n", p2);
//	}
//	else {
//		printf("没有找到\n");
//	}
//
//	return 0;
//}

//strstr的模拟实现
// 自己写的
//char* my_strstr(char* arr1, char* arr2, int size) {
//    while (*arr1 != '\0') {
//        char* p = arr1;//是为了接收改变后的指针
//        int an = size;
//        char* p2 = arr2;//an和p2是为了恢复成之前的数值
//        while (an > 0 && (*p == *p2) && *p!='\0') {
//            p++;
//            p2++;
//            an--;
//        }
//        if (an == 0) {
//            return arr1;
//        }
//        arr1++;
//    }
//    return NULL;
//}
//
//int main()
//{
//    char arr1[] = "abbbabcdabcd";
//    char arr2[] = "abcd";
//    int size = sizeof(arr2) / sizeof(arr2[0]) - 1; //减去\0
//    char* p1 = my_strstr(arr1, arr2, size);
//    if (p1 != NULL) {
//        printf("%s\n", p1);
//    }
//    else {
//        printf("没有找到\n");
//    }
//    return 0;
//}

//标准
//char* my_strstr(const char* str1, const char* str2)
//{
//    const char* s1;
//    const char* s2;
//    const char* cp = str1;
//
//    while (*cp)
//    {
//        //从cp的位置来时找str2中的字符串
//        s1 = cp;
//        s2 = str2;
//        while (*s2 && *s1 && *s1 == *s2)
//        {
//            s1++;
//            s2++;
//        }
//        if (*s2 == '\0')
//            return (char*)cp;
//        cp++;
//    }
//    return NULL;
//}


//练习
//char* my_strstr(const char* arr1, const char* arr2) {
//    char* s1;
//    char* s2;
//    char* cp = arr1;
//    while (*cp) {
//        s1 = cp;
//        s2 = arr2;
//        while (*s1 && *s2 && *s1 == *s2) {
//            s1++;
//            s2++;
//        }
//        if (*s2 == '\0')
//            return (char*)cp;
//        cp++;
//    }
//    return NULL;
//}
//
//int main()
//{
//    char arr1[] = "abbbabcdabcd";
//    char arr2[] = "abcd";
//
//    char* ret = my_strstr(arr1, arr2);
//    if (ret != NULL)
//    {
//        printf("%s\n", ret);
//    }
//    else
//    {
//        printf("没有找到\n");
//    }
//    return 0;
//}


//strtok--分割字符串
//char * strtok(char *str,const char *delim)
//delim--分割符,str是要切割的字符串地址，但只有第一次需要，后面在这个基础上再次切割传入NULL
//返回切割的子字符串的地址,多个连续分隔符视为一个
//会直接修改原始字符串，将分隔符换成'\0'，建议拷贝一份
//#include<string.h>
//int main() {
//    char arr[] = "zhangzhenyu@qq.com";
//    char* p = "@.";
//    char buf[20] = { 0 };
//    strncpy(buf, arr,20);
//    char* pr = strtok(buf, p);
//    //while (pr != NULL)   //先判断不为空再打印
//    //{
//    //    printf("%s\n", pr);
//    //    pr = strtok(NULL, p); //再取下一段
//    //}
//    //也可以写成
//    for (pr = strtok(buf, p);pr != '\0';pr = strtok(buf, p)) {
//        printf("%s", pr);
//    }
//    return 0;
//}


//strerror--通过参数的值表示错误码，得到对应的错误信息，返回这个错误信息的首地址
//只处理标准库函数产生的错误码，需要头文件string.h
//0--没有错误
//char* strerror(int errnum){}
//#include<string.h>
//int main() {
//    for (int i = 0;i < 10;i++) {
//        printf("%s\n", strerror(i));
//    }
//    return 0;
//}

//perror==strerror + printf
//#include<string.h>
//int main() {
//	for (int i = 0;i < 10;i++) {
//		perror("错误信息是：");
//	}
//	//会显示没有错误，因为它是自己拿去错误码，不会根据你的输入来显示对应错误信息
//	//因为- `perror(提示字符串)`：直接打印，内部自动拿`errno`，输出到 stderr；
//	//strerror：接收数字错误码，返回字符串指针， 不打印 。
//	return 0;
//}





/////////////////////////////内存相关函数//////////////////
//1.memcpy--内存拷贝
//不考虑内存里面存放的是什么类型的数据
//memcpy只负责拷贝不重叠的内存，重叠的内存使用memmove
//重叠就是比如将arr1中的1,2,3,4拷贝到arr1中3，4，5，6的位置，就是重叠，使用memcpy不一定实现得了
//
//#include<string.h>
//int main() {
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[20] = {0 };
//	memcpy(arr2, arr1, 40);
//	//传进来的num是字节的大小，不是字符数，因为它不考虑类型
//	for (int i = 0;i < 20;i++) {
//		printf("%d", arr2[i]);
//	}
//
//	return 0;
//}



//memmove--更强到的内存拷贝，可以处理重叠
//推荐使用memmove
//#include<string.h>
//int main() {
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	memmove(arr1+3, arr1, 16);
//	for (int i = 0;i < 10;i++) {
//		printf("%d", arr1[i]);
//	}
//
//	return 0;
//}


//memcpy的模拟实现
//#include<assert.h>
//void* my_memcpy(void* dest, void* src, size_t num) {
//	void* ret = dest;
//	assert(dest && src);
//	while (num--) {
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//	return ret;
//}
//
//
//int main() {
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int arr2[] = { 0 };
//	my_memcpy(arr2, arr1, 16);
//	for (int i = 0;i < 10;i++) {
//		printf("%d", arr1[i]);
//	}
//
//	return 0;
//}

//memmove的模拟实现
//注意拷贝的逻辑思考，多构思
//针对重叠的时候，dest和src的位置关系，它两交错之后，如果dest在src前，就是从前向后拷贝是正确的，反之，就从后向前
//#include<assert.h>
//void* my_memmove(void* dest, void* src, size_t num) {
//	void* ret = dest;
//	assert(dest && src);
//	//数组越想后的位置，地址越大，所以dest在前，是小于
//	if (dest < src) {
//		//从前往后
//		while (num--) {
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		//从后向前
//		while (num--) {
//			*((char*)dest + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
//
//
//int main() {
//	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr1+3, arr1, 16);
//	for (int i = 0;i < 10;i++) {
//		printf("%d", arr1[i]);
//	}
//
//	return 0;
//}


//memset--内存设置
//void * memset ( void * ptr, int value, size_t num );
//ptr：指针，指向要设置的内存空间，也就是存放了要设置的内存空间的起始地址。
//value：要设置的值，函数将会把 value 值转换成 unsigned char 的数据进行设置的。也就是以字节为单位来设置内存块的。
//num：要设置的内存长度，单位是字节。
//返回值：返回的是要设置的内存空间的起始地址。
#include<string.h>
//int main() {
//	char arr[] = "hello word";
//	memset(arr, 'x', 5);
//	printf("%s\n", arr);
//
//	return 0;
//}
//int main() {
//	int arr[] = { 1,2,3,4,5 };
//	memset(arr, 1, 5);
//	//原来存放的01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00 05 00 00 00
//	//改变后存放01 01 01 01 01 00 00 00 ......
//	//改变了前五个字符为01
//	for (int i = 0;i < 5;i++) {
//		printf("%d   ", arr[i]);
//	}
//	//因为是按照字节设置，所以其实只改变了地址的前五个字节为01，所以arr[0]是0x0101010101
//	
//	
//	return 0;
//}


//memcmp---内存比较

//int main() {
//	int arr1[] = { 1,2,3,4,5 };
//	int arr2[] = { 1,2,3,400,56 };
//	int r = memcmp(arr1, arr2, 13);
//	printf("%d\n", r);
//	return 0;
//}


////////////////////数据在内存中的存储/////////////////
//大小端存储
//int main() {
//	int a = 1;
//	if (*(char*)&a == 1)
//	{
//		printf("小端");
//	}
//	else
//		printf("大端");
//	return 0;
//}

//优化
//int check() {
//	int a = 1;
//	return (*(char*)&a);
//}
//int main() {
//	if(check()==1){
//	    printf("小端");
//	}
//	else
//		printf("大端");
//	return 0;
//}


//练习
//认识数据在内存的形式
//int main() {
//	char a = -1;
//	signed char b = -1;
//	//有符号数,整型提升的时候按照高位补全
//	unsigned char c = -1;
//	//无符号char 整型提升时，补0
//	printf("a=%d,b=%d,c=%d", a, b, c);
//
//	return 0;
//}

//int  main() {
//	char a = -128;
//	//1000000000000000000000000001000000
//	//1111111111111111111111111110111111
//	//1111111111111111111111111111000000
//	//1000000-a
//	printf("%u\n", a);
//	//%u是以10进制的形式，打印无符号整数
//	//1111111111111111111111111111000000
//	//因为打印的是无符号整数，所以这个补码就是原码
//	return 0;
//}

//int main() {
//	char a = 128;
//	//有符号char的取值范围是-128~127
//	//00000000000000000000000000000001000000--128的原码
//	//1000000
//	printf("%u\n", a);
// //值与-128相同
//	return 0;
//}

//取值范围的讨论
//int main() {
//	char a[1000];
//	int i;
//	for (i = 0;i < 1000;i++) {
//		a[i] = i - 1;
//	}
//	printf("%d", strlen(a));//想一想为什么是255
//	return 0;
//}


//x86环境下
//int main() {
//	int a[4] = { 1,2,3,4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//
//	printf("%x,%x", ptr1[-1], *ptr2);
//	//%x--以16进制形式打印
//	//4,20000000
//	return 0;
//}


//浮点数在内存中存储
// 浮点数不一定能够精确保存
//#include <stdio.h>
//int main()
//{
//	int n = 9;
//	float* pFloat = (float*)&n;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//
//	*pFloat = 9.0;
//	printf("n的值为：%d\n", n);
//	printf("*pFloat的值为：%f\n", *pFloat);
//	return 0;
//}

//不能精确保存的现象
//int main() {
//	if (0.1 + 0.2 == 0.3) {
//		printf("==");
//	}
//	else
//		printf("!=");
//
//	return 0;
//}

//解决这种误差
//#include<math.h>
//#define EXP 0.000001
//
////abs
////fabs
//int main() {
//	if (fabs((0.1 + 0.2) - 0.3) < EXP){
//		printf("==");
//	}
//	else{
//		printf("!=");
//	}
//
//	return 0;
//}




//////////////////自定义类型///////////////////
//结构体
//结构体的特殊声明---不完全声明

//匿名结构体类型,不要结构体标签
//struct  {
//	int a;
//	int b;
//	float x;
//}x;
//struct {
//	int a;
//	int b;
//	float x;
//}* p=&x;
//不可以成功，因为在编译器看来，他们两个是不同类型

//结构体的自引用
//struct Node {
//	int data;
//	struct Node* next;
//};


//结构体内存对齐--有空间空缺没有使用(拿空间来换时间)
//1. 结构体的第1个成员对齐到和结构体变量起始位置偏移量为0的地址处。
//2. 从第2个成员变量开始，都要对齐到某个对齐数的整数倍的地址处。
//对齐数 = 编译器默认的一个对齐数(vs默认是8，linux中gcc没有) 与 该成员变量大小的较小值。
//3. 结构体总大小为最大对齐数（结构体中每个成员变量都有一个对齐数，所有对齐数中最大的）的整数倍。
//4. 如果嵌套了结构体的情况，嵌套的结构体成员对齐到自己的成员中最大对齐数的整数倍处，
// 结构体的整体大小就是所有最大对齐数（含嵌套结构体中成员的对齐数）的整数倍。
//struct s1 {
//	char c1;
//	int i;
//	char c2;
//};
//struct s2 {
//	char c1;
//	char c2;
//	int i;
//};
//int main() {
//	//printf("%zu\n", sizeof(struct s1));
//	//printf("%zu\n", sizeof(struct s2));
//	////成员顺序会改变结构体大小
//
//
//	struct s1 s11;
//
//	//offsetof()//计算成员变量相对于起始位置的偏移量
//	printf("%d\n", offsetof(struct s1, c1));
//	printf("%d\n", offsetof(struct s1, i));
//	printf("%d\n", offsetof(struct s1, c2));
//	return 0;
//}
//在设计结构体的时候，为了节省空间，尽量让占用空间小的成员集中在一起


//修改默认对齐数
//#pragma pack()
//尽量设置成1，2，4，8，符合类型所需字节
//#pragma pack(1)
//struct s1 {
//	char c1;
//	int i;
//	char c2;
//};
//int main() {
//		printf("%zu\n", sizeof(struct s1));
//		//输出就变为了1
//		return 0;
//}


////结构体传参
//struct S
//{
//    int data[1000];
//    int num;
//};
////传值调用
//void print1(struct S t)
//{
//    int i = 0;
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", t.data[i]);
//    }
//    printf("\n");
//    printf("%d\n", t.num);
//}
////传址调用
//void printf2(struct S* ps){
//    int i = 0;
//    for (i = 0; i < 5; i++)
//    {
//        printf("%d ", ps->data[i]);
//    }
//    printf("\n");
//    printf("%d\n", ps->num);
//
//}
////首选传址调用，因为传值调用的时间和空间需要的比较大
//int main()
//{
//    struct S s = { {1,2,3,4,5}, 100 };
//    print1(s);
//    printf2(&s);
//
//    return 0;
//}


//结构体的位段
//位段：结构体的变量后跟着冒号和数字
//位指的是二进制位数，不可以超过自身类型的范围，
// 成员可以共用同一个字节，导致某些成员没有地址，无法使用scanf给值，但可以创建另一个变量来赋值
//如果指定了位段，在输入数据超过可位段可接收范围，会被截断，如果剩余空间不够下一个变量，会直接浪费掉重新开辟空间
// 同时，这个不具备可移植性，因为开辟空间后存放的方向不确定，根据编译器处理
//struct A {
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 20;
//};
////在明确变量范围时可以使用
//
//struct B {
//	int a ;//4-32
//	int b ;//4
//	int c ;
//	int d ;
//};
//
//int main() {
//	printf("%zu\n", sizeof(struct A));
//	//输出结果是8，因为2+5+10+20=37，一个int类型是32，所以需要再加一个int类型
//	printf("%zu\n", sizeof(struct B));
//	return 0;
//}


//想一想如果是从低位到高位，从右向左（bitx-bit0)
//这个程序输出的结果是多少
//struct S {
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//
//int main() {
//	struct S s = { 0 };
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//
//	return 0;
//}

//位段慎重使用，位段的应用
//常用于网络中ip地址的传输



///////////////////////////////////联合体与枚举////////////////////////////////////////
// union
//联合体结构与结构体相同，但是联合体只为最大的成员分配空间，所有成员共用一块内存，所以也叫共用体

//union Un {
//	char c;
//	int i;
//};
//
//int main() {
//	union Un un;
//	printf("zu\n", sizeof(un));
//	printf("&un= %p\n", &un);
//	printf("&un.c= %p\n", &(un.c));
//	printf("&un= %p\n", &(un.i));
//	//地址相同，所以改一个，另一个也被改了
//
//	return 0;
//}
//

//但是联合体的空间不一定与最大的变量所需的空间相同
//联合体的大小最小与最大的变量相同
//存在对齐规则，当最大成员不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍
//union Un {
//	char a[5];// 5，但其实对齐数是1---8,1选1
//	int i;//4---8，4，选4
//	//因为5不是最大对齐数的整数呗，所以对齐到8
//};
//
//int main() {
//	union Un stm;
//	printf("%zu\n", sizeof(stm));
//
//	return 0;
//}


//联合体的应用
//比如，我们要搞一个活动，要上线一个礼品兑换单，礼品兑换单中有三种商品：图书、杯子、衬衫。
//每一种商品都有：库存量、价格、商品类型和商品类型相关的其他信息。
//图书：书名、作者、页数
//杯子：设计
//衬衫：设计、可选颜色、可选尺寸

//struct gift {
//	int number;//库存量
//	double price;//价格
//	int type;//类型
//
//	union {
//		struct {
//			char name[20];//书名
//			char author[20];//作者;
//			int num_pages;//页数
//		}book;
//		struct {
//			char desgin[30];//设计
//		}beizi;
//		struct {
//			char desgin[30];//设计
//			char color;//颜色
//			int sizes;//尺寸
//		}shirt;
//	}item;
//};


//判断机器是大端还是小端
//union Un {
//	char c;
//	int i;
//};
//int main() {
//	union Un un;
//	un.i = 1;
//	if (un.c == 1)
//		printf("小端");
//	else
//		printf("大端");
//
//}



//枚举类型---enum
//枚举顾名思义就是一一列举的
//遵守作用域的规则
//相比于#define，#define在预处理阶段，会被直接删除掉它定义的符号，没有了类型；
//枚举常量的本质是int类型，不可以定义float，char*之类的字符串；，想将枚举类型的值变为其他类型的值，可以使用字符串数组，数组下标映射
//enum SEX
//{
//	//枚举类型的可能取值 -枚举常量
//	male,//0
//	semale,//1
//	secret//2
//	//如果不给初始值，编译器默认从0开始，依次加一
//};
//
//enum Color
//{
//	red,
//	green,
//	blue
//};
//
//int main() {
//	enum Sex sex;
//	enum Color color;
//
//	printf("%d\n", male);
//	printf("%d\n", secret);
//}

//枚举有着比较强的类型检查
//如 enum SEX s=2;是不可行的
//enum SEX s=green;也是赋值为2，但是这个可以


////////////////////////////动态内存管理///////////////////////////////
//为什么要有动态内存分配
//某些所需空间大小要在程序运行时才可以知道，不方便使用提前开辟空间的方式


///////////malloc 和 free
//malloc
//开辟的空间时在堆区
//局部变量，函数参数放在栈区
//malloc，calloc等开辟的空间在堆区
//全局变量，静态变量放在静态区

//如果开辟成功了，就返回起始地址
//如果失败了，就返回一个NULL指针

//malloce的使用

//int main() {
//	//int arr[] = { 1,2,3,4,4 };//在栈区开辟20个字节的空间
//	int* p = (int*)malloc(20);//在堆区上开辟20个字节
//	if (p == NULL) {
//		perror("use malloc");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0;i < 5;i++) {
//		p[i] = i + 1;
//		printf("%d", p[i]);
//	}
//}

//free--释放空间
//free()

//比如在上个程序中，free(p),但是p变成了野指针，所以要p=NULL;



//calloc动态分配
//void * calloc(size_t num,size_t size);
//为num个大小为size的元素开辟一块空间，并且把空间的每个字节初始化为0；
//与函数malloc相比，会在返回地址前把申请的空间的每个字节初始话为全0；


//reallloc对动态开辟内存大小的调整
//void * realloc(void * ptr,size_t size);
//ptr是要调整空间的其实地址，如果ptr是NULL指针，realloc函数的功能类似于malloc
//size调整之后的新大小，单位是字节

//也是成功返回void*类型指针，但这个指针可能与原来那个不同，
//失败返回NULL

//int main() {
//	int* p = (int*)calloc(5, sizeof(int));
//	if (p == NULL) {
//		perror("use malloc");
//		return 1;
//	}
//	//使用空间
//	int i = 0;
//	for (i = 0;i < 5;i++) {
//		p[i] = i + 1;
//		printf("%d\t", p[i]);
//	}
//
//	//调整空间大小
//	int * ptr=realloc(p, 10 * sizeof(int));
//	if (ptr == NULL) {
//		perror("use realloc");
//		return 1;
//	}
//	else
//	{
//		p = ptr;//继续使用p来维护空间
//      ptr=NULL;
//	}
//	for (i = 5;i < 10;i++) {
//		p[i] = i + 1;
//		printf("%d\t", p[i]);
//	}
//
//
//	//释放
//	free(p);
//	p = NULL;
//	return 0;
//}

//在realloc扩容时
//如果后续空间足够，不会移动数据，但如果后续空间不够扩容，会连着旧内容一起搬迁到新空间，指针也被修改了；


//常见动态内存管理的错误
//1.对NULL指针的解引用操作
//2.对动态开辟空间的越界访问
//3.重复释放同一块非NULL空间
//4.忘记释放空间（内存泄露），记得标记清楚动态内存的创建


//练习、
//#include<string.h>
//void GetMemory(char* p)
//{
//	p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(str);
//	strcpy(str, "hello world");
//	printf(str);
//	//会崩溃，因为是值传递，没有修改到str，str还是NULL
//	//没有释放内存，出现内存泄露
//}
//
//int main()
//{
//	Test();
//	return 0;
//}


//修改后的版本
//#include<string.h>
//void GetMemory(char** p)
//{
//	//使用二级指针进行地址的传递
//	*p = (char*)malloc(100);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello world");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//
//int main()
//{
//	Test();
//	return 0;
//}
//


//其实也可以在使用值传递之后返回p的地址，之后用str接收p的地址，也可以做到改变



//练习2
//char* GetMemory(void)
//{
//	char p[] = "hello world";
//	return p;
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//	//不一定能够输出，因为在函数GetMemory结束之后，函数栈空间销毁，p就是一个野指针，对应的内存已经被系统释放了
//	//尽量不要返回栈空间地址
//}
//
//int main()
//{
//	Test();
//	return 0;
//}
//解决办法
//1.static
//2.动态开辟


//练习3
//void GetMemory(char** p, int num)
//{
//	*p = (char*)malloc(num);
//}
//
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	//唯一问题，没有释放内存
//}
//
//int main()
//{
//	Test();
//	return 0;
//}



//练习4
//void Test(void)
//{
//    char* str = (char*)malloc(100);
//    strcpy(str, "hello");
//    free(str);
//    //释放之后，str就是野指针，访问野指针是非法访问内存
//    //所以释放之后记得赋值为NULL;
//    if (str != NULL)
//    {
//        strcpy(str, "world");
//        printf(str);
//    }
//}
//
//int main()
//{
//    Test();
//    return 0;
//}




////////柔性数组
//在C99中，结构中的最后一个元素允许是未知大小的数组，这就叫做「柔性数组」成员。


//struct st_type
//{
//	int i;
//	int a[];//柔性数组成员
//};
//
//int main() {
//	printf("%d", sizeof(struct st_type));
//	//结果是4
//
//	return 0;
//}

//结构中的柔性数组成员前面必须至少一个其他成员。
//sizeof 返回的这种结构大小不包括柔性数组的内存。
//包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应柔性数组的预期大小。
//柔性数组有利于访问速度和减少内存碎片
//使用
//struct S
//{
//	int n;
//	int arr[];
//};
//
//int main() {
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));//24
//	if (ps == NULL) {
//		perror("use malloc");
//		return 1;
//	}
//	ps->n = 100;
//	int i = 0;
//	for (i = 0;i < 5;i++) {
//		ps->arr[i] == i + 1;
//	}
//	//扩容
//	struct S* ptr = realloc(ps, sizeof(struct S) + 10 * sizeof(int));
//	if (ptr == NULL) {
//		perror("realloc");
//	}
//	else
//	{
//		ps = ptr;
//		ptr = NULL;
//		for (i = 5;i < 10;i++) {
//			ps->arr[i] = i + 1;
//		}
//	}
//	free(ps);
//	ps = NULL;
//	return 0;
//}


//如果结构体最后一个指针类型的时候，也可以先只开辟前面变量所需空间，后面再单独开辟这一个变量的空间
//因此释放空间时先释放后面的指针变量的
//推荐使用柔性数组




////////////////////////////////////////文件操作////////////////////////
//使用文件是为了数据持久化保存
//程序每次运行结束后，数据都会回收


//文件名
//文本的区分
//按照文件功能---程序文件和数据文件
//按照数据的组织形式-----文本文件和二进制文件


//文件的打开与关闭
//流和标准流

//文件指针

//通过文件指针来操作文件


//文件的打开与关闭,打开之后必须关闭，不然会文件泄露
//打开--fopoen--FILE * fopen ( const char * filename, const char * mode );
//-返回值：`FILE*` 文件指针。打开成功返回指向文件的 FILE 结构体指针；打开失败返回`NULL`。
//- 参数 1：`const char* filename` → 文件名字符串（可以带路径），加`const`代表函数不会修改文件名。
//- 参数 2：`const char* mode` → 打开模式字符串，`const`代表不会修改模式字符串。
//关闭--fclose--int fclose ( FILE * stream );



//int main() {
//	FILE* pf = fopen("E:\\test.txt", "w+");//使用双反斜杠，因为单独一个反斜杠会被视为转义字符
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//	else {
//		printf("打开文件成功\n");
//	}
//	//写文件
//	//fputc('a', pf);
//	//fputc('b', pf);
//	//fputc('c', pf);
//	for (char ch = 'a';ch <= 'z';ch++) {
//		fputc(ch, pf);
//	}
//	//循环结束之后文件指针已经停留在文件最后面
//	// 必须挪回去
//	rewind(pf);//挪动回到文件开头
//	//读取文件
//	int ch = 0;
//	while ((ch = fgetc(pf))!= EOF)
//	{
//		printf("%c", ch);
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}



//文件的顺序读写函数
//fgetc/fputc   fgets/fputs   fscanf/fprintf   fread/fwrite


//fputc ,成功以int的形式返回写入的字符，失败返回EOF(-1)
//int fputc(int chaerater,FILE * stream);
//fputc可以在标准输出流中写入文件，也就是在屏幕上打印，不写入文件

//int main() {
//	for (char ch = 'a';ch <= 'z';ch++) {
//		fputc(ch, stdout);
//	}
//
//		return 0;
//}


//fgetc,返回的是文件指示器当前指向的字符，读取之后，自动前进，
//返回值类型是int，不要写成char ch
//EOF代表两种情况：文件尾 / 读取出错，靠 feof 和 ferror 区分
//fgetc(stdin)就是键盘读一个字符，等价 getchar()


//feof--文件末尾检测
//ferror--错误检测
// 检测到末尾或者错误，返回非0，没检测到返回0；
//int main()
//{
//	FILE* fp = fopen("E:\\test.txt", "r");
//	if (fp == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		int c = fgetc(fp);
//      printf("%d",c);
//		fputc(c, stdout); //使用fputc在标准输出流上打印字符
//	}
//
//	//不再使用文件时，需要关闭文件
//	fclose(fp);
//	fp = NULL; //将指针置为NULL,避免成为野指针。
//	return 0;
//}


//feof检测
//int main()
//{
//	FILE* fp = fopen("E:\\test.txt", "r");
//	if (fp == NULL)
//	{
//		perror("fopen\n");
//		return 1;
//	}
//	int i = 0;
//	for (i = 0; i < 30; i++)
//	{
//		int c = fgetc(fp);
//		if (c == EOF)
//		{
//			if (feof(fp))
//				printf("遇到文件末尾了\n");
//			else if (ferror(fp))
//				printf("读取发生了错误\n");
//		}
//		else
//		{
//			fputc(c, stdout); //使用fputc在标准输出流上打印字符
//		}
//	}
//
//	// 补充：关闭文件，置空指针
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}


//ferror检测
//#include <stdio.h>
////以写的形式打开文件后，再去读文件，就会发生错误
//int main()
//{
//	FILE* fp = fopen("E:\\test.txt", "w");
//	if (fp == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	int c = fgetc(fp);//读文件
//	if (c == EOF)
//	{
//		if (feof(fp))
//			printf("遇到文件末尾了\n");
//		else if (ferror(fp))
//		{
//			printf("读文件发生了错误\n");
//		}
//	}
//	else
//	{
//		fputc(c, stdout); //使用fputc在标准输出流上打印字符
//	}
//
//	//不再使用文件时，需要关闭文件
//	fclose(fp);
//	fp = NULL; //将指针置为NULL,避免成为野指针。
//	return 0;
//}


//fputs
//int fputs(const *str,FILE *stream);
//将str指向的字符串写入参数stream指向的流中（不包括\0)
//int main()
//{
//	FILE* fp = fopen("E:\\test.txt", "w");
//	if (fp == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fputs("hello", fp);
//	fputs("world", fp);
//	//结果在一行中，不会自动换行
//	//如果提前遇到了\0，会直接丢弃掉之后的内容
//
//	//不再使用文件时，需要关闭文件
//	fclose(fp);
//	fp = NULL; //将指针置为NULL,避免成为野指针。
//	return 0;
//}

//fgets
//cahr * fgets(char * str,int num, FILE * stream);
// 从stream中读取，存储到str的空间中
//停止条件三选一：碰到换行\n / EOF / 读到num - 1个字符
//num包含末尾\0，实际最多读 num - 1 个字符；会自动追加\0
//成功会读取并保存换行符\n到数组
//返回：成功返回 str；读到末尾 / 出错返回 NULL，搭配 feof、ferror 判断

//练习
//int main() {
//	FILE* pf = fopen("E:\\test.txt", "r");
//	if (pf == NULL) {
//		perror("fopen");
//		return 1;
//	}
//
//	char arr[20];
//	while (fgets(arr, 20, pf) != NULL)
//	{
//		printf("%s", arr);
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//读取到的\n也会保存着，除非超出了限制，是最后一个，那就会填\0

//fprintf
//int fprintf(FILE * stream,const char * format,...);
//格式化输出，和printf语法几乎一模一样，printf 只能输出到控制台；fprintf 可以输出到任意流（文件 / stdout）
//参数
//stream：文件流指针（文件fp或者stdout）
//format：格式化字符串， % d % s % f等格式符
//...：可变参数，对应格式符的数据
//返回值
//成功：返回写入的字符总个数（非负数）
//失败：返回负数，可用ferror()检测错误


//struct stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main() {
//	struct stu s = { "zhangsan",20,95.5f };
//
//	FILE* fp = fopen("E:\\test.txt", "w");
//	if (fp == NULL) {
//		perror("fopen");
//		return 1;
//	}
//	//写文件
//	fprintf(fp, "名字：%s 年龄：%d 成绩：%.2f\n", s.name, s.age, s.score);
//
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}

//fscanf
//int fscanf(FILE *stream,const char * format,..)
//类比scanf,但可以指定输入源
//format中需要与...中的格式匹配
//读取成功：返回成功读到、填充进变量的项数
//可能等于你预期的数量，也可能更少，甚至返回 0
//变少原因：格式不匹配、读取出错、碰到 EOF
//❌ 还没读到任何数据就遇到错误 / 文件末尾：直接返回 EOF
//读到 EOF → 设置文件结束标记，用feof()判断
//IO 读取错误 → 设置错误标记，用ferror()判断


//struct stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main() {
//	struct stu s = { 0 };
//
//	FILE* fp = fopen("E:\\test.txt", "r");
//	if (fp == NULL) {
//		perror("fopen");
//		return 1;
//	}
//	//读文件
//	fscanf(fp, "名字：%s 年龄：%d 成绩：%.2f\n", s.name, &(s.age), &(s.score));
//	fprintf(stdout, "名字：%s 年龄：%d 成绩：%.2f\n", s.name, s.age, s.score);
//
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}


//sprintf
//把数字 / 变量、结构数据，转换成字符串，存进字符数组（内存里，不碰屏幕、不碰文件）
// 返回值（考试重点）
//成功：返回 写入的字符个数，不包含末尾的 '\0' 
//失败：返回负数

//struct stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main() {
//	struct stu s = { "zhangsan",20,95.5f };
//	char arr1[30] = { 0 };
//	sprintf(arr1, "%s %d %.2f", s.name, s.age, s.score);
//	printf("%s\n", arr1);
//
//	//从arr1中解析一个结构体数据
//	//使用对应的sscanf
//	struct stu t = { 0 };
//	sscanf(arr1, "%s %d %f", t.name, &(t.age), &(t.score));
//	fprintf(stdout, "%s %d %.2f", t.name, t.age, t.score);
//
//	return 0;
//}


// 四个兄弟一次性分清（超级好记）
//1. `printf` → 输出到 屏幕控制台 stdout
//2. `fprintf` → 输出到文件流 / stdout 
//3. `sprintf` → 输出到内存字符数组（字符串）
//4. `sscanf` → 从 内存字符数组读取数据（和 sprintf 配对）


//fwrite
//以2进制形式写入，以文本格式写进去的时候可能会出现问题
//size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream );
//1. `ptr`：数据源指针（你要写出去的数据的起始地址，可以是结构体、数组）
//2. `size`： * *单个数据项的字节大小 * *
//3. `count`：要写多少个这样的数据项
//4. `stream`：文件指针
//总写入字节 = `size * count`
//返回 * *成功写入的数据项个数 * *（不是字节数！！考试高频坑）
//- 正常：返回值 == count
//- 出错：返回值 < count
//重点：文本模式 vs 二进制打开
//fwrite`是二进制读写，打开文件必须带`b`：
//
//	- `wb`：二进制只写
//	- `rb`：二进制只读
//	- `ab`：二进制追加

//struct stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main() {
//	struct stu s = { "zhangsan",20,95.5f };
//	FILE* fp = fopen("E:\\test.txt","wb");
//	if (fp == NULL) {
//		perror(fopen);
//		return 1;
//	}
//	//写文件
//	fwrite(&s, sizeof(struct stu), 1, fp);
//
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}


//fread
//size_t fread( const void * ptr, size_t size, size_t count, FILE * stream );
//从stream指向的文件流中读取数据块，并将其存储到ptr指向的内存缓冲区，需要确保文件已经以二进制可读形式打开
//struct stu
//{
//	char name[20];
//	int age;
//	float score;
//};
//
//int main()
//{
//	struct stu s_read;
//	FILE* fp = fopen("E:\\test.txt", "rb"); // rb 二进制读
//	if (fp == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fread(&s_read, sizeof(struct stu), 1, fp);
//	printf("%s %d %.2f\n", s_read.name, s_read.age, s_read.score);
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}




////////////////////文件的随机读写////////////
//fseek
//int fseek ( FILE * stream, long int offset, int origin );
//作用：移动文件内部读写光标，可以跳到文件任意位置读写
//stream：文件指针 FILE*
//offset：偏移字节数
//正数：往文件末尾方向移动
//负数：往文件开头方向移动
//0：不动
//origin：基准起点，只有 3 个宏：
//SEEK_SET：文件开头
//SEEK_CUR：光标当前位置
//SEEK_END：文件末尾
//返回值
//✅成功返回 0
//❌失败返回非 0（一般是 - 1）

//int main()
//{
//	FILE* fp = fopen("E:\\test.txt", "r"); 
//	if (fp == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int c = fgetc(fp);
//	fputc(c,stdout);
//	//fseek(fp,5, SEEK_SET);
//	fseek(fp, -5, SEEK_END);
//	c = fgetc(fp);
//	fputc(c, stdout);
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}
//注意事项
//对于二进制，fseek是准确的
// 
//但对于文本文件,fseek的行为是可能不确定的，唯一被严格保证的用法是
//将offset设置为0，origin设置为SEEK_SET
//将offset设置为ftell()的返回值（ftell返回当前指针位置）

//ftell
//二进制：ftell 返回 = 真实字节数，可读、可加减、可 fseek 任意跳转
//文本：ftell 返回 = 位置令牌，只可以原封不动还给 fseek 跳回去，不能做算术运算

//int main()
//{
//	FILE* fp = fopen("E:\\test.txt", "r");
//	if (fp == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	int c = fgetc(fp);
//	fputc(c, stdout);//a
//	
//	int pos = ftell(fp);//1
//
//	fseek(fp, 4, SEEK_CUR);
//	c = fgetc(fp);
//	fputc(c, stdout);//f
//
//	fseek(fp, pos, SEEK_SET);
//	c = fgetc(fp);
//	fputc(c, stdout);//b
//
//	fclose(fp);
//	fp = NULL;
//	return 0;
//}

//rewind
//让文件指针回到文件的起始位置
//与fseek(fp,0,SEEK_SET)相比会清除错误标志
//rewind= fseek+清理错误标志和文件标志(clearerr)


//文件缓冲区和更新文件

//文件缓冲区
//fflush
//int fflush(FILE * stream)
//强制刷新参数stream指向流的缓冲区，确保数据写入底层设备
//对输出流：将缓冲区中的数据立即写入文件
//对输入流：行为由具体实现决定
//参数是NULL的时候，会刷新所有打开的输出流

//更新文件
//"r+" "w+" "a+"
//在写完文件后，要继续读文件的时候，在读取之前一定要使用 fflush () 刷新文件缓冲区，再使用 fseek ()，rewind () 重新定位文件指示器的位置。
// 在读完文件后，需要继续写文件之前，在写文件之前，使用 fseek()，rewind() 重新定位文件指示器的位置。

//int main()
//{
//	FILE* fp = fopen("test.txt", "w+");
//	if (fp == NULL)
//	{
//		perror("fopen for w+");
//		return 1;
//	}
//	//写abcdefghi到文件中
//	fputs("abcdefghi", fp);
//	//刷新缓冲区，保证数据写入文件
//	fflush(fp);
//	//要读取数据b字符，先定位文件指针
//	fseek(fp, 1, SEEK_SET);
//	int ch = fgetc(fp);//读取字符
//	printf("%c\n", ch);
//	//在b的位置开始写入hello
//	fseek(fp, -1, SEEK_CUR);
//	//解释: 因为前面读取一个字符后,文件指示器现在指向了c,需要从当前位置退回一个字符
//	fputs("hello", fp);
//
//	//关闭文件
//	fclose(fp);
//	fp = NULL;
//
//	return 0;
//}


//////////////编译与链接//////////////////

//预处理（预编译）
//预处理（生成.i文件）做的 6 件事：
//宏展开，删掉 #define
//处理条件编译 #ifdef / #if 等
//#include 头文件递归插入
//删除全部注释
//增加行号、文件名标记（用于调试）
//保留 #pragma 指令


//编译


//汇编


//链接








//////预处理详解
//1.预定义符号（c语言设置了一些）,预处理阶段就处理了
// 常见预定义符号
//__FILE__     //进行编译的源文件
//__LINE__    //文件当前的行号
//__DATE__    //文件被编译的日期
//__TIME__    //文件被编译的时间
//__STDC__    //如果编译器遵循ANSI C，其值为1，否则未定义

//int main()
//{
//	printf("文件：%s\n", __FILE__);
//	printf("行号：%d\n", __LINE__);
//	printf("编译日期：%s\n", __DATE__);
//	printf("编译时间：%s\n", __TIME__);
//	return 0;
//}

//#define定义常量
//define reg register 起别名
//register建议把变量放在寄存器中，不一定保存

//#define do_forever for(;;)
//用符号来替代一种实现

//
//#define CASE break;case

//定义函数或一段代码
//     续行符  \     表明之后之后的内容是在一行的
//#define  deugb printf("%s %d %s %s\n"\
//         __FILE__,\
//         __LINE__,\
//	     __DATE__,\
//         __TIME__)
//
//int main() {
//	deugb;
//
//	return 0;
//}



//3.#define定义宏
//#define sex(x) x*x;
//注意，参数列表左括号必须与名字紧邻，不然会编译为操作而不是参数
//#define cheng(x) x*x
//
//int main() {
//	int a = 5;
//	int r = cheng(a);
//	int x = cheng(a + 2);
//	printf("%d\t,%d\n", r, x);
//	//输出结果其实是25和17，因为实际上是参数的替换，与函数有区别
//	//对于r，5*5=25
//	//对于x，5+2*5+2=5+10+2=17
//    //最好修改为(x)*(x)
//	return 0;
//}



//4.带有副作用的宏参数
//如++，--

//#define MAX(x,y) (x)>(y)?(x):(y)
//
//int main() {
//	int a = 10;
//	int b = 20;
//	int m = MAX(a++, b++);
//	printf("m=%d\n", m);
//	printf("a=%d,b=%d", a, b);
//	//输出的是a=11,b=22;
//	//(a++)>(b++)?(a++):(b++)
//	return 0;
//}

//5.宏替换的规则

//6.宏与函数的对比
//① 宏没有函数调用开销（保存栈帧、跳转、返回），执行更快；
//② 宏不限制参数类型，一套宏代码可以兼容 int、long、double 等多种类型

//和函数相比宏的劣势：
//每次使用宏的时候，一份宏定义的代码将插入到程序中。除非宏比较短，否则可能大幅度增加程序的长度。
//宏是没法调试的。并且宏参数还有副作用问题
//宏由于类型无关，也就不够严谨。
//宏可能会带来运算符优先级的问题，导致程序容易出现错。


//同时宏也可以做到函数做不到的传类型
//#define MALLOC(num,type) (type*)malloc(sizeof(type))
//
//int main() {
//	int* p = MALLOC(1, int);
//
//}

//inline 函数
//将函数声明成为内联函数
//内联函数具有了函数与宏的优点












//7.#和##
//#----字符串化
//#define PRINT(val,format) printf("the value of  "#val"  is "format"\n",val)
//int main() {
//	int a = 10;
//	//pritnf("the value of a is %d\n", a);
//	PRINT(a, "%d");
//	float b= 3.5f;
//	//pritnf("the value of a is %f\n", b);
//	PRINT(b, "%f");
//
//	return 0;
//}


//##--把位于两边的符号合成一个符号
//一个比较函数的模板
//#define MAX(type)  type  max_##type(type x, type y)\
//                          {\
//                                return x>y?x:y\
//                          }
//
//int main() {
//	int a = 10;
//	int b = 20;
//	int m1 = max_int(a, b);
//	printf("%d\n", m1);
//
//	return 0;
//}



//8.命名约定
//宏名全大写，函数名不全大写

//9.#undef
//移除一个宏定义，只对当前文件生效，所以可以在这个文件中消除外部文件对这个同名宏的定义
//#define M 100
//
//int main() {
//	int m = M;
//#undef M
//	printf("%d\n", M);
//	//报错，M未定义
//	return 0;
//}



//10.命令行定义
//在命令行界面定义值

//11.条件编译
//#ifdef   #endif
//也可以跟一个表达式，但必须是常量表达式

//#define __DEBUG__
//
//int main() {
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0;i < 10;i++) {
//		arr[i] = i;
//    #ifdef __DEBUG__//如果定义了这个DEBUG，就执行之后的，否则执行#endif之后的
//		printf("%d\n", arr[i]);
//    #endif
//	}
//	return 0;
//}

//多分支


//判断是否被定义


//嵌套指令
//#if defined(OS_UNIX)
//   #ifdef OPTION1
//          unix_version_option1();
//   #endif
//   #ifdef OPTION2
//           unix_version_option2();
//   #endif
//#elif defined(OS_MSDOS)
//   #ifdef OPTION2
//        msdos_version_option2();
//   #endif
//#endif


//11.包含头文件
//本地文件包含
//#include"xxxxxxx.h"

//库文件
//#include<xxxxx.h>

//嵌套文件包含
//为了防止一个头文件被重复多次包含
//使用#ifndef
//或者 #pragam once
