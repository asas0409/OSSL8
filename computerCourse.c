#include <stdio.h>
#include "computerCourse.h"

int addCourse(computerCourse *c){
    int count = 0;
    printf("�����̸���?");
    scanf(" %[^\n]s", c->name);
    printf("�̼�������?(�����ʼ�, ��������, ���������ʼ�)");
    scanf(" %s", c->classification);
    printf("������?");
    scanf(" %d", &c->credit);
    printf("������� ���δ�?(Y or N)");
    scanf(" %c", &c->designCourse);
    count++;
    return count;
}

void readCourse(computerCourse c){
        printf(" %s  %d����   %c       %s\n", c.classification, c.credit, c.designCourse, c.name);
}

int selectDataNum(computerCourse *c,int count){
    int no;
    listCourse(c,count);
    printf("������ �޴��� ������ ������ ��ȣ��? (���  :0) " );
    scanf("%d",&no);
    getchar();
    return no;
}


void updateCourse(computerCourse *c){
    printf("�� �����̸���?");
    scanf(" %[^\n]s", c->name);
    printf("�� �̼�������?(�����ʼ�, ��������, ���������ʼ�)");
    scanf(" %s", c->classification);
    printf("�� ������?");
    scanf(" %d", &c->credit);
    printf("������� ���δ�?(Y or N)");
    scanf(" %c", &c->designCourse);
    printf("=>�����Ϸ�!\n");
}
/*
int deleteCourse(computerCourse *c){

}
void savaData(computerCourse *c, int count){

}
int loadData(computerCourse *c){

}
void searchCourseByName(computerCourse *c,int count){

}
void searchCourseByCredit(computerCourse *c,int count){

}
void addInCart(computerCourse *cart, computerCourse c){

}
void showchoose(computerCourse *cart, int count){

}
*/

void listCourse(computerCourse *c, int count){
    printf("  �̼�����  ����  ������񿩺�  �����̸�\n");
    printf("===============================\n");
    for(int i =0; i<count; i++){
        if(c[i].credit == -1) continue;
        //���������� �ؿ��� �������� ���� �����ض�.
        printf("%1d", i+1);
        //�������� ��ȣ�� ���� ������ֱ�
        readCourse(c[i]);
        //�� ���� ������ �б�
    }
}


int selectMenu(){

    int menu;
    printf("\n=========================\n");
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
