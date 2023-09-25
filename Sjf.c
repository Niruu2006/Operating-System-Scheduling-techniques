#include <stdio.h>

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

    struct Process array[n];
    
    int a = 0;
    while (a < n)
    {
        struct Process p;
        printf("\nEnter the pid: ");
        scanf("%s", p.pid);
        printf("Enter the bt :");
        scanf("%d", &p.bt);
        printf("Enter the at :");
        scanf("%d", &p.at);

        p.wt = 0;
        p.et = 0;
        p.tat = 0;

        array[a] = p;

        a++;
        printf("\n");
    }

    for (int i = 0; i < n-1; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (array[i].at > array[j].at){
                struct Process temp = array[i];
                array[i] = array[j];
                array[j] = temp;
             }
        }
    }
    
    int d=0;
    while (array[d].bt > array[d+1].bt && array[d].at == array[d+1].at)
    {
        struct Process temp = array[d];
        array[d] = array[d+1];
        array[d+1] = temp;

        d++;
    }

    for (int b = 0; b < n; b++)
    {
        if(b == 0){
            array[b].wt = 0;
            array[b].et = array[b].at + array[b].bt;
        }else{
            array[b].wt = array[b-1].et - array[b].at;
            array[b].et = array[b-1].et + array[b].bt;
        }
        array[b].tat = array[b].et-array[b].at;
    }

    printf("\n\nResult: ");
    int avgwt=0;
    int avgtat=0;
    for (int c = 0; c < n; c++)
    {
        printf("\n%s %d %d  --> %d  %d", array[c].pid,array[c].at,array[c].bt,array[c].wt,array[c].tat);
        avgwt = avgwt + array[c].wt;
        avgtat = avgtat + array[c].tat;
        //printf("%d\n",array[c].tat);
    }
    printf("\n avg waiting time = %d", avgwt/n);
    printf("\n avg tat time = %d", avgtat/n);
    printf("\n");

    return 0;
}