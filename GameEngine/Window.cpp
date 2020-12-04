#pragma once

#include "pch.h"
#include "Window.h"
#include <windows.h>
#include "dirent.h"
#include "SDLTexture.h"

Window::Window(const char* title, int width, int height) {
	_width = width;
	_height = height;

	SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

	_window.reset(window);
	_renderer.reset(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));
}

int Window::getWidth() const {
	return _width;
}

int Window::getHeight() const {
	return _height;
}

void Window::registerTexture(std::string textureKey, std::string texturePath) {
	SDLTexture texture = SDLTexture(texturePath, _renderer.get());

	AssetRegistry::getInstance().registerTexture(textureKey, make_shared<SDLTexture>(texture));
}

void Window::registerTexture(std::string textureKey, std::string texturePath, std::map<std::string, Rect> sprites) {
	SDLTexture texture = SDLTexture(texturePath, _renderer.get());
	texture.isSpriteSheet = true;
	texture.sprites = sprites;
	AssetRegistry::getInstance().registerTexture(textureKey, make_shared<SDLTexture>(texture));
}

void Window::registerTextures(std::string prefix, std::string directory, bool isDeep) {
	std::vector<FileData> files = AssetRegistry::getInstance().getFilesInDirectory(directory, isDeep);

	for (size_t i = 0; i < files.size(); i++) {
		if (prefix == "")
			registerTexture(files[i].key, files[i].path);
		else
			registerTexture(prefix + "_" + files[i].key, files[i].path);
	}
}

void Window::registerFont(std::string fontKey, std::string fontPath) {
	AssetRegistry::getInstance().registerFont(fontKey, fontPath);
}

TTF_Font* Window::getFont(std::string fontKey, int fontSize) {
	return TTF_OpenFont(AssetRegistry::getInstance().getFontPath(fontKey.c_str()).c_str(), fontSize);
}

void Window::clear() {
	SDL_SetRenderDrawColor(_renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer.get());
}

void Window::renderRectangle(Rect rect, Color color) {
	SDL_Rect sdlRect;
	sdlRect.x = rect.x;
	sdlRect.y = rect.y;
	sdlRect.w = rect.w;
	sdlRect.h = rect.h;

	SDL_SetRenderDrawColor(_renderer.get(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(_renderer.get(), &sdlRect);
}

void Window::renderTexture(std::string textureKey, Rect rect, float angle, bool flipLeft, std::string spriteKey) {
	std::shared_ptr<SDLTexture> texture = AssetRegistry::getInstance().getTexture(textureKey);

	texture->renderTexture(_renderer.get(), rect, angle, flipLeft, texture->isSpriteSheet ? spriteKey : "");
}

void Window::renderText(std::string text, TTF_Font* font, Rect rect, Color foregroundColor, Color backgroundColor, bool center, bool multiLine) {
	SDL_Color sdlForegroundColor = { foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a };
	SDL_Color sdlBackgrouldColor = { backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a };

	if (multiLine) {
		int pixelcounter = 0;

		std::vector<std::string> lines;

		std::string::size_type pos = 0;
		std::string::size_type prev = 0;
		while ((pos = text.find("\n", prev)) != std::string::npos) {
			lines.push_back(text.substr(prev, pos - prev));
			prev = pos + 1;
		}

		lines.push_back(text.substr(prev));


		for (auto line : lines) {
			if (line == "")
				continue;

			SDL_Surface* surface = TTF_RenderText_Shaded(font, line.c_str(), sdlForegroundColor, sdlBackgrouldColor);

			SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), surface);

			SDL_Rect sdlRect;
			sdlRect.x = rect.x;
			sdlRect.y = rect.y + pixelcounter;
			sdlRect.w = surface->w;
			sdlRect.h = surface->h;

			if (center) {
				int txtWidth;
				int txtHeight;
				if (TTF_SizeText(font, line.c_str(), &txtWidth, &txtHeight))
					cout << TTF_GetError();
				else
					sdlRect.x = (getWidth() / 2) - (txtWidth / 2);
			}

			SDL_RenderCopy(_renderer.get(), texture, NULL, &sdlRect);
			SDL_FreeSurface(surface);
			SDL_DestroyTexture(texture);

			pixelcounter += surface->h;
		}

	}
	else {

		SDL_Surface* surface = TTF_RenderText_Shaded(font, text.c_str(), sdlForegroundColor, sdlBackgrouldColor);

		SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), surface);

		SDL_Rect sdlRect;
		sdlRect.x = rect.x;
		sdlRect.y = rect.y;
		sdlRect.w = surface->w;
		sdlRect.h = surface->h;

		if (center) {
			int txtWidth;
			int txtHeight;
			if (TTF_SizeText(font, text.c_str(), &txtWidth, &txtHeight))
				cout << TTF_GetError();
			else
				sdlRect.x = (getWidth() / 2) - (txtWidth / 2);
		}

		SDL_RenderCopy(_renderer.get(), texture, NULL, &sdlRect);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}
}

void Window::renderMultiLineText(std::vector<std::string> textLines, TTF_Font* font, Rect rect, Color foregroundColor, Color backgroundColor, bool center, bool multiLine) {

	SDL_Color sdlForegroundColor = { foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a };
	SDL_Color sdlBackgrouldColor = { backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a };

	int w;
	int h;

	TTF_SizeText(font, "TestRender", &w, &h);

	for (size_t i = 0; i < textLines.size(); i++) {

		if (textLines[i] == "")
			continue;

		SDL_Surface* surface = TTF_RenderText_Shaded(font, textLines[i].c_str(), sdlForegroundColor, sdlBackgrouldColor);

		SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), surface);

		SDL_Rect sdlRect;
		sdlRect.x = rect.x;
		sdlRect.y = rect.y + (h * i);
		sdlRect.w = surface->w;
		sdlRect.h = surface->h;

		if (center) {
			int txtWidth;
			int txtHeight;
			if (TTF_SizeText(font, textLines[i].c_str(), &txtWidth, &txtHeight))
				cout << TTF_GetError();
			else
				sdlRect.x = (getWidth() / 2) - (txtWidth / 2);
		}

		SDL_RenderCopy(_renderer.get(), texture, NULL, &sdlRect);
		SDL_FreeSurface(surface);
		SDL_DestroyTexture(texture);
	}

}

int Window::metersToPixels(float value) {
	return (int)(40.0f * value);
}

void Window::display() {
	SDL_RenderPresent(_renderer.get());
}