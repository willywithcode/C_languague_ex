#include <stdio.h>
#include <string.h>
#define NUM_TEAM_GROUP 4
#define MAX_GROUP 8
typedef struct Team {
    char GroupID;
    char TeamName[20];
    int Points;
    int Goal_diff;

}Team;


Team Clubs[40];
int num_team = 0;
char group_name[MAX_GROUP];
int num_groups = 0;
int check_group(char name) {
    for (int i = 0; i < num_groups; i++){
        if (strcmp(name,group_name[i]) == 0){
            return i;
        } 
    }
    return -1;
}
void Add_Group(int number) {
    for (int i = 0; i < number; i++) {
        printf("Input Group Name:");
        do {
            scanf("%c",&group_name[num_groups]);
        } while (group_name[num_groups] >'Z' || group_name[num_groups]<'A' || check_group(group_name[num_groups] != -1));
        num_groups++;
        printf("Input the group %c\n",group_name[num_groups-1]);
        for (int j = 0; j < NUM_TEAM_GROUP; j++) {
            Clubs[num_team].GroupID = group_name[num_groups-1];
            getchar();printf("Input Team Name: "); fgets(Clubs[num_team].TeamName,20,stdin);
            Clubs[num_team].TeamName[strcspn(Clubs[num_team].TeamName, "\n")] = '\0'; 
            printf("Input points:");scanf("%d",&Clubs[num_team].Points);
            printf("Input Goal Different:");scanf("%d",&Clubs[num_team].Goal_diff);
            num_team++;
        }   
    }
}
void Print_Info_each_group() {
    for (int i = 0; i < strlen(group_name); i ++) {
        printf("Group %c\n",group_name[i]);
        printf("Team \tPoints\tGoal Differents\n");
        for (int j = 0; j < num_team; j++) {
            if(Clubs[i].GroupID == group_name[i]) {
                printf("Team %s\t",Clubs[i].TeamName);
                printf("Points: %d\t",Clubs[i].Points);
                printf("Goal Diff: %d\t",Clubs[i].Goal_diff);
            }
        }
    }
}
int main() {
    int choice;
    while(1) {
        do {
            printf("Choose one number between 1 and 6\n");
            printf("1. Add group\n");
            printf("2. Print infomation's Group\n");
            printf("3. Find information of a team\n");
            printf("4. Update group\n");
            printf("5. Sort team in a group\n");
            printf("6. Exit.\n");
            scanf("%d", &choice);
    } while (choice < 1 || choice > 6);
        switch (choice) {
            case 1: 
                int num =0;
                do {
                    printf("Input the number of groups: ");scanf("%d", &num);
                } while(num < 1 || num +num_groups > 8);
                Add_Group(num);
            case 2:
            case 3: 
            case 4:
            case 5:    
            case 6:
                return 0;
        }
    }
} 