#include <vector>
#include <stdio.h>

using namespace std;

int swaps;

vector <int> mergeSort(vector <int> numbers) {
    if (numbers.size() > 1){
        int middle = numbers.size()/2;
        vector <int> left_numbers(numbers.begin(), numbers.begin() + middle);
        vector <int> right_numbers(numbers.begin() + middle, numbers.begin() + numbers.size());

        left_numbers = mergeSort(left_numbers);
        right_numbers = mergeSort(right_numbers);

        int i = 0, j = 0, k = 0;

        while (i < left_numbers.size() && j < right_numbers.size()){
            if (left_numbers[i] > right_numbers[j]){
                numbers[k++] = right_numbers[j++];
                swaps += left_numbers.size() - i;
            }
            else{
                numbers[k++] = left_numbers[i++];
            }
        }

        while (i < left_numbers.size())
            numbers[k++] = left_numbers[i++];

        while (j < right_numbers.size())
            numbers[k++] = right_numbers[j++];
    }

    return numbers;
}

int main () {

    int t, number, size;
    vector <int> numbers;

    scanf("%d", &t);
    int out[t];


    for (int i = 0; i < t; i++){
        scanf("%d", &size);
        for (int j = 0; j < size; j++){
            scanf("%d", &number);
            numbers.push_back(number);
        }

        mergeSort(numbers);
        out[i] = swaps;

        numbers.clear();
        swaps = 0;
    }
    for (int i = 0; i < t; i++)
        printf("%d\n", out[i]);
    
	return 0;
}
