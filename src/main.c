#include<stdio.h>

#include"phonebook.h"
#include"menu.h"


int main()
{
    menu();
    return 0;
   
}

//云端：未收到修改信息，尝试于本地核对
//本地：收到核对信息尝试再次于云端建立联系
//云端：收到本地的信息，开始进入通讯测试
//
//云端：未收到本地消息，返回核对
//本地：开始第一次测试
//本地：测试失败，云端未接受修改
//云端：（点击全部提交后，并同步以后才收到修改）
//本地：点击同步以后即可收到修改
//云端：（点击推送后收到修改）

//现在存在的问题时本地发送到云端存在问题
//本地：开始测试