#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector <int> mergeSort(vector <int> numbers) {
    if (numbers.size() > 1){
        int middle = numbers.size()/2;
        vector <int> left_numbers(numbers.begin(), numbers.begin() + middle);
        vector <int> right_numbers(numbers.begin() + middle, numbers.begin() + numbers.size());

        left_numbers = mergeSort(left_numbers);
        right_numbers = mergeSort(right_numbers);

        int i = 0, j = 0, k = 0;

        while (i < left_numbers.size() && j < right_numbers.size()){
            if (left_numbers[i] > right_numbers[j])
                numbers[k++] = right_numbers[j++];
            else
                numbers[k++] = left_numbers[i++];
        }

        while (i < left_numbers.size())
            numbers[k++] = left_numbers[i++];

        while (j < right_numbers.size())
            numbers[k++] = right_numbers[j++];
    }

    return numbers;
}

int main () {

    int number;
    vector <int> numbers;
    string line;

    getline(cin, line);
    istringstream iss(line);

    while ( iss >> number )  
        numbers.push_back(number);

    numbers = mergeSort(numbers);
    
    for (int i = 0; i < numbers.size(); i++)
        cout << numbers[i] << ' ';

	return 0;
}
