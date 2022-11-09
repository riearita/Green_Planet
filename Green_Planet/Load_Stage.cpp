#include"Game.hpp"

void Game::load_stage() {

	//データ読み込み

	{

		//String adress = U"stageData/" + Format(Stage) + U"/tile.bin";
		String adress = U"stage/test.bin";

		Deserializer<BinaryReader> Reader{ adress };

		if (not Reader)
		{
			throw Error{ U"Failed to open " + adress };
		}

		Reader(block_data);

	}
}
