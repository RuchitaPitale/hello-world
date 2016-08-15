#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*temp;
void display(struct node *n)
{	
	if(n==NULL)
	{
		printf("List empty\n");
		return;
	}
	printf("Data is \n");
	//	n=head;
			do
			{				
			printf("%d",(n->data));
			n=(n->next);
			getch();
			}while((n!=NULL));
}
void deleteList(struct node **head)
{
	struct node *auxNode,*iterator=*head;
	while(iterator)
	{
		auxNode=iterator->next;
		printf("Deleting node ");
		
		free(auxNode);
		iterator=auxNode;
	}
	*head=NULL;
}
void insert(struct node **head,int d,int pos)
{
	int k=1;temp=*head;struct node *p=*head;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	if(!newnode)
	 printf("Error occured\n");
	else
	{
		newnode->data=d;
		if(pos==1)
		{
			printf("Insert at start\n");	
			newnode->next=p;
			*head=newnode;
			return;
		}
		else
		{
			while((k<pos-1)&&(temp!=NULL))
			{
			printf("k= %d\tpos= %d",k,pos);
			temp=temp->next;
			k++;
			}
			if(temp==NULL)
				{
					printf("Insert at end\n");
					temp->next=newnode;
					newnode->next=NULL;
							
				}
			else
			{
				printf("Insert at middle\n");
				newnode->next=temp->next;
				temp->next=newnode;
			}
			return;
		}
	}
}
void delete(struct node **head,int pos)
{
	int k=1;temp=*head;struct node *p=*head;struct node *q;
	if(pos==1)
	{
		printf("Delete from start \n");
		temp=*head;
		*head=(*head)->next;
		free(temp);
		printf("Node deleted\n");
		return;
	}
	else
	{
	 while((k<pos)&&(temp->next!=NULL))
			{
			printf("k= %d\tpos= %d",k,pos);
			p=temp;
			temp=temp->next;
			k++;
			printf("\nTEMP IS %u",temp);
			}	
			printf("TEMP->next %u",temp->next);
			if(temp->next==NULL)
				{
					printf("Delete at end\n");
					p->next=temp->next;
					free(temp);
				}
			else
			{
				printf("Delete at middle\n");
				p->next=temp->next;
				free(temp);
			}
			return;
	}
}
int main()
{
	int d,pos,i;int flag=1,ch,count=0;
	struct node *head=NULL;
	struct node *n=head;
	printf("****Linked List****\n");
label:	while(flag)
	{
	printf("1.Insert at start \n2.Insert at middle\n3.Insert at end\n");
	printf("4.Delete at start \n5.Delete at middle\n6.Delete at end\n7.Exit\n");
	printf("Enter choice \n");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
		case 4:
		{	pos=1;
			break;
		}
		case 2:
		case 5:
		{	
			printf("Enter position\n");
			scanf("%d",&pos);
			break;
		}
		case 3:
		case 6:
		{
			pos=++count;
			break;
		}
		case 7:
			{
				flag=0;
				goto label;
				break;
			}
	}

	printf("POSITION : %d\n",pos);
	if(ch==1||ch==2||ch==3)
	{
	printf("Enter data \n");
	scanf("%d",&d);
	insert(&head,d,pos);
	printf("COUNT IS %d",count);
	count++;
	}
/*	else {
		deleteList(&head);
	}*/
	else{
	delete(&head,pos);
	count--;
	}
	display(head);
	

//	display(head);
}
	return 0;
}
