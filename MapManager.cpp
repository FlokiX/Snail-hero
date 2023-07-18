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

	//for (int i = _player.position.y / 32; i < (_player.position.y + 800) / 32; i++)//���������� �� ��������, �������������� � �������, �� ���� �� ���� ����������� ������� 32*32, ������� �� ���������� � 9 �����. ��� ������� ������� ����.
	//	for (int j = _player.position.x / 32; j < (_player.position.x + 600) / 32; j++)//��� ����� �� 32, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ���� ������ ������� 32*32, ������� ����� ������������ ������ �� ���������� ���������). � j<(x + w) / 32 - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
	//	{
	//		if (_GameMap.TileMap[i][j] == '0')//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
	//		{
	//			if (_player.position.y > 0)//���� �� ��� ����,
	//			{
	//				_player.position.y = i * 32 - 800;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
	//			}
	//			if (_player.position.y < 0)
	//			{
	//				_player.position.y = i * 32 + 32;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
	//			}
	//			if (_player.position.x> 0)
	//			{
	//				_player.position.x = j * 32 - 600;//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
	//			}
	//			if (_player.position.x < 0)
	//			{
	//				_player.position.x = j * 32 + 32;//���������� ���� �����
	//			}
	//		}

	//		if (_GameMap.TileMap[i][j] == 's') { //���� ������ ����� 's' (������)
	//			_player.position.x = 300; _player.position.y = 300;//����� �� ��������... �������� ������������ �����
	//			_GameMap.TileMap[i][j] = ' ';//������� ������, ���� ����� �����. ����� � �� �������, ������.
	//		}
	//	}
}
void MapManager::Render(sf::RenderWindow& window) {
    _GameMap.Render(window);
    _player.Render(window);
}