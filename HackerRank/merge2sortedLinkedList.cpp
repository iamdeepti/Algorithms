#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data ;
    Node * next;
};
void print(Node * tp)
{

    while(tp!=NULL)
    {
        cout<<tp->data<<"->";
        tp=tp->next;
    }
    cout<<"NULL";
}
void insert(Node ** head, int x)
{

    Node * np = new Node;
    np->data = x;
    np->next = NULL;

    if(*head==NULL)
    {
        *head = np;
    }
    else{
    Node * tmp = *head;
        while(tmp->next !=NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = np;
    }
}
Node * Merge(Node * head1,Node * head2)
{
    Node * head = new Node;
    head = NULL;
    if(head1==NULL)
    {
        head = head2;
        return head;
    }
    if(head2==NULL)
    {
        head = head1;
        return head;
    }
    if(head1->data < head2->data)
    {
        head->data = head1->data;
        head->next = Merge(head1->next,head2);
        return head;
    }
    else
    {
        head->data = head2->data;
        head->next = Merge(head1,head2->next);
        return head;
    }
}
void mergeList(Node ** head, Node * head1, Node * head2)
{
    if(head1==NULL)
	{
		*head = head2;
 	}
	if(head2==NULL)
	{
		*head = head1;
 	}
    while(head1!=NULL || head2!=NULL)
    {
	if(head1->data < head2->data)
        {
		insert(head,head1->data);
		head1=head1->next;
         }
	else
        {
		insert(head,head2->data);
		head2=head2->next;
         }
     }
	while(head1!=NULL)
	{
        insert(head,head1->data);
        head1=head1->next;
	}
    while(head2!=NULL)
	{
        insert(head,head2->data);
        head2=head2->next;
	}

}
int main()
{
    int t;
    cin>>t;
    int n,m;
    while(t)
    {

        cin>>n;
        Node * head1 = new Node;
        head1 = NULL;
        int x;
        for(int i=0;i<n;i++)
        {

                cin>>x;
                insert(&head1,x);
        }
        cin>>m;
        Node * head2 = new Node;
        head2 = NULL;
        for(int i=0;i<m;i++)
        {

                cin>>x;
                insert(&head2,x);
        }
    print(head1);
    cout<<endl;
    print(head2);
    cout<<endl;
    Node * head3 = new Node;
    //head3=NULL;
    head3=Merge(head1,head2);
    print(head3);
    Node * head = new Node;
    head = NULL;
    //head->next=NULL;
    mergeList(&head,head1,head2);
    print(head);

        t--;
    }
    return 0;

}
