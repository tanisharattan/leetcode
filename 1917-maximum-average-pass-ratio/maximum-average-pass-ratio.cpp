class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
         // Function to calculate the gain if we add one student to a class
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        // Max heap (priority queue) to store {gain, pass, total}
        // Using tuple so we can store all values together
        priority_queue<tuple<double,int,int>> pq;

        // Push all classes with their initial gain into the heap
        for (auto &c : classes) {
            pq.push({gain(c[0], c[1]), c[0], c[1]});
        }

        // Assign each extra student one by one
        while (extraStudents--) {
            auto [g, p, t] = pq.top(); // Get the class with max gain
            pq.pop();

            // Add one brilliant student (both pass and total increase)
            p += 1;
            t += 1;

            // Push the updated class back into the heap with new gain
            pq.push({gain(p, t), p, t});
        }

        // Now compute the final average pass ratio
        double sum = 0.0;
        while (!pq.empty()) {
            auto [g, p, t] = pq.top();
            pq.pop();
            sum += (double)p / t;
        }

        return sum / classes.size();
    }
};