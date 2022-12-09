#pragma once

#include <memory>

#include "Node.h"

class SpriteNode: public Node{
private:
    std::shared_ptr<class Sprite> sprite;

    class SpriteRenderer* renderer;

public:
    explicit SpriteNode(const std::shared_ptr<Sprite> &sprite, SpriteRenderer* renderer);
    SpriteNode(const SpriteNode &obj);

    std::shared_ptr<Node> Clone() override;

    [[nodiscard]] const Sprite* getSprite() const;
    virtual ~SpriteNode();

protected:
    void Draw(glm::mat4 &ParentTransform, bool IsDirty) override;

private:
    SpriteNode();
};
