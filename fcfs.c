#include <stdio.h>
#include <errno.h>
#include <conio.h>

struct Process
{
    char pid[3];
    int bt;
    int at;
    int wt;
    int et;
    int tat;
};

int main()
{
    int n;
    printf("Enter the no. of processes: ");
    scanf("%d", &n);

    if (n <= 1){
        perror("Error");
    } 
    else{
        struct Process array[n];

        int i = 0;
        while (i < n)
        {
            struct Process p;
            printf("\nEnter the pid: ");
            scanf("%s", p.pid);
            printf("Enter the bt :");
            scanf("%d", &p.bt);
            printf("Enter the at :");
            scanf("%d", &p.at);

            p.wt =
            p.et =
            p.tat = 0;

            array[i] = p;

            if (i == 0)
            {
                array[i].wt = 0;
                array[i].et = array[i].at + array[i].bt;
                array[i].tat = array[i].at + array[i].bt;
            }
            else
            {
                array[i].wt = array[i - 1].et - array[i].at;
                array[i].et = array[i - 1].et + array[i].bt;
                if (array[i].at > array[i - 1].et)
                {
                    array[i].wt = 0;
                    array[i].et = array[i].at + array[i].bt;
                }
                array[i].tat = array[i].et - array[i].at;
            }
            i++;
            printf("\n");
        }

        printf("\n\nResult: ");
        int avgwt;
        int avgtat;
        for (int j = 0; j < n; j++)
        {
            printf("\n%s %d %d  --> %d  %d", array[j].pid, array[j].at, array[j].bt, array[j].wt, array[j].tat);
            avgwt = avgwt + array[j].wt;
            avgtat = avgtat + array[j].tat;
            printf("\n");
        }
        printf("\n avg waiting time = %d", avgwt / n);
        printf("\n avg tat time = %d", avgtat / n);
        printf("\n");
    }
    getch();
    return 0;
}