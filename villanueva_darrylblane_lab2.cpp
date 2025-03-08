#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node  *link;
}Node;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }
        
        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << "A new node has been inserted at the beginning \n" <<endl;
    
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;
    
    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such exist, please try again later.";
        }
        
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "An new node has been inserted after " + after + "\n";
}

int main(){
    Node *head = createNode("Hit'Em up by 2pac");
    
    head = insertAtEnd("It Wasn't Me by Shaggy", head);
    head = insertAtEnd("Family Affair by Mary J.Blige", head);
    head = insertAtEnd("Do For Love by 2pac", head);
    head = insertAtEnd("Without Me by Eminem", head);
    
    head = insertAtBeginning("Easy by Mac ayres", head);
    head = insertAtBeginning("Can We Make love by Keith Sweat", head);
    head = insertAtBeginning("You are Not Alone by Michael Jackson", head);
    head = insertAtBeginning("Loose by Daniel Caesar", head);
    traverse(head);
    
    insertAfter ("Ikaw lang by nobita", "You Are Not Alone by Michael Jackson", head);
    insertAfter ("Lihim by Arthur miguel", "Easy by Mac ayres", head);
    insertAfter ("Uhaw by Dilaw", "Can We Make Love by Keith Sweat", head);
    traverse(head);
    
    

    return 0;
}