#include<stdio.h>
#include<stdlib.h>
#include <iostream>

using namespace std;

typedef struct items
{
    char name[20];
    unsigned int weight;
    float profit;
};

float max(float a, float b)
{
    return ((a > b) ? a : b);
}

float knapsack(unsigned int n, struct items object[], unsigned int capacity)
{
    float** table = new float* [n + 1];

    for (unsigned int i = 0; i <= n; i++)
    {
        table[i] = new float[capacity + 1];
        for (unsigned int j = 0; j <= capacity; j++)
        {
            if (i == 0 || j == 0)
                table[i][j] = 0.0;
            else if (object[i - 1].weight <= j)
                table[i][j] = max((object[i - 1].profit + table[i - 1][j - object[i - 1].weight]), table[i - 1][j]);
            else
                table[i][j] = table[i - 1][j];
        }
    }
    //Printing table
    //printf("Printing profit table\n");
    //for (unsigned int i = 0; i <= n; i++)
    //{
    //    for (unsigned int j = 0; j <= capacity; j++)
    //        printf("%.1f\t", table[i][j]);
    //    printf("\n");
    //}
    return table[n][capacity];
}

void main()
{
    setlocale(LC_ALL, "rus");

    unsigned int capacity;
    cout << "������� ����� �������:";
    cin >> capacity;

    unsigned int n;
    printf("������� ����� ���������� ���������: ");
    cin >> n;

    items* item = new items[n];

    printf("������� ������������� ������:\n");
    for (unsigned int i = 0; i < n; i++)
    {
        printf("���� No. %d\n", i + 1);
        printf("��� : ");
        cin >> item[i].name;
        printf("��� : ");
        cin >> item[i].weight;
        printf("����: ");
        cin >> item[i].profit;
    }

    float maxPrice = knapsack(n, item, capacity);

    printf("������������ ���� - ��� %.2f.", maxPrice);
}