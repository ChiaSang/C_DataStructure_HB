/* 郝斌数据结构结构体复习 */

#include <stdio.h>
// 一个结构体例子
struct Student
{
    int sid;
    char name[10];
    int age;
};

// 打印函数
ffprint(struct Student *st)
{
    printf("%d  %s  %d\n", st->sid, st->name, st->age);
}
// 定义在main函数之外
int main(int argc, char const *argv[])
{
    struct Student st = {100, "zhouzhou", 26};
    ffprint(&st);

    // 另外一种表示方式

    struct Student *stu;
    stu = &st;
    stu->sid = 200;  // 指针变量的引用方式
    (*stu).age = 30; // 普通变量的引用方式
    // 两种引用结构体内部变量的方式
    ffprint(&st);
    // 只用发送st的地址给函数，效率更高，如果传递结构体则需要发送结构体4个字节加上变量的大小，效率低下

    int a[2] = {23, 55};
    //malloc的动态分配

    //动态定义一个数组
    int *pArr = (int *)malloc(sizeof(a)); //定义一个int类型的动态数组
    printf("%ld", sizeof(a));
    pArr[1] = 20; // 相当于给数组赋值
    free(pArr); //释放
    


    return 0;
}
