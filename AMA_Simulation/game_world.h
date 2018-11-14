#pragma once
class game_world
{
private:
	static game_world* instance_;

	game_world();
public:
	static  game_world* get_instance();
	void update(float);
	void render();

};

