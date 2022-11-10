#include"Player.hpp"

void Player::update(double _d_time) {

	d_time = _d_time;

	set_old_pos();

	walk();
	
	jump();

	add_gravity();

	pos += speed;

	

	muteki_count -= d_time;
	if (muteki_count < 0) {
		muteki_count = 0;
	}

	controll_fade();
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
		direction = 3;
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
		direction = 4;
	}

	//キー入力がない時は慣性をなくす
	else {

		//絶対値が0.1以上
		if (abs(inertia) > 0.1) {

			double v = 80 * d_time;

			if (v > 0.93) {
				v = 0.93;
			}


			inertia *= v;

		}
		else {
			inertia = 0;
		}
	
	}

    //慣性の上限
	if (inertia > 8) {
		inertia = 8;
	}
	else if (inertia < -8) {
		inertia = -8;
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

	double fade_v = 1;

	if (fade_on == 1) {
		fade_v = 0.5;
	}

	TextureAsset(U"player").draw(pos.x - x, pos.y - y, ColorF(1.0, fade_v));
}

void Player::damage(int v) {

	if (muteki_count <= 0) {

		hp -= v;

		if (hp < 0) {
			hp = 0;
		}

		muteki_count = 2;

		fade_count = 0;
	}
}

void Player::controll_fade() {

	if (muteki_count > 0) {

		fade_count += d_time;

		if (fade_count >= 0.1) {

			if (fade_on == 0) {
				fade_on = 1;
			}
			else if (fade_on == 1) {
				fade_on = 0;
			}
			fade_count = 0;
		}
	}
	else if (muteki_count == 0) {
		fade_on = 0;
	}

	
}
