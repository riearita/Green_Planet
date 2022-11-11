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

	//データ読み込み

	{

		String adress = U"stage/" + stage + U"/enemy.bin";


		Deserializer<BinaryReader> Reader{ adress };

		if (not Reader)
		{
			throw Error{ U"Failed to open " + adress };
		}

		Reader(enemy_data);

	}

	//データ読み込み

	{

		String adress = U"stage/" + stage + U"/start.bin";


		Deserializer<BinaryReader> Reader{ adress };

		if (not Reader)
		{
			throw Error{ U"Failed to open " + adress };
		}

		Reader(start_point);

	}

	//データ読み込み

	{

		String adress = U"stage/" + stage + U"/tile.bin";


		Deserializer<BinaryReader> Reader{ adress };

		if (not Reader)
		{
			throw Error{ U"Failed to open " + adress };
		}

		Reader(tile_data);

	}

	//データ読み込み

	{

		String adress = U"stage/" + stage + U"/event.bin";


		Deserializer<BinaryReader> Reader{ adress };

		if (not Reader)
		{
			throw Error{ U"Failed to open " + adress };
		}

		Reader(event_data);

	}
}
