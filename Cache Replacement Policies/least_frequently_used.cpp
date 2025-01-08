#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node {
    struct Node* forward;
    struct Node* backward;
    string key;
    int value;
    int frequency;
};
int main()
{
    int capacity, op_type;
    cin >> capacity;
    int current_capacity = 0;

    unordered_map<string, struct Node*> map;
    unordered_map<int, struct Node*> freq_head_node_map;
    unordered_map<int, struct Node*> freq_tail_node_map;

    int min_freq = 0;

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
                int current_freq = curr->frequency;

                struct Node* curr_next = NULL;
                struct Node* curr_prev = NULL;

                if (curr->forward) {
                    curr_next = curr->forward;
                } else {
                    freq_tail_node_map[current_freq] = curr->backward;
                }
                if (curr->backward) {
                    curr_prev = curr->backward;
                    curr_prev->forward = curr_next;
                } else {
                    freq_head_node_map[current_freq] = curr_next;
                }

                if (freq_head_node_map[current_freq] == NULL && current_freq == min_freq) {
                    min_freq++;
                }

                curr->forward = NULL;
                curr->backward = NULL;
                curr->frequency = current_freq+1;

                struct Node* head = NULL;
                if (freq_head_node_map.count(current_freq+1)) {
                    head = freq_head_node_map[current_freq+1];
                }

                if (head) {
                    freq_head_node_map[current_freq+1] = curr;
                    curr->forward = head;
                } else {
                    freq_head_node_map[current_freq+1] = curr;
                    freq_tail_node_map[current_freq+1] = curr;
                }
                continue;
            }
            
            if (current_capacity >= capacity) {
                struct Node* tail = freq_tail_node_map[min_freq];
                struct Node* pre_tail = tail->backward;
                string delete_key = tail->key;
                map.erase(delete_key);
                free(tail);
                freq_tail_node_map[min_freq] = pre_tail;
                if (pre_tail == NULL) {
                    min_freq++;
                }
                cout << "key deleted due to low space : " << delete_key << '\n';
            }

            struct Node* head = freq_head_node_map[1];
            
            if (head==NULL) {
                head = (struct Node*)malloc(sizeof(struct Node));
                map[t1] = head;
                head->key = t1;
                head->value = t2;
                head->forward = NULL;
                head->backward = NULL;
                head->frequency = 1;
                freq_head_node_map[1] = head;
                freq_tail_node_map[1] = head;
            } else {
                struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
                map[t1] = temp;
                temp->key = t1;
                temp->value = t2;
                temp->forward = head;
                temp->backward = NULL;
                temp->frequency = 1;
                freq_head_node_map[1] = temp;
            }
            min_freq = 1;
            current_capacity++;
        } else if (op_type == 2) {
            string key;
            cin >> key;
            if (map.count(key)) {
                struct Node* curr = map[key];
                cout << "Found key : " << curr->value << '\n';
                int current_freq = curr->frequency;

                struct Node* curr_next = NULL;
                struct Node* curr_prev = NULL;

                if (curr->forward) {
                    curr_next = curr->forward;
                } else {
                    freq_tail_node_map[current_freq] = curr->backward;
                }
                if (curr->backward) {
                    curr_prev = curr->backward;
                    curr_prev->forward = curr_next;
                } else {
                    freq_head_node_map[current_freq] = curr_next;
                }

                if (freq_head_node_map[current_freq] == NULL && current_freq == min_freq) {
                    min_freq++;
                }

                curr->forward = NULL;
                curr->backward = NULL;
                curr->frequency = current_freq+1;
                struct Node* head = NULL;
                if (freq_head_node_map.count(current_freq+1)) {
                    head = freq_head_node_map[current_freq+1];
                }
                if (head) {
                    freq_head_node_map[current_freq+1] = curr;
                    curr->forward = head;
                } else {
                    freq_head_node_map[current_freq+1] = curr;
                    freq_tail_node_map[current_freq+1] = curr;
                }
            } else {
                cout << "Key not found in map\n";
            }
        } else if (op_type == 3) {
            break;
        } else if (op_type == 4) {
            for (auto i : freq_head_node_map) {
                int frequency = i.first;
                struct Node* head = i.second;
                cout << "frequency : " << frequency << '\n';
                while (head) {
                    cout << head->key << ":" << head->value << " ";
                    head = head->forward;
                }
                cout << '\n';
            }
        }
    }
    cout << "Program ends\n";

    return 0;
}