#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool fail_lecture(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i) {
        absent_count += attendance_records[i] == 0;
    }

    return absent_count >= 3;
}

int actual_absent_count(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i) {   // bugged function
        absent_count += attendance_records[i] == 0;
    }
    return absent_count;   // returns the count, not (count >= 3)
}

int expected_absent_count(const vector<int>& records) {
    int absent_count = 0;
    for (size_t i = 0; i < records.size(); ++i) {   // starts at 0
        if (records[i] == 0) {
            absent_count++;
        }
    }
    return absent_count;
}

bool expected_fail_lecture(const vector<int>& records) {
    return expected_absent_count(records) >= 3;
}

int main() {
    // Q4: error state, but no failure
    vector<int> q4 = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Q4 record: 0 1 1 1 1 1 1 1 1 1\n";
    cout << "Absence count: expected = " << expected_absent_count(q4)
         << ", actual = " << actual_absent_count(q4) << "\n";
    cout << "Output: expected = " << expected_fail_lecture(q4)
         << ", actual = " << fail_lecture(q4) << "\n\n";

    // Q5: failure
    vector<int> q5 = {0, 0, 0, 1, 1, 1, 1, 1, 1, 1};
    cout << "Q5 record: 0 0 0 1 1 1 1 1 1 1\n";
    cout << "Absence count: expected = " << expected_absent_count(q5)
         << ", actual = " << actual_absent_count(q5) << "\n";
    cout << "Output: expected = " << expected_fail_lecture(q5)
         << ", actual = " << fail_lecture(q5) << "\n";

    return 0;
}