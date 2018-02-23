//Declaring obstacle's and text's surface
SDL_Surface *obs1, *obs2, *ts1, *ts2;
//Declaring obstacle's and text's rectangle
SDL_Rect o1, o2, t1, t2;
//Declaring random integers
int r1, r2, r3, r4;
//Declaring and defining text's color
SDL_Color textColor = {255, 255, 255};
//A function that randomizes the above integers
void frandom(){
srand(time(NULL));
	r1 = rand() % 2 + 1;
	r2 = rand() % 2 + 1;
	r3 = rand() % 2 + 2;
	r4 = rand() % 100 +20;
}
//boject function! :P
void object(){
	r4 = rand() % 100 +20;
	//Defining obstacle's and text's rectangle
	o1.x = 10;
	o1.y = r4;
	t1.x = 354;
	t1.y = 10;
	t2.x = 354;
	t2.y = 300;
	o2.x = 212;
	o2.y = 0;
	//Defining font
	TTF_Font *font = TTF_OpenFont( "arial.ttf", 45 );
	//Inserting images to obstacle's surface
	obs1 = IMG_Load("o2.png");
	obs2 = IMG_Load("o2.png");
	//Inserting text in the surfaces
	ts1 = TTF_RenderText_Solid(font, "The Score" , textColor);
	ts2 = TTF_RenderText_Solid(font, "Highscore" , textColor);
	//Filling rectangles with surface's images (Binding surface with rectangle)
	SDL_FillRect(obs1, &o1, SDL_MapRGB(obs1->format, 255, 255, 255));
	SDL_FillRect(obs2, &o2, SDL_MapRGB(obs2->format, 255, 255, 255));
}
