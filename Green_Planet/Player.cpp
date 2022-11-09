#include"Player.hpp"

void Player::update(double _d_time) {

	d_time = _d_time;

	set_old_pos();

	walk();
	if (ground==1) {
		
	}
	if (ground == 0) {
		air_move();
	}
	jump();

	add_gravity();

	pos += speed;
}

void Player::walk() {

	//double walk_speed = 300 * d_time;

	double walk_speed = 5 * d_time;
	double reversal = 25 * d_time;

	//キー入力中慣性を増やす
	if (KeyLeft.pressed()) {

		//左移動中
		if (inertia <= 0) {
			inertia -= walk_speed;
		}
		//反転
		else {
			inertia -= reversal;
			
		}
	}
	else if (KeyRight.pressed()) {

		//右移動中
		if (inertia >= 0) {
			inertia += walk_speed;
		}
		//反転
		else {
			inertia += reversal;
		}
	}

	//キー入力がない時は慣性をなくす
	else {
		if (inertia > 0 or inertia < 0) {
			
			double v = 80 * d_time;
		
			if (v > 0.93) {
				v = 0.93;
			}
			

			inertia *= v;
			
		}

	
	}

    //慣性の上限
	if (inertia > 10) {
		inertia = 10;
	}
	else if (inertia < -10) {
		inertia = -10;
	}

	//慣性分を代入
	speed.x= inertia;


	
}

void Player::air_move(){}

void Player::jump() {

	int can_jump = 0;

	//地上にいる
	if (ground == 1) {
		can_jump = 1;
	}

	//コヨーテタイム中
	if (coyote_time > 0) {
		can_jump = 1;
	}


	//ジャンプ可能

	if (can_jump == 1) {

		//ジャンプ開始
		if (KeyZ.down()) {

			//初速度を与える
			speed.y = jump_v0;

			//コヨーテタイムなくす
			coyote_time = 0;
		}
	}



	//空中操作

	if (ground == 0) {

		//上昇中andボタンを離している
		if (speed.y < 0 && 1 != KeyZ.pressed()) {

			//ジャンプ抑える
			speed.y *= 0.9;
		}
	}

	//コヨーテタイム減少
	if (coyote_time > 0) {
		coyote_time -= d_time;
	}
}

void Player::add_gravity() {

	//重力として下に加速度を与える
	speed.y += gravity * d_time;

	//加速制限
	if (speed.y >= 60) {
		speed.y = 60;
	}
}

void Player::draw(double x,double y) {

	TextureAsset(U"player").draw(pos.x - x, pos.y - y);
}
