#include "game_state_recorder.h"
#include <fstream>
#include <iostream>

void GameStateRecorder::recordGameState(const GameRecord& record) {
    records.push_back(record);
}

json GameStateRecorder::fruitInfoToJson(const FruitInfo& fruit) {
    json j;
    j["type"] = fruit.type;
    j["x"] = fruit.x;
    j["y"] = fruit.y;
    j["radius"] = fruit.radius;
    return j;
}

json GameStateRecorder::gameStateToJson(const GameState& state) {
    json j;
    j["list-fruit"] = json::array();
    for (const auto& fruit : state.list_fruit) {
        j["list-fruit"].push_back(fruitInfoToJson(fruit));
    }
    j["current_fruit"] = fruitInfoToJson(state.current_fruit);
    j["next_fruit"] = fruitInfoToJson(state.next_fruit);
    return j;
}

json GameStateRecorder::gameRecordToJson(const GameRecord& record) {
    json j;
    
    // Game area
    j["game_area"]["x_min"] = record.game_area.x_min;
    j["game_area"]["x_max"] = record.game_area.x_max;
    j["game_area"]["y_min"] = record.game_area.y_min;
    j["game_area"]["y_max"] = record.game_area.y_max;
    
    // State
    j["state"] = gameStateToJson(record.state);
    
    // Action
    j["action"]["x"] = record.action.x;
    
    // Reward
    j["reward"] = record.reward;
    
    // Next state
    j["next_state"] = gameStateToJson(record.next_state);
    
    // Done
    j["done"] = record.done;
    
    return j;
}

void GameStateRecorder::saveToFile(const std::string& filename) {
    try {
        std::ofstream file(filename, std::ios::app); // Mode append
        if (!file.is_open()) {
            std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filename << std::endl;
            return;
        }

        // Si le fichier est vide, on commence un tableau JSON
        if (file.tellp() == 0) {
            file << "[\n";
        } else {
            // On se positionne juste avant le dernier ']' pour ajouter une virgule
            file.seekp(-1, std::ios::end);
            file << ",\n";
        }

        // On écrit le nouvel enregistrement
        file << std::setw(2) << gameRecordToJson(records.back()) << "\n]";
        
        file.close();
    }
    catch (const std::exception& e) {
        std::cerr << "Erreur lors de la sauvegarde: " << e.what() << std::endl;
    }
}

void GameStateRecorder::loadFromFile(const std::string& filename) {
    try {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Erreur: Impossible d'ouvrir le fichier " << filename << std::endl;
            return;
        }

        json j;
        file >> j;

        records.clear();
        for (const auto& record_json : j) {
            GameRecord record;
            
            // Game area
            record.game_area.x_min = record_json["game_area"]["x_min"];
            record.game_area.x_max = record_json["game_area"]["x_max"];
            record.game_area.y_min = record_json["game_area"]["y_min"];
            record.game_area.y_max = record_json["game_area"]["y_max"];
            
            // State
            for (const auto& fruit_json : record_json["state"]["list-fruit"]) {
                FruitInfo fruit;
                fruit.type = fruit_json["type"];
                fruit.x = fruit_json["x"];
                fruit.y = fruit_json["y"];
                fruit.radius = fruit_json["radius"];
                record.state.list_fruit.push_back(fruit);
            }
            
            record.state.current_fruit.type = record_json["state"]["current_fruit"]["type"];
            record.state.current_fruit.x = record_json["state"]["current_fruit"]["x"];
            record.state.current_fruit.y = record_json["state"]["current_fruit"]["y"];
            record.state.current_fruit.radius = record_json["state"]["current_fruit"]["radius"];
            
            record.state.next_fruit.type = record_json["state"]["next_fruit"]["type"];
            record.state.next_fruit.x = record_json["state"]["next_fruit"]["x"];
            record.state.next_fruit.y = record_json["state"]["next_fruit"]["y"];
            record.state.next_fruit.radius = record_json["state"]["next_fruit"]["radius"];
            
            // Action
            record.action.x = record_json["action"]["x"];
            
            // Reward
            record.reward = record_json["reward"];
            
            // Next state
            for (const auto& fruit_json : record_json["next_state"]["list-fruit"]) {
                FruitInfo fruit;
                fruit.type = fruit_json["type"];
                fruit.x = fruit_json["x"];
                fruit.y = fruit_json["y"];
                fruit.radius = fruit_json["radius"];
                record.next_state.list_fruit.push_back(fruit);
            }
            
            record.next_state.current_fruit.type = record_json["next_state"]["current_fruit"]["type"];
            record.next_state.current_fruit.x = record_json["next_state"]["current_fruit"]["x"];
            record.next_state.current_fruit.y = record_json["next_state"]["current_fruit"]["y"];
            record.next_state.current_fruit.radius = record_json["next_state"]["current_fruit"]["radius"];
            
            record.next_state.next_fruit.type = record_json["next_state"]["next_fruit"]["type"];
            record.next_state.next_fruit.x = record_json["next_state"]["next_fruit"]["x"];
            record.next_state.next_fruit.y = record_json["next_state"]["next_fruit"]["y"];
            record.next_state.next_fruit.radius = record_json["next_state"]["next_fruit"]["radius"];
            
            // Done
            record.done = record_json["done"];
            
            records.push_back(record);
        }
        
        file.close();
    }
    catch (const std::exception& e) {
        std::cerr << "Erreur lors du chargement: " << e.what() << std::endl;
    }
} 