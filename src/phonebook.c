#include<stdio.h>
#include "phonebook.h"

#define MAX_CONTACTS 100

/*定义量一个名为contact的结构体，用于存放通讯录*/
typedef struct {
    char name[50];
    char gender[20];
    char phone[20];
    char email[50];
} Contact;

/*Contact contacts[MAX_CONTACTS];
是一个定义了一个名为 contacts 的数组，
数组的元素类型是 Contact 结构体。
这行代码用于声明一个通讯录的数组。*/
Contact contacts[MAX_CONTACTS];
int numContacts = 0;


void addContact() {
    if (numContacts == MAX_CONTACTS) {
        printf("通讯录已满，无法添加更多联系人。\n");
        return;
    }
    /*char* fgets(char* str, int size, FILE* stream);
    */

    Contact newContact;
    printf("请输入联系人姓名：");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';  // 移除输入中的换行符

    printf("请输入性别：");
    fgets(newContact.gender, sizeof(newContact.gender), stdin);
    newContact.gender[strcspn(newContact.gender, "\n")] = '\0';


    printf("请输入联系人电话号码：");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("请输入联系人电子邮件：");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    contacts[numContacts++] = newContact;
    printf("联系人已添加到通讯录。\n");
}

void deleteContact() {
    if (numContacts == 0) {
        printf("通讯录为空。\n");
        return;
    }

    int index;
    printf("请输入要删除的联系人索引：");
    scanf_s("%d", &index);
    getchar();  // 读取换行符

    if (index < 1 || index > numContacts) {
        printf("无效的索引。\n");
        return;
    }

    // 将要删除的联系人后面的联系人向前移动
   /* for (int i = index - 1; i < numContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }*/

    numContacts--;
    printf("联系人已删除。\n");
}

void modifyContact() {
    if (numContacts == 0) {
        printf("通讯录为空。\n");
        return;
    }

    int index;
    printf("请输入要修改的联系人索引：");
    scanf_s("%d", &index);
    getchar();  // 读取换行符

    if (index < 1 || index > numContacts) {
        printf("无效的索引。\n");
        return;
    }

    Contact* contact = &contacts[index - 1];

    printf("请输入新的联系人姓名：");
    fgets(contact->name, sizeof(contact->name), stdin);
    contact->name[strcspn(contact->name, "\n")] = '\0';  // 移除输入中的换行符

    printf("请输入新的联系人性别: ");
    fgets(contact->gender, sizeof(contact->gender), stdin);
    contact->gender[strcspn(contact->gender, "\n")] = '\0';

    printf("请输入新的联系人电话号码：");
    fgets(contact->phone, sizeof(contact->phone), stdin);
    contact->phone[strcspn(contact->phone, "\n")] = '\0';

    printf("请输入新的联系人电子邮件：");
    fgets(contact->email, sizeof(contact->email), stdin);
    contact->email[strcspn(contact->email, "\n")] = '\0';

    printf("联系人信息已修改。\n");
}

void displayContacts() {
    if (numContacts == 0) {
        printf("通讯录为空。\n");
        return;
    }

    printf("通讯录中的联系人：\n");
    for (int i = 0; i < numContacts; i++) {
        printf("联系人 #%d\n", i + 1);
        printf("姓名: %s\n", contacts[i].name);
        printf("性别：%s\n", contacts[i].gender);
        printf("电话: %s\n", contacts[i].phone);
        printf("邮箱: %s\n", contacts[i].email);
        printf("\n");
    }
}


/*
* `Contact newContact;` 这行代码声明了一个名为 `newContact` 的变量，其类型为 `Contact` 结构体。这个变量用于存储新添加联系人的信息。

`printf("请输入联系人姓名：");` 是用来向用户显示一条消息，提示用户输入联系人的姓名。

`fgets(newContact.name, sizeof(newContact.name), stdin);` 这行代码使用 `fgets` 函数从标准输入（键盘）读取用户输入的联系人姓名，并将其存储在 `newContact.name` 字符数组中。

`sizeof(newContact.name)` 是用于获取 `newContact.name` 数组的大小，以确保 `fgets` 函数不会超出数组的边界。

`stdin` 是一个指向标准输入流的指针，它告诉 `fgets` 函数从标准输入读取用户的输入。

`newContact.name[strcspn(newContact.name, "\n")] = '\0';` 这行代码用于移除用户输入的姓名中可能包含的换行符（`\n`）。`strcspn` 函数用于找到字符串中第一个匹配指定字符集的字符的位置，这里用于找到换行符的位置。通过将换行符替换为字符串结束符 `'\0'`，确保存储的联系人姓名不包含换行符，以便后续的处理和显示。

总之，这段代码的目的是接收用户输入的联系人姓名，并将其存储在 `newContact.name` 字符数组中，同时移除输入中的换行符，以便保持数据的正确性和一致性。
*/