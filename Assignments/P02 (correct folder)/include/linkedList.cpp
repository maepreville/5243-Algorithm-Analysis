#include "linkedList.hpp"
#include "counters.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using json = nlohmann::json;

// Linked list wrapper that tracks operation metrics (inserts, deletes, lookups, etc.)
class InstrumentedLinkedList : public LinkedList {
private:
    Counters c;  // Stores performance counters

public:
    // Insert operation with logging
    void runLoggedInsert(int val) {
        c.inserts++;
        if (this->insert(val)) {
            c.structural_ops++;
        }
    }

    // Lookup operation with logging
    void runLoggedContains(int val) {
        c.lookups++;
        this->contains(val);
    }

    // Delete operation with logging
    void runLoggedErase(int val) {
        c.deletes++;
        if (this->erase(val)) {
            c.structural_ops++;
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

        // Parse workload and initialize linked list
        json workload = json::parse(inFile);
        InstrumentedLinkedList ll;

        // Execute operations from workload
        for (const auto& operation : workload) {
            std::string op = operation["op"];
            int val = operation["value"];

            if (op == "insert") ll.runLoggedInsert(val);
            else if (op == "contains") ll.runLoggedContains(val);
            else if (op == "delete") ll.runLoggedErase(val);
        }

        // Save performance metrics for this workload
        ll.saveMetrics(baseName + "_LinkedList_output.json");

        std::cout << "Processed " << baseName << " via LinkedList.\n";
    }

    return 0;
}