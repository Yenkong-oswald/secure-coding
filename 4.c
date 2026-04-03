#include <stdio.h>
int main() {
    int arr[3] = {1, 2, 3};
    int index, value;
    printf("Enter index and value: ");
    scanf("%d %d", &index, &value);
    if (index >= 0 && index < 3) {
        arr[index] = value;
        printf("Value updated\n");
    } else {
        printf("Invalid index!\n");
    }
    return 0;
}
