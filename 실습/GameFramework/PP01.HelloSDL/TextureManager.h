/*
	2018.11.09
	Kwon Kiseok
	TextureManager.h
	하나의 종족을 위한 이미지 파일은 중앙의 한 곳에서 관리
	각각의 캐릭터 객체는 중앙 매니저를 통해 데이터 공유하기 쉬움
*/

#pragma once
#include <map>
#include <SDL_image.h>

class TextureManager
{
public:
	~TextureManager() {}

	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool load(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureManager() {}
	static TextureManager* s_pInstance;
	std::map<std::string, SDL_Texture*> m_textureMap;
};

typedef TextureManager TheTextureManager;