#include"Game.hpp"

void Game::update_input() {

	/*

	inputLeft = KeyLeft;
	inputRight = KeyRight;

	inputZ = KeyZ;
	inputX = KeyX;
	inputShift = KeyShift;

     */

	if (const auto gamepad = Gamepad(playerIndex)) // 接続されていたら
	{

		ClearPrint();

		

		const auto& info = gamepad.getInfo();

		Print << U"{} (VID: {}, PID: {})"_fmt(info.name, info.vendorID, info.productID);

		for (auto [i, button] : Indexed(gamepad.buttons))
		{
			Print << U"button{}: {}"_fmt(i, button.pressed());
		}

		for (auto [i, axe] : Indexed(gamepad.axes))
		{
			Print << U"axe{}: {}"_fmt(i, axe);
		}

		Print << U"POV: " << gamepad.povD8();

		
	}
	
}
