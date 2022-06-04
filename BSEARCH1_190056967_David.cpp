#include <vector>
#include <stdio.h>

using namespace std;

int binary_search (int sorted_numbers[], int queried_number, int low, int high){
    if (high < low)
        return -1;

    int middle = low + (high - low)/2;
        
    if (sorted_numbers[middle] == queried_number && sorted_numbers[middle - 1] != queried_number)
        return middle;

    if (sorted_numbers[middle] < queried_number)
        return binary_search(sorted_numbers, queried_number, middle + 1, high);

    return binary_search(sorted_numbers, queried_number, low, middle - 1);
}

int main () {

    int n, q, queried_number, i;

    scanf("%d %d", &n, &q);

    int numbers[n];
    int out[q];

    for (i = 0; i < n; i++)
        scanf("%d", &numbers[i]);

    for (i = 0; i < q; i++){
        scanf("%d", &queried_number);

        out[i] = binary_search(numbers, queried_number, 0, n - 1);
    }

    for (i = 0; i < q; i++)
        printf("%d\n", out[i]);
    
	return 0;
}
