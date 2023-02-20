#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    long studentId;
    char name[30];
    char mobileno[30];
    char Dept[20];
    char batch[20];
    char Email[30];
    char Date_of_birth[30];
} STUDENT;

typedef struct node
{
    struct node *prev;
    STUDENT info;
    struct node *next;
} NODE;

NODE *head = NULL;

void print_title()
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t\t\tSTUDENT MANAGEMENT SYSTEM\n");
    printf("\t\t\t\t\t*-------------------------------------*\n");
    printf("\n\n");
}

void maintitle(){
printf("\n\n\n\n\n\n\n");
printf("\t\t\t\t -------------------------------------------------------------------------\n");
printf("\t\t\t\t|                                                                         |\n");
printf("\t\t\t\t|\t\t\t STUDENT MANAGEMENT SYSTEM                        |\n");
printf("\t\t\t\t|                                                                         |\n");
printf("\t\t\t\t -------------------------------------------------------------------------\n");
getch();
}

int menu_function()
{
    system("cls");
    print_title();
    int choice;
    printf(" \t\t\t\t1. Add Student\n");
    printf(" \t\t\t\t2. Display All-Student\n");
    printf(" \t\t\t\t3. Delete Record\n");
    printf(" \t\t\t\t4. Modify record\n");
    printf(" \t\t\t\t5. Search record\n");
    printf(" \t\t\t\t6. Sort Student\n");
    printf(" \t\t\t\t7. Billing History\n");
    printf(" \t\t\t\t8. Generate Mark-shit\n");
    printf(" \t\t\t\t9. EXIT\n");
    printf(" \t\t\tEnter your choice-->>  ");
    scanf("%d", &choice);
    if (choice < 0 || choice > 10)
    {
        printf(" Error Enter valid choice\n");
    }
    return choice;
}

void FreeList()
{
    while (CountNodes(head))
    {
        DeleteStudent();
    }
}

int CountNodes(NODE *trav)
{
    int count = 0;
    while (trav != NULL)
    {
        count++;
        trav = trav->next;
    }
    return count;
}
void DeleteStudent()
{
    NODE *temp = head;
    head = head->next;
    free(temp);
    temp = NULL;
}

void DeleteStudentMenu()
{
    system("cls");
    NODE *temp = head;
    long id;
    printf("Enter the id you want to delete: ");
    scanf("%ld", &id);
    int position = 1;
    while (temp != NULL)
    {
        if (id == temp->info.studentId)
        {
            if (position == 1)
            {
                head = head->next;
            }
            else if (position == CountNodes(head))
            {
                while (temp->next->next != NULL)
                    temp = temp->next;
                temp->next = NULL;
            }
            else
            {
                for (int i = 2; i <= position; i++)
                {
                    if (temp->next != NULL)
                        temp = temp->next;
                }
                temp->next = temp->next->next;
            }
        }
        temp = temp->next;
        position++;
    }
}


void addrecord(STUDENT *student)
{
    system("cls");
    print_title();
    printf("\t\t\t\tEnter Student ID: ");
    scanf("%ld", &student->studentId);
    fflush(stdin);
    printf("\t\t\t\tEnter Student name: ");
    gets(student->name);
    fflush(stdin);
    printf("\t\t\t\tEnter Phone Number: ");
    gets(student->mobileno);
    fflush(stdin);
    printf("\t\t\t\tEnter Email: ");
    gets(student->Email);
    fflush(stdin);
    printf("\t\t\t\tEnter Batch: ");
    gets(student->batch);
    fflush(stdin);
    printf("\t\t\t\tEnter Department: ");
    gets(student->Dept);
    fflush(stdin);
    printf("\t\t\t\tEnter Date Of Birth(dd/mm/yy): ");
    gets(student->Date_of_birth);
    fflush(stdin);
    printf("\t\t\t\tStudent added to list successfully...\n");
    system("pause");
}

