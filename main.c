#include <stdio.h>
#include <stdlib.h>
#include "computerCourse.h"

int main(){
    int menu; //�޴� ����
    int index=0,count=0; 
    int cartIndex=0,cartCount=0;
    computerCourse c[100];
    computerCourse cart[20];

    //index = count = loadData(c);

    while(1){
        menu = selectMenu();
        if((menu==1||menu==3||menu==4)&&count==0) continue;

        if(menu==1){
            //���� ��ȸ
            if(count>0){ 
                //���� ���� �����ϰ� �ִ� �����Ͱ� �ִٸ�
                listCourse(c, index);
                //list�����ֱ�
            } else{
                //���� ���� �����ϰ� �ִ� �����Ͱ� �ϳ��� ���ٸ�?
                printf("�����Ͱ� �����ϴ�!\n");
            }
        }
        else if(menu==2){
              //���� �߰�
              count += addCourse(&c[index]);
              index++;
              }
        
        else if(menu==3){
            //���� ����
            int no = selectDataNum(c,index);
            if(no>0)
                updateCourse(&c[no-1]);
            else
                printf("=>��ҵǾ����ϴ�!\n");
        }
        else if(menu==4){
            //���� ����
            int delCourse = selectDataNum(c, index);
            int del = 0;
            if(delCourse>0){
                printf("������ �����Ͻðڽ��ϱ�?(����:1)");
                scanf("%d", &del);
                if(del == 1){
                    if(deleteCourse(&c[delCourse-1]) == 1){
                    printf("=>������!\n");
                    count --;
                    }
                }
            }else{
                printf("=>��ҵ�!\n");
            }
        }
        else if(menu==5){
            //���� ���Ͽ� ����
            saveCourse(c,index);
        }

        else if(menu==6){
            //���� �̸����� �˻�
            searchCourseByName(c,index);
        }
        
        else if(menu==7){
            //���� �������� �˻�
            searchCourseByCredit(c,index);
        }

        else if(menu==8){
            //��ٱ��Ͽ� ���� ���
            int no = selectDataNum(c,index);
            if(no>0){
                cartCount += addInCart(&cart[cartIndex++],c[no-1]);
            }else{
                printf("=>��ҵ�!\n");
            }
        }

        else if(menu==9){ 
            //��ٱ��Ͽ� ���� ���� �����ֱ�
            if(cartCount>0){ 
                //���� ���� ��ٱ��Ͽ� �ִ� �����Ͱ� �ִٸ�
                showchoose(cart, cartCount);
                //��ٱ��Ͽ� ���� ���� list�����ֱ�
            } else{
                //���� ���� ��ٱ��Ͽ� �ִ� �����Ͱ� �ϳ��� ���ٸ�?
                printf("=>��ٱ��Ͽ� ��� ������ �����ϴ�.\n");
            }
        
        }
        
        else if(menu==10){
            //���α׷� ����
            break;
        }
    }

    return 0;
}