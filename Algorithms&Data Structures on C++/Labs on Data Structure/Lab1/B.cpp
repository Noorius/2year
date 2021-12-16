#include <iostream>

using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

struct st{
    private:
        node * head;
        node * tail;
        node * cnt = new node(0);

    public:
    st(){
        head = NULL;
        tail = head;
    }

    int size(){
        return cnt->val;
    }

    void front(){
        if(head != NULL){
            cout<< head->val;
        }else cout<<"error";
    }

    void push(int x){
       node * item = new node(x);
       if(head != NULL){
            tail->prev = item;
            item->next = tail;
       }
       else{
           tail = item;
           head = tail;
       }  
       tail = item;
       cnt->val++;
    }

    void pop(){
        if(head != NULL){
            cout<<head->val;
            head = head->prev;
            if(head != NULL){
                head->next = NULL; 
            }
            cnt->val--;
        }
        else{
            cout<<"error";
        }
    }

    void clear(){
        cout<<"ok";
        head = NULL;
        tail = NULL;
        cnt->val = 0;
    }

};


void command(string n, bool &on, st &s){
    if(n=="size")
        cout<<s.size();

    else if(n=="push"){
        int k;
        cin>>k;
        s.push(k);
        cout<<"ok";
    }
    else if(n=="pop"){
        s.pop();
    }

    else if(n=="front")
        s.front();

    else if(n=="clear"){
        s.clear();
    }
    else if(n=="exit"){
        cout<<"bye";
        on = false;
    }
}

int main(){
    st s;
    string n;
    bool on = true;
    while(on){
        cin>>n;
        command(n,on,s);
        cout<<"\n";
    }
}