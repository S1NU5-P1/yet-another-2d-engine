#include "include/Nodes/Map.h"

#include <fstream>

Map::Map(const std::string &path, const std::map<char, struct Node *> &nodesMap) {
    std::ifstream file(path);

    std::string FileLine;
    int lineNumber = 0, characterNumber = 0;
    size = glm::vec2{0, 0};

    while (std::getline(file, FileLine)) {
        for (char character : FileLine) {
            auto tile = nodesMap.at(character)->Clone();
            tile->GetLocalTransform()->SetPosition(glm::vec3(characterNumber, lineNumber, 0));
            AddChild(tile);

            characterNumber++;
        }
        size.x = std::max(size.x, (float)characterNumber);
        characterNumber = 0;
        lineNumber++;
    }
    size.y = (float)lineNumber;

    file.close();
}

const glm::vec2 &Map::GetSize() const {
    return size;
}