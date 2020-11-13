#include "pch.h"
#include "Scene.h"

Scene Scene::instance;

Scene::Scene() {
    score = 1000;
}

shared_ptr<GameObject> Scene::getGameObject(int id) {
    return _gameObjects[id];
}

void Scene::addGameObject(int index, shared_ptr<GameObject> obj) {
    _gameObjects.insert(std::pair<int, shared_ptr<GameObject>>(index, obj));
}

void Scene::addGameObject(shared_ptr<GameObject> obj) {
    addGameObject(_gameObjects.size() + 1, obj);
}

int Scene::getNextAvailableId() {
    return _gameObjects.size() + 1;
}

void Scene::removeGameObject(int id) {
    _gameObjects.erase(id);
}

void Scene::addItem(shared_ptr<AbstractManageableItem> item) {
    _items.insert(std::pair<int, shared_ptr<AbstractManageableItem>>(_items.size() + 1, item));
}

shared_ptr<AbstractManageableItem> Scene::getItem(int index) {
    return _items[index];
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
    score = 1000;
    _gameObjects.clear();
    _items.clear();
    getPlayerMoveExtension()->reset();
}

void Scene::render(const unique_ptr<Window>& window) {
    for (pair<int, shared_ptr<GameObject>> const& x : _gameObjects)
        x.second->render(window);
}

