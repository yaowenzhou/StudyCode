/*
 * @Author       : yaowenzhou
 * @Date         : 2021-03-30 20:09:54
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-03-30 20:47:07
 * @version      :
 * @Description  :
 */
#include <Windows.h>

#include <cstdio>

int main() {
  char readBuf[128];
  char a;
  for (int i = 0; i < 5; i++) {
    memset(readBuf, 0, 128);
    printf("Please enter a string:\n");
    // 方法1
    // scanf_s("%[^\n]%*c", readBuf, 127);
    // 方法2
    // scanf_s("%[^\n]", readBuf, 127);
    // scanf_s("%c", &a, 1);
    // 方法3
    scanf_s("%[^\n]", readBuf, 127);
    getchar();
    printf("String is: %s\n", readBuf);
  }
  return 0;
}