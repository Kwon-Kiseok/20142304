#include "TextureManager.h"

TextureManager* TextureManager::s_pInstance = 0;

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0)
	{
		return false;
	}
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	if (pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}
	return false;
}
void TextureManager::draw(std::string id, int x, int y, int width, int height,
	SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = srcRect.y = 0;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	//SDL_RenderCopyEx
	//SDL_RenderCopy에서 회전과 뒤집기를 위한 인자가 3가지 추가된 확장버전 함수
	//angle, flip 두 인자가 추가 되었으며 angle은 회전시킬 각도(degree) , flip은 뒤집기 옵션이다
	//SDL_FLIP_NONE = 뒤집지 않음 SDL_FLIP_HORIZONTAL = 수평 뒤집기 SDL_FLIP_VERTICAL _ 수직 뒤집기이다
	// [참고 링크] https://m.blog.naver.com/PostView.nhn?blogId=pjc0247&logNo=80188617278&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}
void TextureManager::drawFrame(std::string id, int x, int y, int width, int height,
	int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * (currentRow - 1);
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}