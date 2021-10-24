struct pointer{
    int left,right;
    pointer(){}
    pointer(int left,int right):left(left),right(right){}
    void set(int left,int right){
        this->left=left;
        this->right=right;
    }
};

struct my_list{
    vector<pointer> p;
    int front,end;
    my_list(){
        front=-1;
        end=-1;
    }
    my_list(int n):p(n){
        front=-1;
        end=-1;
    }

    void set(int i,int left,int right){
        p[i].set(left,right);
        if(p[i].left==-1)front=i;
        if(p[i].right==-1)end=i;
    }

    void insert_front(int x1,int x2){
        int c=p[x1].left;
        set(x2,c,x1);
        p[x1].left=x2;
        if(c!=-1)p[c].right=x2;
        if(p[x2].left==-1)front=x2;
        if(p[x2].right==-1)end=x2;
    }

    void insert_back(int x1,int x2){
        int c=p[x1].right;
        set(x2,x1,c);
        p[x1].right=x2;
        if(c!=-1)p[c].left=x2;
        if(p[x2].left==-1)front=x2;
        if(p[x2].right==-1)end=x2;
    }

    vector<int> get_list(){
        vector<int> li;
        int i=front;
        while(i!=-1){
            li.push_back(i);
            i=p[i].right;
        }
        return li;
    }
};