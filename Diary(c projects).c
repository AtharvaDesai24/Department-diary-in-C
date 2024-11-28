#include <stdio.h>
#include<string.h>

//Function Declaration
void view_diary();
void add_record();
void delete_record();
void edit_record();
    //Global variable declaration
    int n, set_record=0, indx=0;
    char record_entry[30][5][30];
    int remove_record;
    //Main section where execution happens
void main()
{
    char cont;
    //Menu for operations
    again:              //Jump statement to execute block again
    printf("\npress 1 to view department dairy");
    printf("\npress 2 to Add record to department dairy");
    printf("\npress 3 to delete department diary records ");
    printf("\npress 4 to edit department diary ");
    printf("\npress 5 to exit ");    
    printf("\nENTER YOUR CHOICE:--");        
    scanf("%d",&n);
    switch(n)
    {
        case 1: view_diary();
                break;
        case 2: add_record();
                break;
        case 3: delete_record();
                break;
        case 4: edit_record();
                break;
        case 5: printf("Exiting...\n");
                break;
        default: printf("\nInput invalid");
    }
    printf("Continue?[Y/N]\n");
    scanf("%s", &cont);
    if (cont=='y' || cont=='Y')
    {
        goto again;         //Jump statement
    }
}

//Function to view diary
void view_diary()
{
    printf("Sr.No.\t\tName\t\tAddress\t\tDuration of task\t\tDate\t\ttime\t\t\n");
    for(int j=0;j<set_record;j++)
    {
        printf("%d\t\t", j+1);
        for(int k=0;k<5;k++)
        {
            printf("%s\t\t", record_entry[j][k]);
            if(k==2)
            {
                printf("\t\t");
            }
        }
        printf("\n");
    }
}

//Function to add records to the diary
void add_record()
{
    printf("Enter number of records to be added:");
    scanf("%d", &set_record);
    for(int i=0;i<set_record;i++)
    {
        printf("Enter record: %d\n", indx+1);
        printf("Enter name: ");
        scanf("%s", record_entry[indx][0]);
    
        printf("Enter address: ");
        scanf("%s", record_entry[indx][1]);
    
        printf("Enter duration of task: ");
        scanf("%s", record_entry[indx][2]);
    
        printf("Enter date: ");
        scanf("%s", record_entry[indx][3]);
    
        printf("Enter time: ");
        scanf("%s", record_entry[indx][4]);

        indx++;
    }
    set_record=indx;
}

//Function to remove records from diary
void delete_record()
{
    printf("Enter sr no. of record to be deleted\n");
    scanf("%d", &remove_record);
    indx=remove_record-1;
    for(int l=0;l<5;l++)
    {
        if(indx==-1)
        {
            strcpy(record_entry[0][l], record_entry[1][1]);
        }
        else
        {
         strcpy(record_entry[indx][l], record_entry[indx+1][l]);
        }
    }
    set_record--;
}

//Function to edit records in diary
void edit_record()
{
    int edit_rec;
    char cont;
    edit_again:             //Jump statement to execute block again
    printf("Enter sr.no. of record to be edited\n");
    scanf("%d", &indx);
    printf("1.Name\n2.Adress\n3.Duration of task\n4.Date\n5.Time\n");
    printf("Enter option to be edited\n");
    scanf("%d", &edit_rec);
    switch(edit_rec)
    {
        case 1: printf("Enter Name:");
                scanf("%s", record_entry[indx-1][0]);
                break;
        case 2: printf("Enter address:");
                scanf("%s", record_entry[indx-1][1]);
                break;
        case 3: printf("Enter Duration of task:");
                scanf("%s", record_entry[indx-1][2]);
                break;
        case 4: printf("Enter Date:");
                scanf("%s", record_entry[indx-1][3]);
                break;
        case 5: printf("Enter Time:");
                scanf("%s", record_entry[indx-1][4]);
                break;
    }
    printf("Any more options to be edited?[Y/N]\n");
    scanf("%s", &cont);
    if (cont=='y' || cont=='Y')
    {
        goto edit_again;            //Jump statement
    }
}


