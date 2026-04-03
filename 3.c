#include <stdio.h>
int main() {
    int arr[3] = {1, 2, 3};
    int index, value;
    printf("Enter index and value: ");
    scanf("%d %d", &index, &value);
    arr[index] = value;
    printf("Done\n");
    return 0;
}
