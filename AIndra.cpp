
struct Node
{
    int data;
    Node *next;
};

class linked_list
{
private:
    Node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void insert(int n)
    {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    
    void makecycle(Node* x,int n)//x is the address of start of cycle and n is value of new node
    {
        Node *tmp = new Node;
        tmp->data = n;
        tmp->next = x;
        tail->next=tmp;
        tail=NULL;  
    }

    void remove( Node * node )
    {
    Node * temp = node->next;
    node->data = node->next->data;
    node->next = temp->next;
    delete(temp);
    }

   Node* next(Node * temp)
   {
    return temp->next;
   }
    

int countNodes( Node *n)// this function used for finding length of cycle
{
   int res = 1;
   struct Node *temp = n;
   while (temp->next != n)
   {
      res++;
      temp = temp->next;
   }
   return res;
}
 
bool checkloop( Node *list)
{
     Node  *slow_p = list, *fast_p = list;
  
    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
           return true;
        }
    }
    return false;
}

int lengthofcycle( Node *list)
{
    struct Node  *slow_p = list, *fast_p = list;
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
            return countNodes(slow_p);
    }
    return 0;
} 

Node* startofcycle(Node* list)//return address of the start node of loop
{
    struct Node  *slow_p = list, *fast_p = list;
    while (slow_p && fast_p && fast_p->next)
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
            break;
        }
    }
    fast_p=list;
    while(fast_p!=slow_p)
    {
        fast_p=fast_p->next;
        slow_p=slow_p->next;
    }
    return slow_p;
}
int lengthoflinkedlist(Node* head)
{
     if(!checkloop(head))//if it doesnot contains cycle
     {
        Node* temp=head;
        int x=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            x++;
        }
        return x;
     }
    Node* temp=startofcycle(head);
    int x=lengthofcycle(head);
    Node* temp2=head;
    while(temp2!=temp)
    {
        temp2=temp2->next;
        x++;
    }
    return x;
}
};
