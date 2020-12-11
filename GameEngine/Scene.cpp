#include "pch.h"
#include "Scene.h"

Scene Scene::instance;

Scene::Scene() {
    score = 1000;
}

shared_ptr<GameObject> Scene::getGameObject(int id) {
    return _gameObjects[id];
}

map<int, shared_ptr<GameObject>> Scene::getGameObjects() {
    return _gameObjects;
}

shared_ptr<GameObject> Scene::getEntityAtIndex(int index) {
    return _gameObjects[_entities.at(index)];
}

size_t Scene::getEntitiesSize() {
    return _entities.size();
}

void Scene::addGameObject(int index, shared_ptr<GameObject> obj) {
    _gameObjects.insert(std::pair<int, shared_ptr<GameObject>>(index, obj));
}

void Scene::addGameObject(shared_ptr<GameObject> obj) {
    addGameObject(obj->id, obj);
}

void Scene::addTextUiElement(shared_ptr<TextUiElement> obj) {
    _textElements.push_back(obj);
}

void Scene::addEntity(shared_ptr<GameObject> obj) {
    addGameObject(obj->id, obj);
    _entities.push_back(obj->id);
}

int Scene::getNextAvailableId() {
    int nextId = _gameObjects.size() + 1;
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

void Scene::addItem(std::string name, shared_ptr<AbstractManageableItem> item) {
    int id = _items.size() + 1;
    
    _items.insert(std::pair<std::string, shared_ptr<AbstractManageableItem>>(name, item));
    _keyRegistry.insert(std::pair<int, std::string>(id, name));
}

shared_ptr<AbstractManageableItem> Scene::getItem(int index) {
    return _items[_keyRegistry[index]];
}

shared_ptr<AbstractManageableItem> Scene::getItem(std::string name) {
    return _items[name];
}

shared_ptr<GameObject> Scene::getPlayer() {
    return _player;
}

void Scene::setPlayer(shared_ptr<GameObject> player) {
    _player = player;
}

shared_ptr<MoveExtension> Scene::getPlayerMoveExtension() {
    return dynamic_pointer_cast<MoveExtension>(_player->getExtension(typeid(MoveExtension)));
}

shared_ptr<CanWieldExtension> Scene::getWieldExtension() {
    return dynamic_pointer_cast<CanWieldExtension>(_player->getExtension(typeid(CanWieldExtension)));
}

void Scene::reset() {
    if (getPlayer() && getPlayer()->hasExtension(typeid(MoveExtension)))
        getPlayerMoveExtension()->reset();

    gameOver = false;
    score = 1000;
    _gameObjects.clear();
    _textElements.clear();
    preRender = false;
    hasCheated = false;
}

void Scene::render(const unique_ptr<Window>& window) {


    for (pair<int, shared_ptr<GameObject>> const& x : _gameObjects) {
        if (x.second != nullptr)
            x.second->render(window);
    }

    for (auto textElement : _textElements) {
        if (!preRender) {
            textElement->preRender(window);
            preRender = true;
        }


        textElement->render(window);
    }

}

float Scene::metersToPixels(float meters) {
    return meters * zoom;
}

float Scene::pixelsToMeters(float pixels) {
    return pixels / zoom;
}




