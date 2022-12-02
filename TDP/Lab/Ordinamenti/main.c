#include <stdio.h>
void insertionSort(int vet[], int N);
void BubbleSort(int vet[], int N);
void OptBubbleSort(int vet[], int N);
void SelectionSort(int A[], int N);
void ShellSort(int A[], int N);
//void CountingSort(int A[],int B[],int C[],int N,int k);
//BottomUpMergeSort(int A[], int B[], int N);
void visualizza(int vet[], int N);
int main() {
    int N=10;
    int vet[]={4,6,2,3,9,8,6,1,6,4};
    visualizza(vet,N);
    insertionSort(vet,N);
    BubbleSort(vet,N);
    OptBubbleSort(vet,N);
    SelectionSort(vet,N);
    ShellSort(vet,N);
    //CountingSort(vet,vet2,vet3,N,k);
    //BottomUpMergeSort(int A[], int B[], int N);
    visualizza(vet,N);
    return 0;
}

void insertionSort(int A[], int N) {
    int i, j, l=0, r=N-1, x;
    for (i = l+1; i <= r; i++) {
        x = A[i];
        j = i - 1;
        while (j >= l && x < A[j]){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void BubbleSort(int A[], int N){
    int i, j, l=0, r=N-1;
    int temp;
    for (i = l; i < r; i++) {
        for (j = l; j < r - i +l; j++)
        if (A[j] > A[j+1]) {
            temp = A[j];
            A[j] = A[j+1];
            A[j+1] = temp;
        }
    }
}

void OptBubbleSort(int A[], int N) {
    int i, j, l=0, r=N-1, flag=1;
    int temp;
    for (i = l; i < r && flag==1; i++) {
        flag = 0;
        for (j = l; j < (r - i + l); j++){
            if (A[j] > A[j+1]) {
                flag = 1;
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }

    }
}

void SelectionSort(int A[], int N) {
    int i, j, l=0, r=N-1, min;
    int temp;
    for (i = l; i < r; i++) {
        min = i;
        for (j = i+1; j <= r; j++)
            if (A[j] < A[min])
                min = j;
        if (min != i) {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
}

void ShellSort(int A[], int N) {
    int i, j, x, l=0, r=N-1, h=1;
    while (h < N/3)
        h = 3*h+1;
    while(h >= 1) {
        for (i = l + h; i <= r; i++) {
            j = i;
            x = A[i];
            while(j >= l + h && x < A[j-h]) {
                A[j] = A[j-h];
                j -=h;
            }
            A[j] = x;
        }
        h = h/3;
    }
}

/*void CountingSort(int A[],int B[],int C[],int N,int k){
    int i, l=0, r=N-1;
    for (i = 0; i < k; i++)
        C[i] = 0;
    for (i = l; i <= r; i++)
        C[A[i]]++;
    for (i = 1; i < k; i++)
        C[i] += C[i-1];
    for (i = r; i >= l; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;7
    }
    for (i = l; i <= r; i++)
        A[i] = B[i];
}*/

/*void BottomUpMergeSort(int A[], int B[], int N) {
    int i, q, m, l=0, r=N-1;
    for (m = 1; m <= r – l; m = m + m){
        for (i = l; i <= r – m;i += m + m) {
                q = i + m - 1;
                Merge(A, B, i, q, r);
        }
    }
}

void Merge(int A[], int B[], int l, int q, int r) {
    int i, j, k;
    i = l;
    j = q+1;
    for (k = l; k <= r; k++)
        if (i > q)
            B[k] = A[j++];
        else if (j > r)
            B[k] = A[i++];
        else if ((A[i]< A[j]) || (A[i]== A[j]))
            B[k] = A[i++];
        else
            B[k] = A[j++];
    for ( k = l; k <= r; k++ )
        A[k] = B[k];
}*/

void visualizza(int vet[], int N){
    for(int i=0;i<N;i++){
        printf("%d\t", vet[i]);
    }
    printf("\n");
}



