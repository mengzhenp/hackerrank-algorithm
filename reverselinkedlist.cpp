Node* Reverse(Node *head)
{
  // Complete this method
    if (head == nullptr){
        return head;
    }
   
    Node* next = head->next;
    head->next = nullptr;
    Node* temp;
    while (next != nullptr){
        temp = next;
        next = next->next;
        temp->next = head;
        head = temp;
    }
    return head;
}