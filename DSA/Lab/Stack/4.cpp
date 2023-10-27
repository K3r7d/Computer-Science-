#include<sstream>
int evaluatePostfix(std::string expr) {
    std::stack<int> st;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            st.push(std::stoi(token));
        } else {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();

            switch (token[0]) {
                case '+':
                    st.push(a + b);
                    break;
                case '-':
                    st.push(a - b);
                    break;
                case '*':
                    st.push(a * b);
                    break;
                case '/':
                    st.push(a / b);
                    break;
            }
        }
    }

    return st.top();
}