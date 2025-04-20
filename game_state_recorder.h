#pragma once

#include "include.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <memory>

using json = nlohmann::json;

struct GameArea {
    int x_min = 0;
    int x_max = 1000;
    int y_min = 0;
    int y_max = 1000;
};

struct FruitInfo {
    std::string type;
    float x;
    float y;
    int radius;
};

struct GameState {
    std::vector<FruitInfo> list_fruit;
    FruitInfo current_fruit;
    FruitInfo next_fruit;
};

struct GameAction {
    float x;
};

struct GameRecord {
    GameArea game_area;
    GameState state;
    GameAction action;
    int reward;
    GameState next_state;
    bool done;
};

class GameStateRecorder {
public:
    static GameStateRecorder& getInstance() {
        static GameStateRecorder instance;
        return instance;
    }

    void recordGameState(const GameRecord& record);
    void saveToFile(const std::string& filename = "game_records.json");
    void loadFromFile(const std::string& filename = "game_records.json");
    
    // Getters pour accéder aux données
    const std::vector<GameRecord>& getRecords() const { return records; }
    void clearRecords() { records.clear(); }

private:
    GameStateRecorder() {}
    std::vector<GameRecord> records;
    
    // Conversion helpers
    json fruitInfoToJson(const FruitInfo& fruit);
    json gameStateToJson(const GameState& state);
    json gameRecordToJson(const GameRecord& record);
}; 