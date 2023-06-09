#include<stdio.h>
#include "phonebook.h"

#define MAX_CONTACTS 100

/*������һ����Ϊcontact�Ľṹ�壬���ڴ��ͨѶ¼*/
typedef struct {
    char name[50];
    char gender[20];
    char phone[20];
    char email[50];
} Contact;

/*Contact contacts[MAX_CONTACTS];
��һ��������һ����Ϊ contacts �����飬
�����Ԫ�������� Contact �ṹ�塣
���д�����������һ��ͨѶ¼�����顣*/
Contact contacts[MAX_CONTACTS];
int numContacts = 0;


void addContact() {
    if (numContacts == MAX_CONTACTS) {
        printf("ͨѶ¼�������޷���Ӹ�����ϵ�ˡ�\n");
        return;
    }
    /*char* fgets(char* str, int size, FILE* stream);
    */

    Contact newContact;
    printf("��������ϵ��������");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0';  // �Ƴ������еĻ��з�

    printf("�������Ա�");
    fgets(newContact.gender, sizeof(newContact.gender), stdin);
    newContact.gender[strcspn(newContact.gender, "\n")] = '\0';


    printf("��������ϵ�˵绰���룺");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0';

    printf("��������ϵ�˵����ʼ���");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0';

    contacts[numContacts++] = newContact;
    printf("��ϵ������ӵ�ͨѶ¼��\n");
}

void deleteContact() {
    if (numContacts == 0) {
        printf("ͨѶ¼Ϊ�ա�\n");
        return;
    }

    int index;
    printf("������Ҫɾ������ϵ��������");
    scanf_s("%d", &index);
    getchar();  // ��ȡ���з�

    if (index < 1 || index > numContacts) {
        printf("��Ч��������\n");
        return;
    }

    // ��Ҫɾ������ϵ�˺������ϵ����ǰ�ƶ�
   /* for (int i = index - 1; i < numContacts - 1; i++) {
        contacts[i] = contacts[i + 1];
    }*/

    numContacts--;
    printf("��ϵ����ɾ����\n");
}

void modifyContact() {
    if (numContacts == 0) {
        printf("ͨѶ¼Ϊ�ա�\n");
        return;
    }

    int index;
    printf("������Ҫ�޸ĵ���ϵ��������");
    scanf_s("%d", &index);
    getchar();  // ��ȡ���з�

    if (index < 1 || index > numContacts) {
        printf("��Ч��������\n");
        return;
    }

    Contact* contact = &contacts[index - 1];

    printf("�������µ���ϵ��������");
    fgets(contact->name, sizeof(contact->name), stdin);
    contact->name[strcspn(contact->name, "\n")] = '\0';  // �Ƴ������еĻ��з�

    printf("�������µ���ϵ���Ա�: ");
    fgets(contact->gender, sizeof(contact->gender), stdin);
    contact->gender[strcspn(contact->gender, "\n")] = '\0';

    printf("�������µ���ϵ�˵绰���룺");
    fgets(contact->phone, sizeof(contact->phone), stdin);
    contact->phone[strcspn(contact->phone, "\n")] = '\0';

    printf("�������µ���ϵ�˵����ʼ���");
    fgets(contact->email, sizeof(contact->email), stdin);
    contact->email[strcspn(contact->email, "\n")] = '\0';

    printf("��ϵ����Ϣ���޸ġ�\n");
}

void displayContacts() {
    if (numContacts == 0) {
        printf("ͨѶ¼Ϊ�ա�\n");
        return;
    }

    printf("ͨѶ¼�е���ϵ�ˣ�\n");
    for (int i = 0; i < numContacts; i++) {
        printf("��ϵ�� #%d\n", i + 1);
        printf("����: %s\n", contacts[i].name);
        printf("�Ա�%s\n", contacts[i].gender);
        printf("�绰: %s\n", contacts[i].phone);
        printf("����: %s\n", contacts[i].email);
        printf("\n");
    }
}


/*
* `Contact newContact;` ���д���������һ����Ϊ `newContact` �ı�����������Ϊ `Contact` �ṹ�塣����������ڴ洢�������ϵ�˵���Ϣ��

`printf("��������ϵ��������");` ���������û���ʾһ����Ϣ����ʾ�û�������ϵ�˵�������

`fgets(newContact.name, sizeof(newContact.name), stdin);` ���д���ʹ�� `fgets` �����ӱ�׼���루���̣���ȡ�û��������ϵ��������������洢�� `newContact.name` �ַ������С�

`sizeof(newContact.name)` �����ڻ�ȡ `newContact.name` ����Ĵ�С����ȷ�� `fgets` �������ᳬ������ı߽硣

`stdin` ��һ��ָ���׼��������ָ�룬������ `fgets` �����ӱ�׼�����ȡ�û������롣

`newContact.name[strcspn(newContact.name, "\n")] = '\0';` ���д��������Ƴ��û�����������п��ܰ����Ļ��з���`\n`����`strcspn` ���������ҵ��ַ����е�һ��ƥ��ָ���ַ������ַ���λ�ã����������ҵ����з���λ�á�ͨ�������з��滻Ϊ�ַ��������� `'\0'`��ȷ���洢����ϵ���������������з����Ա�����Ĵ������ʾ��

��֮����δ����Ŀ���ǽ����û��������ϵ��������������洢�� `newContact.name` �ַ������У�ͬʱ�Ƴ������еĻ��з����Ա㱣�����ݵ���ȷ�Ժ�һ���ԡ�
*/