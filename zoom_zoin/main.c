#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 

void Test()
{
    Save_Setting(1, 2);
    char Data = Load_Setting();

}
void Save_Setting(int usedProgram, int waiting_min)
{

    FILE* fp = fopen("setting.txt", "w"); //읽기모드

    if (usedProgram == 0)
        fputs("Edge\n", fp); //문자열 입력
    else if (usedProgram == 1)
        fputs("Chrome\n", fp); //문자열 입력

    fputs(waiting_min + "\n", fp); //문자열 입력
    fclose(fp); //파일 포인터 닫기
}

char Load_Setting()
{
    FILE* fp = fopen("setting.txt", "r");  //test파일을 r(읽기) 모드로 열기
    char buffer[1000] = { 0, };

    fread(buffer, 1, 1000, fp); //전체 읽기
    printf("%s", buffer);

    fclose(fp); //파일 포인터 닫기

    return "123";
}

int main()
{
    Test()
        return 0;
}