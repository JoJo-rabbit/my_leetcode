
  struct ListNode {
      int val;
      struct ListNode *next;
 };
/*     还就那个数据过大导致直接溢出
*/

long long chang_node_to_num(struct ListNode* my_node)
{
    struct ListNode* p=my_node;
    long long num=p->val;
    long long change=10;
    if(num == 0) return 0;
    while(p->next != NULL){
        p =p->next;
        num=num+p->val*change;
        change=change*10;
    }
    return num;
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    long long num_sum=chang_node_to_num(l1)+chang_node_to_num(l2);
    struct ListNode* node2=NULL;
    struct ListNode* p=NULL;
    int aa=num_sum%10;
    struct ListNode* node1=(struct ListNode* )malloc(sizeof(struct ListNode));
    node1->val=aa;
    node1->next=NULL;
    node2=node1;
    p=node1;
    num_sum=num_sum/10;
    while(num_sum != 0){
        int aa=num_sum%10;
        struct ListNode* node1=(struct ListNode* )malloc(sizeof(struct ListNode));
        node1->val=aa;
        node1->next=NULL;
        node2->next=node1;
        node2=node1;
        num_sum=num_sum/10;
    }
    return p;
}

