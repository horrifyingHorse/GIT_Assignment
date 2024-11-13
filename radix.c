#include <stdio.h>

// Function to get the maximum value in the array
int getMax(int array[], int size) {
    int max = array[0];
    for(int i = 1; i < size; i++) { // Change `n` to `size` and start from index 1
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

// Counting sort function for a specific digit represented by 'place'
void countingSort(int array[], int size, int place) {
    int output[size];
    int count[10] = {0}; // Count array to store count of occurrences

    // Calculate count of elements
    for(int i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
    }

    // Calculate cumulative count
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order
    for(int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    // Copy the sorted elements into original array
    for(int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

// Main function to implement radix sort
void radixSort(int array[], int size) {
    // Get the maximum element in the array
    int max = getMax(array, size);

    // Apply counting sort to sort elements based on place value
    for(int place = 1; max / place > 0; place *= 10) {
        countingSort(array, size, place);
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int array[] = {121, 432, 564, 23, 1, 45, 788};
    int n = sizeof(array) / sizeof(array[0]); // Add a semicolon here
    radixSort(array, n);
    printArray(array, n);
    return 0; // Return statement added
}