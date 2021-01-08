# include <stdio.h>
void Swap(int *, int *);  //��������, ��������������ֵ
void QuickSort(int *, int, int);  //��������, ��������
int main(void)
{
    int i;  //ѭ������
    int a[] = {900, 2, -58, 3, 34, 5, 76, 7, 32, 4, 43, 9, 1, 56, 8,-70, 635, -234, 532, 543, 2500};
    QuickSort(a, 0, 20);  /*���������ܼ�, 0Ϊ��һ��Ԫ�ص��±�, 20Ϊ���һ��Ԫ�ص��±�*/
    printf("����������Ϊ:\n");
    for (i=0; i<21; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
void Swap(int *p, int *q)
{
    int buf;
    buf = *p;
    *p = *q;
    *q = buf;
    return;
}
void QuickSort(int *a, int low, int high)
{
    int i = low;
    int j = high;
    int key = a[low];
    if (low >= high)  //���low >= high˵�����������
    {
        return ;
    }
    while (low < high)  //��whileѭ������һ�α�ʾ�Ƚ���һ��
    {
        while (low < high && key <= a[high])
        {
            --high;  //��ǰѰ��
        }
        if (key > a[high])
        {
            Swap(&a[low], &a[high]);
            ++low;
        }
        while (low < high && key >= a[low])
        {
            ++low;  //���Ѱ��
        }
        if (key < a[low])
        {
            Swap(&a[low], &a[high]);
            --high;
        }
    }
    QuickSort(a, i, low-1);  //��ͬ���ķ�ʽ�Էֳ�������ߵĲ��ֽ���ͬ�ϵ�����
    QuickSort(a, low+1, j);  //��ͬ���ķ�ʽ�Էֳ������ұߵĲ��ֽ���ͬ�ϵ�����
}