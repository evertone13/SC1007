//To finish Q3, open termianl, use 'cd' and 'dlr' or 'ls command
//to open your working directory.
//Step 1:Copy 'Input_1mil.txt'to the working directory.
//Step 2:Compile the main.c with command 'gcc main.c-o main'. Now you have 'main.exe'.
//Step 3:Run 'main.exe <input_1mil.txt'.

//Question 1;

void dualSearch(int A[],int size,int K, int dualIndex[])
{
    int i,j;

    for(i=0;i<size;i++)
        for(j=i;j<size;j++)
            if(A[i]+A[j]==K){
                dualIndex[0]=i;
                dualIndex[1]=j;
                return;
            }
}

//Question 2;

void dualSortedSearch(int A[],int size, int K, int dualIndex[])
{
    int i,j,temp;
    i=0;
    j=size-1;
    while(i<j){
        temp=A[i]+A[j];
        if(temp==K){
            dualIndex[0]=i;
            dualIndex[1]=j;
            return;
        }
        else if(temp<K){
            i++;
        }
        else
            j--;
    }
}
