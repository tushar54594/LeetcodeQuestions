/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int top = 0, down = m-1, left = 0, right = n-1;
        int dir = 0;
        while(top<=down && left<=right)
        {
            if(dir==0){
                for(int i = left; i<=right; i++)
                {
                    if(head != NULL)
                    {
                        res[top][i] = head->val;
                        head = head->next;
                    }
                    else break;
                }
                top++;
            }
            else if(dir == 1){
                for(int i = top; i<=down; i++)
                {    
                    if(head != NULL)
                    {
                        res[i][right] = head->val;
                        head = head->next;
                    }
                    else break;
                }
                right--;              
            }
            else if(dir == 2){
                for(int i = right; i>= left; i--)
                {    
                    if(head != NULL)
                    {
                        res[down][i] = head->val;
                        head = head->next;
                    }
                    else break;
                }
                down--;
            }
            else if(dir == 3){
                for(int i = down; i>=top; i--)
                {    
                    if(head != NULL)
                    {
                        res[i][left] = head->val;
                        head = head->next;
                    }
                    else break;
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        
        return res;
    }
};