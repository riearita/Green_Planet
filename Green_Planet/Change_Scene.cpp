#include"Game.hpp"

void Game::update_change_scene() {


	double d_time = Scene::DeltaTime();

	
	//黒を増やす
	if (change_scene_scene == 0) {

		change_scene_alpha += 1 * d_time;

		if (change_scene_alpha >=1) {
			change_scene_scene++;

			change_scene_alpha = 1;
		}
	}

	//黒い画面キープ
	else if (change_scene_scene == 1) {


		change_scene_count += d_time;

		if (change_scene_count >= 1) {

			change_scene_scene++;

			change_scene_count = 0;

			if (change_scene_type == U"scene") {

				main_scene = change_scene_go_scene;

			}
			else if (change_scene_type == U"stage") {

				stage = change_scene_go_stage;

				load_stage();
				make_stage();

				control_scroll();
			}

		}

	}

	//黒を減らす
	else if (change_scene_scene == 2) {

		change_scene_alpha -= 1 * d_time;

		//終了処理
		if (change_scene_alpha <= 0) {

			change_scene_on = false;

			change_scene_scene = 0;
			change_scene_count = 0;
			change_scene_alpha = 0;
		
		}
	}

}

void Game::draw_change_scene() {

	Rect black_rect(0, 0, 1920, 1080);

	black_rect.draw(Color(1,1,1,change_scene_alpha));

	TextureAsset(U"black").draw(0, 0, ColorF(1, 1, 1, change_scene_alpha));

	
}

void Game::change_scene(int v) {

	change_scene_on = true;

	change_scene_type = U"scene";

	change_scene_scene = v;
}

void Game::change_stage(String v) {

	change_scene_on = true;

	change_scene_type = U"stage";

	change_scene_go_stage = v;
}
