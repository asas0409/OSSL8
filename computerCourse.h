typedef struct //�İ���ȭ ����
{
    char name[100]; //�����̸�
    int credit; //����
    char designCourse; //������� ����(Y or N)
    char classification[100]; //�̼�����(�����ʼ�, ��������, ���������ʼ�)
}computerCourse;

int addCourse(computerCourse *c); //���� ��� �߰��ϱ�
void readCourse(computerCourse c); //���� ��� �б�
void updateCourse(computerCourse *c); //���� ��� ������Ʈ
/*
int deleteCourse(computerCourse *c); //���� ����

void savaData(computerCourse *c, int count); //���� ���� ���
int loadData(computerCourse *c); //���� �ҷ����� ���
void searchCourseByName(computerCourse *c,int count); //�����̸����� �˻��ϴ� ���
void searchCourseByCredit(computerCourse *c,int count); //�������� �˻��ϴ� ���
void addInCart(computerCourse *cart, computerCourse c); //������ ������ ��ٱ��Ͽ� ��� ���
void showchoose(computerCourse *cart, int count); //���� ���� ���� ��ȸ�� �� �ִ� ��� �߰�

*/
int selectDataNum(computerCourse *c, int count);
void listCourse(computerCourse *c, int count); //������� ��ü �б�
int selectMenu(); //ó�� �޴� ����




