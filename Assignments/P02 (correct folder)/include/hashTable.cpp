#include "hashTable.hpp"
#include "counters.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using json = nlohmann::json;

class InstrumentedHashTable : public HashTable {
private:
    Counters c;
public:
    void clear() {
        c = Counters();
    }

    void runLoggedInsert(int key) {
        c.inserts++;
        // Tracking chain comparisons and modifications
        if (this->insert(key)) {
            c.structural_ops++;
        }
    }

    void runLoggedContains(int key) {
        c.lookups++;
        this->contains(key);
    }

    void runLoggedErase(int key) {
        c.deletes++;
        if (this->erase(key)) {
            c.structural_ops++;
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
        InstrumentedHashTable ht;

        for (const auto& operation : workload) {
            std::string op = operation["op"];
            int val = operation["value"];

            if (op == "insert") ht.runLoggedInsert(val);
            else if (op == "contains") ht.runLoggedContains(val);
            else if (op == "delete") ht.runLoggedErase(val);
        }

        ht.saveMetrics(baseName + "_HashTable_output.json");
        std::cout << "Processed " << baseName << " via Hash Table.\n";
    }
    return 0;
}