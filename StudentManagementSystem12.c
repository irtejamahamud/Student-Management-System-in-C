#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node node;

struct data{
char name[20];
char id[20];
char mobile_no[20];
char email[30];
char date_of_birth[20];
char gender[20];
char batch[20];
char dept[20];
}std;

typedef struct data STD;
struct Node{
struct Node *next;
STD info;
}*head=NULL;

FILE *file,*f1;
int f=0,m=0,k=0;

void saved_data(){

   node *temp,*new_node;
    f=0;
    m=0;
    head=NULL;
    rewind(file);
    while((fread(&std,sizeof(std),1,file))==1)
    {
        temp=(node*)malloc(sizeof(node));
        strcpy(temp->info.name,std.name);
        strcpy(temp->info.id,std.id);
        strcpy(temp->info.mobile_no,std.mobile_no);
        strcpy(temp->info.email,std.email);
        strcpy(temp->info.batch,std.batch);
        strcpy(temp->info.dept,std.dept);
        strcpy(temp->info.id,std.id);
        strcpy(temp->info.gender,std.gender);
        if(strcmp(temp->info.gender,"F")==0||strcmp(temp->info.gender,"f")==0)
            f++;
        if(strcmp(temp->info.gender,"M")==0||strcmp(temp->info.gender,"m")==0)
            m++;
        strcpy(temp->info.date_of_birth,std.date_of_birth);

        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            new_node=temp;
        }
        else
        {
            new_node->next=temp;
            new_node=temp;
        }

    }
}
void addrecord(){
    system("cls");
    print_title();
    char check='y';
    //int k=1;
    while(check=='y'||check=='Y')
    {
        k++;
        printf("\t\tStudent %d:\n",k);

        fflush(stdin);
        printf("\t\t\t\tEnter Name:");
        gets(std.name);
        fflush(stdin);

        printf("\n\t\t\t\tEnter Student ID:");
        scanf("%s",std.id);

        fflush(stdin);
        printf("\n\t\t\t\tEnter Mobile No:");
        gets(std.mobile_no);

        fflush(stdin);
        printf("\n\t\t\t\tEnter E-Mail:");
        gets(std.email);

        fflush(stdin);
        printf("\n\t\t\t\tEnter Batch:");
        gets(std.batch);

        fflush(stdin);
        printf("\n\t\t\t\tEnter Department:");
        gets(std.dept);

        fflush(stdin);
        printf("\n\t\t\t\tIf Female write F or If Male write M:");
        scanf("%s",std.gender);

        printf("\n\t\t\t\tEnter Date of Birth(dd/mm/yy):");
        scanf("%s",std.date_of_birth);

        fwrite(&std,sizeof(std),1,file);
        printf("\n\t\t\t\tDo You Want to Add More Information (y/n)--> ");
        getchar();
        check=getchar();
        printf("\n");
        //k++;
    }

}
void print_title()
{
    system("cls");
    printf("\n\n\n");
    printf("\t\t\t\t\t\tSTUDENT MANAGEMENT SYSTEM\n");
    printf("\t\t\t\t\t*-------------------------------------*\n");
    printf("\n\n");
}

