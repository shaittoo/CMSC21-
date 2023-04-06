#include <stdio.h>

int main() {
    int days, start_day, i, day;
    printf("Enter the number of days in the month: ");
    scanf("%d", &days);
    if (days < 28 || days > 31) {
        printf("Invalid input. Please enter a value between 28 and 31.\n");
        return 1;
    }
    printf("Enter the day of the week on which the month begins (1=Sunday, 7=Saturday): ");
    scanf("%d", &start_day);
    if (start_day < 1 || start_day > 7) {
        printf("Invalid input. Please enter a value between 1 and 7.\n");
        return 1;
    }
    printf("  S   M   T   W   T   F   S\n");
    printf(" --- --- --- --- --- --- ---\n");
    for (i = 1; i < start_day; i++) {
        printf("    ");
    }
    for (day = 1; day <= days; day++) {
        printf("%3d ", day);
        if ((start_day + day - 1) % 7 == 0) {
            printf("\n");
        }
    }
    if ((start_day + day - 1) % 7 != 1) {
        printf("\n");
    }
    return 0;
}

