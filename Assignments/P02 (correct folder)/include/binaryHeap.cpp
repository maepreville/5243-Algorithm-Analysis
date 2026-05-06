#include "binaryHeap.hpp"
#include "counters.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using json = nlohmann::json;

// Heap wrapper that tracks operation metrics (inserts, deletes, lookups, etc.)
class InstrumentedHeap : public BinaryHeap {
private:
    Counters c;  // Stores performance counters

public:
    // Insert operation with logging
    void runLoggedPush(int val) {
        c.inserts++;
        this->push(val);
        c.structural_ops++;
    }

    // Delete (pop) operation with logging
    void runLoggedPop() {
        c.deletes++;
        if (this->pop()) {
            c.structural_ops++;
        }
    }

    // Lookup operation (approximated using top for heap)
    void runLoggedTop() {
        c.lookups++;
        if (!this->empty()) {
            this->top();
        }
    }

    // Save collected metrics to output file
    void saveMetrics(const std::string& filename) {
        c.saveCounters(filename, true);
    }
};

int main() {
    // List of workload files to process
    std::vector<std::string> workloads = {
        "workload_A_1000", "workload_A_5000", "workload_A_10000", "workload_A_20000",
        "workload_B_1000", "workload_B_5000", "workload_B_10000", "workload_B_20000",
        "workload_C_1000", "workload_C_5000", "workload_C_10000", "workload_C_20000",
        "workload_D_1000", "workload_D_5000", "workload_D_10000", "workload_D_20000"
    };

    // Process each workload file
    for (const auto& baseName : workloads) {
        std::ifstream inFile(baseName + ".json");
        if (!inFile.is_open()) continue;

        // Parse workload and initialize heap
        json workload = json::parse(inFile);
        InstrumentedHeap bh;

        // Execute operations from workload
        for (const auto& operation : workload) {
            std::string op = operation["op"];
            int val = operation["value"];

            // Map workload operations to heap operations
            if (op == "insert") bh.runLoggedPush(val);
            else if (op == "contains") bh.runLoggedTop();
            else if (op == "delete") bh.runLoggedPop();
        }

        // Save performance metrics for this workload
        bh.saveMetrics(baseName + "_BinaryHeap_output.json");

        std::cout << "Processed " << baseName << " via BinaryHeap.\n";
    }

    return 0;
}