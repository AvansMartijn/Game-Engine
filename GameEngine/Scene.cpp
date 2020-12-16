#include "pch.h"
#include "Scene.h"

Scene Scene::instance;

Scene::Scene() {
    score = 1000;
}

shared_ptr<GameObject> Scene::getGameObject(int id) {
    return _gameObjects[id];
}

map<int, shared_ptr<GameObject>> Scene::getGameObjects() const {
    return _gameObjects;
}

shared_ptr<GameObject> Scene::getEntityAtIndex(int index) {
    return _gameObjects[_entities.at(index)];
}

size_t Scene::getEntitiesSize() const {
    return _entities.size();
}

void Scene::addGameObject(int index, shared_ptr<GameObject> obj) {
    _gameObjects.insert(std::pair<int, shared_ptr<GameObject>>(index, obj));
}

void Scene::addGameObject(shared_ptr<GameObject> obj) {
    addGameObject(obj->id, obj);
}

void Scene::addTextUiElement(unique_ptr<TextUiElement> obj) {
    _textElements.push_back(std::move(obj));
}

void Scene::addEntity(shared_ptr<GameObject> obj) {
    addGameObject(obj->id, obj);
    _entities.push_back(obj->id);
}

int Scene::getNextAvailableId() {
    int nextId = (int)_gameObjects.size() + 1;
    if (!_gameObjects.empty())
        nextId = _gameObjects.rbegin()->first + 1;

    return nextId;
}

void Scene::removeGameObject(int id) {
    _gameObjects.erase(id);
}

void Scene::removeEntity(int index) {
    _entities.erase(_entities.begin() + index);
}

void Scene::addItem(std::string name, unique_ptr<AbstractManageableItem> item) {
    int id = (int)_items.size() + 1;
    
    _items.insert(std::pair<std::string, unique_ptr<AbstractManageableItem>>(name, std::move(item)));
    _keyRegistry.insert(std::pair<int, std::string>(id, name));
}

AbstractManageableItem* Scene::getItem(int index) {
    if (_items[_keyRegistry[index]] == nullptr)
        return nullptr;

    return _items[_keyRegistry[index]].get();
}

AbstractManageableItem* Scene::getItem(std::string name) {
    if (_items[name] == nullptr)
        return nullptr;

    return _items[name].get();
}

shared_ptr<GameObject> Scene::getPlayer() const {
    return _player;
}

void Scene::setPlayer(shared_ptr<GameObject> player) {
    _player = player;
}

void Scene::reset() {
    if (getPlayer() && getPlayer()->hasExtension(typeid(MoveExtension)))
        getPlayer()->getExtension<MoveExtension>()->reset();

    gameOver = false;
    score = 1000;
    _gameObjects.clear();
    preRender = false;
    hasCheated = false;
}

void Scene::render(const unique_ptr<Window>& window) {
    for (pair<int, shared_ptr<GameObject>> const& x : _gameObjects) {
        if (x.second != nullptr)
            x.second->render(window);
    }

    for (const auto& textElement : _textElements) {
        if (!preRender) {
            textElement->preRender(window);
            preRender = true;
        }

        textElement->render(window);
    }
}

float Scene::metersToPixels(float meters) const {
    return meters * zoom;
}

float Scene::pixelsToMeters(float pixels) const {
    return pixels / zoom;
}