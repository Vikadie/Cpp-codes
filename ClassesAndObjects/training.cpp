#include <iostream>

using namespace std;

int main() {

	//int length = 0;
	//cin >> length;
	const int length = 7;
	int arr[length];

	printf("array=%p : &array=%p : *(&array)=%p\n", arr, &arr, *(&arr));

	printf("array+1 = %p : &array + 1 = %p : *(&arrays + 1) = %p\n", arr + 1, &arr + 1, *(&arr + 1));
	printf("\n");
	int size = *(&arr + 1) - *(&arr);
	cout << "Number of elements in arr[] is "
		<< size << endl;

	for (int i = 0; i < size; i++)
		arr[i] = 45;

	for (int j = 0; j < size; j++)
		cout << arr[j] << " ";

	cout << endl << "printed as char: ";
	for (char k : arr)
		cout << k << " ";
	cout << endl << "printed as char but with (double): ";
	for (char k : arr)
		cout << (double)k << " ";
	cout << endl << "printed as char + 4: ";
	for (char k : arr)
		cout << k + 4 << " ";
	cout << endl << "printed as (char)(char + 4): ";
	for (char k : arr)
		cout << (char)(k + 4) << " ";
	cout << endl << "printed as char + '4': ";
	for (char k : arr)
		cout << k + '4' << " ";
	cout << endl << "printed as (char)(char + '4'): ";
	for (char k : arr)
		cout << (char)(k + '4') << " ";
	cout << endl << "print 'a' + 2: 'a' + '2' =  ";
	cout << 'a' + 2 << "  :  " << 'a' + '2';
	cout << endl;

	string s = "abcd";
	cout << s << endl;
	cout << s.replace(1, 2, "sme") << endl;
	cout << s.replace(1, 1, "h") << endl;
	s[1] = 'k';
	cout << s << endl;
	cout << s.erase(1, 2) << endl;

	cout << "==================" << endl;
	char line1[4] = { 'a', 'b', 'c' };
	char line2[] = { 'd', 'e', 'f' };
	cout << line1 << endl;
	cout << line2 << endl;

	return 0;
}