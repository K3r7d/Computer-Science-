#include <string>
#include <stack>
#include <cstdlib> 
int baseballScore(string ops) {
    stack<int> scores; 

    for (char c : ops) {
        if (isdigit(c)) {
            scores.push(c - '0');
        } else if (c == 'C') {
            if (!scores.empty()) {
                scores.pop();
            }
        } else if (c == 'D') {
            if (!scores.empty()) {
                scores.push(scores.top() * 2);
            }
        } else if (c == '+') {
            if (scores.size() >= 2) {
                int last = scores.top();
                scores.pop();
                int secondLast = scores.top();
                scores.push(last);
                scores.push(last + secondLast);
            }
        }
    }
    int sum = 0;
    while (!scores.empty()) {
        sum += scores.top();
        scores.pop();
    }

    return sum;
}
