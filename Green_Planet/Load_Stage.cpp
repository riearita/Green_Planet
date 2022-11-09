#include"Game.hpp"

void Game::load_stage() {

	//データ読み込み

	{

		String adress = U"stage/" + stage + U"/block.bin";
		

		Deserializer<BinaryReader> Reader{ adress };

		if (not Reader)
		{
			throw Error{ U"Failed to open " + adress };
		}

		Reader(block_data);

	}
}