void search_record(){

    print_title();

    char flag='y';
    do
    {
        NODE *c=head,*temp=NULL;
        long id1;
        printf("\n\t\t\tEnter Student ID:");
        scanf("%ld",&id1);
        printf("\n");
        while(c!=NULL)
        {
            if(c->info.studentId==id1)
            {
                temp=c;
                break;
            }
            c=c->next;
        }
        if(temp==NULL)
            printf("\t\tRecord Not found!!!\n\n");
        else
        {

            printf("\n\t\tStudent\tName: %s\n",temp->info.name);
            printf("\n\t\tStudent\tID: %ld\n",temp->info.studentId);
            printf("\n\t\tStudent\tBatch: %s\n",temp->info.batch);
            printf("\n\t\tStudent\tDepartment: %s\n",temp->info.Dept);
            printf("\n\t\tStudent\tMobile_N0: %s\n",temp->info.mobileno);
            printf("\n\t\tStudent\tE-mail: %s\n",temp->info.Email);
            printf("\n\t\tDate of Birth\t: %s\n\n\n",temp->info.Date_of_birth);



        }
        getchar();
        printf("Do you want to search more (Y/N) :");
        scanf("%c",&flag);

    }
    while(flag=='y'||flag=='Y');

    printf("\n");
    system("pause");


}

NODE *CreateNode()
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void AddtoStudentlist(STUDENT student)
{
    NODE *new_node;
    new_node = CreateNode();
    new_node->info = student;

    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void DisplayStudents(NODE *trav)
{
    system("cls");
    print_title();
    if (trav == NULL)
    {
        printf(" Student list is empty...\n");
    }
    else
    {
        system("cls");
        printf("\n\n%-15s %-30s %-20s %-30s %-20s %-20s %s","ID","STUDENT NAME", "Mobile_No", "E-Mail", "Date-of-Birth", "Batch", "Department");
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
        while (trav != NULL)
        {

             printf("%-15d %-30s %-20s %-30s %-20s %-20s %s\n",trav->info.studentId,trav->info.name,trav->info.mobileno,trav->info.Email,trav->info.Date_of_birth,trav->info.batch,trav->info.Dept);
            trav = trav->next;
        }
        printf("\n");
    }
    getch();
}

void SortStudents()
{
    NODE *trav = head, *right = head->next;
    STUDENT temp;

    while (trav->next != NULL)
    {
        right = trav->next;
        while (right != NULL)
        {
            if (trav->info.studentId > right->info.studentId)
            {
                temp = trav->info;
                trav->info = right->info;
                right->info = temp;
            }
            right = right->next;
        }
        trav = trav->next;
    }
    printf("\n\nSuccessfully Sorted...");
    getch();
}

void AddStudentsToFile()
{
    NODE *trav = head;
    FILE *fp;
    fp = fopen("studentrecord.txt", "w");
    if (fp != NULL)
    {
        while (trav != NULL)
        {
            fwrite(&trav->info, sizeof(STUDENT), 1, fp);
            trav = trav->next;
        }
    }
    fclose(fp);
}

void ReadStudentsFromFile()
{
    STUDENT student;
    FILE *fp;
    fp = fopen("studentrecord.txt", "r");
    if (fp != NULL)
    {
        while ((fread(&student, sizeof(STUDENT), 1, fp)) != 0)
        {
            AddtoStudentlist(student);
        }
    }
    fclose(fp);
}

void genaratemarkshit(){
system("cls");
print_title();
printf("\n\t\t\t\tThis Section Will Available Soon!\n");
printf("\n\t\t\t\tThank You !\n");
getch();
}

void billsection(){
system("cls");
print_title();
int ch;
printf("\n\t\t\t\tSelect How You Want To Payment\n");
printf("\t\t\t\t1. BKASH\n");
printf("\t\t\t\t2. ROCKET\n");
printf("\t\t\t\t3. NAGAD\n");
printf("\t\t\t\t ENTER YOUR CHOICE:");
scanf("%d",&ch);
system("cls");
print_title();
printf("\n\t\t\t\tThis Section Will Available Soon!\n");
printf("\n\t\t\t\tThank You !\n");
getch();
}

int main()
{

    int data,choice;
    maintitle();
    STUDENT student;
    ReadStudentsFromFile();

    do{
            print_title();
       choice = menu_function();

        switch (choice)
        {
        case 1 :
            addrecord(&student);
            AddtoStudentlist(student);
            break;

        case 2 :
            DisplayStudents(head);
            printf("\n");
            break;

        case 3 :
            DeleteStudentMenu();
            break;
        case 5 :
            search_record();
            printf("\n");
            break;
        case 6:
            if (head == NULL)
            {
                printf(" No Student to sort...\n");
                break;
            }
            SortStudents();
            AddStudentsToFile();
            break;
        case 7:
            billsection();
            break;
        case 8:
            genaratemarkshit();
            break;

        case 9:
            AddStudentsToFile();
            exit(0);
        }
    }while(1);
    AddStudentsToFile();
    FreeList();
    return 0;
}
