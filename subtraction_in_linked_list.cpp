class Solution {
public:
    string removeLeadingZeros(const string& num) {
        int nonZeroPos = 0;
        while (nonZeroPos < num.size() && num[nonZeroPos] == '0') {
            nonZeroPos++;
        }
        return nonZeroPos == num.size() ? "0" : num.substr(nonZeroPos);
    }
    string subtractStrings(string& s1, string& s2){
        
        string num1=s1;
        string num2=s2;
        num1=removeLeadingZeros(num1);
        num2=removeLeadingZeros(num2);
        
        if(num1.length()<num2.length() || (num1.length()==num2.length() && num1<num2)){
            swap(num1,num2);
        }
        string res="";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int carry=0;
        
        for(int i=0;i<num2.size();i++){
            int sub=((num1[i]-'0')-(num2[i]-'0')-carry);
            if(sub<0){
                sub=sub+10;
                carry=1;
            }else{
                carry=0;
            }
            res.push_back(sub+'0');
        }
        
        for(int i=num2.size();i<num1.size();i++){
            int sub=(num1[i]-'0')-carry;
            if(sub<0){
                sub=10+sub;
                carry=1;
            }else{
                carry=0;
            }
            res.push_back(sub+'0');
        }
        while (res.size() > 1 && res.back() == '0') {
            res.pop_back();
        }
        reverse(res.begin(),res.end());
        
        return res;
    }
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
       // vector<int>vec1;
       // vector<int>vec2;
        
        Node* curr1=head1;
        Node* curr2=head2;
        
        string s1="";
        string s2="";
        while(curr1){
           // vec1.push_back(curr1->data);
            s1+=to_string(curr1->data);
            curr1=curr1->next;
        }
         while(curr2){
           // vec2.push_back(curr2->data);
            s2+=to_string(curr2->data);
            curr2=curr2->next;
        }
        if (s1 == "0" && s2 == "0") {
            return new Node(0);
        }
        string result = subtractStrings(s1, s2);
    
        
        Node* dummy=new Node(0);
        Node* temp=dummy;
        
        for(char c:result){
            temp->next=new Node(c-'0');
            temp=temp->next;
        }
        
        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
        
        
    }
};