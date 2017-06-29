//This is a Merge Sort code for Github test
#include <iostream>

//using namespace  std;

class MergeSort
{
	int *arr, *aux, size;
	void sortArr(int *mainArr, int *auxArr, int lo, int hi);
	void mergeArr(int *mainArr, int *auxArr, int lo, int mid, int hi);
public:
	MergeSort(int len){
		size = len;
		arr = new int[size];
		aux = new int[size];
		cout << "\nEnter the elements: ";
		for (int i = 0; i < size; ++i)
		{
			cin>>arr[i];
		}
	}
	~MergeSort();
	void sortArr();
	void displayArr();
};
void MergeSort::sortArr(int *mainArr, int *auxArr, int lo, int hi){
	if(lo >= hi) return;
	int mid = lo + (hi - lo) / 2;
	sortArr(mainArr, auxArr, lo, mid);
	sortArr(mainArr, auxArr, mid + 1, hi);
	mergeArr(mainArr, auxArr, lo, mid, hi);
}
void MergeSort::mergeArr(int *mainArr, int *auxArr, int lo, int mid, int hi){
	int i, j, k;
	for (int i = lo; i <= hi; ++i)
	{
		auxArr[i] = mainArr[i];
	}
	i = lo - 1, j = mid;
	for (int k = lo; k <= hi; ++k)
	{
		if(i > mid) mainArr[k] = auxArr[++i];
		else if(j > hi) mainArr[k] = auxArr[++j];
		else if(auxArr[j] < auxArr[i]) mainArr[k] = auxArr[++j];
		else mainArr[k] = auxArr[++i];
	}
}
void MergeSort::sortArr(){
	for (int i = 0; i < size; ++i)
	{
		aux[i] = arr[i];
		sortArr(arr, aux, 0, size - 1);
	}
}
void MergeSort::displayArr(){
	cout<<"\nThe array is: ";
	for(int i = 0;i < size; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int len;
	cout<<"\nEnter the size: ";
	cin>>len;
	MergeSort obj(len);
	obj.displayArr();
	obj.sortArr();
	obj.displayArr();
	return 0;
}