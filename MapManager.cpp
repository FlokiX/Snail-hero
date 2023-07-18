#include "MapManager.h"


MapManager::MapManager(GameMap& map, Player& player)
    : _GameMap(map), _player(player) {
   
}

void MapManager::Update(float deltaTime) {
    playerBouds = _player.sprite.getGlobalBounds();
    objectBouds = _GameMap.rectangle.getGlobalBounds();
   
    if (playerBouds.intersects(objectBouds)) {
        if (_player.HeroDirection == 0) {
            _player.position.x += _player.speed * deltaTime;
        }
        if (_player.HeroDirection == 1) {
            _player.position.x -= _player.speed * deltaTime;
        }
        if (_player.HeroDirection == 2) {
            _player.position.y += _player.speed * deltaTime;
        }
        if (_player.HeroDirection == 3) {
            _player.position.y -= _player.speed * deltaTime;
        }
    }     

	//for (int i = _player.position.y / 32; i < (_player.position.y + 800) / 32; i++)//проходимся по тайликам, контактирующим с игроком, то есть по всем квадратикам размера 32*32, которые мы окрашивали в 9 уроке. про условия читайте ниже.
	//	for (int j = _player.position.x / 32; j < (_player.position.x + 600) / 32; j++)//икс делим на 32, тем самым получаем левый квадратик, с которым персонаж соприкасается. (он ведь больше размера 32*32, поэтому может одновременно стоять на нескольких квадратах). А j<(x + w) / 32 - условие ограничения координат по иксу. то есть координата самого правого квадрата, который соприкасается с персонажем. таким образом идем в цикле слева направо по иксу, проходя по от левого квадрата (соприкасающегося с героем), до правого квадрата (соприкасающегося с героем)
	//	{
	//		if (_GameMap.TileMap[i][j] == '0')//если наш квадратик соответствует символу 0 (стена), то проверяем "направление скорости" персонажа:
	//		{
	//			if (_player.position.y > 0)//если мы шли вниз,
	//			{
	//				_player.position.y = i * 32 - 800;//то стопорим координату игрек персонажа. сначала получаем координату нашего квадратика на карте(стены) и затем вычитаем из высоты спрайта персонажа.
	//			}
	//			if (_player.position.y < 0)
	//			{
	//				_player.position.y = i * 32 + 32;//аналогично с ходьбой вверх. dy<0, значит мы идем вверх (вспоминаем координаты паинта)
	//			}
	//			if (_player.position.x> 0)
	//			{
	//				_player.position.x = j * 32 - 600;//если идем вправо, то координата Х равна стена (символ 0) минус ширина персонажа
	//			}
	//			if (_player.position.x < 0)
	//			{
	//				_player.position.x = j * 32 + 32;//аналогично идем влево
	//			}
	//		}

	//		if (_GameMap.TileMap[i][j] == 's') { //если символ равен 's' (камень)
	//			_player.position.x = 300; _player.position.y = 300;//какое то действие... например телепортация героя
	//			_GameMap.TileMap[i][j] = ' ';//убираем камень, типа взяли бонус. можем и не убирать, кстати.
	//		}
	//	}
}
void MapManager::Render(sf::RenderWindow& window) {
    _GameMap.Render(window);
    _player.Render(window);
}