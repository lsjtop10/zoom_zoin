#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

void Test()
{
    Save_Setting(1, 2);
    char Data = Load_Setting();

}
void Save_Setting(int usedProgram, int waiting_min)
{

    FILE* fp = fopen("setting.txt", "w"); //�б���

    if (usedProgram == 0)
        fputs("Edge\n", fp); //���ڿ� �Է�
    else if (usedProgram == 1)
        fputs("Chrome\n", fp); //���ڿ� �Է�

    fputs(waiting_min + "\n", fp); //���ڿ� �Է�
    fclose(fp); //���� ������ �ݱ�
}

char Load_Setting()
{
    FILE* fp = fopen("setting.txt", "r");  //test������ r(�б�) ���� ����
    char buffer[1000] = { 0, };

    fread(buffer, 1, 1000, fp); //��ü �б�
    printf("%s", buffer);

    fclose(fp); //���� ������ �ݱ�

    return "123";
}

int main()
{
    Test()
        return 0;
}