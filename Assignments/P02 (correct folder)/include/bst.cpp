#include "bst.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using json = nlohmann::json;

class RunnerBST : public Bst {
public:
    void executeWorkload(const std::string& inputPath, const std::string& outputPath) {
        std::ifstream inFile(inputPath);
        if (!inFile.is_open()) {
            std::cerr << "Warning: Could not open " << inputPath << "\n";
            return;
        }

        json workload = json::parse(inFile);
        this->reset(); // Reset counters and structure

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

        this->save(outputPath, true);
        std::cout << "Successfully processed " << inputPath << " -> " << outputPath << "\n";
    }
};

int main() {
    std::vector<std::string> workloads = {
        "workload_A_1000", "workload_A_5000", "workload_A_10000", "workload_A_20000",
        "workload_B_1000", "workload_B_5000", "workload_B_10000", "workload_B_20000",
        "workload_C_1000", "workload_C_5000", "workload_C_10000", "workload_C_20000",
        "workload_D_1000", "workload_D_5000", "workload_D_10000", "workload_D_20000"
    };

    RunnerBST runner;
    for (const auto& baseName : workloads) {
        runner.executeWorkload(baseName + ".json", baseName + "_BST_output.json");
    }
    return 0;
}