#include "ImageUiElement.h"

using namespace std;
ImageUiElement::ImageUiElement(std::string filePath, SDL_Rect rect) {
    _rectangle = rect;
    _filePath = filePath;
}

ImageUiElement::~ImageUiElement() {}

void ImageUiElement::render(SDL_Renderer* renderer) {
    
    // TODO: Make it so we don't have to create a new instance every time.
    SDL_RenderCopy(renderer, SdlHelper{}.getTexture(_filePath.c_str(), renderer), NULL, &_rectangle);
}

void ImageUiElement::onClick() {
    cout << "YOU CLICKED ME \n";
}

bool ImageUiElement::isInBound(int mouseX, int mouseY) {
    return false;
}