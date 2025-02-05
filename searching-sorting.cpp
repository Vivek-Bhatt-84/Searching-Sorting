#include <iostream>
#include <vector>

using namespace std;

/**
 * Quick Sort Algorithm
 *
 * This function sorts the array using the Quick Sort algorithm. It picks a pivot element
 * and partitions the array around the pivot, recursively sorting the sub-arrays.
 *
 */
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = arr[high]; // Choosing the pivot element as the last element.
        int i = low - 1;

        // Partitioning the array based on the pivot element.
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]); // Putting the pivot in the correct position.
        int pi = i + 1;

        // Recursively sorting the left and right sub-arrays.
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/**
 * Merge Sort Algorithm
 *
 * This function sorts the array using the Merge Sort algorithm. It divides the array into
 * two halves, recursively sorts them, and then merges them back together.
 *
 */
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    // Copying data into temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    // Merging the temporary arrays back into the original array.
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copying remaining elements of L[] and R[] if any.
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        // Recursively sorting both halves of the array.
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merging the sorted halves.
        merge(arr, left, mid, right);
    }
}

/**
 * Heap Sort Algorithm
 *
 * This function sorts the array using the Heap Sort algorithm. It builds a max-heap and
 * extracts the largest element to place it at the correct position in the sorted array.
 *
 */
void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Checking if the left child is larger than the root.
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Checking if the right child is larger than the largest so far.
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swapping and recursively heapifying the affected subtree.
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    // Building the max-heap.
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Extracting elements from the heap one by one and placing them in the correct position.
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]); // Swap the root (max element) with the last element.
        heapify(arr, i, 0);   // Heapify the reduced heap.
    }
}

/**
 * Binary Search Algorithm
 *
 * This function performs binary search on a sorted array to find the index of the target element.
 */
int binarySearch(const vector<int> &arr, int target)
{
    int left = 0, right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Not found
}

/**
 * Linear Search Algorithm
 *
 * This function performs linear search to find the target element in an unsorted array.
 *
 */
int linearSearch(const vector<int> &arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }

    return -1; // Not found
}

/**
 * Function to display the menu options to the user.
 */
void displayMenu()
{
    cout << "\nSelect an option:" << endl;
    cout << "1. Sort the array using Quick Sort" << endl;
    cout << "2. Sort the array using Merge Sort" << endl;
    cout << "3. Sort the array using Heap Sort" << endl;
    cout << "4. Search for an element using Binary Search" << endl;
    cout << "5. Search for an element using Linear Search" << endl;
    cout << "6. Exit" << endl;
}

int main()
{
    vector<int> data = {12, 11, 13, 5, 6, 7}; // Initial data array
    int choice, target, result;

    cout << "Original Data: ";
    for (int val : data)
        cout << val << " ";
    cout << endl;

    // Menu driven program for sorting and searching
    while (true)
    {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            quickSort(data, 0, data.size() - 1);
            cout << "Sorted Data (Quick Sort): ";
            for (int val : data)
                cout << val << " ";
            cout << endl;
            break;

        case 2:
            mergeSort(data, 0, data.size() - 1);
            cout << "Sorted Data (Merge Sort): ";
            for (int val : data)
                cout << val << " ";
            cout << endl;
            break;

        case 3:
            heapSort(data);
            cout << "Sorted Data (Heap Sort): ";
            for (int val : data)
                cout << val << " ";
            cout << endl;
            break;

        case 4:
            cout << "Enter target element for Binary Search: ";
            cin >> target;
            result = binarySearch(data, target);
            if (result != -1)
                cout << "Element found at index " << result << endl;
            else
                cout << "Element not found!" << endl;
            break;

        case 5:
            cout << "Enter target element for Linear Search: ";
            cin >> target;
            result = linearSearch(data, target);
            if (result != -1)
                cout << "Element found at index " << result << endl;
            else
                cout << "Element not found!" << endl;
            break;

        case 6:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice, please try again!" << endl;
        }
    }

    return 0;
}
