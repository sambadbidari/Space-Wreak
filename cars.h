//Declaring cars and divider's surface
SDL_Surface *car2surface, *car1surface, *dsurface, *dsurface1, *dsurface2, *dsurface3;
//Declaring cars and divider's rectangle
SDL_Rect car1rect, car2rect, d1, d2, d3, d4;
void cars(){
	//Defining cars and divider's rectangle
	car1rect.x = 20;
	car1rect.y = 380;
	car2rect.x = 222;
	car2rect.y = 380;
	d1.x = 135;
	d1.y = 0;
	d2.x = 270;
	d2.y = 0;
	d3.x = 67;
	d3.y = 0;
	d4.x = 202;
	d4.y = 0;
	//Defining cars and divider's surface (Putting images in syrface)
	//car1surface = IMG_Load("car.png");
	car2surface = IMG_Load("car2.png");
	dsurface = IMG_Load("divider.png");
	dsurface1 = IMG_Load("divider.png");
	dsurface2 = IMG_Load("divider.png");
	dsurface3 = IMG_Load("divider.png");
	//Filling rectangles with surface's images (Binding surface with rectangle)
	//SDL_FillRect(car1surface, &car1rect, SDL_MapRGB(car1surface->format, 255, 255, 255));
	SDL_FillRect(car2surface, &car2rect, SDL_MapRGB(car2surface->format, 255, 255, 255));
	SDL_FillRect(dsurface, &d1, SDL_MapRGB(dsurface->format, 255, 255, 255));
	SDL_FillRect(dsurface1, &d2, SDL_MapRGB(dsurface1->format, 255, 255, 255));
	SDL_FillRect(dsurface2, &d3, SDL_MapRGB(dsurface2->format, 255, 255, 255));
	SDL_FillRect(dsurface3, &d4, SDL_MapRGB(dsurface3->format, 255, 255, 255));
	}
