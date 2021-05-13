#include <stdio.h>
#include <string.h>
#include "computerCourse.h"

int addCourse(computerCourse *c){
    int count = 0;
    printf("\n�����̸���? ");
    scanf(" %[^\n]s", c->name); //���Ⱑ ���Ե� �����̸��� �ֱ� ������ %[^\n]s��� (����Ű �� ��� ���� �Է� �޴´�)
    printf("�̼�������?(�����ʼ�, ��������, ���������ʼ�) ");
    scanf(" %s", c->classification);
    printf("������? ");
    scanf(" %d", &c->credit);
    printf("������� ���δ�?(Y or N) ");
    scanf(" %c", &c->designCourse);
    printf("=>�����߰��Ϸ�!\n");
    count++; //���� �ϳ� �߰�
    return count; 
}

void readCourse(computerCourse c){
    //�ٸ� �Լ������� ���� �бⰡ ����ϰ� ������ ������ readCourse �Լ� �߰�
    printf(" %-12s  %d����   %7c       %12s\n", c.classification, c.credit, c.designCourse, c.name);
}

int selectDataNum(computerCourse *c,int count){
    //������ ���� �Լ��� ������ ��, Ư�� �Լ��� �����ؾ� �ϱ� ������ selectDataNum �Լ� ����
    int no;
    listCourse(c,count);
    printf("������ �޴��� ������ ������ ��ȣ��? (���  :0) " );
    scanf("%d",&no);
    getchar();
    return no;
}


void updateCourse(computerCourse *c){
    printf("\n�� �����̸���? ");
    scanf(" %[^\n]s", c->name); //���Ⱑ ���Ե� �����̸��� �ֱ� ������ %[^\n]s��� (����Ű �� ��� ���� �Է� �޴´�)
    printf("�� �̼�������?(�����ʼ�, ��������, ���������ʼ�) ");
    scanf(" %s", c->classification);
    printf("�� ������? ");
    scanf(" %d", &c->credit);
    printf("������� ���δ�?(Y or N) ");
    scanf(" %c", &c->designCourse);
    printf("=>�����Ϸ�!\n");
}

int deleteCourse(computerCourse *c){
    //������ ���� �ϸ� ������ -1�� ����� �ش�.
    c->credit = -1;
    return 1;
}

int addInCart(computerCourse *cart, computerCourse c){
    *cart = c;
    printf("=>�����Ͻ� ������ ��ٱ��Ͽ� �߰��Ǿ����ϴ�!\n");
    return 1;
}

void showchoose(computerCourse *cart, int count){ //��ٱ��Ͽ� ���� ����
    int sum=0;
    printf("\n==> ��ٱ��Ͽ� ���� �����Դϴ�.\n");
    printf("  �̼�����   ����     ������񿩺�   �����̸�\n");
    printf("==================================================\n");
    for(int i =0; i<count; i++){
        if(cart[i].credit == -1) continue;
        //���������� �Ʒ��� statement�� �������� ���� i��° loop ������
        printf("%1d", i+1);
        //�������� ��ȣ�� ���� ���
        readCourse(cart[i]);
        //i��° ������ �б�
        sum+=cart[i].credit;
    }
    printf("                                  �� ���� : %2d����\n",sum);
}

void saveCourse(computerCourse *c, int count){
    FILE *fp;
    fp = fopen("test.txt","wt");
    for(int i=0;i<count;i++){
        if(c[i].credit==-1) continue;
        fprintf(fp,"%s %d %c %s\n",c[i].classification,c[i].credit,c[i].designCourse,c[i].name);
    }
    fclose(fp);
    printf("=>�����!\n");
}


int loadData(computerCourse *c){
    int count = 0;
    FILE *fp;
    fp = fopen("test.txt", "rt");
    if(fp == NULL){
        printf("=> ���� ����\n");
        return 0;
    }
    else{
        for(int i  = 0; i<100; i++){
            fscanf(fp, "%s", c[i].classification);
            if(feof(fp)) break;
            fscanf(fp, "%d", &c[i].credit);
            fscanf(fp, "%c", &c[i].designCourse);
            fscanf(fp, "%s", c[i].name);
            count++;
        }
        fclose(fp);
        printf("=> ���� �ε� ����!\n");
        return count;
    }

}

void searchCourseByCredit(computerCourse *c,int count){
    int searchresult = 0; //�˻��� ����� ����
    int search = 0; //�˻��� ����

    printf("�˻��� ������? ");
    scanf("%d", &search); //�˻��� ������ �Է� �޾� search�� �����Ѵ�.
    printf("  �̼�����   ����     ������񿩺�   �����̸�\n");
    printf("==================================================\n");
    for(int i =0; i<count; i++){
        if(c[i].credit == -1) continue; //������ �Լ���� �̹� loop�� ������. �ٸ� i��°�� �Ѿ
        if(c[i].credit == search){ //�˻��� ������ ���� ������ �˻��Ǹ� 
            printf("%2d", i+1); 
            readCourse(c[i]); //�� ������ ������ش�
            searchresult++; //ã������ +1
        }
    }
    if(searchresult == 0) printf("=> �˻��� ���� ����!"); //���࿡ �˻��� ����� ���ٸ�, ������ ���ٰ� ���
    printf("\n");

}


void searchCourseByName(computerCourse *c,int count){
    char sn[20];
    int comp=0;
    printf("�˻��� �������? ");
    scanf("%s",sn);
    printf("  �̼�����   ����     ������񿩺�   �����̸�\n");
    printf("==================================================\n");
    for(int i=0;i<count;i++){
        if(c[i].credit==-1) continue;
        if(strstr(c[i].name,sn)){
            printf("%2d", i+1);
            readCourse(c[i]);
            comp++;
        }
    }
    if(comp==0){
        printf("=> ���� �����Դϴ�.\n");
    }
}



void listCourse(computerCourse *c, int count){
    printf("  �̼�����   ����     ������񿩺�   �����̸�\n");
    printf("==================================================\n");
    for(int i =0; i<count; i++){
        if(c[i].credit == -1) continue;
        //���������� �Ʒ��� statement�� �������� ���� i��° loop ������
        printf("%1d", i+1);
        //�������� ��ȣ�� ���� ���
        readCourse(c[i]);
        //i��° ������ �б�
    }
}


int selectMenu(){
    //main�Լ��� ����ǰ� ����Ǳ� ������ �޴��� �����ִ� �Լ�
    int menu;
    printf("\n**��ǻ�Ͱ��н�ȭ ���� ��ȸ ���α׷�**\n");
    printf("================================\n");
    printf("1. �������� ��ȸ\n");
    printf("2. �������� �߰�\n");
    printf("3. �������� ���� ����\n");
    printf("4. �������� ����\n");
    printf("5. ����\n");
    printf("6. ���� �̸����� �˻�\n");
    printf("7. �������� �˻�\n");
    printf("8. ��ٱ��Ͽ� ���\n");
    printf("9. ��ٱ��� ����\n");
    printf("10. ����\n");
    printf("���ϴ� �޴� ��ȣ�� �Է��ϼ��� : ");
    scanf("%d",&menu);
    
    return menu;
}