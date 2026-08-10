#include <stdio.h>

int main()
{
    int total_lanes = 25;
    int rate_lanes = 16;
    int capacity_lanes = 9;

    printf("SHA-3 State = 1600 bits\n");
    printf("Block Size  = 1024 bits\n");
    printf("Lane Size   = 64 bits\n\n");

    printf("Rate lanes     = %d\n", rate_lanes);
    printf("Capacity lanes = %d\n", capacity_lanes);

    printf("\nInitial state:\n");
    printf("Non-zero lanes = %d\n", rate_lanes);
    printf("Zero lanes     = %d\n", capacity_lanes);

    printf("\nPermutation is ignored.\n");
    printf("The original zero lanes remain zero.\n");

    printf("\nTime required for all lanes to become non-zero: NEVER\n");

    return 0;
}
