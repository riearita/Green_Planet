#include"Player.hpp"

void Player::update(double _d_time,InputGroup _left,InputGroup _right, InputGroup _z, InputGroup _x) {

	d_time = _d_time;

	Left = _left;
	Right = _right;
	Z = _z;
	X = _x;

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

	// 加速度 (px/s^2)
	const double a = 800.0;

	// 最大の速さ (px/s)
	const double maxSpeed = 300.0;

	// 平滑化時間（小さいと速く目標値 (0.0) に近づく）
	const double smoothTime = 0.05;

	if (KeyLeft.pressed())
	{
		inertia -= (a * d_time);
		direction = 3;
	}
	else if (KeyRight.pressed())
	{
		inertia += (a * d_time);
		direction = 4;
	}
	else
	{
		// 速度を緩やかに 0 に近づける
		double m_v2 = 0.0;
		inertia = Math::SmoothDamp(inertia, 0.0, m_v2, smoothTime, unspecified, d_time);
	}

	// 速度を -maxSpeed ～ maxSpeed の範囲に抑える
	inertia = Clamp(inertia, -maxSpeed, maxSpeed);

	// 移動
	pos.x += (inertia * d_time);
}



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
		if (KeyX.down()) {

			

			//初速度を与える
			speed.y = jump_v0;

			//コヨーテタイムなくす
			coyote_time = 0;
		}
	}



	//空中操作

	if (ground == 0) {

		//上昇中andボタンを離している
		if (speed.y < 0 && 1 != KeyX.pressed()) {

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

	String image;

	String dire;

	if (direction == 3) {
		dire = U"left";
	}
	else if (direction == 4) {
		dire = U"right";
	}

	image = U"player_" + dire;

	

	TextureAsset(image).draw(pos.x - x, pos.y - y, ColorF(1.0, fade_v));
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
