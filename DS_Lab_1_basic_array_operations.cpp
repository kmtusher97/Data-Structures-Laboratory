#include <iostream>
#include <cstdio>
using namespace std;

int ln;

void dots() { for(int i=0; i<80; i++) printf("."); }

void mainMenu() {
        printf("\nOperations on array..... Enter your choice\n");
        dots();
        printf("\n1 Traversing\n2 Insertion\n3 Deletion\n4 Searching\n5 Sorting\n0 Exit\n\nChoice : ");
}

void traversing( int *arr ) {
        printf("\nThe array :\n");
        for(int i=1; i<=ln; i++) printf("%d ", arr[i]);
        printf("\n");
}

void insertion( int *arr, int pos, int vlu ) {
        for(int i=ln; i>=pos; i--) {
                arr[i+1] = arr[i];
        }
        arr[pos] = vlu;
        ln++;
}

void deletion( int *arr, int pos ) {
        for(int i=pos+1; i<=ln; i++) {
                arr[i-1] = arr[i];
        }
        ln--;
}

void linerSearch( int *arr, int vlu ) {
        bool flg = false;
        for(int i=1; i<=ln; i++) {
                if( arr[i] == vlu ) {
                        printf("\n%d found at position %d\n", vlu, i);
                        flg = true;
                        break;
                }
        }
        if( !flg ) printf("Not found!!!\n");
}

void binarySerach( int *arr, int vlu ) {
        int lo = 1, hi = ln, mid;
        while( lo <= hi ) {
                mid = lo + (hi-lo)/2;
                if( arr[mid] == vlu ) {
                        printf("\n%d found at position %d\n", vlu, mid);
                        return;
                }
                else if( arr[mid] > vlu ) hi = mid-1;
                else lo = mid+1;
        }
        printf("Not found!!!\n");
}

void selectionSort( int *arr ) {
        traversing( arr );
        for(int i=1; i<ln; i++) {
                for(int j=i+1; j<=ln; j++) {
                        if( arr[i] > arr[j] ) swap(arr[i], arr[j]);
                }
        }
        printf("\nThe sorted array :\n");
        for(int i=1; i<=ln; i++) printf("%d ", arr[i]);
        printf("\n");
}

void insertionSort( int *arr ) {
        traversing( arr );
        for(int i=1; i<=ln; i++) {
                int x = arr[i];
                int j = i-1;
                while( j >= 1 && arr[j] > x ) {
                        arr[j+1] = arr[j];
                        j--;
                }
                arr[j+1] = x;
        }
        printf("\nThe sorted array :\n");
        for(int i=1; i<=ln; i++) printf("%d ", arr[i]);
        printf("\n");
}

void bubbleSort( int *arr ) {
        traversing( arr );
        for(int i=1; i<ln; i++) {
                for(int j=i+1; j<=ln; j++) {
                        if( arr[i] > arr[j] ) swap(arr[i], arr[j]);
                }
        }
        printf("\nThe sorted array :\n");
        for(int i=1; i<=ln; i++) printf("%d ", arr[i]);
        printf("\n");
}

int main() {
        int ar[10000], choice;
        printf("\n****** Basic array operations ******\n");
        printf("\nEnter the number of elements in the array.........\n");
        scanf("%d", &ln);
        printf("Input %d numbers \n", ln);
        for(int i=1; i<=ln; i++) scanf("%d", &ar[i]);
        mainMenu();
        while( scanf("%d", &choice) == 1 ) {
                if( choice == 1 ) {
                        traversing( ar );
                }
                else if( choice == 2 ) {
                        int vlu, pos;
                        printf("\nEnter the position & the value to insert : \n");
                        scanf("%d %d", &pos, &vlu);
                        insertion( ar, pos, vlu );
                        traversing( ar );
                }
                else if( choice == 3 ) {
                        int pos;
                        printf("\nEnter the position to delete : \n");
                        scanf("%d", &pos);
                        deletion(ar, pos);
                        traversing(ar);
                }
                else if( choice == 4 ) {
                        printf("\n1. Liner Search\n2. Binary Search\nEnter choice & the element to search : \n");
                        int choicesrch, v;
                        scanf("%d %d", &choicesrch, &v);
                        if( choicesrch == 1 ) linerSearch( ar, v );
                        else binarySerach( ar, v );
                }
                else if( choice == 5 ) {
                        printf("\nWays for Sorting\n");
                        printf("1. Bubble Sort\n2.Insertion Sort\n3. Selection Sort\n");
                        int ch;
                        scanf("%d", &ch);
                        if( ch == 1 ) bubbleSort( ar );
                        else if( ch == 2 ) insertionSort( ar );
                        else if( ch == 3 ) selectionSort( ar );
                }
                else break;
                mainMenu();
        }

        return 0;
}

