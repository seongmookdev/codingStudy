//url: https://huiyu.tistory.com/entry/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-%EC%B2%B4%EC%9D%B4%EB%8B%9D-%ED%95%B4%EC%8B%9C-%ED%85%8C%EC%9D%B4%EB%B8%94Chaining-Hash-Table

#include <iostream>
#define MAX_HASH 10
#define HASH_KEY(key) key%MAX_HASH
using namespace std;

typedef struct Node{
    int id;
    Node* hashNext;
}Node;

Node* hashTable[MAX_HASH];

void AddHashData(int key, Node* node){
    int hash_key = HASH_KEY(key);
    if(hashTable[hash_key] == NULL){
        hashTable[hash_key] = node;
    }
    else{
        node->hashNext = hashTable[hash_key];
        hashTable[hash_key] = node;
    }
}

void DelHashData(int id){
    int hash_key = HASH_KEY(id);
    if(hashTable[hash_key]==NULL) return;

    Node* delNode = NULL;
    if(hashTable[hash_key]->id == id){
        delNode = hashTable[hash_key];
        hashTable[hash_key] = hashTable[hash_key]->hashNext;
    }
    else{
        Node* node = hashTable[hash_key];
        Node* next = node->hashNext;
        while(next){
            if(next->id == id){
                node->hashNext = next->hashNext;
                delNode = next;
                break;
            }
            node = next;
            next = node->hashNext;
        }
    }
    free(delNode);
}

Node* FindHashData(int id){
    int hash_key = HASH_KEY(id);
    if(hashTable[hash_key] == NULL) return NULL;

    if(hashTable[hash_key]->id == id){
        return hashTable[hash_key];
    }
    else{
        Node* node = hashTable[hash_key];
        while(node->hashNext){
            if(node->hashNext->id==id){
                return node->hashNext;
            }
            node = node->hashNext;
        }
    }
    return NULL;
}

void PrintAllHashData(){
    printf("###Print All Hash Data###\n");

    for(int i=0; i<MAX_HASH; ++i){
        printf("idx:%d",i);
        if(hashTable[i] != NULL){
            Node* node = hashTable[i];
            while(node->hashNext){
                printf("%d \n",node->id);
                node = node->hashNext;
            }
            printf("%d\n",node->id);
        }
    }
    printf("\n");
}

int main(){
    int saveidx[101] = {0,};
    for(int i=0; i<100; ++i){
        Node* node = (Node*)malloc(sizeof(Node));
        node->id = rand() % 1000;
        node->hashNext = NULL;
        AddHashData(node->id, node);
        saveidx[i] = node->id;
    }
    PrintAllHashData();

    for(int i=0; i<50; ++i){
        DelHashData(saveidx[i]);
    }
    PrintAllHashData();

    for(int i=50; i<100; ++i){
        DelHashData(saveidx[i]);
    }
    PrintAllHashData();
    return 0;
}
