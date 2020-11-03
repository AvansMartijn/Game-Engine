#include "pch.h"
#include "Scene.h"

Scene Scene::instance;

Scene::Scene() {
    score = 1000;
}

shared_ptr<GameObject> Scene::getGameObject(int index) {
    return _gameObjects[index];
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

void Scene::reset() {
    score = 1000;
    _gameObjects.clear();
}

void Scene::render(const unique_ptr<Window>& window) {
    for (pair<int, shared_ptr<GameObject>> const& x : _gameObjects)
        x.second->render(window);
}