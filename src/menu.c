#include<stdio.h>


enum
{
    ADD = 1,
    DISPALY = 2,
    DELETE = 3,
    MODIFY = 4

};

void menu()
{
    int choice;
    while (1)
    {
        printf("通讯录程序\n");
        printf("1. 添加联系人\n");
        printf("2. 显示所有联系人\n");
        printf("3. 删除联系人\n");
        printf("4. 修改联系人\n");
        printf("5. 退出\n");
        printf("请选择操作：");
        scanf_s("%d", &choice);
        getchar();  // 读取换行符,消除缓冲区造成的影响

        switch (choice) {
        case ADD:
            addContact();
            break;
        case DISPALY:
            displayContacts();
            break;
        case DELETE:
            deleteContact();
            break;
        case MODIFY:
            modifyContact();
            break;
        case 5:
            printf("程序已退出。\n");
            exit(0);
        default:
            printf("无效的选择，请重新输入。\n");
        }

        printf("\n");
    }

}

