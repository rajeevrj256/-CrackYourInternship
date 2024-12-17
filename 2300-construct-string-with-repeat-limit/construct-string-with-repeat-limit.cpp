class Solution {
  public:
    string repeatLimitedString(string s, int repeatLimit) {
      unordered_map < char, int > hash;
      for (char c:s) {
        hash[c]++;
      }

      priority_queue < pair < char, int >> pq;

      for (auto i:hash) {
        pq.push({ i.first, i.second });
      }
  
          string ans = "";

      while (!pq.empty()) {
        pair < char, int > front=pq.top();
        pq.pop();
              int count = front.second;
              int len = min(count, repeatLimit);

        for (int i = 0; i < len; i++) {
          ans += (front.first);

        }
        if (count > repeatLimit) {
          if (pq.empty()) {
            break;
          }


          pair < char, int > sec=pq.top();
          pq.pop();
          ans += sec.first;
          
          if (--sec.second > 0) {
            pq.push(sec);
        }
         pq.push({ front.first, count- repeatLimit});
      }
    }
  
          return ans;
      }
  };