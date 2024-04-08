#include <vector>

class Solution {
public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches) {
        int circular_count = 0;
        int square_count = 0;
        
        // Count the number of students preferring circular and square sandwiches
        for (int student : students) {
            if (student == 0) {
                circular_count++;
            } else {
                square_count++;
            }
        }
        
        // Iterate through the sandwiches
        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (circular_count > 0) {
                    circular_count--;
                } else {
                    break; // No more students who prefer circular sandwiches
                }
            } else {
                if (square_count > 0) {
                    square_count--;
                } else {
                    break; // No more students who prefer square sandwiches
                }
            }
        }
        
        // Remaining count of students who couldn't eat
        return circular_count + square_count;
    }
};
