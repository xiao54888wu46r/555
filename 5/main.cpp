#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct xsxx             //ѧ����Ϣ�ṹ��
{
	char name[100];		//����
	int xh;				//ѧ��
	int age;	  		//����
	float cj;			//�ɼ�
	float tz;			//����
	float sg;			//���
	struct xsxx* next;	//������ָ��
};

void chao_zhuo()
{
	printf("�������Ĳ���\n����ѧ����		��1\n");
	printf("ɾ��ѧ����		��2\n");
	printf("��ѯѧ����		��3\n");
	printf("��ӡ����ѧ����		��4\n");
	printf("�˳�����		��5\n");
}

int main()
{
	struct xsxx s[100];

	int a = 0, b = 0, c, d, e = 0, f = 0, g = 0;  //e:��ѧ���� d:������ c:�����ѧ��

	printf("��ӭʹ�ü���ѧ������ϵͳ��������н������Ĳ�����\n");
	while (1)
	{
		chao_zhuo();
		scanf("%d", &d);
		struct xsxx* curNode = &s[0];
		if (d == 1)
		{
			printf("������ѧ����\n");
			scanf("%d", &a);
			if (a <= 0)
			{
				printf("����ѧ��������ȷ\n");
				continue;
			}
			f = f + a;
			for (a = 0; e < f; e++, a++)
			{
				printf("�������%d��ѧ������Ϣ(���� ѧ�� ���� �ɼ� ����(kg) ���(m))\n", a + 1);
				scanf("%s %d %d %f %f %f", &s[e].name, &s[e].xh, &s[e].age, &s[e].cj, &s[e].tz, &s[e].sg);

				if (e >= 1)
				{
					for (int h = 0; h < e; h++)
					{
						if (s[h].xh == s[e].xh)
						{
							printf("����ѧ�ų����ظ���\n");
							break;
						}
						if (e + 1 == f)
						{
							s[e].next = NULL;
							printf("\n������ϣ�\n\n");
							break;
						}
						else
						{
							s[e].next = &s[e + 1];
						}
					}
					continue;
				}
				else
				{
					s[e].next = &s[e + 1];
				}
			}
		}
		else if (d == 2)
		{
			printf("����Ҫɾ��ѧ��ѧ�ţ�\n");
			scanf("%d", &c);
			if (f == 0)
			{
				printf("��ǰû��ѧ��\n\n");
				continue;
			}
			for (b = 0; b < f; b++)
			{
				if (c == curNode->xh)
				{
					if (b >= 1)
					{
						s[b - 1].next = &s[b+1];
					}
					else
					{
						curNode = &s[b+1];
						g++;
					}
					s[b].next = NULL;
					printf("ɾ���ɹ���\n\n");
					break;
				}
				else if (curNode->next == NULL)
				{
					printf("û�и�ѧ��!\n\n");
				}
				curNode = curNode->next;
			}
			continue;
		}
		else if (d == 3)
		{
			if (g == 0)
			{
				struct xsxx* curNode = &s[0];
			}
			printf("�����ѯѧ��ѧ�ţ�\n");
			scanf("%d", &c);
			struct xsxx* curNode = &s[0];
			if (f == 0)
			{
				printf("��ǰû��ѧ��!\n\n");
				continue;
			}
			for (b = 0; b < f; b++)
			{
				if (c == curNode->xh)
				{
					printf("\n����:%s\nѧ��:%d\n ����:%d\n �ɼ�:%f\n ����(kg):%f\n ���(m):%f\n\n", s[b].name, s[b].xh, s[b].age, s[b].cj, s[b].tz, s[b].sg);
					break;
				}
				else if (f == b + 1)
				{
					printf("û�в�ѯ��������\n\n");
				}
				curNode = curNode->next;
			}
			continue;
		}

		else if (d == 4)
		{
			if (f == 0)
			{
				printf("��ǰû��ѧ��\n\n");
				continue;
			}
			printf("\n��ǰ����ѧ����Ϣ��\n");
			while (1)
			{
				printf("\n����:%s\nѧ��:%d\n ����:%d\n �ɼ�:%f\n ����(kg):%f\n ���(m):%f\n\n", curNode->name, curNode->xh, curNode->age, curNode->cj, curNode->tz, curNode->sg);
				if ((curNode->next) == NULL)
				{
					break;
				}
				curNode = curNode->next;
			}
			printf("�������\n\n");
		}
		else if (d == 5)
			break;
	}
	return 0;
}
