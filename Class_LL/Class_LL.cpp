
#include "LL.h"

int main()
{
	int arr[] = {4,11,23,6,7};
	int arr2[] = {1,5,3,8};
	
	LL O1(arr, sizeof(arr)/sizeof(arr[0]));
	LL O2(arr2, sizeof(arr2) / sizeof(arr2[0]));
	cout << O1;
	cout << O2;
	LL O3;
	O3 = O1 + O2;
	cout << "Res O3: " << O3;

	/*
	Node* A;
	A = O1.lastNth(20);

	if (A != NULL)
		cout << "data from last: " << A->data << endl;
	else
		cout << "Error \n";

*/
	
	/*
	LL O2;
	O2=!O1;
	//O2 = O1;
	
	LL O3(O1);

	cout << "After: " << O1;
	cout << "Value O2: " << O2;
	cout << "Value O3: " << O3;

	// findmiddle
	*/


	
}

