#include "binaryHeap.hpp"
#include "counters.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using json = nlohmann::json;

class InstrumentedHeap : public BinaryHeap {
private:
    Counters c;
public:
    void runLoggedPush(int val) {
        c.inserts++;
        this->push(val);
        c.structural_ops++;
    }

    void runLoggedPop() {
        c.deletes++;
        if (this->pop()) {
            c.structural_ops++;
        }
    }

    void runLoggedTop() {
        c.lookups++;
        if (!this->empty()) {
            this->top();
        }
    }

    void saveMetrics(const std::string& filename) {
        c.saveCounters(filename, true);
    }
};

int main() {
    std::vector<std::string> workloads = {
        "workload_A_1000", "workload_A_5000", "workload_A_10000", "workload_A_20000",
        "workload_B_1000", "workload_B_5000", "workload_B_10000", "workload_B_20000",
        "workload_C_1000", "workload_C_5000", "workload_C_10000", "workload_C_20000",
        "workload_D_1000", "workload_D_5000", "workload_D_10000", "workload_D_20000"
    };

    for (const auto& baseName : workloads) {
        std::ifstream inFile(baseName + ".json");
        if (!inFile.is_open()) continue;

        json workload = json::parse(inFile);
        InstrumentedHeap bh;

        for (const auto& operation : workload) {
            std::string op = operation["op"];
            int val = operation["value"];

            // Adjust mapping safely since heaps lack explicit value lookup keys
            if (op == "insert") bh.runLoggedPush(val);
            else if (op == "contains") bh.runLoggedTop();
            else if (op == "delete") bh.runLoggedPop();
        }

        bh.saveMetrics(baseName + "_BinaryHeap_output.json");
        std::cout << "Processed " << baseName << " via BinaryHeap.\n";
    }
    return 0;
}