#include <stdio.h>
int main () 
{
    printf("enter the number of elements in the array: ");
    int n;
    scanf("%d", &n);
    printf("enter the elements of the array: ");
    int arr[n];
    for (int i = 0; i < n; i++)
    {scanf("%d", &arr[i]);
    }
    printf("enter the element to be deleted: ");
      
    int x ;
    scanf("%d", &x);
    int pos = -1;  
    for (int i = 0; i < n; i++)
    {        if (arr[i] == x)
        {            pos = i;
            break;
        }   } 
        printf("position of the element to be deleted: %d\n", pos + 1);
    if (pos == -1)
    {        printf("element not found in the array.\n");
    } else
    {        for (int i = pos; i < n - 1; i++)
        {            arr[i] = arr[i + 1];
        }        n--;
        printf("array after deletion:\n");        for (int i = 0; i < n; i++)
        {            printf("%d ", arr[i]);
        }        printf("\n");
    }

       return 0;
}