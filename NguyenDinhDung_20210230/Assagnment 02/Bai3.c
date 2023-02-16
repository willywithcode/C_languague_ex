#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char date[20];
    char time[20];
    float temp;
    float total_temp = 0, temp1 = 0, temp2 = 0, temp3 = 0;
    int count = 0, count1 = 0, count2 = 0, count3 = 0;

    fp = fopen("temp.dat", "r");
    if (fp == NULL) {
        printf("Cannot open file");
        return 1;
    }
    // fscanf(fp, "%s %s %f", date,time, &temp);
    // int hour = atoi(time);
    // printf("%s %f %d\n",time,temp,hour);

    while (fscanf(fp, "%s %s %f", date, time, &temp) != EOF) {
        int hour;
        // sscanf(datetime + 11, "%d", &hour);
        hour = atoi(time);
        total_temp += temp;
        count++;
        if (hour >= 5 && hour < 16) {
            temp1 += temp;
            count1++;
        } else if (hour >= 16 && hour < 22) {
            temp2 += temp;
            count2++;
        } else {
            temp3 += temp;
            count3++;
        }
    }


    printf("Average temperature for the day: %.3f\n", total_temp/count);
    printf("Average temperature from 5:00 to 15:59:59: %.3f\n", temp1/count1);
    printf("Average temperature from 16:00 to 21:59:59: %.3f\n", temp2/count2);
    printf("Average temperature from 22:00 to 4:59:59: %.3f\n", temp3/count3);

    fclose(fp);
    return 0;
}
