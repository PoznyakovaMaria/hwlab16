#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

//������� ��� ������ � ���������
double* full_elements(double* ptr_array, int size);
double* calc_elements(double* ptr_array, int size, int* new_size);
void put_elements(double* ptr_array, int size);
double calculate_average(double* array, int size);

int main() {
    setlocale(LC_ALL, "RUS");
    int size;
    double* ptr_array;
    printf("������� ������ �������: ");
    scanf_s("%d", &size);

    //��������� ������ ��� ������
    ptr_array = (double*)malloc(size * sizeof(double));
    if (ptr_array == NULL) {
        puts("������ ��������� ������");
        return -1;
    }
    ptr_array = full_elements(ptr_array, size);

    //��������� ��������� �������
    int new_size;
    double* ptr_array2 = calc_elements(ptr_array, size, &new_size);

    printf("�������� ������:\n");
    put_elements(ptr_array, size);
    printf("\n��������������� ������:\n");
    put_elements(ptr_array2, new_size);
    free(ptr_array);
    free(ptr_array2);

    return 0;
}
// ������� ��� ���������� �������
double* full_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        ptr_array[i] = (double)(i + 1);
    }
    return ptr_array;
}
// ������� ��� ��������� ��������� �������
double* calc_elements(double* ptr_array, int size, int* new_size) {
    double* new_array = (double*)malloc(size * sizeof(double));
    if (new_array == NULL) {
        puts("������ ��������� ������ ��� ������ �������");
        return NULL;
    }
    double average = calculate_average(ptr_array, size);
    int index = 0; 
    for (int i = 0; i < size; i++) {
        if (ptr_array[i] > 0) {
            if (ptr_array[i] > 1) {
                new_array[index++] = ptr_array[i] - 0.5;
            }
            else {
                new_array[index++] = ptr_array[i] + 0.5;
            }
            if (index == 1) {
                new_array[index++] = average; 
                new_array[0] = average;
            }
        }
    }
    //������������� ����������� ������ ������ �������
    *new_size = index;
    return new_array;
}
void put_elements(double* ptr_array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.2lf ", ptr_array[i]);
    }
    printf("\n");
}
//������� ��� ������� �������� �������� �������
double calculate_average(double* array, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum / size;
}