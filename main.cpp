#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::cerr;
using std::stringstream ;
using std::string;
using std::ostream;

unsigned long long int Fibonacci(unsigned int n);
void PrintReverseString(const string& str, ostream& output = cout);
// You may change the parameters of these functions
size_t MinimumPosition(const int array[], size_t size);
void SelectionSort(int array[], size_t size);


int main() {
	const size_t ELEMENTS = 7;
	const size_t TESTS = 3;
	int data[][ELEMENTS] = {
			{7, 5, 4, 1, 3, 0, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{8, 5, 4, 1, 3, 4, 0}};

	int minimumSolutions[] = {5, 0, 6};
	int sortedArrays[][7] = {
			{0, 1, 3, 4, 5, 7, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{0, 1, 3, 4, 4, 5, 8}};

	unsigned long long int fibonacciSequence[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};

	string strings[] = {"hello", "aardvark", "reviver"};
	string reverses[] = {"olleh", "kravdraa", "reviver"};
	size_t passed = 0;
	int minimumResponses[TESTS];
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = -1;
	}

	cout << "Testing Fibonacci" << endl;
	for (int i = 0; i < 10; ++i) {
		unsigned long long int fibonacci = Fibonacci(i);
		if (fibonacci == fibonacciSequence[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}


	cout << "Testing Minimum Position Finding" << endl;
	for (int i = 0; i < TESTS; ++i) {
		minimumResponses[i] = MinimumPosition(data[i], ELEMENTS);
		if (minimumResponses[i] == minimumSolutions[i]){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Sorting" << endl;
	bool equal;
	for (int i = 0; i < TESTS; ++i) {
		SelectionSort(data[i], ELEMENTS);
		equal = true;
		for (int j = 0; j < ELEMENTS; ++j) {
			if (data[i][j] != sortedArrays[i][j]){
				equal = false;
				cerr << "Test " << i << " position " << j << " values: ";
				cerr << data[i][j] << " " << sortedArrays[i][j] << endl;
				break;
			}
		}
		if (equal){
			cout << "\tPassed " << ++passed << " tests" << endl;
		}
	}
	cout << "Testing Reverse Strings" << endl;
	stringstream out;
	for (int i = 0; i < TESTS; ++i) {
		out.clear();
		out.str("") ;
		PrintReverseString(strings[i], out);
		if (out.str() == reverses[i])
			cout << "\tPassed " << ++passed << " tests" << endl;
	}

	return 0;
}

//Returns number n in Fibonacci sequence (Note: Input must be >= 1)
unsigned long long int Fibonacci(unsigned int n){
    if (n == 0 || n == 1) {
        return n;
    } else {
        return (Fibonacci(n-1) + Fibonacci(n-2));
    }
}

int i = 0;
//Prints reversed string FIXME
void PrintReverseString(const string& str, ostream& output){
    size_t numChars = str.length();
    output << str.back();
    if (numChars == 1) {
        output << str << endl;
    } else {
        output << str.back();
        //output << str[numChars];
        //PrintReverseString(str.substr(0, numChars - 1));

        //string(str).pop_back();
        //PrintReverseString(str.substr(0, numChars));
    }
}


//FIXME You may change the parameters of these functions
size_t MinimumPosition(const int array[], size_t size){
    if (size == 1) {
        return 0;
    } else {
        size_t min = (MinimumPosition(array, size - 1));
        if (array[size] < array[min]) {
            return size;
        } else return min;
    }
}


int posOfSmallest = 0;

void SelectionSort(int array[], size_t size){
    /*
    if (size - a == 1) {
        return;
    } else {
        int smallest = array[a]; //assume the first element is the smallest, because, so far, it is.
        int b = a; //b is used to track the position of the smallest element in the array
        for (int i = a; i < size; ++i) //loop through all values to find the smallest element
        {
            if (array[i] < smallest) {
                smallest = array[i]; //set the smallest element so far
                b = i; //remember position
            }
        }
        //put smallest element in its proper position
        int temp = array[a];
        array[a] = array[b];
        array[b] = temp;

        SelectionSort(array, size, a+1);
        //SelectionSort(array, size, a + 1); //sort the next sub array
    }*/


    //If one element, exit function
    if (size == 1) {
        return;
    } else {
        int curSmallest  = array[posOfSmallest];
        for (int j = posOfSmallest + 1; j < size; j++) {
            if (array[j] < curSmallest) {
                posOfSmallest = j;
                int temp = curSmallest;
                curSmallest = array[posOfSmallest];
                array[posOfSmallest] = temp;
                SelectionSort(array, size);
            }
        }


    }






    /*
    int minPosition = MinimumPosition(array, size - 1);
    if (minPosition != index) {
        //Swap
        temp = array[index];
        array[index] = array[minPosition];
        array[minPosition] = temp;
    }
    index++;
    SelectionSort(array, size);*/

    /*
    if (minpos1 != pos1){
        temp=arr1[pos1];
        arr1[pos1]=arr1[minpos1];
        arr1[minpos1]=temp;
    }
    recurselectSort(arr1, len1, pos1 + 1);
    */
}
