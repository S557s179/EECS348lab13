#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ------------------------------------------------------------
// Faulty version (given in assignment)
// ------------------------------------------------------------
bool fail_lecture_faulty(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 1; i < attendance_records.size(); ++i) {   // BUG: skips index 0
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}

// ------------------------------------------------------------
// Correct version (for comparison)
// ------------------------------------------------------------
bool fail_lecture_correct(const vector<int>& attendance_records) {
    int absent_count = 0;
    for (int i = 0; i < attendance_records.size(); ++i) {
        absent_count += (attendance_records[i] == 0);
    }
    return absent_count >= 3;
}

// Helper to print arrays
void printVec(const vector<int>& v) {
    cout << "{ ";
    for (int x : v) cout << x << " ";
    cout << "}";
}

// Helper to run and print both outputs
void runTest(const string& name, const vector<int>& attendance) {
    cout << "=========================\n";
    cout << "Test Case: " << name << "\nAttendance: ";
    printVec(attendance);
    cout << "\n";

    bool correct = fail_lecture_correct(attendance);
    bool faulty  = fail_lecture_faulty(attendance);

    cout << "Expected Output (Correct): " << correct << "\n";
    cout << "Actual Output (Faulty):   " << faulty  << "\n";

    cout << "Result: "
         << (correct == faulty ? "NO FAILURE" : "FAILURE")
         << "\n\n";
}

int main() {

    // ------------------------------------------------------------
    // Test Case 2: Impossible under assignment constraints
    // (omitted because array must have size 10)
    // ------------------------------------------------------------

    // ------------------------------------------------------------
    // Test Case 3: Executes the fault, but no error state
    // ------------------------------------------------------------
    vector<int> tc3 = {1,1,1,1,1,1,1,1,1,1};

    // ------------------------------------------------------------
    // Test Case 4: Error state but no failure
    // ------------------------------------------------------------
    vector<int> tc4 = {0,1,1,1,1,1,1,1,1,1};

    // ------------------------------------------------------------
    // Test Case 5: Failure
    // ------------------------------------------------------------
    vector<int> tc5 = {0,0,0,1,1,1,1,1,1,1};

    runTest("3. Executes fault but no error state", tc3);
    runTest("4. Error state but no failure", tc4);
    runTest("5. Failure", tc5);

    return 0;
}
