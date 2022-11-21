#include"Game.hpp"

void Game::set_debug() {

	/*

	tile_data.clear();

	{
		String adress = U"stage/" + stage + U"/tile.bin";


		// バイナリファイルをオープン
		Serializer<BinaryWriter> Writer{ adress };

		if (not Writer) // もしオープンに失敗したら
		{
			throw Error{ U"Failed to open " + adress };
		}

		// シリアライズに対応したデータを記録
		Writer(tile_data);

	}
*/


	load_stage();
	make_stage();

	main_scene = 0;


	


	
}
