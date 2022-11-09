#include"Game.hpp"

void Game::update_edit() {

	edit_cur_x = (Cursor::Pos().x + scroll_x) / Definition::block_size;
	edit_cur_y = (Cursor::Pos().y + scroll_y) / Definition::block_size;

	write_edit();


	update_edit_scroll_controller();

	if (KeyP.down()) {
		go_play();
	}

	if (KeyS.down()) {
		save_edit();
	}
}

void Game::update_edit_scroll_controller() {

	int speed = 8;

	if (scroll_contorller[0].leftPressed()) {
		scroll_y -= speed;
		edit_lock = true;
	}
	else if (scroll_contorller[1].leftPressed()) {
		scroll_y += speed;
		edit_lock = true;
	}
	else if (scroll_contorller[2].leftPressed()) {
		scroll_x -= speed;
		edit_lock = true;
	}
	else if (scroll_contorller[3].leftPressed()) {
		scroll_x += speed;
		edit_lock = true;
	}

	if (scroll_x < 0) {
		scroll_x = 0;
	}

	if (scroll_y < 0) {
		scroll_y = 0;
	}

}

void Game::write_edit() {

	if (edit_type == U"block") {
		write_block_edit();
	}
}

void Game::write_block_edit() {


	if (MouseL.pressed()) {//ペン
	
		int exist = 0;

		for (size_t i = 0; i < block_data.size(); i++) {

			int x = block_data[i].get_x();
			int y = block_data[i].get_y();

			if (edit_cur_x == x && edit_cur_y == y) {//すでにある
				exist = 1;

				block_data[i].set_name(edit_block_name);
			}
		}

		if (exist == 0) {//まだない

			block_data.push_back(Block_Data(edit_block_name, edit_cur_x, edit_cur_y));
		}
	}
}

void Game::erase_edit() {

}

void Game::go_play() {

	main_scene = 0;
	save_edit();
	make_stage();
}

void Game::save_edit() {

	{
		//String adress = U"stage/" + Format(Stage) + U"/wall.bin";
		String adress = U"stage/test.bin";

		// バイナリファイルをオープン
		Serializer<BinaryWriter> Writer{ adress };

		if (not Writer) // もしオープンに失敗したら
		{
			throw Error{ U"Failed to open " + adress };
		}

		// シリアライズに対応したデータを記録
		Writer(block_data);

	}

}
