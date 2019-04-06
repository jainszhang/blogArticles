常用方法：
1.原地反转，使用三个指针
2.快慢指针寻找是否存在环
3.删除时考虑值的覆盖，或者考虑节点的指向


链表结构体
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x=0) :val(x), next(nullptr) {}
};

1.逆序构建单链表：输入数据：1 2 3 4 5 6，构造单链表：6->5->4->3->2->1。
    void  desc_construct(ListNode * &head)//传入头节点的引用
    {
        //头插法创建链表
        ListNode *pre = nullptr;
        int x = 0;
        while (cin>>x && x!=-1)
        {
            ListNode *cur = new ListNode;
            cur->val = x;
            cur->next = pre;
            pre = cur;
        }
        head = pre;//头节点指向第一个节点
    }
    调用处：
    ListNode *h=nullptr;
    name_list::desc_construct(h);

2.创建和打印链表
    //创建带头节点的链表
    void createHeadList(ListNode *phead,int &n)
    {
        ListNode *p=phead;
        for (int i = 0; i < n; ++i) {
            ListNode * pnewNode = (ListNode*)malloc(sizeof(ListNode));
            pnewNode->val = i;
            pnewNode->next = nullptr;
            p->next = pnewNode;
            p = pnewNode;
        }
    }
    //创建不带头节点的链表
    ListNode* createNoHeadList()
    {
        ListNode * head=nullptr,*cur=nullptr;

        int v=0;
        while (1)
        {
            cin>>v;
            if (1000==v)
                break;
            ListNode * tmp = (ListNode*)malloc(sizeof(ListNode));

            tmp->val = v;
            tmp->next = nullptr;
            if(nullptr == head)//头节点为空，第一次分配
            {
                head = tmp;
                cur = head;
            }
            else//头节点不同，在cur后面接节点即可
            {
                cur->next = tmp;
                cur = tmp;
            }

        }
        cur->next = nullptr;

        return head;
    }
    //打印不带头节点的链表
    void printNoHeadList(ListNode* head)
    {
        ListNode * cur = head;
        if (!cur)
            return;
        while (cur)
        {
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
    //打印带头节点的链表
    void printHeadList(ListNode* head)
    {
        ListNode * cur = head->next;
        if (!cur)
            return;
        while (cur)
        {
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }

3.链表的反转
//例如：假设现有链表：6->5->4->3->2->1，进行反转操作后，链表变成：1->2->3->4->5->6。
方法1:利用栈的特性反转链表
    ListNode* ReverseList(ListNode* pHead) {
        if(!pHead)
            return nullptr;
        ListNode * p = pHead;
        ListNode * h = nullptr,*q= nullptr;
        stack<ListNode*> vs;
        while (p)
        {
            vs.push(p);
            p=p->next;
        }
        p = q = h = vs.top();
        vs.pop();
        while (!vs.empty())
        {
            p = vs.top();
            q->next = p;
            q = p;
            vs.pop();
        }
        q->next = nullptr;
        return h;
    }
方法2:原地反转，使用3个指针
    ListNode* ReverseList2(ListNode* pHead) {
        if(pHead==nullptr || !pHead->next->next)//链表为空或只有一个节点
            return nullptr;
        //原地反转  1,2,3,4...
        ListNode * pre=nullptr,*cur=pHead,*t= nullptr;
        while (cur)
        {
            t = cur->next;//最后t值会变为null
            cur->next = pre;
            pre = cur;//cur最后一个节点时赋值给了pre
            cur = t;//null赋值给了cur

        }
        return pre;
    }

4.返回链表倒数第k个节点
方法1:遍历访问链表，加入到数组中，直接访问索引节点
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        vector<ListNode*> vnode;
        if (!pListHead)
            return nullptr;
        ListNode *p=pListHead;
        while(p)
        {
            vnode.push_back(p);
            p=p->next;
        }
        return vnode[vnode.size() - k];
    }
方法2:利用两个指针距离为k。假设 k 是小于等于链表长度，那么我们可以设置两个指针 p 和 q，这两个指针在链表里的距离就是 k，那么后面那个指针走到链表末尾的 nullptr 时，另一个指针肯定指向链表倒数第 k 个值。
ListNode* FindKthToTail2(ListNode* pListHead, unsigned int k)
    {
        if(!pListHead)
            return nullptr;
        ListNode * pre=pListHead,*last = pListHead;
        for (int i = 0; i < k; ++i) {//后指针走了k次
            last = last->next;
        }
        //前后指针同时走，一直到后指针指向nullptr
        while (last)
        {
            last = last->next;
            pre = pre->next;
        }
        return pre;
    }


5.合并两个有序链表
 //合并两个顺序链表
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
//        ListNode * ph1=pHead1,*ph2=pHead2,*tmp= nullptr,*ph = nullptr;
        //两个任意一个为空返回另一ge
        if(pHead1== nullptr)
            return pHead2;
        else if(pHead2 == nullptr)
            return pHead1;
        //两者都不空，比较两个大小,申请两个指针，一个头指针，一个当前指针
        ListNode * head= nullptr,*cur = nullptr;
        //遍历两个链表，同时不空时方可比较
        while (pHead1 && pHead2)
        {
            if (pHead1->val < pHead2->val)
            {
                if(head==nullptr)
                {
                    head = pHead1;
                    cur = pHead1;
                } else
                {
                    cur ->next = pHead1;//连接合并的节点
                    cur = cur->next;//维护合并的节点
                }
                pHead1=pHead1->next;//ph1向后移动

            }
            else
            {
                if(head==nullptr)
                {
                    head = pHead2;
                    cur = pHead2;
                } else
                {
                    cur ->next = pHead2;
                    cur = cur->next;

                }
                pHead2=pHead2->next;
//                cur = cur->next;
            }

        }
        //追加余下链表值
        if(pHead1)
            cur->next = pHead1;
        if(pHead2)
            cur->next = pHead2;
        return head;
    }

6. 判断链表是否有环
    bool is_Loop(ListNode * head)
    {
        //设置两个指针，一个pre，一个last，pre一次走1步，last一次走2步，如果两者某一时刻相等，那么就存在环。
        // 这是因为pre一次走一步，last一次走2步，若有环，必然会相遇。如果无环，last会走到nullptr
        if(!head)
            return false;
        ListNode *pre=head,*last=head;
        while (nullptr!=last && nullptr!=pre)
        {
            pre = pre->next;
            last = last->next->next;
            if(long(pre) == long(last))
            {

                return true;
            }
        }
        return false;
    }

7.删除链表中的当前节点
//删除链表当前节点，要求时间O（1）。
//思路：1->2->3->4->5->6，如果我们要删除 4，可以把 4 和 5 的数据交换下，然后删除 5，再把 4 和 6 连接起来，如此其时间复杂度为 。
    void del(ListNode *head,ListNode * position)
    {
        if(position->next)//不是最后一个节点
        {
            position->val = position->next->val;
            position->next = position->next->next;
        } else if(!position->next)//最后一个节点
        {
            //需要遍历到最后一个节点的前一个节点
            ListNode *pre = head;
            while (pre->next != position)
                pre = pre->next;
            pre->next=nullptr;
            delete position;
        }
    }

8.找出单链表中间节点
//找出单链表的中间节点。慢指针走的长度等于快慢指针相距的程度。所以利用这个性质，当快指针走到链表尾时，慢指针正好在中间结点。
    ListNode *find_middle(ListNode* head)
    {
        ListNode * slow = head;
        ListNode *fast = head;
        while (fast->next && slow->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;

    }

9.链表升序排序


10.判断链表是否有环？返回相遇环的节点，并且找到环的入口
//若存在环且找到了相遇点 C，此时令一个指针 start_node 从链表第一个结点处开始往后遍历，再令另一个指针 meet_node 从 C 处往后遍历，它们的相遇结点就是环的入口点。
ListNode * is_loop(ListNode * header)
{
    if (!header->next)  // 空链表
        return nullptr;
  
    ListNode * slow_pointer = header;
    ListNode * fast_pointer = header;
  
    while (fast_pointer->next && fast_pointer->next->next && slow_pointer != fast_pointer)
    {
        slow_pointer = slow_pointer->next;        // 慢指针走一步
        fast_pointer = fast_pointer->next->next;  // 快指针走两步
    }

    if (slow_pointer == fast_pointer)
        return slow_pointer;

    return nullptr;
}

ListNode * find_meet_node(ListNode * header)
{
    ListNode * meet_node = is_loop(header);
  
    if (meet_node == nullptr)  // 不存在环
        return nullptr;
  
    ListNode * start_node = header->next;
    while (start_node != meet_node)
    {
        start_node = start_node->next;
        meet_node = meet_node->next;
    }
  
    return start_node;
}


11.判断两个链表是否相交？或者是求两个链表的交点这样的问题，万变不离其宗。只需要把链表尾接到其中一个链表头就转换为9/10的问题了（有环无环）


