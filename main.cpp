#include "raylib.h"
#include<iostream>
#include <corecrt_math.h>

Color green = { 38,185,154,255 };
Color Dark_green = { 20,160,133,255 };
Color Light_green = { 129,204,184,255 };
Color Yellow = { 243,213,91,255 };
const float screen_width = 1250;
const float screen_height = 700;

int player1_score = 0;
int player2_score = 0;

class Ball {
public:
	float m_ball_x, m_ball_y;
	float m_ball_speed_x = 10.0f;
	float m_ball_speed_y = 10.0f;
	float m_ball_radius = 20.0f;
	Vector2 v2 = { m_ball_x,m_ball_y };
	void Draw()
	{
		DrawCircle(m_ball_x,m_ball_y,m_ball_radius,Yellow);
		
	}
	void rand_ball_move()
	{
		int random_num = rand( );
	}
	void movement()
	{
		//for movement of ball
	m_ball_x += (int)m_ball_speed_x;
	m_ball_y += (int)m_ball_speed_y;
	//for opposite movement
	
	if (m_ball_x >= (screen_width - m_ball_radius))
	{
		reset_ball();
		player1_score++;
	}
	if (m_ball_x <= m_ball_radius)
	{
		reset_ball();
		player2_score++;
	}
	if (m_ball_y >= (screen_height - m_ball_radius) || m_ball_y <= m_ball_radius) m_ball_speed_y *= -1.0f;
		
	}
	void reset_ball()
	{
		m_ball_x = screen_width / 2;
		m_ball_y = screen_height / 2;
		int speed_choices[2] = { -1,1 };
		m_ball_speed_x *= speed_choices[GetRandomValue(0, 1)];
		m_ball_speed_y *= speed_choices[GetRandomValue(0, 1)];
	}
};
class Player {
public:
	float m_pos_x;
	float m_pos_y;
	float m_speed_y = 13.5f;
	int m_width=20, m_height=80;
	//Vector2 v1 = {m_pos_x,m_pos_y};
	void Draw()
	{
		//DrawRectangle(m_pos_x, m_pos_y, m_width, m_height, PINK);
		DrawRectangleRounded({ m_pos_x, m_pos_y,(float) m_width,(float) m_height },0.8,0,WHITE);
	}
	void movement() {
		if (IsKeyDown(KEY_DOWN))
		{
			m_pos_y += m_speed_y;

		}
		if (IsKeyDown(KEY_UP))
		{
			m_pos_y -= m_speed_y;

		}

	}
	void limit_movement()
	{
		if (m_pos_y  + m_height <= m_height )
		{
			m_pos_y =0 ;
		}
		if (m_pos_y+m_height >= screen_height)
		{
			m_pos_y = screen_height - m_height;
		}
	}
	void auto_movement(float ball_y)
	{
		if (ball_y > m_pos_y)
		{
			m_pos_y += m_speed_y;
		}
		if (ball_y <= m_pos_y)
		{
			m_pos_y -= m_speed_y;
		}
	}
	void p1_score()

	{
		DrawText(TextFormat("Score:%d",player1_score),80,20,40,WHITE);
	}
	void p2_score()
	{
		DrawText(TextFormat("Score:%d",player2_score), 1000, 20, 40, WHITE);
	}

	
};







//object initialize
Ball ball;
Player player1;
Player player2;


//Vector2 ball_pos = { screen_width,screen_height };

int main()
{
	SetTraceLogLevel(LOG_NONE);
	InitWindow((int)screen_width, (int)screen_height, "ping-pong");
	SetTargetFPS(60);
	//set entity values for ball
	ball.m_ball_x = GetScreenWidth() / 2;
	ball.m_ball_y = GetScreenHeight() / 2;
	ball.m_ball_radius = 20.0f;
	
	    
	//set entity values for players
	player1.m_pos_x = 10;
	player1.m_pos_y = GetScreenHeight()/2;

	player2.m_pos_x = GetScreenWidth()-30;
	player2.m_pos_y = GetScreenHeight() / 2;

	
	

	while (!WindowShouldClose())
	{
		BeginDrawing();
		
		ClearBackground(Dark_green);
		DrawRectangle(screen_width/2,0,screen_width/2,screen_height,green);
		DrawCircle(GetScreenWidth()/2,GetScreenHeight()/2,150,Light_green);
		DrawLine(GetScreenWidth()/2,0,GetScreenWidth()/2,GetScreenHeight(),WHITE);
		ball.Draw();
		ball.movement();
		
		//for player 1
		if (CheckCollisionCircleRec({ ball.m_ball_x,ball.m_ball_y }, ball.m_ball_radius, { player1.m_pos_x,player1.m_pos_y,(float)player1.m_width,(float)player1.m_height }))
		{
			ball.m_ball_speed_x *= -1.0f;
			//ball.m_ball_speed_y *= -1.0f;
		}

		//for player2
			if (CheckCollisionCircleRec({ ball.m_ball_x,ball.m_ball_y }, ball.m_ball_radius, { player2.m_pos_x,player2.m_pos_y,(float)player2.m_width,(float)player2.m_height }))
			{
				ball.m_ball_speed_x *= -1.0f;
				//ball.m_ball_speed_y *= -1.0f;
			}
		
		
		//CheckCollisionCircleRec();
		player1.Draw();
		player1.p1_score();
		player1.auto_movement(ball.m_ball_y);
		player1.limit_movement();
		player2.Draw();
		player2.p2_score();
		player2.movement();
		player2.limit_movement();
		



		EndDrawing();
	}
	CloseWindow();

}