#include <stdio.h>

int main()
{
    int a[100], n, i, j, choice, temp, min, key;
    char ch;

    do
    {
        printf("\n===== SORTING MENU =====\n");
        printf("1. Insertion Sort\n");
        printf("2. Selection Sort\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("Enter the number of elements: ");
        scanf("%d", &n);

        printf("Enter the elements:\n");
        for(i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }

        if(choice == 1)
        {
            // Insertion Sort
            for(i = 1; i < n; i++)
            {
                key = a[i];
                j = i - 1;

                while(j >= 0 && a[j] > key)
                {
                    a[j + 1] = a[j];
                    j--;
                }

                a[j + 1] = key;
            }

            printf("\nArray after Insertion Sort:\n");
            for(i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
        }
        else if(choice == 2)
        {
            // Selection Sort
            for(i = 0; i < n - 1; i++)
            {
                min = i;

                for(j = i + 1; j < n; j++)
                {
                    if(a[j] < a[min])
                    {
                        min = j;
                    }
                }

                temp = a[i];
                a[i] = a[min];
                a[min] = temp;
            }

            printf("\nArray after Selection Sort:\n");
            for(i = 0; i < n; i++)
            {
                printf("%d ", a[i]);
            }
        }
        else
        {
            printf("Invalid Choice!");
        }

        printf("\n\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &ch);

    } while(ch == 'y' || ch == 'Y');

    printf("\nProgram Ended.\n");

    return 0;
}