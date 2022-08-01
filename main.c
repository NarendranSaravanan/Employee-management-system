#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void employeedetails(char a[],int b,char c[],int d,long int e,char f[]);
void employeesalary(int a,int b, int c,int d);
void employeeattandance(int y,int a[],int b[15][15],char c[15][15],int d[15][15],float e[15][15],int f[],int g[15][15], char h[15][15], int i[15][15], float j[15][15]);
void employeeleave(int a, int b, char c, int d, char e,int f, int g);
int main()
{
    int choose,dw,dw1,user,n,a,b,e,x,y,i,event=0,entry=0,exit=0,password1,password2,infocheck[15]={0},check1[15],check2[15],admin,g,h,serialcheck;
    int eventdate[15],eventyear[15],entryyear[15][15],exitdate[15][15], exityear[15][15],leavedate[15],leaveyear[15],entrydate[15][15],usernamecheck;
    int leavecheck[15],leavedays[15],leaveapproval[15],experience[15],performance[15],trainingcheck[15], performancecheck[15];
    int financecheck[15];
    double entrytime[15][15],exittime[15][15],eventtime[15];
    char eventmonth[15][15],eventname[15][15],leavereason[15][15],leavemonth[15][15], exitmonth[15][15],entrymonth[15][15],username1[30];
    FILE *f1;
    struct employee{
    char username[30],birthmonth[15],gmail[30];
    int password,date,year,duedate,salary,allowance,loan;
    long int phonenumber;
    }employee[15];
    do{
    printf("Press 1 for user panel\nPress 2 for administration panel\n");
    scanf("%d", &choose);
    if(choose==1){
       do{
        printf("USER PANEL\n");
        printf("\n\n");
        printf(" LOGIN \n");
        printf("enter the serial number\n");
        scanf("%d", &b);
        printf("enter the username\n");
        scanf("%s", username1);
        printf("enter the password\n");
        scanf("%d", &password1 );
        if(employee[b].password==password1){
            printf("entered username and password is correct\n");
            printf("USER PANNEL");
            printf("\n\n");
            do{
            printf(" press 1 to update password\n press 2 to manage personal information\n press 3 to view salary\n press 4 to view attendance\n");
            printf(" press 5 to view events\n press 6 to manage leave\n press 7 to know your performance\n press 8 to logout\n");
            scanf("%d", &user);
            if(user==1){
                printf("UPDATE PASSWORD");
                printf("enter the newpassword\n");
                scanf("%d", &employee[b].password);
                printf("your password has been updated\n");
            }else if(user==2){
                do{
                printf("MANAGE PERSONAL INFORMATION\n");
                printf(" press 1 to edit info\n press 2 to view info\n");
                scanf("%d", &g);
                if(g==1){
                    if(infocheck[b]==1){
                        printf("enter the correct date of birth of the user\n");
                        scanf("%d %s %d", &employee[b].date,employee[b].birthmonth, &employee[b].year);
                        printf("enter the correct phone number of the user\n");
                        scanf("ld", &employee[b].phonenumber);
                        printf("enter the correct email id\n");
                        scanf("%s", employee[b].gmail);
                    }else printf("information is not yet uploaded by the admin\n");
                }else if(g==2){
                    if(infocheck[b]==1){
                    employeedetails(employee[b].username,employee[b].date,employee[b].birthmonth,employee[b].year,employee[b].phonenumber, employee[b].gmail);
                    }else printf("no info is updated\n");
                }
                printf("press 1 to return to manage personal info menu or anyother key to exit\n");
                scanf("%d", &dw1);
                }while(dw1==1);
            }else if(user==3){
                do{
                printf("SALARY\n");
                if(financecheck[b]==1){
                        employeesalary(employee[b].salary,employee[b].allowance,employee[b].loan,employee[b].duedate);
                }else printf("employee finance has not been uploaded by the admin\n");
                printf("press 1 to return to salary menu or anyother number to exit\n");
                scanf("%d", &dw1);
                }while(dw1==1);

            }else if(user==4){
               printf("ATTANDANCE\n");
               employeeattandance(b,check1,entrydate,entrymonth,entryyear,entrytime,check2,exitdate,exitmonth,exityear,exittime);
            }else if(user==5){
               printf("EVENTS\n");
               if(event>0){
               for(x=0;x<event;x++){
                printf("event name : %s\n", eventname[x]);
                printf("event time is %lf on %d,%s,%d\n ", eventtime[x], eventdate[x], eventmonth[x], eventyear[x]);
               }
               }else printf("there are no current event in calender\n");
            }else if(user==6){
                do{
            printf("MANAGE LEAVE\n");
            printf(" press 1 to apply for a leave\n press 2 to view approval of leave\n");
            scanf("%d", &g);
            if(g==1){
            printf("enter the reason for leave\n");
            scanf("%s", leavereason[b]);
            printf("enter the date,month,year from which you wish to take\n");
            scanf("%d %s %d",&leavedate[b],leavemonth[b],&leaveyear[b]);
            printf("enter the number of days the leave to be applied\n");
            scanf("%d", &leavedays[b]);
            leavecheck[b]=1;
            }else if(g==2){
                employeeleave(leavecheck[b],leaveapproval[b], leavereason[b], leavedate[b],leavemonth[b],leaveyear[b],leavedays[b]);
            }
            printf("press  1 to return to manage leave menu or any other key to exit\n");
            scanf("%d", &dw1);
            }while(dw1==1);
            }
            printf("press 1 to return to userpannel menu or anyother to exit\n");
            scanf("%d", &dw1);
            }while(dw1==1);
        }else{ printf("entered username or password is incorrect\n");}
              printf("press 1 to return to userpannel login or anyother to exit\n");
              scanf("%d", &dw1);
       }while(dw1==1);
    }else if(choose ==2){
        do{
        printf("ADMINSTRATION PANEL\n");
        printf("\n\n");
        printf("enter the password for the admin\n");
        scanf("%d", &password2);
        if(password2==11){
            printf("entered password is correct\n");
        do{
        printf(" press 1 to add new user\n press 2 to manage employee personal information\n press 3 to manage employee finance\n press 4 to manage employee attandance\n");
        printf(" press 5 to manage employee events\n press 6 to manage employee leave\n press 7 to manage employee training record\n press 8 to manage employee performance\n");
        printf(" press 9 to view list of employees\n");
        scanf("%d", &admin);
        if(admin==1){
                f1=fopen("username.txt","a+");
            printf("enter the number of user to be added\n");
            scanf("%d", &n);
            for(a=serialcheck;a<serialcheck+n;a++){
                printf("enter the username of the user %d\n", a+1);
                scanf("%s", employee[a].username);
                printf("enter the password for user %d\n", a+1 );
                scanf("%d", &employee[a].password);
                printf("serial number for the user %d is %d\n", a+1, a );
            }
             serialcheck=serialcheck+n;
        }else if(admin==2){
            do{
              printf("EMPLOYEE PERSONAL INFORMATION\n");
              printf(" press 1 to add new information\n press 2 to update information\n");
              scanf("%d",&h);
              if(h==1){
                  printf("enter the serial number of the user\n");
                  scanf("%d", &a);
                  if(a<serialcheck && a>=0){
                  printf("enter the date of birth of the user\n");
                  scanf("%d %s %d", &employee[a].date, employee[a].birthmonth, &employee[a].year);
                  printf("enter the phone number of the user\n");
                  scanf("%ld", &employee[a].phonenumber);
                  printf("enter the email id\n");
                  scanf("%s", employee[a].gmail);
                  infocheck[a]=1;
                  }else printf("no such user exist\n");
              }else if(h==2){
                  printf("enter the serial number of the user\n");
                  scanf("%d", &a);
                  if(a<=serialcheck && a>=0){
                  if(infocheck[a]==1){
                  printf("enter the correct date of birth of the user\n");
                  scanf("%d %s %d", &employee[a].date, employee[a].birthmonth, &employee[a].year);
                  printf("enter the correct phone number of the user\n");
                  scanf("%ld", &employee[a].phonenumber);
                  printf("enter the correct email id\n");
                  scanf("%s", employee[a].gmail);
                  }else printf("please add information of the user\n");
                  }else printf("no such user exist\n");
              }
              printf("press 1 to return to EMPLOYEE PERSONAL INFORMATION or any other key to exit\n");
              scanf("%d", &dw);
            }while(dw==1);
        }else if(admin==3){
            do{
            printf("EMPLOYEE FINANCE\n");
             printf("enter the serial number of the user\n");
            scanf("%d", &a);
            if(a>=0 && a<=serialcheck){
                printf("SALARY\n");
                scanf("%d", &employee[a].salary);
                printf("MANAGE ALLOWANCE\n");
                scanf("%d", &employee[a].allowance);
                printf("MANAGE LOAN\n");
                scanf("%d", &employee[a].loan);
                printf("MANAGE DUE DATE\n");
                scanf("%d", &employee[a].duedate);
            financecheck[a]=1;
            }else printf("no such user exist\n");
            printf("press 1 to return to EMPLOYEE FINANCE or anyother number to exit\n");
            scanf("%d", &dw);
            }while(dw==1);
        }else if(admin==4){
            do{
            printf("EMPLOYEE ATTENDANCE\n");
            printf(" press 1 to enter the entry time of the user\n press 2 to enter the exit time of the user\n");
            scanf("%d", &h);
            printf("enter the serial number of the user\n");
            scanf("%d", &a);
            if(a>=0 && a<=serialcheck){
            if(h==1){
                    if(check1[a]==0){
                        entry=0;
                    }
                    do{
                printf("enter the employee entry time\n");
                scanf("%lf", &entrytime[a][entry]);
                printf("enter the date,month,year\n");
                scanf("%d %s %d", &entrydate[a][entry],& entrymonth[a][entry], &entryyear[a][entry]);
                check1[a]++;
                entry++;
                 printf("press 1 to enter another entry detail or anyother number to exit\n ");
                scanf("%d", &dw);
                    }while(dw==1);
            }else if(h==2){
                do{
                if(check2[a]==0){
                    exit=0;
                }
                printf("enter the employee exit time\n");
                scanf("%lf", &exittime[a][exit]);
                printf("enter the date,month,year\n");
                scanf("%d %s %d", &exitdate[a][exit], &exitmonth[a][exit], &exityear[a][exit]);
                check2[a]++;
                exit++;
                printf("press 1 to enter another exit details or anyother number to exit\n");
                scanf("%d", &dw);
            }while(dw==1);
            }
            }else printf("no such user exist\n");
            printf("press 1 to return to EMPLOYEE ATTENDANCE or anyother number to exit\n");
            scanf("%d", &dw);
            }while(dw==1);
        }else if(admin==5){
            do{
            printf("EMPLOYEE EVENTS\n");
            printf("enter the number of events to be added\n");
            scanf("%d", &e);
            for(a=event;a<event+e;a++){
            printf("enter the event name\n");
            scanf("%s", eventname[a]);
            printf("enter the time in 24hrs formate\n");
            scanf("%lf", &eventtime[a]);
            printf("enter the date,month,year\n");
            scanf("%d %s %d", &eventdate[a], eventmonth[a], &eventyear[a]);
            }
            event=event+e;
            printf("press 1 to return to EMPLOYEE EVENTS or anyother number to exit\n");
            scanf("%d", &dw);

            }while(dw==1);
        }else if(admin==6){
            do{
            printf("MANAGE EMPLOYEE LEAVE\n");
            printf("enter the serial number of the employee\n");
            scanf("%d", &a);
            if(a>=0 && a<=serialcheck){
            if(leavecheck[a]==1){
                printf("reason for the leave is %s\n",leavereason[a] );
                printf("leave asked is from %d,%s,%d for %d days", leavedate[a], leavemonth[a], leaveyear[a], leavedays[a]);
                printf("if leave is approved press 1 and if denied press 2\n");
                scanf("%d", &leaveapproval[a]);
            }else printf("the employee has not applied for leave\n");
            }else printf("no such user exist\n");
            printf("press 1 to return to manage employee leave menu or any other key to exit\n");
            scanf("%d", &dw);
            }while(dw==1);
        }else if(admin==7){
            printf("MANAGE EMPLOYEE TRAINING RECORDS\n");
            printf("enter the serial number of the user\n");
            scanf("%d", &a);
            if(a>=0 && a<=serialcheck){
            printf("enter the number of year of experience of the user\n");
            scanf("%d", &experience[a]);
            printf("press 1 if the employee has done certificate courses or any other number to exit\n");
            scanf("%d", &h);
            if(h==1){
                printf("enter the name of the course that the employee has done\n");
            }
            trainingcheck[a]=1;
            }else printf("no such user exist\n");
        }else if(admin==8){
            printf("EMPLOYEE PREFORMANCE\n");
            printf("enter the serial number of the user\n");
            scanf("%d", &a);
            if(a>=0 && a<=serialcheck){
            printf("rate the work performance of the employee form 1 to 5\n");
            scanf("%d", &performance[a]);
            performancecheck[a]=1;
            }else printf("no such user exist\n");
        }else if(admin==9){
            for(a=0;a<serialcheck;a++){
                printf("%s\t", employee[a].username);
                printf("%d\t", employee[a].password);
                printf("%d,%s,%d\t", employee[a].date,employee[a].birthmonth,employee[a].year);
                printf("\n");
            }
        }

        printf("press 1 to return to admin menu and anyother number to exit\n");
        scanf("%d", &dw);
        }while(dw==1);
     }else{printf("incorrect password\n");}
     printf("press 1 to return to admin menu and anyother number to exit\n");
     scanf("%d", &dw);
   }while(dw==1);
    }
   printf("press 1 to return to main menu and anyother number to exit\n");
   scanf("%d", &dw);
    }while(dw==1);
    fprintf(f1,"  username\tpassword\tdob\tphonenumber\tgmail\n" );
        for(a=0;a<serialcheck;a++){
            fprintf(f1,"%d  %s", a+1,employee[a].username);
            fprintf(f1,"\t");
            fprintf(f1,"%d", employee[a].password);
            fprintf(f1,"\t");
            if(infocheck[a]==1){
            fprintf(f1,"  %d,%s,%d",employee[a].date, employee[a].birthmonth, employee[a].year);
            fprintf(f1,"\t");
            fprintf(f1,"%ld", employee[a].phonenumber);
            fprintf(f1,"\t");
            fprintf(f1,"%s",employee[a].gmail);
            }
            fprintf(f1,"\n");
        }
        fclose(f1);
return 0;
}
void employeedetails(char a[],int b,char c[],int d,long int e,char f[]){
 printf("username : %s\n", a );
 printf("DOB : %d,%s,%d\n",b , c, d);
 printf("phone number: %ld\n", e);
 printf("email id : %s\n",f);
}
void employeesalary(int a,int b, int c,int d){
int g;
printf(" press 1 to view payments and deduction\n press 2 to view net salary\n press 3 view duration\n");
scanf("%d", &g);
if(g==1){
printf(" fixed salary : %d\n", a);
printf(" allowance amount : %d\n", b);
}else if(g==2){
printf("net salary : %d\n", a+b-c);
}else if(g==3){
printf("duration : %d\n", d);
}
}
void employeeattandance(int y,int a[],int b[15][15],char c[15][15],int d[15][15],float e[15][15],int f[],int g[15][15], char h[15][15], int i[15][15], float j[15][15])
{
    int x;
     if(a[y]!=0){
                    for(x=0;x<a[y];x++){
               printf(" entry time on %d.%d.%d is %f\n", b[y][x],c[y][x],d[y][x],e[y][x]);
               }
               }else printf("no entry time is updated\n");
               if(f[y]!=0){
                    for(x=0;x<f[y];x++){
               printf(" exit time on %d.%d.%d is %f\n", g[y][x], h[y][x], i[y][x], j[y][x]);
               }
               }else printf("no exit time is updated\n");
}
void employeeleave(int a, int b, char c, int d, char e,int f, int g){
if(a==1 && b==1){
                printf("reason for the leave is %s\n",c );
                printf("leave asked is from %d,%s,%d for %d days", d, e, f, g);
                printf("the leave is approved by the admin\n");
            }else if(a==1 && b==2){
                 printf("reason for the leave is %s\n",c );
                printf("leave asked is from %d,%s,%d for %d days", d, e, f, g);
                printf("the leave is not approved by the admin due to specific reason\n");
            }else if(a==1 && b==0){
                printf("your request is not yet viewed by the admin please wait\n");
            }else if(a==0){
                 printf("you have not applied for a leave\n");
            }
}
