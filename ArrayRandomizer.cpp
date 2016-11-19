#include <iostream>
#include <random>
using namespace std;

template <typename T, size_t N>
void Randomize(T(&input)[N]) {

	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, N - 1);
	unsigned int index;

	for (int i = 0; i < N; i++) {

		unsigned int index = distribution(generator);
		T value = input[i];

		input[i] = input[index];
		input[index] = value;
	}

}

int main() {

	int intArray[10] = { 0,1,2,3,4,5,6,7,8,9 };

	Randomize(intArray);

	for (int i = 0; i < 10; i++) {
		cout << intArray[i] << ' ';
	}
	cout << endl;

	char charArray[10] = { 'a','b','c','d','e','f','g','h','i','j' };

	Randomize(charArray);

	for (int i = 0; i < 10; i++) {
		cout << charArray[i] << ' ';
	}
	cout << endl;

	system("pause");

}