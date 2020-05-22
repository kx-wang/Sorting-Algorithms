#include <iostream>
// sorts lists of numbers from smallest to largest, using different sort algorithms

using namespace std;
void bubbleSort(int arr[], int length)
{
    bool isSorted = false;
    int temp;

    while (isSorted == false)
    {
        // if we loop through all items in the list without swapping, then
        // all items in the list are in the correct order, isSorted will remain true and exit out of while loop
        isSorted = true;

        for (int i = 0; i < length - 1; i++)
        {
            // swap if not in correct order
            if (arr[i] > arr[i + 1])
            {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                isSorted = false;
            }
        }
    }
}
int divide (int arr[], int ind_low, int ind_high)
{
    int pivot = arr[ind_high];
    int i = ind_low; //variable to keep track of where the new pivot index is
    int temp;

    for (int j = ind_low; j <= ind_high; j++)
    {
        // if arr[j] > pivot, then we increase that block of numbers that
        // are greater than the pivot value

        // else, arr[j] < pivot, so this arr[j] belongs with the block of
        // numbers smaller than the pivot value. Thus swap arr[i] and arr[j],
        // and update the fact that i should be increased by 1
        if (arr[j] < pivot)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i = i+1;
        }
    }

    // swap the pivot value with arr[i], which is placing it
    // at the interface between the smaller than pivot block and greater than
    // pivot block
    temp = arr[ind_high];
    arr[ind_high] = arr[i];
    arr[i] = temp;

    return i; // return the index of the new pivot
}

// uses a divide and conquer algorithm, so it's recursive
// average case running time is O(n log_2(n))
// Refs: Lomuto partition scheme in wikipedia,
// and https://www.khanacademy.org/computing/computer-science/algorithms/quick-sort/a/linear-time-partitioning
void quickSort(int arr[], int ind_low, int ind_high)
{
    int ind_pivot;

    if (ind_low < ind_high)
    {
        ind_pivot = divide(arr, ind_low, ind_high);
        quickSort(arr, ind_low, ind_pivot-1);
        quickSort(arr, ind_pivot+1, ind_high);
    }

}

int main()
{
    int length = 7;
    int arr[length] = { 5, 2, 3, 6, 8, 1, 10};

    //cout << "Sorted array using bubbleSort: \n";
    //bubbleSort(arr,length);

    cout << "Sorted array using quickSort: \n";
    quickSort(arr,0,length-1);

    for (int i = 0; i < length ; i++)
    {
        cout << arr[i] << " ";
    }
}

