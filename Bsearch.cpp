/******A Bsearch program by zhanghongyu 20131010
**next version a tongyong Bsearch
*/


#include<iostream>

int Bsearch(int *arr, int *key, int arrlength, int &count);

int Bsearch(int *arr, int *key, int arrlength, int &count)
{	
	
	int l = 0;
	int r = arrlength;
	while(*key <= arr[r] && *key >= arr[l]){
		if(l > r) return -1;
		int m = (l+r)/2; 
		if(*(arr+m) == *key ){
			count++; 
			return m;
		}
		if(*(arr+m) > *key){
	 		r=m-1;
			count++;
		}
		if(*(arr+m) < *key) {
			l=m+1;
			count++;
		}
	}
	return -1;	
}

int main()
{
	int arr[] = { 1,4,6,9,13,16,19,28,40,50,58};
	int key = 4;
	int count = 0;
	int a =	Bsearch(arr, &key, 11, count);
	std::cout << a <<"  "<< count << std::endl;
	return 0;
}
