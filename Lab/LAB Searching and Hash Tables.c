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

//Question 4:
ListNode* HashSearch(HashTable Q3Hash,int key){
    int index;
    listNode *temp;

    //we may use Q3Hash.Table !=NULL
    if(Q3Hash.hSize!=0)
        index=Hash(key,Q3Hash.hSize);
    else
        return NULL;

    temp=Q3Hash.Table[index].head;
    while(temp!=NULL){
        if(temp->key==key)
            return temp;
        temp=temp->next;
    }
    return NULL;
}

int HashInsert(HashTable* Q3HashPtr, int key)
{
    int index;
    ListNode *newNode;

    if(HashSearch(*Q3HashPtr,key)!=NULL)
        return 0;
    if(Q3HashPtr->hSize!=0)
        index = Hash(key,Q3HashPtr->hSize);
    
    //The key is inserted from the front. It is not the same approach discussed in lecture
    newNode = (ListNode *) malloc(sizeof(ListNode));
    newNode->next=Q3HashPtr->Table[index].head;
    Q3HashPtr->Table[index].head=newNode;

    Q3HashPtr->Table[index].size++;
    Q3HashPtr->nSize++;

    return 1;
}
