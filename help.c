#include<stdio.h>

int checkMonth(int m){
    if(m >= 1 && m <= 12){
        return m;
    }else{
        return -1;
    }
}

int main(){

    int m=0, month=0;

    printf("������ �Է��Ͻÿ�: ");
    scanf("%d", &m);

    month = checkMonth(m);
    switch (month)
    {
    case 1:
        printf("January\n");
        break;
    case 2:
        printf("February\n");
        break;
    case 3:
        printf("March\n");
        break;
    case 4:
        printf("April\n");
        break;
    case 5:
        printf("May\n");
        break;
    case 6:
        printf("June\n");
        break;
    case 7:
        printf("July\n");
        break;
    case 8:
        printf("August\n");
        break;
    case 9:
        printf("September\n");
        break;
    case 10:
        printf("October\n");
        break;
    case 11:
        printf("November\n");
        break;
    case 12:
        printf("December\n");
        break;    
    default:
        printf("�������� ���� ���Դϴ�.\n");
        break;
    }
   
    return 0;
}