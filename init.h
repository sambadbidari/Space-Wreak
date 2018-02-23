//Including other header files
#include "cars.h"
#include "objects.h"
#include "screen.h"
#include "highscore.h"
//Declaring window, main surface and background's surface ( surface with purple color! :P)
SDL_Window *window;
SDL_Surface *surface;
SDL_Surface *background;
//Declaring SDL Event ( Event does stuffs like key detection, Mouse detection, etc)
SDL_Event e;
//Bool variables for main loop and logic
bool pause = false;
bool quit = false;
//Game speed integer used in SDL_Delay()
int gamespeed = 5;
//Function with main game loop and other stuffs!
void init(){
//Initializes every SDL2 functions
SDL_Init(SDL_INIT_EVERYTHING);
//Initializes TTF (True Type Fonts)
TTF_Init();
	//Creating window
	window = SDL_CreateWindow("Space Wreck", 359, 100, 640, 480, SDL_WINDOW_SHOWN);
	//Declaring window's surface, the main Surface I told u about, remember now?
	surface = SDL_GetWindowSurface(window);
	//Loads that purple image I told u about, remember? No rectangle
	background = IMG_Load("background.png");
	//Runs car() function from car.h
	cars();
	//Runs object() function from object.h
	object();
	//Runs mainscreen() function from screen.h
	mainscreen();
	//Increases object 1's y co-ordinantes
	if(o2.y<=380)
		o2.y++;
	else
		o2.y = 10;
	//Main game loop
	while(!quit){
		//Event loop
		 while( SDL_PollEvent( &e ) != 0 )
                {
										//If event is SDL quit, main loop stops
                    if( e.type == SDL_QUIT )
                    {
												quit = true;
												wrhs();
												//Integer to const char conversion stuffs
												strm.str("");
												strm.clear();
                    }
										//If a key is pressed
                    else if( e.type == SDL_KEYDOWN )
                    {
												//switch case starts
                        switch( e.key.keysym.sym )
                        {
														//If escape is pressed, game pauses
                            case SDLK_ESCAPE:
                            MainSc = IMG_Load("pausegame.png");
                            pause = false;
                            break;
														//If 2 is pressed, help scren is displayed
														case SDLK_2:
														MainSc = IMG_Load("help.png");
														pause = false;
														break;

														//If 1 is pressed, game starts
                            case SDLK_1:
                            MainSc = NULL;
                          	pause = true;
                            break;
														//If 3 is pressed, loop stops and game exits after showing end.png image
														case SDLK_3:
                            quit = true;
                           	break;
														//If A is pressed, car1 moves in the left lane
                            case SDLK_a:
                            car1rect.x = 20;
                           	break;
														//If S is pressed, car1 moves in the right lane
                            case SDLK_s:
                            car1rect.x = 88;
                            break;
														//If k is pressed, car2 moves in the left lane
													  case SDLK_LEFT:
														car2rect.x = 155;
                            break;
														//If l is pressed, car2 moves in the right lane
                            case SDLK_RIGHT:
                            car2rect.x = 222;
                            break;
														//If Enter is pressed, paused game resumes
														case SDLK_RETURN:
                            if(pause == false){
															MainSc = NULL;
															pause = true;
														}
														break;

                        }
                    }
                }
	 //Random function from objects.h file
   frandom();
	 //Pause logic
	 if(pause == true){
   	o1.y++;
   	o2.y++;
 		}
	//Collision detection
   /*if(o1.y == 350){
		 wrhs();
   	if(o1.x != car1rect.x-10){
			MainSc = IMG_Load("end.png");
			gamespeed = 3000;
			quit = true;
			wrhs();
			strm.str("");
			strm.clear();
		}
		else{
			 	if(r1 == 1)
	 			o1.x = 10;
	 		else
	 			o1.x = 78;
				point++;
				wrhs();
				strm.str("");
				strm.clear();
			o1.y = 0;
			}
	 }*/

	 //Collision detection
	 if(o2.y == 350){
	 	if(o2.x == car2rect.x-10){
			MainSc = IMG_Load("end.png");
			SDL_Rect quitrect;
			gamespeed = 3000;
	 		quit = true;
			wrhs();
			strm.str("");
			strm.clear();
		}
	 	else{
	 		if(r2 == 1)
	 			o2.x = 145;
	 		else
				o2.x = 212;
			o2.y = 0;
			point++;

			wrhs();
			strm.str("");
			strm.clear();

		//Game speed control
		if(point == 0)
			gamespeed = 5;
		else if((point >= 0)&&(point <10))
			gamespeed = 5;
		else if((point >= 10)&&(point <20))
			gamespeed = 4;
		else if((point >= 20)&&(point <30))
			gamespeed = 3;
		else if((point >= 30)&&(point <40))
			gamespeed = 2;
		else if(point >= 50)
			gamespeed  = 1;
	 		}

	 }
	//SDL Blitting, marrying the rectangles and images just as I told you! :P
	SDL_BlitSurface( background, NULL, surface, NULL );
	SDL_BlitSurface( dsurface, NULL, surface, &d1 );
	SDL_BlitSurface( dsurface1, NULL, surface, &d2 );
	//SDL_BlitSurface( dsurface2, NULL, surface, &d3 );
	SDL_BlitSurface( dsurface3, NULL, surface, &d4 );
	//SDL_BlitSurface( obs1, NULL, surface, &o1 );
	SDL_BlitSurface( obs2, NULL, surface, &o2 );
	SDL_BlitSurface( MainSc, NULL, surface, NULL );
	SDL_BlitSurface( ts1, NULL, surface, &t1);
	SDL_BlitSurface( ts2, NULL, surface, &t2);
	//SDL_BlitSurface( car1surface, NULL, surface, &car1rect );
	SDL_BlitSurface( car2surface, NULL, surface, &car2rect );
	SDL_BlitSurface( fontsurface1, NULL, surface, &fontrect1);
	SDL_BlitSurface( fontsurface2, NULL, surface, &fontrect2);
	SDL_BlitSurface( MainSc, NULL, surface, NULL );
	//Updating window's surface
	SDL_UpdateWindowSurface( window );
	//Gamme speed control
	SDL_Delay(gamespeed);
	}
}
