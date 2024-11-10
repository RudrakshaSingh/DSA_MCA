void countSort(int arr[], int n){
    //finding maximum element
    int maximunElement = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>maximunElement)
        {
            maximunElement=arr[i];
        }
    }
    
    //initializing count array as 0
    int *count=(int *)malloc((maximunElement+1)*sizeof(int));
    for (int i = 0; i < maximunElement+1; i++)
    {
        count[i]=0;
    }

    //incrementing indexes of count according the array elements
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }
    
    //putting elements back to array
    int j =0;//given array
    for (int i = 0; i < maximunElement+1; i++)
    {
        while (count[i]>0)
        {
            arr[j]=i;
            j++;
            count[i]--;
        }    
    }
    
}