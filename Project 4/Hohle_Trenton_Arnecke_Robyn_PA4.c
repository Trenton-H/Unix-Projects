/* Names: Trenton Hohle & Robyn Arnecke
 * Serial Numbers: 23           4
 * Group Number: 8
 * Course: 4350 - 251
 * Assignment: 4
 * Due Date: 4/10/19
 *
 * Was told by another student that during the day I missed Mr Gholoom mentioned only
 * displaying frequency out to 10 nums for formatting and preventing wrapping?
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("This Program is Written By Trenton and Robyn\n\n");
    printf("The function of this program is to find the frequency\n");
    printf("of each number that has been drawn in the Texas lotto game.\n");
    printf("The program :\n\n");
    printf("\t1. Calculates and displays the frequency of drawn numbers\n");
    printf("\t   in Texas Lotto in each year.\n");
    printf("\t2. Calculates and displays the overall frequency of each\n");
    printf("\t   number that has been drawn since the lotto started.\n");
    printf("\t3. Sorts the frequency numbers in Descending order. Display\n");
    printf("\t   the sorted list.\n");
    printf("\t4. Displays total number of integers in the entire file.\n\n");

    printf("For each year, the frequeny of drawn numbers in the Texas\n");
    printf("Lotto are as follows :-\n\n");

    int temp[7] = {0}; //holds the current pulls line
    int year [55] = {0};
    int total [55] = {0};
    int nums[55];
    int num, i;
    year[0] = 1992;
    int grandTotal = 0;

    char file[] = "lottofile.txt";
    FILE *fp = fopen(file, "r");

    if(fp==NULL)
    {
        printf("File not found.");
        return 0;
    }

    for(i = 0; i<55; i++)
    {
        nums[i] = i;
    }

    //printf("Year -> No 1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14\t15\t16\t17\t18\t19\t20\t21\t22\t23\t24\t25\t26\t27\t28\t29\t30\t31\t32\t33\t34\t35\t36\t37\t38\t39\t40\t41\t42\t43\t44\t45\t46\t47\t48\t49\t50\t51\t52\t53\t54\n\n");

    printf("Year -> No 1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n\n"); //temp to test code easier.
    printf(" |\n");

    while(fscanf(fp,"%d %d %d %d %d %d %d", &temp[0], &temp[1], &temp[2], &temp[3], &temp[4], &temp[5], &temp[6]) != EOF)
    {
        if(year[0] == temp[0]) {
            for (i = 1; i < 7; i++) {
                num = temp[i];
                year[num]++;
                total[num]++;
            }

        }
        else
        {
            printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",year[0], year[1], year[2], year[3], year[4], year[5], year[6], year[7], year[8], year[9], year[10]); //ultimately print whole year
            year[0] = temp[0];
            for(i = 1; i<55; i++) //loop to zero out
                year[i] = 0;
            for (i = 1; i < 7; i++) {
                num = temp[i];
                year[num]++; //= year[num] + 1;
                total[num]++;
            }
        }
    }
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",year[0], year[1], year[2], year[3], year[4], year[5], year[6], year[7], year[8], year[9], year[10]); //Will output 2019. this line in the loop outputs all other years

    for(i = 0; i < 55; i++) //calculates the total number of ints read
    {
        grandTotal+= total[i];
    }

    int j, tempHolder;
    int biggest = total[1];
    int spot = 0;
    /*for(i = 1; i < 54; i++) //selection sort. Currently doesn't work.
    {
        for(j = i+1; j < 55; j++)
        {
            if(total[j] > biggest)
            {
                biggest = total[j];
                spot = j;
            }
        }
        tempHolder = total[i]; //shifts values of frequency
        total[i] = total[spot];
        total[spot] = tempHolder;

        tempHolder = nums[i]; //swaps around lotto number value
        nums[i] = nums[j];
        nums[j] = tempHolder;
        printf("%d ", total[i]);
    }*/
    printf("\n\n");


    printf("Over All The Data, The Frequency of drawn numbers in the\n");
    printf("Texas Lotto are\t:-\n\n");
    printf("No    ---> %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n|\n",nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7], nums[8], nums[9], nums[10]);
    printf("Frequency  %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",total[1], total[2], total[3], total[4], total[5], total[6], total[7], total[8], total[9], total[10]);

    printf("\n\n\n");
    printf("The MOST frequent Numbers Drawn in the Texas LOTTO Game from\n");
    printf("Highest to Lowest\n\n\n");
    printf("The Number ->    %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n|\n",nums[1], nums[2], nums[3], nums[4], nums[5], nums[6], nums[7], nums[8], nums[9], nums[10]);
    printf("Was Drawn ->     %d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",total[1], total[2], total[3], total[4], total[5], total[6], total[7], total[8], total[9], total[10]);

    printf("\n\n");
    printf("Total Number of integers read\t:    %d", grandTotal);

    return 0;
    //There are no footer comments on his assignment page.
}