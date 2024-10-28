#include <iostream>
using namespace std;

// Hàm trộn hai nửa mảng đã sắp xếp thành một mảng hoàn chỉnh
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1; // Số phần tử trong nửa trái
    int n2 = right - mid;    // Số phần tử trong nửa phải

    // Tạo mảng tạm cho nửa trái và nửa phải
    int *L = new int[n1];
    int *R = new int[n2];

    // Sao chép dữ liệu vào mảng tạm
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Trộn các mảng tạm vào lại mảng chính `arr`
    int i = 0;    // Chỉ số của nửa trái
    int j = 0;    // Chỉ số của nửa phải
    int k = left; // Chỉ số của mảng chính

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k] = L[i++];
        else
            arr[k] = R[j++];
        k++;
    }
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
    delete[] L;
    delete[] R;
}

// Hàm Merge Sort
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Đệ quy chia mảng thành hai nửa
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Trộn hai nửa đã sắp xếp lại với nhau
        merge(arr, left, mid, right);
    }
}

// Hàm in mảng
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "ban dau: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "sap xep: ";
    printArray(arr, n);

    return 0;
}