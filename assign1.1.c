#include<stdio.h>

struct date {
    int day;
    int month;
    int year;
};
void initdate(struct date*ptrDate){
    ptrDate->day=27;
    ptrDate->month=8;
    ptrDate->year=2024;
    printf("%d-%d-%d\n",ptrDate->day,ptrDate->month,ptrDate->year);
}
void acceptdate(struct date*ptrDate){
    printf("Enter date : ");
    scanf("%d%d%d",&ptrDate->day,&ptrDate->month,&ptrDate->year);
}
void printdate(struct date*ptrDate){
    printf("%d-%d-%d\n",ptrDate->day,ptrDate->month,ptrDate->year);
}
int menu(){
    int choice;
    printf("0. exit\n");
    printf("1. accept date\n");
    printf("2. print date\n");
    printf("3.default date\n");
    printf("enter your choice\n");
   scanf("%d",&choice);
    return choice;
}
int main(){
    int choice;
    struct date d1;
    while((choice=menu())!=0){
         switch (choice)
    {
    case 1:
        acceptdate(&d1);
        break;

    case 2:
        printdate(&d1);
        break;

    
    case 3:
        initdate(&d1);
        break;
    
    default:
       printf("wrong choice\n");
        break;
    }

    }
        return 0;
    }


