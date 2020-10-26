// Copyright 2020 Sakshi Sharma
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

ListNode* rev(ListNode* head){
    //Function to reverse a linked list
    if((!head) || (!head->next))
        return head;
    ListNode* prev=NULL, *curr = head, *next = head->next;
    while(next){
        ListNode* temp = next->next;
        curr->next = prev;
        next->next = curr;
        prev = curr;
        curr = next;
        next = temp;
    }
    return curr;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    int i = 0, len = 0;
    //Creating a dummy node whose next is current head
    ListNode* ans = new ListNode(0);
    ans->next = head;
    ListNode *temp2 = head;
        
    //Calculating length of linked list
    while(temp2){
        temp2 = temp2->next;
        len++;
    }
        
    temp2 = ans;
    while(i < len){
        int j=i;
        ListNode* old = temp2;
        //Finding kth node from old within list
        while((temp2) && (j <= (i+k-1)) && (j <= len)){
            temp2 = temp2->next;
            j++;
        }
        //Reached a null node
        if((!temp2) || (j > len) && ((j-i) < k)){
            break;
        }
        ListNode *temp1 = temp2->next;
        temp2->next = NULL;
        ListNode *temp4 = old->next;
        //Reverse k length list and join
        old->next = rev(temp4);
        while(old->next){
            old = old->next;
        }
        temp2 = old;
        old->next = temp1;
        i = j;
    }
    
    return ans->next;
}
