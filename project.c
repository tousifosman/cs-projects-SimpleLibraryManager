#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/*functions*/
void settings(void);
void del(void);
void manage(void);
void search_b(void);
void search_s(void);
void issue(void);
void search_issu(void);
void add_log(void);
void add_b(void);
void add_s(void);
void edit_b(void);
void edit_s(void);
void viewall(void);
void returnbook(void);
void resetprogram(void);
void re(void);

/*filing*/
void save_b(void);
void load_b(void);
void save_s(void);
void load_s(void);
void save_l(void);
void load_l(void);
void display_b(int x);
void display_s(int x);
int logchk(void);

/*global variables*/
int key_b=0,key_s=0,key_l=0;
char log_l[50][50];
struct b_data_t
{
    char book_name[50];
    int book_id;
    char author[30];
    char category[20];//{"Philosophy","Science","economics","History","journal"};
    int quantity;
    int rack;
}data_b[1000];

struct s_data_t
{
    char student_name[50];
    int student_id;
    int book[20];
    int key;
}data_s[1000];

/*Program starts from hear*/

int main()
{
    load_b();
    load_s();
    load_l();
    save_b();
    save_s();
    save_l();

    if(logchk())
        return 0;
    else
        printf("\nID Mached!!\n");
    while(1)
    {
        printf("\n");
        printf("###########################\n");
        printf("#           Menu          #\n");
        printf("#   ___________________   #\n");
        printf("# 1->View all             #\n");
        printf("# 2->Manage Libraby       #\n");
        printf("# 3->Settings             #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("# 0->Exit                 #\n");
        printf("###########################\n");
        printf("\nPress a number for ation:");
        switch(getche())
        {
            case '1':viewall();
                    break;
            case '2':manage();
                    break;
            case '3':settings();
                    break;
            case '0':
                    return 0;
            default:printf("worng action!!\a");
        }
    }
}

void save_l(void)
{
    FILE* fp;
    if((fp=fopen("data_l","wb"))==NULL)
    {
        printf("\nWARNING!!data missing!\n\a");
        exit(1);
    }
    if(fwrite(&key_l,sizeof key_l,1,fp)!=1)
    {
        printf("\nError writing Login Data!!\a");
        exit(1);
    }
    if(fwrite(log_l,sizeof log_l,1,fp)!=1)
    {
        printf("\nError writing Login Data!!\n\a");
        exit(1);
    }
}

void load_l(void)
{
    FILE* fp;
    if((fp=fopen("data_l","rb"))==NULL)
    {
        printf("\nWARNING!!data missing!\n\a");
    }
    if(fread(&key_l,sizeof key_l,1,fp)!=1)
    {
        printf("\nError reading Key Point!!\a");
    }
    if(fread(log_l,sizeof log_l,1,fp)!=1)
    {
        printf("\nError reading data!!\n\a");
    }
    fclose(fp);
}

void save_b(void)
{
    FILE* fp;
    if((fp=fopen("data_b","wb"))==NULL)
    {
        printf("\nWARNING!!data missing!\a");
        exit(1);
    }
    if(fwrite(&key_b,sizeof key_b,1,fp)!=1)
    {
        printf("\nError writing Key Point!!\a");
        exit(1);
    }
    if(fwrite(data_b,sizeof data_b,1,fp)!=1)
    {
        printf("\nError writing data!!\n\a");
        exit(1);
    }
    fclose(fp);
}

void load_b(void)
{
    FILE* fp;
    if((fp=fopen("data_b","rb"))==NULL)
    {
        printf("\nWARNING!!data missing!\n\a");
    }
    if(fread(&key_b,sizeof key_b,1,fp)!=1)
    {
        printf("\nError reading Key Point!!\a");
    }
    if(fread(data_b,sizeof data_b,1,fp)!=1)
    {
        printf("\nError reading data!!\n\a");
    }
    fclose(fp);
}

void save_s(void)
{
    FILE* fp;
    if((fp=fopen("data_s","wb"))==NULL)
    {
        printf("\nWARNING!!data missing!\n\a");
        exit(1);
    }
    if(fwrite(&key_s,sizeof key_s,1,fp)!=1)
    {
        printf("Error writing Key Point!!\a");
        exit(1);
    }
    if(fwrite(data_s,sizeof data_s,1,fp)!=1)
    {
        printf("Error writing data!!\n\a");
        exit(1);
    }
    fclose(fp);
}

void load_s(void)
{
    FILE* fp;
    if((fp=fopen("data_s","rb"))==NULL)
    {
        printf("\nWARNING!!data missing!\a");
    }
    if(fread(&key_s,sizeof key_s,1,fp)!=1)
    {
        printf("\nError reading Key Point!!\a");
    }
    if(fread(data_s,sizeof data_s,1,fp)!=1)
    {
        printf("\nError reading data!!\n\a");
    }
    fclose(fp);
}

int logchk(void)
{
    char id[50];
    int i,j=5;

    load_l();
    while(j--)
    {
        printf("\nLogIN ID:");
        gets(id);
        if(!strcmp(id,"1"))
            add_log();
        else
        {
            for(i=0;i<key_l;i++)
            {
                if(!strcmp(id,log_l[i]))
                    return 0;
            }
        }
    }
    printf("\nAccess Denied\n");
    return 1;

}

void manage(void)
{
    while(1)
    {
        printf("\n");
        printf("###########################\n");
        printf("#      Manage Library     #\n");
        printf("#   ___________________   #\n");
        printf("# 1->Search books         #\n");
        printf("# 2->Search Students      #\n");
        printf("# 3->Search Issued book   #\n");
        printf("# 4->Issue Books          #\n");
        printf("# 5->Return Book          #\n");
        printf("# 6->Add Books            #\n");
        printf("# 7->Add Students         #\n");
        printf("# 8->Edit Books           #\n");
        printf("# 9->Edit Students        #\n");
        printf("#                         #\n");
        printf("# 0->Menu                 #\n");
        printf("###########################\n");
        printf("\nPress a number for ation:");
        switch(getche())
        {
            case '1':search_b();
                    break;
            case '2':search_s();
                    break;
            case '3':search_issu();
                    break;
            case '4':issue();
                    break;
            case '5':returnbook();
                    break;
            case '6':add_b();
                    break;
            case '7':add_s();
                    break;
            case '8':edit_b();
                    break;
            case '9':edit_s();
                    break;
            case '0':
                    return;
        }
    }
}

void settings(void)
{
    load_b();
    load_s();
    while(1)
    {
        printf("\n");
        printf("###########################\n");
        printf("#         Settings        #\n");
        printf("#   ___________________   #\n");
        printf("# 1->Delet deta           #\n");
        printf("# 2->Add Login ID         #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("#                         #\n");
        printf("# R->***ResetProgram      #\n");
        printf("#                         #\n");
        printf("# 0->Menu                 #\n");
        printf("###########################\n");
        printf("\nPress a number for ation:");
        fflush(stdin);
        switch(getche())
        {
            case '1':del();
                    break;
            case '2':add_log();
                    break;
            case 'R':re();
                    break;
            case '0':
                    return ;
            default:printf("\nworng action!!\a");
        }
    }
}
void del(void)
{
    char x,y[50];
    int a,b,i,j,fg=1;
    load_b();
    load_s();
    load_l();
    while(1)
    {
        printf("\n\n1->Delete Book\n2->Delete Student\n3->Delete Login ID\n0->Back\n\naction:");
        x=getche();fflush(stdin);
        if(x=='1')
        {
            printf("\nBook ID:");
            scanf("%d",&a);
            if(key_b<0)
            {
                printf("\nNo Book found\n");
                return;
            }
            if(a>=key_b)
            {
                printf("\nID Not Found!!");
                return;
            }
            for(i=0;i<=key_s;i++)
            {
                for(j=1;j<=data_s[i].key;j++)
                {
                    if(data_s[i].book[j]==a)
                    {
                        printf("\nBook is Issued!!Can not Delete Data!!\n\n");
                        return;
                    }
                }
            }
            for(i=a;i<key_b-1;i++)
            {
                data_b[i].book_id=data_b[i+1].book_id;
                strcpy(data_b[i].book_name,data_b[i+1].book_name);
                strcpy(data_b[i].author,data_b[i+1].author);
                strcpy(data_b[i].category,data_b[i+1].category);
                data_b[i].quantity=data_b[i+1].quantity;
                data_b[i].rack=data_b[i+1].rack;
            }
            key_b--;
            printf("\nBook Data Deleted!!\n");
            save_b();

        }
        else if(x=='2')
        {
            if(key_b<0)
            {
                printf("\nNo Student found\n");
                return;
            }
            printf("\nStudent ID:");
            scanf("%d",&a);fflush(stdin);
            for(i=0;i<key_s;i++)
            {
                if(data_s[i].student_id==a)
                {
                    fg=0;
                    break;
                }
            }
            if(fg)
            {
                printf("\nID Not Found\n");
                return;
            }
            for(a=i;a<key_s-1;a++)
            {
                for(b=1;b<=data_s[a].key;b++)
                    data_s[a].book[b]=data_s[a+1].book[b];
                data_s[a].student_id=data_s[a+1].student_id;
                strcpy(data_s[a].student_name,data_s[a+1].student_name);
                data_s[a].key=data_s[a+1].key;

            }
            key_s--;
            printf("\nStudebt Data Deleted!!\n");
            save_s();

        }
        else if(x=='3')
        {
            printf("\nlogIN ID:");
            gets(y);fflush(stdin);
            for(i=0;i<key_l;i++)
            {
                if(!strcmp(y,log_l[i]))
                {
                    fg=0;
                    break;
                }
            }
            if(fg)
            {
                printf("\nLogin ID not found!!\n");
                return;
            }
            for(a=i;a<key_l;a++)
                strcpy(log_l[a],log_l[a+1]);
            key_l--;
            printf("\nLog ID Deleted!!\n");
            save_l();
        }
        else if(x=='0')
            return;
        else
            printf("\n\nWrong Action!!\n");
        while(1)
        {
            char ask;
            fflush(stdin);
            printf("Do you want Delet more Deta?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }

    }
}

void search_b(void)
{
    char x,temp[50];
    int i,i_t,fg=1;
    load_b();
    fflush(stdin);
    while(1)
    {
        printf("\n1->Search Book by NAME\n2->Search Book by ID\n0->Back\naction:");
        x=getche();fflush(stdin);
        if(x=='1')
        {
            printf("\nName:");
            scanf("%s",temp);fflush(stdin);
            for(i=0;i<key_b;i++)
            {
                if(!strcmp(temp,data_b[i].book_name))
                {
                    display_b(i);
                    fg=0;
                    break;
                }
            }

        }
        else if(x=='2')
        {
            printf("\nID:");
            scanf("%d",&i_t);fflush(stdin);
            for(i=0;i<key_b;i++)
            {
                if(data_b[i].book_id==i_t)
                {
                    display_b(i);
                    fg=0;
                    break;
                }
            }

        }
        else if(x=='0')
            return;
        else
        {
            printf("WARING!!Wrong action!\n\a");
            continue;
        }
        if(fg)
            printf("Not Found\n");
        while(1)
        {
            char ask;
            fflush(stdin);
            printf("Do you want to search more?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }
    }
}

void search_s(void)
{
    load_s();
    int id,i,fg=1;
    while(1)
    {
        printf("\nStudent ID:");
        scanf("%d",&id);fflush(stdin);
        for(i=0;i<=key_b;i++)
        {
            if(data_s[i].student_id==id)
            {
                display_s(i);
                fg=0;
                break;
            }
        }
        if(fg)
            printf("Not Found\n");
        while(1)
        {
            char ask;
            fflush(stdin);
            printf("Do you want to search more?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }
    }
}

void issue(void)
{
    int id_s,id_b,i,j,fg=0;
    load_b();
    load_s();
    while(1)
    {
        printf("\nstudent ID:");
        scanf("%d",&id_s);fflush(stdin);
        for(i=0;i<key_s;i++)
        {
            if(id_s==data_s[i].student_id)
            {
                fg=1;
                break;
            }
        }
        if(!fg)
        {
            printf("\nStudent ID not found!!\n");
            return;
        }
        printf("\nBook ID:");
        scanf("%d",&id_b);fflush(stdin);
        for(j=0;j<key_b;j++)
        {
            if(id_b==data_b[j].book_id)
            {
                fg=0;
                break;
            }
        }
        if(fg)
        {
            printf("\nBook ID not found\n");
            return;
        }
        if(!data_b[j].quantity)
        {
            printf("\nBook  not in stock\n");
            return;
        }
        data_s[i].book[++data_s[i].key]=id_b;
        data_b[j].quantity--;
        save_b();
        save_s();
        while(1)
        {
            char ask;
            fflush(stdin);
            printf("Do you want to issue more?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }
    }
}

void returnbook(void)
{
    int id_s,id_b,i,j,k,fg=0;

    load_b();
    load_s();
    while(1)
    {
       printf("\nstudent ID:");
        scanf("%d",&id_s);fflush(stdin);
        for(i=0;i<=key_s;i++)
        {
            if(id_s==data_s[i].student_id)
            {
                fg=1;
                break;
            }
        }
        if(!fg)
        {
            printf("\nStudent ID not found!!\n");
            return;
        }
        printf("\nBook ID:");
        scanf("%d",&id_b);fflush(stdin);
        for(j=0;j<=key_b;j++)
        {
            if(id_b==data_b[j].book_id)
            {
                fg=0;
                break;
            }
        }
        if(fg)
        {
            printf("\nBook ID not found\n");
            return;
        }
        for(k=1;k<=data_s[i].key;k++)
        {
            if(data_s[i].book[k]==id_b)
            {
                fg=1;
                break;
            }
        }
        if(!fg)
        {
            printf("Book is not Issued!!");
            return;
        }
        data_b[j].quantity++;
        for(j=k;j<data_s[i].key;j++)
            data_s[i].book[j]=data_s[i].book[j+1];
        data_s[i].key--;
        printf("\nBook Returned\n");
        save_b();
        save_s();
                while(1)
        {
            char ask;
            fflush(stdin);
            printf("Do you want to return more Book?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }
    }
}

void search_issu(void)
{
    load_s;
    int id,i,j,fg=1;
    while(1)
    {
        printf("\nBook ID:");
        scanf("%d",&id);fflush(stdin);
        for(i=0;i<=key_s;i++)
        {
            for(j=1;j<=data_s[i].key;i++)
            {
                if(data_s[i].book[j]==id)
                {
                    printf("\n\n#_________________________\n# Student Name :%s\n",data_s[i].student_name);
                    printf("\n#_________________________\n# Student Id:%d\n#_________________________\n",data_s[i].student_id);
                    fg=0;
                    break;
                }
            }
        }
        if(fg)
            printf("\nbook is not issued!!\n");
        while(1)
        {
            char ask;
            fflush(stdin);
            printf("\nDo you want to search more issue?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }

    }
}

void add_log(void)
{
    load_l();
    char id[50];
    while(1)
    {
        printf("\nGive LogIN ID:");
        gets(id);
        strcpy(log_l[key_l++],id);
        save_l();
        while(1)
        {
            char ask;
            fflush(stdin);
            printf("Do you want to add more LogIN ID?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }
    }
}

void add_b(void)
{
    load_b();
    while(1)
    {
        printf("\n\n\nName  of  the   Book:");
        gets(data_b[key_b].book_name);
        printf("  \n\nName of  the  Authar:");
        gets(data_b[key_b].author);
        printf("  \n\nCategory of the Book:");
        gets(data_b[key_b].category);
        printf("  \n\nQuantity of the book:");
        scanf("%d",&data_b[key_b].quantity);
        printf("  \n\nRack   of   the Book:");
        scanf("%d",&data_b[key_b].rack);
        data_b[key_b].book_id=key_b;
        key_b++;
        save_b();
        while(1)
        {
            char ask;
            fflush(stdin);
            printf("Do you want to add more Books?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }
    }

}

void add_s(void)
{
    load_s();
    while(1)
    {
        printf("\nstudent Name:");
        gets(data_s[key_s].student_name);fflush(stdin);
        printf("Student  ID :");
        scanf("%d",&data_s[key_s].student_id);
        data_s[key_s].key=0;
        key_s++;
        save_s();
        while(1)
        {
            char ask;
            fflush(stdin);
            printf("Do you want to add more Student?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }

    }
}

void edit_b(void)
{
    int i,x,fg=1;
    char z;
    load_b();
    while(1)
    {
        printf("\nBook ID:");
        scanf("%d",&x);fflush(stdin);
        for(i=0;i<key_b;i++)
        {
            if(x==data_b[i].book_id)
            {
                fg=0;
                break;
            }

        }
        if(fg)
        {
            printf("ID not found!!\n\a");
            continue;
        }
        printf("1->Edit Name\n2->Edit Author\n3->Edit Category\n4->Edit Quantity\n5->Edit Rack\n0->Back\n");
        printf("action");
        z=getche();fflush(stdin);
        if(z=='1')
        {
            printf("\n\nName:");
            gets(data_b[x].book_name);fflush(stdin);
        }
        else if(z=='2')
        {
            printf("\n\nAuthor:");
            gets(data_b[x].author);fflush(stdin);
        }
        else if(z=='3')
        {
            printf("\n\nCategory:");
            gets(data_b[x].category);fflush(stdin);
        }
        else if(z=='4')
        {
            printf("\n\nQuantity:");
            scanf("%d",&data_b[x].quantity);fflush(stdin);
        }
        else if(z=='5')
        {
            printf("\n\nRack:");
            scanf("%d",&data_b[x].rack);fflush(stdin);
        }
        else if(z=='0')
            return;
        else
            printf("\nWrong Action!n");
        save_b();
        while(1)
        {
            char ask;
            fflush(stdin);
            printf("\nDo you want to Edit more Books?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }

    }
}

void edit_s(void)
{

    int x,i,fg=1;
    char k;
    load_s();
    while(1)
    {
        printf("\nStudent ID:");
        scanf("%d",&x);fflush(stdin);
        for(i=0;i<=key_s;i++)
        {
            if(data_s[i].student_id==x)
            {
                fg=0;
                break;
            }
        }
        if(fg)
        {
            printf("ID not found!!\n\a");
            continue;
        }
        printf("\n\n1->Edit Name\n2->Edit ID\n0->Books\n");
        printf("action:");
        k=getche();fflush(stdin);
        if(k=='1')
        {
            printf("\n\nName:");
            gets(data_s[i].student_name);
        }
        else if(k=='2')
        {
            printf("\n\nID:");
            scanf("%d",&data_s[i].student_id);
        }
        else if(k=='0')
            return;
        else
            printf("Wrong action!!");
        save_s();
        while(1)
        {
            char ask;
            fflush(stdin);
            printf("Do you want to Edit more Students?(y/n)");
            ask=getche();fflush(stdin);
            if(ask=='y')
                break;
            else if(ask=='n')
                return;
            else
                printf("\nWrong Action!!\n");
        }
    }

}

void viewall(void)
{
    char x;
    int i,j;
    load_b();
    load_s();
    while(1)
    {
        printf("\n1->View all Books\n2->View all Students\n3->View all issues\n0->Menu\n");
        printf("action:");
        x=getche();fflush(stdin);
        if(x=='1')
        {
            printf("\n\n\t     All Books\n____________________________________\n\n\n");
            for(i=0;i<key_b;i++)
            {
                printf("SL:%d",i);
                display_b(i);
                printf("\n\n");
            }
        }
        else if(x=='2')
        {
            printf("\n\n\t  All Students\n___________________________________\n\n\n");
            for(i=0;i<key_s;i++)
            {
                printf("SL:%d",i);
                display_s(i);
                printf("\n\n");
            }
        }
        else if(x=='3')
        {
            printf("\n\n\t    All Issues\n____________________________________\n\n\n");
            for(i=0;i<key_s;i++)
            {
                for(j=1;j<=data_s[i].key;j++)
                {
                    printf("\n\nSL:%d\n#___________________________________\n# Student Name :%s\n#",i,data_s[i].student_name);
                    printf("\n#___________________________________\n# Student Id:%d\n#___________________________________\n# Book:%d\n#___________________________________\n",data_s[i].student_id,data_s[i].book[j]);
                    printf("\n\n");

                }
            }
        }
        else if(x=='0')
            return;
        else
            printf("Wrong action!!\n");

    }
}

void re(void)
{
    load_b();
    load_s();
    load_l();
    printf("\nWARNING!!All Datas Will Be Lost!\a\a\n");
    while(1)
    {
        char ask;
        fflush(stdin);
        printf("\nSure You Want To Reset The Program?(y/n)");
        ask=getche();fflush(stdin);
        if(ask=='y')
            break;
        else if(ask=='n')
            return;
        else
            printf("\nWrong Action!!\n");
    }
    key_b=0;
    key_s=0;
    key_l=0;
    save_b();
    save_s();
    save_l();
    printf("\nProgram had been reseted!!\n");

}

void display_b(int x)
{
    printf("\n\n#  Book Name:%s",data_b[x].book_name);
    printf("\n#___________________________________\n#  Authar name:%s",data_b[x].author);
    printf("\n#___________________________________\n#  Book ID:%d",data_b[x].book_id);
    printf("\n#___________________________________\n#  Book Category:%s",data_b[x].category);
    printf("\n#___________________________________\n#  Book Quantity:%d",data_b[x].quantity);
    printf("\n#___________________________________\n#  Book in Rack:%d\n#___________________________________\n",data_b[x].rack);
}

void display_s(int x)
{
    int i;
    printf("\n\n#Student Name:%s",data_s[x].student_name);
    printf("\n#___________________________________\n#  Student ID:%d",data_s[x].student_id);
    printf("\n#___________________________________\n#  Books Issued by the Student:");
    for(i=1;i<=data_s[x].key;i++)
        printf("\n#\tBook ID:%d",data_s[x].book[i]);
    printf("\n#___________________________________\n");
}
