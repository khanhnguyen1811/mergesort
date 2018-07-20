//merge sort. 
#include <iostream>
using namespace std; 
void Merge(int arr[], int l, int mid, int r){
	int i, j, k; 
	int left_s, right_s; 
	left_s = mid - l + 1; 
	right_s = r - mid; 
	//goi mang tam. 
	int left_array[100], right_array[100]; 
	//truyen tham so vao. 
	for (i = 0; i < left_s; i++)
	{
		left_array[i] = arr[l + i];
	}
	for (j = 0; j < right_s; j++)
	{
		right_array[j] = arr[mid + 1 + j];
	}
	//goi i, j, k la cac phan tu dau cua mang. 
	i = 0, j = 0, k = l;
	//xet cac dieu kien. 
	while (i < left_s && j < right_s)
	{
		if (left_array[i] < right_array[j])
		{
			arr[k] = left_array[i];
 			i++;
		}
		else
		{
			arr[k] = right_array[j];
			j++;
		}
		k++;
	}
	while (i < left_s)
	{
		arr[k] = left_array[i];
		i++; k++; 
	}
	while (j < right_s)
	{
		arr[k] = right_array[j]; 
		j++; k++;
	}
}
void MergeSort(int arr[], int l, int r){
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		MergeSort(arr, l, mid);
		MergeSort(arr, mid + 1, r);
		Merge(arr, l, mid, r);
	}
}
int main(){
	//khai bao mang, i, sopt; 
	int arr[100], i, sopt; 
	cout << "nhap so phan tu mang: "; cin >> sopt; 
	for (i = 0; i < sopt; i++)
	{
		cin >> arr[i];
	}
	MergeSort(arr, 0, sopt - 1); 
	//xuat mang. 
	cout << "mang duoc sap xep la: " << "\n"; 
	for (i = 0; i < sopt; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}