#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node {
    struct Node* forward;
    struct Node* backward;
    string key;
    int value;
};
int main()
{
    int capacity, op_type;
    cin >> capacity;
    int current_capacity = 0;

    unordered_map<string, struct Node*> map;
    struct Node* head = NULL;
    struct Node* tail = NULL;

    while(true) {
        cin >> op_type;

        if (op_type == 1) {
            string t1;
            int t2;
            cin >> t1 >> t2;

            if (map.count(t1)) {
                struct Node* curr = map[t1];
                cout << "key already exists : " << curr->value << '\n';
                curr->value = t2;

                struct Node* curr_next = NULL;
                struct Node* curr_prev = NULL;

                if (curr->forward) {
                    curr_next = curr->forward;
                }
                if (curr->backward) {
                    curr_prev = curr->backward;
                }

                curr->forward = head;
                curr->backward = NULL;
                head = curr;

                if (curr_prev) {
                    curr_prev->forward = curr_next;
                }

                continue;
            }
            
            if (current_capacity >= capacity) {
                struct Node* pre_tail = tail->backward;
                string delete_key = tail->key;
                map.erase(delete_key);
                free(tail);
                tail = pre_tail;
                cout << "key deleted due to low space : " << delete_key << '\n';
            }
            
            if (head==NULL) {
                head = (struct Node*)malloc(sizeof(struct Node));
                map[t1] = head;
                head->key = t1;
                head->value = t2;
                head->forward = NULL;
                head->backward = NULL;
                tail = head;
            } else {
                struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
                map[t1] = temp;
                temp->key = t1;
                temp->value = t2;
                temp->forward = head;
                temp->backward = NULL;

                head->backward = temp;
                head = temp;
            }
            current_capacity++;
        } else if (op_type == 2) {
            string key;
            cin >> key;
            if (map.count(key)) {
                struct Node* curr = map[key];
                cout << "Found key : " << curr->value << '\n';
                struct Node* curr_next = NULL;
                struct Node* curr_prev = NULL;

                if (curr->forward) {
                    curr_next = curr->forward;
                }
                if (curr->backward) {
                    curr_prev = curr->backward;
                }

                curr->forward = head;
                curr->backward = NULL;
                head = curr;

                if (curr_prev) {
                    curr_prev->forward = curr_next;
                }
            } else {
                cout << "Key not found in map\n";
            }
        } else if (op_type == 3) {
            break;
        } else if (op_type == 4) {
            struct Node* curr = head;
            int current_capacity_2 = current_capacity;
            while(curr && current_capacity_2--) {
                cout << curr->key << ":" << curr->value << " ";
                curr = curr->forward;
            }
            cout << '\n';
        }
    }
    cout << "Program ends\n";

    return 0;
}