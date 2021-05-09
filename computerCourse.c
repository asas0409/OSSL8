#include <stdio.h>
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
    printf(" %-12s  %d����   %9c   %s\n", c.classification, c.credit, c.designCourse, c.name);
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
    printf("�����Ͻ� ������ ��ٱ��Ͽ� �߰��Ǿ����ϴ�!\n");
    return 1;
}

void showchoose(computerCourse *cart, int count){ //��ٱ��Ͽ� ���� ����
    printf("==> ��ٱ��Ͽ� ���� �����Դϴ�.\n");
    printf("  �̼�����  ����  ������񿩺�  �����̸�\n");
    printf("=====================================\n");
    for(int i =0; i<count; i++){
        if(cart[i].credit == -1) continue;
        //���������� �Ʒ��� statement�� �������� ���� i��° loop ������
        printf("%1d", i+1);
        //�������� ��ȣ�� ���� ���
        readCourse(cart[i]);
        //i��° ������ �б�
    }
}

/*
void savaData(computerCourse *c, int count){
}
int loadData(computerCourse *c){
}
void searchCourseByName(computerCourse *c,int count){
}
void searchCourseByCredit(computerCourse *c,int count){
}

*/

void listCourse(computerCourse *c, int count){
    printf("\n  �̼�����      ����  ������񿩺�  �����̸�\n");
    printf("============================================\n");
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