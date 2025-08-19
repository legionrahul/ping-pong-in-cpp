//#include<stdio.h>
//#include "raylib.h"
//
//
//
//
//const int screen_width = 1100;
//const int screen_height = 650;
//
//int main(void) {
//	
//	char* tittle = "test";
//	InitWindow((int)screen_width, (int)screen_height, tittle);
//	Vector2 ball_speed = { 5.0f,6.0f };
//	Vector2  ball_position = { (float)screen_width / 2,(float)screen_height / 2 };
//	float ball_radius = 20;
//	bool pause = false;
//	SetTargetFPS(60);
//	Vector2 score={ 10,10 };
//
//	Vector2 player1_pos = {GetScreenWidth()-(GetScreenWidth()-1),GetScreenHeight() / 2};
//	float player1_speed = 7.8f;
//	int player1_score = 0;
//
//	Vector2 player2_pos = {GetScreenWidth()-20,GetScreenHeight() / 2};
//	float player2_speed = 7.8f;
//	int player2_score = 0;
//	int test = 1;
//	Rectangle rec1 = {
//		
//		.width = 20,
//		.height = 80
//
//	};
//	Rectangle rec2={
//		.width = 20,
//		.height = 80
//
//	};
//	Font f = {
//	.baseSize=12,
//	};
//
//	while (!WindowShouldClose())
//	{
//		
//		//test = LoadTexture(i);
//
//	
//		ClearBackground(BLACK);
//		if (IsKeyPressed(KEY_SPACE))
//		{
//			pause = !pause;
//		}
//		if (!pause)
//
//		{
//			ball_position.x += ball_speed.x;
//			ball_position.y += ball_speed.y;
//			if (ball_position.x >= (screen_width - ball_radius) || ball_position.x<=ball_radius ) ball_speed.x *= -1.0f;
//			if (ball_position.y >= (screen_height - ball_radius) || ball_position.y <= ball_radius)  ball_speed.y *= -1.0f;
//			//for player and ball collision of player 2
//			
//
//			//if (ball_position.x >=  0- (ball_radius + rec2.width)) ball_speed.x *= -1;
//			//if (ball_position.x >=  line_pos.x) ball_speed.x *= -1;
//		}
//		BeginDrawing();
//		//
//
//		//collision with upper and lower wall for player1
//		if (player1_pos.y + 80 >= GetScreenHeight())
//		{
//			player1_pos.y = GetScreenHeight() - 80;
//		}
//		if (player1_pos.y + 80 <= 80)
//		{
//			player1_pos.y = 0;
//		}
//
//		// player1 entity and its movement with key
//		DrawRectangle(rec1.x=player1_pos.x,rec1.y=player1_pos.y,rec1.width,rec1.height,RED);
//
//			if (ball_position.x < GetScreenWidth() / 2)
//			{
//				if (IsKeyDown(KEY_DOWN))
//				{
//					player1_pos.y += player1_speed;
//
//
//
//				}
//				if (IsKeyDown(KEY_UP))
//				{
//					player1_pos.y -= player1_speed;
//
//				}
//			}
//			//collision with ball for player2
//			if (player2_pos.y + 80 >= GetScreenHeight())
//			{
//				player2_pos.y = GetScreenHeight() -80;
//				
//			}
//			if (player2_pos.y + 80 <= 80)
//			{
//				player2_pos.y = 0;
//			}
//		
//		DrawRectangle(rec2.x=player2_pos.x,rec2.y=player2_pos.y, rec2.width, rec2.height, RED);
//
//		if (ball_position.x >= GetScreenWidth() / 2)
//		{
//			if (IsKeyDown(KEY_DOWN))
//			{
//				player2_pos.y += player2_speed;
//
//			}
//			if (IsKeyDown(KEY_UP))
//			{
//				player2_pos.y -= player2_speed;
//			}
//		}
//
//		DrawLine(GetScreenWidth()/2, 0, GetScreenWidth()/2, GetScreenHeight() , WHITE);
//
//          DrawCircle(ball_position.x,ball_position.y,ball_radius,GREEN);
//		 /* if (CheckCollisionCircleRec(ball_position, ball_radius, rec1 ))
//		  {
//			  ball_speed.x *= -1;
//			  ball_speed.y *= -1;
//		  }
//		  if (CheckCollisionCircleRec(ball_position, ball_radius, rec2))
//		  {
//			  ball_speed.x *= -1;
//		\	  ball_speed.y *= -1;
//			  test += 1;
//		  }*/
//		  if (ball_position.y >= screen_height - (ball_radius + rec2.width)) ball_speed.y *= -1.0f;
//		 // if (ball_position.x >= screen_width - (ball_radius + rec2.width)) ball_speed.x *= -1.0f;
//		  //for player 1
//		  //if (ball_position.y <) ball_speed.y *= -1.0f;
//		 // if (ball_position.x < ball_radius+rec1.width ) ball_speed.x *= -1.0f;
//		 // if (ball_position.y < ball_radius + rec1.width) ball_speed.y *= -1.0f;
//		  
//
//		  
//
//		if (pause) DrawText("paused", 380, 180, 32, RED);
//
//		if (!pause)DrawText("press space to pause", 380, 10, 24, GREEN);
//		else
//			DrawText("press space to start", 380, 10, 24, GREEN);
//		 DrawText(TextFormat("score is %d",test), 20, 20, 24, RED);
//		//DrawTextCodepoint(f,player1_score,score,24,GREEN);
//		
//		DrawFPS(10,10);
//		
//		EndDrawing();
//	}
//	CloseWindow();
//	return 0;
//
//	
//}