struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* node1=l1;
    struct ListNode* node2=l2;
    int mark=0;
    struct ListNode* node4=NULL;
    while( (node1 != NULL) && (node2 != NULL) ){
        node4=node2;
        if(mark == 0) node2->val = node1->val + node2->val;
        else node2->val = node1->val + node2->val + 1;
        if(node2->val / 10) mark = 1;
        else mark = 0;
        node2->val = node2->val % 10;
        node1=node1->next;
        node2=node2->next;
    }
    while( (node1 != NULL) && (node2 == NULL) ){
        node4->next = node1;
        node4=node4->next;
        if(mark == 1) node1->val = node1->val + 1;
        if(node1->val >= 10) mark = 1;
        else mark = 0;
        node1->val = node1->val % 10;
        node1=node1->next;
    }
    while( (node1 == NULL) && (node2 != NULL) ){
        node4=node2;
        if(mark == 1) node2->val = node2->val + 1;
        if(node2->val >= 10) mark = 1;
        else mark = 0;
        node2->val = node2->val % 10;
        node2=node2->next;
    }
    if(mark == 1) {
        struct ListNode* newnode=(struct ListNode* )malloc(sizeof(struct ListNode));
        newnode->val =1;
        newnode->next = NULL;
        node4->next=newnode;
    }
    return l2;
}