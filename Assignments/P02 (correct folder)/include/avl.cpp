#include "avl.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using json = nlohmann::json;

// Runner class that executes workloads using an AVL tree
class RunnerAVL : public Avl {
public:
    // Reads a JSON workload, applies operations to the AVL tree, and saves results
    void executeWorkload(const std::string& inputPath, const std::string& outputPath) {
        std::ifstream inFile(inputPath);

        // Handle file open failure
        if (!inFile.is_open()) {
            std::cerr << "Warning: Could not open " << inputPath << "\n";
            return;
        }

        // Parse workload and reset tree state
        json workload = json::parse(inFile);
        this->reset();

        // Execute each operation from the workload
        for (const auto& operation : workload) {
            std::string op = operation["op"];
            int val = operation["value"];

            if (op == "insert") {
                this->insert(val);
            } else if (op == "contains") {
                this->contains(val);
            } else if (op == "delete") {
                this->erase(val);
            }
        }

        // Save results after processing
        this->save(outputPath, true);

        std::cout << "Successfully processed " << inputPath << " -> " << outputPath << "\n";
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

    RunnerAVL runner;

    // Process each workload and generate corresponding output
    for (const auto& baseName : workloads) {
        runner.executeWorkload(baseName + ".json", baseName + "_AVL_output.json");
    }

    return 0;
}