struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* node1=l1;
    struct ListNode* node2=l2;
    int mark=0;int i=0;
    struct ListNode* node4=NULL;
    struct ListNode* p=NULL;
    while( (node1 != NULL) && (node2 != NULL) ){
        struct ListNode* node3=(struct ListNode* )malloc(sizeof(struct ListNode));
        if(i == 0) {
            node4=node3;
            p=node3;
            i++;
        }
        else node4->next=node3;
        node4=node3;
        if(mark == 0) node3->val = node1->val + node2->val;
        else node3->val = node1->val + node2->val + 1;
        mark = 0;
        if(node3->val >= 10) mark = 1;
        node3->val = node3->val % 10;
        node1=node1->next;
        node2=node2->next;
    }
    while( (node1 != NULL) && (node2 == NULL) ){
        struct ListNode* node3=(struct ListNode* )malloc(sizeof(struct ListNode));
        node4->next=node3;
        node4=node3;
        if(mark == 0) node3->val = node1->val;
        else node3->val = node1->val + 1;
        mark = 0;
        if(node3->val >= 10) mark = 1;
        node3->val = node3->val % 10;
        node1=node1->next;
    }
    while( (node1 == NULL) && (node2 != NULL) ){
        struct ListNode* node3=(struct ListNode* )malloc(sizeof(struct ListNode));
        node4->next=node3;
        node4=node3;
        if(mark == 0) node3->val = node2->val;
        else node3->val = node2->val + 1;
        mark = 0;
        if(node3->val >= 10) mark = 1;
        node3->val = node3->val % 10;
        node2=node2->next;
    }
    if(mark == 0) node4->next=NULL;
    else {
        struct ListNode* newnode=(struct ListNode* )malloc(sizeof(struct ListNode));
        newnode->val =1;
        newnode->next = NULL;
        node4->next=newnode;
    }
    return p;
}