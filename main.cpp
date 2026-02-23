#include <iostream>
#include <vector>

using namespace std;

class Factorizer {
public: 
	vector<int> primeFactors(int num) {
		vector<int> factors;

		//less than or = 1, return empty
		if (num <= 1) {
			return factors;
		}

		int divisor = 2;

		while (num > 1) {
			//if divis, add divisor and divide
			if (num % divisor == 0) {
				factors.push_back(divisor);
				num = num / divisor;
			}
			else {
				divisor++; // next number
			}
		}

		return factors;
	}

	void printVec(vector<int> vec) {
		cout << "[";

		for(int i = 0; i < vec.size(); i++) {
			cout << vec[i];
			if (i != vec.size() - 1) {
				cout << ",";
			}
		}
		cout << "]";
	}

	//tests
	void runTests() {
		Factorizer factor;

		cout << "Testing: \n";

		vector<int> test1 = factor.primeFactors(0);
		cout << "Test 1: 0 ";
		printVec(test1);
		cout << " Expected: []\n";

		vector<int> test2 = factor.primeFactors(1);
		cout << "Test 2: 1  ";
		printVec(test2);
		cout << " Expected: []\n";

		vector<int> test3 = factor.primeFactors(9);
		cout << "Test 3 : 9 ";
		printVec(test3);
		cout << " Expected: [3, 3]\n";

		vector<int> test4 = factor.primeFactors(10);
		cout << "Test 4: 10 ";
		printVec(test4);
		cout << " Expected: [2, 5]\n";

		vector<int> test5 = factor.primeFactors(32);
		cout << "Test 5: 32 ";
		printVec(test5);
		cout << " Expected: [2]\n";

		vector<int> test6 = factor.primeFactors(24);
		cout << "Test 5: 24 ";
		printVec(test6);
		cout << " Expected: [2, 3]\n";

		cout << "Tests Complete.\n\n";
	}

};

int main() {
	
	Factorizer factor;

	factor.runTests();

	int userNum;

	cout << "Enter a number to factorize: ";
	cin >> userNum;

	vector<int> result = factor.primeFactors(userNum);

	cout << "Prime factors of " << userNum << " are: ";
	factor.printVec(result);
	cout << endl;

	return 0;

}