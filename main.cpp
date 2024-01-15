#include <stdio.h>

/**
 * Description:
 * 初始化顺序表（顺序表中元素为整型），里边的元素是1,2,3，然后通过scanf读取一个元素（假如插入的是6），
 * 插入到第2个位置，打印输出顺序表，每个元素占3个空格，格式为1  6  2  3，然后scanf读取一个整型数，是删除的位置（假如输入为1），
 * 然后输出顺序表  6  2  3，假如输入的位置不合法，输出false字符串。提醒，Language一定要选为C++。
 * @return
 */

//顺序表（sequence list）的声明与定义
#define MAXSIZE 128
typedef int ElemType;//数据类型别名使用驼峰命名法
typedef struct{
    ElemType data[MAXSIZE]={0};//具体变量名使用下划线命名法
    int length=0;//数组的初始化长度，即实际的元素个数
}SequenceList;

void PrintList(SequenceList list);

bool InsertList(SequenceList &list,int position,ElemType e);

bool DeleteList(SequenceList &list,int position);

//查找特定元素的位置,成功返回位置值，失败返回0
int LocateElem(SequenceList list,ElemType e);

int main() {
    //初始化顺序表
    SequenceList sequence_list;
    sequence_list.length=3;
    sequence_list.data[0]=1;
    sequence_list.data[1]=2;
    sequence_list.data[2]=3;
    //插入元素
    ElemType e;//声明元素变量用于存储输入的元素值
    scanf("%d",&e);
    bool ret;//函数返回值
    ret=InsertList(sequence_list,2,e);
    if(ret)
    {
        PrintList(sequence_list);
    }
    //删除元素
    int delete_position;//删除位置
    scanf("%d",&delete_position);
    ret=DeleteList(sequence_list,delete_position);
    if(ret)
    {
        PrintList(sequence_list);
    }
    return 0;
}

void PrintList(SequenceList list) {
    for (int i = 0; i < list.length; i++) {
        printf("%3d",list.data[i]);
    }
    printf("\n");
}

bool InsertList(SequenceList &list,int position,ElemType e){
    //判断插入位置是否合法
    if(position<1 || position>list.length+1)
    {
        return false;
    }
    //判断是否超出表长度
    if(MAXSIZE<=list.length)
    {
        return false;
    }
    //从表尾开始移动元素，到插入位置为止
    for (int i = list.length; i>=position; i--) {
        list.data[i]=list.data[i-1];
    }
    //将新的元素赋值到插入位置，下标比位置少1
    list.data[position-1]=e;
    //表长度加1
    list.length++;
    return true;
}

bool DeleteList(SequenceList &list,int position){
    //判断输入位置合法性
    if(position<1 || position>list.length)
    {
        printf("false\n");
        return false;
    }
    //删除操作：移动删除位置后面的元素覆盖需要删除的元素值即可，从删除位置开始移动，直到表尾
    for (int i = position; i < list.length; i++) {
        list.data[i-1]=list.data[i];
    }
    //表长度减1
    list.length--;
    return true;
}

int LocateElem(SequenceList list,ElemType e){
    int i=0;
    while (i<list.length){
        if(list.data[i]==e){
            return i+1;
        }
        i++;
    }
    return i;
}