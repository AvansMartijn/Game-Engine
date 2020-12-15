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

void Window::registerTexture(const std::string& textureKey, const std::string& texturePath, bool isReversed) {
	SDLTexture texture = SDLTexture(texturePath, _renderer.get());
	texture.isReversed = isReversed;

	AssetRegistry::getInstance().registerTexture(textureKey, make_shared<SDLTexture>(texture));
}

void Window::registerTextures(const std::string& prefix, const std::string& directory, bool isDeep) {
	std::vector<FileData> files = AssetRegistry::getInstance().getFilesInDirectory(AssetRegistry::getInstance().getBasePath(), directory, isDeep);

	for (size_t i = 0; i < files.size(); i++) {
		if (prefix == "")
			registerTexture(files[i].key, files[i].path);
		else
			registerTexture(prefix + "_" + files[i].key, files[i].path);
	}
}

void Window::registerFont(const std::string& fontKey, const std::string& fontPath) {
	AssetRegistry::getInstance().registerFont(fontKey, fontPath);
}

TTF_Font* Window::getFont(const std::string& fontKey, int fontSize) {
	return TTF_OpenFont(AssetRegistry::getInstance().getFontPath(fontKey.c_str()).c_str(), fontSize);
}

void Window::clear() {
	SDL_SetRenderDrawColor(_renderer.get(), 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_renderer.get());
}

void Window::renderRectangle(const Rect& rect, const Color& color) {
	SDL_Rect sdlRect;
	sdlRect.x = rect.x;
	sdlRect.y = rect.y;
	sdlRect.w = rect.w;
	sdlRect.h = rect.h;

	SDL_SetRenderDrawColor(_renderer.get(), color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(_renderer.get(), &sdlRect);
}

void Window::renderTexture(const std::string& textureKey, const Rect& rect, float angle, bool flipLeft, int alpha) {
	std::shared_ptr<SDLTexture> texture = AssetRegistry::getInstance().getTexture(textureKey);

	texture->renderTexture(_renderer.get(), rect, angle, flipLeft, alpha);
}

void Window::renderSprite(const std::string& textureKey, const Rect& rect, const Rect& sprite, float angle, bool flipLeft) {
	std::shared_ptr<SDLTexture> texture = AssetRegistry::getInstance().getTexture(textureKey);

	texture->renderSprite(_renderer.get(), rect, sprite, angle, flipLeft);
}

void Window::renderText(const std::string& text, TTF_Font* font, const Rect& rect, const Color& foregroundColor, const Color& backgroundColor, bool center, bool multiLine) {
	SDL_Color sdlForegroundColor = { foregroundColor.r, foregroundColor.g, foregroundColor.b, foregroundColor.a };
	SDL_Color sdlBackgrouldColor = { backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a };

	if (multiLine) {
		std::vector<std::string> lines;

		std::string::size_type pos = 0;
		std::string::size_type prev = 0;
		while ((pos = text.find("\n", prev)) != std::string::npos) {
			lines.push_back(text.substr(prev, pos - prev));
			prev = pos + 1;
		}

		lines.push_back(text.substr(prev));

		int w;
		int h;

		TTF_SizeText(font, "TestRender", &w, &h);

		for (size_t i = 0; i < lines.size(); i++) {
			if (lines[i] == "")
				continue;

			SDL_Surface* surface = TTF_RenderText_Shaded(font, lines[i].c_str(), sdlForegroundColor, sdlBackgrouldColor);

			SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer.get(), surface);

			SDL_Rect sdlRect;
			sdlRect.x = rect.x;
			sdlRect.y = rect.y + (h * (int)i);
			sdlRect.w = surface->w;
			sdlRect.h = surface->h;

			if (center) {
				int txtWidth;
				int txtHeight;
				if (TTF_SizeText(font, lines[i].c_str(), &txtWidth, &txtHeight))
					cout << TTF_GetError();
				else
					sdlRect.x = (getWidth() / 2) - (txtWidth / 2);
			}

			SDL_RenderCopy(_renderer.get(), texture, NULL, &sdlRect);
			SDL_FreeSurface(surface);
			SDL_DestroyTexture(texture);
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

void Window::renderHPBar(int x, int y, int w, int h, float percentage, const Color& fgColor, const Color& bgColor) {
	percentage = percentage > 1.f ? 1.f : percentage < 0.f ? 0.f : percentage;
	Color old;
	SDL_GetRenderDrawColor(_renderer.get(), &old.r, &old.g, &old.g, &old.a);

	SDL_Rect border = { x + 2, y - 2, w - 4, h + 4 };
	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
	SDL_RenderFillRect(_renderer.get(), &border);

	SDL_Rect background = { x, y, w, h };
	SDL_SetRenderDrawColor(_renderer.get() , bgColor.r, bgColor.g, bgColor.b, bgColor.a);
	SDL_RenderFillRect(_renderer.get(), &background);

	int posW = (int)((float)w * percentage);
	int posX = x + (w - posW); // 
	SDL_Rect bar = { posX, y, posW, h };
	SDL_Rect line = { posX + 2, y, posW, h };

	SDL_SetRenderDrawColor(_renderer.get(), 0, 0, 0, 255);
	SDL_RenderFillRect(_renderer.get(), &line);

	SDL_SetRenderDrawColor(_renderer.get(), fgColor.r, fgColor.g, fgColor.b, fgColor.a);
	SDL_RenderFillRect(_renderer.get(), &bar);
	SDL_SetRenderDrawColor(_renderer.get(), old.r, old.g, old.b, old.a);
}

void Window::renderMultiLineText(std::vector<std::string> textLines, TTF_Font* font, const Rect& rect, const Color& foregroundColor, const Color& backgroundColor, bool center, bool multiLine) {
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
		sdlRect.y = rect.y + (h * (int)i);
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