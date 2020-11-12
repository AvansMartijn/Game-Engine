#include "pch.h"
#include "DummyManagableItem.h"
#include <iostream>

DummyManagableItem::DummyManagableItem() {
	_textureKey = "Krool";
}

void DummyManagableItem::onLeftClick(int x, int y) {
	std::cout << "x: " << x << " | " << "y: " << y << std::endl;
}

void DummyManagableItem::onRightClick(int x, int y) {
	std::cout << "x: " << x << " | " << "y: " << y << std::endl;
}