void SortStudents()
{
    saved_data();
    struct Node *trav = head, *right = head->next;
    struct data temp;

    while (trav->next != NULL)
    {
        right = trav->next;
        while (right != NULL)
        {
            if (trav->info.id > right->info.id)
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
    display_student();
}

void add_data_to_file()
{
    struct Node *temp = head;
    file = fopen("studentlist.txt", "w");
    if (file != NULL)
    {
        while (temp != NULL)
        {
            fwrite(&temp->info, sizeof(struct Node), 1, file);
            temp = temp->next;
        }
    }
}
void sortlist(){
system("cls");
print_title();
  printf("\n\n\t\t\tSuccessfully Sorted...");
  getch();
}

void modify_data(){
print_title();
    int check=0;
    char id1[100];
    printf("\n\t\tEnter roll Number to Modify:");
    scanf("%s",id1);

    rewind(file);
    while((fread(&std,sizeof(std),1,file)==1))
    {
        if(strcmp(id1,std.id)==0)
        {
            check=1;
            break;
        }
    }

    if(check==0)
        printf("\n\t\tRecord not found!!!\n\n");
    else
    {
        fseek(file,-sizeof(std),SEEK_CUR);
        printf("\n\t\tEnter new data :\n\n");

         fflush(stdin);
        printf("\t\t\t\tEnter Name:");
        gets(std.name);
        fflush(stdin);

        printf("\n\t\t\t\tEnter Student ID:");
        scanf("%s",std.id);

        fflush(stdin);
        printf("\n\t\t\t\tEnter Mobile No:");
        gets(std.mobile_no);

        fflush(stdin);
        printf("\n\t\t\t\tEnter E-Mail:");
        gets(std.email);

        fflush(stdin);
        printf("\n\t\t\t\tEnter Batch:");
        gets(std.batch);

        fflush(stdin);
        printf("\n\t\t\t\tEnter Department:");
        gets(std.batch);

        fflush(stdin);
        printf("\n\t\t\t\tIf Female write F or If Male write M:");
        scanf("%s",std.gender);

        printf("\n\t\t\t\tEnter Date of Birth:");
        scanf("%s",std.date_of_birth);

        fwrite(&std,sizeof(std),1,file);


    }
    if(check==1)
    {
        printf("\n\t\tRecord was changed successfully.\n");
    }
    printf("\n");
    system("pause");
}

void display_student()
{
    print_title();
    saved_data();
    node *c=head;
    if(head!=NULL)
    {
        printf("\n\n%-15s %-30s %-20s %-30s %-20s %-20s %s","ID","STUDENT NAME", "Mobile_No", "E-Mail", "Date-of-Birth", "Batch", "Department");
        printf("\n----------------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    }
    while(c!=NULL)
    {
        printf("%-15s %-30s %-20s %-30s %-20s %-20s %s\n",c->info.id,c->info.name,c->info.mobile_no,c->info.email,c->info.date_of_birth,c->info.batch,c->info.dept);
        c=c->next;
    }

   // printf("\n\nTotal Female Student: %d && Total Male Student: %d.\n",f,m);
    printf("\n");
    system("pause");

}

void delete_records(){

    print_title();
    char id1[100];
    FILE *tmp;
    if((tmp=fopen("tmp.txt","wb+"))==NULL)
    {
        printf("\n\t\tCan not be opened");

    }
    printf("\n\t\tEnter Student ID that to be delete:");
    scanf("%s",id1);
    int check=0;
    rewind(file);
    while((fread(&std,sizeof(std),1,file))==1)
    {
        if(strcmp(std.id,id1)==0)
        {
            check=1;
        }
        else
        {
            fwrite(&std,sizeof(std),1,tmp);
        }

    }
    fclose(file);
    fclose(tmp);
    remove("studentlist.txt");
    rename("tmp.txt","studentlist.txt");
    if((file=fopen("studentlist.txt","rb+"))==NULL)
    {
        printf("Can not be opened.");

    }
    if(check==1)
    {
        printf("\n\t\tThe record has been deleted successfully.\n");
    }
    if(check==0)
        printf("\n\t\t\tERROR!!Record Not Found..\n");

    printf("\n");
    system("pause");

}

void search_record(){

    print_title();
    saved_data();

    char flag='y';
    do
    {
        node *c=head,*temp=NULL;
        char id1[100];
        printf("\n\t\t\tEnter Student ID:");
        scanf("%s",id1);
        printf("\n");
        while(c!=NULL)
        {
            if(strcmp(c->info.id,id1)==0)
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
            printf("\n\t\tStudent\tID: %s\n",temp->info.id);
            printf("\n\t\tStudent\tBatch: %s\n",temp->info.batch);
            printf("\n\t\tStudent\tDepartment: %s\n",temp->info.dept);
            printf("\n\t\tStudent\tMobile_N0: %s\n",temp->info.mobile_no);
            printf("\n\t\tStudent\tE-mail: %s\n",temp->info.email);

            printf("\n\t\tGender\t: %s\n",temp->info.gender);
            printf("\n\t\tDate of Birth\t: %s\n\n\n",temp->info.date_of_birth);



        }
        getchar(); //For clearing the input buffer
        printf("Do you want to search more (Y/N) :");
        scanf("%c",&flag);

    }
    while(flag=='y'||flag=='Y');

    printf("\n");
    system("pause");


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

void maintitle(){
printf("\n\n\n\n\n\n\n");
printf("\t\t\t\t -------------------------------------------------------------------------\n");
printf("\t\t\t\t|                                                                         |\n");
printf("\t\t\t\t|\t\t\t STUDENT MANAGEMENT SYSTEM                        |\n");
printf("\t\t\t\t|                                                                         |\n");
printf("\t\t\t\t -------------------------------------------------------------------------\n");
getch();
}
int main()
{

    if((file=fopen("studentlist.txt","rb+"))==NULL)
    {
        if((file=fopen("studentlist.txt","w"))==NULL)
        {
            printf("The file can not be opened\n");
        }
    }
    maintitle();
    while(1)
    {


        int press;
        printf("\n");
        print_title();

        printf("\t\t\t\t\t\t1. Add New Records\n\n");
        printf("\t\t\t\t\t\t2. Display All-Students Records\n\n");
        printf("\t\t\t\t\t\t3. Delete Records\n\n");
        printf("\t\t\t\t\t\t4. Search and View Records\n\n");
        printf("\t\t\t\t\t\t5. Modify Records\n\n");
        printf("\t\t\t\t\t\t6. Sort Record\n\n");
        printf("\t\t\t\t\t\t7. Billing History\n\n");
        printf("\t\t\t\t\t\t8. Generate Mark-shit\n\n");
        printf("\t\t\t\t\t\t9. Exit\n\n");

        int choice;
        printf("\n\t\t\t\t\t\tEnter Option:--> ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:

        {
            addrecord();

        }
        break;
        case 2:

        {
            display_student();

        }
        break;
        case 3:
        {
            delete_records();
        }
        break;
        case 4:

        {
            search_record();

        }
        break;

        case 5:

        {
            modify_data();
        }
        break;
        case 6:
        {
           sortlist();
        }
        break;

         case 7:
            billsection();
            break;
        case 8:
            genaratemarkshit();
            break;

        case 9:

        {
            system("cls");
            exit(0);

        }
        break;
        default:
        {
            printf("Wrong Input.. END!!\n");

        }
        }
    }

    return 0;

}

