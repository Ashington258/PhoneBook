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
        printf("ͨѶ¼����\n");
        printf("1. �����ϵ��\n");
        printf("2. ��ʾ������ϵ��\n");
        printf("3. ɾ����ϵ��\n");
        printf("4. �޸���ϵ��\n");
        printf("5. �˳�\n");
        printf("��ѡ�������");
        scanf_s("%d", &choice);
        getchar();  // ��ȡ���з�,������������ɵ�Ӱ��

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
            printf("�������˳���\n");
            exit(0);
        default:
            printf("��Ч��ѡ�����������롣\n");
        }

        printf("\n");
    }

}

