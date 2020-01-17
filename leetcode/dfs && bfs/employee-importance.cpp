//
// Created by segni on 17/01/2020.
//
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee *> um;

        for (Employee *emp : employees)
            um[emp->id] = emp;

        int sum = 0;
        queue<int> que;
        que.push(id);

        while (!que.empty()) {
            int em = que.front();
            sum += um[em]->importance;

            for (int subs : um[em]->subordinates)
                que.push(subs);

            que.pop();
        }
        return sum;
    }
};
